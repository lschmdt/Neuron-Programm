#pragma once

#include <iostream>
#include <cmath>
#include <list>
#include "Constant.hpp"


class Neuron {
	public:
	Neuron();
	double getPotential() const;
	int getNumberSpikes() const;
	std::list<double> getTime() const;
	bool getEtat();
	
	void updateState(double dt, double intensity, Neuron n);
	
	bool isGettingMessage(Neuron n);
	
	private:
	bool etat;
	double clock;
	double refrac_time;
	double membrane_pot;
	int number_spikes;
	std::list<double> time_spikes;
};
