#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math.h"

void calculate_US_units(double height_cm, int& height_feet, double& height_inches){
    height_inches = height_cm * CM2IN;
    height_feet = int(height_inches / 12);
    height_inches = height_inches - height_feet * 12; 
}

double cel_to_far(double celsius){
    return celsius * double(9)/5 + 32;
}

double cel_to_k(double celsius){
    return celsius + 273; 
}

void print_range(int num1, int num2){
    printf("%d ",num1++);
    if(num1 <= num2){
        print_range(num1, num2); 
    } 
}

void print_bar_chart(int length){
    int i = 0;
    printf("%2d│",length); 
    for (i = 0; i <length; i++) {
        printf("▧");
    }
    printf("\n"); 
}

void generate_data_list(int *data_set, int size){
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        data_set[i] = rand() % 20;
    }
}

void print_data_list(int *data_set, int size){
    for (int i = 0; i < size; i++) {
        print_bar_chart(data_set[i]);
    }
}

user_loan get_lone_info(struct user_loan loan){
    printf("What is the principle loan amount?\n");
    scanf("%lf",&loan.loan_amount);

    printf("What is the interest rate?\n");
    scanf("%lf",&loan.interest_rate);

    printf("How many years?\n");
    scanf("%d",&loan.years);

    return loan;
}

user_loan calculate_loan_info(struct user_loan loan){
    double i = (loan.interest_rate/100.0)/12.0;
    int n = loan.years * 12;
    double discount = (pow(1+i,n)-1)/(i*pow(1+i,n));
    loan.monthly_payment = loan.loan_amount / discount;
    loan.loan_payment = loan.monthly_payment * n; 
    return loan;
}

void print_loan_info(struct user_loan loan){
    printf("Total monthly payment is $%.2lf\n",loan.monthly_payment);
    printf("Total loan payback is $%.2lf",loan.loan_payment);
}

void calculate_quardinate_value(struct degree_coordinate *input){
    if(input->circular_vaule == 90) {snprintf(input->quardinate_vaule, char_buffer_size,"E");}
    else if(input->circular_vaule == 180) {snprintf(input->quardinate_vaule, char_buffer_size,"S");}
    else if(input->circular_vaule == 270) {snprintf(input->quardinate_vaule, char_buffer_size,"W");}
    else if(input->circular_vaule == 0 || input->circular_vaule == 0) {
        snprintf(input->quardinate_vaule, char_buffer_size,"N");
    }


    else if(input->circular_vaule > 0 &&  input->circular_vaule < 90) {
        snprintf(input->quardinate_vaule, char_buffer_size,"N %.2lf° E",input->circular_vaule);
    }

    else if(input->circular_vaule > 90 &&  input->circular_vaule < 180) {
        snprintf(input->quardinate_vaule, char_buffer_size,"S %.2lf° E",180 - input->circular_vaule);
    }

    else if(input->circular_vaule > 180 &&  input->circular_vaule < 270) {
        snprintf(input->quardinate_vaule, char_buffer_size,"S %.2lf° W",input->circular_vaule - 180);
    }

    else if(input->circular_vaule > 270 &&  input->circular_vaule < 360) {
        snprintf(input->quardinate_vaule, char_buffer_size,"N %.2lf° W", 360 - input->circular_vaule);
    }

    else {
        printf("You must enter a value between 0 - 360°");
        exit(EXIT_FAILURE);
    }
}    
void print_coordinate(struct degree_coordinate *input){
    printf("%.2lf° in compass coordinates is %s.", input->circular_vaule, input->quardinate_vaule);
}
