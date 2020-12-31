#include<stdio.h>
struct process
{
int pid,at,bt,ct,tt,wt;
}p[10],temp;

int main()
{
int i,j,n;
float avgtt=0,avgwt=0;
printf("Shortest Job First Scheduling\n\n");
printf("enter the no of processes:\t");
scanf("%d",&n);

for(i=1;i<=n;i++)
{
p[i].pid=i;
printf("\nenter the arrival time for process %d:\t",i);
scanf("%d",&p[i].at);
printf("\nenter the burst time for process %d:\t",i);
scanf("%d",&p[i].bt);
}

printf("\n\nInitial listing:\n   processid\tat\tbt\n");
for(i=1;i<=n;i++)
{
printf("\n\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt);
}

for(i=1;i<n;i++)
{
for(j=i+1;j<=n;j++)
{
if(p[i].bt>p[j].bt)
{
temp.pid=p[i].pid;
p[i].pid=p[j].pid;
p[j].pid=temp.pid;
temp.bt=p[i].bt;
p[i].bt=p[j].bt;
p[j].bt=temp.bt;
}}}

p[1].wt=0;
for(i=1;i<=n;i++)
{
p[i].ct=p[i].bt+p[i-1].ct;
p[i].tt=p[i].ct-p[i].at;
p[i].wt=p[i].tt-p[i].bt;
}

printf("\n\nSorted Burst Time:\n  processid\tat\tbt\tct\ttt\twt\n");

for(i=1;i<=n;i++)
{
printf("\n\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
avgwt=p[i].wt+avgwt;
avgtt=p[i].tt+avgtt;
}
avgtt=avgtt/n;
avgwt=avgwt/n;
printf("\n\n avgtt = %.2f\t avgwt = %.2f\n",avgtt,avgwt);
return 0;
}