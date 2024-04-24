#include <stdio.h>
#include <stdbool.h>

int main()
{
    int frames, pages;

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("Enter the number of pages: ");
    scanf("%d", &pages);

    int pageRequests[pages];
    int frame[frames];
    int counter[frames];
    bool isPageFound;

    printf("Enter the page requests:\n");
    for (int i = 0; i < pages; i++)
    {
        scanf("%d", &pageRequests[i]);
    }

    // Initialize frame and counter arrays
    for (int i = 0; i < frames; i++)
    {
        frame[i] = -1;  // -1 indicates an empty frame
        counter[i] = 0; // Counter to maintain LRU
    }

    int pageFaults = 0;
    int hits = 0;

    printf("Page Requests\tFrames\n");

    for (int i = 0; i < pages; i++)
    {
        isPageFound = false;

        for (int j = 0; j < frames; j++)
        {
            if (pageRequests[i] == frame[j])
            {
                isPageFound = true;
                hits++;
                counter[j] = i + 1; // update counter to current index
                break;
            }
        }

        if (!isPageFound)
        {
            int lruIndex = 0;
            int lruCounter = counter[0];
            for (int j = 1; j < frames; j++)
            {
                if (counter[j] < lruCounter)
                {
                    lruIndex = j;
                    lruCounter = counter[j];
                }
            }
        
        frame[lruIndex] = pageRequests[i];
        counter[lruIndex] = i+1; //Update counter to counter Index
        pageFaults++;
    }

    printf("%d\t\t", pageRequests[i]);
    for (int j = 0; j < frames; j++)
    {
        if (frame[j] != -1)
            printf("%d\t", frame[j]);
        else
            printf("-\t");
    }
    printf("\n");
}

// Calculate Hit Ratio and Miss Ratio
float hitRatio = (float)hits / pages;
float missRatio = (float)pageFaults / pages;

printf("\nTotal Page Faults: %d\n", pageFaults);
printf("Hit Ratio: %.2f\n", hitRatio);
printf("Miss Ratio: %.2f\n", missRatio);

return 0;
}


// Enter the number of frames: 3
// Enter the number of pages: 12
// Enter the page requests:
// 7 0 1 2 0 3 0 4 2 3 0 3