#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 50000 												

int main(void) {
    struct sockaddr_in si_me, si_other;  						
    int s;															
	int slen = sizeof(si_other);  									
    char buf[512];  												

    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {			
        printf("Socket creation failed.\n");					
        exit(1);												
    }

    memset(&si_me, 0, sizeof(si_me));  		
    si_me.sin_family = AF_INET;						
    si_me.sin_port = htons(PORT);	
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);		
     
    if (bind(s, (struct sockaddr*)&si_me, sizeof(si_me)) == -1) {		
        printf("Binding failed.\n");	
        exit(1);			
    }

    while(1) {														
    	memset(buf, 0, sizeof(buf));						    				
        if (recvfrom(s, buf, 512, 0, (struct sockaddr*)&si_other, &slen) == -1) {		
            printf("Binding failed.\n");								
        	exit(1);					
        }

        printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), inet_ntoa(si_other.sin_port));
        printf("Data: %s\n", buf);					
    }

    close(s);  
    return 0;
}
