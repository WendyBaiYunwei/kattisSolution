#include <stdio.h>
#include <string.h>
#define MAX 1000010

int main(){
    char pattern[MAX+1],text[MAX+1];
    int len1,len2,i,j=0,pos[MAX];
    char *temp;
    
    while (fgets(pattern, MAX+1, stdin)!=NULL){
        
        len1 = strlen(pattern); 
        if (pattern[len1 - 1] == '\n')
            pattern[len1 - 1] = '\0';
        
        fgets(text, MAX+1, stdin);
        len2 = strlen(text); 
        if (text[len2 - 1] == '\n')
            text[len2 - 1] = '\0';
        
        temp=text;
        len1 -= 1;
        len2 -= 1; 
        
        for(i=0;i<len2-len1+1;i++,temp+=1)
            if(strncmp(temp,pattern,len1)==0){
                pos[j]=i;
                j++;
            }
        
        for(i=0;i<j;i++)
            printf("%d ",pos[i]);
        
        j=0;
        
        printf("\n");
    
    }
    
    return 0;
}