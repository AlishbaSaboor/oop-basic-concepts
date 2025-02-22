#include"iostream"
using namespace std;
template <typename T, typename U>
class base
{
private:
T x;
U y;
public:
base(T x1, U y1);
void display();
};
template <typename T, typename U>
base<T, U> ::base(T x1, U y1) 
{
x = x1;
y = y1;
}
template <typename T, typename U>
void base<T, U> ::display() 
{
cout << "x=" << x;
cout << "\ny=" << y << endl;
}
template <typename T, typename U>
void base<T, U> ::display() 
{
cout << "x=" << x;
cout << "\ny=" << y << endl;
}