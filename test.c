#include"pizzanet.h"


void main()
{
signal(SIGSEGV,handle);
char **lol;
struct news *g;
system("rm file.txt pat.txt test.txt");
system("touch file.txt pat.txt test.txt");
system("touch pat1.txt pat2.txt pat3.txt pat4.txt pat5.txt");
//int fd=open("file.txt",O_RDONLY);
//puts("google description --------------------------------------------------------------------------------------- ");
//google_desc("Mahesh Babu");
//puts("----------------------------------------------------------Get all the google search results https links with related to the search word-------------------");
//lol=google_visit("mahesh babu",15);
//puts("--------------------------------------------------------------Get all the google news results related to the search words----------------------------------");
/*g=google_news("trump iran",10);

char *filename="pat0.txt";
for(int i=0;i<9;i++)
{
puts(g[i].news);


//download(g[0].news,"file.txt");
if(download(g[i].news,"file.txt")!=-1)
{
char *stag="p",*etag="/p";
filter_tag(6,"file.txt","test.txt",stag,etag,"h","/h","span","/span");
filename[3]+=i;
clean_tags("test.txt",filename);
}
}
*/

//puts("visits the site and gets all the content in body although small bugs are there----------------------------------------------------");

//visit("https://www.theguardian.com/games/2019/nov/15/star-wars-jedi-fallen-order-review/",0);
//puts("gets all the https links from the site---------------------------------------------");
//visit("https://en.wikipedia.org/wiki/Institute_of_Electrical_and_Electronics_Engineers/",0);
//visit("https://www.indiatoday.in/world/story/trump-impeachment-1631326-2019-12-25//",0,fd); //use double // at the end as delimiter
//visit("https://www.pinkvilla.com/entertainment/south/mahesh-babu-man-golden-heart-and-video-fan-meet-proof-495267//",0,fd);
//download("https://www.theguardian.com/games/2019/nov/15/star-wars-jedi-fallen-order-review///","file.txt");
//visit("https://www.washingtonpost.com/business/2019/12/27/trumps-quest-shatter-gop-economics-reached-its-culmination///",0,"file.txt");
//visit("https://en.wikipedia.org/wiki/The_Witcher_3:_Wild_Hunt//",0,"file.txt");
//close(fd);

download("https://www.nttftrg.com///","file.txt");
///char *stag="table class=\"highlight tab-size js-file-line-container\" data-tab-size=\"8\"",*etag="/table"; for github code leave this unchanged
filter_tag(6,"file.txt","test.txt","p","/p","span","/span");
clean_tags("test.txt","pat1.txt");
}
