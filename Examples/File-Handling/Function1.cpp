#include"Header1.h"
User::User() 
{
course = "";
batch = "";
age = 0;
}
User::User(string f) 
{
file = f;
}
void User::write() 
{
fstream f1(file);
cout << "\nEnter your course: ";
getline(cin, course);
cout << "\nEnter your batch: ";
getline(cin, batch);
cout << "\nEnter your age: ";
cin >> age;
cin.ignore();
if (f1.is_open())
f1 << course << endl<< batch << endl<< age;
else
cerr << "\nError in opening file.";
}
void User::read() 
{
ifstream f2("Text.txt");
if (!f2)
cerr << "\nFile does not exist";
else
{
if (f2.is_open())
{
if (!f2.eof())
{
getline(f2, course);
getline(f2, batch);
f2 >> age;
cout<<endl<<course<<endl<<batch<<endl<<age<<endl;
}
}
else
cerr << "\nFile can't be open.";
}
}