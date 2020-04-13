# 0x16. C - Simple Shell
------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;
![](https://blog.holbertonschool.com/wp-content/uploads/2019/04/instagram_feed180.jpg)

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;
# Description

------------
In this project we are tasked with creating our own simple **UNIX** command interpreter. Our program must have the exact same output as **sh**  **(/bin/sh)** as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your **argv[0]**

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

# Compilation

------------

&bull; Our shell **compiles** as follows:

------------
    gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

# Testing

------------
&bull;  **Interactive** mode:

	$ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $

------------

&bull; **Non-interactive** mode:
   
    $ echo "/bin/ls" | ./hsh
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

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

# Tasks Done

------------

## README, man, AUTHORS

------------
&bull;  Write a **README**
&bull; Write a **man** for your shell.
&bull; You should have an **AUTHORS** file at the root of your repository, listing all    individuals having contributed content to the repository. Format, see [Dockers](http://https://github.com/moby/moby/blob/master/AUTHORS "Dockers").

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;


## Betty would be proud

------------

&bull; Write a beautiful code that passes the **Betty** checks

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;


## Simple shell 0.1

------------
&bull; Write a **UNIX** command line interpreter.

------------
&bull; Display a prompt and wait for the user to type a command. A command line always ends with a new line.

&bull; The prompt is displayed again each time a command has been executed.

&bull; The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.

&bull; The command lines are made only of one word. No arguments will be passed to programs.

&bull; If an executable cannot be found, print an error message and display the prompt again.

&bull; Handle errors.

&bull; You have to handle the end of file condition (**Ctrl+D**)

------------
&bull; You **don’t** have to:

------------
&bull; Use the **PATH**

&bull; Implement **built-ins**

&bull; Handle **special characters** 

&bull; Be able to **move the cursor**

&bull; Handle commands **with arguments**

------------

    julien@ubuntu:~/shell$ ./shell 
    #cisfun$ ls
    ./shell: No such file or directory
    #cisfun$ /bin/ls
    barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
    env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
    #cisfun$ /bin/ls -l
    ./shell: No such file or directory
    #cisfun$ ^[[D^[[D^[[D
    ./shell: No such file or directory
    #cisfun$ ^[[C^[[C^[[C^[[C
    ./shell: No such file or directory
    #cisfun$ exit
    ./shell: No such file or directory
    #cisfun$ ^C
    julien@ubuntu:~/shell$ echo "/bin/ls" | ./shell
    #cisfun$ barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c stat.c         wait
    env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
    #cisfun$ julien@ubuntu:~/shell$

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

## Simple shell 0.2 

------------
&bull; Handle command lines **with arguments**

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

## Simple shell 0.3

------------

&bull; Handle  the **PATH**

------------

    julien@ubuntu:~/shell$ ./shell_0.3
    :) /bin/ls
    barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
    env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
    :) ls
    barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
    env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
    :) ls -l /tmp 
    total 20
    -rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
    drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
    drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
    drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
    -rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
    :) ^C
    julien@ubuntu:~/shell$ 

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

## Simple shell 0.4

------------
&bull; Implement the **exit built-in**, that exits the shell

&bull; Usage: **exit**

&bull; You **don’t** have to handle any argument to the built-in exit

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

## Simple shell 1.0

------------
&bull;Implement the **env built-in**, that prints the current environment

------------

    julien@ubuntu:~/shell$ ./simple_shell
    $ env
    USER=julien
    LANGUAGE=en_US
    SESSION=ubuntu
    COMPIZ_CONFIG_PROFILE=ubuntu
    SHLVL=1
    HOME=/home/julien
    C_IS=Fun_:)
    DESKTOP_SESSION=ubuntu
    LOGNAME=julien
    TERM=xterm-256color
    PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
    DISPLAY=:0
    $ exit
    julien@ubuntu:~/shell$ 

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

## What happens when you type ls -l in the shell

------------

