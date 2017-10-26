#include "Neuron.hpp"
/**Neuron's constructor
 */
Neuron::Neuron(Type x) : etat(false), buffer({0}), type(x)

{
	time_spikes.clear();
	number_spikes = 0;
}
/** Neuron's destructor
 */
Neuron::~Neuron() {}

/** getter
 * @return le potentiel de la membrane
 */
double Neuron::getPotential() const
{ 
	return membrane_pot; 
}

/** getter
 * @return le nombre de spike
 */
int Neuron::getNumberSpikes() const
{ 
	return number_spikes; 
}

/**
 * @return retourne le temps
 */
std::list<double> Neuron::getTime() const
{ 
	return time_spikes; 
}

/**setter du buffer
 * @param a number i for the index of the vector ad the potential
 */
std::array<double,29> Neuron::setBuffer(int i, double potential){
	buffer[i] += potential;
}

/**
 * @return si le neuron spike ou non
 */
bool Neuron::getEtat() const{
	return etat;
}

/**update the potential of the neuron. It controls if it is refractory 
 * or not and if it reachs a spike potential or not.
 * @param dt is the time interval, intensity is the external intensity
 */
void Neuron::updateState(double dt, double intensity){ 
	
	//si c'est dans le temps réfractaire
	if (refrac_time >= 0)
	{
		membrane_pot = 0.0;
		refrac_time -= dt;
		return;
	}
	
	
	//calcul de la membrane en général
	membrane_pot = exp(-dt/TAU)*membrane_pot + intensity*R*(1-exp(-dt/TAU));
	
	/*si le buffer de son pas de temps clock contient un potentiel 
	car il a recu un message d'un autre synapse
	rajouter la constante J a son potentiel*/
	if (buffer[clock%(int)buffer.size()] != 0){
		membrane_pot += buffer[clock%(int)buffer.size()];
		buffer[clock%(int)buffer.size()] = 0;
	}
	
	//si la membrane a un potentiel trop élevé
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

/*change le buffer du Neuron en paramètre pour qu'il recoive le spike à
un temps clock + delay on rajoute donc le potentiel post synaptic a son buffer
*/
void Neuron::ifSendingMessage(Neuron* n){
	int J;
	if (getEtat() == true){
		if(type == EXCITATORY){
			J=JE;
		}else{
			J=JI;
		}
		n->setBuffer(((int)(clock + (DELAY/REAL_TIME))%(int)buffer.size()), J);
	}
}
	
	
	
	
	
	
	
	
