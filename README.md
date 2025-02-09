# OOP-Basic-Concepts
In this repository, I have covered all the basic concepts of OOP using examples
## Virtual & Pure Virtual functions
<b>//Header file</b>  
#include"iostream"  
#include"iomanip"  
using namespace std;  
class base {  
protected:  
int x, y, sum;  
public:  
base();  
virtual void input() = 0;  
virtual void display();  
void Sum();  
virtual ~base();  
};  
class derived :public base {  
public:  
derived();  
void input();  
virtual void display();  
~derived();  
};
<br><br><b>//Function file</b>  
#include"Header.h"  
base::base() {  
cout << "\nbase constructor called";  
x = 0;  
y = 0;  
sum = 0;  
}  
void base:: display() {  
cout << "\n****Base class display****";  
cout << "\nx=" << x;  
cout << "\ny=" << y;  
}  
void base:: Sum() {  
cout << "\n\n****Base class function****";  
sum = x + y;  
cout << "\nsum=" << sum << endl;  
}  
base::~base()  
{  
cout << "\nBase destructor called" << endl;  
}  
derived::derived() {  
cout << "\nderived constructor called";  
}  
void derived:: input() {  
cout << endl;  
cout << "\n****derived class input****";  
cout << "\nEnter the value of x&y: ";  
cin >> x >> y;  
}  
void derived:: display() {  
cout << "\n****derived class display****";  
cout << "\nx=" << x;  
cout << "\ny=" << y;  
}  
derived::~derived()  
{  
cout << "\nderived destructor called";  
}
<br><br><b>//main file</b>  
#include"Header.h"  
int main() {  
base* b = new derived;  
b->input();  
b->display(); 
b->Sum();  
delete b;  
/*can also write above as  
base* b;  
derived d;  
b = &d;  
b->input();  
b->display();  
b->Sum();  
delete b;*/  
system("pause");  
return 0;  
}  

## Virtual Classes
<b>//Header file</b>
<br>#include"iostream"
<br>#include"iomanip"
<br>using namespace std;
<br>class base {
<br>public:
<br>void displayBase();
<br>};
<br>//used virtual class so that base class can be accessed through last class obj
<br>class derived1 :virtual public base {
<br>public:
<br>void displayDerived1();
<br>};
<br>class derived2 : virtual public base {
<br>public:
<br>void displayDerived2();
<br>};
<br> last : public derived1, public derived2 {
<br>:
<br>void displayLast();
<br>};
<br><br><b>//Function file</b>
<br>#include"Header.h"
<br>void base::displayBase() {
<br>cout << "\nBase class";
<br>}
<br>void derived1::displayDerived1() {
<br>cout << "\nderived class 1";
<br>}
<br>void derived2::displayDerived2() {
<br>cout << "\nderived class 2";
<br>}
<br>void last::displayLast() {
<br>cout << "\nlast class"<<endl;
<br>}
<br><br><b>//main file</b>
<br>#include"Header.h"
<br>int main() {
<br>last l;
<br>l.displayBase();
<br>l.displayDerived1();
<br>l.displayDerived2();
<br>l.displayLast();
<br>system("pause");
<br>return 0;
<br>}  

## Friend Function
<b>//Header file</b>
<br>#include"iostream"
<br>using namespace std;
<br>class base; 
<br>//forward declare base as compiler will not know if base class exists during executing multiply 
<br>function
<br>class derived
<br>//declared it before base so that friend void derived::multiply(base& b); will know derived class exists 
<br>{
<br>private:
<br>int y;
<br>int prod;
<br>public:
<br>derived();
<br>void multiply(base& b);
<br>};
<br>class base {
<br>private:
<br>int x;
<br>public:
<br>base();
<br>friend void derived::multiply(base& b);
<br>};
<br><br><b>//Function file</b>
<br>#include"Header.h"
<br>base::base() {
<br>x = 5;
<br>}
<br>void derived::multiply(base& b) {
<br>prod = b.x * y;
<br>cout << "\nProduct=" << prod<<endl;
<br>}
<br>derived::derived() {
<br>y = 3;
<br>prod = 0;
<br>}
<br><br><b>//Main file</b>
<br>#include"Header.h"
<br>int main() {
<br>base b;
<br>derived d;
<br>d.multiply(b);
<br>system("pause");
<br>return 0;
<br>}

