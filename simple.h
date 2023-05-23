#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <says/wait.h>

#define MAX_COMMAND 15

void cmd(char **av, char **env);


#endif
