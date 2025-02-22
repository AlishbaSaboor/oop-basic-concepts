#include"iostream"
#include"string"
using namespace std;
class base 
{
private:
int age;
public:
base(int a) 
{
age = a;
}
void check() 
{
if (age < 17) 
{
throw ("Don't display website dashboard.");
}
cout << "\nDisplay dashboard";
}
};