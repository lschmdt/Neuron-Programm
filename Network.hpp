#pragma once

#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <list>
#include <memory>
#include <random>
#include "Constant.hpp"
#include "Neuron.hpp"

class Network {
	public:
	Network();
	~Network();
	
	int nbConnexion();
	void createConnexions();
	
	void update(int time, double intensity);
	
	std::vector<int> chooseRandomly(int a, int b, int connexion, int x);
	//std::vector<Neuron*> chooseRandomly(int a, int b, int connexion, int x);

	void simulationLoopNetwork(int time, int i_ext);
	
	private:
	std::vector<Neuron*> network; //!< neurons that are on the network
};
