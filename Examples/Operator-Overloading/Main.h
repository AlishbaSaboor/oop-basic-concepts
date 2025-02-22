#include"Header.h"
int main() 
{
overloading o1, o2, o3;
cout << "\nEnter an integer value for object 1: ";
o1.input();
cout << "\nEnter an integer value for object 2: ";
o2.input();
cout << "\n\n****Binary overloading with class return type****";
o3 = o1 + o2;
cout << "\nValue of obj 3: ";
o3.display();
cout<<"\n\n****Preincrement unary overloading with void return type****";
++o3;
cout << "\nValue of obj 3: ";
o3.display();
cout<<"\n\n****Postdecrement unary overloading with void return type****";
o3--;
cout << "\nValue of obj 3: ";
o3.display();
cout << endl;
system("pause");
return 0;
}