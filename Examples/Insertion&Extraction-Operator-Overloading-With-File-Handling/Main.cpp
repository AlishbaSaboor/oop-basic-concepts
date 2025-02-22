#include"Header.h"
int main() 
{
base b1(3,4),b2;
ofstream f1("text.txt");
if (f1.is_open()) {
f1 << b1;
f1.close();
}
else
cerr << "\nError opening file.";
ifstream f2("text.txt");
if (!f2) 
cerr << "\nFile not found.";
else {
if (f2.is_open()&& !f2.eof())
{
f2>> b2;
f2.close();
cout << "\nData read from file:\n";
b2.display();
v}
else
cerr << "\nError opening file.";
}
system("pause");
return 0;
}