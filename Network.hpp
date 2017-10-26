#pragma once

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <memory>
#include <random>
#include "Constant.hpp"
#include "Neuron.hpp"

class Network {
	public:
	Network();
	~Network();
	
	void update(double dt, double intensity);
	
	void chooseRandomly(int a, int b, int connexion);
	
	private:
	std::vector<Neuron*> network;
	std::vector<std::vector<int>> connexions;
	std::array<bool, 12500> is_choosen;
};
