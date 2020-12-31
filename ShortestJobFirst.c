#include<stdio.h>
struct process
{
int pid,bt,wt,tt;
} p[10],temp;

int main()
{ 
 int i,j,n;
float avgwt,avgtt;
printf("SJF Scheduling\n");
printf("\nEnter the number of process:\t");
scanf("%d",&n);

for(i=1;i<=n;i++)
{
p[i].pid=i;
printf("\nEnter the burst time:\t");
scanf("%d",&p[i].bt);
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
temp.bt=p[i].bt;p[i].bt=p[j].bt;
p[j].bt=temp.bt;
}}}

p[1].wt=0;
p[1].tt=p[1].bt+p[1].wt;
for(i=2;i<=n;i++)
{
p[i].wt=p[i-1].bt+p[i-1].wt;
p[i].tt=p[i].bt+p[i].wt;
}

printf("\n\nProcess id \tbt \twt \ttt");
for(i=1;i<=n;i++)
{
printf("\n\t%d \t%d \t%d \t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
avgwt=p[i].wt+avgwt;
avgtt=p[i].tt+avgtt;
}

avgwt=avgwt/n;
avgtt=avgtt/n;
printf("\navgwt=%.2f\t avgtt=%.2f",avgwt,avgtt);
return 0;
}
