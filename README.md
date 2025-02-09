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
<b>//Function file</b>  
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
<b>//main file</b>  
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

##Friend Function
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

##Friend Class
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