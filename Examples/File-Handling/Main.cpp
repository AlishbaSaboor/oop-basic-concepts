#include"Header1.h"
#include"Header2.h"
int main() 
{
cout << "****For Text file****\n";
User u1();
User u2("Text.txt");
u2.write();
u2.read();
cout << "\n****For Binary file****\n";
BinaryUser b1();
BinaryUser b2("BinaryText.txt");
b2.Binarywrite();
b2.Binaryread();
system("pause");
return 0;
}