//********** server *************

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
	int sfd,len,nsfd;
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
	c.sin_addr.s_addr=inet_addr("0.0.0.0");
	len=sizeof(c);
/***********  BIND   *********************/
	if(bind(sfd,(struct sockaddr *)&c,len)<0)
	{
	perror("bind");
	return 0;
	}
	perror("bind");
/************* LISTEN ************/

	listen(sfd,10);
	perror("listen");
/************ ACCEPT ************/

	nsfd=accept(sfd,(struct sockaddr *)&c,&len);
	if(nsfd<0)
	{
	perror("accept");
	return 0;
	}
	perror("accept");
	
	read(nsfd,s,sizeof(s));
	printf("data=%s\n",s);
}
