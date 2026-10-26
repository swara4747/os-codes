#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
int p[2];
int id;
char msg[100];
char a[100];

pipe(p);
id=fork();

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>

int main(){
    int pid;
    int p[2];            //pipe
    char msg[100];
    int a[100];
    
    
    pipe(p);
    pid=fork();
    
    if (pid>0){            //parent process
    close(p[0]);           
    printf("enter a message : \n");
    fgets(msg, 100, stdin);
    
    write(p[1], msg, strlen(msg)+1);
    close(p[1]);
    
    wait(NULL);
    printf("parent process terminated\n");
    }


    else if(pid==0){           //child process
    close(p[1]);
    read(p[0], a , sizeof(a));
    printf("message from parent process is :  %s", a);
    close (p[0]);
    }
    
    else{
        printf("Process fork creation failed");
        return 0;
    }
}
