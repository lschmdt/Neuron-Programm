#include "Network.hpp"

Network::Network(){
	//clear the vector before utilization
	network.clear();
	//complete the vector with new Neurons
	network.push_back(new Neuron());
	network.push_back(new Neuron());
	
	//choose the connexion randomly
	for(size_t i(0), i < connexions.size(), ++i){
		for(size_t j(0), j < connexions[i].size(), ++j){
			//le neurone ne peut pas se connecter à lui même
			if(i==j){
				connexions[i][j] == false;
			}
		}
	}
	connexions[0][1] = true;
	connexions[1][0] = false;
	
	
}

Network::~Network(){
	for (auto& elm : network){
		delete elm;
		elm = nullptr; 
	}
}
