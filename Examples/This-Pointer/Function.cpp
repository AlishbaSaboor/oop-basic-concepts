#include"Header.h"
base::base(int x, int y) 
{
this->x=x; //when both data member & argument are represented by same variable
this->y = y;
}
void base::check(base b2) 
{
if (this->sum() > b2.sum()) //to call the functions
cout << "\nSum of obj b1 is greater than b2.";
else if (this->sum() < b2.sum())
cout << "\nSum of obj b1 is less than b2.";
else
cout << "\nSum of both objects b1&b2 is equal";
}
int base::sum() 
{
return (x + y);//sum of x&y of obj b1&b2
}
base* base::address() 
{
return this; //to get the address of object
}