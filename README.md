# ELEC2645-project
An engineering calculator written in C language
It include two main functions: unit converter and basic circuit analyzer.

Unit converter:Support 8 types of unit conversions. kg/m^3 to g/cm^3, g/cm^3 to kg/m^3, kg to g, g to kg, Hz to rad/s, rad/s to Hz, Celsius to Kelvin, Kelvin to Celsius.

Basic circuit analyzer: Implement the following circuit calculate. 
1.Calculate the total resistance of the parallel circuit.
2.Calculate the total current of the parallel circuit.
3.Calculate the total resistance of the series circuit.
4.Calculate the total voltage of the series circuit.
5.Ohm's law
6.Calculate resistance power.
The input and output results will be saved in separate files, unit.txt and circuit.txt.


File structure:
Main menu:
main.c

Unit converter:
converter.h
converter.c

Basic circuit analyzer:
circuit.c
circuit.h

Run code:
You can build the code as we have been using in the labs with
gcc main.c converter.c circuit.c -o main.out -lm
(the -lm is required to link the math library).
You can also use make -B to force a rebuild using the provided Makefile.
Then run the code with ./main.out
