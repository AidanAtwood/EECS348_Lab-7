#include "football.h"
#include <stdio.h>

//declare a function that will try to find every combination of points available
int count_combos(int points) {
    int count = 0;

    //iterates possible touchdown + 2pt conversions 
    for (int td2pt = 0; td2pt * 8 <= points; td2pt++) {
        //iterates possible touchdown and field goals
        for (int tdfg = 0; tdfg * 7 <= points - td2pt * 8; tdfg++) {
            //iterates possible touchdowns
            for (int td = 0; td * 6 <= points - td2pt * 8 - tdfg * 7; td++) {
                //iterates possible field goals
                for (int fg = 0; fg * 3 <= points - td2pt * 8 - tdfg * 7 - td * 6; fg++) {
                    //iterates possible saftey counts
                    for (int saf = 0; saf * 2 <= points - td2pt * 8 - tdfg * 7 - td * 6 - fg * 3; saf++) {
                        //calculate final score
                        int total = td2pt * 8 + tdfg * 7 + td * 6 + fg * 3 + saf * 2;
                        if (total == points) {
                            //increases count if our total equals our points
                            count++;
                        }
                    }
                }
            }
        }
    }
    //returns the number of point combinations
    return count;
}

//declare a function that will print all of our combinations
void print_combos(int points) {
    printf("Possible combinations: %d:\n", points);

    //print all our possible combos
    for (int td2pt = 0; td2pt * 8 <= points; td2pt++) {
        for (int tdfg = 0; tdfg * 7 <= points - td2pt * 8; tdfg++) {
            for (int td = 0; td * 6 <= points - td2pt * 8 - tdfg * 7; td++) {
                for (int fg = 0; fg * 3 <= points - td2pt * 8 - tdfg * 7 - td * 6; fg++) {
                    for (int saf = 0; saf * 2 <= points - td2pt * 8 - tdfg * 7 - td * 6 - fg * 3; saf++) {
                        int total = td2pt * 8 + tdfg * 7 + td * 6 + fg * 3 + saf * 2;
                        if (total == points) {
                            //print score
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, tdfg, td, fg, saf);
                        }
                    }
                }
            }
        }
    }
}