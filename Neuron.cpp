#include "Neuron.hpp"

Neuron::Neuron() : etat(false)
{
	time_spikes.clear();
	number_spikes = 0;
}

double Neuron::getPotential() const
{ 
	return membrane_pot; 
}

//retourne le nombre de spike
int Neuron::getNumberSpikes() const
{ 
	return number_spikes; 
}

//retourne le temps
std::list<double> Neuron::getTime() const
{ 
	return time_spikes; 
}

//retourne si le neuron spike or not
bool Neuron::getEtat(){
	return etat;
}

void Neuron::updateState(double dt, double intensity, Neuron n){ 
	
	//si c'est dans le temps réfractaire
	if (refrac_time >= 0)
	{
		membrane_pot = 0.0;
		refrac_time -= dt;
		return;
	}

	//calcul de la membrane en général
	membrane_pot = exp(-dt/TAU)*membrane_pot + intensity*R*(1-exp(-dt/TAU));
	
	if (isGettingMessage(n)){
		membrane_pot += J;
	}
	
	//si la membrane à un potentiel trop élevé
	if(membrane_pot >= POTENTIEL_MAX){
		membrane_pot = POTENTIEL_RESET;
		time_spikes.push_back(clock);
		++number_spikes;
		
		refrac_time = REFRAC_TIME;
		etat = true;
		return;
	}	
	
	clock += dt;
	etat = false;
	
}

bool Neuron::isGettingMessage(Neuron n){
	if (n.getEtat() == true){
		return true;
	}else{
		return false;
	}
		
}


