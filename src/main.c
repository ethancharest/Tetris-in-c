#include "input.h"
#include <stdio.h>
#include <unistd.h>

int main(void) {
    input_enable_raw_mode();
    printf("Press keys (q to quit). No key needed to keep looping.\n");

    while (1) {
        int key = input_read_key();
        if (key != -1) {
            printf("Got key: %d\n", key);
            if (key == 'q') break;
        }
        usleep(200000); // sleep 200ms so it doesn't spam your terminal
    }

    input_disable_raw_mode();
    return 0;
}
