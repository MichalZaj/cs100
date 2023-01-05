#include <stdio.h>
#include <string.h>
#include <ctype.h>

void left(char word[]);
void right(char word[]);
void inc(char word[]);
void dec(char word[]);

int main(int argc, char **argv) { 

    if(argc!= 3){
        printf("Invalid number of arguments");
        return 1;
    }
    
    FILE *fp = fopen(argv[1],"r");
    if(fp == NULL){
        printf("Could not open file '%s'",argv[1]);
        return 1;
    }
    
    char list[30][100]; //array declaration for the words
    int count = 0;
    while(1){
        fscanf(fp, "%s", list[count]);
        if(feof(fp)) break;
        count++;
    }

    int k = 0;

    while(argv[2][k] != '\0'){
        if(argv[2][k] == 'L'){
            for(int i = 0; i < count; i++){
                left(list[i]);
            }
        }
        else if(argv[2][k] == 'R'){
            for(int i = 0; i < count; i++){
                right(list[i]);
            }
        }
        else if(argv[2][k] == 'I'){
            for(int i = 0; i < count; i++){
                inc(list[i]);
            }
        }
        else if(argv[2][k] == 'D'){
            for(int i = 0; i < count; i++){
                dec(list[i]);
            }
        }
        else{
            printf("You threw off my schwiftiness with schwifty '%c'!", argv[2][k]);
            return 1;
        }
        k++;
    }

    //Print the array
    for(int i = 0; i < count; i++){
        printf("%s\n", list[i]);
    }

    fclose(fp);

    

   return 0;
}

void left(char word[]) {
    int len = strlen(word);
    char temp = word[0];
    for(int i = 1; i <= len; i++){
        word[i-1] = word[i];
    }
    word[len - 1] = temp;
    word[len] = '\0';

}
    
void right(char word[]) {
    int len = strlen(word);
    char temp = word[len-1];
    for(int i = len-1; i >= 0; i--){
        word[i+1] = word[i];
    }
    word[0] = temp;
    word[len] = '\0';
}

void inc(char word[]) {
   int len = strlen(word);

   for(int i = 0; i < len; i++){
       if(word[i] == 'z'){
           word[i] = 'a';
       }
       else if(word[i] == 'Z'){
           word[i] = 'A';
       }
       else if(word[i] == '9'){
           word[i] = '0';
       }
       else if((word[i] >= 'a') && (word[i]<'z') || (word[i]>='A') && (word[i]<'Z') || (word[i]>='0') && (word[i]<'9')){
           word[i] = word[i] + 1;
       }

   }
}

void dec(char word[]) {
   int len = strlen(word);

   for(int i = 0; i < len; i++){
       if(word[i] == 'a'){
           word[i] = 'z';
       }
       else if(word[i] == 'A'){
           word[i] = 'Z';
       }
       else if(word[i] == '0'){
           word[i] = '9';
       }
       else if(((word[i] >= 'b') && (word[i]<='z')) || ((word[i]>='B') && (word[i]<='Z')) || ((word[i]>='1') && (word[i]<='9'))){
           word[i] = word[i] - 1;
       }
   }
}