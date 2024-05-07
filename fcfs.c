include <stdio.h>
void main()
{
        int pid[15];
        int bt[15];
        int n;
        printf("Enter the number of processes");
        scanf("%d",&n);
        printf("Enter process id of all the processes");
        for(int i=0;i<n;i++)
        {
                scanf("%d",&pid[i]);
        }
        printf("Enter burst time of all the processes");
        for(int i=0;i<n;i++)
        {
                scanf("%d",&bt[i]);
        }
        int i,wt[n];
        wt[0]=0;
        for(i=1;i<n;i++)
        {
                wt[i]=bt[i-1]+wt[i-1];
        }
        printf("process  Burst Time  Waiting Time  Turnaround Time\n");
        float twt=0.0;
        float tat=0.0;
        for(i=0;i<n;i++)
        {
                printf("%d\t\t",pid[i]);
                printf("%d\t\t",bt[i]);
                printf("%d\t\t",wt[i]);
                printf("%d\t\t",bt[i]+wt[i]);
                printf("\n");
                twt+=wt[i];
                tat+=(wt[i]+bt[i]);
        }
        float att,awt;
        awt=twt/n;
        att=tat/n;
        printf("Average waiting time=%f\n",awt);
        printf("Average turn around time=%f",att);
}
