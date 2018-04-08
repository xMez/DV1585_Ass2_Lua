#include "node.hh"
int Node::nCounter = 0;
int Node::sCounter = 0;
map<std::string, BBlock*> Node::funcNames = {};

void Node::dump(int depth)
{
	for(int i=0; i<depth; i++)
		std::cout << "  ";
	std::cout << tag << ":" << value << std::endl;
	for(auto i=children.begin(); i!=children.end(); i++)
		(*i).dump(depth+1);
}

std::ostringstream Node::toStream(int &depth, int parent)
{
	std::ostringstream oss;
	oss << depth << " [label=\"" << tag << ":" << value << "\"];\n";
	for(auto i=children.begin(); i!=children.end(); i++)
	{
		depth++;
		oss << parent << " -> " << depth << "\n";
		oss << (*i).toStream(depth, depth).str();
	}
	parent++;
	return oss;
}

std::string Node::makeName()
{
  std::string name = "_t" + to_string(nCounter++);
  return name;
}

std::string Node::makeString()
{
  std::string name = "_s" + to_string(sCounter++);
  return name;
}

BBlock* Node::convert(BBlock* out)
{
  if (tag == "block" || tag == "chunk") {
    for (auto it : children)
      out = it.convert(out);
    return out;
  }
  else if (tag == "functioncall") {
    std::string funcName = children.front().convertExp(out);
    std::string rhs = children.back().convertExp(out);
    std::string funcType = "_func";
    if (children.back().tag == "string"
        || children.back().children.front().tag == "string")
      funcType = "S";
    out->instructions.push_back(ThreeAd(funcType, "call", funcName, rhs));
    return out;
  }
  else if (tag == "laststat") {
    std::string retVal = children.front().convertExp(out);
    out->instructions.push_back(ThreeAd("return ", "ret", retVal, retVal));
    return out;
  }
  else if (tag == "stat") {
    if (value == "FOR") {
      auto it = children.begin();
      std::string varName = it->convertExp(out);
      std::string varVal = (++it)->convertExp(out);
      out->instructions.push_back(ThreeAd(varName, "ass", varVal, varVal));
      std::string limit = (++it)->convertExp(out);

      BBlock* evalBlock = new BBlock();
      BBlock* trueBlock = new BBlock();

      evalBlock->instructions.push_back(ThreeAd("eval", "<=", varName, limit));

      out->tExit = evalBlock;
      evalBlock->tExit = trueBlock;
      trueBlock->tExit = evalBlock;

      std::string addrVar = this->makeName();
      BBlock* addrBlock = (++it)->convert(trueBlock);
      addrBlock->tExit = evalBlock;
      addrBlock->instructions.push_back(ThreeAd(addrVar, "+", varName, "1"));
      addrBlock->instructions.push_back(ThreeAd(varName, "ass", addrVar, addrVar));


      BBlock* endBlock = new BBlock();
      evalBlock->fExit = endBlock;


      //(++it)->convert(trueBlock)->tExit = evalBlock;
      //evalBlock->instructions.push_back(ThreeAd(varName, "+", varName, "1"));

      return endBlock;
    }
    else if (value == "IF") {
      auto it = children.begin();

      it->children.front().convertExp(out);

      BBlock* trueBlock = new BBlock();
      BBlock* falseBlock = new BBlock();
      BBlock* endBlock = new BBlock();
      out->tExit = trueBlock;
      out->fExit = falseBlock;
      it->children.back().convert(trueBlock)->tExit = endBlock;
      it++;
      it++;
      if (it->value != "empty")
        it->children.front().convert(falseBlock)->tExit = endBlock;
      else
        out->fExit = endBlock;
      return endBlock;
    }
    else if (value == "REP") {
      BBlock* trueBlock = new BBlock();
      BBlock* evalBlock = new BBlock();
      BBlock* endBlock = new BBlock();
      out->tExit = trueBlock;

      children.front().convert(trueBlock)->tExit = evalBlock;
      children.back().convertExp(evalBlock);
      evalBlock->tExit = endBlock;
      evalBlock->fExit = trueBlock;
      return endBlock;
    }
    else if (value == "FUNC") {
      std::string funcName = children.front().convertExp(out);
      std::string param = children.back().children.front().convertExp(out);
      BBlock* startBlock = new BBlock();
      children.back().children.back().convert(startBlock);
      funcName += "(double " + param + ")";
      funcNames[funcName] = startBlock;
      return out;
    }
    else {
      if (children.back().children.size() > 1) {
        std::string expString = children.back().convertExp(out);
        std::istringstream iss(expString);
        std::vector<std::string> expList{istream_iterator<std::string>{iss},
                                       istream_iterator<std::string>{}};

        auto it = children.front().children.begin();
        for (size_t i = 0; i < children.front().children.size(); i++) {
          std::string varName;
          varName += it->convertExp(out);
          out->instructions.push_back(ThreeAd(varName, "ass", expList[i], expList[i]));
          it++;
        }
      }
      else {
        std::string varName = children.front().convertExp(out);
        children.back().tag = "exp";
        std::string lhs = children.back().convertExp(out);
        if (lhs.find_first_of("{") != std::string::npos)
          out->instructions.push_back(ThreeAd(varName + "[]", "ass", lhs, lhs));
        else
          out->instructions.push_back(ThreeAd(varName, "ass", lhs, lhs));
      }
      return out;
    }
  }
}

