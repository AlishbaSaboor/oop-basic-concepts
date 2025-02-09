# OOP-Basic-Concepts
In this repository, I have covered all the basic concepts of OOP using examples
## Virtual & Pure Virtual functions
//Header file
#include<iostream>
#include<iomanip>
using namespace std;g
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
//Function file
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
//main file
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