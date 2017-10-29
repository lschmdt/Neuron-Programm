#include "Network.hpp"
/** constructor of Network class
 */
Network::Network(){
	//clear the vector before utilization
	for(auto& elm : network){
		delete elm;
		elm = nullptr; 
	}
	

	//complete the vector with new Neurons
	for(int i(0); i < NE; ++i){
		network.push_back(new Neuron(EXCITATORY));
	}
	
	for(int i(0); i < NI; ++i){
		network.push_back(new Neuron(INHIBITORY));
	}

	createConnexions();
	
}
/** destructor of Network class
 */

Network::~Network(){
	for (auto& elm : network){
		delete elm;
		elm = nullptr; 
	}
}

/**
 * This method updates our network
 * @param time : time of the simulation 
 * @param intensity : the external intensitsy of the current
 */
void Network::update(int time, double intensity){
	//We need to update the network by updating all the Neurons 
	//and control that they are connected or not
	std::vector<int> connexions;
	for(auto neuron : network){
		connexions = neuron->getTarget();
		for(auto connect : connexions){
			neuron->ifSendingMessage(network[connect]);
		}
	}
}
	
	/*for(size_t i(0); i < connexions.size(); ++i){
		for(size_t j(0); j< connexions[i].size(); ++j){
			if(connexions[i][j] == 1){
				network[j]->ifSendingMessage(network[i]);
		}
		network[i]->updateState(time,intensity);
		}
	}*/


/** 
 * to choose random numbers (connexion number) between two borns without taking himself 
 * to prevent the same neuron two be connect with himself
 * @param a : lowest born
 * @param b : greatest born
 * @param connexion : number of random numbers wanted
 * @param x : number of the neuron to prevent to be connect with himself
 * @return a vector<int> with all the choosen random numbers
 */ 
std::vector<int> Network::chooseRandomly(int a, int b, int connexion, int x){
	std::default_random_engine randomGenerator; 
    std::uniform_int_distribution<int> disNeuron(a, b);
    std::vector<int> connect;
    connect.clear(); //make sure ther is nothing inside
	int i(0);
	do{
		int aleatory(0);
		aleatory = disNeuron(randomGenerator);
		if(aleatory != x){
			connect.push_back(aleatory);
			++i;
		}
	} while (i < connexion);
	
	return connect;
   
}
/**
@return the number of connexions there are in all our Network
 */
int Network::nbConnexion(){
	int c;
	for (size_t i(0); i< network.size(); ++i){
				c += (int)network[i]->getTarget().size();
	}
	return c;
}

void simulationLoopNetwork(int time, int i_ext){
}

/**
 * this function create exactly CE and CI connexions for all Neurons.
 * It add targets in the vector of all the Neurons
 */
void Network::createConnexions(){
	std::vector<int> a;
	for(size_t i(0); i < network.size(); ++i){
		a = chooseRandomly(0,NE,CE,i);
		for (auto elm : a){
			network[i]->addTarget(elm);
		}
		a.clear();
		a=chooseRandomly(0+NE,NE+NI, CI, i);
		for(auto elm : a){
			network[i]->addTarget(elm);
		}
		a.clear();
	}
}

