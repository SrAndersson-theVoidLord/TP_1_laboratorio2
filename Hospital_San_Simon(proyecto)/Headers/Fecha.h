#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
struct Fecha{
  int dia, mes, anio;
};

void mostrar_fecha(Fecha f){
  cout << f.dia << "/" << f.mes << "/" << f.anio << endl;
}
Fecha cargar_fecha(){
  Fecha aux;
  cout << "Dia: ";
  cin >> aux.dia;
  cout << "Mes: ";
  cin >> aux.mes;
  cout << "Anio: ";
  cin >> aux.anio;
  return aux;
}


#endif // FECHA_H_INCLUDED

