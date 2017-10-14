#pragma once

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include "Constant.hpp"
#include "Neuron.hpp"

class Network {
	public:
	Network();
	~Network();
	
	private:
	std::vector<Neuron*> network;
	std::vector<vector<int>> connexions;
};
