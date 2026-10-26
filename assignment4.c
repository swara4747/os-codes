#include<stdio.h>

int main(){
    int i, n;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    int totaltat=0;
    int totalwt=0;
    float avgtat, avgwt;
    
    printf("enter the number of processes :\n");
    scanf("%d", &n);
    printf("enter the arrival and the burst time for all the processess:  ");
    for(i=0;i<n;i++){
        scanf("%d %d", &at[i], &bt[i]);
    }
    
    
    //calculating ct 
    
    ct[0]=at[0]+bt[0];
    for (i=1;i<n;i++){
        if(ct[i-1]<at[i]){
            ct[i]=at[i]+bt[i];
        }
        else {
            ct[i]=ct[i-1]+bt[i];
        }
    }
    
    //calculating tat, wt
    for (i=0;i<n;i++){
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
    
    totaltat=totaltat+tat[i];
    totalwt=totalwt+wt[i];
    }
    
    avgtat=totaltat/n;
    avgwt=totalwt/n;
    
    
    
    //displaying
    
    printf("gantt chart\n\n");
   printf(" \tAT\tBT\tCT\tTAT\tWT\n");
    for (i=0;i<n;i++){
        
        printf("pno.%d\t%d\t%d\t%d\t%d\t%d\t", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
        printf("\n");
        
    }
    printf("average turnaround time: %0.2f\n", avgtat);
        printf("average wait time: %0.2f\n\n", avgwt);
    return 0;
}
