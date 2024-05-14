
# get_next_line 
This project implements the `get_next_line` function, which reads a line from a file descriptor. It is part of the 42 Network curriculum. 
## Table of Contents
- [Introduction](#introduction) 
- [Usage](#usage) 
- [Function Description](#function-description)
- [Building](#building) 
- [Resources](#resources) 
## Introduction 
The `get_next_line` function reads a line from a file descriptor (such as a file or standard input) and returns it without the newline character. It allows for reading multiple lines from a file or input stream one at a time.
## Usage 
To use the `get_next_line` function in your project, follow these steps: 
1. Clone the repository: `git clone https://github.com/rlabbiz/get_next_line.git`  
2. Include the `get_next_line.h` header file in your source code. 
3. Call the `get_next_line` function with the file descriptor you want to read from.
Example: 
```c 
#include "includes/get_next_line.h" 
#include <fcntl.h> 
int main() {
	int fd; 
	char *line; 
	fd = open("example.txt", O_RDONLY); 
	while ((line = get_next_line(fd)) != NULL) { 
		printf("%s\n", line); 
		free(line); // Remember to free the line allocated by get_next_line 
	}
	close(fd); 
	return 0; 
}
```
## Function Description

The `get_next_line` function has the following prototype:
```c
char  *get_next_line(int fd);
```
-   `fd`: The file descriptor to read from.

The function returns:

-   A pointer to a line read from the file without the newline character.
-   `NULL` if the end of file (EOF) has been reached or an error occurs.
## Building

To build the `get_next_line` function, you can compile it along with your other source files. Include the `get_next_line.c` and `get_next_line_utils.c` files in your build process.

Example using GCC:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 mandatory/get_next_line.c mandatory/get_next_line_utils.c your_program.c -o your_program	
```
Adjust `BUFFER_SIZE` as needed based on your requirements.
## Resources
- [https://www.geeksforgeeks.org/static-variables-in-c/](https://www.geeksforgeeks.org/static-variables-in-c/)
- [https://www.geeksforgeeks.org/basics-file-handling-c/](https://www.geeksforgeeks.org/basics-file-handling-c/)
