#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    
    while (fgets(line, 1024, f)) 
    {
        // Skip empty lines
        if (line[0] == '\n') 
        {
            continue;
        }
        // Do something with the line
    }
}