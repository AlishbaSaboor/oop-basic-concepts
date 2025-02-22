#include"iostream"  
#include"iomanip"  
using namespace std;  
class base 
{  
protected:  
int x, y, sum;  
public:  
base();  
virtual void input() = 0;  
virtual void display();  
void Sum();  
virtual ~base();  
};  
class derived :public base 
{  
public:  
derived();  
void input();  
virtual void display();  
~derived();  
};