#include<stdio.h>
#include<windows.h>
struct Process
{
    int WT,TAT,AT,CT,BT,RT;
};
 // P-Processes
 // BT-Burst Time
 // AT-Arrival Time
 // TAT-Turnarround Time
 // WT-Waiting Time
 // CT-Completion Time
 // RT-Remaining Time
 void display_res(int n,struct Process *P)
 {
    printf("\nProcesses\tArrival Time\tBurst Time\tWaiting Time\tTurnarround Time\n");
    for(int i=0;i<n;i++)
    {
        printf(" P%d    \t\t %d    \t\t %d    \t\t %d    \t\t %d\n",(i+1),P[i].AT,P[i].BT,P[i].WT,P[i].TAT);
    }
    printf("__________________________________________________________________________________");
 }
 void completion_time(int n,int q,struct Process *P)
{
    // Calculating the time taken by process for its completion
    printf("\nProcesses\tTime\n");
    P[n].RT;
    int total=0,j=0;
    for(int i=0; i<n; i++)
    {
        P[i].RT=P[i].BT;
    }
    while(1)
    {
        for(int i=0; i<n; i++)
        {
            if(P[i].RT>0 && P[i].RT<=q )
            {
                total=total+P[i].RT;
                P[i].RT=0;
                P[i].CT=total;
                j++;
                printf("P%d  \t\t %d    \t\t\n",(i+1),total);
            }
            else if(P[i].RT>q)
            {
                total=total+q;
                P[i].RT=P[i].RT-q;
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
        if(P[i].CT>P[i].AT)
        {
            P[i].TAT=P[i].CT-P[i].AT;
        }
        else
        {
            P[i].TAT=P[i].AT-P[i].CT;
        }
    }
     for(int i=0; i<n; i++)
    {
        if(P[i].TAT>=P[i].BT)
        {
            P[i].WT=P[i].TAT-P[i].BT;
        }
        else
        {
            P[i].WT=P[i].BT-P[i].TAT;
        }
    }
}
 void Waiting_time(int n,struct Process *P)
{
    P[0].WT=0;
    for(int i=1;i<n;i++)
    {
        P[i].WT=P[i-1].WT+P[i-1].BT;
    }
    for(int i=0;i<n;i++)
    {
        P[i].TAT=P[i].BT+P[i].WT;
    }
}
void sort_with_BT(int n,struct Process *P)
{
    // sorting the processes using bubble sort according to their burst time
    struct Process temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(P[j].BT>P[j+1].BT)
            {
                temp=P[j];
                P[j]=P[j+1];
                P[j+1]=temp;
            }
        }
    }
}
void sort_with_AT(int n,struct Process *P)
{
    // Sorting the processes with bubble sort according to their arrival time
    struct Process temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(P[j].AT>P[j+1].AT)
            {
                temp=P[j];
                P[j]=P[j+1];
                P[j+1]=temp;
            }
        }
    }
}
void Avg_Turnarraound_Time(int n,struct Process *P)
{
    // Calculating the average turnarround time
    float total=0;
    for(int i=0;i<n;i++)
    {
        total=total+P[i].TAT;
    }
    printf("\n*** The average Turnarround Time is: %0.2f\n",total/n);
}
void Avg_Waiting_Time(int n,struct Process *P)
{
    // Calculating the average waiting time
    float total=0;
    for(int i=0;i<n;i++)
    {
        total=total+P[i].WT;
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
    struct Process P[n];
    int i=0;
    // Taking deatils of process
    while(i<n)
    {
        printf("Enter details for %d process:\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&P[i].AT);
        printf("Burst time : ");
        scanf("%d",&P[i].BT);
        printf("\n");
        i++;
    }
    //display(n,P,AT,BT);
    sort_with_AT(n,P);
    Waiting_time(n,P);
    // Final result
    display_res(n,P);
    printf("\n");
    Avg_Turnarraound_Time(n,P);
    Avg_Waiting_Time(n,P);
}
void SJF()
{
    printf("==========* CPU SHEDULING WITH SJF *==========\n\n");
    int n;
    printf("Enter no.of processes:\n");
    scanf("%d",&n);
    printf("\n");
    struct Process P[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter details for %d process:\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&P[i].AT);
        printf("Burst time: ");
        scanf("%d",&P[i].BT);
        printf("\n");
    }
    //display(n,P,AT,BT);
    sort_with_BT(n,P);
    Waiting_time(n,P);
    display_res(n,P);
    Avg_Turnarraound_Time(n,P);
    Avg_Waiting_Time(n,P);
}
void RR()
{
    printf("==========* CPU SHEDULING WITH RR *==========\n\n");
    int n,Q;
    printf("Enter the no.of processes:\n");
    scanf("%d",&n);
    printf("\n");
    struct Process P[n];
     // Input for Quantum time /time slice of CPU
    printf("Set the Quantum Time:\n");
    scanf("%d",&Q);
    // Input for process details
    for(int i=0; i<n; i++)
    {
        printf("Enter details for %d process:\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&P[i].AT);

        printf("Burst time: ");
        scanf("%d",&P[i].BT);
        printf("\n");

    }
    //display(n,P,AT,BT);
    sort_with_AT(n,P);
    completion_time(n,Q,P);
    printf("\n");
   // display_res(n,AT,BT,WT,TAT);
   printf("** Final :\n");
    printf("\nProcesses\tArrival Time\t Burst Time\tWaiting Time\tTurnarround Time\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d    \t\t %d    \t\t %d    \t\t  %d    \t\t %d\n",(i+1),P[i].AT,P[i].BT,P[i].WT,P[i].TAT);
    }
    printf("_____________________________________________________________________________________________________");
    printf("\n");
    Avg_Turnarraound_Time(n,P);
    Avg_Waiting_Time(n,P);
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
