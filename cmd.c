#include "simple.h"
void prompt(char **av, char **env)
{
char *cmd = NULL;
int n, status;
size_t s = 0;
ssize_t num_char;
char argv[] = (NULL, NULL);
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
            if (cmd[n] == '&s')
                cmd[n] = 0;
            i++;
        }
        argv[0] = cmd;
        pid = fork();
        // pid = getpid();
        if (pid == -1)
        {
            free(cmd);
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            if (execve(argv[0], argv, env) == -1)
                ;
            printf("%s: No such file or diretory", av[0]);
        }
        else
            wait(&status);
    }
}
