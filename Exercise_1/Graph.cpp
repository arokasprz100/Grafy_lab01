#include "Graph.h"

Graph::Graph(std::vector<std::vector<int>> inputFromFile, char typeOfRepresentation)
{
	m_storedRepresentation = inputFromFile;
	m_representation = typeOfRepresentation;
}

void Graph::PrintGraph(std::ostream& placeToPrint) const 
{
	for (unsigned i = 0; i < m_storedRepresentation.size(); ++i)
	{
		for (unsigned j = 0; j < m_storedRepresentation.at(i).size(); ++j)
			placeToPrint<<m_storedRepresentation.at(i).at(j)<<" ";
		placeToPrint<<std::endl;
	}
}

char Graph::GetRepresentation() const
{
	return m_representation;
}

void Graph::ChangeAdjacencyListToIncidenceMatrix()
{
	std::vector<std::vector<int>> incidenceMatrix(m_storedRepresentation.size(), std::vector<int>(EdgesCounter(), 0));
	int counter=0;
	if(m_representation=='l')
	{
		for (unsigned i = 0; i < m_storedRepresentation.size(); ++i)
		{
			for (unsigned j = 0; j < m_storedRepresentation.at(i).size(); ++j)
			{
				if(i+1 < (unsigned)m_storedRepresentation[i][j])
				{
					incidenceMatrix[i][counter]=1;
					incidenceMatrix[m_storedRepresentation[i][j]-1][counter]=1;
					counter++;
				}
			}
		}
	}
	m_storedRepresentation=incidenceMatrix;
	m_representation='i';
}

void Graph::ChangeAdjacencyMatrixToIncidenceMatrix()
{
	std::vector<std::vector<int>> incidenceMatrix(m_storedRepresentation.size(), std::vector<int>(EdgesCounter(), 0));
	int counter=0;
	if(m_representation=='a')
	{
		for (unsigned i = 0; i < m_storedRepresentation.size(); ++i)
		{
			for (unsigned j = i; j < m_storedRepresentation.at(i).size(); ++j)
			{
				if(m_storedRepresentation[i][j]==1)
				{
					incidenceMatrix[i][counter]=1;
					incidenceMatrix[j][counter]=1;
					counter++;
				}
			}
		}
	}
	m_storedRepresentation=incidenceMatrix;
	m_representation='i';

}

int Graph::EdgesCounter() const
{
	int edges=0;
	if(m_representation=='l')
	{
		for (unsigned i = 0; i < m_storedRepresentation.size(); ++i)
			edges+=m_storedRepresentation.at(i).size();
		edges/=2;
	}
	if(m_representation=='a')
	{
		for (unsigned i = 0; i < m_storedRepresentation.size(); ++i)
		{
			for (unsigned j = i+1; j < m_storedRepresentation.at(i).size(); ++j)
			{
				if(m_storedRepresentation[i][j]==1)
					edges++;
			}
		}
	}
	if(m_representation=='i')
		edges=m_storedRepresentation.at(0).size();
	return edges;
}

void Graph::ChangeToIncidenceMatrix()
{
	if(m_representation=='l')
		ChangeAdjacencyListToIncidenceMatrix();
	else if(m_representation=='a')
		ChangeAdjacencyMatrixToIncidenceMatrix();
	else if(m_representation=='i')
		std::cout<<"Graph is already represented by an incidence matrix."<<std::endl;
}