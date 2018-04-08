#ifndef BLOCKTHREE_HH
#define BLOCKTHREE_HH
#include <list>
#include <map>
#include <set>
#include <initializer_list>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <cstddef>
#include <vector>
#include <iterator>

using namespace std;

extern ofstream outputFile;

/************* Three Address Instructions *************/
class ThreeAd
{
public:
        string name,lhs,rhs;
        string op;
        static map<string, int> vars;

        ThreeAd(string name, string op, string lhs, string rhs) :
                name(name), op(op), lhs(lhs), rhs(rhs)
        {
        }

        void dump();
        void dumpC();
};

/* Basic Blocks */
class BBlock
{
private:
        static int nCounter;
public:
        list<ThreeAd> instructions;
        BBlock *tExit, *fExit;
        string name;

        BBlock() :
                tExit(NULL), fExit(NULL), name("blk" + to_string(nCounter++))
        {
        }

        void dump();
        void dumpC();
};
#endif
