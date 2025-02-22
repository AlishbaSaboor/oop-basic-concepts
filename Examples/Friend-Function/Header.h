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
class base 
{
private:
int x;
public:
base();
friend void derived::multiply(base& b);
};