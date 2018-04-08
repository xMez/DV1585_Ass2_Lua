#include "node.hh"
#include <iostream>
#include <fstream>
#include "binary.tab.hh"
extern FILE *yyin;
extern Node root;
extern unsigned int total;
std::ofstream outputFile;

void yy::parser::error(std::string const&err)
{
	std::cout << "Error occured  " << err << std::endl;
}

void makeFile()
{
	std::ofstream ofs("parse.txt", std::ofstream::out);

	ofs << "digraph {\n";
	int depth = 0;
	ofs << root.toStream(depth).str();
	ofs << "}";

	ofs.close();
}

void dumpCFG(BBlock *start)
{
  set<BBlock *> done, todo;
  todo.insert(start);
  while(todo.size()>0)
  {
    // Pop an arbitrary element from todo set
    auto first = todo.begin();
    BBlock *next = *first;
    todo.erase(first);
    outputFile << next->name << " [label=\"";
    next->dump();
    outputFile << "\"]" << std::endl;
    done.insert(next);
    if(next->tExit!=NULL && done.find(next->tExit)==done.end())
      todo.insert(next->tExit);
    if(next->fExit!=NULL && done.find(next->fExit)==done.end())
      todo.insert(next->fExit);

    if(next->tExit!=NULL)
      outputFile << next->name << "->" << next->tExit->name << " [label=\"true\"]" << std::endl;
    if(next->fExit!=NULL)
      outputFile << next->name << "->" << next->fExit->name << " [label=\"false\"]" << std::endl;
  }
}

void dumpCode(BBlock *start)
{
  for (size_t i = 0; i < root.nCounter; i++) {
    outputFile << "double " "_t" + to_string(i) << ";" << std::endl;
  }
  for (size_t i = 0; i < root.sCounter; i++) {
    outputFile << "std::string " "_s" + to_string(i) << ";" << std::endl;
  }
  set<BBlock *> done, todo;
  todo.insert(start);
  while(todo.size()>0)
  {
    // Pop an arbitrary element from todo set
    auto first = todo.begin();
    BBlock *next = *first;
    todo.erase(first);
    next->dumpC();
    done.insert(next);
    if(next->tExit!=NULL && done.find(next->tExit)==done.end())
      todo.insert(next->tExit);
    if(next->fExit!=NULL && done.find(next->fExit)==done.end())
      todo.insert(next->fExit);
  }
}

int main(int argc, char **argv)
{
	if(argc > 1)
		yyin = fopen(argv[1], "r");
	yy::parser parser;
	if(!parser.parse())
	{
		//root.dump();
		//makeFile();
    BBlock* block = new BBlock();
    root.convert(block);

    //freopen("cfg.dot", "w", stdout);

    outputFile.open("cfg.dot");
    outputFile << "digraph {";
    for (auto it : root.funcNames) {
      dumpCFG(it.second);
    }
    dumpCFG(block);
    outputFile << "}" << std::endl;
    outputFile.close();

    //freopen("target.cc", "w", stdout);

    outputFile.open("target.cc");
    outputFile << "#include <stdio.h>" << std::endl;
    outputFile << "#include <stdlib.h>" << std::endl;
    outputFile << "#include <stdbool.h>" << std::endl;
    outputFile << "#include <iostream>" << std::endl;
    outputFile << "#include <string>" << std::endl;
    outputFile << "#include <math.h>" << std::endl;
    for (auto it : root.funcNames) {
      outputFile << "double " << it.first << "{" << std::endl;
      dumpCode(it.second);
      outputFile << "}" << std::endl;
    }
    outputFile << "int main() {" << std::endl;
    dumpCode(block);
    outputFile << "}" << std::endl;
    outputFile.close();
	}
	fclose(yyin);
	return 0;
}
