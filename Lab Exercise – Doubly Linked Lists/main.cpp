#include "header.h"

int main()
{
	ifstream fin;
	string title;
	string genre;
	int year;

	MovieRec* head = NULL;
	MovieRec* tail = NULL;
	fin.open("input.txt");

	while (fin)
	{
		getline(fin, title);
		getline(fin, genre);
		fin >> year;
		fin.ignore(numeric_limits<streamsize>::max(), '\n');
		AddMovie(head, tail, title, genre, year);
	}

	fin.close();

	DisplayMovies(head);
	RemoveMovie(head, tail, "Jurassic Park");
	DisplayMovies(head);
	RemoveMovie(head, tail, "Cinderella Man");
	DisplayMovies(head);
	RemoveMovie(head, tail, "Movie Tested");
	DisplayMovies(head);
	RemoveMovie(head, tail, "Test Movie");
	DisplayMovies(head);
	RemoveMovie(head, tail, "nonexistent");
	DisplayMovies(head);

	return 0;
}