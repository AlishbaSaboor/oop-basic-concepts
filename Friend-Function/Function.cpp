#include"Header.h"
base::base() 
{
x = 5;
}
void derived::multiply(base& b) 
{
prod = b.x * y;
cout << "\nProduct=" << prod<<endl;
}
derived::derived() 
{
y = 3;
prod = 0;
}