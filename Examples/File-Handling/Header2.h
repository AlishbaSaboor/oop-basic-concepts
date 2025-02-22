#include"iostream"
#include"fstream"
#include"string"
using namespace std;
class BinaryUser
{
private:
string file2;
string bcourse;
string bbatch;
int bage;
public:
BinaryUser();
BinaryUser(string f);
void Binarywrite();
void Binaryread();
};