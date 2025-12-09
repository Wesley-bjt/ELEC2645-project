#include <stdio.h>
#include <stdlib.h>
#include "converter.h"
#include "circuit.h"

void main_menu(void);
int  get_user_input(void);
void select_menu_item(int input);
void print_main_menu(void);
void select_unit_menu(int input2);
void go_back_to_main(void);
int  get_user_input2(void);
void print_unit_menu(void);
void print_circuit_menu(void);
void select_circuit_menu(int input2);
void print_parallel_menu(void);
void select_parallel_menu(int input3);
int  get_user_input3(void);
void print_series_menu(void);
void select_series_menu(int input3);
void go_back_to_circuit_menu(void);

int main(void) {
    main_menu();
    return 0;
}

void main_menu(void) {
    print_main_menu();
    int input = get_user_input();
    select_menu_item(input);
}

int get_user_input(void) {
    int input;
    printf("\nSelect item: ");
    scanf("%d", &input);  
    return input;
}

void select_menu_item(int input) {
    switch (input) {
        case 1: 
        print_unit_menu(); 
        int input2 = get_user_input2();
        select_unit_menu(input2); 
        break;
        
        case 2: 
        print_circuit_menu();
        input2 = get_user_input2();
        select_circuit_menu(input2);
        break;
        case 3: printf("Exiting program...\n"); exit(0);
        default: 
            printf("Invalid selection. Try again\n"); 
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            main_menu();
            break;
    }
}

void print_main_menu(void) {
    printf("\n----------- Main menu -----------\n");
    printf("|\t1. Unit converter\t|\n");
    printf("|\t2. Basic circuit analyser|\n");
    printf("|\t3. Exit\t\t\t|\n");
    printf("---------------------------------\n");
}

void go_back_to_main(void) {
    char input;
    do {
        printf("\nEnter 'b' to go back to main menu: ");
        scanf(" %c", &input);
    } while (input != 'b');
    main_menu();
}

int get_user_input2(void) {
    int input2;
    printf("\nSelect item: ");
    scanf("%d", &input2);  
    return input2;
}

void select_unit_menu(int input2) {
    switch (input2) {
        case 1: 
            kgm3_to_gcm3();
            go_back_to_main();
            break;
        
        case 2:
            gcm3_to_kgm3();
            go_back_to_main();
            break;
        
        case 3:
            kg_to_g();
            go_back_to_main();
            break;
        
        case 4:
            g_to_kg();
            go_back_to_main();
            break;
        
        case 5:
            Hz_to_rads();
            go_back_to_main();
            break;
        
        case 6:
            rads_to_Hz();
            go_back_to_main();
            break;
        
        case 7:
            Celsius_to_Kelvin();
            go_back_to_main();
            break;
            
        case 8: 
            Kelvin_to_Celsius();
            go_back_to_main();
            break;
            
        case 9: main_menu(); break;
        default: 
            printf("\nInvalid selection. Try again.\n"); 
            print_unit_menu();
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            int input2 = get_user_input2();
            select_unit_menu(input2);
            break;
            
           
    }
}

void print_unit_menu(void) {
    printf("\n----------- Unit converter -----------\n");
    printf("|\t1. kg/m^3 --> g/cm^3\t|\n");
    printf("|\t2. g/cm^3 --> kg/m^3\t|\n");
    printf("|\t3. kg --> g\t|\n");
    printf("|\t4. g --> kg\t|\n");
    printf("|\t5. Hz --> rad/s\t|\n");
    printf("|\t6. rad/s --> Hz\t|\n");
    printf("|\t7. Celsius --> Kelvin\t|\n");
    printf("|\t8. Kelvin --> Celsius\t|\n");
    printf("|\t9. Go back to main menu.\t|\n");
    printf("---------------------------------\n");
}

int get_user_input3(void) {
    int input3;
    printf("\nSelect item: ");
    scanf("%d", &input3);  
    return input3;
}

void select_circuit_menu(int input2) {
    struct Ohms_law ol;
    struct Power po;

    switch(input2) {
        case 1: 
           print_parallel_menu();
           int input3 = get_user_input3();
           select_parallel_menu(input3);
           break;
        case 2: 
            print_series_menu();
            input3 = get_user_input3();
            select_series_menu(input3);
            break;
        case 3: 
            Ohms(&ol);
            go_back_to_circuit_menu();
            break;
        case 4: 
            Power_U_I(&po);
            go_back_to_circuit_menu();
            break;
        case 5:main_menu(); break;
        default:
            printf("\nInvalid selection. Try again.\n"); 
            print_circuit_menu();
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            int input2 = get_user_input2();
            select_circuit_menu(input2);
            break;

    }
    
}

void print_circuit_menu(void){
    printf("\n---- Basic circuit analyzer -----\n");
    printf("|\t1. Parallel circuit\t|\n");
    printf("|\t2. Series circuit\t|\n");
    printf("|\t3. Ohm's law\t|\n");
    printf("|\t4. Resistance power\t|\n");
    printf("|\t5. Go back to main menu.|\n");
    printf("---------------------------------\n");
}

void select_parallel_menu(int input3) {
    struct Parallel_R p;
    struct Parallel_I pi;
    
    switch(input3) {
        case 1: 
            Parallel_R_tol(&p); 
            go_back_to_circuit_menu();
            break;

        case 2:
            Parallel_I_tol(&pi);
            go_back_to_circuit_menu();
            break;
        
        case 3: 
            print_circuit_menu();
            int input2 = get_user_input2();
            select_circuit_menu(input2);
            break;
        
        default:
            printf("\nInvalid selection. Try again.\n"); 
            print_parallel_menu();
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            int input3 = get_user_input3();
            select_parallel_menu(input3);
            break;

    }
}

void print_parallel_menu (void){
    printf("\n--------------- Parallel circuit ---------------\n");
    printf("|\t1. Calculate the total resistance.\t|\n");
    printf("|\t2. Calculate the total current.\t|\n");
    printf("|\t3. Go back to basic circuit analyzer.\t|\n");
    printf("------------------------------------------------\n");
}

void select_series_menu(int input3){
    struct Series_R sr;
    struct Series_U su;

    switch(input3){
        case 1:
            Series_R_tol(&sr);
            go_back_to_circuit_menu();
            break;

        case 2:
            Series_U_tol(&su);
            go_back_to_circuit_menu();
            break;

        case 3:
            print_circuit_menu();
            int input2 = get_user_input2();
            select_circuit_menu(input2);
            break;

        default:
            printf("\nInvalid selection. Try again.\n"); 
            print_series_menu();
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            int input3 = get_user_input3();
            select_circuit_menu(input3);
            break;

    }
}

void print_series_menu(void) {
    printf("\n---------------- Series circuit ----------------\n");
    printf("|\t1. Calculate the total resistance.\t|\n");
    printf("|\t2. Calculate the total voltage.\t|\n");
    printf("|\t3. Go back to basic circuit analyzer.\t|\n");
    printf("------------------------------------------------\n");
}

void go_back_to_circuit_menu(void) {
    char input;
    do {
        printf("\nEnter 'b' to go back to basic circuit analyzer menu: ");
        scanf(" %c", &input);
    } while (input != 'b');
    print_circuit_menu();
    int input2 = get_user_input2();
    select_circuit_menu(input2);
}