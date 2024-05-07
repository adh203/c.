include <stdio.h>
void main()
{
        int noofprocesses,noofresources=3,available[10],work[10],max[10][10],need[10][10],allocation[10][10];
        int i,j,flag=0,ss[10],k=0,finish[10],l;
        printf("Enter no of processes and resources");
        scanf("%d%d",&noofprocesses,&noofresources);
        printf("Enter allocation matrix\n");
        for(i=0;i<noofprocesses;i++)
        for(j=0;j<noofresources;j++)
        scanf("%d",&allocation[i][j]);
        printf("Enter max matrix\n");
        for(i=0;i<noofprocesses;i++)
        for(j=0;j<noofresources;j++)
        scanf("%d",&max[i][j]);
        printf("Enter available resources\n");
        for(i=0;i<noofresources;i++)
        {
                scanf("%d",&available[i]);
                work[i]=available[i];
        }
        for(i=0;i<noofprocesses;i++)
        finish[i]=0;
        for(i=0;i<noofprocesses;i++)
        for(j=0;j<noofresources;j++)
        need[i][j]=max[i][j]-allocation[i][j];
        printf("need matrix is\n");
        for(i=0;i<noofprocesses;i++)
        {
                for(j=0;j<noofresources;j++)
                printf("%d\t",need[i][j]);
                printf("\n");
        }
        for(l=0;l<noofprocesses;l++)
        {
                for(i=0;i<noofprocesses;i++)
                {
                        flag=0;
                        if(finish[i]==0)
                        {
                                for(j=0;j<noofresources;j++)
                                {
                                        if(need[i][j]>work[j])
                                        {
                                                flag=1;
                                                break;
                                        }
                                }
                                if(flag==0)
                                {
                                        for(j=0;j<noofresources;j++)
                                        {
                                                work[j]+=allocation[i][j];
                                        }
                                        ss[k]=i;
                                        k=k+1;
                                        finish[i]=1;
                                }
                        }
                }
        }
        flag=1;
        for(i=0;i<noofprocesses;i++)
        {
                if(finish[i]==0)
                {
                        flag=0;
                        printf("System is not safe\n");
                        break;
                }
        }
        if(flag==1)
        {
                printf("safe sequence is");
                for(i=0;i<noofprocesses-1;i++)
                printf("p%d->",ss[i]);
                printf("p%d",ss[noofprocesses-1]);
        }
}
