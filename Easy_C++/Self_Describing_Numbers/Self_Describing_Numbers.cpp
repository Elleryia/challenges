#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>

typedef unsigned long long bigint;

using namespace std;

class sdn
{
public:
    bool check( bigint n )
    {
        int cc = digitsCount( n );
        return compare( n, cc );
    }
 
    void displayAll( bigint s )
    {
        for( bigint y = 1; y < s; y++ )
        {
            if( check( y ) )
            {
                cout << y << " is a Self-Describing Number." << endl;
            }
        }
    }
 
private:
    bool compare( bigint n, int cc )
    {
        bigint a;
        while( cc )
        {
            cc--; a = n % 10;
            if( dig[cc] != a ) return false;
            n -= a; n /= 10;
        }
        return true;
    }
 
    int digitsCount( bigint n )
    {
        int cc = 0; bigint a;
        memset( dig, 0, sizeof( dig ) );
        while( n )
        {
            a = n % 10; dig[a]++;
            cc++ ; n -= a; n /= 10;
        }
        return cc;
    }
 
    int dig[10];
};

int main(int argc, char *argv[])
{
    ifstream file;
    file.open(argv[1]);
    string lineBuffer;
    while (!file.eof()) 
    {
        getline(file, lineBuffer);
        if (lineBuffer.length() == 0)
        {
            continue; //ignore all empty lines
        }
        else 
        {
            //do something here
            lineBuffer.erase( std::remove(lineBuffer.begin(), lineBuffer.end(), '\r'), lineBuffer.end());
            int num = atoi(lineBuffer.c_str());
            sdn s;
            if(s.check(num)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}