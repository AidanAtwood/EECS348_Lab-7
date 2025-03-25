#include <stdio.h>
#include "temperature.h"

//perform the calculation that converts celsius to fahrenheit as a float
float C_to_F(float celsius) {
    //convert celsius to fahrenheit and return
    return (9.0/5.0) * celsius + 32;
}

//perform the calculation that converts fahrenheit to celsius as a float
float F_to_C(float fahrenheit) {
    //convert fahrenheit to celsius and return
    return (fahrenheit - 32) * (5.0/9.0);
}

//perform the calculation that converts celsius to kelvin as a float
float C_to_K(float celsius) {
    //convert celsius to kelvin and return
    return celsius + 273.15;
}

//perform the calculation that converts fahrenheit to kelvin as a float
float F_to_K(float fahrenheit) {
    //convert fahrenheit to kelvin and return
    return (fahrenheit - 32) * (5.0/9.0) + 273.15;
}

//perform the calculation that converts kelvin to celsius as a float
float K_to_C(float kelvin) {
    //convert kelvin to celsius and return
    return kelvin - 273.15;
}

//perform the calculation that converts kelvin to fahrenheit as a float
float K_to_F(float kelvin) {
    //convert kelvin to fahrenheit and return
    return (kelvin - 273.15) * (9.0/5.0) + 32;
}

//decide what category our temperature is and return as such
void display_temperature(float C) {
    //check if the temperature in celsius is below or at freezing
    if (C <= 0) {
        //give the temperature category
        printf("Temperature: Freezing\n");
        //give the weather advisory
        printf("Weather advisory: Stay indoors unless necessary and stay warm!\n");
    }
    //check if the temperature in celsius is above freezing and at or below 10c
    else if (C > 0 && C <= 10) {
        //give the temperature category
        printf("Temperature: Cold\n");
        //give the weather advisory
        printf("Weather advisory: Make sure to wear a jacket!\n");
    }
    //check if the temperature in celsius is above 10c and at or below 25c
    else if (C > 10 && C <= 25) {
        //give the temperature category
        printf("Temperature: Comfortable\n");
        //give the weather advisory
        printf("Weather advisory: Nothing to report, have fun!\n");
    }
    //check if the temperature in celsius is above 25c and at or below 35c
    else if (C > 25 && C <= 35 ) {
        //give the temperature category
        printf("Temperature: Hot\n");
        //give the weather advisory
        printf("Weather advisory: Don't forget your sunscreen!\n");
    }
    //if all previous cases fail, the temperature should be above 35c
    else {
        //give the temperature category
        printf("Temperature: Extreme Heat\n");
        //give the weather advisory
        printf("Weather advisory: Stay indoors and keep cool!\n");
    }
}

//clear the input buffer if needed
void clear_input(void) {
    int c;
    while ((c = getchar()) != "\n" && c != EOF) {}
}