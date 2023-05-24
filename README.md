# pipex
A program that will mimic '< infile cmd1 | cmd2 > outfile' in bash.

usage: ./pipex infile "cmd1" "cmd2" outfile

Designed for a project assigned by 42 School.

Will make on an M1 Mac if Rosetta 2 is installed. Compilation is handled under x86_64, if only for simplicity when switching architectures
between school and home.

The basics of the program:

command line arguments are parsed using ft_strdup() and ft_split()

outfile is deleted before program is run(in the case that it exists)

file descriptor for infile and outfile are assigned,

two file descriptors are assigned with the pipe function,

then the fork function is used to create a simultaneous work flow with a parent and child process,

child process uses dup2() to replace the std input with infile fd, and again to replace std output with the pipe output,

execvp() is used to run the first command from the program,

parent process uses dup2() to replace the std output with the outfile fd, and again to replace std input with the pipe input,

execvp() is used to run the second command from the program.

Thanks for looking!
