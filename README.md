# OOP-Basic-Concepts
In this repository, I have covered all the basic concepts of OOP using examples
## Virtual & Pure Virtual functions
<b>//Header file</b>  
#include<iostream>  
#include<iomanip>  
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
<br><b>//Header file</b>
<br>#include<iostream>
<br>#include<iomanip>
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