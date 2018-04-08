#ifndef NODE_HH
#define NODE_HH
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>
//#include "enviroment.hh"
#include "blockthree.hh"
class Node {
public:
	std::string tag, value;
	std::list<Node> children;
  static int nCounter;
  static int sCounter;
  static map<std::string, BBlock*> funcNames;
	//static Enviroment globals;
	Node(std::string t, std::string v) : tag(t), value(v) {}
	Node() { tag="uninitilized"; value="uninitialized"; }
	void dump(int depth=0);
	std::ostringstream toStream(int &depth, int parent=0);

  std::string makeName();
  std::string makeString();
  BBlock* convert(BBlock* out);
  std::string convertExp(BBlock* out);
};
#endif
