#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n, head, j = 0, a[50],mov=0;
    printf("Enter the head position \n");
    scanf("%d", &head);
    printf("Enter the number of requests \n");
    scanf("%d", &n);
    int req[n];
    int head1 = head, index[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    for(int k=0;k<n;k++){
    for (int i = 0; i < n; i++)
    {
        index[i] = abs(head - req[i]);
    }
    int min = index[0];
    int mini = 0;
    for (int i = 0; i < n; i++)
    {
        
            if (min > index[i])
            {
                min = index[i];
                mini = i;
            }
        }
        a[j] = req[mini];
        j++;
        head = req[mini];
        req[mini] = 999;
    }
    printf("Sequence is ");
    printf("%d -> ",head1);
    mov=mov+abs(head1-a[0]);    // head movement
    printf(" -> %d",a[0]);
    for(int i=1;i<n;i++){
        mov=mov+abs(a[i]-a[i-1]);
        printf("%d -> ",a[i]);
    }
    printf("\n");
    printf("total head movement = %d\n",mov);
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

