#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[10];
    FILE *fptr;
    int i;
    i = 0;

    fptr = fopen("random10000000.txt", "w");
    if (fptr == NULL)
    {
        printf("ERROR Creating File!");
        exit(1);
    }
    for (int i = 1; i <= 10000000; ++i)
    {
        fprintf(fptr, "%d     ", rand() % 1000);
        if (i % 10 == 0)
        {
            fprintf(fptr, "\n");
        }
    }
    puts(str);
    fprintf(fptr, "%s", str);
    fclose(fptr);
    return (0);
}