## Friend Class
<b>//Header file</b>
<br>#include"iostream"
<br>using namespace std;
<br>class derived;
<br>class base {
<br>private:
<br>int x;
<br>public:
<br>base();
<br>friend derived;
<br>};
<br>class derived
<br>{
<br>private:
<br>int y;
<br>int prod;
<br>int sum;
<br>public:
<br>derived();
<br>void multiply(base&);
<br>void add(base&);
<br>};
<br><br><b>//Function file</b>
<br>#include"Header.h"
<br>base::base() {
<br>x = 5;
<br>}
<br>void derived::multiply(base& b) {
<br>prod = b.x * y;
<br>cout << "\nProduct=" << prod<<endl;
<br>}
<br>void derived::add(base& b) {
<br>sum = b.x+ y;
<br>cout << "Sum=" << sum << endl;
<br>}
<br>derived::derived() {
<br>y = 3;
<br>prod = 0;
<br>sum = 0;
<br>}
<br><br><b>//Main file</b>
<br>#include"Header.h"
<br>int main() {
<br>base b;
<br>derived d;
<br>d.multiply(b);
<br>d.add(b);
<br>system("pause");
<br>return 0;
<br>}

## Operator Overloading
<b>//Header file</b>
<br>#include "iostream"
<br>using namespace std;
<br>class overloading {
<br>private:
<br>int a;
<br>public:
<br>void input();
<br>void display();
<br>overloading operator +(overloading x2);
<br>void operator ++();
<br>void operator --(int);
<br>};
<br><br><b>//Function file</b>
<br>#include"Header.h"
<br>void overloading::input() {
<br>cin >> a;
<br>}
<br>void overloading::display() {
<br>cout << a;
<br>}
<br>overloading overloading:: operator +(overloading x2) {
<br>overloading temp;
<br>temp.a = a + x2.a;
<br>return temp;
<br>}
<br>void overloading::operator ++() {
<br>++a;
<br>}
<br>void overloading::operator --(int) {
<br>a--;
<br>}
<br><br><b>//Main file</b>
<br>#include"Header.h"
<br>int main() {
<br>overloading o1, o2, o3;
<br>cout << "\nEnter an integer value for object 1: ";
<br>o1.input();
<br>cout << "\nEnter an integer value for object 2: ";
<br>o2.input();
<br>cout << "\n\n****Binary overloading with class return type****";
<br>o3 = o1 + o2;
<br>cout << "\nValue of obj 3: ";
<br>o3.display();
<br>cout<<"\n\n****Preincrement unary overloading with void return type****";
<br>++o3;
<br>cout << "\nValue of obj 3: ";
<br>o3.display();
<br>cout<<"\n\n****Postdecrement unary overloading with void return type****";
<br>o3--;
<br>cout << "\nValue of obj 3: ";
<br>o3.display();
<br>cout << endl;
<br>system("pause");
<br>return 0;
<br>}

## Aggregation
<b>//header file</b>
<br>#include"iostream"
<br>#include"string"
<br>using namespace std;
<br>class office {
<br>private:
<br>string o_name;
<br>public:
<br>office(string o) {
<br>o_name = o;
<br>}
<br>void owork() {
<br>cout << "\nOffice is opened.";
<br>}
<br>};
<br>class employees {
<br>private:
<br>string e_name;
<br>public:
<br>office* off;
<br>employees(string e, office* o) 
<br>{
<br>off=o;
<br>e_name = e;
<br>}
<br>void ework() 
<br>{
<br>off->owork();
<br>cout << "\nEmployees are working.";
<br>}
<br>};
<br><br><b>//main file</b>
<br>#include"Header.h"
<br>int main() 
<br>{
<br>office o1("H&H");
<br>employees e1("Alishba",&o1);
<br>e1.ework();
<br>cout << endl;
<br>system("pause");
<br>return 0;
<br>}

## Composition
<b>//header file</b>
<br>#include"iostream"
<br>#include<string>
<br>using namespace std;
<br>class office {
<br>private:
<br>string o_name;
<br>public:
<br>office(string o) {
<br>o_name = o;
<br>}
<br>void owork() {
<br>cout << "\nOffice is opened.";
<br>}
<br>};
<br>class employees {
<br>private:
<br>string e_name;
<br>public:
<br>office off;
<br>employees(string e, string o):off(o){
<br>e_name = e;
<br>}
<br>void ework() 
<br>{
<br>off.owork();
<br>cout << "\nEmployees are working.";
<br>}
<br>};
<br><br><b>//main file</b>
<br>#include"Header.h"
<br>int main() 
<br>{
<br>employees e1("Alishba","H&H");
<br>e1.ework();
<br>cout << endl;
<br>system("pause");
<br>return 0;
<br>}

