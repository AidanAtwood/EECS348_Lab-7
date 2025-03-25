/*
EECS 348 Lab 07 exercise 2
Temperature converter

Inputs: A temperature provided by the user as well as the current and desired unit of measure/
Outputs: The converted temperature and weather advisory

Collaborators: None
Other sources: geeksforgeeks.org, w3schools.com
Author's name: Aidan Atwood
Creation date: 3/20/25
*/

#include "temperature.h"
#include <stdio.h>

//declare main
int main(int argc, char *argv[]) {
    //declare the user input
    float user_input;

    //declare current unit
    int current_unit;

    //declare target unit
    int target_unit;

    //ask the user for their temperature
    printf("Give a temperature: ");

    //save our input if it is in the correct format 
    int temp1 = scanf("%f", &user_input);

    //otherwise, ask for the input again
    while (temp1 != 1) {
        //print our message
        printf("Invalid number. Please try again: ");
        //clear input buffer
        clear_input();
        //save user input
        temp1 = scanf("%f", &user_input);
    }

    //ask user for the current unit
    printf("Choose the current scale: [1] Celsius, [2] Fahrenheit, [3] Kelvin: ");

    //save our input if it is in the correct format
    int temp2 = scanf("%d", &current_unit);

    //otherwise, ask for the input again
    while(temp2 != 1 || (current_unit != 1 && current_unit != 2 && current_unit != 3)) { 
        //print our message
        printf("Invalid input. Please try again:");
        //clear input buffer
        clear_input();
        //save user input
        temp2 = scanf("%d", &current_unit); 
    }

    //ask user for the target unit
    printf("Convert to [1] Celsius, [2] Fahrenheit, [3] Kelvin: ");

    //save user input if it is in the correct format
    int temp3 = scanf("%d", &target_unit);

    //otherwise, ask for the input again
    while(current_unit == target_unit || temp3 != 1 || (current_unit != 1 && current_unit != 2 && current_unit != 3)) {
        //print our message
        printf("Invalid input. Please try again:");
        //clear input buffer
        clear_input();
        //save user input
        temp3 = scanf("%d", &target_unit); 
    }

    //this will only run if the current unit is kelvin and the user's input is negative, returning an error
    while( current_unit == 3 && user_input < 0) {
        //print our message
        printf("Invalid Kelvin temperature. Temperature cannot be negative.\n");
        //ask user for another temperature
        printf("Enter the temperature: ");
        //save our input
        temp1 = scanf("%f", &user_input);
        //make sure our input is in the correct format this time
        while (temp1 != 1) {
            printf("Invalid number. Please try again: ");
            clear_input();
            temp1 = scanf("%f", &user_input);
        }

        //ask for the current unit
        printf("Choose the current unit: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");

        //save our input 
        temp2 = scanf("%d", &current_unit);

        //make sure our input is in the correct format, repeat if not
        while(temp2 != 1 || (current_unit != 1 && current_unit != 2 && current_unit != 3)) {
            printf("Invalid input. Please try again:");
            clear_input();
            temp2 = scanf("%d", &current_unit);
        }

        //ask user for the unit to convert to
        printf("Convert to [1] Celsius, [2] Fahrenheit, [3] Kelvin: ");

        //save our input
        temp3 = scanf("%d", &target_unit);

        //make sure input is in the correct format
        while(current_unit == target_unit || temp3 != 1 || (current_unit != 1 && current_unit != 2 && current_unit != 3)) {
            printf("Invalid input. Please choose the convert unit again:");
            clear_input();
            temp3 = scanf("%d", &target_unit);
        }
    }
        //start a switch-case
        switch (current_unit) {
            //run if current unit is celsius
            case 1:
                switch(target_unit) {
                    //run if target is fahrenheit
                    case 2:
                        //calculate
                        {float temp = C_to_F(user_input);
                        //print converted temperature
                        printf("Converted temperature: %.2f F\n", temp);
                        //use break to exit loop
                        break;}
                    //run if target is kelvin
                    case 3:
                        //calculate
                        {float temp = C_to_K(user_input);
                        //print converted temperature
                        printf("Converted temperature: %.2f K\n", temp);
                        //use break to exit loop
                        break;}
                }
                //print weather
                display_temperature(user_input);
                //use break to exit loop
                break;
            //run if current unit is fahrenheit
            case 2:
                switch(target_unit) {
                    //run if target is celsius
                    case 1:
                        //calculate
                        {float temp = F_to_C(user_input);
                        //print converted temperature
                        printf("Converted temperature: %.2f C\n", temp);
                        //use break to exit loop
                        break;}
                    //run if target is kelvin
                    case 3:
                        //calculate
                        {float temp = F_to_K(user_input);
                        //print converted temperature
                        printf("Converted temperature: %.2f K\n", temp);
                        //use break to exit loop
                        break;}
                }
                //print weather
                display_temperature(F_to_C(user_input));
                //use break to exit loop
                break;
            //run if current unit is kelvin
            case 3:
                switch(target_unit) {
                    //run if target is celsius
                    case 1:
                        //calculate
                        {float temp = K_to_C(user_input);
                        //print converted temperature
                        printf("Converted temperature: %.2f C\n", temp);
                        //use break to exit loop
                        break;}
                    //run if target is fahrenheit
                    case 2:
                        //calculate
                        {float temp = K_to_F(user_input);
                        //print converted temperature
                        printf("Converted temperature: %.2f F\n", temp);
                        //use break to exit loop
                        break;}
                }
                //print weather
                display_temperature(K_to_C(user_input));
                //use break to exit loop
                break;
    }
    
    //return 0, ending main
    return 0;
}