#include"iostream"
using namespace std;
class base 
{
private:
int x,y;
public:
base(int x, int y);
void check(base b2);
int sum();
base* address();
};