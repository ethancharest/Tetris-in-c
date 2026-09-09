#include "input.h"
#include <termios.h>
#include <unistd.h>

static struct termios original_termios;

void input_enable_raw_mode(void) {
    tcgetattr(STDIN_FILENO, &original_termios); // step 1: save current settings

    struct termios raw = original_termios; // step 2: copy settings
    raw.c_lflag &= ~(ECHO | ICANON); // disable echo and canonical mode
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); // step 3: apply new settings
}

void input_disable_raw_mode(void) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
}

int input_read_key(void) {
    char c;
    ssize_t nread = read(STDIN_FILENO, &c, 1);
    if (nread < 1) {
        return -1;  // nothing available, or an error
    }
    return c;
}