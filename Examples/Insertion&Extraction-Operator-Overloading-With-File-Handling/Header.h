#include "iostream"
#include"fstream"
using namespace std;
class base 
{
private:
int x, y;
public:
base() 
{
x = 0;
y = 0;
}
base(int x1, int y2) 
{
x = x1;
y = y2;
}
void display() 
{
cout << x << "+" << y << "=" << x + y<<endl;
}
friend ofstream& operator <<(ofstream& out, base& b);
friend ifstream& operator >> (ifstream& in, base& c);
};
ofstream& operator <<(ofstream& out, base& b) 
{
out << b.x<<" "<<b.y;
return out;
}
ifstream& operator >> (ifstream& in, base& c) 
{
in >> c.x >> c.y;
return in;
}