#include <stdio.h>


float original[10];


void swap(float *x, float *y)
{
    float temp = *x;
    *x = *y;
    *y = temp;
}


void boobleSortDes(float *ratio, float *profit, float *weight, float *original, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < (size - i - 1); j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                swap(&ratio[j], &ratio[j + 1]);

                swap(&profit[j], &profit[j + 1]);

                swap(&weight[j], &weight[j + 1]);

                swap(&original[j], &original[j + 1]);
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%f", ratio[i]);
    }
}

void boobleSortAsc(float *ratio, float *profit, float *weight, float *original, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ratio[j] > ratio[j + 1])
            {
                swap(&ratio[j], &ratio[j + 1]);

                swap(&profit[j], &profit[j + 1]);

                swap(&weight[j], &weight[j + 1]);

                swap(&original[j], &original[j + 1]);
            }
        }
    }
}

void knapSack(float *ratio, float *profit, float *weight, int size, int capacity)
{
    int u = capacity;
    int i;
    float totalProfit = 0;
    float x[size];
    for (i = 0; i < size; i++)
    {
        x[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        if (weight[i] > u)
        {
            break;
        }
        else
        {
            u = u - weight[i];
            x[i] = 1;
            totalProfit = totalProfit + profit[i];
        }
    }
    if (i < size)
    {
        x[i] = u / weight[i];
    }
    totalProfit = totalProfit + profit[i] * x[i];

    boobleSortAsc(original, x, weight, profit, size);
    printf("The Result Vector: \n");
    for (i = 0; i < size; i++)
    {
        printf("%.0f  \t", original[i]);
    }
    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("%f ", x[i]);
    }
    printf("\nTotal Profit: %f\n", totalProfit);
}

int main()
{
    int object, capacity, opt, choice;
    printf("Enter the size: ");
    scanf("%d", &object);
    float weight[object], profit[object], ratio[object];
    printf("Enter the capacity :");
    scanf("%d", &capacity);

    printf("Enter the profit: ");
    for (int i = 0; i < object; i++)
    {
        scanf("%f", &profit[i]);
    }

    printf("Enter the Weights: ");
    for (int i = 0; i < object; i++)
    {
        scanf("%f", &weight[i]);
    }
    for (int i = 0; i < object; i++)
    {
        original[i] = i;
        ratio[i] = (profit[i] / weight[i]);
    }
    printf("The ratio is: \n");
    for (int i = 0; i < object; i++)
    {
        printf("%f ", ratio[i]);
    }
    do
    {
        printf("\n1. Ratio Wise\n");
        printf("2. Maximum Profit Wise\n");
        printf("3. Minimum Weight\n");
        printf("4. Exit\n");
        printf("Enter what you want to do: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            boobleSortDes(ratio, profit, weight, original, object);
            knapSack(ratio, profit, weight, object, capacity);
            break;
        case 2:
            boobleSortDes(profit, ratio, weight, original, object);
            knapSack(ratio, profit, weight, object, capacity);
            break;
        case 3:
            boobleSortAsc(weight, profit, ratio, original, object);
            knapSack(ratio, profit, weight, object, capacity);
            break;

        default:
            printf("MadarDairy thik se option dal lol XD");
            break;
        }
    } while (choice != 4);
}