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
    bool isPageFound;

    printf("Enter the page requests:\n");
    for (int i = 0; i < pages; i++)
    {
        scanf("%d", &pageRequests[i]);
    }

    // Initialize frame array
    for (int i = 0; i < frames; i++)
    {
        frame[i] = -1; // -1 indicates an empty frame
    }

    int pageFaults = 0;
    int hits = 0;

    printf("Page Requests\tFrames\n");

    for (int i = 0; i < pages; i++)
    {
        isPageFound = false;

        // Check if the page is already in a frame
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pageRequests[i])
            {
                isPageFound = true;
                hits++;
                break;
            }
        }

        // If page is not found in frames
        if (!isPageFound)
        {
            int farthestIndex = i + 1; // Initialize to the next page request index
            int replaceIndex = -1;

            // Find the farthest page in the future
            for (int j = 0; j < frames; j++)
            {
                int k;
                for (k = i + 1; k < pages; k++)
                {
                    if (frame[j] == pageRequests[k])
                    {
                        if (k > farthestIndex)
                        {
                            farthestIndex = k;
                            replaceIndex = j;
                        }
                        break;
                    }
                }

                // If page is not found in future requests
                if (k == pages)
                {
                    replaceIndex = j;
                    break;
                }
            }

            if (replaceIndex != -1)
            {
                frame[replaceIndex] = pageRequests[i];
            }

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
