#ifndef CIRCUIT_H
#define CIRCUIT_H

struct Parallel_R  {
    char name[40];
    double R1;
    double R2;
    double R_tol;
};

struct Parallel_I {
    char name[40];
    double I1;
    double I2;
    double I_tol;
};

struct Series_R {
    char name[40];
    double R1;
    double R2;
    double R_tol;
};

struct Series_U {
    char name[40];
    double U1;
    double U2;
    double U_tol;
};

struct Ohms_law {
    char name[40];
    double U;
    double I;
    double R;
};

struct Power{
    char name[40];
    double U;
    double I;
    double P;
};

double Parallel_R_tol(struct Parallel_R *p);
double Parallel_I_tol(struct Parallel_I *pi);
double Series_R_tol(struct Series_R *sr);
double Series_U_tol(struct Series_U *su);
double Ohms (struct Ohms_law *ol);
double Power_U_I(struct Power *po);
double check2();
#endif