#include"Header.h"  
base::base() 
{  
cout << "\nbase constructor called";  
x = 0;  
y = 0;  
sum = 0;  
}  
void base:: display() 
{  
cout << "\n****Base class display****";  
cout << "\nx=" << x;  
cout << "\ny=" << y;  
}  
void base:: Sum() 
{  
cout << "\n\n****Base class function****";  
sum = x + y;  
cout << "\nsum=" << sum << endl;  
}  
base::~base()  
{  
cout << "\nBase destructor called" << endl;  
}  
derived::derived() 
{  
cout << "\nderived constructor called";  
}  
void derived:: input() 
{  
cout << endl;  
cout << "\n****derived class input****";  
cout << "\nEnter the value of x&y: ";  
cin >> x >> y;  
}  
void derived:: display() 
{  
cout << "\n****derived class display****";  
cout << "\nx=" << x;  
cout << "\ny=" << y;  
}  
derived::~derived()  
{  
cout << "\nderived destructor called";  
}