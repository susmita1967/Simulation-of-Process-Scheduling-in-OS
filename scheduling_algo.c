#include<stdio.h>
#include<windows.h>
 // P-Processes
 // BT-Burst Time
 // AT-Arrival Time
 // TAT-Turnarround Time
 // WT-Waiting Time
 // CT-Completion Time
 // RT-Remaining Time
 void display_res(int n,int *AT,int *BT,int *WT,int *TAT)
 {
    printf("\nProcesses\tArrival Time\tBurst Time\tWaiting Time\tTurnarround Time\n");
    for(int i=0;i<n;i++)
    {
        printf(" P%d    \t\t %d    \t\t %d    \t\t %d    \t\t %d\n",(i+1),AT[i],BT[i],WT[i],TAT[i]);
    }
    printf("__________________________________________________________________________________");
 }
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
    printf("_____________________________________________________________________________________________________");

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
}
 void Waiting_time(int n,int *BT,int *WT,int *TAT)
{
    WT[0]=0;
    for(int i=1;i<n;i++)
    {
        WT[i]=WT[i-1]+BT[i-1];
    }
    for(int i=0;i<n;i++)
    {
        TAT[i]=BT[i]+WT[i];
    }
}
void sort_with_BT(int n,int *BT,int *AT)
{
    // sorting the processes using bubble sort according to their burst time
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
            }
        }
    }
}
void sort_with_AT(int n,int *AT,int *BT)
{
    // Sorting the processes with bubble sort according to their arrival time
    int temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(AT[j]>AT[j+1])
            {
                temp=AT[j];
                AT[j]=AT[j+1];
                AT[j+1]=temp;

                temp=BT[j];
                BT[j]=BT[j+1];
                BT[j+1]=temp;
            }
        }
    }
}
void Avg_Turnarraound_Time(int n,int *TaT)
{
    // Calculating the average turnarround time
    float total=0;
    for(int i=0;i<n;i++)
    {
        total=total+TaT[i];
    }
    printf("\n*** The average Turnarround Time is: %0.2f\n",total/n);
}
void Avg_Waiting_Time(int n,int *WT)
{
    // Calculating the average waiting time
    float total=0;
    for(int i=0;i<n;i++)
    {
        total=total+WT[i];
    }

    printf("\n*** The average Waiting Time is: %0.2f\n",total/n);
}
void gotoxy(int x,int y)
{
	COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}
void FCFS()
{
    printf("==========* CPU SHEDULING With FCFS *==========\n\n");
    int n;
    printf("Enter the no.of processes:\n");
    // TAking input for number of processes
    scanf("%d",&n);
    printf("\n");
    int BT[n],WT[n],TAT[n],AT[n];
    int i=0;
    // Taking deatils of process
    while(i<n)
    {
        printf("Enter details for %d process:\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&AT[i]);
        printf("Burst time : ");
        scanf("%d",&BT[i]);
        printf("\n");
        i++;
    }
    //display(n,P,AT,BT);
    sort_with_AT(n,AT,BT);
    Waiting_time(n,BT,WT,TAT);
    // Final result
    display_res(n,AT,BT,WT,TAT);
    printf("\n");
    Avg_Turnarraound_Time(n,TAT);
    Avg_Waiting_Time(n,WT);
}
void SJF()
{
    printf("==========* CPU SHEDULING WITH SJF *==========\n\n");
    int n;
    printf("Enter no.of processes:\n");
    scanf("%d",&n);
    printf("\n");
    int BT[n],WT[n],TAT[n],AT[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter details for %d process:\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&AT[i]);
        printf("Burst time: ");
        scanf("%d",&BT[i]);
        printf("\n");
    }
    //display(n,P,AT,BT);
    sort_with_BT(n,BT,AT);
    Waiting_time(n,BT,WT,TAT);
    display_res(n,AT,BT,WT,TAT);
    Avg_Turnarraound_Time(n,TAT);
    Avg_Waiting_Time(n,WT);
}
void RR()
{
    printf("==========* CPU SHEDULING WITH RR *==========\n\n");
    int n,Q;
    printf("Enter the no.of processes:\n");
    scanf("%d",&n);
    printf("\n");
    int BT[n],WT[n],TAT[n],AT[n],CT[n];
     // Input for Quantum time /time slice of CPU
    printf("Set the Quantum Time:\n");
    scanf("%d",&Q);
    // Input for process details
    for(int i=0; i<n; i++)
    {
        printf("Enter details for %d process:\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&AT[i]);

        printf("Burst time: ");
        scanf("%d",&BT[i]);
        printf("\n");

    }
    //display(n,P,AT,BT);
    sort_with_AT(n,AT,BT);
    completion_time(n,Q,BT,CT,WT,TAT,AT);
    printf("\n");
   // display_res(n,AT,BT,WT,TAT);
   printf("** Final :\n");
    printf("\nProcesses\tArrival Time\tCompletion Time\t Burst Time\tWaiting Time\tTurnarround Time\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d    \t\t %d    \t\t %d    \t\t  %d    \t\t %d    \t\t %d\n",(i+1),AT[i],CT[i],BT[i],WT[i],TAT[i]);
    }
    printf("_____________________________________________________________________________________________________");
    printf("\n");
    Avg_Turnarraound_Time(n,TAT);
    Avg_Waiting_Time(n,WT);
}
/*void display(int n,int *AT,int *BT)
 {
    printf("\n** Before arrange:\n");
    printf("\nProcesses\tArrival Time\tBurst Time\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d    \t\t %d    \t\t %d\n",(i+1),AT[i],BT[i]);
    }
    printf("__________________________________________________________________________________");
    printf("\n");
 }*/
int main()
{
    gotoxy(42,2);
    printf("==========CPU SHEDULING==========\n");
    int ch,c;
    do
    {
        printf("\n\n\n***** Select the Algorithm for scheduling *****\n\n");
        printf("1.First Come First Serve\n\n2.Shortest Job First\n\n3.Round Robin\n");
        printf("_____________________________________________________________________________________________________");
        printf("\nEnter choice number: ");
        scanf("%d",&ch);
        printf("\n\n");
        switch(ch)
        {
            case 1:
                FCFS();
                break;
            case 2:
                SJF();
                break;
            case 3:
                RR();
                break;
            default:
                printf("select valid choice...\n");
        }
        printf("\nEnter '1' for more or '0' for exit\n");
        scanf("%d",&c);
    }while(c==1);
    printf("******Exited successfully....!******\n\n\n\n");
    return 0;
}
