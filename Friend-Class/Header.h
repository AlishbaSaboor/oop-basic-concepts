#include"iostream"
using namespace std;
class derived;
class base 
{
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