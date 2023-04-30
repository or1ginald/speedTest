#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define FILE_URL "http://212.183.159.230/20MB.zip" // Loaded file
#define FILE_SIZE 20000000 // File size in bytes

int main() {
    clock_t start_time, end_time;
    double total_time, speed;
    char command[100];
    printf("Testing internet speed...\n");

    // Start loading file
    sprintf(command, "curl -o /dev/null -s -w '%%{time_total}\\n' %s", FILE_URL);
    start_time = clock();
    system(command);
    end_time = clock();

     // Compute load time
    total_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("-------------- %f\n", total_time);

    // Compute internet speed in seconds
    speed = (double) FILE_SIZE / 1000000 / total_time ;

    // Show result
    printf("Download speed: %.2f Mbps\n", speed);

    return 0;
}
