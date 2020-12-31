

#include<stdio.h>
struct process
{
int pid,bt,wt,tt,prior;
} p[10],temp;

int main()
{
int i,j,n,avgwt=avgtt=0;

printf("Priority Scheduling\n");
printf("enter the number of process");
scanf("%d",&n);


for(i=1;i<=n;i++)
{
p[i].pid=i;
printf("enter the burst time of process %d",i);
scanf("%d",&p[i].bt);
printf("\n enter the priority");
scanf("%d",&p[i].prior);
}

for(i=1;i<n;i++)
{ 
for(j=i+1;j<=n;j++)
{
if(p[i].prior>p[j].prior)

{
temp.pid=p[i].pid;
p[i].pid=p[j].pid;
p[j].pid=temp.pid;
temp.bt=p[i].bt;
p[i].bt=p[j].bt;
p[j].bt=temp.bt;
temp.prior=p[i].prior;
p[i].prior=p[j].prior;
p[j].prior=temp.prior;
}
}
}
p[i].wt=0;
p[1].tt=p[1].bt+p[1].wt;
for(i=2;i<=n;i++)
{
p[i].wt=p[i-1].bt+p[i-1].wt;
p[i].tt=p[i].bt+p[i].wt;
}


printf("\n process to \t bt \t wt \t tt");
for(i=1;i<=n;i++)
{
printf("\n%d\t %d\t %d\t %d\t",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
avgwt=p[i].wt+avgwt;
avgtt=p[i].tt+avgtt;
}

avgwt=avgwt/n;
avgtt=avgtt/n;

printf("\n Average Waiting Time=%d \t 
Average Turnaround Time=%d\t",avgwt,avgtt);
return 0;
}