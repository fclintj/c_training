/*
 *
 *  Program Practice in C  
 *  
 *    Reading input, printing text, writing function. Projects include:
 *    Compass calculator, financial calculator, bar charts, recursive functions,
 *    struts, centimeters to feet/inches, and Celsius to Fahrenheit. 
 *   
 *  Author: Clint Ferrin
 *
 */
#include "functions.h"
#include <string.h>
#include <ctype.h>
      
int main (int argc, char *argv[]){
    if(argc == 1){
        printf("zero arguments.\n");
        return -1; 
    }
    double x;
    sscanf(argv[1],"%lf",&x);
    struct degree_coordinate input;
    input.circular_vaule = x;
    calculate_quardinate_value(&input);
    print_coordinate(&input);
    return EXIT_SUCCESS;
}
