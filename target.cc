#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <string>
#include <math.h>
int main() {
double _t0;
double _t1;
double _t2;
double _t3;
double _t4;
double _t5;
double _t6;
double _t7;
blk0: ;
double list[] = {5, 6, 1, 2.4, 2.3, 2.5, 9, 14, 2, 15, 6, 7, 8, 97};
_t0 = sizeof(list) / sizeof(list[0]);
double itemCount = (double)_t0;
{ goto blk1; }
blk1: ;
bool hasChanged = (bool)false;
_t1 = (double)itemCount-(double)1;
itemCount = _t1;
double i = (double)1;
{ goto blk4; }
blk4: ;
if(i<=itemCount) { goto blk5; }
else { goto blk9; }
blk5: ;
if(list[(int)i-1]>list[(int)i+1-1]) { goto blk6; }
else { goto blk8; }
blk6: ;
_t3 = list[(int)i+1-1];
_t4 = list[(int)i-1];
list[(int)i-1] = (double)_t3;
list[(int)i+1-1] = (double)_t4;
hasChanged = (bool)true;
{ goto blk8; }
blk8: ;
_t2 = (double)i+(double)1;
i = _t2;
{ goto blk4; }
blk9: ;
{ goto blk2; }
blk2: ;
if(hasChanged==false) { goto blk3; }
else { goto blk1; }
blk3: ;
i = 1;
_t5 = sizeof(list) / sizeof(list[0]);
{ goto blk10; }
blk10: ;
if(i<=_t5) { goto blk11; }
else { goto blk12; }
blk11: ;
_t7 = list[(int)i-1];
std::cout << _t7  << std::endl;
_t6 = (double)i+(double)1;
i = _t6;
{ goto blk10; }
blk12: ;
return 0;
}
