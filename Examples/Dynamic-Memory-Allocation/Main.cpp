#include"Header.h"
int main() 
{
User* u = new User; //int* i=new int;
u->sum();
u->display();
delete u;
system("pause");
return 0;
}