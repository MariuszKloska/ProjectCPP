#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include "ascii.cpp"
#include "menuF.cpp"

using namespace std;

int menuNavigation = 1, pressedKey, checkstring = 0;
string menuPositions[10][10][10];
int menuSpaceScreen = 10; // Odległość ramki od lewej krawędzi ekranu
int menuWide = 60; // Szerokośc menu minimum tyle co ma znaków najdłuższa pozycja w menu+1

void loadMenuNemes() //Błędy w wyświetlaniu można rozwiązać dodatkową spacją w nazwie nie chce budować kolejego ifa występują dla nazw o nieparzystej liczbie znaków 
{
	menuPositions[1][0][0] = "Menu1 ";
	menuPositions[2][0][0] = "Menu2 ";
	menuPositions[3][0][0] = "Menu3 ";
	menuPositions[4][0][0] = "Menu4 ";
	menuPositions[5][0][0] = "Menu5 ";
	menuPositions[6][0][0] = "Menu6 ";
	menuPositions[7][0][0] = "Menu7 ";
	menuPositions[8][0][0] = "ASCII ";
	menuPositions[9][0][0] = " Wyjscie  ";

	menuPositions[1][1][0] = "Menu1-1 ";
	menuPositions[1][2][0] = "Menu1-2 ";
	menuPositions[1][3][0] = "Menu1-3 ";
	menuPositions[1][4][0] = "Menu1-4 ";
	menuPositions[1][5][0] = "Oczywiscie w kazdym z menu mozna zamiescic  ";
	menuPositions[1][6][0] = "nie wybieralny tekst ograniczony loopem.    ";
	menuPositions[1][7][0] = "Wystarczy dodac go do tabeli w odpowiednim  ";
	menuPositions[1][8][0] = "miejscu. :)                                 ";

	menuPositions[2][1][0] = "Menu2-1 ";
	menuPositions[2][2][0] = "Menu2-2 ";
	menuPositions[2][3][0] = "Menu2-3 ";
	menuPositions[2][4][0] = "Menu2-4 ";

	menuPositions[3][1][0] = "Menu3-1 ";
	menuPositions[3][2][0] = "Menu3-2 ";
	menuPositions[3][3][0] = "Menu3-3 ";
	menuPositions[3][4][0] = "Menu3-4 ";

	menuPositions[4][1][0] = "Menu4-1 ";
	menuPositions[4][2][0] = "Menu4-2 ";
	menuPositions[4][3][0] = "Menu4-3 ";
	menuPositions[4][4][0] = "Menu4-4 ";

	menuPositions[5][1][0] = "Menu5-1 ";
	menuPositions[5][2][0] = "Menu5-2 ";
	menuPositions[5][3][0] = "Menu5-3 ";
	menuPositions[5][4][0] = "Menu5-4 ";

	menuPositions[6][1][0] = "Menu6-1 ";
	menuPositions[6][2][0] = "Menu6-2 ";
	menuPositions[6][3][0] = "Menu6-3 ";
	menuPositions[6][4][0] = "Menu6-4 ";

	menuPositions[7][1][0] = "Menu7-1 ";
	menuPositions[7][2][0] = "Menu7-2 ";
	menuPositions[7][3][0] = "Menu7-3 ";
	menuPositions[7][4][0] = "Menu7-4 ";



}

void logo()
{
	cout << "Ostatnio wcisniety klawisz : " << pressedKey << endl;
	cout << "Pozycja w menu : " << menuNavigation << endl << endl;
	putSpace(menuSpaceScreen + (menuWide - 37) / 2);
	cout << "   __|  _ \\ \\ \\   /    __|    \\ __ __|" << endl;
	putSpace(menuSpaceScreen + (menuWide - 37) / 2);
	cout << "  (     |  | \\ \\ /     _|    _ \\   |   " << endl;
	putSpace(menuSpaceScreen + (menuWide - 37) / 2);
	cout << " \\___| ___/   \\_/     ___| _/  _\\ _|   " << endl;
}

void menuTopBorderDeepZero()
{
	putSpace(menuSpaceScreen);  cout << (char)(201); putHorLine(menuWide); cout << (char)(187); cout << endl;
}




