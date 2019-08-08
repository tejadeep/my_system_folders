//*************** client *************
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<unistd.h>
#include<arpa/inet.h>
int main()
{
	char s[20];
	int sfd,len,r;
	struct sockaddr_in c;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{
	perror("socket");
	return 0;
	}
	perror("socket");
	printf("sfd=%d\n",sfd);
	c.sin_family=AF_INET;
	c.sin_port=htons(3000);
	c.sin_addr.s_addr=inet_addr("192.168.4.131");
	len=sizeof(c);
/********* CONNECT   *********************/
	r=connect(sfd,(struct sockaddr *)&c,len);
	if(r<0)
	{
	perror("connect");
	return 0;
	}
	perror("connect");

	printf("enter the data.......\n");
	scanf("%s",s);
	write(sfd,s,strlen(s)+1);
}
