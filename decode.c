#include <stdio.h>

int main()
{

    int enc[] = {113, 104, 118, 102, 100, 105, 104};
    int key = 3;

    for (int i = 0; i < 7; i++)
    {
        printf("%c", enc[i] - key);
    }

    printf("\n");

    return 0;
}