#include"pizzanet.h"
# define flag puts("pizza");


//some issue in calling order of functions , call google_visit and then call google_desc in that order. Must be some buffer issue;


void handle()
{
printf("improper memory reference , check news article and start again \n");
exit(0);
}

char** google_visit(char * site,short int num)
{
	char **data;
        data = (char **)malloc(num * sizeof(char **));
        for(int i=0;i<num;data[i]=(char *)malloc(200),i++);	
	short int count=0;
	struct sockaddr_in servaddr;
	struct hostent *hp;
	int sock_id;
/*	char request[] = "GET /search?gs_ivs=1&q=avengers HTTP/1.1\r\n"
"Host: www.google.com \r\n"
"User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:65.0) Gecko/20100101 Firefox/65.0 \r\n"
"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,;q=0.8 \r\n"
"Accept-Language: en-US,en;q=0.5 \r\n" 
"Accept-Encoding: gzip, deflate, br \r\n"
"Connection: keep-alive \r\n"
		"\r\n";  */

  char request[300] = "GET /search?gs_ivs=1&q=";
  char request1[]=	" HTTP/1.1\r\n"
                "Host: www.google.com \r\n"
                "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:61.0) Gecko/20100101 Firefox/61.0 \r\n"
                "\r\n";
  char re[40];
  short int ln=0;
  short int rgl=0;
  while(ln<strlen(site))
  {
  if(site[rgl]==' ')
  {
   re[ln++]='+';
   rgl+=3;
  }
  else
  re[ln++]=site[rgl++];
  }
  re[ln]='\0';
  strcpy(request+strlen(request),re);
  strcpy(request +strlen(request),request1);
// puts(request);

            // sleep(5);  
       //  request[35]=argv[1][0];
//	 request[36]=argv[1][1];
         

          sock_id = socket(AF_INET,SOCK_STREAM,0);
	
	memset(&servaddr,0,sizeof(servaddr));
	
	
	hp = gethostbyname("www.google.com");
		
	memcpy((char *)&servaddr.sin_addr.s_addr, (char *)hp->h_addr, hp->h_length);
//	printf("%s",inet_ntoa(servaddr.sin_addr));   to print ip adress use to check bugs in gethostbyname


	
	servaddr.sin_port = htons(443);
	servaddr.sin_family = AF_INET;



SSL_load_error_strings ();
SSL_library_init ();

SSL_CTX *ssl = SSL_CTX_new (SSLv23_client_method ());


SSL *sslcon = SSL_new(ssl);
SSL_set_fd(sslcon, sock_id);
	
	
	connect(sock_id, (struct sockaddr *)&servaddr, sizeof(servaddr));
	
	
SSL_connect(sslcon);
	
SSL_write(sslcon,request,sizeof(request));
int val=0;
	int stat = 0;
	char buf;
        short int cn=0,cm=0;
	int f=0;
//	char *str="data-currency-value";
	while(1)
	{
	SSL_read(sslcon,&buf,1);
//	putchar(buf);
	if(buf=='h' && SSL_read(sslcon,&buf,1) && buf=='r' && SSL_read(sslcon,&buf,1) && buf=='e' && SSL_read(sslcon,&buf,1) && buf=='f'&& SSL_read(sslcon,&buf,1) && buf=='=' && SSL_read(sslcon,&buf,1) && buf=='"' && SSL_read(sslcon,&buf,1) && buf=='h')	{	
data[cn][cm++]='h';
while(SSL_read(sslcon,&buf,1)&&buf!='"')
{
data[cn][cm++]=buf;
//putchar(buf);
}
//printf("%d %d",cn,cm);
data[cn][cm++]='/';
data[cn][cm++]='\0';
//puts(data[cn]);
cm=0;
cn++;
count++;
if(count==num)
break;
	}
	else if(buf=='<' &&   SSL_read(sslcon,&buf,1) && buf=='/' && SSL_read(sslcon,&buf,1) && buf=='h' &&   SSL_read(sslcon,&buf,1) && buf=='t' &&  SSL_read(sslcon,&buf,1) && buf=='m' &&  SSL_read(sslcon,&buf,1) && buf=='l'  && SSL_read(sslcon,&buf,1) && buf=='>')
	break;
	}
//sleep(1) is mandatory since you dont want to spook google lol and also requests dont go through well
//sleep(1);
return data;
}
void google_desc(char *site)
{
	struct sockaddr_in servaddr;
	struct hostent *hp;
	int sock_id;
/*	char request[] = "GET /search?gs_ivs=1&q=avengers HTTP/1.1\r\n"
"Host: www.google.com \r\n"
"User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:65.0) Gecko/20100101 Firefox/65.0 \r\n"
"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,;q=0.8 \r\n"
"Accept-Language: en-US,en;q=0.5 \r\n"
"Accept-Encoding: gzip, deflate, br \r\n"
"Connection: keep-alive \r\n"
		"\r\n";  */

  char request[300] = "GET /search?gs_ivs=1&q=";
  char request1[]=	" HTTP/1.1\r\n"
                "Host: www.google.com \r\n"
                "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:61.0) Gecko/20100101 Firefox/61.0 \r\n"
                "\r\n";
  char re[40];
  short int ln=0;
  short int rgl=0;
  while(ln<strlen(site))
  {
  if(site[rgl]==' ')
  {
   re[ln++]='+';
   rgl+=3;
  }
  else
  re[ln++]=site[rgl++];
  }
  re[ln]='\0';
  strcpy(request+strlen(request),re);
  strcpy(request +strlen(request),request1);
// puts(request);

            // sleep(5);
       //  request[35]=argv[1][0];
//	 request[36]=argv[1][1];


          sock_id = socket(AF_INET,SOCK_STREAM,0);

	memset(&servaddr,0,sizeof(servaddr));


	hp = gethostbyname("www.google.com");

	memcpy((char *)&servaddr.sin_addr.s_addr, (char *)hp->h_addr, hp->h_length);
	printf("%s",inet_ntoa(servaddr.sin_addr));



	servaddr.sin_port = htons(443);
	servaddr.sin_family = AF_INET;



SSL_load_error_strings ();
SSL_library_init ();

SSL_CTX *ssl = SSL_CTX_new (SSLv23_client_method ());


SSL *sslcon = SSL_new(ssl);
SSL_set_fd(sslcon, sock_id);


	connect(sock_id, (struct sockaddr *)&servaddr, sizeof(servaddr));


SSL_connect(sslcon);

SSL_write(sslcon,request,sizeof(request));
int val=0;
	int stat = 0;
	char buf;
	int count =0;
	int f=0;
	char *str="data-currency-value";
	while(1)
	{
	short int count=100;
	SSL_read(sslcon,&buf,1);
//	putchar(buf);
	if(buf=='D' && SSL_read(sslcon,&buf,1) && buf=='e' && SSL_read(sslcon,&buf,1) && buf=='s' && SSL_read(sslcon,&buf,1) && buf=='c' && SSL_read(sslcon,&buf,1) && buf=='r' && SSL_read(sslcon,&buf,1) && buf=='i' && SSL_read(sslcon,&buf,1) && buf=='p'  && SSL_read(sslcon,&buf,1) && buf=='t'  && SSL_read(sslcon,&buf,1) && buf=='i'  && SSL_read(sslcon,&buf,1) && buf=='o'  && SSL_read(sslcon,&buf,1) && buf=='n'  ){
	for(int i=0;i<=10;SSL_read(sslcon,&buf,1),i++);
	while(SSL_read(sslcon,&buf,1),(buf!='<' && putchar(buf)));
	break;
	}
	else if(buf=='<' &&   SSL_read(sslcon,&buf,1) && buf=='/' && SSL_read(sslcon,&buf,1) && buf=='h' &&   SSL_read(sslcon,&buf,1) && buf=='t' &&  SSL_read(sslcon,&buf,1) && buf=='m' &&  SSL_read(sslcon,&buf,1) && buf=='l'  && SSL_read(sslcon,&buf,1) && buf=='>')
	break;
	}

	
//sleep(1) is mandatory since you dont want to spook google lol and also requests dont go through well
//sleep(1);
printf("\n");
}

