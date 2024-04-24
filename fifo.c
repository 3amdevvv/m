#include <stdio.h>

int main()
{
    int frames;
    int pages;

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("Enter the number of pages: ");
    scanf("%d", &pages);

    int incomingStream[pages];

    printf("Enter the page requests:\n");
    for (int i = 0; i < pages; i++)
    {
        scanf("%d", &incomingStream[i]);
    }

    int pageFaults = 0;
    printf("Incoming \t frame 1\t frame 2 \t frame 3 \n");
    int temp[frames];
    for(int m=0;m<frames;m++){
        temp[m]=-1;
    }

    for(int m=0;m<frames;m++){
        int s=0;
        for(int n=0;n<frames;n++){
            if(incomingStream[m] == temp[n]){
                s++;
                pageFaults--;
            }
        }
        pageFaults++;

        if((pageFaults <= frames ) && (s==0)){
            temp[m]=incomingStream[m];
        }else if(s==0){
            temp[(pageFaults-1)%frames] = incomingStream[m];
        }
       printf("%d\t\t\t", incomingStream[m]);
        for (int n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
                printf("%d\t\t\t", temp[n]);
            else
                printf("-\t\t\t");
        }
        printf("\n");
    }

    float missRatio = (float)pageFaults / pages;
    float hitRatio = 1 - missRatio;

    printf("\nMiss Ratio:\t%.2f\n", missRatio);
    printf("Hit Ratio:\t%.2f\n", hitRatio);

    return 0;
}


// Enter the number of frames: 3
// Enter the number of pages: 12
// Enter the page requests:
// 7 0 1 2 0 3 0 4 2 3 0 3