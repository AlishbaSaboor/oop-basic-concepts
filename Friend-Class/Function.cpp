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
void derived::add(base& b) 
{
sum = b.x+ y;
cout << "Sum=" << sum << endl;
}
derived::derived() 
{
y = 3;
prod = 0;
sum = 0;
}