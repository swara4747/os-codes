#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

pid_t num_pid;

int main(){
    int n, temp,i,j;

    printf("Enterthe size of array: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter %d elements of array: ",n);
    for (i =0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    num_pid = fork();

    if (num_pid < 0)
    {
        printf("Error in fork execution\n");
        exit(1);
    }
    else if (num_pid == 0)   // Child process
    {
        // Descending order
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (a[j] < a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }

        printf("Child process in descending order: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");

        exit(0);
    }
    else   // Parent process
    {
        // Ascending order
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }

        printf("Parent process in ascending order: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");

        wait(NULL);
    }

    return 0;
}
