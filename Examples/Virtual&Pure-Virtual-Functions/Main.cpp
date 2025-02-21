```cpp
#include"Header.h"  
int main() 
{  
base* b = new derived;  
b->input();  
b->display(); 
b->Sum();  
delete b;  
/*can also write above as  
base* b;  
derived d;  
b = &d;  
b->input();  
b->display();  
b->Sum();  
delete b;*/  
system("pause");  
return 0;  
} 