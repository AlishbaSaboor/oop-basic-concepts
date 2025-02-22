#include"iostream"
using namespace std;
class User 
{
private:
int a=2, b=3, c;
public:
void sum() 
{
c = a + b;
}
void display() 
{
cout << "\nSum=" << c<<endl;
}
};