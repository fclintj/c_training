#include <stdio.h>
#include <stdlib.h>

#ifndef MYLIBRARY_H
#define MYLIBRARY_H

#define CM2IN 0.3937007874;
#define CEL2FAR
#define CEL2K
#define char_buffer_size 20


struct user_loan {
    double loan_amount;
    int years;
    double interest_rate;
    double monthly_payment;
    double loan_payment;
};

struct degree_coordinate {
    double circular_vaule;
    char quardinate_vaule[char_buffer_size];
    int quardinate;    
    //          0°
    //          │  
    //       4  │  1
    // 270°─────┼─────90°
    //       3  │  2
    //          │   
    //         180°
};

void calculate_US_units(double height_cm, int& height_feet, double& height_inches);
double cel_to_far(double celsius);
double cel_to_k(double celsius);
void print_range(int num1, int num2);
void print_bar_chart(int length);
void generate_data_list(int *data_set, int size);
void print_data_list(int *data_set, int size);
user_loan get_lone_info(struct user_loan loan);
user_loan calculate_loan_info(struct user_loan loan);
void print_loan_info(struct user_loan loan);
void calculate_quardinate_value(struct degree_coordinate *input);
void print_coordinate(struct degree_coordinate *input);
#endif /* end of include guard: MYLIBRARY_H */
