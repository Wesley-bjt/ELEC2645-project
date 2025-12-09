#include "converter.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

double  kgm3_to_gcm3(){
    FILE *output = fopen("unit.txt", "w");
    double kgm3;
    printf("\nPlease enter density (kg/m^3):");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    kgm3 = check();
    fprintf(output, "%lfkg/m^3\n", kgm3);
    if(kgm3 < 0) {
        printf("\nERROR!!! The input error density cannot be less than 0.");
        fprintf(output,"ERROR!!! The input error density cannot be less than 0.");
        fclose(output);
        return -1;
    } else{
        double gcm3 = kgm3 * 1000 / 1000000 ;
        printf("\nDensity is :%lf g/cm^3",gcm3);    
        fprintf(output, "%lfg/cm^3\n", gcm3); 
        fclose(output);
        return gcm3;
    }
    
}

double  gcm3_to_kgm3(){
    FILE *output = fopen("unit.txt", "w");
    double gcm3;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\nPlease enter density (kg/m^3):");
    gcm3 = check();
    fprintf(output, "%lfg/cm^3\n", gcm3); 
    if(gcm3 < 0) {
        printf("\nERROR!!! The input error density cannot be less than 0.");
        fprintf(output,"ERROR!!! The input error density cannot be less than 0.");
        fclose(output);
        return -1;
    } else{
        double kgm3 = gcm3 * 0.001 / 0.000001 ;
        printf("\nDensity is :%lfkg/m^3",kgm3);
        fprintf(output, "%lfkg/m^3\n", kgm3);
        fclose(output);
        return kgm3;
    }
}

double  kg_to_g() {
    FILE *output = fopen("unit.txt", "w");
    double kg;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\nPlease enter mass (kg):");
    kg = check();
    fprintf(output, "%lfkg\n", kg); 
    if(kg < 0) {
        printf("\nERROR!!! The input error mass cannot be less than 0.");
        fprintf(output,"ERROR!!! The input error mass cannot be less than 0.");
        fclose(output);
        return -1;
    } else{
        double g = kg * 1000;
        printf("\nMass is :%lf g",g);
        fprintf(output, "%lfg\n", g); 
        fclose(output);
        return g;
    }
}

double  g_to_kg(){
    FILE *output = fopen("unit.txt", "w");
    double g;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\nPlease enter mass (g):");
    g = check();
    fprintf(output, "%lfg\n", g); 
    if(g < 0) {
        printf("\nERROR!!! The input error mass cannot be less than 0.");
        fprintf(output,"ERROR!!! The input error mass cannot be less than 0.");
        fclose(output);
        return -1;
    } else{
        double kg = g *  0.001 ;
        printf("\nMass is :%lfkg/cm^3",kg);
        fprintf(output, "%lfkg\n", kg); 
        fclose(output);
        return kg;
    }
}

double  Hz_to_rads(){
    FILE *output = fopen("unit.txt", "w");
    double Hz;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\nPlease enter frequency (Hz):");
    Hz = check();
    fprintf(output, "%lfHz\n", Hz); 
    if(Hz < 0) {
        printf("\nERROR!!! The input error frequency cannot be less than 0.");
        fprintf(output,"ERROR!!! The input error frequency cannot be less than 0.");
        fclose(output);
        return -1;
    } else{
        double rads = Hz * 2 * PI ;
        printf("\nAngular velocity is :%lf rad/s",rads);
        fprintf(output, "%lfrad/s\n", rads); 
        fclose(output);
        return rads;
    }
}

double  rads_to_Hz(){
    FILE *output = fopen("unit.txt", "w");
    double rads;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\nPlease enter Angular velocity (rad/s):");
    rads = check();
    fprintf(output, "%lfrad/s\n", rads); 
    double Hz = fabs(rads) / (2 * PI) ;                                                               //"fabs," cppreference.com. https://en.cppreference.com/w/c/numeric/math/fabs (accessed Nov. 26, 2025).
    printf("\nFrequency is:%lf Hz",Hz);
    fprintf(output, "%lfHz\n", Hz); 
    fclose(output);
    return Hz;
}

double  Celsius_to_Kelvin(){
    FILE *output = fopen("unit.txt", "w");
    double Celsius;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\nPlease enter Celsius (℃):");
    Celsius = check();
    fprintf(output, "%lf℃\n", Celsius); 
    if(Celsius < -273) {
        printf("\nERROR!!! The input error celsius cannot be less than -273.");
        fprintf(output,"ERROR!!! The input error celsius cannot be less than -273");
        fclose(output);
        return -1;
    } else {
        double Kelvin = Celsius + 273;
        printf("\nKelvin is:%lf K",Kelvin);
        fprintf(output, "%lfK\n", Kelvin); 
        fclose(output);
        return Kelvin;
    }
}

double Kelvin_to_Celsius(){
    FILE *output = fopen("unit.txt", "w");
    double  Kelvin;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\nPlease enter Kelvin (K):");
    Kelvin = check();
    fprintf(output, "%lfK\n", Kelvin); 
    if(Kelvin < 0) {
        printf("\nERROR!!! The input error kelvin cannot be less than 0.");
        fprintf(output,"ERROR!!! The input error kelvin cannot be less than 0.");
        fclose(output);
        return -1;
    } else {
        double Celsius = Kelvin - 273;
        printf("\nCelsius is :%lf ℃  " , Celsius ) ;
        fprintf(output, "%lf℃\n", Celsius);
        fclose(output);
        return  Celsius;
    }
    
}

double check() {
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