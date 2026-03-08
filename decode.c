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

    int key = 3;

    int hidden[] = {109, 102, 112, 96, 98, 101, 102};

    printf("Location unlocked: ");

    for (int i = 0; i < 7; i++)
    {
        printf("%c", hidden[i] ^ key);
    }

    printf("\n");
}

int main()
{

    char buffer[50];

    printf("Enter access code: ");
    scanf("%s", buffer);

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