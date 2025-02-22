#include "iostream"
using namespace std;
class person 
{
private :
string name;
int id;
public:
person()
{ 
name = "";
id = 0;
}
friend istream& operator>>(istream& in, person& p)
{
cout << "\n Enter name and id";
in >> p.name >> p.id;
return in;
}
friend ostream& operator<<(ostream& out, const person& p)
{
out << "\n name :"<<p.name << ", Id :" << p.id;
return out;
}
};
class student:public person
{
protected:
int marks[5];
int sum;
public:
student()
{
sum = 0;
marks[5] = {};
}
friend istream& operator>>(istream& in, student& s)
{
in >> static_cast<person&>(s);
// This calls the overloaded >> for the person class
cout << "\n enter marks for five subjects ";
in.ignore();
for (int i = 0; i < 5; i++)
{
in >> s.marks[i];
s.sum += s.marks[i];
}
return in;
}
friend ostream& operator<<(ostream& out, student& s)
{
out << static_cast<const person&>(s);
out << "\n marks for 5 subjects are ";
for (int i = 0; i < 5; i++)
{
out << s.marks[i] << " ";
}
cout << endl;
out <<"\n sum is "<< s.sum;
return out;
}
};