#include <stdio.h>

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int n,bt[15],p[15],index[15];
    
        printf("Enter the number of processes ");
        scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        printf("enter the burst time and priority for %d process",i+1);
        scanf("%d %d",&bt[i],&p[i]);
        index[i]=i+1;
    }
    int m,a;
    for(int i=0;i<n;i++){
        a=p[i];
        m=i;
        for(int j=i;j<n;j++){
            if(p[j]>a){
                a=p[j];
                m=j;
            }
        }
         swap(&p[i], &p[m]);
        swap(&bt[i], &bt[m]);
        swap(&index[i],&index[m]);
    }
        // T stores the starting time of process
    int t=0;
 
    //Printing scheduled process
    printf("Order of process Execution is\n");
    for(int i=0;i<n;i++)
    {
        printf("P %d is executed from %d to %d\n",index[i],t,t+bt[i]);
        t+=bt[i];
    }
    printf("\n");
    printf("Process Id     Burst Time   Wait Time    TurnAround Time\n");
    int wait_time=0;
    for(int i=0;i<n;i++)
    {
        printf("P%d          %d          %d          %d\n",index[i],bt[i],wait_time,wait_time + bt[i]);
        wait_time += bt[i];
    }
    return 0;
}
