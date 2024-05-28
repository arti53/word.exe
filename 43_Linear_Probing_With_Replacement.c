#include <stdio.h>

void Insert_HashTable(int arr[], int iKey, int chain[]);
void Display_HashTable(int arr[], int chain[]);

int count = 0;

int main(void)
{
    int arr[10];
    int chain[10];
    int iKey;

    for (int i = 0; i < 10; i++)
    {
        arr[i] = -1;
        chain[i] = -1;
    }

    printf("Enter Data:\n");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &iKey);
        Insert_HashTable(arr, iKey, chain);
    }

    Display_HashTable(arr, chain);
    printf("Count %d\n", count);

    return 0;
}

void Insert_HashTable(int arr[], int iKey, int chain[])
{
    int iPos = iKey % 10;

    if (arr[iPos] == -1)
    {
        arr[iPos] = iKey;
        return;
    }

    if (arr[iPos] != -1 && arr[iPos] % 10 != iPos)
    {
        for (int i = 0; i < 10; i++)
        {
            count++;
            int newPos = (iPos + i) % 10;
            if (arr[newPos] == -1)
            {
                arr[newPos] = arr[iPos];
                arr[iPos] = iKey;
                for (int j = 0; j < 10; j++)
                {
                    if (chain[j] == iPos)
                    {
                        chain[j] = newPos;
                    }
                }
                chain[iPos] = -1;
                for (int j = 0; j < 10; j++)
                {
                    if (arr[j] != iKey && arr[j] % 10 == iKey % 10 && chain[j] == -1)
                    {
                        chain[j] = iPos;
                        return;
                    }
                }
                return;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        count++;
        int newPos = (iPos + i) % 10;
        if (arr[newPos] == -1)
        {
            arr[newPos] = iKey;
            for (int j = 0; j < 10; j++)
            {
                if (arr[j] != iKey && arr[j] % 10 == iKey % 10 && chain[j] == -1)
                {
                    chain[j] = newPos;
                    return;
                }
                if (arr[j] == iKey && chain[j] == -1)
                {
                    chain[j] = newPos;
                    return;
                }
            }
            return;
        }
    }
}

void Display_HashTable(int arr[], int chain[])
{
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] != -1)
        {
            printf("[%d] %d -> %d\n", i, arr[i], chain[i]);
        }
    }
}


 //11 101 88 18 70 3 50 19 16 26
