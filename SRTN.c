#include<stdio.h>
void sort_process(int n,int q,int *P,int *AT,int *BT,int *RT)
{
    int temp;
    // Initially assigning the burst time of each process to the remaining time of that process
    for(int i=0;i<n;i++)
   {
       RT[i]=BT[i];
   }
   // Calculating the remaining time for each process
   for(int i=0;i<n;i++)
   {
       if(RT[i]>=q)
       {
           RT[i]=RT[i]-q;
       }
       else
       {
           RT[i]=q-RT[i];
       }
   }
   // Sorting the processes according to shortest remaining time
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(RT[j]>RT[j+1])
            {
                temp=AT[j];
                AT[j]=AT[j+1];
                AT[j+1]=temp;

                temp=BT[j];
                BT[j]=BT[j+1];
                BT[j+1]=temp;

                temp=P[j];
                P[j]=P[j+1];
                P[j+1]=temp;
            }
        }
    }
}
void waiting_time(int n,int *BT,int *WT)
{
    WT[0]=0;
    for(int i=1;i<n;i++)
    {
        WT[i]=WT[i-1]+BT[i-1];
    }
}
void turnarround_Time(int n,int *BT,int *WT,int *TAT)
{
    //Calculating the turnarround time for each process
    for(int i=0;i<n;i++)
    {
        TAT[i]=BT[i]+WT[i];
    }
}
void Avg_Turnarraound_Time(int n,int *Tat)
{
    // Calculating the average turnarround time
    float total=0;
    for(int i=0;i<n;i++)
    {
        total=total+Tat[i];
    }
    printf("The average Turnarround Time is:%0.2f\n",total/n);
}
void Avg_Waiting_Time(int n,int *WT)
{
    // Calculating the average waiting time
    float total=0;
    for(int i=0;i<n;i++)
    {
        total=total+WT[i];
    }

    printf("The average Waiting Time is:%0.2f\n",total/n);
}
int main()
{
    int n,Q;
    printf("Enter the no.of processes:\n");
    scanf("%d",&n);
    printf("\n");
    int P[n],AT[n],BT[n],RT[n],TAT[n],WT[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the process id: ");
        scanf("%d",&P[i]);
        printf("Arrival Time: ");
        scanf("%d",&AT[i]);
        printf("Burst Time: ");
        scanf("%d",&BT[i]);
        printf("\n");
    }
    printf("Enter Quantum Time : ");
    scanf("%d",&Q);
    printf("\nBefore arrange:\n");
    printf("\nProcesses\tArrival Time\tBurst Time\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d    \t\t %d    \t\t %d\n",P[i],AT[i],BT[i]);
    }
    printf("\n");
    sort_process(n,Q,P,AT,BT,RT);
    waiting_time(n,BT,WT);
    turnarround_Time(n,BT,WT,TAT);
    printf("Final :\n");
    printf("\nProcesses\tArrival Time\t Burst Time\tRemaining Time\tWaiting Time\tTurnarround Time\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d    \t\t %d    \t\t %d    \t\t  %d    \t\t %d    \t\t %d\n",P[i],AT[i],BT[i],RT[i],WT[i],TAT[i]);
    }
    printf("\n");
    Avg_Waiting_Time(n,WT);
    Avg_Turnarraound_Time(n,WT);

    return 0;
}
