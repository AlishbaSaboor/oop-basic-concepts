#include"Header.h"
int main() 
{
base b1(3,2);
base b2(5,3);
b1.check(b2);
cout<<"\nAddress of obj b1: "<<b1.address(); //to get the address of object
cout << "\nAddress of obj b2: " << b2.address()<<endl;
system("pause");
return 0;
}