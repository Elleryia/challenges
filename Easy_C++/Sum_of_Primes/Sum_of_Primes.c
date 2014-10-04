#include <stdio.h>
#include <math.h>

int check_prime(int a)
{
    if(a < 2)
        return 0;
    if(a == 2)
        return 1;
    int sq = (int)sqrt(a);
    for (int c = 2 ; c <= sq ; c++ )
    { 
        if ( a % c == 0 )
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int count = 0;
    int sum = 0;
    int n = 0;
    while(count < 1000)
    {
        if(check_prime(n))
        {
            count++;
            sum += n;
        }
        n++;
    }
    fprintf(stdout, "%d\n", sum);
}