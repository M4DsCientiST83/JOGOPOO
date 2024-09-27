#ifndef CAPTURE_KEY_HPP
#define CAPTURE_KEY_HPP

#include <unistd.h>
#include <termios.h>
#include <stdio.h>

void set_terminal_mode(bool enableRaw);

char captureKey();

#endif