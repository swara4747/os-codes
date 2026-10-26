#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>


//functions sortarray and printarray
void sortarray(int a[], int n, int asc){          //asc 0 is descending and asc 1 is ascending 
    int i, j, t;
    
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            
            if ((asc && a[j]>a[j+1]) || (!asc && a[j]<a[j+1])){
                t= a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    
}


void printarray(int a[], int n){
    
    for (int i=0;i<n;i++){
        printf("%d", a[i]);
        printf("\n");
    }
}



//int main for taking user input of array

int main(){
    pid_t pid;               //pid_t comes under library <sys/types.h>
    int a[50];
    int i;
    int n; 
    int status;
    

printf("enter the number of elements inside the array: \n");
scanf("%d", &n);
printf("enter the array\n");
for (int i=0;i<n;i++){
    scanf("%d", &a[i]);
}


//performing fork conditions 

pid=fork();

if (pid<0){
    printf("fork formation failed\n");
    exit(1);                 //exit 1 is failure exit 
}

else if (pid==0){            //this is the child process
    printf("PID: %d, and PPID: %d\n", getpid(), getppid());
    printf("child process will be sorting the array in descending order: \n");
    sortarray(a, n, 0);
    printarray(a, n);
    exit(0);                     //exit 0 is succesful exit 
}

else {                            //parent process
wait(&status);                         //it will wait for the child process to give its status and then simultaneously execute its program
printf("PID: %d\n", getpid());
printf("the parent process will be sorting the array in ascending order: \n");
sortarray(a, n, 1);
printarray(a, n);
}

return 0;
}


//zombie process 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void sortarray(int a[], int n, int asc) {      // 1 = ascending, 0 = descending
    int i, j, t;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if ((asc && a[j] > a[j+1]) || (!asc && a[j] < a[j+1])) {
                t = a[j]; a[j] = a[j+1]; a[j+1] = t;
            }
}

void printarray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[50], n, i;
    pid_t pid;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    pid = fork();

    if (pid < 0) {
        printf("fork failed\n");
        exit(1);
    }
    else if (pid == 0) {                       // child
        printf("Child PID=%d sorting ascending:\n", getpid());
        sortarray(a, n, 1);
        printarray(a, n);
        exit(0);                               // child dies first
    }
    else {                                     // parent
        printf("Parent PID=%d sleeping, NOT calling wait()\n", getpid());
        sleep(30);                             // child is a zombie meanwhile
        printf("Parent done\n");
    }
    return 0;
}



//orphan process


int main() {
    int a[50], n, i;
    pid_t pid;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    pid = fork();

    if (pid < 0) {
        printf("fork failed\n");
        exit(1);
    }
    else if (pid == 0) {                       // child
        printf("Child PID=%d, PPID=%d (parent alive)\n", getpid(), getppid());
        sleep(5);                              // parent dies meanwhile
        printf("Child PID=%d, PPID=%d (now orphan), sorting descending:\n",
               getpid(), getppid());
        sortarray(a, n, 0);
        printarray(a, n);
    }
    else {                                     // parent
        printf("Parent PID=%d exiting\n", getpid());
        exit(0);                               // parent dies first
    }
    return 0;
}
