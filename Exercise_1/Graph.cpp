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

void Graph::ChangeIncidenceMatrixToAdjacencyMatrix()
{
	std::vector<std::vector<int>> adjacencyMatrix(m_storedRepresentation.size(), std::vector<int>(m_storedRepresentation.size(), 0));
	if(m_representation == 'i')
	{
		for (unsigned i = 0; i < m_storedRepresentation.size(); ++i)
		{
			for (unsigned j = 0; j < m_storedRepresentation.at(i).size(); ++j)
			{
				if (m_storedRepresentation[i][j] == 1)
				{
					for (unsigned k = 0; k < m_storedRepresentation.size(); ++k)
					{
						if((m_storedRepresentation[k][j] == 1) && (k != i))
							adjacencyMatrix[i][k] = 1;
					}
				}
			}
		}
	}

	m_storedRepresentation=adjacencyMatrix;
	m_representation='a';	
}
	
void Graph::ChangeAdjacencyListToAdjacencyMatrix()
{
	std::vector<std::vector<int>> adjacencyMatrix(m_storedRepresentation.size(), std::vector<int>(m_storedRepresentation.size(), 0));
	if(m_representation == 'l')
	{
		for (unsigned i = 0; i < m_storedRepresentation.size(); ++i)
		{
			for (unsigned j = 0; j < m_storedRepresentation.at(i).size(); ++j)
			{
				if(m_storedRepresentation[i][j] != 0)
				{
					adjacencyMatrix[i][m_storedRepresentation[i][j]-1] = 1;
				}
			}		
		}			
	}
	m_storedRepresentation=adjacencyMatrix;
	m_representation='a';
}

void Graph::ChangeAdjacencyMatrixToAdjacencyList()
{
	std::vector<std::vector<int>> adjacencyList(m_storedRepresentation.size(), std::vector<int>(m_storedRepresentation.size(), 0));
	int counter;
	if(m_representation == 'a'){
		for (unsigned i = 0; i < m_storedRepresentation.size(); ++i)
		{
			counter = 0;
			for (unsigned j = 0; j < m_storedRepresentation.at(i).size(); ++j)
			{
				if(m_storedRepresentation[i][j] == 1)
				{
					adjacencyList[i][counter] = j+1;
					counter++;
				}
			}
		}
		for (unsigned i = 0; i < m_storedRepresentation.size(); ++i)
		{
			 for (unsigned j = 0; j < m_storedRepresentation.at(i).size(); ++j)
			{
				if(adjacencyList[i][j] == 0)
				{
					adjacencyList.at(i).erase(adjacencyList.at(i).begin()+j, adjacencyList.at(i).size());
					break;
				}
			}
		}
	}
	m_storedRepresentation=adjacencyList;
	m_representation='l';
}

void Graph::ChangeInicidenceMatrixToAdjacencyList()
{
	ChangeIncidenceMatrixToAdjacencyMatrix();
	ChangeAdjacencyMatrixToAdjacencyList();
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

void Graph::ChangeToAdjacencyMatrix()
{
	if(m_representation=='l')
		ChangeAdjacencyListToAdjacencyMatrix();
	else if(m_representation=='a')
		std::cout<<"Graph is already represented by an adjacency matrix."<<std::endl;
	else if(m_representation=='i')
		ChangeIncidenceMatrixToAdjacencyMatrix();

}
	
void Graph::ChangeToAdjacencyList()
{
	if(m_representation=='l')
		std::cout<<"Graph is already represented by an adjacency list."<<std::endl;
	else if(m_representation=='a')
		ChangeAdjacencyMatrixToAdjacencyList();
	else if(m_representation=='i')
		ChangeInicidenceMatrixToAdjacencyList();
}

void Graph::AskUserAboutChange()
{
	char newRepresentation;
	std::cout<<"In which representation you want to have your graph?"<<std::endl;
	std::cout<<"Options: \nl - adjacency list \na - adjacency matrix \ni - incidence matrix"<<std::endl;
	std::cin>>newRepresentation;
	if(newRepresentation=='l')
		ChangeToAdjacencyList();
	else if(newRepresentation=='a')
		ChangeToAdjacencyMatrix();
	else if(newRepresentation=='i')
		ChangeToIncidenceMatrix();
	else
		std::cout<<"Wrong option."<<std::endl;
}

