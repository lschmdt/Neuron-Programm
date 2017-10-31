#include "Neuron.hpp"

double Neuron::getPotential(){ return membrane_pot; }
int Neuron::getNumberSpikes(){ return number_spikes; }
std::list <double> Neuron::getTime(){ return time_spikes; }

void Neuron::updateState(double dt, double intensity){ 
	membrane_pot = exp(-dt/TAU)*membrane_pot + intensity*R*(1-exp(-dt/TAU));
}
