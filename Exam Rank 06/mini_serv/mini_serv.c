#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>


int maxfd;
int ids[65000]
fd_set aset, rset, wset;

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void print(char *str) {
	write(2, str, strlen(str));
	write(2, "\n", 1);
	exit(1);
}

int main(int argc, char **argv) {
	(void)argv;
	if (argc != 2)
		print("Wrong number of arguments");

	int sockfd, connfd;
	socklen_t len;
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)  
		print("Fatal error");

	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		print("Fatal error");
	
	if (listen(sockfd, 10) != 0)
		print("Fatal error");

	len = sizeof(cli);
	maxfd = sockfd;
	FD_ZERO(&aset);
	FD_SET(sockfd, &aset);
   	int clientid = 0;	

	while (42) {
		rset = wset = aset;
		if (select(maxfd + 1, &rset, &wset, NULL, NULL) <= 0)
			continue;
		
		if (FD_ISSET(sockfd, &rset)) {
			connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
			if (connfd < 0)
				print("Fatal error");

			ids[connfd] = clientid++;
		}

	}
}
