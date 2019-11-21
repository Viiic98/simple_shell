## SIMPLE SHELL PROJECT

Simple Shell is a project to understand the behavior of the Real Shell starting with the input data of the user and the error handles until the creation of functions like env and the calling of built-ins like pwd with the PATH and the command execve.

This project was built by Victor Arteaga and Orlando Gomez.

# Table of Contents
	1. [Authors](#Authors)
	2. [Features](#Features)
	3. [How to use](#Usage)
	4. [How to compile](#Compilation)
	5. [Requirements](#Requirements)
	6. [Commands](#Commands)

# Authors
	**Victor Arteaga**

	- Github: [@Viiic98](https://github.com/Viiic98)

	**Orlando Gomez**

	- Github: [@oran2527](https://github.com/oran2527)

# Features
	- The main function takes the input of the user and analyze every argument to determine which function to execute with its respective flags and arguments.
	- The input data of the user will be analyzed with the "|" character (pipe) to separate every single command.
	- The Simple Shell calls intern functions like "pwd" and other extern functions like "env".


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

- The command **ls lists all the files and directories in the path that the user selects in the entry data.

## Flags

- **l : Display long format information about Unix file type, permissions, number of hard links, owner, group, size, 

## Command cd 

- The command **cd allows to change from the actual directory to other one.

## Command cp

- The command **cp allows to copy files and gives them a name or rewrite an existing file. 

## Command pwd

- The command **pwd allows to display the path of the current directory.

## Command echo

- The command **echo allows to display the argument that the user types after the first argument.

## Command env

- The command **env allows to display all the environment variables of the system.

## Command rm

- The command **rm allows to delete all the files or directories that the user is available.

## Command exit

- The command **exit allows to finish the execution of the Simple Shell.




