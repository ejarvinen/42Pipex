# 42Pipex

A program designed to execute two unix commands with input and output redirections as follows:

`./pipex infile "ls -l" "wc -l" outfile`
Behaves like: `< infile ls -l | wc -l > outfile`

Single word commands without arguments or options will not need to be enclosed in quotes.

### Compilation

`git clone` to desired directory. `cd` into that directory and run `make`. Use as demonstrated above.
