#include <stdio.h>
void fcfs(int bt[], int at[], int n)
{
    int ct[100];
    int tat[100];
    int wt[100];
    ct[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("pid:%d \nbt:%d \nat:%d \nct:%d \ntat:%d \nwt:%d\n\n", i + 1, bt[i], at[i], ct[i], tat[i], wt[i]);
    }
}
void sjf(int bt[], int at[], int n)
{
    int ct[100];
    int tat[100];
    int wt[100];
    int temp;
    int prid[100];
    for (int i = 0; i < n; i++)
    {
        prid[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = prid[i];
                prid[i] = prid[j];
                prid[j] = temp;
            }
        }
    }
    ct[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("prid:%d \nbt:%d \nat:%d \nct:%d \ntat:%d \nwt:%d\n\n", prid[i], bt[i], at[i], ct[i], tat[i], wt[i]);
    }
}
void ps(int bt[], int at[], int n, int pri[])
{
    int ct[100];
    int tat[100];
    int wt[100];
    int temp;
    int prid[100];
    for (int i = 0; i < n; i++)
    {
        prid[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (prid[i] > prid[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = prid[i];
                prid[i] = prid[j];
                prid[j] = temp;

                temp = prid[i];
                prid[i] = prid[j];
                prid[j] = temp;
            }
        }
    }
    ct[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("prid:%d \nbt:%d \nat:%d \nct:%d \npriority:%d \ntat:%d \nwt:%d\n\n", prid[i], bt[i], at[i], ct[i], pri[i], tat[i], wt[i]);
    }
}
void roundRobin(int bt[], int at[], int n, int rest)
{
    int rem_bt[n];
    int ct[100] = {0};
    int tat[100];
    int wt[100];
    int t = 0;

    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }

    while (1)
    {
        int done = 1;

        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = 0;

                if (rem_bt[i] > rest)
                {
                    t += rest;
                    rem_bt[i] -= rest;
                }
                else
                {
                    t += rem_bt[i];
                    ct[i] = t;
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == 1)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("prid:%d \nbt:%d \nat:%d \nct:%d \ntat:%d \nwt:%d\n\n", i + 1, bt[i], at[i], ct[i], tat[i], wt[i]);
    }
}

int main()
{
    int bt[100];
    int at[100];
    int prid[100];
    int n;
    int choice;
    int rest;
    printf("number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter bt of p%d ", i + 1);
        scanf("%d", &bt[i]);
        printf("enter at of p%d ", i + 1);
        scanf("%d", &at[i]);
    }
    printf("Choose a scheduler: \n1.)FCFS\n2.)SJF\n3.)PS\n4.)RR\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        fcfs(bt, at, n);
        break;
    case 2:
        sjf(bt, at, n);
        break;
    case 3:
        for (int i = 0; i < n; i++)
        {
            printf("enter priority of p%d ", i + 1);
            scanf("%d", &prid[i]);
        }
        ps(bt, at, n, prid);
        break;
    case 4:
        printf("enter response time : ");
        scanf("%d", &rest);
        roundRobin(bt, at, n, rest);
        break;
    default:
        printf("Invalid choice!\n");
        return 1;
}
}
