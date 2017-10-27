#include "Network.hpp"

Network::Network(){
	//clear the vector before utilization
	for(auto& elm : network){
		delete elm;
		elm = nullptr; 
	}
	
	//complete the vector with new Neurons
	for(int i(0); i < 10000; ++i){
		network.push_back(new Neuron(EXCITATORY));
	}
	
	for(int i(0); i < 2500; ++i){
		network.push_back(new Neuron(INHIBITORY));
	}
	
	for(size_t i(0); i < connexions.size(); ++i){
		connexions[i].clear();
	}

	//choose the connexion randomly
	for(size_t i(0); i < network.size(); ++i){
		for(size_t j(0); j < network.size(); ++j){
			chooseRandomly(0,10000,CE);
			chooseRandomly(10000,12500,CI);
			for(int z(0); z < 12500; ++z){
				if (is_choosen[z] == true){
					connexions[i][z] = true;
				}else{
					connexions[i][z] = false;
				}
			
			}
			is_choosen.empty();
			
			//Neuron can't connect itself
			if(i==j){
				connexions[i][j] = false;
			}
			
			std::cout << connexions[i][j] << "   ";
		}
		std::cout << std::endl;
	}
	
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
 * @param dt le parametre de temps and the intensitsy of the current
 */
void Network::update(int time, double intensity){
	
	for(size_t i(0); i < connexions.size(); ++i){
		for(size_t j(0); j< connexions[i].size(); ++j){
			if(connexions[i][j] == 1){
				network[j]->ifSendingMessage(network[i]);
		}
		network[i]->updateState(time,intensity);
		}
	}
}
		
void Network::chooseRandomly(int a, int b, int connexion){
	std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dis(a, b);
	int i(0);
	
	do{
        if(is_choosen[dis(gen)] == false){
		   is_choosen[dis(gen)] = 1;
		   ++i;
		   std::random_device rd;  
		   std::mt19937 gen(rd());  
		}	
	} while (i < connexion);
   
}


