#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("enter the number of disk requests \n");
    scanf("%d",&n);

    int requests[n];

    for(int i=0;i<n;i++){
        printf("enter the disk request %d \n",i+1);
    scanf("%d",&requests[i]);
    }

    printf("Enter the initial head position \n");
    int head;
    scanf("%d",&head);

    printf("\nFCFS Disk Scheduling Sequence:\n");
    printf("%d -> ", head);
    
    int total=0;
    
    for(int i=0;i<n;i++){
        total += abs(head - requests[i]);
        head=requests[i];
        printf("%d -> ",head);
    }

    printf("total head movement %d ",total);
    return 0;
}

// enter the number of disk requests 
// 5
// enter the disk request 1 
// 98
// enter the disk request 2 
// 183
// enter the disk request 3 
// 37
// enter the disk request 4 
// 122
// enter the disk request 5 
// 14
// Enter the initial head position 
// 53
