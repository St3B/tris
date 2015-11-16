#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
//#include "trislib.cpp";

using namespace std;

#define MAX 3
int check (int dim, int square [MAX] [MAX] ); //la dichiaro, poichè darebbe errore

int cercavincita (int dim, int square [MAX] [MAX], int usr)
	{
	int i;
	int j;
	for (j = 0; j < dim; j++)
		{
		for (i = 0; i < dim; i++)
			{
			if (square [j][i] == 0)
				{
				square [j][i] = usr;
				if (check (dim, square) == usr)
					return 1;	
				square [j][i] = 0;		
				}
			}
		}
		return 0; //nessuna cella libera, in pratica il gioco è finito
	}

int cercavuota (int dim, int square [MAX] [MAX], int usr)
	{
	int i;
	int j;
	int ro;	//row
	int co;	//coloumn
	srand (time(NULL)); //metto il seed di rand a time
	for (j = 0; j < dim; j++)
		{
		for (i = 0; i < dim; i++)
			{
			if (square [j][i] == 0)	//se ce n'è una libera...
				{
				for (int k = 0; k < 10000; k++) //dovrebbe trovarne almeno la [j][i]
					{
					// cerco righe e colonne casuali un bel po' di volte
					//se proprio non ne trovo, ne prendo una sicutamente vuota ([j][i])
					ro = rand () % dim;
					co = rand () % dim;
					if (square [ro][co] == 0)
						{
						//a questo punto la prenoto
						square [ro][co] = usr;
						return 1; //e basta
						}
					} 
					square [j][i] == usr; //se proprio non ci risce prende j,i
				}
			}
		}
		return 0; //nessuna cella libera, in pratica il gioco è finito
	}

int cercapericolo (int dim, int square [MAX] [MAX], int usr)
	{
	//VARIABILI COMUNI
	int nv, me, ro_v,co_v;
	int i;
	int j;
	//CONTROLLO DELLE RIGHE
	for (j = 0; j < dim; j++)	
		{
		nv = 0;	//numero delle cella vuote
		me = 0; //numerod delle di user
		ro_v = 0; //riga in cui c'è la cella vuota (una)
		co_v = 0; //colonna in cui c'è la cella vuota

		for (i = 0; i < dim; i++)
			{
			if (square [j][i] == 0)
				{
				ro_v = j;
				co_v = i;
				nv++;
				}
			if (square [j][i] == usr)
				{
				me++;
				}
			}

		//primo test
		if (me == 0 && nv == 1)	//due nemici più una cella vuota => pericolo
			{	
			square [ro_v][co_v] = usr;
			return 1;
			} 
		}


	//CONTROLLO DELLE COLONNE
	for (j = 0; j < dim; j++)	
		{
		nv = 0;	//numero delle cella vuote
		me = 0; //numerod delle di user
		ro_v = 0; //riga in cui c'è la cella vuota (una)
		co_v = 0; //colonna in cui c'è la cella vuota

		for (i = 0; i < dim; i++)
			{
			if (square [i][j] == 0)
				{
				ro_v = i;
				co_v = j;
				nv++;
				}
			if (square [i][j] == usr)
				{
				me++;
				}
			}
			
		//primo test
		if (me == 0 && nv == 1)	//due nemici più una cella vuota => pericolo
			{	
			square [ro_v][co_v] = usr;
			return 1;
			} 
		}

	//CONTROLLO PRIMA DIAGONALE			(a quesllo dopo devo sostituire a i dim - i - j)
	nv = 0;me=0;
	for (i = 0; i < dim; i++)
		{
		if (square [i][i] == 0)
			{
			ro_v = i;
			co_v = i;
			nv++;
			}
		if (square [i][i] == usr) 
			{
			me++;
			}	
		}	
     cout << me <<" " << nv << " ";
	if (me == 0 && nv == 1)
		{
		square [ro_v][co_v] = usr;
		return 1;
		}



	//CONTROLLO SECONDA DIAGONALE			
	nv = 0;me=0;
	for (i = 0; i < dim; i++)
		{
		if (square [i][dim -i -1] == 0)
			{
			co_v = dim -i -1;
			ro_v = i;
			nv++;
			}
		if (square [i][dim -i -1] == usr)
			{
			me++;
			}	
		}	

	if (me == 0 && nv == 1)
		{
		square [ro_v][co_v] = usr;
		return 1;
		}

return cercavuota (dim, square, usr);
}


