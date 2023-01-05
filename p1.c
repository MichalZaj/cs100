#include <stdio.h>

int main(){

    int cups = 2000;
    int candy = 1000;
    int popcorn = 2500;
    int water = 750;

    int cupsR, candyR, popcornR, waterR;

    printf("Enter the number of cups, candy, popcorn, and water remaining:\n"); //Ask for remaining items
    scanf("%d%d%d%d", &cupsR, &candyR, &popcornR, &waterR);

    int cupsN = cups - cupsR;
    int candyN = candy - candyR;
    int popcornN = popcorn - popcornR;
    int waterN = water - waterR;
    printf("Need: %d cups, %d candy bars, %d bags of popcorn, and %d bottles of water\n", cupsN,candyN,popcornN,waterN); //print first statement

    int cost = (cupsN * 5) + (candyN * 30) + (popcornN * 20) + (waterN * 50);
    int dollars = cost / 100;
    int cents = cost % 100;
    printf("Cost: %d dollars and %d cents\n", dollars, cents); //Print second statement
    double cupsA = cupsN / 7.0;
    double candyA = candyN / 7.0;
    double popcornA = popcornN /7.0;
    double waterA = waterN / 7.0;

    printf("Average sold: %.2lf cups, %.2lf candy bars, %.2lf bags of popcorn, and %.2lf bottles of water per day", cupsA ,candyA, popcornA, waterA);


    return 0;
}