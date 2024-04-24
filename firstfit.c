#include<stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) 
{ 
    int i, j; 
    int allocation[n]; 

    for(i = 0; i < n; i++) 
    { 
        allocation[i] = -1; 
    } 
    
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            if (blockSize[j] >= processSize[i]) 
            { 
                allocation[i] = j; 
                blockSize[j] -= processSize[i]; 
                break; 
            } 
        } 
    } 

    printf("\nProcess No.\tProcess Size\tBlock no.\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf(" %i\t\t\t", i+1); 
        printf("%i\t\t\t\t", processSize[i]); 
        if (allocation[i] != -1) 
            printf("%i", allocation[i] + 1); 
        else
            printf("Not Allocated"); 
        printf("\n"); 
    } 
} 

int main() 
{ 
    int m, n;
    
    printf("Enter the number of blocks in memory: ");
    scanf("%d", &m);

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int blockSize[m], processSize[n];

    printf("Enter the block sizes:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the process sizes:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processSize[i]);
    }

    firstFit(blockSize, m, processSize, n); 

    return 0; 
} 

// Enter the number of blocks in memory: 5
// Enter the number of processes: 4
// Enter the block sizes:
// 100 200 300 400 500
// Enter the process sizes:
// 212 417 112 426
