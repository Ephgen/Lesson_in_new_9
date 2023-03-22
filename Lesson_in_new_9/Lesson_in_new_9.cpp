#include <iostream>
#include <Windows.h>
#include "Three.h"
using namespace std;

Three tournament;	//турнирная таблица

void Game(char Commands[][20], int N) {
	int i, j;
	int p1, p2; // Счёт

	int k;
	Elem* temp;
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < N - 1; i++) {
			for (j = i + 1; j < N; j++) {
				temp = new Elem;
				if (k == 0) {
					strcpy_s(temp->Name, Commands[i]);
					strcpy_s(temp->Opponent, Commands[j]);
				}
				else
				{
					strcpy_s(temp->Name, Commands[j]);
					strcpy_s(temp->Opponent, Commands[i]);
				}
				p1 = rand() % 6;
				p2 = rand() % 6;
				if (p1 > p2) {
					temp->oppPoints = 0;
					temp->ownerPoints = 3;
				}
				else if (p1 < p2) {
					temp->oppPoints = 3;
					temp->ownerPoints = 0;
				}
				else {
					temp->oppPoints = 1;
					temp->ownerPoints = 1;
				}
				sprintf_s(temp->Match, " %d : %d ", p1, p2);
				tournament.Insert(temp);
			}
		}
	}
}

int main()
{
	srand(time(0));
	const int N = 4;
	char Commands[4][20] = {
		"Arsenal",
		"Liverpool",
		"Manchester United",
		"Zenit" };
	Game(Commands, N);
	tournament.Print(tournament.GetRoot());
}
