#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define FILE_URL "https://speed.hetzner.de/1MB.bin" // Loaded file
#define FILE_SIZE 1000000 // File size in bytes
#define LOAD_TIME 20

int main() {
    clock_t start_time, end_time;
    double total_time, speed;
    char command[100];
    printf("Testing internet speed...\n");

    sleep(LOAD_TIME);

    // Start loading file
    sprintf(command, "curl -o /dev/null -s -w '%%{time_total}\\n' --max-time %d %s", LOAD_TIME, FILE_URL);
    start_time = clock();
    system(command);
    end_time = clock();

     // Compute load time
    total_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Compute internet speed
    speed = (double) FILE_SIZE / total_time / 1000000;

    // Show result
    printf("Download speed: %.2f Mbps\n", speed);

    return 0;
}
