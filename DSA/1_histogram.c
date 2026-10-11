#include <stdio.h>

int arr[20], fr[20], n;

void getdata()
{
    int i;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}



void printdata()
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}



void makehistogram()
{
    int i, j, count;
    printf("\nElement / Frequency\n");
    printf("-------------------\n");
    for(i = 0; i < n; i++)
    {
        if(fr[i] == -1)
            continue;
        count = 1;
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                fr[j] = -1;
            }
        }
        printf("%d | ", arr[i]);
        for(j = 0; j < count; j++)
            printf("* ");
        printf("\n");
    }
}



int main()
{
    getdata();
    printdata();
    makehistogram();
    return 0;
}
