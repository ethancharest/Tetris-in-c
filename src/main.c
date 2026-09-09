#include "input.h"
#include <stdio.h>

int main(void) {
    input_enable_raw_mode();
    printf("Raw mode on. Type a character (won't echo, won't need Enter):\n");
    char c = getchar();
    printf("\nYou typed something (code %d)\n", c);
    input_disable_raw_mode();
    return 0;
}
