#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main()
{
double _t2 = 0;
double _t3 = 0;
blk0: ;
double list[] = {5, 6, 1, 2.4, 2.3, 2.5, 9, 14, 2, 15, 6, 7, 8, 97};
double _t0 = sizeof(list) / sizeof(list[0]);
double itemCount = (double)_t0;
{ goto blk1; }
blk1: ;
bool hasChanged = (bool)false;
double _t1 = (double)itemCount-(double)1;
itemCount = (double)_t1;
double i = (double)1;
{ goto blk5; }
blk5: ;
if((double)list[(int)i-1]>(double)list[(int)i+1-1]) { goto blk7; }
else { goto blk9; }
blk7: ;
_t2 = (double)list[(int)i+1-1];
_t3 = (double)list[(int)i-1];
list[(int)i-1] = (double)_t2;
list[(int)i+1-1] = (double)_t3;
hasChanged = (bool)true;
{ goto blk9; }
blk9: ;
{ goto blk4; }
blk4: ;
i = (double)i+(double)1;
if(i<=itemCount) { goto blk5; }
else { goto blk6; }
blk6: ;
{ goto blk2; }
blk2: ;
if(hasChanged==false) { goto blk1; }
else { goto blk3; }
blk3: ;
i = (double)1;
double _t4 = sizeof(list) / sizeof(list[0]);
{ goto blk11; }
blk11: ;
double _t5 = (double)list[(int)i-1];
printf("%lf\n", _t5 );
{ goto blk10; }
blk10: ;
i = (double)i+(double)1;
if(i<=_t4) { goto blk11; }
else { goto blk12; }
blk12: ;
return(0);
}
