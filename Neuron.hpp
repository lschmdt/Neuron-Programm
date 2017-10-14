#pragma once

#include <iostream>
#include <cmath>
#include <list>
#include <array>
#include "Constant.hpp"


class Neuron {
	public:
	Neuron();
	~Neuron();
	double getPotential() const;
	int getNumberSpikes() const;
	std::list<double> getTime() const;
	bool getEtat();
	std::array<double,29> setBuffer(int i, double potential);
	
	void updateState(double dt, double intensity, Neuron n);
	
	bool isGettingMessage(Neuron n);
	void ifSendingMessage(Neuron n);
	
	private:
	bool etat;
	int clock;
	double refrac_time;
	double membrane_pot;
	int number_spikes;
	std::list<double> time_spikes;
	
	std::array<double,29> buffer;
};
