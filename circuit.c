#include "circuit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

double Parallel_R_tol(struct Parallel_R *p) {
    FILE *output = fopen("circuit.txt", "w");
    strncpy(p->name, "The values of each resistor in a basic parallel circuit.", sizeof(p->name) - 1);
    p->name[sizeof(p->name) - 1] = '\0';
    fprintf(output, "%s\n", p->name);
    printf("\nPlease enter the value of resistor R1 (Ohm):");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    p->R1 = check2();
    fprintf(output, "R1: %lfOhm\n", p->R1);
    printf("\nPlease enter the value of resistor R2 (Ohm):");
    p->R2 = check2();
    fprintf(output, "R2: %lfOhm\n", p->R2);
    if(p->R1 <= 0 || p->R2 <=0){
        printf("\nERROR!!!In a basic parallel circuit that operates normally, the resistance must be greater than 0 Ohm.");
        fprintf(output,"The circuit is unable to operate correctly; R_tol does not output.");
        fclose(output);
        return -1;
    } else {
        p->R_tol = (p->R1 * p->R2) / (p->R1 + p->R2);
        printf("\nThe value of R_tol is: %lfOhm.", p->R_tol);
        fprintf(output, "R_tol: %lfOhm\n", p->R_tol);
        fclose(output);
        return p->R_tol;
    }
}

double Parallel_I_tol(struct Parallel_I *pi) {
    FILE *output = fopen("circuit.txt", "w");
    strncpy(pi->name, "The values of each current in a basic parallel circuit.", sizeof(pi->name) - 1);
    pi->name[sizeof(pi->name) - 1] = '\0';
    fprintf(output, "%s\n", pi->name);
    printf("\nPlease enter the value of current I1 (A):");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    pi->I1 = check2();
    fprintf(output, "I1: %lfA\n", pi->I1);
    printf("\nPlease enter the value of current I2 (A):");
    pi->I2 = check2();
    fprintf(output, "I2: %lfA\n", pi->I2);
    if(pi->I1 <= 0 || pi->I2 <= 0){
        printf("\nERROR!!!In a basic parallel circuit that operates normally, the current must be greater than 0 A.");
        fprintf(output,"The circuit is unable to operate correctly; I_tol does not output.");
        fclose(output);
        return -1;
    } else {   
        pi->I_tol = pi->I1 + pi->I2;
        printf("\nThe value of I_tol is: %lf A.", pi->I_tol);
        fprintf(output, "I_tol: %lfA\n", pi->I_tol);
        fclose(output);
        return pi->I_tol;   
    }
}

double Series_R_tol(struct Series_R *sr) {
    FILE *output = fopen("circuit.txt", "w");
    strncpy(sr->name, "The values of each resistor in a basic series circuit.", sizeof(sr->name) - 1);
    sr->name[sizeof(sr->name) - 1] = '\0';
    fprintf(output, "%s\n", sr->name);
    printf("\nPlease enter the value of resistor R1 (Ohm):");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    sr->R1 = check2();
    fprintf(output, "R1: %lfOhm\n", sr->R1);
    printf("\nPlease enter the value of resistor R2 (Ohm):");
    sr->R2 = check2();
    fprintf(output, "R2: %lfOhm\n", sr->R2);
    if(sr->R1 <= 0 || sr->R2 <=0){
        printf("\nERROR!!!In a basic series circuit that operates normally, the resistance must be greater than 0 Ohm.");
        fprintf(output,"The circuit is unable to operate correctly; R_tol does not output.");
        fclose(output);
        return -1;
    } else {
        sr->R_tol = sr->R1 + sr->R2;
        printf("\nThe value of R_tol is: %lf Ohm.", sr->R_tol);
        fprintf(output, "R_tol: %lfOhm\n", sr->R_tol);
        fclose(output);
        return sr->R_tol;
    }
}

