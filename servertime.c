#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <time.h>

int main(){
	int clientSocket, newSocket;
	char message[1024];
	struct sockaddr_in serverAddr , c;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7777);
	serverAddr.sin_addr.s_addr = inet_addr("192.168.184.137");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
	
	bind(clientSocket, (struct sockaddr *) &serverAddr, 
sizeof(serverAddr));

	if(listen(clientSocket,5)==0)
		printf("Listening\n");
	else
		printf("Error\n");

	addr_size = sizeof serverStorage;
	newSocket = accept(clientSocket, (struct sockaddr *) 
&serverStorage, &addr_size);

	puts("Connection Established");

	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime ( &rawtime );
	printf("current server date time:%s", asctime (timeinfo) ) ; 
	
	char date[1024];
	strcpy(date , asctime(timeinfo));
	char date2[] = "Current date and time is: ";
	strcat(date2 , date);
	
	
	strcpy(message , date2);		
	send(newSocket, message, 50, 0);

	
	close(clientSocket);
	return 0;

}
	


