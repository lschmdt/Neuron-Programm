#include "Network.hpp"

Network::Network(){
	//clear the vector before utilization
	network.clear();
	
	//complete the vector with new Neurons
	for(int i(0); i < 10000; ++i){
		network.push_back(new Neuron(EXCITATORY));
	}
	
	for(int i(0); i < 2500; ++i){
		network.push_back(new Neuron(INHIBITORY));
	}
	
	///network.push_back(new Neuron());
	///network.push_back(new Neuron());
	for(size_t i(0); i < connexions.size(); ++i){
		connexions[i].clear();
	}
	
	//choose the connexion randomly
	for(size_t i(0); i < network.size(); ++i){
		for(size_t j(0); j < network.size(); ++j){
			//Neuron can't connect itself
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

void Network::update(double dt, double intensity){
	
	for(size_t i(0); i < connexions.size(); ++i){
		for(size_t j(0); j< connexions[i].size(); ++j){
			if(connexions[i][j] == 1){
				network[j]->ifSendingMessage(network[i]);
		}
		network[i]->updateState(dt,intensity);
		}
	}
}
		