void MenuExitDeepOne()
{
	system("cls");
	logo();
	menuTopBorderDeepZero();
	putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(201); putHorLine(menuWide); cout << (char)(187); cout << endl;
	putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(186); putSpace((menuWide - menuPositions[9][0][0].length() - 14) / 2); cout << "Menu glowne > " << menuPositions[9][0][0]; putSpace((menuWide - menuPositions[9][0][0].length() - 14) / 2); cout << (char)(186); cout << endl;
	putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(204); putHorLine(menuWide); cout << (char)(185); cout << endl;
	putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(186); putSpace(menuWide); cout << (char)(186); cout << endl; // pusta linia podmenu
	putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(186); putSpace((menuWide - 26) / 2); cout << "Czy napewno chcesz wyjsc ?";  putSpace((menuWide - 26) / 2); cout << (char)(186); cout << endl;
	switch (menuNavigation)
	{
	case 90:
	{
		putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(186); putHorLine((menuWide - 5) / 2); cout << " TAK  ";  putHorLine((menuWide - 5) / 2); cout << (char)(186); cout << endl; break;
	}
	case 91:
	{
		putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(186); putSpace((menuWide - 5) / 2); cout << " TAK  ";  putSpace((menuWide - 5) / 2); cout << (char)(186); cout << endl; break;

	}
	}
	switch (menuNavigation)
	{
	case 91:
	{
		putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(186); putHorLine((menuWide - 5) / 2); cout << " NIE  ";  putHorLine((menuWide - 5) / 2); cout << (char)(186); cout << endl; break;
	}
	case 90:
	{
		putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(186); putSpace((menuWide - 5) / 2); cout << " NIE  ";  putSpace((menuWide - 5) / 2); cout << (char)(186); cout << endl; break;

	}
	}
	for (short putUnderMenuEmpty = 0; putUnderMenuEmpty < 9; putUnderMenuEmpty++)
	{
		putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(186); putSpace(menuWide); cout << (char)(186); cout << endl; // pusta linia menu
	}
	putSpace(menuSpaceScreen);  cout << (char)(200) << (char)(186); putSpace(menuWide); cout << (char)(186); cout << endl; // linia zamykająca deepone
	putSpace(menuSpaceScreen + 1);  cout << (char)(200); putHorLine(menuWide); cout << (char)(188); cout << endl; //Linia zamykająca
}

void menuLegendDeepZero()
{
	putSpace(menuSpaceScreen); cout << (char)(204); putHorLine(menuWide); cout << (char)(185) << endl;
	putSpace(menuSpaceScreen); cout << (char)(186) << (char)(24) << (char)(25) << (char)(26) << ":nawigacja  "; putSpace(menuWide - 15); cout << (char)(186) << endl;
	putSpace(menuSpaceScreen); cout << (char)(186) << "Enter:zatwiedz "; putSpace(menuWide - 15); cout << (char)(186) << endl;
	putSpace(menuSpaceScreen); cout << (char)(186) << "Esc:wyjscie    "; putSpace(menuWide - 15); cout << (char)(186) << endl;
	putSpace(menuSpaceScreen); cout << (char)(200); putHorLine(menuWide); cout << (char)(188) << endl;

}

void menuLoop()
{
	switch (menuNavigation) 
	{
	case 0: menuNavigation = 9; break;
	case 10: menuNavigation = 1; break;
	case 92: menuNavigation = 90; break;
	case 89: menuNavigation = 91; break;
	
	}
	if (menuNavigation % 10 == 5 && menuNavigation > 10 && menuNavigation < 89)
	{
		menuNavigation -= 4;
	}
	else if (menuNavigation % 10 == 0 && menuNavigation > 10 && menuNavigation < 89)
	{
		menuNavigation += 4;
	}
}

void menuControl()
{
	switch (pressedKey)
	{
	case 80: // strzalka w dol
	{
		menuNavigation++;
		break;
	}
	case 72: // strzalka w gore
	{
		menuNavigation--;
		break;
	}
	}
}

