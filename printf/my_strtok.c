#include <stdio.h>
#include <string.h>  
#include <malloc.h>
char* my_strtok(char* s, const char* delm)
{
    static int currIndex = 0;
    if(!s || !delm || s[currIndex] == '\0')
    return NULL;
    char *W = (char *)malloc(sizeof(char)*100);
    int i = currIndex, k = 0, j = 0;
    //char *ptr;
    //static char *Iterator = s;
    //ptr = s;

    /*if (s == NULL){
    s = Iterator;
    }*/
    while (s[i] != '\0'){
        j = 0;
        while (delm[j] != '\0'){
            if (s[i] != delm[j])
                W[k] = s[i];
            else goto It;
            j++;
        }
        //ptr++;
        i++;
        k++;
    }
It:
    W[i] = 0;
    currIndex = i+1;
    //Iterator = ++ptr;
    return W;
}

int main(void)
{
char s[100] = "my name is khan \t test";
char delm[] = " ";
const char whitespace[8] = " \t\v\n\f\n\r";
//char newstr[100];
char *str = my_strtok(s,whitespace);
while(str){
    printf("%s", str);
    free(str);
    str = my_strtok(s, delm);
}
//strcpy(newstr, str);
//for(int i = 0; newstr[i] != '\0'; i++)
//    printf("%c", newstr[i]);
return 0;
}
