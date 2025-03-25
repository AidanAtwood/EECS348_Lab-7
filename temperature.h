#ifndef __REPORT_H__
#define __REPORT_H__

/* Add any function signatures you need here but do not modify the existing ones */

/**
 * @brief Convert temperature in Celsius to Fahrenheit
 * 
 * @param celsius
 * @return float
 */
float C_to_F(float celsius);

/**
 * @brief Convert temperature in Fahrenheit to Celsius
 * 
 * @param fahrenheit
 * @return float
 */
float F_to_C(float fahrenheit);

/**
 * @brief Convert temperature in Celsius to Kelvin
 * 
 * @param celsius
 * @return float
 */
float C_to_K(float celsius);

/**
 * @brief Convert temperature in Kelvin to Celsius
 * 
 * @param kelvin
 * @return float
 */
float K_to_C(float kelvin);

/**
 * @brief Convert temperature in Fahrenheit to Kelvin
 * 
 * @param fahrenheit
 * @return float
 */
 float F_to_K(float fahrenheit);

 /**
 * @brief Convert temperature in Kelvin to Fahrenheit
 * 
 * @param kelvin
 * @return float
 */
 float K_to_F(float kelvin);

 /**
 * @brief Decide what category our temp falls into
 * 
 * @param celsius
 * @return none
 */
 void display_temperature(float C);

 /**
 * @brief Clear the input buffer
 *
 * @param none
 * @return none
 */
 void clear_input();
#endif /* __REPORT_H__ */
