#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
/* [LNG 2023-06-11] - Definicion de los menús para las diferentes categorias.*/
void menu_principal();
void menu_pacientes();
void menu_medicos();
void menu_controles();

using namespace rlutil;

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
setColor(LIGHTGREEN);
	gotoXY(18,7); cout << "->";

	while(running)
	{
	     if(x==7||x==8||x==9||x==10){
                setColor(LIGHTGREEN);
            gotoXY(18,x); cout << "->";

	     }
	    setColor(LIGHTGREEN);
	    gotoXY(30,5); cout << "MENU MEDICOS";
	    setColor(LIGHTBLUE);
	gotoXY(18,6); cout << "----------------------------------------";
	setColor(LIGHTGREEN);
                gotoXY(20,7);  cout << "1) NUEVO MEDICO";
		gotoXY(20,8);  cout << "2) MODIFICAR MEDICO";
		gotoXY(20,9);  cout << "3) LISTAR TODOS LOS MEDICOS";
		gotoXY(20,10); cout << "4) LISTAR MEDICO POR NRO DE MATRICULA";
		setColor(LIGHTBLUE);
		gotoXY(18,11); cout << "---------------------------------------";
		setColor(LIGHTRED);
		gotoXY(20,12); cout << "0) VOLVER AL MENU PRINCIPAL";

		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(0x28) & 0x8000 && x != 12) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";

				if(x==11){
                    gotoXY(18,x); cout << "  ";
				x++;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";
				}

				menu_item++;
				continue;

			}

		if(GetKeyState(0x26) & 0x8000 && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";
				if(x==11){
                    gotoXY(18,x); cout << "  ";
				x--;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";
				}
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN)& 0x8000){ // Enter key pressed

			switch(menu_item){

				case 0: {

					clrscr();
					if (cargarMedico()){
                            gotoXY(20,16);
          cout << endl << "EL MEDICO SE CARGO CON EXITO";
          pausa();
        }
        else{
                gotoXY(20,16);
                setColor(LIGHTRED);
          cout << endl << "ERROR: NO SE PUDO CARGAR EL MEDICO";
          pausa();
          clrscr();
        }
					break;
				}


				case 1: {

					clrscr();
        if (modificar_sueldo()){
                gotoXY(20,16);
          cout << "EL SUELDO DEL MEDICO SE MODIFICO CORRECTAMENTE";
        }
        else{
            gotoXY(20,16);
            setColor(LIGHTRED);
          cout << "ERROR: NO SE PUDO MODIFICAR EL SUELDO";
        }
        pausa();
        clrscr();
					break;
				}

				case 2: {
					clrscr();
        mostrarMedicos();
        pausa();
        system("cls");
					break;
				}

				case 3: {
					clrscr();
        mostrarMedico_x_ID();
        pausa();
        system("cls");
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


	setColor(LIGHTGREEN);
	gotoXY(18,7); cout << "->";

	while(running)
	{
	     if(x==7||x==8||x==9||x==10||x==11){
                setColor(LIGHTGREEN);
            gotoXY(18,x); cout << "->";

	     }
	    setColor(LIGHTGREEN);
	    gotoXY(27,5); cout << "MENU PACIENTES";
	setColor(LIGHTBLUE);
	gotoXY(18,6); cout << "--------------------------------";
               setColor(LIGHTGREEN);
                gotoXY(20,7);  cout << "1) NUEVO PACIENTE";
		gotoXY(20,8);  cout << "2) MODIFICAR PACIENTE";
		gotoXY(20,9);  cout << "3) LISTAR PACIENTE POR DNI";
		gotoXY(20,10); cout << "4) LISTAR TODOS LOS PACIENTES";
		gotoXY(20,11); cout << "5) ELIMINAR PACIENTE";
		setColor(LIGHTBLUE);
		gotoXY(18,12); cout << "--------------------------------";

		setColor(LIGHTRED);
		gotoXY(20,13); cout << "0) VOLVER AL MENU PRINCIPAL";

		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(0x28) & 0x8000 && x != 13) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";

				if(x==12){
                    gotoXY(18,x); cout << "  ";
				x++;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";
				}

				menu_item++;
				continue;

			}

		if(GetKeyState(0x26) & 0x8000 && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";
				if(x==12){
                    gotoXY(18,x); cout << "  ";
				x--;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";
				}
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN)& 0x8000){ // Enter key pressed

			switch(menu_item){

				case 0: {
				    clrscr();

					 if (cargarPaciente()){
          cout << endl << "EL PACIENTE SE CARGO CON EXITO";
          pausa();
          system("cls");
        }
        else{
                 setColor(LIGHTRED);
          cout << endl << "ERROR:NO SE PUDO CARGAR EL PACIENTE";
          pausa();
          system("cls");
        }
					break;
				}


				case 1: {
				    clrscr();
        if (modificar_Obra_social()){
          cout << "LA OBRA SOCIAL SE MODIFICO CORRECTAMENTE";
        }
        else{
                 setColor(LIGHTRED);
          cout << "ERROR: NO SE PUDO MODIFICAR LA OBRA SOCIAL";
        }
        pausa();
        system("cls");

					break;
				}

				case 2: {
					 clrscr();
        mostrarPaciente_x_ID();
        pausa();
        system("cls");
					break;
				}

				case 3: {
					 clrscr();
        mostrarPacientes();
        pausa();
        system("cls");
					break;
				}

				case 4: {
					  clrscr();
        if (eliminarPaciente()){
          cout << "EL PACIENTE SE ELIMINO CORRECTAMENTE";
        }
        else{
                 setColor(LIGHTRED);
          cout << "ERROR: NO SE PUDO ELIMINAR EL PACIENTE";
        }
        pausa();
        system("cls");

					break;
				}

				case 5: {
					gotoXY(20,16);

					running = false;
        system("cls");
				}

			}

		}

	}

	gotoXY(20,21);

	}



	void menu_principal(){
	    system("cls");
	int menu_item=0, run, x=7;
	bool running = true;

	setColor(LIGHTGREEN);
gotoXY(18,x); cout << "->";

	while(running)
	{



	     if(x==7||x==8||x==9||x==10||x==11){
                setColor(LIGHTGREEN);
            gotoXY(18,x); cout << "->";

	     }


	     setColor(LIGHTGREEN);
	     gotoXY(23,5); cout << "MENU PRINCIPAL";
	setColor(LIGHTBLUE);
	gotoXY(18,6); cout << "------------------------";
                setColor(LIGHTGREEN);
                gotoXY(20,7);  cout << "1) PACIENTES";
		gotoXY(20,8);  cout << "2) MEDICOS";
		gotoXY(20,9);  cout << "3) CONTROLES";
		gotoXY(20,10); cout << "4) REPORTES";
		gotoXY(20,11); cout << "5) CONFIGURACION";
		setColor(LIGHTBLUE);
		gotoXY(18,12); cout << "------------------------";
		setColor(LIGHTRED);
		gotoXY(20,13); cout << "0) SALIR DEL PROGRAMA";

		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(0x28) & 0x8000 && x != 13) //down button pressed
			{


				gotoXY(18,x); cout << "  ";
				x++;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";

				if(x==12){
                    gotoXY(18,x); cout << "  ";
				x++;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";
				}

				menu_item++;
				continue;

			}

		if(GetKeyState(0x26) & 0x8000 && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";
				if(x==12){
                    gotoXY(18,x); cout << "  ";
				x--;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";
				}
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN)& 0x8000){ // Enter key pressed

			switch(menu_item){

				case 0: {

					menu_pacientes();

        system("cls");
					break;
				}


				case 1: {
					menu_medicos();

        system("cls");
					break;
				}

				case 2: {
					gotoXY(20,16);
					menu_controles();

        system("cls");
					break;
				}

				case 3: {
					gotoXY(20,16);
					cout << "You chose Option 4...     ";
					break;
				}

				case 4: {
					gotoXY(20,16);
					back_up_registros();

        system("cls");
					break;
				}

				case 5: {
					system("cls");
					setColor(LIGHTRED);
                gotoXY(20,7);  cout << "PROGRAMA TERMINADO";
		gotoXY(20,8);  cout << "GRACIAS POR UTILIZAR EL SISTEMA";
					running = false;
				}

			}

		}

	}

	gotoXY(20,21);}


	void menu_controles(){
	int menu_item=0, run, x=7;
	bool running = true;
	system("cls");


	setColor(LIGHTGREEN);
	gotoXY(18,7); cout << "->";

	while(running)
	{
	     if(x==7||x==8||x==9||x==10||x==11){
                setColor(LIGHTGREEN);
            gotoXY(18,x); cout << "->";

	     }
	    setColor(LIGHTGREEN);
	    gotoXY(27,5); cout << "MENU CONTROLES";
	setColor(LIGHTBLUE);
	gotoXY(18,6); cout << "--------------------------------";
               setColor(LIGHTGREEN);
                gotoXY(20,7);  cout << "1) NUEVO CONTROL";
		gotoXY(20,8);  cout << "2) MODIFICAR CONTROL";
		gotoXY(20,9);  cout << "3) LISTAR CONTROL POR ID";
		gotoXY(20,10); cout << "4) LISTAR TODOS LOS CONTROLES";
		gotoXY(20,11); cout << "5) CANCELAR CONTROL";
		setColor(LIGHTBLUE);
		gotoXY(18,12); cout << "--------------------------------";

		setColor(LIGHTRED);
		gotoXY(20,13); cout << "0) VOLVER AL MENU PRINCIPAL";

		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetKeyState(0x28) & 0x8000 && x != 13) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";

				if(x==12){
                    gotoXY(18,x); cout << "  ";
				x++;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";
				}

				menu_item++;
				continue;

			}

		if(GetKeyState(0x26) & 0x8000 && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";
				if(x==12){
                    gotoXY(18,x); cout << "  ";
				x--;
				setColor(LIGHTGREEN);
				gotoXY(18,x); cout << "->";
				}
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN)& 0x8000){ // Enter key pressed

			switch(menu_item){

				case 0: {
				    clrscr();

					 if (cargarControl()){
          cout << endl << "EL CONTROL SE CARGO CON EXITO";
          pausa();
        system("cls");
        }
        else{
                 setColor(LIGHTRED);
          cout << endl << "ERROR:NO SE PUDO CARGAR EL CONTROL";
          pausa();
        system("cls");
        }
					break;
				}


				case 1: {
				    clrscr();
        if (modificar_Control()){
          cout << "EL CONTROL SE MODIFICO CORRECTAMENTE";
        }
        else{
                 setColor(LIGHTRED);
          cout << "ERROR: NO SE PUDO MODIFICAR EL CONTROL SOLICITADO";
        }
        pausa();
        system("cls");

					break;
				}

				case 2: {
					 clrscr();
        mostrarControl_x_ID();
        pausa();
        system("cls");
					break;
				}

				case 3: {
					 clrscr();
        mostrarControles();
        pausa();
        system("cls");
					break;
				}

				case 4: {
					  clrscr();
        if (eliminarControl()){
          cout << "EL CONTROL SE CANCELO CORRECTAMENTE";
        }
        else{
                 setColor(LIGHTRED);
          cout << "ERROR: NO SE PUDO CANCELAR EL CONTROL";
        }

        pausa();
        system("cls");
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







#endif // MENUS_H_INCLUDED
