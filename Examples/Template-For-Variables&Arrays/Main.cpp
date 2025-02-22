#include"Header.h"
#include"Header1.h"
int main() 
{
base<int,char> b(3,'a');
base<string, string> b1("Alishba", "Saboor");
b.display();
b1.display();
cout << "\n**********************************\n";
int arr[3] = { 3,8,5 };
derived<int, int> d(arr, 3);
d.calculate();
system("pause");
return 0;
}