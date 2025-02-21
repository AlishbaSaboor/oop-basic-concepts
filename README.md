# OOP-Basic-Concepts
In this repository, I have covered all the basic concepts of OOP using examples. The basic concepts of OOP include:
- Virtual & Pure Virtual functons(Abstract Classes)
- Virtual Classes
- Friend Functions & Classes
- Operator Overloading
- Aggregation & Composition
- Templates for variables & arrays
- Static members & functions
- This pointer (this->)
- Insertion & Extraction overloading (with & without file handling, by calling base from derived class different method)
- File Handling
- Exeption Handling
- Dynamic Memory Allocation for objects
- Basic C++ concepts (Dynamic memory allocation for variables, Passing dynamic array to function, Passing static array to function, Functions returning pointer, Pointers storing another pointers, String Functions)
---
## Virtual & Pure Virtual functions
## Virtual Classes


 

## Friend Function
<b>//Header file</b>
#include"iostream"
using namespace std;
class base; 
//forward declare base as compiler will not know if base class exists during executing multiply 
function
class derived
//declared it before base so that friend void derived::multiply(base& b); will know derived class exists 
{
private:
int y;
int prod;
public:
derived();
void multiply(base& b);
};
class base {
private:
int x;
public:
base();
friend void derived::multiply(base& b);
};
<b>//Function file</b>
#include"Header.h"
base::base() {
x = 5;
}
void derived::multiply(base& b) {
prod = b.x * y;
cout << "\nProduct=" << prod<<endl;
}
derived::derived() {
y = 3;
prod = 0;
}
<b>//Main file</b>
#include"Header.h"
int main() {
base b;
derived d;
d.multiply(b);
system("pause");
return 0;
}

## Friend Class
<b>//Header file</b>
#include"iostream"
using namespace std;
class derived;
class base {
private:
int x;
public:
base();
friend derived;
};
class derived
{
private:
int y;
int prod;
int sum;
public:
derived();
void multiply(base&);
void add(base&);
};
<b>//Function file</b>
#include"Header.h"
base::base() {
x = 5;
}
void derived::multiply(base& b) {
prod = b.x * y;
cout << "\nProduct=" << prod<<endl;
}
void derived::add(base& b) {
sum = b.x+ y;
cout << "Sum=" << sum << endl;
}
derived::derived() {
y = 3;
prod = 0;
sum = 0;
}
<b>//Main file</b>
#include"Header.h"
int main() {
base b;
derived d;
d.multiply(b);
d.add(b);
system("pause");
return 0;
}

