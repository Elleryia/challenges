#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copy_string(const char *s)
{
    char *copy = malloc(strlen(s) + 1);
    if (copy != NULL)
    {
        strcpy(copy, s);
    }
    return copy;
}

int *isplit(const char *s, int *size, const char *delim)
{
    char *copy = copy_string(s);
    int *result = NULL;
    *size = 0;
    for (char *tok = strtok(copy, delim); tok != NULL; tok = strtok(NULL, delim))
    {
        // Omitting error handling for brevity
        ++(*size);
        result = realloc(result, *size * sizeof *result);
        result[*size - 1] = atoi(tok);
    }
    free(copy);
    return result;
}

int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    char line[1024];
    while (fgets(line, 1024, f)) 
    {
        // Skip empty lines
        if (line[0] == '\n') 
        {
            continue;
        }
        // Do something with the line
        //fprintf(stdout, line);
        int size;
        int *nums = isplit(line, &size, " ");
        
        for(int i = 1; i <= nums[2]; ++i)
        {
            if((i % nums[0]) == 0)
            {
                fprintf(stdout, "F");
                if((i % nums[1]) == 0)
                {
                    fprintf(stdout, "B ");
                }
                else
                {
                    fprintf(stdout, " ");
                }
            }
            else if((i % nums[1]) == 0)
            {
                fprintf(stdout, "B ");
            }
            else
            {
                fprintf(stdout, "%d ", i);
            }
        }
        fprintf(stdout, "\n");
        free(nums);
    }
}