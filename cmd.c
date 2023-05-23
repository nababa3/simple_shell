#include "simple.h"

void cmd(char **av, char **env)
{
    char *cmd = NULL;
    int n, status;
    size_t s = 0;
    ssize_t num_char;
    char *argv[] = (NULL, NULL);
    pid_t pid;
    
    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("$");
        num_char = getline(&cmd, &s, stdin);
        if (num_char == -1)
        {
            free(cmd);
            exit(EXIT_FAILURE);
        }
        n = 0;
        while (cmd[n])
        {
            if (cmd[n] == '\n')
                cmd[n] = 0;
            n++;
        }
        argv[0] = cmd;
        pid = fork();
        if (pid == -1)
        {
            free(cmd);
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            if (execve(argv[0], argv, env) == -1)
                printf("%s: No such file or diretory\n", av[0]);
        }
        else
            wait(&status);
    }
}
