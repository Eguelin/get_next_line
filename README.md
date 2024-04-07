# GET_NEXT_LINE

<!-- ABOUT THE PROJECT -->
## About The Project

This project is about creating a function that returns a line ending with a newline, read from a file descriptor.
The aim of this project is to learn a highly interesting new concept in C programming:
static variables, better understand allocations and buffering.

### Mandatory part

The function must be prototyped as follows:
```c
char	*get_next_line(int fd);
```

the buffer BUFFER_SIZE must be able to be modified at compile time with the flag -D BUFFER_SIZE=xx.

### Bonus part

To succeed get_next_line with a single static variable.
To be able to manage multiple file descriptors with get_next_line without losing the reading thread on each of the descriptors.

This lib will be reusable for future projects.

### Built With

* C

<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

The gcc compiler must be installed. To install them, run the following commands:
* deb-based systems:
	```sh
	sudo apt install build-essential -y
	```
* or arch-based systems:
	```sh
	sudo pacman -S base-devel
	```

### Installation

* Clone the repo
	```sh
	git clone https://github.com/Eguelin/get_next_line.git
	```

### Compilation

1. Use the library in your project
	```c
	#include "get_next_line.h"
	```

2. Compile your project with the library
	```sh
	gcc -o my_project my_project.c srcs/get_next_line.c srcs/get_next_line_utils.c -I include -D BUFFER_SIZE=42
	```

3. Run your project
	```sh
	./my_project
	```

<!-- USAGE EXAMPLES -->
## Usage

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char *line;
	int fd = open("file.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

