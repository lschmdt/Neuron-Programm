#pragma once

#include <iostream>
#include <cmath>
#include <list>

double const TAU(20);
double const R(1.0);

class Neuron {
	public:
	
	double getPotential();
	int getNumberSpikes();
	std::list<double> getTime();
	
	void updateState(double dt, double intensity);
	
	
	private:
	
	double membrane_pot;
	int number_spikes;
	std::list<double> time_spikes;
};
