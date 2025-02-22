#include"Header.h"
void overloading::input() 
{
cin >> a;
}
void overloading::display() 
{
cout << a;
}
overloading overloading:: operator +(overloading x2) 
{
overloading temp;
temp.a = a + x2.a;
return temp;
}
void overloading::operator ++() 
{
++a;
}
void overloading::operator --(int) 
{
a--;
}