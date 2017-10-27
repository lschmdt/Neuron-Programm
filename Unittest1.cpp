#include "Neuron.hpp"
#include "gtest/include/gtest/gtest.h"
#include <iostream>
#include <cmath>

TEST (NeuronTest, MembranePotential){
	Neuron neuron1(EXCITATORY);
	Neuron neuron2(EXCITATORY);
	Neuron neuron3(EXCITATORY);
	
	/*neuron.updateState(1868, 1.01);
	EXPECT_EQ(neuron.getPotential(), 0.0);*/
	
	neuron1.simulationLoopNeuron(924, 1.01);
	EXPECT_NEAR(neuron1.getPotential(), 20, 1);
	
	neuron2.simulationLoopNeuron(0, 1.01);
	EXPECT_EQ(neuron2.getPotential(),0);
	
	neuron3.simulationLoopNeuron(925, 1.01);
	EXPECT_EQ(neuron3.getPotential(), 0);
	
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


int main(int argc, char**argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
