#include <stdio.h>
#include <ctype.h>

void jerseyPrompt(int i);
void ratingPrompt(int k); //own method
void printRoster(int jerseyNums[], int ratingNums[]);
char menu();
void getInput(int *jerseyNums, int *ratingNums);
void replacePlayer(int jerseyNums[], int ratingNums[]);
void updateRating(int jerseyNums[], int ratingNums[]);

const int NUM_PLAYERS = 5;

int main() {
    int jerseys[NUM_PLAYERS];
    int ratings[NUM_PLAYERS];
   
    getInput(jerseys, ratings);

    printRoster(jerseys, ratings);

    char option;

    option = menu();
    
    while(1){
        
         if(option == 'u'){
             updateRating(jerseys, ratings);
         }
         else if(option == 'r'){
             replacePlayer(jerseys, ratings);
         }
         else if(option == 'o'){
             printRoster(jerseys, ratings);
         }
        else if(option == 'q'){
            return 1;
        }
         else{
            printf("Invalid option\n");
             break;
         }
         option = menu();
     }

    return 0;
}

void jerseyPrompt(int i){
    printf("Enter player %d's jersey number:\n", i);
}
//Own function
void ratingPrompt(int k){
    printf("Enter player %d's rating:\n",k);
}

void getInput(int *jerseyNums, int *ratingNums){ //done
    int num = 1;
    for(int i = 0; i < 5; i++){
        //Get the Jersey numbers from the user and use while loop to make sure it is valid
        jerseyPrompt(num);
        scanf("%d", &jerseyNums[i]);
        while(jerseyNums[i] < 1 || jerseyNums[i] > 99){
            printf("Invalid Jersey number. ");
            jerseyPrompt(num);
            scanf("%d", &jerseyNums[i]);
        }
        //Get the ratings from the user and validate them with while loop
        ratingPrompt(num);
        scanf("%d", &ratingNums[i]);
        while(ratingNums[i] < 1 || ratingNums[i] > 10){
            printf("Invalid player rating. ");
            ratingPrompt(num);
            scanf("%d", &ratingNums[i]);
        }
        num++; //count update for the player
    }
}
char menu(){
    char input;
    printf("\nMENU\n");
    printf("u - Update player rating\n");
    printf("r - Replace player\n");
    printf("o - Output roster\n");
    printf("q - Quit\n");
    printf("\n");
    printf("Choose an option:\n");

    //Scan for the user input
    scanf(" %c", &input);

    return input;
}
void printRoster(int jerseyNums[],int ratingNums[]){
    int num = 1;
    printf("ROSTER\n");
    for(int i = 0; i < 5; i++){
        printf("Player %d -- Jersey number: %d, Rating: %d\n", num ,jerseyNums[i],ratingNums[i]);
        num++;
    }
}

void updateRating(int jerseyNums[], int ratingNums[]){
    printf("Enter jersey number for rating update:\n");
    int check = 0;
    int num  = 0;
    int place = 0;

    while(check == 0){
        scanf("%d", &num);
        for(int i = 0; i< NUM_PLAYERS; i++ ){
        if(jerseyNums[i] == num){
            check = 1;
            place = i;
        }
   }
    if(check == 0){
         printf("Invalid jersey number. Enter valid jersey number:\n");
    }
    }
    
    printf("Found jersey number. Enter new rating for player: \n");
    scanf("%d", &ratingNums[place]);
        while(ratingNums[place] < 1 || ratingNums[place] > 10){
            printf("Invalid player rating. Enter valid rating:\n");
            scanf("%d", &ratingNums[place]);
        }

}
void replacePlayer(int jerseyNums[], int ratingNums[]){
    printf("Enter jersey number to replace:\n");
    int check = 0;
    int num  = 0;
    int place = 0;

    while(check == 0){
        scanf("%d", &num);
        for(int i = 0; i< NUM_PLAYERS; i++ ){
        if(jerseyNums[i] == num){
            check = 1;
            place = i;
        }
    }
    if(check == 0){
         printf("Invalid jersey number. Enter valid jersey number:\n");
    }
    }
    
    printf("Found player. Enter new jersey number:\n");
    scanf("%d", &jerseyNums[place]);
        while(jerseyNums[place] < 0 || jerseyNums[place] > 99){
            printf("Invalid jersey number. Enter valid jersey number:\n");
            scanf("%d", &jerseyNums[place]);
        }
        printf("Enter player rating:\n");
        scanf("%d", &ratingNums[place]);
        while((ratingNums[place]) < 1 || (ratingNums[place] > 10)){
            printf("Invalid player rating. Enter valid rating:\n");
            scanf("%d", &ratingNums[place]);
        }
}