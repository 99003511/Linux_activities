#include "count.h"

int lines, characters, words;;

void checkfile()
{
	int fd,nbytes;
	char ch[16384];
  fd=open("alpha.txt",O_RDONLY);  // open file in readonly mode
	if(fd<0)
	{
		perror("open");  // open fd 
		exit(1);
	}
  words = 0,lines = 0;
    while(nbytes=read(fd,ch,sizeof(ch)))
    {
        for(int i=0;i<nbytes;i++)
        {
            //Check new line 
            if (ch[i] == '\n')
               lines++;
            // Check words 
            if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
               words++;
        }
        characters=nbytes;
    }
    // Close files to release resources 
    close(fd);
}

int getLines()
{
  return lines;
}
int getCharacters()
{
  return characters;
}
int getWords()
{
  return words;
}
