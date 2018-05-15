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

int main(){
	int clientSocket, newSocket;
	char message[1024];
	struct sockaddr_in serverAddr , c;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5356);
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

	int hostName;
	char hostbuffer[1024];
	hostName = gethostname(hostbuffer, sizeof(hostbuffer));	

	int lenp = sizeof(serverAddr);
	int serverPort = ntohs(serverAddr.sin_port);
	char serPort[1024];
	sprintf(serPort,"%d",serverPort);
	getsockname(newSocket, (struct sockaddr *) &serverAddr, &lenp);

	
	int lenc = sizeof(c);
	char cip[1024];
	getpeername(newSocket, (struct sockaddr *) &c, &lenc);
	inet_ntop(AF_INET, &c.sin_addr, cip, sizeof(cip)); 

	struct ifreq ifr;
				
while(1){
	recv(newSocket, message, 50, 0);

	char s[]="Assalamualaikum";
	char q[]="quit";
	char h[]="hostname";
	char sp[]="port";
//IP ADDRESS
	char clientip[]="clientip";
	char serverip[]="serverip";
//MTU
	char mtu[]="mtu";	
	char get[]="get";
	char set[]="set";
	char vmtu[1024];
//TTL
	char ttl[]="ttl";
	char vttl[1024];

	if(strcasecmp(message , h)==0)
	{ strcpy(message , hostbuffer);}
	
	else if(strcasecmp(message , ttl)==0)
	{strcpy(message, "get or set?");
	 send(newSocket, message, 50, 0);
	 recv(newSocket, message, 50, 0);
	 
	 if(strcasecmp(message , get)==0)
	     {  int sock = socket(AF_INET, SOCK_RAW, 
IPPROTO_ICMP);
		unsigned int opt_val;
		unsigned int opt_len;
		getsockopt(sock, IPPROTO_IP, IP_TTL, &opt_val, 
&opt_len);
		printf("ttl %d\n", opt_val);
		printf("ttl %d\n", IPPROTO_IP);
		printf("ttl %d\n", sock);
		printf("ttl %d\n", IP_TTL);
		sprintf(vttl, "%d", opt_val);
		strcpy(message,vttl);  
	     }
	else if(strcasecmp(message , set)==0)
	     {  strcpy(message, "Enter a value");
		send(newSocket, message, 50, 0);
		recv(newSocket, message, 50, 0);
	
		int sock = socket(AF_INET, SOCK_RAW, 
IPPROTO_ICMP);
		int abcd = atoi(message);
		unsigned char ttl_val = abcd; 
		setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl_val, 
sizeof(ttl_val));
		strcpy(message , "TTL changed successfully"); 
	     }
		else;
		 

	}

	else if(strcasecmp(message,mtu)==0)
  	 {strcpy(message , "get or set?");
	  send(newSocket, message, 50, 0);
	  recv(newSocket, message, 50, 0);

	  if(strcasecmp(message , get)==0)
	     { strcpy(ifr.ifr_name, "wm0");
	       if(!ioctl(clientSocket, SIOCGIFMTU, &ifr))
			{ifr.ifr_mtu;}
	       sprintf(vmtu, "%d", ifr.ifr_mtu);
	       strcpy(message, vmtu); }

	  else if(strcasecmp(message , set)==0)
	     { strcpy(message , "Enter a value");
	       send(newSocket, message, 50, 0);
	       recv(newSocket, message, 50, 0);
	       	 
	       strcpy(ifr.ifr_name, "wm0");
	       if(!ioctl(clientSocket, SIOCGIFMTU, &ifr))
	       {ifr.ifr_mtu ;}
	       int abc = atoi(message);
	       ifr.ifr_mtu = abc;
	       if(!ioctl(clientSocket, SIOCSIFMTU, &ifr))
	       strcpy(message , "MTU changed successfully");}
     	       else;}

	else if(strcasecmp(message , serverip)==0)
	{ strcpy(message , inet_ntoa(serverAddr.sin_addr));}
	
	else if(strcasecmp(message , clientip)==0)
	{ strcpy(message , cip );}
	
	else if(strcasecmp(message , sp)==0)
	{ strcpy(message , serPort);}

	else if(strcasecmp(message , s)==0)
	{ strcpy(message,"Waalaikumussalam\n");}

	else if(strcasecmp(message , q)==0)
	{ break ; } 

	else
	{ strcpy (message , "Invalid Command");}

	send(newSocket, message, 50, 0);
  
  }
	close(clientSocket);
	return 0;
}
	


