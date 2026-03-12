#include <stdio.h>
#include <string.h>

int verify(char *input)
{

    int seed = 4;

    int table[] = {112, 118, 101, 106, 119, 103, 97, 106, 96, 109, 106, 99};

    for (int i = 0; i < 12; i++)
    {
        if ((input[i] ^ seed) != table[i])
        {
            return 0;
        }
    }

    return 1;
}

void reveal()
{
    FILE *fp;
    int data[9];
    int key = 7;

    fp = fopen("flag.enc", "r");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < 9; i++)
        fscanf(fp, "%d", &data[i]);

    fclose(fp);

    printf("Location unlocked: ");

    for (int i = 0; i < 9; i++)
        printf("%c", data[i] ^ key);

    printf("\n");
}

int main()
{

    char buffer[50];

    printf("Enter access code: ");

    if (scanf("%49s", buffer) != 1)
    {
        return 1;
    }

    if (verify(buffer))
    {
        reveal();
    }
    else
    {
        printf("Access denied\n");
    }

    return 0;
}