void displayMenuDeepOne()
{
	for (short positionsInMenu = 0; positionsInMenu < 9; positionsInMenu++)
	{
		if (menuNavigation == (positionsInMenu+1)+(menuNavigation/10)*10)
		{
			putSpace(menuSpaceScreen); cout << (char)(204);
			putHorLine((menuWide - menuPositions[menuNavigation / 10][((((menuNavigation / 10) * 10) + 1) % 10) + positionsInMenu][0].length()) / 2);
			cout << menuPositions[menuNavigation / 10][((((menuNavigation / 10) * 10) + 1) % 10) + positionsInMenu][0];
			putHorLine((menuWide - menuPositions[menuNavigation / 10][((((menuNavigation / 10) * 10) + 1) % 10) + positionsInMenu][0].length()) / 2);
			cout << (char)(185) << endl;
		}
		else
		{
			putSpace(menuSpaceScreen); cout << (char)(186);
			putSpace((menuWide - menuPositions[menuNavigation / 10][((((menuNavigation / 10) * 10) + 1) % 10) + positionsInMenu][0].length()) / 2);
			cout << menuPositions[menuNavigation / 10][((((menuNavigation / 10) * 10) + 1) % 10) + positionsInMenu][0];
			putSpace((menuWide - menuPositions[menuNavigation / 10][((((menuNavigation / 10) * 10) + 1) % 10) + positionsInMenu][0].length()) / 2);
			cout << (char)(186) << endl;
		}
	}
}
void displayMenuDeepZero()
{
	for (short positionsInMenu = 1; positionsInMenu < 10; positionsInMenu++)
	{
		if (menuNavigation == positionsInMenu)
		{
			putSpace(menuSpaceScreen); cout << (char)(204);
			putHorLine((menuWide - menuPositions[positionsInMenu][0][0].length()) / 2);
			cout << menuPositions[positionsInMenu][0][0];
			putHorLine((menuWide - menuPositions[positionsInMenu][0][0].length()) / 2);
			cout << (char)(185) << endl;
		}
		else
		{
			putSpace(menuSpaceScreen); cout << (char)(186);
			putSpace((menuWide - menuPositions[positionsInMenu][0][0].length()) / 2);
			cout << menuPositions[positionsInMenu][0][0];
			putSpace((menuWide - menuPositions[positionsInMenu][0][0].length()) / 2);
			cout << (char)(186) << endl;
		}
	}
}

int main()
{
	do
	{
		HideCursor();
		system("cls");
		loadMenuNemes();

		if (menuNavigation < 10)
		{
			logo();
			menuTopBorderDeepZero();
			displayMenuDeepZero();
			menuLegendDeepZero();

		}
		else if (menuNavigation > 10 && menuNavigation < 90)
		{
			logo();
			menuTopBorderDeepZero();
			displayMenuDeepOne();
			menuLegendDeepZero();
		}
		switch (menuNavigation)
		{
		case 90: MenuExitDeepOne(); break;
		case 91: MenuExitDeepOne(); break;//Potwierdzenie wyjścia 
		}

		putSpace(menuSpaceScreen + 10);
		cout << "Miejsce na stopke programu ma zawierac np :\n";
		putSpace(menuSpaceScreen + 5);
		cout << "Zalogowany jako : Mariusz               Godzina: 12:21\n";
		putSpace(menuSpaceScreen + 5);
		cout << "Wartosc koszyka : 0 PLN";



		pressedKey = _getch();
		menuControl();
		menuLoop();

		//odwołania do funkcji plików z odpowiedniej pozycji menu
		if (pressedKey == 77 || pressedKey == 13)
		{
			if (menuNavigation>0 && menuNavigation<8)
			{
				menuNavigation = (menuNavigation * 10) + 1; pressedKey = 0;
			}
			switch (menuNavigation)
			{
			
			case 8: system("cls");  ascii(); cout << "\n\n";  system("pause"); break; //odwołanie funcji ascii z pliku ascii.cpp
			case 9: menuNavigation *= 10; pressedKey = 0; break;

			case 90: exit(0); break;
			case 91: menuNavigation /= 10; pressedKey = 0; break;
			}
		}
		else if (pressedKey == 75)
		{
			menuNavigation /= 10;
		}

	} while (pressedKey != 27); //Esc zeby wyjsc
}