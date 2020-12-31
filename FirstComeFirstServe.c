#include<stdio.h>

struct process
{
int pid,at,bt,ft,tt,wt;
}p[10];

int main()
{
int i,n;
float avgtt=0,avgwt=0;
printf("enter the no of process\n");
scanf("%d",&n)
  
for(i=1;i<=n;i++)
{
p[i].pid=i;
printf("enter the arrival time for process %d\n",i);
scanf("%d",&p[i].at);
printf("enter the burst time for process   %d\n",i);
scanf("%d",&p[i].bt);
p[i].ft=p[i].bt+p[i-1].ft;
p[i].tt=p[i].ft-p[i].at;
p[i].wt=p[i].tt-p[i].bt;
}
i=1;
printf("\n processid  ArrivalTime  BurstTime  CompletionTime   TurnaroundTime  WaitingTime\n");
while(i<=n)
{
printf("\n\t%d\t%d\t   %d\t           %d\t          %d\t          %d",p[i].pid,p[i].at,p[i].bt,p[i].ft,p[i].tt,p[i].wt);
avgwt=p[i].wt+avgwt;
avgtt=p[i].tt+avgtt;
i++;
}
avgtt=avgtt/n;
avgwt=avgwt/n;
printf("\n\n Average Turnaround Time = %.2f \n Average Waiting Time    = %.2f\t",avgtt,avgwt);
return 0;
}
