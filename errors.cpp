#include "headers.h"

// reusable error function, just pass in message
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

