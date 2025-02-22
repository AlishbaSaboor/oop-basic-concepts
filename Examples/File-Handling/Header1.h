#include"iostream"
#include"fstream"
#include"string"
using namespace std;
class User 
{
protected:
string file;
string course;
int age;
string batch;
public:
User();
User(string f);
void write();
vvoid read();
};