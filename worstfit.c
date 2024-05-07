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
                best=-1;
                for(int j=0;j<n;j++)
                {
                        if(b[i].size<=a[j])
                        {
                               if(best==-1)
                               {
                                        best=j;
                                }
                                else if(a[j]>a[best])
                                {
                                        best=j;
                                }
                        }
                }
                if(best!=-1)
                {
                        b[i].allocated=a[best];
                        a[best]=a[best]-b[i].size;
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
                        printf("\n%d\t%d\tnot allocated",i+1,b[i].size);
                }
        }
        printf("\n");
}
