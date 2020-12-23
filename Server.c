#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	mkfifo("my_pipe", 0600);
	int fd = open("my_pipe", O_RDWR);

	char in_buff[100];
	char out_buff[100];
	char postfix[100] = " is trash";

	while (1) {
		//Receive data from client
		read(fd, in_buff, sizeof(in_buff));
		printf("Received data: %s\n", in_buff);

		//Process data
		strncpy(out_buff, in_buff, sizeof(in_buff));
		strcat(out_buff, postfix);

		//Send processed data to client
		write(fd, out_buff, sizeof(out_buff));
		printf("Sent data: %s\n", out_buff);
	}
	return 0;
}