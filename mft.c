#include<stdio.h>

int main()
{
    int ms,bs,nob,n,mp[10],tif=0,ef,p=0;
    printf("Enter total memory size:");
    scanf("%d",&ms);
    printf("Enter block size:");
    scanf("%d",&bs);
    nob=ms/bs;
    printf("Enter no. of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter size of process %d:",i+1);
        scanf("%d",&mp[i]);
    }
    ef=ms-(nob*bs);
    printf("No. of blocks available in memory=%d\n",nob);
    printf("\n\nProcess\tMemory Reqd\tAllocated\tInternal fragmentation");
    for(int i=0;i<n && p<nob;i++){
        printf("\n%d\t\t%d\t\t",i+1,mp[i]);
        if(mp[i]>bs){
            printf("No\t--");
        }
        else{
            tif+=(bs-mp[i]);
            printf("Yess\t%d",bs-mp[i]);
            p++;
        }
    }
    if(nob<n){
        printf("\nRemaining processes cannot be allocated\n");
        printf("Total internal fragmentation=%d\n",tif);
        printf("External fragmentation=%d\n",ef);
    }

    return 0;
}

// Enter total memory size: 1000
// Enter block size: 200
// Enter no. of processes: 5
// Enter size of process 1: 150
// Enter size of process 2: 400
// Enter size of process 3: 250
// Enter size of process 4: 100
// Enter size of process 5: 350
