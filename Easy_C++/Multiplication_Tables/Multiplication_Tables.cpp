#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char *argv[])
{
    for(int i = 1; i < 13; ++i)
    {
        for(int j = 1; j < 13; ++j)
        {
            cout << setw(4) << (i * j);
        }
        cout << endl;
    }
}