#include <stdio.h>
#include <stdlib.h>

#define INC <
#define DEC >
#define PPW ppw 
#define P p 
#define W w 

typedef struct
{
    int pos;
    int w;
    float ppw;
    int p;
} data;

void swap(data *d1, data *d2)
{
    data temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}

void sort(data d[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (d[j].ppw < d[j + 1].ppw)
            {
                swap(&d[j], &d[j + 1]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    data d[100];

    int sz;
    printf("Enter the no of items : ");
    scanf("%d", &sz);

    printf("Enter the weight of individual items: \n");
    for (int i = 0; i < sz; i++)
    {
        printf("item %d weight: ", i);
        scanf("%d", &d[i].w);
        d[i].pos = i;
    }
    printf("\nEnter the profit of individual items: \n");
    for (int i = 0; i < sz; i++)
    {
        printf("item %d profit: ", i);
        scanf("%d", &d[i].p);
        d[i].ppw = (float)d[i].p / (float)d[i].w;
        printf("%f\t", d[i].ppw);
    }

    printf("1. ON THE BASIS OF PROFIT PER WEIGHT \n");
    printf("2. On the basis of Only Profit\n");
    printf("3. On the basis of minimum weight\n");
    int choice;
    while (1)
    {
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            sort(d,sz);
            for(int i = 0 ; i < sz ; i++){
                printf("%f\t",d[i].ppw);
            }
            break;

        case 2:

            break;
        case 3:

            break;

        default:
            printf("Invalid Choice");
            break;
        }
    }

    return 0;
}

// https://stackoverflow.com/questions/13716913/default-value-for-struct-member-in-c