std::string Node::convertExp(BBlock *out)
{
  if (tag == "varlist"
      || tag == "exp"
      || tag == "tableconstructor"
      || tag == "field"
      || tag == "ifexp"
      || tag == "funcname"
      || tag == "parlist"
      || tag == "namelist") {
    return children.front().convertExp(out);
  }
  if (tag == "explist") {
    std::string names;
    for (auto it : children) {
      std::string name;
      if (it.tag == "string")
        name = this->makeString();
      else
        name = this->makeName();
      std::string lhs = it.convertExp(out);
      out->instructions.push_back(ThreeAd(name, "ass", lhs, lhs));
      names += name;
      names += " ";
    }
    return names;
  }
  else if (tag == "binop") {
    std::string lhs = children.front().convertExp(out);
    std::string rhs = children.back().convertExp(out);
    std::string name;
    if (value == "==" || value == ">" || value == "<")
      name = "eval";
    else
      name = this->makeName();
    out->instructions.push_back(ThreeAd(name, value, lhs, rhs));
    return name;
  }
  else if (tag == "bracket") {
    std::string name = children.front().convertExp(out);
    name += value;
    name += children.back().convertExp(out);
    return name;
  }
  else if (tag == "unop") {
    std::string lhs = children.front().convertExp(out);
    std::string name = this->makeName();
    out->instructions.push_back(ThreeAd(name, value, lhs, lhs));
    return name;
  }
  else if (tag == "NAME") {
    if (value == "io")
      return value += children.front().value;
    else
      return value;
  }
  else if (tag == "NUMBER"
           || tag == "FALSE"
           || tag == "TRUE"
           || tag == "string") {
    return value;
  }
  else if (tag == "functioncall") {
    std::string varName = this->makeName();
    std::string lhs = children.front().convertExp(out);
    std::string rhs = children.back().convertExp(out);
    out->instructions.push_back(ThreeAd(varName, "call", lhs, rhs));
    return varName;
  }
  else if (tag == "fieldlist") {
    std::stringstream ss;
    ss << "{";
    std::for_each(children.begin(), --children.end(),
      [&](Node &n){ ss << n.convertExp(out) << ", "; });
    ss << children.back().convertExp(out) << "}";
    return ss.str();
  }
  else if (tag == "var") {
    std::stringstream ss;
    ss << children.front().convertExp(out);
    if (children.back().tag == "binop")
      children.back().tag = "bracket";
    ss << "[(int)" << children.back().convertExp(out) << "-1]";
    return ss.str();
  }
}
