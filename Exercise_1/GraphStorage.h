#ifndef GraphStorage_h
#define GraphStorage_h

#include "Input.h"
#include "Graph.h"

class GraphStorage
{
public:
	GraphStorage();
	void AddGraphToStorage(std::vector<std::vector<int>> inputFromFile,  char typeOfRepresentation);
	Graph* operator-> ();
	~GraphStorage();
private:
	Graph* m_storedGraph;
};

#endif