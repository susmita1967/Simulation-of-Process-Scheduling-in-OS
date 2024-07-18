#include<stdio.h>
void sort_process(int n,int *P,int *BT,int *AT)
{
    // sorting the processes according to their burst time
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(BT[j]>BT[j+1])
            {
                temp=BT[j];
                BT[j]=BT[j+1];
                BT[j+1]=temp;

                temp=AT[j];
                AT[j]=AT[j+1];
                AT[j+1]=temp;

                temp=P[j];
                P[j]=P[j+1];
                P[j+1]=temp;
            }
        }
    }
}
void wating_time(int n,int *Burst_time,int *waiting_time)
{
    waiting_time[0]=0;
    for(int i=1;i<n;i++)
    {
        waiting_time[i]=waiting_time[i-1]+Burst_time[i-1];
    }
}
void turnarround_Time(int n,int *Burst_Time,int *wating_Time,int *turnarround_time)
{
    for(int i=0;i<n;i++)
    {
        turnarround_time[i]=Burst_Time[i]+wating_Time[i];
    }
}
void Avg_Turnarraound_Time(int n,int *Tat)
{
    float total=0;
    for(int i=0;i<n;i++)
    {
        total=total+Tat[i];
    }
    printf("The average Turnarround Time is:%0.2f\n",total/n);
}
void Avg_Waiting_Time(int n,int *WT)
{
    float total=0;
    for(int i=0;i<n;i++)
    {
        total=total+WT[i];
    }

    printf("The average Waiting Time is:%0.2f\n",total/n);
}
int main()
{
    int n;
    printf("Enter no.of processes:\n");
    scanf("%d",&n);
    printf("\n");
    int P[n],BT[n],WT[n],TAT[n],AT[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the process id: ");
        scanf("%d",&P[i]);
        printf("Arrival Time: ");
        scanf("%d",&AT[i]);
        printf("Burst time: ");
        scanf("%d",&BT[i]);
        printf("\n");
    }
    printf("Before arrange:\n");
    printf("\nProcesses\tBurst Time\n");
    for(int i=0;i<n;i++)
    {
        printf(" P%d    \t\t %d \n",P[i],BT[i]);
    }
    sort_process(n,P,BT,AT);
    wating_time(n,BT,WT);
    turnarround_Time(n,BT,WT,TAT);
    printf("\nProcesses\tBurst Time\tWaiting Time\tTurnarround Time\n");
    for(int i=0;i<n;i++)
    {
        printf(" P%d    \t\t %d    \t\t %d    \t\t %d\n",P[i],BT[i],WT[i],TAT[i]);
    }
    Avg_Turnarraound_Time(n,TAT);
    Avg_Waiting_Time(n,WT);

    return 0;
}
