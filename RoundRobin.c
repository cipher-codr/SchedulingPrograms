#include<stdio.h>
struct process
{
int pid,bt,tt,wt;
};
int main()
{
struct process x[10],p[30];
int i,j,k,n,m,tot=0;
float wttime=0.0,tottime=0.0,a1,a2;
printf("enter the no of processes:\t");
scanf("%d\n",&n);

for(i=1;i<=n;i++)
{
p[i].pid=i;
printf("enter the burst time for process %d:\t",i);
scanf("%d\n",&x[i].bt);
tot=tot+x[i].bt;
}
printf("\nTotal Burst Time:\t%d",tot);
p[0].tt=0;
k=1;
printf("\nEnter the Time Slice:\t");
scanf("%d",&m);
for(j=1;j<tot;j++)
{
for(i=1;i<=n;i++)
{
if(x[i].bt!=0)
{
p[k].pid=i;
if(x[i].bt-m<0)
{
p[k].wt=p[k-1].tt;
p[k].bt=x[i].bt;
p[k].tt=p[k].wt+x[i].bt;
x[i].bt=0;
k++;
}
else
{
p[k].wt=p[k-1].tt;
p[k].tt=p[k].wt+m;
p[k].bt=x[i].bt-m;
k++;
}}}

printf("\n\n processid\twt\ttt");
for(i=1;i<k;i++)
{
printf("\n\t%d\t%d\t%d\n",p[i].pid,p[i].wt,p[i].tt);
wttime=wttime+p[i].wt;
tottime=totime+p[i].tt;
a1=wttime/n;
a2=tottime/n;
}
printf(" \n\n Average Waiting Time:\t %f",a1);
printf("\n\nAverage Turnaround Time:\t%f",a2);
return 0;
}