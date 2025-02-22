#include"Header2.h"
#include"iostream"
#include"fstream"
#include"string"
using namespace std;
BinaryUser::BinaryUser()
{
bcourse = "";
bbatch = "";
bage = 0;
}
BinaryUser::BinaryUser(string f) 
{
file2 = f;
}
void BinaryUser::Binarywrite() 
{
ofstream f1(file2, ios::binary);
cout << "\nEnter your course: ";
getline(cin, bcourse);
cout << "\nEnter your batch: ";
getline(cin, bbatch);
cout << "\nEnter your age: ";
cin >> bage;
cin.ignore();
if (f1.is_open())
{
f1.write(reinterpret_cast<char*>(&bcourse), sizeof(bcourse));
f1.write(reinterpret_cast<char*>(&bbatch), sizeof(bbatch));
f1.write(reinterpret_cast<char*>(&bage), sizeof(bage));
 }
else
cerr << "\nError in opening file.";
}
void BinaryUser::Binaryread() 
{
ifstream f2("BinaryText.txt");
if (!f2)
cerr << "\nFile does not exist";
else
{
if (f2.is_open())
{
if (!f2.eof())
{
f2.read(reinterpret_cast<char*>(&bcourse), sizeof(bcourse));
f2.read(reinterpret_cast<char*>(&bbatch), sizeof(bbatch));
f2.read(reinterpret_cast<char*>(&bage), sizeof(bage));
cout<<endl<<bcourse<< endl << bbatch << endl << bage << endl;
}
}
else
cerr << "\nFile can't be open.";
}
}