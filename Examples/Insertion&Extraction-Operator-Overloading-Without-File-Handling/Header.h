#include "iostream"
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
 
 friend void operator <<(ostream& out, base& b);
 friend void operator >> (istream& in, base& c);
};
 operator <<(ostream& out, base& b) 
 {
 out << endl;
 out << b.x << " " << b.y;
 return;
}
 operator >> (istream& in, base& c) 
 {
 cout << "\nEnter value of x and y: ";
 in >> c.x >> c.y;
 return;
}