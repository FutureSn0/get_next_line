
# get_next_line

get_next_line is a project where we must create a function that will allow us to read a single line from a text file. Repeated calls to the fuction will allow us to read a whole text file. A default buffer size is defined in the header file as 42. However, the buffer size can be altered upon compilation. The bonus variant will allow you to read from multiple files at the same time.

# How to use

1. Clone the repository, then enter the cloned directory

```bash
git clone git@github.com:FutureSn0/get_next_line.git
cd get_next_line
```

2. Compile with source files including the main as follows. To compile the bonus version, use get_next_line_bonus and get_next_line_utills_bonus instead.

```bash
<flags> = -Wextra -Wall -Werror
<buffer size> = -D BUFFER_SIZE=<size>
<source.c files> = get_next_line get_next_line_utills 

cc -Wextra -Wall -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utills.c
```
*NOTE* an example main is included in the get_next_line.c and get_next_line_bonus.c file. you can use this template or remove it and use without or your own.

3. Now run the output program with a given text file. The bonus version will allow you to add more files to read

```bash
./a.out <text file>
./a.out test.txt test2.txt
```

# Subject
### Mandatory
- Read from one file descriptor, one line at a time.
- Needs to return the line that was read. If empty or error, return `NULL`.
- Should work as expected reading from a file or standard input.
- Returned line should include the terminating `\n` character, except if it's the end of the file and the line does not end with `\n`.
- The `get_next_line.h` header file should include at least the `get_next_line()` function.
- All adicional functions should be included in `get_next_line_utils.c` file, libft is not allowed.
- To define the buffer size for `read()`, add the option to the compiled file `-D BUFFER_SIZE=[SIZE]`.

All functions must be fully functioning and well-tested to obtain passing score (100/100). 

### Bonus
- Use only one static variable.
- Manage multiple file descriptors at the same time.
- Bonus files should include a suffix `_bonus.[c/h]`. All functions must be fully functioning and well-tested to obtain an additional 25 points to the passing grade (125/100).

# Norminette

All projects are written according to a standard implemented by the 42 school known as "Norminette". This standard specifies our files to be formatted in a specific way, limits the amount of functions and varables included in a single file, and also the use of certain statements (for, do.. while, switch.. case, etc).
