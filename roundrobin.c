#include <stdio.h>

int main(){
    int n,bt[15],at[15],temp_bt[15],ta_time = 0,wait_time = 0;
    
        printf("Enter the number of processes ");
        scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        printf("enter the burst time and arrival time for %d process",i+1);
        scanf("%d %d",&bt[i],&at[i]);
        temp_bt[i]=bt[i];
    }
    printf("Enter time slot \n");
    int tslot;
    scanf("%d",&tslot);
    
    int i,total,counter=0;
      printf("Process ID       Burst Time       Turnaround Time      Waiting Time\n");
    for(total=0, i = 0; n!=0;)  
    {
        if(temp_bt[i]<=tslot && temp_bt[i]>0){
            total = total + temp_bt[i];
            temp_bt[i]=0;
            counter=1;
        }
        else if(temp_bt[i] >0){
            temp_bt[i] =  temp_bt[i]-tslot;
            total  += tslot;
        }
        if(temp_bt[i]== 0 && counter==1){
            printf("\nProcess No %d  \t\t %d\t\t\t\t %d\t\t\t %d",
             i+1, 
             bt[i],
            total-at[i], total-at[i]-bt[i]);  
            wait_time = wait_time+total-at[i]-bt[i];  
            ta_time += total -at[i];  
            counter =0; 
        }
        if(i==n-1)  
        {  
            i=0;  
        }  
        else if(at[i+1]<=total)  
        {  
            i++;  
        }  
        else  
        {  
            i=0;  
        }  
    }  
    float average_wait_time = wait_time * 1.0 / n;
    float average_turnaround_time = ta_time * 1.0 / n;
    printf("\nAverage Waiting Time:%f", average_wait_time);
    printf("\nAvg Turnaround Time:%f", average_turnaround_time);
    return 0;
}


// Enter the number of processes: 4
// enter the burst time and arrival time for 1 process: 5 0
// enter the burst time and arrival time for 2 process: 4 1
// enter the burst time and arrival time for 3 process: 2 2
// enter the burst time and arrival time for 4 process: 3 3
// Enter time slot: 2