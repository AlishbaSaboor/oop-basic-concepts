#include"Header.h"
int main() 
{
//all objects are sharing same memory
cout << "Initial value of x:";
base::display(); //static functions are accessed like this
base b1;
cout << "\nafter increment of x in obj 1:";
base::display();
base b2;
cout << "\nafter increment of x in obj 2:";
base::display();
cout << endl;
system("pause");
return 0;
}