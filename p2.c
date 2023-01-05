//Michal Zajac
//The program is based on nested if-else statements. One location brances on to other and eventually ends at one location.

#include <stdio.h>
#include <string.h>

int main(){

    char s[50];

        printf("From tuscaloosa: new-orleans, nashville, milton, or atlanta?\n");

        scanf("%s",s);

        if(strcmp(s, "new-orleans")==0){ //branch of new orleans
            printf("From new-orleans: lafayette or lake-charles?\n");
            scanf("%s",s);
            if(strcmp(s, "lafayette")==0){ //branch of new orleans
                printf("\nYou ended your trip in lafayette!");
            }
            else if(strcmp(s, "lake-charles")==0){ //branch of lake charles
                printf("From lake-charles: shrevport or alexandria?\n");
                scanf("%s", s);
                if(strcmp(s, "shrevport")==0){
                    printf("You ended your trip in shrevport!");
                }
                else if(strcmp(s, "alexandria")==0){
                    printf("You ended your trip in alexandria!"); 
                }
            }
        }
    //deleted 
         //new orleans branch end
        else if(strcmp(s, "nashville")==0){ //nashvile branch
            printf("From nashville: memphis or murfreesboro?\n");
            scanf("%s",s);
            if(strcmp(s, "memphis")==0){
                printf("You ended your trip in memphis!");
            }
            else if(strcmp(s, "murfreesboro")==0){
                printf("From murfreesboro: chattanooga or knoxville?\n");
                scanf("%s",s);
                if(strcmp(s, "knoxville")==0){
                    printf("You ended your trip in knoxville!");
                }
                else if (strcmp(s, "chattanooga")==0){
                    printf("From chattanooga: gatlinburg or asheville?\n");
                    scanf("%s",s);
                    if(strcmp(s, "gatlinburg")==0){
                        printf("You ended your trip in gatlinburg!");
                    }
                    else if(strcmp(s, "asheville")==0){
                        printf("You ended your trip in asheville!");
                    }
            }

        }
        }
        else if(strcmp(s, "milton")==0){ //Milton branch
            printf("From milton: pensacola, destin, panama-city?\n");
            scanf("%s", s);
            if(strcmp(s, "pensacola")==0){
                printf("From pensacola: tallahassee or st-augustine?\n");
                scanf("%s" ,s);
                if(strcmp(s, "tallahassee")==0){
                    printf("From tallahassee: gainesville or ocola?\n");
                    scanf("%s", s);
                    if(strcmp(s, "gainesville")==0){
                        printf("You ended your trip in gainesville!");
                    }
                    else if(strcmp(s, "ocola")==0){
                        printf("You ended your trip in ocola!");
                    }
                }
                else if(strcmp(s, "st-augustine")==0){
                    printf("You ended your trip in st-augustine!");
                }
            }
            else if(strcmp(s, "destin")==0){  //Destin branch apart of Milton branch
                printf("From destin: daytona or kissimmee?\n");
                scanf("%s", s);
                if(strcmp(s, "daytona")==0){
                    printf("You ended your trip in daytona!");
                }
                else if(strcmp(s, "kissimmee")==0){
                    printf("You ended your trip in kissimmee!");
                }
            }
            else if(strcmp(s, "panama-city")==0){ //panama city branch
                printf("From panama-city: tampa or jacksonville?\n");
                scanf("%s", s);
                if(strcmp(s, "tampa")==0){
                    printf("You ended your trip in tampa!");
                }
                else if(strcmp(s, "jacksonville")==0){
                    printf("From jacksonville: clearwater, orlando or st-petersburg?\n");
                    scanf("%s", s);
                    if(strcmp(s, "orlando")==0){
                        printf("From orlando: west-palm or fort-lauderdale?\n");
                        scanf("%s", s);
                            if(strcmp(s, "west-palm")==0){
                                printf("You ended your trip in west-palm!");
                            }
                            else if(strcmp(s, "fort-lauderdale")==0){
                                printf("You ended your trip in fort-lauderdale!");
                            }
                    }
                    else if(strcmp(s, "st-petersburg")==0){
                        printf("You ended your trip in st-petersburg!");
                    }
                    else if(strcmp(s, "clearwater")==0){
                        printf("From clearwater: fort-myers or miami?\n");
                        scanf("%s", s);
                        if(strcmp(s, "fort-myers")==0){
                            printf("You ended your trip in fort-myers!");
                        }
                        else if (strcmp(s, "miami")==0){
                            printf("You ended your trip in miami!");
                        }
                    }
                }
            }

        }
        else if(strcmp(s, "atlanta")==0){
            printf("From atlanta: athens or columbus?\n");
            scanf("%s", s);
            if(strcmp(s, "athens")==0){
                printf("From athens: augusta or macon?\n");
                scanf("%s", s);
                if(strcmp(s, "augusta")==0){
                    printf("From augusta: savannah or tybee-island?\n");
                    scanf("%s", s);
                    if(strcmp(s, "savannah")==0){
                        printf("You ended your trip in savannah!");
                    }
                    else if(strcmp(s, "tybee-island")==0){
                        printf("You ended your trip in tybee-island!");
                    }
                }
                else if(strcmp(s, "macon")==0){
                    printf("You ended your trip in macon!");
                }
            }
            else if(strcmp(s, "columbus")==0){
                printf("From colombus: warner-robins or albany?\n");
                scanf("%s",s );
                if(strcmp(s, "warner-robins")==0){
                    printf("You ended your trip in warner-robins!");
                }
                else if(strcmp(s, "albany")==0){
                    printf("From albany: fernandina or brunswick?\n");
                    scanf("%s",s);
                    if(strcmp(s, "fernandina")==0){
                        printf("You ended your trip in fernandina!");
                    }
                    else if(strcmp(s, "brunswick")==0){
                        printf("You ended your trip in brunswick!");
                    }
                }
            }
        }


    
    return 0;
}