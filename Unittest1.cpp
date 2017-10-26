#include "Neuron.hpp"
#include "gtest/include/gtest/gtest.h"
#include <iostream>
#include <cmath>

TEST (NeuronTest, MembranePotential){
	Neuron neuron(EXCITATORY);
	neuron.updateState(1, 1.01);
	EXPECT_EQ(neuron.getPotential(), 0.0);
	
	neuron.updateState(56, 1.01);
	EXPECT_NEAR(neuron.getPotential(), 18, 3);
	//std::cout << neuron.getPotential() << " potential" << std::endl;
	
	neuron.updateState(924, 1.01);
	EXPECT_EQ(neuron.getPotential(), 0);

}

TEST(NeuronTest, SpikesTest){
	Neuron neuron(EXCITATORY);
	if(neuron.getEtat()==true){
		EXPECT_EQ(neuron.getPotential(), 0.0);
	}
}

TEST(NeuronTest, NumberSpike){
	Neuron neuron(EXCITATORY);
	for(int i(0); i < 50;++i){
		neuron.updateState(i, 1.01);
	}
	EXPECT_EQ(neuron.getNumberSpikes(), 1);
}


int main(int argc, char**argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