double Series_U_tol(struct Series_U *su){
    FILE *output = fopen("circuit.txt", "w");
    strncpy(su->name, "The values of each voltage in a basic series circuit.", sizeof(su->name) - 1);
    su->name[sizeof(su->name) - 1] = '\0';
    fprintf(output, "%s\n", su->name);
    printf("\nPlease enter the value of voltage U1 (V):");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    su->U1 = check2();
    fprintf(output, "U1: %lfV\n", su->U1);
    printf("\nPlease enter the value of voltage U2 (V):");
    su->U2 = check2();
    fprintf(output, "U2: %lfV\n", su->U2);
    if(su->U1 <= 0 || su->U2 <= 0){
        printf("\nERROR!!!In a basic series circuit that operates normally, the voltage must be greater than 0 V.");
        fprintf(output,"The circuit is unable to operate correctly; U_tol does not output.");
        fclose(output);
        return -1;
    } else {
        su->U_tol = su->U1 + su->U2;
        printf("\nThe value of U_tol is: %lf V.", su->U_tol);
        fprintf(output, "U_tol: %lfV\n", su->U_tol);
        fclose(output);
        return su->U_tol;   
    }
}  

double Ohms (struct Ohms_law *ol) {
    FILE *output = fopen("circuit.txt", "w");
    strncpy(ol->name, "The value of three elements(U, I, R) in Ohm's law.", sizeof(ol->name) - 1);
    ol->name[sizeof(ol->name) - 1] = '\0';
    fprintf(output, "%s\n", ol->name);
    printf("\nPlease enter the value of voltage U (V):");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    ol->U = check2();
    fprintf(output, "U: %lfV\n", ol->U);
    printf("\nPlease enter the value of current I (A):");
    ol->I = check2();
    fprintf(output, "I: %lfA\n", ol->I);
    if (ol->U == 0 && ol->I != 0) {
        printf("\nShort circuit!!! Resistance is 0 Ohm.");
        fprintf(output,"Short circuit!!! Resistance is 0 Ohm.");
        fclose(output);
        return -1;
    }
    if (ol->I == 0 && ol->U != 0){
        printf("\nOpen circuit!!! Resistance is infinite");
        fprintf(output,"Open circuit!!! Resistance is infinite.");
        fclose(output);
        return -1;
    }
    if (ol->I == 0 && ol->U == 0) {
        printf("\nVoltage and current cannot be both 0 in the normally operating circuit.");
        fprintf(output,"Voltage and current cannot be both 0 in the normally operating circuit.");
        fclose(output);
        return -1;
    }
    ol->R = fabs(ol->U) / fabs(ol->I);                                                               //"fabs," cppreference.com. https://en.cppreference.com/w/c/numeric/math/fabs (accessed Nov. 26, 2025).
    printf("\nThe value of resistance is: %lf Ohm.",ol->R);
    fprintf(output, "R: %lfOhm\n", ol->R);
    fclose(output);
    return ol->R;
}

double Power_U_I(struct Power *po){
    FILE *output = fopen("circuit.txt", "w");
    strncpy(po->name, "The value of three elements(U, I, P) in power formula.", sizeof(po->name) - 1);
    po->name[sizeof(po->name) - 1] = '\0';
    fprintf(output, "%s\n", po->name);
    printf("\nPlease enter the value of voltage U (V):");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    po->U= check2();
    fprintf(output, "U: %lfV\n", po->U);
    printf("\nPlease enter the value of current I (A):");
    po->I = check2();
    fprintf(output, "I: %lfA\n", po->I);
    po->P = po->U * po->I;
    printf("\nThe value of power is: %lf W.",po->P);
    fprintf(output, "P: %lfW\n", po->P);
    fclose(output);
    return po->P;
}
    
double check2() {
    char input[20];
    int right;
    do {
        right = 1;  
        fgets(input, sizeof(input), stdin);
        if (strlen(input) - 1 == 0) {  
            right = 0;
        } 
        for (int i = 0; i < strlen(input); i++) {
            if(isalpha(input[i])!=0){
              right = 0;
            }
        }
        if (!right) {
            printf("\nInvalid input, please enter a number: ");
        }
    } while (!right);

    return atof(input);  
}
