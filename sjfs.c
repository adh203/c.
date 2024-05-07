#include <stdio.h>
void main()
{
        float avgwt,avgtat;
        int bt[20],p[20],wt[20],tat[20],i,j,n,totalit=0,pos,temp,total=0;
        printf("Enter the no of processes");
        scanf("%d",&n);
        printf("Enter burst time\n");
        for(i=0;i<n;i++)
        {
                printf("p%d",i+1);
                scanf("%d",&bt[i]);
                p[i]=i+1;
        }
        for(i=0;i<n;i++)
        {
                pos=i;
                for(j=i+1;j<n;j++)
                {
                        if(bt[j]<bt[pos])
                        pos=j;
                }
                temp=bt[i];
                bt[i]=bt[pos];
                bt[pos]=temp;
                temp=p[i];
                p[i]=p[pos];
                p[pos]=temp;
        }
        wt[0]=0;
        for(i=1;i<n;i++)
        {
                wt[i]=0;
                for(j=0;j<i;j++)
                {
                        wt[i]+=bt[j];
                }
                total+=wt[i];
        }
        avgwt=(float)total/n;
        printf("\nprocess\tburst time\twaiting time\tturn around time");
        for(i=0;i<n;i++)
        {
                tat[i]=bt[i]+wt[i];
                totalit+=tat[i];
                printf("\np%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
        }
        avgtat=(float)totalit/n;
        printf("\nAverage waiting time=%f",avgwt);
        printf("\nAverage turn around time=%f",avgtat);
}
