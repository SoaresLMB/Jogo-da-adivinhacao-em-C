#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Imprime o cabeçalho do jogo.
    printf("****************************\n");
    printf("welcome to the guessing game\n");
    printf("****************************\n");

    int seconds = time(0);
    srand(seconds);

    int big_number = rand();

    int secret_number = big_number %100;
    printf("%d\n",secret_number);
    int kick;
    int attempts = 1;
    double score = 1000;
    int got_it_right = 0;


    int level;
    printf("Choose a difficulty level, (1) Easy, (2) Medium,(3) Hard:\n");
    scanf("%d",&level);

    int attempts_number;

    switch(level) {
        case 1:
            attempts_number = 20;
            break;
        case 2:
            attempts_number = 15;
            break;
        default:
            attempts_number = 6;
            break;
    }

    for(int i=1;i <= attempts_number; i++) {

        printf("attempt %d\n", attempts);
        printf("what is your kick?");
        scanf("%d", &kick);
        printf("Your kick is %d\n", kick);

        if (kick < 0) {
            printf("you can't kick negative numbers\n");
            continue;
        }

        got_it_right = (kick == secret_number);
        int bigger_than = kick > secret_number;

        if (got_it_right) {
            break;

        } else if (bigger_than) {
            printf("Your kick is bigger than the secret number!\n");
        } else {
            printf("Your kick is less than the secret number!\n");
        }
        attempts++;

        double score_lost = abs(kick - secret_number) / (double)2;
        score = score - score_lost;
    }

    printf("Game over!\n");

    if (got_it_right){
        printf("You win!\n");
        printf("You got it right in %d attempts\n", attempts);
        printf("Score:%.1f\n",score);
    } else{
        printf("You lost, try again!");
    }

}