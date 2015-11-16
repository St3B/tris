#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "trislib.cpp"
#include <iomanip>
//#include "trislib.cpp";

using namespace std;

#define MAX 3

void monodim()
  {
  int c, winner = 2, d, e, f = 0, player = 1;
  
 	system ("clear");
	system ("date");
	cout <<"[Tris]"<< endl;
	cout <<"Gli utenti decidano con quante caselle giocare -> " ;
  cin >> c;
  int a[c];
	for (int i = 0; i < c; i++) 
		a[i] = 0;
	do
	  {
		d = 0;
		system ("clear");
		for (int i = 0; i < c; i ++)
			cout << setw (3) << i + 1 << " |";
		cout << endl;
		for (int i = 0; i < c; i++)
			cout << "-----";
		cout << endl;
		for (int i = 0; i < c; i++) {
			if (a [i] == 1)
				cout << setw (3) << "X" << " |";
			else if (a [i] == -1)
				cout << setw (3) << "O" << " |";
			else 
				cout << setw (3) << "#" << " |";			
		}
	for (int i = 0; i < c-2; i ++)
		if ((a[i] == a[i+1]) and (a[i+1] == a[i+2]) and (a[i] != 0))
			winner = a[i];
	for (int i = 0; i < c; i ++)
		if (a[i] != 0)
			d ++;

	if (d == c)
		winner = 0;
	
	if (winner == 2) 
	  {
		player *= -1;
		do
		  {
			if (f != 0)
				cout << "casella già occupata" << endl;
			f = 0;
	
			if (player == 1)
				cout << "\nX> ";
			else
				cout << "\nO> ";
			cin >> e;
			if (a[e - 1] == 0)
				a[e - 1] = player;
			else 
				f++;
		  } while(f != 0);
	  }
	

	} while(winner == 2);
	
	if (winner == 0)
		cout << "\n\nPareggio";
	else if (winner == 1)
		cout << "\n\n\aIl vincitore è \"X\"";
	else if (winner == -1)
		cout << "\n\n\aIl vincitore è \"O\"";
	cout << endl << endl;

	//return 0;
 	
  }

