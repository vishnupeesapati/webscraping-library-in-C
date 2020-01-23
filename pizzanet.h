#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<pthread.h>
#include <openssl/ssl.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<ctype.h>
#include<signal.h>
struct news
{
char *title;
char *news;
};
struct tag
{
char *src;
char *etag;
};
void handle();
char** google_visit(char *,short int num);
void google_desc(char *);
struct news* google_news(char *,int num);
void visit(char *,int num,char *filename);
void wiki_visit(char *site,int num);
int download(char *site,char *filename);
void clean_tags(char *src,char *dest);
//void filter_tag(char *src,char *dest,char *stag,char* etag);
void filter_tag(int n,...);// this is a a varargs function. The first 2 arguments correspond to the source and destination filenames. and int n corresponds to the number of arguments that need to be used.


