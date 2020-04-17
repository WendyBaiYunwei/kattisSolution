#include <stdio.h>
#include <string.h>
#define MAX 10000
 
void rev(char str[]){
    int i,j;
    char temp[MAX];
    j=0;
    for(i=strlen(str)-1;i>=0;i--)
        temp[j++]=str[i];
    temp[j]='\0';
    strcpy(str,temp);
}

void selectionSort(char arr[][MAX], int n)
{
    int i, j, min_idx;
    char temp[MAX];
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if(strcmp(arr[j],arr[min_idx])<0)
                min_idx = j;
 
        // Swap the found minimum element with the first element
        strcpy(temp,arr[i]);
        strcpy(arr[i],arr[min_idx]);
        strcpy(arr[min_idx],temp);
    }
}


int main(void){
    int i,maxLen,total,m,j,count=0;
    char words[100][MAX];
    
    i=0;
    
    while(fgets(words[i],MAX,stdin)!=NULL){
        if(words[i][strlen(words[i])-1]=='\n')
            words[i][strlen(words[i])-1]='\0';
        
        maxLen = 0;
        count++;
        //input start
        i++;
        while(fgets(words[i],MAX,stdin)!=NULL){
            //printf("%d\n",i);
            if(words[i][strlen(words[i])-1]=='\n')
                words[i][strlen(words[i])-1]='\0';
            if(words[i][0]=='\0')
                break;
            i++;
        }
        
        //input end
        
        total = i;
        //printf("%d\n",total);
        for(j=0;j<total;j++){
            //printf("%s\n",words[j]);
            rev(words[j]);
            if(strlen(words[j])>maxLen)
                maxLen = strlen(words[j]);
        }
        
        
        //sort and right justify
        selectionSort(words,total);
        
        if(count!=1)
            printf("\n");
        
        for(j=0;j<total;j++){
            for(m=0;m<maxLen-strlen(words[j]);m++)
                printf(" ");
            rev(words[j]);
            printf("%s\n",words[j]);
        }
        i=0;
    }
    return 0;
}