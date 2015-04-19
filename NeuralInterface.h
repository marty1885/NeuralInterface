#ifndef NEURALINTERFACE_H
#define NEURALINTERFACE_H

#include <iostream>
#include <vector>
#include <string>

#include <string.h>

namespace NeuralInterface
{

class SubInterface
{
public:
	SubInterface(int size);
	~SubInterface();
	float* data = NULL;
	int dataSize = 0;
};

class Interface
{
public:
	Interface(int* dimensionSize, int size, int depth = 0);
	Interface();
	~Interface();
	void clear(float value);
	int getDimension();

	std::vector<Interface*> node;
	SubInterface* interface = NULL;

	Interface& operator[](int index);
};

class InterfaceManager
{
public:
	int add(std::string name, int* dimensionSize, int size);
	int append(std::string name,Interface* interface);
	Interface& find(std::string name);
	Interface* findPtr(std::string name);
	int findId(std::string name);
	int remove(std::string name);

	std::vector<Interface*> interfaces;
	std::vector<std::string> names;
};

};


#endif