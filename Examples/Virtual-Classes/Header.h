#include"iostream"
#include"iomanip"
using namespace std;
class base 
{
public:
void displayBase();
};
//used virtual class so that base class can be accessed through last class obj
class derived1 :virtual public base 
{
public:
void displayDerived1();
};
class derived2 : virtual public base 
{
public:
void displayDerived2();
};
class last : public derived1, public derived2 
{
void displayLast();
};