# 42Pipex

A 42 school project of a program designed to execute two unix commands with input and output redirections as follows:

`./pipex infile "ls -l" "wc -l" outfile`

Behaves like: `< infile ls -l | wc -l > outfile`

Single word commands without arguments or options will not need to be enclosed in quotes.

## How to run
_This project has been developed in macOS._

`git clone` and `cd` to desired directory. Run `git submodule init` and `git submodule update` in the same directory and then `make`. Use as demonstrated above.
