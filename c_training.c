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
    }
    printf("%s\n",argv[1]);
    double x = 0;
    sscanf(argv[1],"%lf",&x);
    printf("%s\n", argv[2]);
    struct degree_coordinate input;
//    printf("Enter an angle between 0 - 360:\n");
//    scans("%lf",&input.circular_vaule);
    input.circular_vaule = x;
    calculate_quardinate_value(&input);
    print_coordinate(&input);
    return EXIT_SUCCESS;
}
