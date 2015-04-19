#include "NeuralInterface.h"

int main()
{
	//Define how much dimension we want and how large it is0
	int dimensionSize[] = {2,50,70};
	int size = 3;

	//Create a manager. This is the core component.
	NeuralInterface::InterfaceManager interfaceManager;

	//Add a Interface named "Test1" with the parameter we defined.
	interfaceManager.add("Test1",dimensionSize,size);

	//set every element in our interface to 0.2;
	interfaceManager.find("Test1").clear(0.2);

	//pick a random one and print it out
	std::cout << interfaceManager.find("Test1")[0][0].interface->data[0] << std::endl;

	return 0;
}