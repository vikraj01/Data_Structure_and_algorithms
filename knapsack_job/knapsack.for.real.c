#include <stdio.h>
#include <stdlib.h>
#define For(x) for (int i = 0; i < n; i++)
#define FOR(i) for (int j = 0; j < n - i - 1; j++)

int n, max;
typedef struct st
{
    int i, w, p;
    float ppw;
} Item;
Item items[100];

void swap(Item *x, Item *y)
{
    Item temp = *x;
    *x = *y;
    *y = temp;
}




void knapsack()
{
    float x[20], tp = 0;
    int u = max;
    For(i) x[i] = 0.0;
    int j;
    For(j)
    {
        if (items[j].w > u)
            break;
        else
        {
            x[j] = 1.0;
            tp = tp + (float)items[j].p;
            u = u - items[j].w;
        }
    }

    if (j < n)
        x[j] = (float)u / (float)items[j].w;

    tp = tp + ((float)items[j].w * x[j]);

    printf("\nThe result vector is: ");
    For(i) printf("%f\t", x[i]);
    printf("\nMaximum profit is:- %f", tp);
}

int main(int argc, char const *argv[])
{
    printf("Enter the max weight: ");
    scanf("%d", &max);
    printf("Enter the number of items : ");
    scanf("%d", &n);

    printf("Enter the profit and weight for the items : \n");
    For(i)
    {
        scanf("%d%d", &items[i].w, &items[i].p);
        items[i].ppw = (float)items[i].p / (float)items[i].w;
        items[i].i = i;
    }

    For(i) FOR(j) if (items[j].ppw < items[j + 1].ppw) swap(&items[j], &items[j + 1]);
    knapsack();

    For(i) FOR(j) if (items[j].p < items[j + 1].p) swap(&items[j], &items[j + 1]);
    knapsack();

    For(i) FOR(j) if (items[j].w > items[j + 1].w) swap(&items[j], &items[j + 1]);
    knapsack();

    return 0;
}
