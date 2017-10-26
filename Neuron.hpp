#pragma once

#include <iostream>
#include <cmath>
#include <list>
#include <array>
#include "Constant.hpp"

enum Type{EXCITATORY, INHIBITORY};

class Neuron {
	public:
	Neuron(Type x);
	~Neuron();
	double getPotential() const;
	int getNumberSpikes() const;
	std::list<double> getTime() const;
	bool getEtat() const;
	std::array<double,29> setBuffer(int i, double potential);
	
	void updateState(double dt, double intensity);
	
	bool isGettingMessage(Neuron n);
	void ifSendingMessage(Neuron* n);

	private:
	bool etat;
	int clock;
	double refrac_time;
	double membrane_pot;
	int number_spikes; ///nombre de spikes fait dans l'intervalle donné
	std::list<double> time_spikes; /// times when a Neuron spikes
	Type type; ///type is exitatory or inhibiory

	std::array<double,29> buffer;
};
