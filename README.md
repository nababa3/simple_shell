<h1>0x16. C - Simple Shell</h1>
<p>A shell is a command line intepreter CLI that takes commands from the keyboard and gives them to the operating system to perform e.g cd, pwd, ls etc</p>
<p>This project is for ALX group project was created by Nababa Abdurahmon and Illhan Mohemmad</p>


<h3>Compilation</h3>

Use `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell`

<h3>Testing</h3>
<p>interactive mode:</p>
$ ./simple_shell
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

<p>non-interactive mode:</p>
$ echo "/bin/ls" | ./simple_shell
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

<h3>FEATURES</h3>
<ul>
    <li>Display a prompt and wait for the user to type a command. A command line always ends with a new line.</li>
    <li>If an executable cannot be found, print an error message and display the prompt again.</li>
    <li>Handle errors.</li>
    <li>Hndling the “end of file” condition (Ctrl+D)</li>
    <li>Hanling the command line with arguments</li>
    <li>Support the exit features and the exit status</li>
    <li>Handle the Ctrl-C to not terminate the shell</li>
</ul>
