#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

const int DIA = 1;
const int MES = 2;
const int ANIO = 2013;
#include"Headers/rlutil.h"
using namespace rlutil;
#include "Headers/Fecha.h"
#include "funciones.h"
#include"Headers/pacientes.h"
#include"Headers/medicos.h"
#include"Headers/controles.h"
#include"Headers/configuracion.h"
#include"Headers/reportes.h"
#include"Headers/menus.h"


#include "venta.h"
#include "listados.h"
#include "extras.h"



int main(){
/*

  char opc;
  while(true){
    clrscr();
    setColor(LIGHTGREEN);
    cout << "MENU PRINCIPAL" << endl;
    cout << "---------------" << endl << endl;
    cout << "A) PACIENTES" << endl;
    cout << "B) VENTAS" << endl;
    cout << "C) LISTADOS" << endl;
    cout << "D) EXTRAS" << endl;
    cout << "---------------" << endl;
    cout << "0) SALIR" << endl << endl;
    cout << "OPCION: ";
    cin >> opc;

    switch(opc){
      case 'a':
      case 'A':
        menuPaciente();
      break;
      case 'b':
      case 'B':
        menuVenta();
      break;
      case 'c':
      case 'C':
        menuListados();
      break;
      case 'd':
      case 'D':
      case '4':
        menuExtras();
      break;
      case '0':
      case 'S':
      case 's':
        return 0;
      break;
    }
  }
*/


menu_principal();


  return 0;
}