int main () 
  {
	int x;
	int y;
	int dimensione;
	int first_input;
	int second_input;
	int square [MAX] [MAX];
	int player;
	int pcresult;
	int gamemode_singleplayer = 0;

	system ("clear");
	system ("date");
	cout << "STEFANO CADRINGHER - ESTATE 2015\n";

//------------ TABELLA CARATTERI STRANI ------------//
//\\//\\//\\//\\//\\//\\//\\//\\//\\//|\//|\//|\//|\//g++
// 	    Š Š + + - + + Š Š		++++++Š--+Š//
//--------------------------------------------------//
 
	 cout << "╔════════════════════════════╗\n";
	 cout << "║ --    GIOCO DEL TRIS    -- ║\n";
	 cout << "╠════════════════════════════╣\n";
	 cout << "║ 0)  TRIS MONODIMENSIONALE  ║\n";
	 cout << "║ 1)  GIOCATORE vs. PC       ║\n";
	 cout << "║ 2)  DUE GIOCATORI          ║\n";
	 cout << "║ 3)  CUSTOM GRID            ║\n";
	 cout << "║ 4)  esci                   ║\n";
	 cout << "║                            ║\n";
	 cout << "╚════════════════════════════╝\n";
	 cout << "scegli > ";
	 cin >> first_input;

	if (first_input == 0)
	  {
	  monodim();	
   	}


	if (first_input == 1)
		{
		system ("clear");
		system ("date");
	  cout << "╔════════════════════════════╗\n";
	  cout << "║ --     PLAYER vs. PC    -- ║\n";
	  cout << "╠════════════════════════════╣\n";
	  cout << "║ 0)  FACILE                 ║\n";
	  cout << "║ 1)  MEDIO                  ║\n";
	  cout << "║ 2)  DIFFICILE              ║\n";
	  cout << "╚════════════════════════════╝\n";
	  cout << "scegli > ";
	  cin >> second_input;
		if (second_input == 0)
		  {
			dimensione = 3;
			player = 1;
			azzera_tabella (MAX, square);
			while (check (dimensione,square) == 0)
				{
				stampa_tabella (dimensione, square);
				do 
					{
					cout << "PLAYER [X]\n";
					cout << "riga > ";
					cin >> x;
					cout << "colonna > ";
					cin >> y;
					if (x < 0 || y < 0 || x > dimensione - 1 || y > dimensione - 1)
						{
						cout << "immetti di nuovo";
						continue;
						}
					} while (square [x][y] != 0);
				square [x][y] = player;
					//stampa_tabella (dimensione, square);

				//if (player == 1)
				 // {
					//player = 2;
				sleep(1);
				pcresult = cercavuota (3 , square, 2);
				if (pcresult < 0)
					{
					cout << "errore in pcresult";
					break;
					}
				  //}
				}
			system ("clear");
			stampa_tabella (dimensione, square);
			if (check (dimensione,square) < 0)
				{
				cout << "patta";
				return 0;
				}

			if (check (dimensione,square) == 1)
				{
				cout << "complimenti, HAI VINTO!";
				return 0;
				}

			if (check (dimensione,square) == 2)
				{
				cout << "il computer ha vinto! ";
				return 0;
				}
		  }
		if (second_input == 1)
  		{
			dimensione = 3;
			player = 1;
			azzera_tabella (MAX, square);
			while (check (dimensione,square) == 0)
				{
				stampa_tabella (dimensione, square);
				do 
					{
					cout << "PLAYER [X]\n";
					cout << "riga > ";
					cin >> x;
					cout << "colonna > ";
					cin >> y;
						if (x < 0 || y < 0 || x > dimensione - 1 || y > dimensione - 1)
							{
							cout << "immetti di nuovo";
							continue;
							}
					} while (square [x][y] != 0);
				square [x][y] = player;
					//stampa_tabella (dimensione, square);

				//if (player == 1)
				 // {
					//player = 2;
				sleep(1);
				pcresult = cercapericolo (3 , square, 2);
				if (pcresult < 0)
					{
					cout << "errore in pcresult";
					break;
					}
				  //}
				}
			system ("clear");
			stampa_tabella (dimensione, square);
			if (check (dimensione,square) < 0)
				{
				cout << "patta";
				return 0;
				}

			if (check (dimensione,square) == 1)
				{
				cout << "complimenti, HAI VINTO!";
				return 0;
				}

			if (check (dimensione,square) == 2)
				{
				cout << "il computer ha vinto! ";
				return 0;
				}
	  	}
		if (second_input == 2)
		  {
			dimensione = 3;
			player = 1;
			azzera_tabella (MAX, square);
			while (check (dimensione,square) == 0)
				{
				stampa_tabella (dimensione, square);
				do 
					{
					cout << "PLAYER [X] \n";
					cout << "riga > ";
					cin >> x;
					cout << "colonna > ";
					cin >> y;
					if (x < 0 || y < 0 || x > dimensione - 1 || y > dimensione - 1)
						{
						cout << "immetti di nuovo";
						continue;
						}
					} while (square [x][y] != 0);
				square [x][y] = player;
					//stampa_tabella (dimensione, square);

				//if (player == 1)
				 // {
					//player = 2;
				sleep(1);
				system ("clear");
				if (cercavincita (3, square, 2) == 0)
 					{
					pcresult = cercapericolo (3 , square, 2);
					if (pcresult < 0)
		 				{
	  				cout << "errore in pcresult";
						break;
		  			}
				  }
			  }
			stampa_tabella (dimensione, square);
			if (check (dimensione,square) < 0)
				{
				cout << "patta";
				return 0;
				}

			if (check (dimensione,square) == 1)
				{
				cout << "complimenti, HAI VINTO!";
				return 0;
				}

			if (check (dimensione,square) == 2)
				{
				cout << "il computer ha vinto! ";
				return 0;
				}
		 }
   }

	if (first_input == 2)
		{
		dimensione = 3;
		player = 1;
		azzera_tabella (MAX, square);
		while (check (dimensione,square) == 0)
			{
			stampa_tabella (dimensione, square);
			do 
				{
				cout << "player  " << player << " \n";
				cout << "riga > ";
				cin >> x;
				//cout << "\n";
				cout << "colonna > ";
				cin >> y;
				if (x < 0 || y < 0 || x > dimensione - 1 || y > dimensione - 1)
					{
					cout << "immetti di nuovo";
					continue;
					}
				} while (square [x][y] != 0);
			square [x][y] = player;
			if (player == 1)
				player = 2;
			else 
				player = 1;
			}
		stampa_tabella (dimensione, square);
		if (check (dimensione,square) < 0)
			cout << "patta";
		if (check (dimensione,square) == 1)
			cout << "player"<< player << " HAI VINTO!";
		if (check (dimensione,square) == 2)
			cout << "player"<< player << " HAI VINTO!";
		}

	if (first_input == 3)
		{
		player = 1;
		cout << "immetti la dimensione > ";
		cin >> dimensione;
		azzera_tabella (MAX, square);
		cout << check (dimensione,square);
		while (check (dimensione,square) == 0)
			{
			stampa_tabella (dimensione, square);
			do 
				{
				cout << "player  " << player<< " " << (player == 1? 'X':'O') <<"  \n";
				cout << "riga > ";
				cin >> x;
				cout << "\n";
				cout << "colonna > ";
				cin >> y;
					if (x < 0 || y < 0 || x > dimensione - 1 || y > dimensione - 1)
						{
						cout << "immetti di nuovo";
						continue;
						}
				}while (square [x][y] != 0);
				square [x][y] = player;
			if (player == 1)
				player = 2;
			else player = 1;
			}
		stampa_tabella (dimensione, square);
		if (check (dimensione,square) < 0)
			cout << "patta";
		if (check (dimensione,square) == 1)
			cout << "player"<< player << " HAI VINTO!";
		if (check (dimensione,square) == 2)
			cout << "player"<< player << " HAI VINTO!";
		}
		
	if (first_input == 4)
		{
		return 0;
		}
  }