## Template for variables & arrays
<b>//Header file 1</b>
<br>#include"iostream"
<br>using namespace std;
<br>template <typename T, typename U>
<br>class base
<br>{
<br>private:
<br>T x;
<br>U y;
<br>public:
<br>base(T x1, U y1);
<br>void display();
<br>};
<br>template <typename T, typename U>
<br>base<T, U> ::base(T x1, U y1) {
<br>x = x1;
<br>y = y1;
<br>}
<br>template <typename T, typename U>
<br>void base<T, U> ::display() 
<br>{
<br>cout << "x=" << x;
<br>cout << "\ny=" << y << endl;
<br>}
<br>template <typename T, typename U>
<br>void base<T, U> ::display() {
<br>cout << "x=" << x;
<br>cout << "\ny=" << y << endl;
<br>}
<br><br><b>//Header file 2</b>
<br>template <typename W, typename S>
<br>class derived
<br>{
<br>private:
<br>W* ptr;
<br>S s;
<br>public:
<br>derived(W* arr, S size);
<br>void calculate();
<br>};
<br>template <typename W, typename S>
<br>derived<W,S>::derived(W* arr, S size) 
<br>{
<br>ptr = arr;
<br>s = size;
<br>}
<br>template <typename W, typename S>
<br>void derived<W, S>::calculate()
<br>{
<br>for (int i = 0; i < s; i++)
<br>{
<br>ptr[i]=ptr[i]+4;
<br>}
<br>for (int i = 0; i < s; i++) 
<br>{
<br>cout << "\nvalue " << i + 1 << ": " << *(ptr + i);
<br>}
<br>cout << endl;
<br>}
<br><br><b>//Main file</b>
<br>#include"Header.h"
<br>#include"Header1.h"
<br>int main() {
<br>base<int,char> b(3,'a');
<br>base<string, string> b1("Alishba", "Saboor");
<br>b.display();
<br>b1.display();
<br>cout << "\n**********************************\n";
<br>int arr[3] = { 3,8,5 };
<br>derived<int, int> d(arr, 3);
<br>d.calculate();
<br>system("pause");
<br>return 0;
<br>}

## Static members & functions
<b>//Header file</b>
<br>#include"iostream"
<br>using namespace std;
<br>class base {
<br>private:
<br>static int x;
<br>public:
<br>base();
<br>static void display();
<br>};
<br><br><b>//Function file</b>
<br>#include"Header.h"
<br>int base::x = 5;
<br>base::base() {
<br>x++;
<br>}
<br>void base::display() {
<br>cout << x;
<br>}
<br><br><b>//Main file</b>
<br>#include"Header.h"
<br>int main() {
<br>//all objects are sharing same memory
<br>cout << "Initial value of x:";
<br>base::display(); //static functions are accessed like this
<br>base b1;
<br>cout << "\nafter increment of x in obj 1:";
<br>base::display();
<br>base b2;
<br>cout << "\nafter increment of x in obj 2:";
<br>base::display();
<br>cout << endl;
<br>system("pause");
<br>return 0;
<br>}

## This pointer (this->)
<b>//Header file</b>
<br>#include"iostream"
<br>using namespace std;
<br>class base {
<br>private:
<br>int x,y;
<br>public:
<br>base(int x, int y);
<br>void check(base b2);
<br>int sum();
<br>base* address();
<br>};
<br><br><b>//Function file</b>
<br>#include"Header.h"
<br>base::base(int x, int y) {
<br>this->x=x; //when both data member & argument are represented by same variable
<br>this->y = y;
<br>}
<br>void base::check(base b2) {
<br>if (this->sum() > b2.sum()) //to call the functions
<br>cout << "\nSum of obj b1 is greater than b2.";
<br>else if (this->sum() < b2.sum())
<br>cout << "\nSum of obj b1 is less than b2.";
<br>else
<br>cout << "\nSum of both objects b1&b2 is equal";
<br>}
<br>int base::sum() {
<br>return (x + y);//sum of x&y of obj b1&b2
<br>}
<br>base* base::address() {
<br>return this; //to get the address of object
<br>}
<br><br><b>//Main file</b>
<br>#include"Header.h"
<br>int main() {
<br>base b1(3,2);
<br>base b2(5,3);
<br>b1.check(b2);
<br>cout<<"\nAddress of obj b1: "<<b1.address(); //to get the address of object
<br>cout << "\nAddress of obj b2: " << b2.address()<<endl;
<br>system("pause");
<br>return 0;
<br>}

