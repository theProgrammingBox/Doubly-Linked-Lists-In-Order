#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <ios>

using namespace std;

struct MovieRec
{
	string title;
	string genre;
	int year;
	MovieRec* next;
	MovieRec* prev;
};

void AddMovie(MovieRec*& head, MovieRec*& tail, string title, string genre, int year)
{
	MovieRec* temp = new MovieRec;
	temp->title = title;
	temp->genre = genre;
	temp->year = year;
	temp->next = NULL;
	temp->prev = NULL;

	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		MovieRec* curr = head;
		while (curr != NULL && curr->title < temp->title)
		{
			curr = curr->next;
		}
		if (curr == NULL)
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		else if (curr == head)
		{
			temp->next = curr;
			temp->prev = curr->prev;
			temp->next->prev = temp;
			head = temp;
		}
		else
		{
			temp->next = curr;
			temp->prev = curr->prev;
			temp->next->prev = temp;
			temp->prev->next = temp;
		}
	}
}

void RemoveMovie(MovieRec*& head, MovieRec*& tail, string title)
{
	MovieRec* temp = head;
	bool found = false;

	while (temp != NULL && !found)
	{
		if (temp->title == title)
		{
			found = true;
			if (temp == head)
			{
				if (temp == tail)
				{
					head = NULL;
					tail = NULL;
				}
				else
				{
					head = temp->next;
					temp->next->prev = NULL;
				}
			}
			else
			{
				if (temp == tail)
				{
					tail = temp->prev;
					temp->prev->next = NULL;
				}
				else
				{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
				}
			}

			delete temp;
		}
		else
		{
			temp = temp->next;
		}
	}
}

void DisplayMovies(MovieRec* head)
{
	MovieRec* temp = head;

	while (temp != NULL)
	{
		cout << left;
		cout << setw(20) << temp->title << setw(20) << temp->genre << setw(20) << temp->year << endl;
		cout << right;
		temp = temp->next;
	}

	cout << endl;
}