#ifndef Graph_h
#define Graph_h

#include <vector>
#include <iostream>

class Graph 
{
public:
	Graph(std::vector<std::vector<int>> inputFromFile, char typeOfRepresentation);
	void PrintGraph(std::ostream& placeToPrint) const ;
	char GetRepresentation() const;
	// Funkcja zamieniajaca liste sasiedztwa na macierz incydencji. Tworzy macierz o wymiarze l.wierzchołków x l.krawedzi, wypełnia zerami.
	// Uzupełnia kolejno kolumny macierzy. Każda kolumna reprezentuje osobna krawedz.
	void ChangeAdjacencyListToIncidenceMatrix();
	// Funkcja zamieniajaca macierz sasiedztwa na macierz incydencji. Tworzy macierz o wymiarze l.wierzchołków x l.krawedzi, wypełnia zerami.
	// Uzupełnia kolejno kolumumny macierzy. Sprawdza pomiędzy którymi wierzchołkami istnieje krawędź. Każda krawędź to osobna kolumna.
	void ChangeAdjacencyMatrixToIncidenceMatrix();
	//
	void ChangeIncidenceMatrixToAdjacencyMatrix();
	//
	void ChangeAdjacencyListToAdjacencyMatrix();
	//
	void ChangeAdjacencyMatrixToAdjacencyList();
	//
	void ChangeInicidenceMatrixToAdjacencyList();
	// Funkcja dla każdej reprezentacji grafu zlicza ilosc krawedzi i zwraca ja.
	int EdgesCounter() const;
	// Funkcja zamieniajaca reprezentacje grafu przechowywana przez obiekt klasy Graph na macierz incydencji. W zaleznosci w jakiej
	// reprezentacji jest graf funkcja wywoluje inna funkcje zamieniajaca, lub wypisuje informacje ze graf jest juz
	// w tej reprezentacji. 
	void ChangeToIncidenceMatrix();
	// Funkcja zamieniajaca reprezentacje grafu przechowywana przez obiekt klasy Graph na macierz sąsiedztwa. W zaleznosci w jakiej
	// reprezentacji jest graf funkcja wywoluje inna funkcje zamieniajaca, lub wypisuje informacje ze graf jest juz
	// w tej reprezentacji. 
	void ChangeToAdjacencyMatrix();
	// Funkcja zamieniajaca reprezentacje grafu przechowywana przez obiekt klasy Graph na listę sąsiedztwa. W zaleznosci w jakiej
	// reprezentacji jest graf funkcja wywoluje inna funkcje zamieniajaca, lub wypisuje informacje ze graf jest juz
	// w tej reprezentacji. 
	void ChangeToAdjacencyList();
	// Funkcja pytajaca uzytkownika na jaka reprezentacje chce zamienic graf i wywolujaca odpowiednia funkcje.
	void AskUserAboutChange();
	/// TODO: Funkcja zamieniajaca na macierz incydencji - wywoluje jedna z dwoch funkcji, zaleznie od aktualnej reprezentacji, j
	///			jesli juz jest macierz incydencji - wypisuje komunikat, nie robi nic

	/// TODO: Funkcja zamieniajaca na liste sasiedztwa - podobnie jak wyzej

	/// TODO: Funkcja zamieniajaca na macierz sasiedztwa - jak wyzej


	/// TODO Gabrysia: pierwsza funkcja - polecam napisac dwie pomocnicze, jedna zamieniajaca macierz sasiedztwa na incydencji, druga liste sasiedztwa
	/// 			na macierz incydencji

	/// TODO Piotr: druga funkcja, podobnie jak u Gabrysi

	/// TODO Gabrysia: interfesjs pytajacy uzytkownika na co chce dokonac zamiany  i wywolujacy odpowiednia funkcje zaleznie od reprezentacji teraz i docelowej

	/// TODO Piotr: trzecia funkcja, podobnie jak wczesniej

	/// TODO Arek; reorganizacja kodu, sprawdzanie poprawnosci pliku, dokumentacja do swojej czesci,

	/// TODO Arek: wymyslic sposob na rysowanie do zadania 2

	/// Uwaga: Prosze pisac dokumentacje i kod do swoich funkcji, najlepiej po angielsku

	/// Uwagi: funkcje maja sprawdzac, czy graf nie jest juz w danej reprezentacji

protected:
	std::vector< std::vector <int> > m_storedRepresentation;
	char m_representation;

};

#endif
