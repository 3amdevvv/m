#include <stdio.h>
#include <stdbool.h>

int main() {
    int frames, pages;

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("Enter the number of pages: ");
    scanf("%d", &pages);

    int pageRequests[pages];
    int frame[frames];
    bool isPageInFrame[frames];
    int pageFaults = 0;
    int hits = 0;

    printf("Enter the page requests:\n");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &pageRequests[i]);
    }

    // Initialize frames
    for (int i = 0; i < frames; i++) {
        frame[i] = -1; // -1 indicates an empty frame
        isPageInFrame[i] = false;
    }

    // Simulate Paging
    printf("\nPage Requests\tFrames\n");
    for (int i = 0; i < pages; i++) {
        bool pageFound = false;

        // Check if page is already in frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pageRequests[i]) {
                isPageInFrame[j] = true;
                pageFound = true;
                hits++;
                break;
            }
        }

        // If page not found, replace a page
        if (!pageFound) {
            int replaceIndex = -1;
            for (int j = 0; j < frames; j++) {
                if (!isPageInFrame[j]) {
                    replaceIndex = j;
                    break;
                }
            }

            if (replaceIndex == -1) {
                int farthest = i;
                for (int j = 0; j < frames; j++) {
                    int k;
                    for (k = i + 1; k < pages; k++) {
                        if (frame[j] == pageRequests[k]) {
                            if (k > farthest) {
                                farthest = k;
                                replaceIndex = j;
                            }
                            break;
                        }
                    }
                    if (k == pages) {
                        replaceIndex = j;
                        break;
                    }
                }
            }

            frame[replaceIndex] = pageRequests[i];
            isPageInFrame[replaceIndex] = true;
            pageFaults++;
        }

        // Display current page request and frames
        printf("%d\t\t", pageRequests[i]);
        for (int j = 0; j < frames; j++) {
            if (isPageInFrame[j]) {
                printf("%d\t", frame[j]);
            } else {
                printf("-\t");
            }
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
// Enter the number of pages: 15
// Enter the page requests:
// 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2

