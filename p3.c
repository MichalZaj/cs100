#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[100];

    while(1){
        int pos = 0;
        int neg = 0;
        int binary = 0;
        int guid = 0;
        int floating = 0;
        int negFloating = 0;
        printf("Enter a token to identify, EOF to stop:");
        
        scanf("%s",s);
        if(feof(stdin)) break;
        //scan for input

        int posCount=0;
        for(int i = 0; i< strlen(s); i++){
            if(isdigit(s[i])){
                posCount++;
            }
        }
        if(posCount == strlen(s)){
            pos = 1;
        }
        //End of first Check for Positives

        int negCount = 0;
        if(s[0] == '-'){
            negCount++;
            
        for(int i = 1; i < strlen(s); i++){
            if(isdigit(s[i])){
                negCount++;
            }
        }
        }
        if(negCount == strlen(s)){
            neg = 1;
        }
        //End of Second Check for negatives

        int binaryCount = 0;
        if(strlen(s)>2){
        if(s[0] == '0' && s[1]== 'b'){
            binaryCount = 2;
            if(strlen(s) > 2)
            for(int i = 2; i< strlen(s); i++){
                if(s[i] == '0' || s[i] == '1'){
                    binaryCount++;
                }
            }
            
        }
        }
        if(binaryCount == strlen(s)){
            binary = 1;
        }
        //End of the Third Check for binary number
        int floatingCount = 0;
        if((isdigit(s[0])) && (isdigit(s[strlen(s)-1]))){
            floatingCount = 2;
            for(int i = 1; i < strlen(s)-1; i++){
                if(isdigit(s[i])){
                    floatingCount++;
                }
                if(s[i] == '.'){
                    floatingCount++;
                }
        }
        }
        if(floatingCount == strlen(s)){
            floating = 1;
        }
        //End of check for Floating point number
        int negFloatingCount = 0;

        if(s[0] == '-'){
            negFloatingCount = 1;
            if((isdigit(s[1])) && (isdigit(s[strlen(s)-1]))){
                negFloatingCount = 3;
                for(int i = 2; i < strlen(s)-1; i++){
                if(isdigit(s[i])){
                    negFloatingCount++;
                }
                if(s[i] == '.'){
                    negFloatingCount++;
                }
            }
        }
        }
        if(negFloatingCount == strlen(s)){
            negFloating = 1;
        }
        //End of negative Floating point Number
        int hexCount = 0;
        char str[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','a','b','c','d','e','f'};
            if(s[8]== '-'){
                hexCount++;
            }
            if(s[13]== '-'){
                hexCount++;
            }
            if(s[18]=='-'){
                hexCount++;
            }
            if(s[23]== '-'){
                hexCount++;
            }

        for(int i = 0; i < strlen(s); i++){
            if(i!=8 && i!=13 && i!=18 && i != 23){
                for(int j = 0; j< strlen(str); j++){
                    if(str[j] == s[i]){
                        hexCount++;
                    }
                }
            }
        }
        if(hexCount == 36){
            guid = 1;
        }

        //End of the Guid check
        
        //These are the results printed
        if(pos == 1){
        printf("The token is a positive integer\n");
        }
        else if(neg == 1){
            printf("The token is a negative integer\n");
        }
        else if(binary == 1){
            printf("The token is a binary number\n");
        }
        else if(floating == 1){
            printf("The token is a positive floating-point number\n");
        }
        else if(negFloating == 1){
            printf("The token is a negative floating-point number\n");
        }
        else if(guid == 1){
            printf("The token is a guid\n");
        }
        else{
            printf("The token cannot be identified\n");
        }

    }
    return 0;
}