&bull; To see this article, click here : [ https://www.linkedin.com/pulse/what-happens-when-you-type-ls-l-shell-daniela-morales ]

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

## Files

------------

| **FILES**  | **DESCRIPTION**   |
| ------------ | ------------ |
| **holberton.h** | In this file we have all the **libraries** we need to be able to use certain functions or system calls, 			we also use **structures**, **macros** this is what our header contains |
|**.gitignore** | In this file we find all the junk files or that we simply do not need for our project, we consider it a 		    good practice to be able to evolve in the working world |
| **minishell.c** | In this file that is the main one compared to the other files we find, the getline that is in charge of                     taking and reading the characters of each line until it discovers a line break, there are also the 	                     different function calls that are in different files and they clearly play different roles |
| **built_n.c**  | In this file we have the different **built-in** that our shell handles such as: *help, which, cd and env* 			that makes our shell more dynamic and functional! |
|**funciones.c** | In this file, we find different functions such as: those that are responsible for freeing memory to 		           handle basic errors, we also divide the character strings typed by the user from our shell through the                      function **strtok()**, which divides by spaces and finally we also do the execution of the different 			   processes children bone the commands |
| **funciones2.c** | In this file we check the character string that will come to us from the user and concatenate, we also 			take the main environment variable called PATH, it contains the different addresses of the commands that 		     our user will use and we divide it by tokens, we also clearly look for the word PATH inside the list 		      of environment variables and all this happens at the moment we enter any command or program that 		            is in our shell and we also enter with the help of this variable |
| **FILES**  | **DESCRIPTION**  |
| ------------ | ------------ |
|funciones3.c| In this file is the function in charge of making the exit of our shell through the system call exit(), and this so that the user when entering the exit keyword in the shell exits automatically |
|funcionesaux.c| In this file we take care of releasing the structure that we use, we eliminate the spaces when the user types commands with arguments and between these there is space when the user to enter this output is not shown with those spaces that the digit, is also the function that is It is responsible for specifying what works specifically when entering a command that comes integrated with the shell, such as the built-in ones, we compare and duplicate the character strings. |


------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

## How do we get the shell out ...

------------
&bull; Creating our mini_shell **!**

This project has truly been one of the biggest challenges that we as a team have faced, our shell has several functionalities without counting on the most basic commands such as:

&bull; **ls =>** lists the files in the current directory

&bull; **pwd =>** show current working directory on screen

&bull; **cat =>** shows information about a file or directory

**&rarr;** Here is a **test** :

------------

![]( https://i.ibb.co/ZTQbKvm/Captura-de-pantalla-de-2020-04-13-12-09-07.png)

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

&bull; Now our shell also handles **commands with arguments**, for example if we want to show or list our files in a long way in a certain directory, let's say the directory where the temporary files are saved, bone **/tmp**, this in our mini_shell would **look like this:**

------------

![](https://i.ibb.co/9Hrstrg/Captura-de-pantalla-de-2020-04-13-11-47-56.png)

------------

&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

## Examples

------------
&bull; Handles "**ls**" command with or without arguments

------------
```c
$ ls
a.out  built_n.c  funciones2.c  funcionesaux.c  funciones.c  holberton.h  man_1_simple_shell  minishell.c  README.md
$ ls -la
-rwxrwxr-x  1 daniela daniela 18576 abr 11 18:15 a.out
-rw-rw-r--  1 daniela daniela   687 abr 11 02:49 built_n.c
-rw-rw-r--  1 daniela daniela  2369 abr 10 16:58 funciones2.c
-rw-rw-r--  1 daniela daniela  2605 abr 11 18:15 funcionesaux.c
-rw-rw-r--  1 daniela daniela  4017 abr 11 17:28 funciones.c
$ ls -lu                           /etc   
total 1304
drwxr-xr-x  3 root root     4096 mar 21  2017 acpi
-rw-r--r--  1 root root     3028 abr  9 02:29 adduser.conf
-rw-r--r--  1 root root       10 mar  8 18:27 adjtime
drwxr-xr-x  2 root root    12288 mar 21  2017 alternatives
-rw-r--r--  1 root root      401 abr 11 21:57 anacrontab
drwxr-xr-x  3 root root     4096 mar 21  2017 apache2
-rw-r--r--  1 root root      112 ene 10  2014 apg.conf
drwxr-xr-x  6 root root     4096 mar 21  2017 apm
drwxr-xr-x  3 root root     4096 mar 21  2017 apparmor
drwxr-xr-x  8 root root     4096 abr 11 16:51 apparmor.d
drwxr-xr-x  5 root root     4096 mar 21  2017 apport
-rw-r--r--  1 root root      389 abr 11 16:56 appstream.conf
drwxr-xr-x  7 root root     4096 mar  8 18:32 apt
drwxr-xr-x  3 root root     4096 mar 21  2017 aptdaemon
drwxr-xr-x  2 root root     4096 mar 21  2017 at-spi2
drwxr-xr-x  3 root root     4096 mar 21  2017 avahi

```

------------

&bull; Handles "**which**" command 

------------
```c
$ which ls
/bin/ls
$ which cat
/bin/cat
$which pwd
/bin/pwd
$
```
------------

**&rarr;** Here is a **test** :

------------

![](https://i.ibb.co/QDCn3R2/Captura-de-pantalla-de-2020-04-13-12-23-11.png)

------------
&bull; Handles "**pwd**" command

------------

```c
$ pwd
/home/daniela/simple-shell

```
------------

&bull; Our Shell also works **non-interactively**

------------

```c
➜  simple-shell git:(daniela) echo ls | ./a.out
built_n.c  funciones2.c  funcionesaux.c  funciones.c  holberton.h  man_1_simple_shell  minishell.c  README.md
➜  simple-shell git:(daniela) echo ls -la | ./a.out
-rwxrwxr-x 1 daniela daniela 18576 abr 11 18:15 ./a.out
➜  simple-shell git:(daniela) echo "/bin/ls" | ./a.out
built_n.c  funciones2.c  funcionesaux.c  funciones.c  holberton.h  man_1_simple_shell  minishell.c  README.md
➜  simple-shell git:(daniela)

```
------------
**&rarr;** Here is a **test** :

------------
![](https://i.ibb.co/gwGv5JS/Captura-de-pantalla-de-2020-04-13-12-53-24.png)

------------

&bull; Handle "**env**" command

------------
```c
$ env
LESSOPEN=| /usr/bin/lesspipe %s
GNOME_KEYRING_PID=
USER=daniela
UNITY_HAS_3D_SUPPORT=true
UNITY_DEFAULT_PROFILE=unity
LANGUAGE=es_CO:es
UPSTART_INSTANCE=
XDG_SEAT=seat0
SESSION=ubuntu
XDG_SESSION_TYPE=x11
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=10
HOME=/home/daniela
LESS=-R
QT4_IM_MODULE=xim
OLDPWD=/home/daniela
DESKTOP_SESSION=ubuntu
ZSH=/home/daniela/.oh-my-zsh
LSCOLORS=Gxfxcxdxbxegedabagacad
QT_LINUX_ACCESSIBILITY_ALWAYS_ON=1
GTK_MODULES=gail:atk-bridge:unity-gtk-module
XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
PAGER=less
INSTANCE=
DBUS_SESSION_BUS_ADDRESS=unix:abstract=/tmp/dbus-3ISfJ8kftR
GNOME_KEYRING_CONTROL=
QT_QPA_PLATFORMTHEME=appmenu-qt5
MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path
IM_CONFIG_PHASE=1
SESSIONTYPE=gnome-session
UPSTART_JOB=unity7
LOGNAME=daniela
GTK_IM_MODULE=ibus
WINDOWID=71303178
_=/bin/sh
DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path
XDG_SESSION_ID=c2
TERM=xterm-256color
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
GTK2_MODULES=overlay-scrollbar
PATH=/home/daniela/bin:/home/daniela/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
$ 

```
------------
**&rarr;** Here is a **test** :
 
------------

![](https://i.ibb.co/5v6LjNR/Captura-de-pantalla-de-2020-04-13-12-25-37.png)

------------
&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

## Note

------------
&bull; And the most **fun is that from our own shell we can see what processes are running**, know what their respective child processes are and clearly their parent process and if they behave **linearly or exponentially!** ...

&bull; With the command (**ps -fe**).

------------
![](https://i.ibb.co/WvR9sMh/Captura-de-pantalla-de-2020-04-13-12-30-16.png)

------------

&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;&mdash;

# AUTHORS
------------
**Daniela Morales**  | 1524@holbertonschool.com  

**Jefferson Leon**   | 1527@holbertonschool.com 

------------
