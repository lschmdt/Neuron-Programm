#include "Neuron.hpp"
#include "Network.hpp"
#include "gtest/include/gtest/gtest.h"
#include <iostream>
#include <cmath>

TEST (NeuronTest, MembranePotential){
	Neuron neuron1(EXCITATORY);
	Neuron neuron2(EXCITATORY);
	Neuron neuron3(EXCITATORY);
	
	/*neuron.updateState(1868, 1.01);
	EXPECT_EQ(neuron.getPotential(), 0.0);
	* spikes : 924, 1868*/
	
	neuron1.simulationLoopNeuron(921, 1.01);
	EXPECT_NEAR(neuron1.getPotential(), 20, 1);
	
	neuron2.simulationLoopNeuron(0, 1.01);
	EXPECT_NEAR(neuron2.getPotential(),0, 1);
	
	neuron3.simulationLoopNeuron(925, 1.01);
	EXPECT_NEAR(neuron3.getPotential(), 0, 1);
	
}

TEST(NeuronTest, RefractoryTest){
	Neuron neuron(EXCITATORY);
	if(neuron.getEtat()==true){
		EXPECT_EQ(neuron.getPotential(), 0.0);
	}
}

TEST(NeuronTest, NumberSpike){
	Neuron neuron(EXCITATORY);
	neuron.simulationLoopNeuron(1000, 1.01);
	EXPECT_EQ(neuron.getNumberSpikes(), 1);
}

TEST(NetworkTest, NumberConnexions){
	Network n;
	EXPECT_EQ(n.nbConnexion(), 1250*12500);
}
	

int main(int argc, char**argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
