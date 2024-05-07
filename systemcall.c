Hello

#include <stdio.h>
#include <unistd.h>
void main()
{
        fork();
        printf("hello\n");
        fork();
        printf("world\n");
}

Oddeven

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
void main()
{
        pid_t p;
        int a;
        printf("Enter the range: ");
        scanf("%d",&a);
        p=fork();
        for(int i=0;i<=a;i++)
        {
                if(p==0)
                {
                        if(i%2==0)
                        {
                                printf("%d\n",i);
                        }
                }
                else if(p>0)
                {
                        if(i%2!=0)
                        {
                                printf("%d\n",i);
                        }
                }
        }
}


execv 

#include <stdio.h>
void main()
{
        int pid;
        printf("This is the first.c called by execv\n");
        printf("process id of first %d",getpid());
}
#include <stdio.h>
#include <unistd.h>
void main()
{
        int pid;
        char*args[]={"./first",NULL};
        printf("process id of second %d",getpid());
        printf("before execv\n");
        execv(args[0],args);
        printf("after execv\n");
}


stat

#include <stdio.h>
#include <sys/stat.h>
void main()
{
        printf("Enter the name of the file:");
        char f_name[78];
        scanf("%s",f_name);
        struct stat s;
        stat(f_name,&s);
        printf("Last access time of file:%d\n",s.st_atime);
        printf("Last modified time: %d\n",s.st_mtime);
        printf("Size of file:%d\n",s.st_size);
        printf("file mode:%o\n",s.st_mode);
}


pid ppid

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
void main()
{
        pid_t pid;
        pid=fork();
        if(pid==0)
        {
                printf("pid of child=%d\npid pf parent of child:%d\n",getpid(),getppid());
        }
        if(pid>0)
        {
                wait(NULL);
                printf("pid of parent=%d\npid of parent of parent:%d\n",getpid(),getppid());
        }
}


directory search

#include <stdio.h>
#include <stdlib.h>
#include <sys/dir.h>
#include <string.h>
int search(char[],char[]);
void main()
{
        printf("Enter the name of the directory to search in:");
        char name[60];
        scanf("%s",name);
        printf("Enter the name of the file to search;");
        char f_name[60];
        scanf("%s",f_name);
        int a=search(name,f_name);
        if(a)
        {
                printf("File is not found\n");
        }
        else
        {
                printf("File is found \n");
        }
}
int search(char dname[],char file[])
{
        DIR *dptr=opendir(dname);
        if(dptr==NULL)
        {
                printf("directory not found\n");
                exit(0);
        }
        else
        {
                struct dirent *entry=readdir(dptr);
                while(entry!=NULL)
                {
                        if(strcmp(entry->d_name,file)==0)
                        return 0;
                        entry=readdir(dptr);
                }
                return 1;
        }
}
