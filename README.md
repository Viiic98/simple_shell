## SIMPLE SHELL PROJECT

Simple Shell is a project to understand the behavior of the Real Shell starting with the input data of the user and the error handles until the creation of functions like env and the calling of built-ins like pwd with the PATH and the command execve.

This project was built by Victor Arteaga and Orlando Gomez.

# Table of Contents
	1. Authors
	2. Features
	3. Usage
	4. Compilation
	5. Requirements
	6. Commands

# Authors
	Victor Arteaga

	- Github: [@Viiic98](https://github.com/Viiic98)

	Orlando Gomez

	- Github: [@oran2527](https://github.com/oran2527)

# Features
	- The main function takes the input of the user and analyze every argument to determine which function to execute with its respective flags and arguments.
	- The input data of the user will be analyzed with the "|" character (pipe) to separate every single command.
	- The Simple Shell calls intern functions like "pwd" and other extern functions like "env".
	- The command execve takes the function and arguments and gives the respective output. 


# How to use
	
	- The user has to enter the commands and the flags or arguments that it needslike "cp file1 filename2".

## How to compile

	- The user has to compile the program with gcc -Wall -Werror -Wextra -pedantic *.c -o hsh.
	
	- The user has to enter ./hsh.

	- The user has to enter the commands with the flags and arguments.

### Requirements

	- compile on Ubuntu 14.04 LTS.
	- compile with gcc 4.8.4.

##
	
# Commands 

## Command ls

- The command ls lists all the files and directories in the path that the user selects in the entry data.

### Some Flags

- l : Display long format like Unix file type, permissions, number of hard links, owner, group, size, last-modified date and filename.

- a : Display all files even hidden or files starting with ".".

- t : Sort the list by modification time

- 1 : Display all the files and directories line by line

### Examples

- ls -lat

- ls -1

## Command cd 

- The command cd allows to change from the actual directory to other one. If you put only the command, it redirects to the home directory.

### Some Flags

- ~ : Display the files and directories of the home directory.

- . : Display the files and directories of the current directory.

- .. : Display the files and directories of the parent directory.

- - : Display the files and directories of the path of the variable OLDPWD or previous directory.

### Examples

- cd ~

- cd folder_current_directory

- cd -

## Command cp

- The command cp allows to copy files to a path and gives them a name or rewrite an existing file. 

### Some Flags

- R or r : copy directories recursively.

- p : copy the file and preserve metadata like time of last data modification and time of the last access.

### Examples

- cp file1 file2 ../parentdirectory

- cp file1 file2

## Command pwd

- The command pwd allows to display the path of the current directory.

### Example 

- pwd

## Command echo

- The command echo allows to display the argument that the user types after the first argument.

### Example

- echo "Hola"

## Command env

- The command env allows to display all the environment variables of the system.


### Example

- env

## Command rm

- The command rm allows to delete all the files or directories that the user is available.

### Some Flags 

- r : Remove directories and its contents

- i : Ask for every deletion

- f : Force every deletion without asking

### Examples

- rm -rf directory_with_files

- rm file1

- rm file1 file2 file3

## Command exit

- The command exit allows to finish the execution of the Simple Shell.

### Example

- exit

## Shell Modes

### INTERACTIVE MODE

- The interactive mode is the way that the shell receives the commands in first plain. First, you have to run the compilated file and then type the comma
    nd line.

### NON-INTERACTIVE MODE

- The non-interactive mode is the way that the shell receives the commands in second plain. Directly, you have to type the command that you want to execu
    te, the character pipe "|" and then the name of the compilated file of the simple shell.

### STEPS OF THE PROGRAM

The steps in the process when you type a command are:


1. Decide to type a command in interactive or non-interactive mode.

2. If you decide an interactive mode, you must run the compilated file with the statement "./compilatedfilename"

3. If you decide an non-interactive mode, you must run the compilated file with your command.

Example : echo "/bin/ls" | ./hsh

4. The Simple Shell evaluates the access mode (interactive or non-interactive) with the command isatty, which returns the value 1 if you use the interactive mode and other value if you use the non-interactive mode.


5. If you use interactive mode, the Simple Shell prints the prompt "#cisfun$ ".

6. If you use non-interactive mode, the Simple Shell doesnt print the prompt "#cisfun$ ".

7. The Simple Shell reads the commands with the command getline in a buffer as a single line.

8. The Simple Shell counts all the characters of the line of the command getline what aren´t space, tab or new line.

9. If the buffer has the string "exit" with new line ("exit\n"), the Simple Shell frees buffer memory and exit(0);

10. If the buffer in the first position is different to '\n' or new line, the Simple Shell pass the environment variables, the buffer and the number of the counter of command lines for the shell (in other words, every command is accounted), to the function pipes, which will have a return value called status that is displayed with the command "echo $?".

11. The function pipes separates in tokens all the buffer every time the character in the buffer was '|' or '\n'. A token is all the characters between the delimitators. For this action, the Simple Shell must allocate memory with a size of 1024. The return of this function is a pointer of strings.

12. The pointer of strings is passed to the function ourcommands with the environment variables and the counter of the command line.

13. The function ourcommands separates in parts all the pointer of strings when the character was ' \ ', ' " ', ' ' ', '\t' or '\n' in a new pointer of strings as also a simple pointer to the first argument that will be the command.The Simple Shell allocates memory for that purpose with the functions alloc1 and alloc2.

14. The Simple evaluates the simple pointer (the command) and compares if the the command is "env", "cd" or if it´s other different command than "env" or "cd". For every case, the Simple Shell redirects to every specif function.

15. If the pointer is "env", the Simple Shell uses the function _env to print all the environment variables in the screen.

16. If the pointer is "cd", the Simple Shell uses the function _cd. This function changes to the directory that the user defines and sets the environment variables OLDPWD and PWD. The variable OLDPWD is the last directory where the user was and PWD is the current directory where the user is. If the command "cd" has a second argument, it must be evaluated too. If the second argument is "..", the Simple Shell must change to the parent directory; if the second argument is "-", the Simple Shell must change to the previous directory that the user was; if the second argument is a path to a directory, the Simple Shell must change to this path if it´s a directory; if there is not a second argument, the Simple Shell must change directory to "home" directory and in this case must take the environment variable "HOME" and uses this path. If the command is different to "cd" or "env", the Simple Shell uses the function "path".

17. The function path gets the command, the tokens and the environment variables. First, the Simple Shell analyzes tif the path is of type directory and it´s, the Simple Shell returns the value 126. To do that, the Simple Shell uses the function stat that returns information about a file. If the command is really a command, the Simple Shell creates a child process and executes this command while the command exist. To prove this, the Simple Shell must take the variable PATH, and separate every intern path, concatenates the command and finds if this file exist in all the paths. If the command is really a path, for example, /bin/ls, the Simple Shell must prove that path exist and create a child process and executes this binary file.

18. When the child process ends, it returns to the parent process which it´s waiting for the value return of the child process. For this process, the Simple Shell uses the command "fork" to create a child process and "wait" to define the point of return of the child process.

