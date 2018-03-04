#include "GraphStorage.h"

GraphStorage::GraphStorage():
	m_storedGraph(nullptr) {}


void GraphStorage::AddGraphToStorage(std::vector<std::vector<int>> inputFromFile, char typeOfRepresentation)
{
	m_storedGraph = new Graph(inputFromFile, typeOfRepresentation);
}

GraphStorage::~GraphStorage()
{
	if (m_storedGraph!=nullptr)
		delete m_storedGraph;
}

Graph* GraphStorage::operator-> ()
{
	return m_storedGraph;
}

