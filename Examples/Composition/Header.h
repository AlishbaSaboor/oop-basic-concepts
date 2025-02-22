#include"iostream"
#include<string>
using namespace std;
class office 
{
private:
string o_name;
public:
office(string o) {
o_name = o;
}
void owork() {
cout << "\nOffice is opened.";
}
};
class employees 
{
private:
string e_name;
public:
office off;
employees(string e, string o):off(o){
e_name = e;
}
void ework() 
{
off.owork();
cout << "\nEmployees are working.";
}
};