## Insertion&extraction operator overloading (With file handling)
<b>//Header file</b>
<br>#include "iostream"
<br>#include"fstream"
<br>using namespace std;
<br>class base {
<br>private:
<br>int x, y;
<br>public:
<br>base() {
<br>x = 0;
<br>y = 0;
<br>}
<br>base(int x1, int y2) {
<br>x = x1;
<br>y = y2;
<br>}
<br>void display() {
<br>cout << x << "+" << y << "=" << x + y<<endl;
<br>}
<br>friend ofstream& operator <<(ofstream& out, base& b);
<br>friend ifstream& operator >> (ifstream& in, base& c);
<br>};
<br>ofstream& operator <<(ofstream& out, base& b) {
<br>out << b.x<<" "<<b.y;
<br>return out;
<br>}
<br>ifstream& operator >> (ifstream& in, base& c) {
<br>in >> c.x >> c.y;
<br>return in;
<br>}
<br><br><b>//main file</b>
<br>#include"Header.h"
<br>int main() {
<br>base b1(3,4),b2;
<br>ofstream f1("text.txt");
<br>if (f1.is_open()) {
<br>f1 << b1;
<br>f1.close();
<br>}
<br>else
<br>cerr << "\nError opening file.";
<br>ifstream f2("text.txt");
<br>if (!f2) 
<br>cerr << "\nFile not found.";
<br>else {
<br>if (f2.is_open()&& !f2.eof())
<br>{
<br>f2>> b2;
<br>f2.close();
<br>cout << "\nData read from file:\n";
<br>b2.display();
v}
<br>else
<br>cerr << "\nError opening file.";
<br>}
<br>system("pause");
<br>return 0;
<br>}

## Insertion&extraction operator overloading (Without file handling)
<b>//Header file</b>
<br>#include "iostream"
<br>using namespace std;
<br>class base {
<br>private:
<br>int x, y;
<br>public:
 <br>base() {
 <br>x = 0;
 <br>y = 0;
 <br>}
 <br>base(int x1, int y2) {
 <br>x = x1;
 <br>y = y2;
 <br>}
 
 <br><br>friend void operator <<(ostream& out, base& b);
 <br>friend void operator >> (istream& in, base& c);
<br>};
<br> operator <<(ostream& out, base& b) {
 <br>out << endl;
 <br>out << b.x << " " << b.y;
 <br>return;
<br>}
<br> operator >> (istream& in, base& c) {
 <br>cout << "\nEnter value of x and y: ";
 <br>in >> c.x >> c.y;
 <br>return;
<br>}
<br><br><b>//main file</b>
<br>#include"Header.h"
<br>int main() {
<br>base b1(3, 4), b2; cin >> b2;
<br>cout << b1;
<br>system("pause");
<br>return 0;
<br>}

## insertion/extraction operator overloading(calling base class  from derived class to overload)
<b>//Header file</b>
<br>#include "iostream"
<br>using namespace std;
<br>class person {
<br>private :
<br>string name;
<br>int id;
<br>public:
<br>person()
<br>{ name = "";
<br>id = 0;
<br>}
<br><br>friend istream& operator>>(istream& in, person& p)
<br>{
<br>cout << "\n Enter name and id";
<br>in >> p.name >> p.id;
<br>return in;
<br>}
<br>friend ostream& operator<<(ostream& out, const person& p)
<br>{
<br>out << "\n name :"<<p.name << ", Id :" << p.id;
<br>return out;
<br>}
<br>};
<br>class student:public person
<br>{
<br>protected:
<br>int marks[5];
<br>int sum;
<br>public:
<br>student()
<br>{
<br>sum = 0;
<br>marks[5] = {};
<br>}
<br><br>friend istream& operator>>(istream& in, student& s)
<br>{
<br>in >> static_cast<person&>(s);
<br>// This calls the overloaded >> for the person class
<br>cout << "\n enter marks for five subjects ";
<br>in.ignore();
<br>for (int i = 0; i < 5; i++)
<br>{
<br>in >> s.marks[i];
<br>s.sum += s.marks[i];
<br>}
<br>return in;
<br>}
<br>friend ostream& operator<<(ostream& out, student& s)
<br>{
<br>out << static_cast<const person&>(s);
<br>out << "\n marks for 5 subjects are ";
<br>for (int i = 0; i < 5; i++)
<br>{
<br>out << s.marks[i] << " ";
<br>}
<br>cout << endl;
<br>out <<"\n sum is "<< s.sum;
<br>return out;
<br>}
<br>};
<br><br><b>//main file</b>
<br>#include"Header.h"
<br>int main()
<br>{
<br>student stu;
<br>cout << "\n enter person details ";
<br>cin >>stu;
<br>cout << "\n displaying student details :";
<br>cout << stu;
<br>person p1, p2;
<br>cout << "\n Enter values for p1";
<br>cin >> p1;
<br>cout << "\n Enter values ofor p2";
<br>cin >> p2;
<br>cout << "\n P1= " << p1;
<br>cout << "\n P2= " << p2;*/
<br>return 0;
<br>}

