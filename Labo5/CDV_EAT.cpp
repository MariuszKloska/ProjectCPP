#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include "ascii.cpp"
#include "menuF.cpp"

using namespace std;

int menuNavigation = 1, pressedKey, checkstring = 0;
string menuPositions[10][10][10];
int menuSpaceScreen = 20; // Odległość ramki od lewej krawędzi ekranu
int menuWide = 80; // Szerokośc menu minimum tyle co ma znaków najdłuższa pozycja w menu

void loadMenuNemes() //Błędy w wyświetlaniu można rozwiązać dodatkową spacją w nazwie nie chce budować kolejego ifa występują dla nazw o nieparzystej liczbie znaków 
{
	// używajćie parzystej liczby znaków !
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

	menuPositions[9][2][0] = "Czy napewno chcesz wyjsc ?";
	menuPositions[9][3][0] = " Tak  ";
	menuPositions[9][4][0] = " Nie  ";


	menuPositions[1][1][1] = "Menu1-1-1 ";
	menuPositions[1][1][2] = "Menu1-1-2 ";


}
void logo()
{

	putSpace(menuSpaceScreen + (menuWide - 37) / 2);
	cout << "   __|  _ \\ \\ \\   /    __|    \\ __ __|" << endl;
	putSpace(menuSpaceScreen + (menuWide - 37) / 2);
	cout << "  (     |  | \\ \\ /     _|    _ \\   |   " << endl;
	putSpace(menuSpaceScreen + (menuWide - 37) / 2);
	cout << " \\___| ___/   \\_/     ___| _/  _\\ _|   " << endl;
}
void loading()
{
	short timeWait = 5;
	HideCursor();

	for (short percent = 1; percent < 101; percent++) {
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n";
		logo();
		putSpace(menuSpaceScreen + (menuWide / 2) - 16);
		if (percent < 33)
			cout << "Szukanie przypraw         : " << percent << " %\n";
		else if (percent >= 33 && percent < 66)
			cout << "Obieranie warzyw          : " << percent << " %\n";
		else
			cout << "Nakrywanie stolikow       : " << percent << " %\n";

		putSpace(menuSpaceScreen + 16);
		for (short symbolLoop = 0; symbolLoop < percent; symbolLoop += 2)
			cout << char(178);

		Sleep(timeWait);
	}
}
void menuTopBorderDeepZero()
{
	putSpace(menuSpaceScreen);  cout << (char)(201); putHorLine(menuWide); cout << (char)(187); cout << endl;
}
void menuLegend(short extraspace)
{
	putSpace(menuSpaceScreen); if (extraspace == 1) { cout << (char)(200); }
	if (extraspace == 2) { cout << (char)(200) << (char)(186); }
	cout << (char)(204); putHorLine(menuWide); cout << (char)(185) << endl;
	if (extraspace == 2) 
	{
		putSpace(menuSpaceScreen + extraspace-1); cout << (char)(200) << (char)(186) << (char)(24) << (char)(25) << (char)(26) << ":nawigacja  "; putSpace(menuWide - 15); cout << (char)(186) << endl;
	}
	else 
	{
		putSpace(menuSpaceScreen + extraspace); cout << (char)(186) << (char)(24) << (char)(25) << (char)(26) << ":nawigacja  "; putSpace(menuWide - 15); cout << (char)(186) << endl;

	}
	
	putSpace(menuSpaceScreen + extraspace); cout << (char)(186) << "Enter:zatwiedz "; putSpace(menuWide - 15); cout << (char)(186) << endl;
	putSpace(menuSpaceScreen + extraspace); cout << (char)(186) << "Esc:wyjscie    "; putSpace(menuWide - 15); cout << (char)(186) << endl;
	putSpace(menuSpaceScreen + extraspace); cout << (char)(200); putHorLine(menuWide); cout << (char)(188) << endl;

}
void menuLoop()
{
	switch (menuNavigation) 
	{
	case 0: menuNavigation = 9; break;
	case 10: menuNavigation = 1; break;
	case 95: menuNavigation = 93; break;
	case 92: menuNavigation = 94; break;
	case 110: menuNavigation = 112; break;
	case 113: menuNavigation = 111; break;
	
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
void displayMenuDeepTwo()
{
	putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(201); putHorLine(menuWide); cout << (char)(187); cout << endl;
	putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(186) << (char)(201); putHorLine(menuWide); cout << (char)(187); cout << endl;

	putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(186) << (char)(186); putSpace((menuWide - menuPositions[menuNavigation / 100][0][0].length() - menuPositions[menuNavigation / 100][(((menuNavigation / 10) % 10))][0].length() - 18) / 2);
	cout << "Menu glowne > " << menuPositions[menuNavigation / 100][0][0] << " >  " << menuPositions[menuNavigation / 100][(((menuNavigation / 10) % 10))][0];
	putSpace((menuWide - menuPositions[menuNavigation / 100][0][0].length() - menuPositions[menuNavigation / 100][(((menuNavigation / 10) % 10))][0].length() - 18) / 2); cout << (char)(186); cout << endl;
	
	putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(186) << (char)(204); putHorLine(menuWide); cout << (char)(185); cout << endl;
	for (short positionsInMenu = 0; positionsInMenu < 9; positionsInMenu++)
	{
		if (menuNavigation == (positionsInMenu + 1) + (menuNavigation / 10) * 10)
		{
			putSpace(menuSpaceScreen); cout << (char)(186) << (char)(186) << (char)(204);
			putHorLine((menuWide - menuPositions[menuNavigation / 100][(((menuNavigation / 10) % 10))][(menuNavigation / 10 * 10) % 10+1+positionsInMenu].length()) / 2);
			cout << menuPositions[menuNavigation / 100][(((menuNavigation / 10) % 10))][(menuNavigation/10*10)%10+1+positionsInMenu];
			putHorLine((menuWide - menuPositions[menuNavigation / 100][(((menuNavigation / 10) % 10))][(menuNavigation / 10 * 10) % 10+1+positionsInMenu].length()) / 2);
			cout << (char)(185) << endl;
		}
		else
		{
			putSpace(menuSpaceScreen); cout << (char)(186) << (char)(186) << (char)(186);
			putSpace((menuWide - menuPositions[menuNavigation / 100][(((menuNavigation / 10) % 10))][(menuNavigation / 10 * 10) % 10+1+positionsInMenu].length()) / 2);
			cout << menuPositions[menuNavigation / 100][(((menuNavigation / 10) % 10))][(menuNavigation / 10 * 10) % 10+1+positionsInMenu];
			putSpace((menuWide - menuPositions[menuNavigation / 100][(((menuNavigation / 10) % 10))][(menuNavigation / 10 * 10) % 10+1+positionsInMenu].length()) / 2);
			cout << (char)(186) << endl;
		}
	}
}
void displayMenuDeepOne()
{
	putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(201); putHorLine(menuWide); cout << (char)(187); cout << endl;
	putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(186); putSpace((menuWide - menuPositions[menuNavigation / 10][0][0].length() - 14) / 2); cout << "Menu glowne > " << menuPositions[menuNavigation/10][0][0]; putSpace((menuWide - menuPositions[menuNavigation/10][0][0].length() - 14) / 2); cout << (char)(186); cout << endl;
	putSpace(menuSpaceScreen);  cout << (char)(186) << (char)(204); putHorLine(menuWide); cout << (char)(185); cout << endl;
	for (short positionsInMenu = 0; positionsInMenu < 9; positionsInMenu++)
	{
		if (menuNavigation == (positionsInMenu+1)+(menuNavigation/10)*10)
		{
			putSpace(menuSpaceScreen); cout << (char)(186) << (char)(204);
			putHorLine((menuWide - menuPositions[menuNavigation / 10][((((menuNavigation / 10) * 10) + 1) % 10) + positionsInMenu][0].length()) / 2);
			cout << menuPositions[menuNavigation / 10][((((menuNavigation / 10) * 10) + 1) % 10) + positionsInMenu][0];
			putHorLine((menuWide - menuPositions[menuNavigation / 10][((((menuNavigation / 10) * 10) + 1) % 10) + positionsInMenu][0].length()) / 2);
			cout << (char)(185) << endl;
		}
		else
		{
			putSpace(menuSpaceScreen); cout << (char)(186) << (char)(186);
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
	loading();
	do
	{

		HideCursor();
		system("cls");
		loadMenuNemes();
		cout << "Ostatnio wcisniety klawisz : " << pressedKey << endl;
		cout << "Pozycja w menu : " << menuNavigation << endl << endl;
		logo();
		menuTopBorderDeepZero();

		if (menuNavigation < 10)
		{
			displayMenuDeepZero();
			menuLegend(0);
		}
		else if (menuNavigation > 10 && menuNavigation < 100)
		{
			displayMenuDeepOne();
			menuLegend(1);
		}
		else 
		{
			displayMenuDeepTwo();
			menuLegend(2);
		}
		putSpace(menuSpaceScreen + 10);
		cout << "Miejsce na stopke programu ma zawierac np :\n";
		putSpace(menuSpaceScreen + 5);
		cout << "Zalogowany jako : Mariusz                              Godzina: 12:21\n";
		putSpace(menuSpaceScreen + 5);
		cout << "Wartosc koszyka : 0 PLN";

		pressedKey = _getch();
		menuControl();
		menuLoop();

		//odwołania do podmenu i funkcji nalepiej z plików 
		if (pressedKey == 77 || pressedKey == 13)
		{	
			if(menuNavigation > 10 && menuNavigation < 20) 
			{
				pressedKey = 0;  menuNavigation = (menuNavigation * 10) + 1; 
			}
			if (menuNavigation>0 && menuNavigation<8)
			{
				 pressedKey = 0; menuNavigation = (menuNavigation * 10) + 1;
			}
		
			switch (menuNavigation)
			{
			
			case 8: system("cls");  ascii(); cout << "\n\n";  system("pause"); break; //odwołanie funcji ascii z pliku ascii.cpp
			case 9: menuNavigation =menuNavigation* 10+3; pressedKey = 0; break;

			case 93: exit(0); break;
			case 94: menuNavigation /= 10; pressedKey = 0; break;
			}
		}
		else if (pressedKey == 75)
		{
			menuNavigation /= 10;
		}

	} while (pressedKey != 27); //Esc zeby wyjsc
}