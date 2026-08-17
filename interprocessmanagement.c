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

if(id>0)
{
close(p[0]);

printf("Enter a message: ");
fgets(msg,100,stdin);

write(p[1],msg,strlen(msg)+1);
close(p[1]);

wait(NULL);
printf("Parent process is terminated\n");
}
else if(id==0)
{
close(p[1]);

read(p[0],a,sizeof(a));

printf("Child process id is %d\n",getpid());
printf("Message: %s",a);

close(p[0]);
}

return 0;
}
