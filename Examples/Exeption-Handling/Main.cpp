#include"Header.h"
int main() 
{
base b(13);
try {
b.check();
}
catch(const char* statement){
cout << statement;
}
cout << endl;
system("pause");
return 0;
}