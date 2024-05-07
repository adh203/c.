#include <stdio.h>
void main()
{
        int i,n,total=0,temp,count=0,qt;
        int wt[10],bt[10],tat[10],rem_bt[10];
        float awt=0,atat=0;
        printf("\nEnter the total number of processes:\n");
        scanf("%d",&n);
        printf("Enter the burst time of processes:\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&bt[i]);
                rem_bt[i]=bt[i];
        }
        printf("\nEnter time quantum:\t");
        scanf("%d",&qt);
        while(1)
        {
                for(i=0,count=0;i<n;i++)
                {
                        temp=qt;
                        if(rem_bt[i]==0)
                        {
                                count++;
                                continue;
                        }
                        if(rem_bt[i]>qt)
                        rem_bt[i]=rem_bt[i]-qt;
                        else
                        if(rem_bt[i]>=0)
                        {
                                temp=rem_bt[i];
                                rem_bt[i]=0;
                        }
                        total=total+temp;
                        tat[i]=total;
                }
                if(n==count)
                break;
        }
        printf("\npid\tBurst time\tTurnaround time\twaiting time\n");
        for(i=0;i<n;i++)
        {
                wt[i]=tat[i]-bt[i];
                awt=awt+wt[i];
                atat=atat+tat[i];
                printf("\n%d\t%d\t%d\t%d\t",i+1,bt[i],tat[i],wt[i]);
        }
        awt=awt/n;
        atat=atat/n;
        printf("\nAverage waiting time:\t%f",awt);
        printf("\nAverage turnaround time:\t%f\n",atat);
}