//dim è la dimansione della tabella, square un array bidimensionale
int azzera_tabella (int dim, int square [MAX] [MAX] ) //funzione che azzera la tabella
//utile quando si inizia il gioco
    {
	int i; //variabii di ciclo
	int j; //variabili di ciclo

	for (j = 0; j < dim; j++)
		{
		for (i = 0; i < dim; i++)
			{
			square [j][i] = 0;
			}
		}
	}


//funzione che stampa a video la tabella
int stampa_tabella (int dim, int square [MAX] [MAX] )
	{
	//aperture (prima riga)
	int i;
	int j;
	int error = 0;
	cout << "\n c0  c1  c2\n╔";
	for (i = 1; i < dim; i++)			
		cout << "═══╦";
	cout << "═══╗\n";

	//interno (righe)
	for (j = 0; j < dim; j++)
		{
		for (i = 0; i < dim; i++)
			{
			cout << "║ ";
			if (square [j][i] == 1)
				cout << "X";
			else 
				{
				if (square [j][i] == 2)
					cout << "O";
				else 
					if (square [j][i] != 0)
						{
						cout << "-";
						error ++;
						}
					else 
						cout << " ";
				}
			
			
			cout << " ";
			}
		cout << "║\n";
		
		if ( j != dim - 1)
			{
				
			cout << "╠";
			for (i = 1; i < dim; i++)
				cout << "═══╬";
			cout <<"═══╣\n";
			}

		else 
			{
			cout << "╚";
			for (i = 1; i < dim; i++)			//ho messo i = 1 perchè così fa dim - 1
				cout << "═══╩";
			cout << "═══╝\n";
			}
			
		}
	
	}

	
	//questa funzione restituisce: uno o due se per indicare l giocatore uno o due (vincita)
	//0 se il gioco è ancora aperto
	//-1 in caso di errore
	
int check (int dim, int square [MAX] [MAX] ) //
	{
	int i;
	int j;
	int tot = 0;
	int player1 = 0;
	int player2 = 0;
	int nulle = 0;
	
	// righe
	for (j = 0; j < dim; j++)
		{
			tot = 0;
		for (i = 1; i < dim; i++)
			{
			if (square [j][i] == square [j][0] && square [j][0] != 0)
				tot ++;
			if (square [j][i] == 0)
				nulle++;
			}
		if (tot == dim - 1)
			{
			if (square [j][0] == 1)
				player1 ++;
			if (square [j][0] == 2)
				player2 ++;
			if (square [j][0] != 1 && square [j][0] != 2)
				cout << "error 1";
			}
		}
	//colonne
	
	for (i = 0; i < dim; i++)
		{
			tot = 0;
		for (j = 1; j < dim; j++)
			if (square [j][i] == square [0][i] && square [0][i] != 0)
				tot ++;
		if (tot == dim - 1)
			{
			if (square [0][i] == 1)
				player1 ++;
			if (square [0][i] == 2)
				player2 ++;
			if (square [0][i] != 1 && square [0][i] != 2)
				cout << "error 2";
			}
		}
	// diag 1
	tot = 0;
	for (j = 1; j < dim; j++)
			if (square [j][j] == square [0][0] && square [0][0] != 0)
				tot ++;
		if (tot == dim - 1)
			{
			if (square [0][0] == 1)
				player1 ++;
			if (square [0][0] == 2)
				player2 ++;
			if (square [0][0] != 1 && square [0][0] != 2)
				cout << "error 3";
			}
	// diag 2
	tot = 0;
	for (j = 1; j < dim; j++)
			if (square [j][dim - 1 - j] == square [0][dim - 1] && square [0][dim - 1] != 0)
				tot ++;
		if (tot == dim - 1)
			{
			if (square [0][dim -1] == 1)
				player1 ++;
			if (square [0][dim -1] == 2)
				player2 ++;
			if (square [0][dim -1] != 1 && square [0][dim - 1] != 2)
				cout << "error 4";
			}
	if (player1 == 0 && player2 == 0)
		return 0;
	if (player1 == 0)
		return 2;
	if (player2 == 0)
		return 1;
	if (nulle == 0)
		return -2; //gioco finito pari
	return -1;
	
	}
	
