#include "football.h"
#include <stdio.h>

/*
EECS 348 Lab 07 exercise 1
NFL game score iterator

Inputs: An NFL game score provided by the user
Outputs: A list of all possible score combinations and the final count of the number of combinations

Collaborators: None
Other sources: geeksforgeeks.org, w3schools.com
Author's name: Aidan Atwood
Creation date: 3/23/25
*/

//declare main
int main(int argc, char *argv[]) {
    int score;
    //start a loop that will prompt the user for the score
    while (1) {
        //print our message
        printf("Enter the NFL score\n(Enter 0 or 1 to STOP): "); 
        //save our input
        scanf("%d", &score);

        //stop program if input is one or zero
        if (score == 0 || score == 1) {
            //use break to end loop
            break;
        }
        //prints an error message and keeps looping if the input is negative
        else if (score < 0) {
            printf("Invalid score. Please enter a non-negative number.\n");
            continue;
        }

        //call our print_combos function
        print_combos(score);

        //call our count_combos function and print
        int count = count_combos(score);
        printf("Total combinations: %d\n", count);
    }

    //return zero, ending loop
    return 0;
}