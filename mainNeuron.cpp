 #include "Neuron.hpp"
#include "Network.hpp"
#include <fstream>
#include <string>


int main(int argc, char **argv)
{
	Network n;
	double t(T_START);
	
	//choix de l'intensité + vérification que celle ci est positive
	double intensity;
	do{
		std::cout << "Give an intensity : ";
		std::cin >> intensity;
		std::cout << std::endl;
	}while(intensity < 0 );
	
	//donner l'intervalle de temps durant lequel l'intensité va etre non nulle
	std::cout << "Give a time interval." << std::endl ;
	double a;
	double b;
	do{
		std::cout << " The lower : " ;
		std::cin >> a;
		std::cout << " and the upper one : ";
		std::cin >> b;
	}while(a< T_START and a>b and b>T_STOP);

	/**on déclare un fichier pour pouvoir noter nos potentiels dedans
	std::ofstream fichier;
	std::string nom_de_fichier("potential_1.dat");
	fichier.open(nom_de_fichier.c_str());
	*/
	//on met à jour le potentiel tous les dt suivant l'intervalle de temps
	//dans lequel il se trouve
	while ( t < T_STOP){

		if ( t < a or t>=b) { 
			n.update(DT, 0.0);
		}
		else if ( t >= a and t < b) {
			n.update(DT, intensity);
		}
		//fichier << "V(" << t << ") = " << n1.getPotential() << std::endl;
		//fichier << "V(" << t << ") = " << n2.getPotential() << std::endl;

		t += DT;
	}
	//fichier.close();
	
	return 0;
}
