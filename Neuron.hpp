#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include "Constant.hpp"

enum Type{EXCITATORY, INHIBITORY};

class Neuron {
	public:
	Neuron(Type x);
	~Neuron();
	double getPotential() const;
	int getNumberSpikes() const;
	std::vector<double> getTime() const;
	bool getEtat() const;
	std::array<double,29> setBuffer(int i, double potential);
	
	void updateState(int time, double intensity);
	
	void ifSendingMessage(Neuron* n);
	bool isRefractory();
	
	//for the simulation
	void simulationLoopNeuron(int time_simul, int i_ext);

	private:
	bool etat;
	int clock;
	double refrac_time;
	double membrane_pot;
	int number_spikes; ///nombre de spikes fait dans l'intervalle donné
	std::vector<double> time_spikes; /// times when a Neuron spikes
	Type type; ///type is exitatory or inhibiory

	std::array<double,29> buffer;
};