// the num in the google news function is for the number of results that need to be fetched

struct news* google_news(char *site,int num)
{
short int count=0;
struct news *gnew;

gnew = (struct news *)malloc(num*sizeof(struct news));
for(int i=0;i<num;i++)
{
gnew[i].title = (char *)malloc(500);
gnew[i].news  = (char *)malloc(500);
}

printf("%d",num);
struct sockaddr_in servaddr;
	struct hostent *hp;
	int sock_id;
char str[30]={'\0'};
strcpy(str,site);
int i=0;
short int len=strlen(str);
for(i=0;i<len;i++)
if(str[i]==' ')
str[i]='+';
  char request[300] = "GET /rss/search?q=";
               char *req= "&hl=en-IN&gl=IN&ceid=IN:en  HTTP/1.1\r\n"
                "Host: news.google.com \r\n"
                "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:61.0) Gecko/20100101 Firefox/61.0 \r\n"
                "\r\n";
	       puts("pizza");
	strcat(request,str);
	strcat(request,req);
         
        puts(request);
        sock_id = socket(AF_INET,SOCK_STREAM,0);
	
	memset(&servaddr,0,sizeof(servaddr));
	
	
	hp = gethostbyname("news.google.com");
		
	memcpy((char *)&servaddr.sin_addr.s_addr, (char *)hp->h_addr, hp->h_length);
	
	
	servaddr.sin_port = htons(443);
	servaddr.sin_family = AF_INET;



SSL_load_error_strings ();
SSL_library_init ();
SSL_CTX *ssl = SSL_CTX_new (SSLv23_client_method ());


SSL *sslcon = SSL_new(ssl);
SSL_set_fd(sslcon, sock_id);
	
	
	connect(sock_id, (struct sockaddr *)&servaddr, sizeof(servaddr));
	
	
SSL_connect(sslcon);
	
SSL_write(sslcon,request,sizeof(request));
int val=0;
	int stat = 0;
	char buf;
	short int ar=0,r=0;
	int f=0;
	while(1)
	{

	SSL_read(sslcon,&buf,1);
//	putchar(buf);
if(buf=='<' && SSL_read(sslcon,&buf,1) && buf=='t' && SSL_read(sslcon,&buf,1) && buf=='i' &&SSL_read(sslcon,&buf,1) && buf=='t' &&SSL_read(sslcon,&buf,1) && buf=='l' &&SSL_read(sslcon,&buf,1) && buf=='e' &&SSL_read(sslcon,&buf,1) && buf=='>')
{


//if(buf=='E' && SSL_read(sslcon,&buf,1) && buf=='r' &&   SSL_read(sslcon,&buf,1) && buf=='r' &&  SSL_read(sslcon,&buf,1) && buf=='o' &&  SSL_read(sslcon,&buf,1) && buf=='r' && SSL_read(sslcon,&buf,1) && buf==' ')
  //      break;
//count++;
printf("\n");
r=0;
while(SSL_read(sslcon,&buf,1),gnew[ar].title[r++]=buf,buf!='<');
printf("\n");
gnew[ar].title[r]='\0';
//puts(gnew[ar].title);

printf("ar = %d r=%d",ar,r);
//printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
if(count== num)
break;
}

else if(buf=='h' && SSL_read(sslcon,&buf,1) && buf=='r' && SSL_read(sslcon,&buf,1) && buf=='e' &&SSL_read(sslcon,&buf,1) && buf=='f' &&SSL_read(sslcon,&buf,1) && buf=='=' &&SSL_read(sslcon,&buf,1) && buf=='"')
{
printf("\n");
count++;
r=0;
while(SSL_read(sslcon,&buf,1),gnew[ar].news[r++]=buf,buf!='"');	
printf("\n");
//printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
printf("\n");
gnew[ar].news[r-1]='/';
gnew[ar].news[r]='\0';
//puts(gnew[ar].news);
printf("ar = %d r=%d",ar,r);
ar++;
if(count==num)
break;

}
}
return gnew;
}
//whenever the site is passed in string form to visit function , please put an '/' at the end or else the requests to websites wont be valid , num - 0,1,2 for only para data, only https links and both para and https respectively , this is for general purpose sites
void visit(char *site,int num,char *filename)
{
int fd=open(filename,O_RDWR);
char website[50],path[200];
short int i=8;
short int z=0;
for(i=8;site[i]!='/';website[i-8]=site[i],i++);
z=i-8;
website[i-8]='\r';
website[i-7]='\n';
website[i-6]='\0';
short int j=0;
//printf("website = %s \n",website);
for(;site[i]!='\0';path[j]=site[i],i++,j++);
path[j-2]='\0';

struct sockaddr_in servaddr;
struct hostent *hp;
int sock_id;
char str[30]={'\0'};

  char request[500] = "GET ";
               char *req= "  HTTP/1.1\r\n";
               char *host ="Host: ";

     
              char *rest = "Connection: keep-alive\r\nUpgrade-Insecure-Requests: 1\r\nDNT: 1\r\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:61.0) Gecko/20100101 Firefox/61.0 \r\n"
                "\r\n";
//	      flag
	strcat(request,path);
//	      flag
	strcat(request,req);
	strcat(request,host);
	strcat(request,website);
	strcat(request,rest);



//       puts(request);
        sock_id = socket(AF_INET,SOCK_STREAM,0);

	memset(&servaddr,0,sizeof(servaddr));

        website[z]='\0';
//	puts(website);
	hp = gethostbyname(website);

	memcpy((char *)&servaddr.sin_addr.s_addr, (char *)hp->h_addr, hp->h_length);

  //       printf("%s",inet_ntoa(servaddr.sin_addr));
	servaddr.sin_port = htons(443);
	servaddr.sin_family = AF_INET;



SSL_load_error_strings ();
SSL_library_init ();
SSL_CTX *ssl = SSL_CTX_new (SSLv23_client_method ());


SSL *sslcon = SSL_new(ssl);
SSL_set_fd(sslcon, sock_id);


	connect(sock_id, (struct sockaddr *)&servaddr, sizeof(servaddr));


SSL_connect(sslcon);
puts(request);
SSL_write(sslcon,request,sizeof(request));
int val=0;
	int stat = 0;
	char buf;
        short int cont=0;
	int f=0;
//	puts("pizza");
short int top=0;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*while(1)
{
SSL_read(sslcon,&buf,1);

if(buf=='<' && SSL_read(sslcon,&buf,1) && buf=='b' && SSL_read(sslcon,&buf,1) && buf=='o')
break;
}*/
while(1)
{
if(cont==0)
SSL_read(sslcon,&buf,1);
putchar(buf);
if(num==0)
{
/*
if( buf=='<' && SSL_read(sslcon,&buf,1) && buf=='p')
{
while(SSL_read(sslcon,&buf,1) && buf!='>')
while(SSL_read(sslcon,&buf,1) && buf!='<' && putchar(buf));
}
*/
if(buf=='<' && SSL_read(sslcon,&buf,1) && buf=='p' )
{
top=0;
while(SSL_read(sslcon,&buf,1) && buf!='>');
while(top==0)
{
SSL_read(sslcon,&buf,1);
if(buf=='<' )
{
if(SSL_read(sslcon,&buf,1) && buf=='/' && SSL_read(sslcon,&buf,1) && buf=='p')
{
top=1;
}
else
while(SSL_read(sslcon,&buf,1) && buf!='>');
}
else
{
putchar(buf);
///////////////////////////////
if(buf=='\r' )
{
cont=0;
while(buf=='\r')
{
SSL_read(sslcon,&buf,1);
if(buf=='\r')
cont++;
if(cont==0)
break;
}
}
////////////////////////////////
}
}
}
else if(buf=='/' && SSL_read(sslcon,&buf,1) && buf=='h' && SSL_read(sslcon,&buf,1) && buf=='t' && SSL_read(sslcon,&buf,1) && buf=='m' && SSL_read(sslcon,&buf,1) && buf=='l' && SSL_read(sslcon,&buf,1) && buf=='>')
break;

}

if(num==1)
{
 if(buf=='h' && SSL_read(sslcon,&buf,1) && buf=='r' && SSL_read(sslcon,&buf,1) && buf=='e' &&SSL_read(sslcon,&buf,1) && buf=='f' &&SSL_read(sslcon,&buf,1) && buf=='=' &&SSL_read(sslcon,&buf,1) && buf=='"' && SSL_read(sslcon,&buf,1) && buf=='h')
{
putchar('h');
while(SSL_read(sslcon,&buf,1) && buf!='"' &&putchar(buf));
printf("\n");
}
else if(buf=='/' && SSL_read(sslcon,&buf,1) && buf=='h' && SSL_read(sslcon,&buf,1) && buf=='t' && SSL_read(sslcon,&buf,1) && buf=='m' && SSL_read(sslcon,&buf,1) && buf=='l' && SSL_read(sslcon,&buf,1) && buf=='>')
break;
}

//flag
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//puts("exited while -----------------------------------------------------------------------------------------------------------------------------------------------");

close(fd);
}
//whenever the site is passed in string form to visit function , please put an '/' at the end or else the requests to websites wont be valid , num - 0,1,2 for only para data, only https links and both para and https respectively , this is specifically for wikipedia and others ,since wiki doesnt use <p> for text specifically
void wiki_visit(char *site,int num)
{

char website[50],path[200];
short int i=8;
short int z=0;
for(i=8;site[i]!='/';website[i-8]=site[i],i++);
z=i-8;
website[i-8]='\r';
website[i-7]='\n';
website[i-6]='\0';
short int j=0;
printf("website = %s \n",website);
for(;site[i]!='\0';path[j]=site[i],i++,j++);
path[j-2]='\0';

struct sockaddr_in servaddr;
struct hostent *hp;
int sock_id;
char str[30]={'\0'};

  char request[500] = "GET ";
               char *req= "  HTTP/1.1\r\n";
               char *host ="Host: ";

     
              char *rest = "Connection: keep-alive\r\nUpgrade-Insecure-Requests: 1\r\nDNT: 1\r\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:61.0) Gecko/20100101 Firefox/61.0 \r\n"
                "\r\n";
	      flag
	strcat(request,path);
	      flag
	strcat(request,req);
	strcat(request,host);
	strcat(request,website);
	strcat(request,rest);



       puts(request);
        sock_id = socket(AF_INET,SOCK_STREAM,0);

	memset(&servaddr,0,sizeof(servaddr));

        website[z]='\0';
	puts(website);
	hp = gethostbyname(website);

	memcpy((char *)&servaddr.sin_addr.s_addr, (char *)hp->h_addr, hp->h_length);

         printf("%s",inet_ntoa(servaddr.sin_addr));
	servaddr.sin_port = htons(443);
	servaddr.sin_family = AF_INET;



SSL_load_error_strings ();
SSL_library_init ();
SSL_CTX *ssl = SSL_CTX_new (SSLv23_client_method ());


SSL *sslcon = SSL_new(ssl);
SSL_set_fd(sslcon, sock_id);


	connect(sock_id, (struct sockaddr *)&servaddr, sizeof(servaddr));


SSL_connect(sslcon);

SSL_write(sslcon,request,sizeof(request));
int val=0;
	int stat = 0;
	char buf;

	int f=0;
//	puts("pizza");
short int top=0;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
while(1)
{
SSL_read(sslcon,&buf,1);
if(buf=='<' && SSL_read(sslcon,&buf,1) && buf=='b' && SSL_read(sslcon,&buf,1) && buf=='o')
break;
}
while(1)
{
SSL_read(sslcon,&buf,1);


if(buf=='<' && SSL_read(sslcon,&buf,1) && buf=='s' &&  SSL_read(sslcon,&buf,1) && buf=='c')
while(puts("script"),SSL_read(sslcon,&buf,1) , !(buf=='/' &&  SSL_read(sslcon,&buf,1) && buf=='s' &&  SSL_read(sslcon,&buf,1) && buf=='c'&&  SSL_read(sslcon,&buf,1) && buf=='r'&&  SSL_read(sslcon,&buf,1) && buf=='i' &&  SSL_read(sslcon,&buf,1) && buf=='p' &&  SSL_read(sslcon,&buf,1) && buf=='t' && SSL_read(sslcon,&buf,1) && buf=='>'));
else if(buf=='/' && SSL_read(sslcon,&buf,1) && buf=='b' && SSL_read(sslcon,&buf,1) && buf=='o' && SSL_read(sslcon,&buf,1) && buf=='d' && SSL_read(sslcon,&buf,1) && buf=='y' && SSL_read(sslcon,&buf,1) && buf=='>')
break;
else if(buf=='>')
{
while(buf!='<')
 {
  if(buf!='>')
  putchar(buf);
  SSL_read(sslcon,&buf,1);
 }       
}


if(num==1)
 if(buf=='h' && SSL_read(sslcon,&buf,1) && buf=='r' && SSL_read(sslcon,&buf,1) && buf=='e' &&SSL_read(sslcon,&buf,1) && buf=='f' &&SSL_read(sslcon,&buf,1) && buf=='=' &&SSL_read(sslcon,&buf,1) && buf=='"' && SSL_read(sslcon,&buf,1) && buf=='h')
{
putchar('h');
while(SSL_read(sslcon,&buf,1) && buf!='"' &&putchar(buf));
printf("\n");
}






//else if(buf=='p' && SSL_read(sslcon,&buf,1) && buf=='>')
//while(SSL_read(sslcon,&buf,1) && buf!='<' &&putchar(buf));
//if(buf=='<' && SSL_read(sslcon,&buf,1) && buf=='s' &&  SSL_read(sslcon,&buf,1) && buf=='c')
//while(SSL_read(sslcon,&buf,1) , !(buf=='/' &&  SSL_read(sslcon,&buf,1) && buf=='s' &&  SSL_read(sslcon,&buf,1) && buf=='c'&&  SSL_read(sslcon,&buf,1) && buf=='r'&&  SSL_read(sslcon,&buf,1) && buf=='i' &&  SSL_read(sslcon,&buf,1) && buf=='p' &&  SSL_read(sslcon,&buf,1) && buf=='t' && SSL_read(sslcon,&buf,1) && buf=='>'));
//else 
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//puts("exited while -----------------------------------------------------------------------------------------------------------------------------------------------");
while(1)
if(SSL_read(sslcon,&buf,1) && buf=='<' && SSL_read(sslcon,&buf,1) && buf=='/' && SSL_read(sslcon,&buf,1) && buf=='h' && SSL_read(sslcon,&buf,1) && buf=='t' &&SSL_read(sslcon,&buf,1) && buf=='m' &&SSL_read(sslcon,&buf,1) && buf=='l' &&SSL_read(sslcon,&buf,1) && buf=='>')
{
//puts("exited the entire program-----------------------------------------------------------------------------------------------------------------------------------");
SSL_shutdown(sslcon);
break;

}
}


int download(char *site,char *filename)
{
int fd=open(filename,O_RDWR);
char website[50],path[200];
short int i=8;
short int z=0;
for(i=8;site[i]!='/';website[i-8]=site[i],i++);
z=i-8;
website[i-8]='\r';
website[i-7]='\n';
website[i-6]='\0';
short int j=0;
//printf("website = %s \n",website);
for(;site[i]!='\0';path[j]=site[i],i++,j++);
path[j-2]='\0';

struct sockaddr_in servaddr;
struct hostent *hp;
int sock_id;
char str[30]={'\0'};

  char request[500] = "GET ";
               char *req= "  HTTP/1.1\r\n";
               char *host ="Host: ";

     
              char *rest = "Connection: keep-alive\r\nUpgrade-Insecure-Requests: 1\r\nDNT: 1\r\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:61.0) Gecko/20100101 Firefox/61.0 \r\n"
                "\r\n";
//	      flag
	strcat(request,path);
//	      flag
	strcat(request,req);
	strcat(request,host);
	strcat(request,website);
	strcat(request,rest);



       puts(request);
       sock_id = socket(AF_INET,SOCK_STREAM,0);

	memset(&servaddr,0,sizeof(servaddr));

        website[z]='\0';
//	puts(website);
	hp = gethostbyname(website);

	memcpy((char *)&servaddr.sin_addr.s_addr, (char *)hp->h_addr, hp->h_length);

  //       printf("%s",inet_ntoa(servaddr.sin_addr));
	servaddr.sin_port = htons(443);
	servaddr.sin_family = AF_INET;



SSL_load_error_strings ();
SSL_library_init ();
SSL_CTX *ssl = SSL_CTX_new (SSLv23_client_method ());


SSL *sslcon = SSL_new(ssl);
SSL_set_fd(sslcon, sock_id);


	connect(sock_id, (struct sockaddr *)&servaddr, sizeof(servaddr));


SSL_connect(sslcon);
char *badrq="HTML/1.1 400";
char br[12];
//puts(request);
SSL_write(sslcon,request,sizeof(request));
int val=0;
	int stat = 0;
	char buf;
SSL_read(sslcon,br,12);
if(strcmp(badrq,br)==0)
{
return -1;
}
while(1)
{
SSL_read(sslcon,&buf,1);
write(fd,&buf,1);
if(buf=='<' && SSL_read(sslcon,&buf,1) && write(fd,&buf,1) &&  buf=='/' && SSL_read(sslcon,&buf,1) && write(fd,&buf,1) && buf=='h' && SSL_read(sslcon,&buf,1) && write(fd,&buf,1) && buf=='t' &&SSL_read(sslcon,&buf,1) && write(fd,&buf,1)&& buf=='m' &&SSL_read(sslcon,&buf,1)&& write(fd,&buf,1) && buf=='l' &&SSL_read(sslcon,&buf,1)&& write(fd,&buf,1) && buf=='>')
{
SSL_shutdown(sslcon);
break;
}
}
close(fd);
puts("Finished downloading the HTML document");
}


void clean_tags(char *src,char *dest)
{
int sd=open(src,O_RDONLY);
if(sd==0)
{
puts("file doesnt exist");
return;
}
int dd=open(dest,O_WRONLY|O_CREAT);
char buf;
while(read(sd,&buf,1)!=0)
{
if(buf=='<')
while(read(sd,&buf,1),buf!='>');
else
write(dd,&buf,1);
}
close(sd);
close(dd);
puts("Finished cleaning all the <> tags");
}

void filter_tag(int n,...)
{
va_list ap;
va_start(ap,n);
char *src=va_arg(ap,char *),*dst=va_arg(ap,char *);
char *stag[n-2],*etag[n-2];
for(int i=0;i<n-2;i++)
if(i%2==0)
puts(stag[i/2]=va_arg(ap,char*));
else
puts(etag[i/2]=va_arg(ap,char*));
short int pos=0;
short int fl=0;
short int len=0;
char b;
char buf[5000];
int sd=open(src,O_RDONLY);
if(sd==0)
{
puts("file doesnt exist");
return;
}
int dd=open(dst,O_WRONLY);

while(read(sd,&b,1)!=0)
{
len=0;
fl=0;
if(b=='<')
{
while(read(sd,&b,1)&&!(b=='>'))
{
buf[len++]=b;
if(len>300)
break;
}
buf[len]='\0';
if(strcmp(buf,"/hmtl")==0)
break;

/////////////////////////////////////////
//while(b!='>' && read(sd,&b,1));
for(int i=0;i<(n/2)-1;i++)
if(strcmp(buf,stag[i])==0)
{
//puts(buf);
len=0;
fl=0;
while(fl==0)
{
read(sd,&b,1);
len=0;
if(b=='<')
{
write(dd,&b,1);
while(read(sd,&b,1) && write(dd,&b,1) && !(b=='>') )
buf[len++]=b;
buf[len]='\0';
if(strcmp(buf,etag[i])==0)
{
fl=1;
puts(buf);
}
}
else
write(dd,&b,1);
}
}
}
}
close(sd);
close(dd);
puts("Finished filtering the tags");
}


