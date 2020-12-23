#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

char *add_terminate(char *in_buff) {
	char *temp = in_buff;
	int i = 0;
	while(*(in_buff + i) != '\n') {
		i++;
	}
	*(in_buff + i) = 0;
	return temp;
}

int main() {
	int fd = open("my_pipe", O_RDWR);

	char in_buff[100];
	char out_buff[100];

	while (1) {
		//Prompt user
		printf("Input data:\n");
		fgets(in_buff, sizeof(in_buff), stdin);
		add_terminate(in_buff);

		//Send data to server
		write(fd, in_buff, sizeof(in_buff));
		printf("Sent data: %s\n", in_buff);

		//Receive processed data from server
		read(fd, out_buff, sizeof(out_buff));
		printf("Received data: %s\n", out_buff);
	}
	return 0;
}