///Autor:L.N.G.
///Fecha:
///Comentario:

#include <iostream>
#include <cstdlib>
#include<cstdio>
#include<cstring>
#include <locale.h>

#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;



HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int,int); // function defined below if this is new to you.



void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);

}

	void menu_medicos(){
	int menu_item=0, run, x=7;
	bool running = true;
system("cls");

	gotoXY(18,7); cout << "->";

	while(running)
	{
	    gotoXY(18,5); cout << "MENU MEDICOS";
	gotoXY(18,6); cout << "----------------------------------------";
                gotoXY(20,7);  cout << "1) NUEVO MEDICO";
		gotoXY(20,8);  cout << "2) MODIFICAR MEDICO";
		gotoXY(20,9);  cout << "3) LISTAR TODOS LOS MEDICOS";
		gotoXY(20,10); cout << "4) LISTAR MEDICO POR NRO DE MATRICULA";
		gotoXY(18,11); cout << "---------------------------------------";
		gotoXY(20,12); cout << "0) VOLVER AL MENU PRINCIPAL";

		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(0x28) & 0x8000 && x != 12) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";

				if(x==11){
                    gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";
				}

				menu_item++;
				continue;

			}

		if(GetKeyState(0x26) & 0x8000 && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				if(x==11){
                    gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				}
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed

			switch(menu_item){

				case 0: {

					gotoXY(20,16);
					cout << "You chose Input...     ";
					break;
				}


				case 1: {
					gotoXY(20,16);
					cout << "You chose Output...     ";
					break;
				}

				case 2: {
					gotoXY(20,16);
					cout << "You chose Option 3...     ";
					break;
				}

				case 3: {
					gotoXY(20,16);
					cout << "You chose Option 4...     ";
					break;
				}



				case 4: {
					gotoXY(20,16);
					cout << "BACK";
					running = false;
					system("cls");
				}

			}

		}

	}

	gotoXY(20,21);


	}

	void menu_pacientes(){
	int menu_item=0, run, x=7;
	bool running = true;
	system("cls");


	gotoXY(18,7); cout << "->";

	while(running)
	{
	    gotoXY(18,5); cout << "MENU PACIENTES";
	gotoXY(18,6); cout << "-------------------";
                gotoXY(20,7);  cout << "1) NUEVO PACIENTE";
		gotoXY(20,8);  cout << "2) MODIFICAR PACIENTE";
		gotoXY(20,9);  cout << "3) LISTAR PACIENTE POR DNI";
		gotoXY(20,10); cout << "4) LISTAR TODOS LOS PACIENTES";
		gotoXY(20,11); cout << "5) ELIMINAR PACIENTE";
		gotoXY(18,12); cout << "-------------------";
		gotoXY(20,13); cout << "0) VOLVER AL MENU PRINCIPAL";

		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(0x28) & 0x8000 && x != 13) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";

				if(x==12){
                    gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";
				}

				menu_item++;
				continue;

			}

		if(GetKeyState(0x26) & 0x8000 && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				if(x==12){
                    gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				}
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed

			switch(menu_item){

				case 0: {

					gotoXY(20,16);
					cout << "You chose Input...     ";
					break;
				}


				case 1: {
					gotoXY(20,16);
					cout << "You chose Output...     ";
					break;
				}

				case 2: {
					gotoXY(20,16);
					cout << "You chose Option 3...     ";
					break;
				}

				case 3: {
					gotoXY(20,16);
					cout << "You chose Option 4...     ";
					break;
				}

				case 4: {
					gotoXY(20,16);
					cout << "You chose Option 5...     ";
					break;
				}

				case 5: {
					gotoXY(20,16);
					cout << "The program has now terminated!!";
					running = false;
					system("cls");
				}

			}

		}

	}

	gotoXY(20,21);

	}



	void menu_principal(){
	int menu_item=0, run, x=7;
	bool running = true;


	gotoXY(18,7); cout << "->";

	while(running)
	{



	     if(x==7){
            gotoXY(18,7); cout << "->";

	     }

	     if(x==8){
            gotoXY(18,8); cout << "->";

	     }

	     gotoXY(18,5); cout << "MENU PRINCIPAL";
	gotoXY(18,6); cout << "------------------------";

                gotoXY(20,7);  cout << "1) PACIENTES";
		gotoXY(20,8);  cout << "2) MEDICOS";
		gotoXY(20,9);  cout << "3) CONTROLES";
		gotoXY(20,10); cout << "4) REPORTES";
		gotoXY(20,11); cout << "5) CONFIGURACION";
		gotoXY(18,12); cout << "------------------------";
		gotoXY(20,13); cout << "0) SALIR DEL PROGRAMA";

		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(0x28) & 0x8000 && x != 13) //down button pressed
			{


				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";

				if(x==12){
                    gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";
				}

				menu_item++;
				continue;

			}

		if(GetKeyState(0x26) & 0x8000 && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				if(x==12){
                    gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				}
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed

			switch(menu_item){

				case 0: {

					menu_pacientes();
					break;
				}


				case 1: {
					menu_medicos();
					break;
				}

				case 2: {
					gotoXY(20,16);
					cout << "You chose Option 3...     ";
					break;
				}

				case 3: {
					gotoXY(20,16);
					cout << "You chose Option 4...     ";
					break;
				}

				case 4: {
					gotoXY(20,16);
					cout << "You chose Option 5...     ";
					break;
				}

				case 5: {
					gotoXY(20,16);
					cout << "The program has now terminated!!";
					running = false;
				}

			}

		}

	}

	gotoXY(20,21);}

int main (){

    menu_principal();

	return 0;
}

