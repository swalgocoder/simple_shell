#include<stdio.h>
#include<stdlib.h>
char *myfgets(char *Buffer_address,int size,FILE *fp)
{
    register int c;
    register char  *Notify_IfNotRead;
    Notify_IfNotRead = Buffer_address;

    if (size > 0)
      {   
      while(--size>0 && (c=getc(fp)) != EOF)
	{
	  *Notify_IfNotRead++ = c;
	  if (c == '\n') break;
	}
      *Notify_IfNotRead = '\0';
      }

    if (c == EOF)
      {
	if (ferror(fp)) return NULL;
	if (feof(fp) && Notify_IfNotRead == Buffer_address) return NULL;
      }
return Buffer_address;

}

int main()
{
    char ch[100];
    FILE *fp ;
    fp=fopen("myfile","r");
    char * pp=(myfgets(ch,100,fp));
    printf("%s",pp);

    exit(EXIT_SUCCESS);  // No need to close(fp) because exit does for us
}
