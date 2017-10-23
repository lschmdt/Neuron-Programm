#pragma once
#include <iostream>

double const TAU(20.0); 
double const R(20.0);
double const POTENTIEL_MAX(20); //seuil de potentiel de membrane
int const REFRAC_TIME(2); //temps refractaire
int const DT(1); //pas de temps
int const T_START(0); //temps de début de simulation
int const T_STOP(100); //temps de fin de simulation
double const POTENTIEL_RESET(0.0); //reset du potentiel de membrane
double const JE(0.1); //potential to add if a neuron receive a message from exitatory neuron
double const JI(0.5);//potential to add if a neuron receive a message from inhibitory neuron
double const DELAY(1.5); //delay for receinving the post-synaptic potential
int const G(5);
int const TETA(20);

double const REAL_TIME(0.1);
///double const REFRAC_STEP(REFRAC_TIME/DT); 
