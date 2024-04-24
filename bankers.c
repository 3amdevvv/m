#include<stdio.h>

int main() {
    int p, c, count = 0, i, j, alc[5][3], max[5][3], need[5][3], safe[5], available[3], done[5], terminate = 0;

    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &p, &c);

    printf("Enter allocation of resources for all processes (%dx%d matrix):\n", p, c);
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &alc[i][j]);
        }
    }

    printf("Enter the max resource process required (%dx%d matrix):\n", p, c);
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resource:\n");
    for (i = 0; i < c; i++) {
        scanf("%d", &available[i]);
    }

    printf("\nNeed resources matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            need[i][j] = max[i][j] - alc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    // Initialize done array
    for (i = 0; i < p; i++) {
        done[i] = 0;
    }

    while (count < p) {
        terminate = 0; // Reset terminate flag for each iteration

        for (i = 0; i < p; i++) {
            if (done[i] == 0) {
                for (j = 0; j < c; j++) {
                    if (need[i][j] > available[j]) {
                        break;
                    }
                }

                if (j == c) {
                    safe[count++] = i;
                    done[i] = 1;

                    // Release resources and add them to available resources
                    for (j = 0; j < c; j++) {
                        available[j] += alc[i][j];
                    }

                    break; // Break the inner loop to restart checking for safe sequences
                }
            }
        }

        if (i == p) { // If no process can be allocated, terminate the loop
            printf("Safe sequence does not exist.\n");
            break;
        }
    }

    if (count == p) {
        printf("\nAvailable resource after completion:\n");
        for (i = 0; i < c; i++) {
            printf("%d\t", available[i]);
        }

        printf("\nSafe sequence is:\n");
        for (i = 0; i < p; i++) {
            printf("P%d\t", safe[i] + 1);
        }
    }

    return 0;
}

// Enter the number of processes and resources: 5 3
// Enter allocation of resources for all processes (5x3 matrix):
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2
// Enter the max resource process required (5x3 matrix):
// 7 5 3
// 3 2 2
// 9 0 2
// 2 2 2
// 4 3 3
// Enter the available resource:
// 3 3 2
