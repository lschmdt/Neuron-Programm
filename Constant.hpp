#pragma once
#include <iostream>

double const TAU(20.0); 
double const R(20.0);
double const POTENTIEL_MAX(20); //seuil de potentiel de membrane
int const REFRAC_TIME(2); //temps refractaire
double const DT(1); //pas de temps
int const T_START(0); //temps de début de simulation
int const T_STOP(100); //temps de fin de simulation
double const POTENTIEL_RESET(0.0); //reset du potentiel de membrane
double const J(10.0); //potentiel qu'un neurone recoit par signal
//double const REAL_TIME(0.1);
//double const REFRAC_STEP(REFRAC_TIME/DT); 
