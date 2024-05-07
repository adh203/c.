#include <stdio.h>
int main()
{
        int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avgwt,avgtat;
        printf("Enter total no of processes");
        scanf("%d",&n);
        printf("\n Burst time and priority\n");
        for(i=0;i<n;i++)
        {
                printf("\n p[%d]\n",i+1);
                printf("Burst time: ");
                scanf("%d",&bt[i]);
                printf("priority");
                scanf("%d",&pr[i]);
                p[i]=i+1;
        }
        for(i=0;i<n;i++)
        {
                pos=i;
                for(j=i+1;j<n;j++)
                {
                        if(pr[j]<pr[pos])
                        pos=j;
                }
                temp=pr[i];
                pr[i]=pr[pos];
                pr[pos]=temp;
                temp=bt[i];
                bt[i]=bt[pos];
                bt[pos]=temp;
                temp=p[i];
                p[i]=p[pos];
                p[pos]=temp;
        }
        wt[0]=0;
        for(i=0;i<n;i++)
        {
                wt[i]=0;
                for(j=0;j<i;j++)
                wt[i]+=bt[j];
                total+=wt[i];
        }
        avgwt=total/n;
        total=0;
        printf("\nProcess\tBurst time\tWaiting time \tTurnaround time");
        for(i=0;i<n;i++)
        {
                tat[i]=bt[i]+wt[i];
                total+=tat[i];
                printf("\n p[%d]\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
        }
        avgtat=total/n;
        printf("\n\nAvg wt=%d",avgwt);
        printf("\n Avg tat=%d\n",avgtat);
        return 0;
}
