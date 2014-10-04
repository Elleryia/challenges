#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    union
    {
        long int l;
        char c[sizeof(long int)];
    } u;
    
    u.l = 1;
    if(u.c[sizeof(long int) - 1] == 1)
        cout << "BigEndian" << endl;
    else
        cout << "LittleEndian" << endl;
}









