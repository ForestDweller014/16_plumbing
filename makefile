all: client server

client: Client.c
	gcc -o client Client.c

server: Server.c
	gcc -o server Server.c