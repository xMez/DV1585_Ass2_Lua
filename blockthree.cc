#include "blockthree.hh"

map<string, int> ThreeAd::vars = {};

void ThreeAd::dump()
{
  outputFile << name << " <- ";
  if (rhs[0] == '"')
    rhs = rhs.substr(1, rhs.size()-2);
  if (lhs[0] == '"')
    lhs = lhs.substr(1, lhs.size()-2);
  outputFile << lhs << " " << op << " " << rhs << endl;
}

void ThreeAd::dumpC()
{
  if (op == "*"
      || op == "+"
      || op == "-"
      || op == "/") {
    if (vars[name] == 0
        && name.find("_t") == std::string::npos
        && name.find("_s") == std::string::npos)
      outputFile << "double " << name << " = " << "(double)" << lhs << op << "(double)" << rhs << ";" << endl;
    else
      outputFile << name << " = " << "(double)" << lhs << op << "(double)" << rhs << ";" << endl;
    vars[name] = 1;
  }
  else if (op == "%") {
    if (vars[name] == 0
        && name.find("_t") == std::string::npos
        && name.find("_s") == std::string::npos)
      outputFile << "double " << name << " = " << "fmod(" << lhs << ", "<< rhs << ");" << endl;
    else
      outputFile << name << " = " << "fmod(" << lhs << ", "<< rhs << ");" << endl;
    vars[name] = 1;
  }
  else if (op == "#") {
    if (vars[name] == 0
        && name.find("_t") == std::string::npos
        && name.find("_s") == std::string::npos)
      outputFile << "double " << name << " = " << "sizeof("  << endl;
    else
      outputFile << name << " = " << "sizeof(" << lhs  << ") / sizeof(" << lhs << "[0]);" << endl;
    vars[name] = 1;
  }
  else if (op == "^") {
    if (vars[name] == 0
        && name.find("_t") == std::string::npos
        && name.find("_s") == std::string::npos)
      outputFile << "double " << name << " = " << "pow(" << rhs << ", "<< lhs << ");" << endl;
    else
      outputFile << name << " = " << "pow(" << rhs << ", "<< lhs << ");" << endl;
    vars[name] = 1;
  }
  else if (op == "call") {
    if (lhs == "print") {
      outputFile << "std::cout << " << rhs << " << std::endl;" << endl;
    }
    else if (lhs == "iowrite") {
      std::istringstream iss(rhs);
      std::vector<std::string> expList{istream_iterator<std::string>{iss},
                                     istream_iterator<std::string>{}};
      outputFile << "std::cout << ";
      for (auto it : expList)
        outputFile << it << " << ";
      outputFile << "\"\";" << endl;
    }
    else if (lhs == "ioread") {
      if (vars[name] == 0
          && name.find("_t") == std::string::npos
          && name.find("_s") == std::string::npos)
        outputFile << "double " << name << ";" << endl;
      outputFile << "scanf(\"%lf\", &" << name << ");" << endl;
    }
    else {
      outputFile << name << " = " << lhs << "(" << rhs << ");" << endl;
    }
  }
  else if (op == "ret") {
    outputFile << name << lhs << ";" << endl;
  }
  else if (op == "ass") {
    auto found = name.find_first_of("[");
    if (rhs == "false"
        || rhs == "true") {
      if (vars[name] == 0
          && name.find("_t") == std::string::npos
          && name.find("_s") == std::string::npos)
        outputFile << "bool " << name << " = " << "(bool)" << lhs << ";" << endl;
      else
        outputFile << name << " = " << "(bool)" << lhs << ";" << endl;
      vars[name] = 1;
    }
    else if (found != std::string::npos) {
      std::string varName = name.substr(0, found);
      if (vars[varName] == 0
          && name.find("_t") == std::string::npos
          && name.find("_s") == std::string::npos)
        outputFile << "double " << name << " = " << lhs << ";" << endl;
      else
        outputFile << name << " = " << "(double)" << lhs << ";" << endl;
      vars[varName] = 1;
    }
    else {
      if (vars[name] == 0
          && name.find("_t") == std::string::npos
          && name.find("_s") == std::string::npos)
        outputFile << "double " << name << " = " << "(double)" << lhs << ";" << endl;
      else
        outputFile << name << " = " << lhs << ";" << endl;
      vars[name] = 1;
    }
  }
  else if (name == "eval") {
    outputFile << "if(" << lhs << op << rhs <<") ";
  }
}

int BBlock::nCounter = 0;

void BBlock::dump()
{
  outputFile << "BBlock @ " << this << endl;
  outputFile << name << endl;
  for(auto i : instructions)
    i.dump();
  if(tExit)
    outputFile << "True:  " << tExit->name << endl;
  if(fExit)
    outputFile << "False: " << fExit->name << endl;
}

void BBlock::dumpC()
{
  outputFile << name << ": ;" << endl;
  for(auto i : instructions)
    i.dumpC();
  if(tExit)
    outputFile << "{ goto "<< tExit->name << "; }" << endl;
  if(fExit)
    outputFile << "else { goto " << fExit->name << "; }" << endl;
    if(tExit == NULL)
      outputFile << "return 0;" << endl;
}
