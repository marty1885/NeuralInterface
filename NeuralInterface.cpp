#include "NeuralInterface.h"


NeuralInterface::SubInterface::SubInterface(int size)
{
	data = new float[size];
	dataSize = size;
	memset(data,0,size);
}

NeuralInterface::SubInterface::~SubInterface()
{
	delete [] data;
}

NeuralInterface::Interface::Interface(int* dimensionSize, int size, int depth)
{
	if(depth < size-1)
	{
		for(int i=0;i<dimensionSize[depth];i++)
		{
			node.push_back(new Interface(dimensionSize,size,depth+1));
		}
	}
	else
		interface = new SubInterface(dimensionSize[depth]);
}

NeuralInterface::Interface::~Interface()
{
	int size = node.size();
	for(int i=0;i<size;i++)
		delete node[i];

	if(interface != NULL)
		delete interface;
}

int NeuralInterface::Interface::getDimension()
{
	Interface* current = this;
	int dimension = 0;
	while(1)
	{
		if(current->node[0] != NULL)
		{
			current = current->node[0];
			dimension++;
		}
		else
			break;
	}
	return dimension;
}

void NeuralInterface::Interface::clear(float value)
{
	int size = node.size();
	if(size != 0)
	{
		for(Interface*& interface : node)
			interface->clear(value);
	}
	else
	{
		int clearSize = interface->dataSize;
		for(int i=0;i<clearSize;i++)
			interface->data[i] = value;
	}
}

NeuralInterface::Interface& NeuralInterface::Interface::Interface::operator[](int index)
{
	return *node.at(index);
}

int NeuralInterface::InterfaceManager::add(std::string name, int* dimensionSize, int size)
{
	//int size = interfaces.size();
	//if name alread exist
	int result = findId(name);
	if(result >= 0)
		return -1;

	interfaces.push_back(new Interface(dimensionSize,size));
	names.push_back(name);
	return 1;
}

int NeuralInterface::InterfaceManager::append(std::string name,Interface* interface)
{
	Interface* result = findPtr(name);
	if(result != NULL)
		return -1;

	interfaces.push_back(interface);
	names.push_back(name);
	return 1;
}

NeuralInterface::Interface& NeuralInterface::InterfaceManager::find(std::string name)
{
	int id = findId(name);
	if(id < 0)
		throw std::string("Error. Name not found.");//Normally I don't do this.
	return *interfaces[id];
}

NeuralInterface::Interface* NeuralInterface::InterfaceManager::findPtr(std::string name)
{
	int id = findId(name);
	return (id < 0 ? NULL : interfaces[id]);
}

int NeuralInterface::InterfaceManager::findId(std::string name)
{
	int size = names.size();
	for(int i=0;i<size;i++)
		if(names[i] == name)
			return i;

	return -1;
}

int NeuralInterface::InterfaceManager::remove(std::string name)
{
	int result = findId(name);
	if(result < 0)
		return -1;
	delete interfaces[result];

	interfaces.erase(interfaces.begin() + result);
	names.erase(names.begin() + result);
}
