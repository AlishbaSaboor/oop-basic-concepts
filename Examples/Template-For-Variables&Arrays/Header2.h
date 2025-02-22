template <typename W, typename S>
class derived
{
private:
W* ptr;
S s;
public:
derived(W* arr, S size);
void calculate();
};
template <typename W, typename S>
derived<W,S>::derived(W* arr, S size) 
{
ptr = arr;
s = size;
}
template <typename W, typename S>
void derived<W, S>::calculate()
{
for (int i = 0; i < s; i++)
{
ptr[i]=ptr[i]+4;
}
for (int i = 0; i < s; i++) 
{
cout << "\nvalue " << i + 1 << ": " << *(ptr + i);
}
cout << endl;
}