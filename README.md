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