## File Handling
<b>//Header file1</b>
<br>#include"iostream"
<br>#include"fstream"
<br>#include"string"
<br>using namespace std;
<br>class User {
<br>protected:
<br>string file;
<br>string course;
<br>int age;
<br>string batch;
<br>public:
<br>User();
<br>User(string f);
<br>void write();
vvoid read();
<br>};
<br><br><b>//Function file1</b>
<br>#include"Header1.h"
<br>User::User() {
<br>course = "";
<br>batch = "";
<br>age = 0;
<br>}
<br>User::User(string f) {
<br>file = f;
<br>}
<br>void User::write() {
<br>fstream f1(file);
<br>cout << "\nEnter your course: ";
<br>getline(cin, course);
<br>cout << "\nEnter your batch: ";
<br>getline(cin, batch);
<br>cout << "\nEnter your age: ";
<br>cin >> age;
<br>cin.ignore();
<br>if (f1.is_open())
<br>f1 << course << endl<< batch << endl<< age;
<br>else
<br>cerr << "\nError in opening file.";
<br>}
<br>void User::read() {
<br>ifstream f2("Text.txt");
<br>if (!f2)
<br>cerr << "\nFile does not exist";
<br>else
<br>{
<br>if (f2.is_open())
<br>{
<br>if (!f2.eof())
<br>{
<br>getline(f2, course);
<br>getline(f2, batch);
<br>f2 >> age;
<br>cout<<endl<<course<<endl<<batch<<endl<<age<<endl;
<br>}
<br>}
<br>else
<br>cerr << "\nFile can't be open.";
<br>}
<br>}
<br><br><b>//Header file2</b>
<br>#include"iostream"
<br>#include"fstream"
<br>#include"string"
<br>using namespace std;
<br>class BinaryUser
<br>{
<br>private:
<br>string file2;
<br>string bcourse;
<br>string bbatch;
<br>int bage;
<br>public:
<br>BinaryUser();
<br>BinaryUser(string f);
<br>void Binarywrite();
<br>void Binaryread();
<br>};
<br><br><b>//Function file2</b>
<br>#include"Header2.h"
<br>#include"iostream"
<br>#include"fstream"
<br>#include"string"
<br>using namespace std;
<br>BinaryUser::BinaryUser()
<br>{
<br>bcourse = "";
<br>bbatch = "";
<br>bage = 0;
<br>}
<br>BinaryUser::BinaryUser(string f) 
<br>{
<br>file2 = f;
<br>}
<br>void BinaryUser::Binarywrite() {
<br>ofstream f1(file2, ios::binary);
<br>cout << "\nEnter your course: ";
<br>getline(cin, bcourse);
<br>cout << "\nEnter your batch: ";
<br>getline(cin, bbatch);
<br>cout << "\nEnter your age: ";
<br>cin >> bage;
<br>cin.ignore();
<br>if (f1.is_open())
<br>{
<br>f1.write(reinterpret_cast<char*>(&bcourse), sizeof(bcourse));
<br>f1.write(reinterpret_cast<char*>(&bbatch), sizeof(bbatch));
<br>f1.write(reinterpret_cast<char*>(&bage), sizeof(bage));
<br> }
<br>else
<br>cerr << "\nError in opening file.";
<br>}
<br>void BinaryUser::Binaryread() {
<br>ifstream f2("BinaryText.txt");
<br>if (!f2)
<br>cerr << "\nFile does not exist";
<br>else
<br>{
<br>if (f2.is_open())
<br>{
<br>if (!f2.eof())
<br>{
<br>f2.read(reinterpret_cast<char*>(&bcourse), sizeof(bcourse));
<br>f2.read(reinterpret_cast<char*>(&bbatch), sizeof(bbatch));
<br>f2.read(reinterpret_cast<char*>(&bage), sizeof(bage));
<br>cout<<endl<<bcourse<< endl << bbatch << endl << bage << endl;
<br>}
<br>}
<br>else
<br>cerr << "\nFile can't be open.";
<br>}
<br>}
<br><br><b>//Main file</b>
<br>#include"Header1.h"
<br>#include"Header2.h"
<br>int main() {
<br>cout << "****For Text file****\n";
<br>User u1();
<br>User u2("Text.txt");
<br>u2.write();
<br>u2.read();
<br>cout << "\n****For Binary file****\n";
<br>BinaryUser b1();
<br>BinaryUser b2("BinaryText.txt");
<br>b2.Binarywrite();
<br>b2.Binaryread();
<br>system("pause");
<br>return 0;
<br>}
