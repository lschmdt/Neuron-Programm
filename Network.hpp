#pragma once

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <memory>
#include "Constant.hpp"
#include "Neuron.hpp"

class Network {
	public:
	Network();
	~Network();
	
	void update(double dt, double intensity);
	
	private:
	std::vector<Neuron*> network;
	std::vector<std::vector<int>> connexions;
};
