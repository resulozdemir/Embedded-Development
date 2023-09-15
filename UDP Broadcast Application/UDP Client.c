#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER "192.168.153.255"			
#define PORT 50000 													

int main(void) {
    struct sockaddr_in si_other;									
    int s; 															
	int slen = sizeof(si_other);									
    char buf[512];													
    char message[512];												

    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {		
        printf("Could not create socket.\n");							
		exit(1);													
    }

    int broadcast = 1;		
    if (setsockopt(s, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast) == -1) {	
        printf("Broadcast permission could not be set.\n");										
    	close(s);							
    	exit(1);						
    }													

    memset(&si_other, 0, sizeof(si_other));		
    si_other.sin_family = AF_INET;    			
    si_other.sin_port = htons(PORT);   		
     
    if (inet_aton(SERVER, &si_other.sin_addr) == 0) {			
    	printf("Could not convert IP address.\n");					
    	close(s);													
    	exit(1);
	}

    while(1) {
    	memset(buf, 0, sizeof(buf));						        
        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);
        
        char *newline = strchr(message, '\n'); 	
		if (newline) 
    		*newline = '\0'; 
         
        if (sendto(s, message, strlen(message), 0, (struct sockaddr*)&si_other,slen) == -1) {	
            printf("Message could not be sent.\n");		
			exit(1);												 
        }		
    }

    close(s);
    return 0;
}
