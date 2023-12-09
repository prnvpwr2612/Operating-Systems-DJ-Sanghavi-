#include <stdio.h>
#include <math.h>

#define SIZE 8

// Function to perform FCFS Disk Scheduling
void FCFS(int request[], int head) {
    int seekCount = 0;
    int currentTrack, distance;

    // Process each track in the request array
    for (int i = 0; i < SIZE; i++) {
        currentTrack = request[i];

        // Calculate absolute distance
        distance = fabs(head - currentTrack);

        // Increase the total seek count
        seekCount += distance;

        // Update head to the current track
        head = currentTrack;
    }

    // Output the total number of seek operations
    printf("Total number of seek operations: %d\n", seekCount);

    // Output the seek sequence
    printf("Seek Sequence is:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", request[i]);
    }
}

// Driver code
int main() {
    // Request array containing track numbers
    int requestArray[SIZE] = {176, 79, 34, 60, 92, 11, 41, 114};

    // Initial head position
    int initialHead = 50;

    // Perform FCFS Disk Scheduling
    FCFS(requestArray, initialHead);

    return 0;
}

