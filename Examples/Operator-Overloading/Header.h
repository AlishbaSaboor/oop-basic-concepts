#include "iostream"
using namespace std;
class overloading 
{
private:
int a;
public:
void input();
void display();
overloading operator +(overloading x2);
void operator ++();
void operator --(int);
};