#include "simple.h"

int main(int ac, char **av, char **env)
{
    if (ac == 1)
        cmd(av, env);
    return (0);
}