## Operator Overloading
<b>//Header file</b>
#include "iostream"
using namespace std;
class overloading {
private:
int a;
public:
void input();
void display();
overloading operator +(overloading x2);
void operator ++();
void operator --(int);
};
<b>//Function file</b>
#include"Header.h"
void overloading::input() {
cin >> a;
}
void overloading::display() {
cout << a;
}
overloading overloading:: operator +(overloading x2) {
overloading temp;
temp.a = a + x2.a;
return temp;
}
void overloading::operator ++() {
++a;
}
void overloading::operator --(int) {
a--;
}
<b>//Main file</b>
#include"Header.h"
int main() {
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

## Aggregation
<b>//header file</b>
#include"iostream"
#include"string"
using namespace std;
class office {
private:
string o_name;
public:
office(string o) {
o_name = o;
}
void owork() {
cout << "\nOffice is opened.";
}
};
class employees {
private:
string e_name;
public:
office* off;
employees(string e, office* o) 
{
off=o;
e_name = e;
}
void ework() 
{
off->owork();
cout << "\nEmployees are working.";
}
};
<b>//main file</b>
#include"Header.h"
int main() 
{
office o1("H&H");
employees e1("Alishba",&o1);
e1.ework();
cout << endl;
system("pause");
return 0;
}

## Composition
<b>//header file</b>
#include"iostream"
#include<string>
using namespace std;
class office {
private:
string o_name;
public:
office(string o) {
o_name = o;
}
void owork() {
cout << "\nOffice is opened.";
}
};
class employees {
private:
string e_name;
public:
office off;
employees(string e, string o):off(o){
e_name = e;
}
void ework() 
{
off.owork();
cout << "\nEmployees are working.";
}
};
<b>//main file</b>
#include"Header.h"
int main() 
{
employees e1("Alishba","H&H");
e1.ework();
cout << endl;
system("pause");
return 0;
}

## Template for variables & arrays
<b>//Header file 1</b>
#include"iostream"
using namespace std;
template <typename T, typename U>
class base
{
private:
T x;
U y;
public:
base(T x1, U y1);
void display();
};
template <typename T, typename U>
base<T, U> ::base(T x1, U y1) {
x = x1;
y = y1;
}
template <typename T, typename U>
void base<T, U> ::display() 
{
cout << "x=" << x;
cout << "\ny=" << y << endl;
}
template <typename T, typename U>
void base<T, U> ::display() {
cout << "x=" << x;
cout << "\ny=" << y << endl;
}
<b>//Header file 2</b>
template <typename W, typename S>
class derived
{
private:
W* ptr;
S s;
public:
derived(W* arr, S size);
void calculate();
};
template <typename W, typename S>
derived<W,S>::derived(W* arr, S size) 
{
ptr = arr;
s = size;
}
template <typename W, typename S>
void derived<W, S>::calculate()
{
for (int i = 0; i < s; i++)
{
ptr[i]=ptr[i]+4;
}
for (int i = 0; i < s; i++) 
{
cout << "\nvalue " << i + 1 << ": " << *(ptr + i);
}
cout << endl;
}
<b>//Main file</b>
#include"Header.h"
#include"Header1.h"
int main() {
base<int,char> b(3,'a');
base<string, string> b1("Alishba", "Saboor");
b.display();
b1.display();
cout << "\n**********************************\n";
int arr[3] = { 3,8,5 };
derived<int, int> d(arr, 3);
d.calculate();
system("pause");
return 0;
}

## Static members & functions
<b>//Header file</b>
#include"iostream"
using namespace std;
class base {
private:
static int x;
public:
base();
static void display();
};
<b>//Function file</b>
#include"Header.h"
int base::x = 5;
base::base() {
x++;
}
void base::display() {
cout << x;
}
<b>//Main file</b>
#include"Header.h"
int main() {
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

## This pointer (this->)
<b>//Header file</b>
#include"iostream"
using namespace std;
class base {
private:
int x,y;
public:
base(int x, int y);
void check(base b2);
int sum();
base* address();
};
<b>//Function file</b>
#include"Header.h"
base::base(int x, int y) {
this->x=x; //when both data member & argument are represented by same variable
this->y = y;
}
void base::check(base b2) {
if (this->sum() > b2.sum()) //to call the functions
cout << "\nSum of obj b1 is greater than b2.";
else if (this->sum() < b2.sum())
cout << "\nSum of obj b1 is less than b2.";
else
cout << "\nSum of both objects b1&b2 is equal";
}
int base::sum() {
return (x + y);//sum of x&y of obj b1&b2
}
base* base::address() {
return this; //to get the address of object
}
<b>//Main file</b>
#include"Header.h"
int main() {
base b1(3,2);
base b2(5,3);
b1.check(b2);
cout<<"\nAddress of obj b1: "<<b1.address(); //to get the address of object
cout << "\nAddress of obj b2: " << b2.address()<<endl;
system("pause");
return 0;
}

## Insertion&extraction operator overloading (With file handling)
<b>//Header file</b>
#include "iostream"
#include"fstream"
using namespace std;
class base {
private:
int x, y;
public:
base() {
x = 0;
y = 0;
}
base(int x1, int y2) {
x = x1;
y = y2;
}
void display() {
cout << x << "+" << y << "=" << x + y<<endl;
}
friend ofstream& operator <<(ofstream& out, base& b);
friend ifstream& operator >> (ifstream& in, base& c);
};
ofstream& operator <<(ofstream& out, base& b) {
out << b.x<<" "<<b.y;
return out;
}
ifstream& operator >> (ifstream& in, base& c) {
in >> c.x >> c.y;
return in;
}
<b>//main file</b>
#include"Header.h"
int main() {
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

## Insertion&extraction operator overloading (Without file handling)
<b>//Header file</b>
#include "iostream"
using namespace std;
class base {
private:
int x, y;
public:
 base() {
 x = 0;
 y = 0;
 }
 base(int x1, int y2) {
 x = x1;
 y = y2;
 }
 
 friend void operator <<(ostream& out, base& b);
 friend void operator >> (istream& in, base& c);
};
 operator <<(ostream& out, base& b) {
 out << endl;
 out << b.x << " " << b.y;
 return;
}
 operator >> (istream& in, base& c) {
 cout << "\nEnter value of x and y: ";
 in >> c.x >> c.y;
 return;
}
<b>//main file</b>
#include"Header.h"
int main() {
base b1(3, 4), b2; cin >> b2;
cout << b1;
system("pause");
return 0;
}

## insertion/extraction operator overloading(calling base class  from derived class to overload)
<b>//Header file</b>
#include "iostream"
using namespace std;
class person {
private :
string name;
int id;
public:
person()
{ name = "";
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
<b>//main file</b>
#include"Header.h"
int main()
{
student stu;
cout << "\n enter person details ";
cin >>stu;
cout << "\n displaying student details :";
cout << stu;
person p1, p2;
cout << "\n Enter values for p1";
cin >> p1;
cout << "\n Enter values ofor p2";
cin >> p2;
cout << "\n P1= " << p1;
cout << "\n P2= " << p2;*/
return 0;
}

## File Handling
<b>//Header file1</b>
#include"iostream"
#include"fstream"
#include"string"
using namespace std;
class User {
protected:
string file;
string course;
int age;
string batch;
public:
User();
User(string f);
void write();
vvoid read();
};
<b>//Function file1</b>
#include"Header1.h"
User::User() {
course = "";
batch = "";
age = 0;
}
User::User(string f) {
file = f;
}
void User::write() {
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
void User::read() {
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
<b>//Header file2</b>
#include"iostream"
#include"fstream"
#include"string"
using namespace std;
class BinaryUser
{
private:
string file2;
string bcourse;
string bbatch;
int bage;
public:
BinaryUser();
BinaryUser(string f);
void Binarywrite();
void Binaryread();
};
<b>//Function file2</b>
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
void BinaryUser::Binarywrite() {
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
void BinaryUser::Binaryread() {
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
<b>//Main file</b>
#include"Header1.h"
#include"Header2.h"
int main() {
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

## Exeption Handling
<b>//header file</b>
#include"iostream"
#include"string"
using namespace std;
class base {
private:
int age;
public:
base(int a) {
age = a;
}
void check() {
if (age < 17) {
throw ("Don't display website dashboard.");
}
cout << "\nDisplay dashboard";
}
};
<b>//Main file</b>
#include"Header.h"
int main() {
base b(13);
try {
b.check();
}
catch(const char* statement){
cout << statement;
}
cout << endl;
system("pause");
return 0;
}

## Dynamic Memory Allocation(for object)
<b>//header file</b>
#include"iostream"
using namespace std;
class User {
private:
int a=2, b=3, c;
public:
void sum() {
c = a + b;
}
void display() {
cout << "\nSum=" << c<<endl;
}
};
<b>//Main file</b>
#include"Header.h"
int main() {
User* u = new User; //int* i=new int;
u->sum();
u->display();
delete u;
system("pause");
return 0;
}

# Simple C++ Concepts

## Dynamic Memory Allocation(for variables)
#include"iostream"
#include"string"
using namespace std;
int main() {
int size = 3;
//for single variable
string* name = new string;
cout << "\nEnter your name: ";
getline(cin, *name);
cout << "\nYour Name: " << *name;
cout << "\n***************************\n";
cout << endl;
//for array 
string* names=new string[size];
for (int i = 0;i < size;i++)
{
cout << "Enter the name of student " << i + 1 << ": ";
getline(cin, *(names + i));
cout << endl << endl;;
}
for (int i = 0;i < size;i++)
{
cout << "Name of student " << i + 1 << ": "<<*(names + i);
cout << endl;
}
delete name;
delete[] names;
system("pause");
return 0;
}

 ## Passing dynamic array to function:
#include"iostream"
#include"string"
using namespace std;
void call(string* names, int size);
int main() {
int size = 3;
string* names=new string[size];
for (int i = 0;i < size;i++)
{
cout << "Enter the name of student " << i + 1 << ": ";
getline(cin, *(names + i));
cout << endl;
}
cout << endl;
call(names,size);
delete[] names;
system("pause");
return 0;
}
void call(string *names,int size)
{
for (int i = 0;i < size;i++)
{
cout << "Name of student " << i + 1 << ": " << *(names + i);
cout << endl;
}
return;
}

## Passing static array to function(method 1)
#include"iostream"
#include"string"
using namespace std;
void call(string* name, int size);
int main() {
int size = 3;
string name[3];
for (int i = 0;i < 3;i++)
{
cout << "Enter the name of student " << i + 1 << ": ";
getline(cin, name[i]);
cout << endl;
}
cout << endl;
call(name,size);
system("pause");
return 0;
}
void call(string *name,int size)
{
for (int i = 0;i < size;i++)
{
cout << "Name of student " << i + 1 << ": " << name[i];
cout << endl;
//OR 
/*for (int i = 0;i < size;i++)
{
cout << "Name of student " << i + 1 << ": " << *(name + i);
cout << endl;
 }*/
return;
}

## Passing static array to function(method 2)
#include"iostream"
#include"string"
using namespace std;
void call(string*, int);
int main() {
int size = 3;
string name[3];
for (int i = 0;i < 3;i++)
{
cout << "Enter the name of student " << i + 1 << ": ";
getline(cin, name[i]);
cout << endl;
}
cout << endl;
call(name, size);
system("pause");
return 0;
}
void call(string n[], int s)
{
for (int i = 0;i < s;i++)
{
cout << "Name of student " << i + 1 << ": " << n[i];
cout << endl;
}
return;
}

## Functions returning pointer
#include"iostream"
using namespace std;
int* sum(int&, int&);
int main() {
int a=3, b=4;
int* c;
c = sum(a, b);
cout << "sum=" << *c<<endl;
system("pause");
return 0;
}
int* sum(int& a, int& b)
{
static int x = a + b;
//can only use static or new operator for x as it is declared locally when compiler comes out of function it destroyes full function including x variable 
return (&x);
}

## Pointers storing another pointer
#include"iostream"
#include"iomanip"
using namespace std;
int main() {
int b = 4;
int* p1 = &b;
int** p2 = &p1;
cout << left;
cout << setw(7) << "b"<< setw(30) << b;
cout << endl;
cout << setw(7) << "&b" <<setw(30)<< & b;
cout << endl;
cout << setw(7) << "p1" << setw(30) << p1;
cout << endl;
cout << setw(7) << "*p1" << setw(30) << *p1;
cout << endl;
cout << setw(7) << "&p1" << setw(30) << &p1;
cout << endl;
cout << setw(7) << "p2" << setw(30) << p2;
cout << endl;
cout << setw(7) << "*p2" << setw(30) << *p2;
cout << endl;
cout << setw(7) << "**p2" << setw(30) << **p2;
cout << endl;
cout << setw(7) << "&p2" << setw(30) << &p2;
cout << endl;
system("pause");
return 0;
}

## String Functions
#include"iostream"
#include"iomanip"
#include"string"
#include"cstring"
using namespace std;
int main() {
//for both string and character array
string s1, s2, s3;
s1 = "Alishba";
s2 = "Saboor";
char ch1[20] = { 'M','a','r','i','a','\0'};
char ch2[20] = { 'H','a','f','e','e','z','\0'};
//finding character in character array
char* ptr1 = strchr(ch1, 'i');
if (ptr1) {
cout << "Character found at: " << ptr1 - ch1;
//subtracts the addresses to get location of a specific characters
}
//finding character in string
int pos1 = s1.find('b'); //better to use size_t data type instead of int 
if (pos1 != string::npos) //pos1(valid position). npos(invalid position)
{
cout << "\nCharacter found at: " << pos1;
}
cout << endl;
//length of string 
cout << "\nLength of character array (Maria): " << strlen(ch1);
//length of character array
cout << "\nLength of string (Alishba): " << s1.length();
cout << endl;
//compare strings for character arrays
int result=strcmp(ch1, ch2);
if (result == 0) {
cout << "Both are Equal.";
}
else if (result == -1) {
cout << "\nMaria is less than Hafeez.";
}
else if (result == 1) {
cout << "\nMaria is greater than Hafeez.";
}
//compare strings for string
if (s1 == s2) {
cout << "Both are Equal.";
}
else if (s1< s2) {
cout << "\nAlishba is less than Saboor.";
}
else if (s1>s2) {
cout << "\nAlishba is greater than Saboor.";
}
cout << endl;
//concatenation for character arrays
strcat_s(ch1, ch2); //strcat can also be used but thats used for old versions 
cout<<"\nConcatenation of character array: "<<ch1;
//concatenation for strings
s3 = s1 + s2;
cout << "\nConcatenation of string: " << s3;
cout << endl;
//copying of character arrays
strcpy_s(ch1, ch2);
cout << "\nAfter copying 2nd name to 1st name: " << ch1;
//copying of strings
s1 = s2;
cout << "\nAfter copying 2nd name to 1st name: " << s1;
cout << endl;
//finding substring in string
char extra1[20] = { 'M','a','r','i','a',' ','H','a','f','e','e','z' };
char* ptr2 = strstr(extra1, "Hafeez");
if (ptr2) {
cout << "\nSubstring found at: " << ptr2 - extra1;
}
//finding substring in character arrays
string extra2 = "Alishba Saboor";
int pos2 = extra2.find("Saboor");
if (pos2 != string::npos) {
cout << "\nSubstring found at: " << pos2;
}
cout << endl<<endl;
system("pause");
return 0;
}

## Find & Replace functions in string
#include"iostream"
#include"iomanip"
#include"string"
#include"cstring"
using namespace std;
int main() {
string name = "Object Oriented Paradigm";
string n = "Paradigm";
cout << "\n****Before modification****";
cout << "\nString: " << name<<endl;
int pos = name.find(n);//name.find finds the index/address of string
if (pos != string::npos) { //npos functions tells if no match found of your string
cout << "\nParadigm found at position: " << pos<<endl;
}
name.replace(pos, n.length(), "Programming"); 
//syntax: variable.replace(starting position, length of word, the word to be replaced with)
cout << "\n****After replacing Paradigm with Programming****";
cout << "\nString: " << name;
cout << endl<<endl;
system("pause");
return 0;
}