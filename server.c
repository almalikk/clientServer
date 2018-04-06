#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
	int clientSocket, newSocket;
	char message[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(6708);
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
	
	recv(newSocket, message, 50, 0);
	char s[]="Assalamualaikum";
	char a[50];
	strcpy(a,message);
	if(strcasecmp(a , s)==0)
	{ strcpy(message,"Waalaikumussalam\n");}
	else
	{ strcpy (message,"Are ypu muslim?\n");}
	send(newSocket, message, 50, 0);
	
	return 0;
}
	
# clientServer
# clientServer
# clientServer
# clientServer
# clientServer
# clientServer
# clientServer
# clientServer_server
# clientServer_client
# clientServer
