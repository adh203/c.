#include <stdio.h>
struct process
{
        int size;
        int allocated;
};
void main()
{
        int n,p,best;
        printf("Enter the no of memory locations");
        scanf("%d",&n);
        int a[n];
        printf("Enter the size of each memory location");
        for(int i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
        printf("Enter the no of processes");
        scanf("%d",&p);
        struct process b[p];
        printf("Enter the size of each process");
        for(int i=0;i<p;i++)
        {
                scanf("%d",&b[i].size);
                b[i].allocated=-1;
        }
        for(int i=0;i<p;i++)
        {
                for(int j=0;j<n;j++)
                {
                        if(a[j]>=b[i].size)
                        {
                                b[i].allocated=a[j];
                                a[j]=a[j]-b[i].size;
                                break;
                        }
                }
        }
        printf("\ns.no\tprocess\tallocated");
        for(int i=0;i<p;i++)
        {
                if(b[i].allocated!=-1)
                {
                        printf("\n%d\t%d\t%d\t",i+1,b[i].size,b[i].allocated);
                }
                else
                {
                        printf("\n%d\t%d\t not allocated",i+1,b[i].size);
                }
        }
        printf("\n");
}
