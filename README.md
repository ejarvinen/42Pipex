# 42Pipex
## Description
**Pipex** is a project that explores the inner workings of UNIX pipes by replicating the behavior of shell piping. The program takes in file inputs and commands and executes them through pipes, mimicking the shell's command execution process.

## Features
- Simulates the shell pipeline behavior: `< file1 cmd1 | cmd2 > file2`.
- Handles file input and output redirections.
- Supports execution of external commands.
- Proper error handling and memory management.

## Installation
1. Clone the repository:
```
git clone https://github.com/ejarvinen/42Pipex.git
cd 42Pipex
```
2. Update and initialize submodules:
```
git submodule init
git submodule update
```
3. Build the project using the Makefile:
```
make
```
## Usage
Run the program with the following syntax:
```
./pipex file1 "cmd1" "cmd2" file2
```
This will behave like:
```
< file1 cmd1 | cmd2 > file2
```
### Examples
```
./pipex infile "ls -l" "wc -l" outfile
```
Equivalent to:
```
< infile ls -l | wc -l > outfile
```
