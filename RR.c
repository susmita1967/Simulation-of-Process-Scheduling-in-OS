#include<stdio.h>
void completion_time(int n,int q,int *BT,int *CT,int *WT,int *TAT,int *AT)
{
    // Calculating the time taken by process for its completion
    printf("\nProcesses\tTime\n");
    int RT[n];
    int total=0,j=0;
    for(int i=0; i<n; i++)
    {
        RT[i]=BT[i];
    }
    while(1)
    {
        for(int i=0; i<n; i++)
        {
            if(RT[i]>0 && RT[i]<=q )
            {
                total=total+RT[i];
                RT[i]=0;
                CT[i]=total;
                j++;
                printf("P%d  \t\t %d    \t\t\n",(i+1),total);
            }
            else if(RT[i]>q)
            {
                total=total+q;
                RT[i]=RT[i]-q;
                printf("P%d  \t\t %d    \t\t\n",(i+1),total);
            }
        }
        if(j==n)
        {
            break;
        }
    }
     for(int i=0; i<n; i++)
    {
        if(CT[i]>AT[i])
        {
            TAT[i]=CT[i]-AT[i];
        }
        else
        {
            TAT[i]=AT[i]-CT[i];
        }
    }
     for(int i=0; i<n-1; i++)
    {
        if(TAT[i]>=BT[i])
        {
            WT[i]=TAT[i]-BT[i];
            WT[n-1]=TAT[n-1]-BT[n-1];
        }
        else
        {
            WT[i]=BT[i]-TAT[i];
            WT[n-1]=BT[n-1]-TAT[n-1];
        }
    }
    float t=0;
    for(int i=0; i<n; i++)
    {
        t=t+TAT[i];
    }
    printf("The average Turnarround Time is:%0.2f\n",t/n);
        float t1=0;
    for(int i=0; i<n; i++)
    {
        t1=t1+WT[i];
    }

    printf("The average Waiting Time is:%0.2f\n",t1/n);
}
/*void Waiting_Time(int n,int *WT,int *TAT,int *BT)
{
    // Calculating Waiting time for each process
    for(int i=0; i<n-1; i++)
    {
        if(TAT[i]>=BT[i])
        {
            WT[i]=TAT[i]-BT[i];
            WT[n-1]=TAT[n-1]-BT[n-1];
        }
        else
        {
            WT[i]=BT[i]-TAT[i];
            WT[n-1]=BT[n-1]-TAT[n-1];
        }
    }

}
void turnarround_Time(int n,int *AT,int *CT,int *TAT)
{
    // Calculating turnarround time for each process
    for(int i=0; i<n; i++)
    {
        if(CT[i]>AT[i])
        {
            TAT[i]=CT[i]-AT[i];
        }
        else
        {
            TAT[i]=AT[i]-CT[i];
        }
    }
}
void Avg_Turnarraound_Time(int n,int *Tat)
{
    // Average turnarround tim
}
void Avg_Waiting_Time(int n,int *WT)
{
    // Average waiting time

}*/
void sort_process(int n,int *AT,int *BT)
{
    // Sorting the process according to their arrival time
    int t1;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(AT[j]>AT[j+1])
            {
                t1=AT[j];
                AT[j]=AT[j+1];
                AT[j+1]=t1;

                t1=BT[j];
                BT[j]=BT[j+1];
                BT[j+1]=t1;

                /*t1=P[j];
                P[j]=P[j+1];
                P[j+1]=t1;*/
            }
        }
    }
}
int main()
{
    int n,Q;
    printf("Enter the no.of processes:\n");
    // TAking input for number of processes
    scanf("%d",&n);
    printf("\n");
    int BT[n],WT[n],TAT[n],AT[n],CT[n];
    // Input for process details
    printf("Set the Quantum Time:\n");
    scanf("%d",&Q);
    for(int i=0; i<n; i++)
    {
        printf("Enter details for %d process:\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&AT[i]);

        printf("Burst time: ");
        scanf("%d",&BT[i]);
        printf("\n");

    }
    // Input for Quantum time /time slice of CPU

    /*printf("\nBefore arrange:\n");
    printf("\nProcesses\tArrival Time\tBurst Time\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d    \t\t %d    \t\t%d\n",P[i],AT[i],BT[i]);
    }
    //turnarround_Time(n,AT,CT,TAT);
    //Waiting_Time(n,WT,TAT,BT);*/
    sort_process(n,AT,BT);
    completion_time(n,Q,BT,CT,WT,TAT,AT);
    printf("\n");
    printf("Final :\n");
    printf("\nProcesses\tArrival Time\tCompletion Time\tBurst Time\t Waiting Time\tTurnarround Time\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d    \t\t %d    \t\t %d    \t\t  %d    \t\t %d    \t\t %d\n",(i+1),AT[i],CT[i],BT[i],WT[i],TAT[i]);
    }
    printf("\n");
    //Avg_Turnarraound_Time(n,TAT);
   // Avg_Waiting_Time(n,WT);

    return 0;
}

