#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED
struct Paciente{

    int Dni;
    char Apellidos[50];
    char Nombres[50];
    char Genero;
    Fecha FechaNac;
    int ObraSocial;
    bool Estado;
   /*
  char codPaciente[5];
  char desc[30];
  int stock;
  float pu;
  bool estado;*/
};



void mostrarPaciente(Paciente art);
const char *FILE_Paciente = "Archivos/Pacientes.dat";

long cantidadRegistosPaciente(){
  long bytes=0;
  FILE *p;
  p = fopen(FILE_Paciente, "rb");
  if (p == NULL){
    return 0;
  }
  fseek(p, 0, SEEK_END);
  bytes = ftell(p);
  fclose(p);
  return bytes/sizeof(struct Paciente);
}
/*
int buscarPacienteVec(struct Paciente *v, int tam, int *valor){
  int i;
  for(i=0; i<tam; i++){
    if( v[i].Dni==valor ){
      return i;
    }
  }
  return -1;
}*/
int buscarPaciente(int DNI){
  int i=0;
  FILE *p;
  p = fopen(FILE_Paciente, "rb");
  if (p==NULL){
    return -1;
  }
  struct Paciente reg;
  while(fread(&reg, sizeof(struct Paciente), 1, p)){
    if(DNI==reg.Dni ){
      fclose(p);
      return i;
    }
    i++;
  }
  fclose(p);
  return -1;
}
struct Paciente obtenerPaciente(int pos){
  struct Paciente reg;
  FILE *p;
  p = fopen(FILE_Paciente, "rb");
  if (p == NULL){
        setColor(LIGHTRED);
    cout<<"ERROR: NO EXISTE EL PACIENTE SOLICITADO";
  }
  else{
    fseek(p, pos*sizeof(struct Paciente), SEEK_SET);
    fread(&reg, sizeof(struct Paciente), 1, p);
    fclose(p);
  }
  return reg;
}

bool guardarPaciente(struct Paciente reg, int pos){
  FILE *p;

  if(pos >= 0){
    //MODIFICACION
    p = fopen(FILE_Paciente, "rb+");
    if (p == NULL){
      return false;
    }
    fseek(p, sizeof(struct Paciente) * pos, SEEK_SET);
  }
  else{
    //ALTA
    p = fopen(FILE_Paciente, "ab");
    if (p == NULL){
      return false;
    }
    fseek(p, 0, SEEK_END);
  }
  fwrite(&reg, sizeof(struct Paciente), 1, p);
  fclose(p);
  return true;
}

bool cargarPaciente(){
  clrscr();
  struct Paciente reg;
 setColor(LIGHTGREEN);
  cout << "DNI: ";
  setColor(WHITE);
  cin >> reg.Dni;
  ///VALIDAR QUE EL CODIGO NO SE REPITA:
  int pos;
  pos = buscarPaciente(reg.Dni);
  if (pos >= 0&& reg.Estado==false){
        setColor(LIGHTGREEN);
    cout<<"EXISTE UN REGISTRO PARA EL PACIENTE CON DNI "<<reg.Dni<<endl<<endl;
    pos = buscarPaciente(reg.Dni);
  if (pos >= 0){
    reg = obtenerPaciente(pos);
    mostrarPaciente(reg);
    char opc;
    do{
      cout << "DESEA RESTAURAR EL REGISTRO?"<<endl<<endl<<"CONFIRMAR (S/N): ";
      cin >> opc;
      opc = toupper(opc);
    }while(opc != 'S' && opc != 'N');
    if (opc == 'S'){
      reg.Estado = true;
      guardarPaciente(reg, pos);
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }

  return 2;
}





  cin.ignore();
  setColor(LIGHTGREEN);
      cout<<"APELLIDOS: ";
setColor(WHITE);
    gets(reg.Apellidos);
strlen(reg.Apellidos);
while(strlen(reg.Apellidos)==0){
setColor(LIGHTRED);
    cout<<"ERROR:CAMPO VACIO POR FAVOR INGRESE UNO O MAS APELLIDOS "<<endl;
     setColor(LIGHTGREEN);
    cout<<"APELLIDOS: ";
    setColor(WHITE);
gets(reg.Apellidos);
strlen(reg.Apellidos);
}


  setColor(LIGHTGREEN);
      cout<<"NOMBRES: ";
setColor(WHITE);
    gets(reg.Nombres);
strlen(reg.Nombres);
while(strlen(reg.Nombres)==0){
setColor(LIGHTRED);
    cout<<"ERROR:CAMPO VACIO POR FAVOR INGRESE UNO O MAS APELLIDOS "<<endl;
    setColor(LIGHTGREEN);
    cout<<"NOMBRES: ";
    setColor(WHITE);
gets(reg.Nombres);
strlen(reg.Nombres);
}


  setColor(LIGHTGREEN);
   cout << "GENERO(M - MASCULINO ; F - FEMENINO ; O - OTRO): ";
   setColor(WHITE);

  char gen;
cin>>gen;
    switch(gen)
    {

    case'M':
    case'm':
        reg.Genero= gen;
        break;

    case'F':
    case'f':
       reg.Genero= gen;
        break;

    case'X':
    case'x':
       reg.Genero = gen;
        break;
    default:
        cout<<"GENERO INEXISTENTE ,POR FAVOR INGRESE UN GENERO VALIDO:";
        break;
    }

setColor(LIGHTGREEN);
    cout << "FECHA DE NACIMIENTO: ";
    setColor(WHITE);
 reg.FechaNac=cargar_fecha() ;
 setColor(LIGHTGREEN);
  cout << "OBRA SOCIAL: ";
  setColor(WHITE);
  cin >> reg.ObraSocial;
while(reg.ObraSocial<1 || reg.ObraSocial>50){
        setColor(LIGHTRED);
     cout << "ERROR OBRA SOCIAL: TIENE QUE SER UN NRO ENTRE 1 Y 50 "<<endl;
     setColor(LIGHTGREEN);
  cout << "OBRA SOCIAL: ";
  setColor(WHITE);
  cin >> reg.ObraSocial;

}
  reg.Estado = 1;
  ///GRABAR PACIENTE EN DISCO:
  guardarPaciente(reg, -1);
  return true;
}

void mostrarPaciente(Paciente art){
    setColor(LIGHTGREEN);
  cout << "----------------------------------------------------" << endl;
  setColor(LIGHTGREEN);
  cout << "DNI                   : " ;
  setColor(WHITE);
  cout<< art.Dni << endl;
  setColor(LIGHTGREEN);
  cout << "APELLIDOS             : ";
   setColor(WHITE);
  cout<< art.Apellidos << endl;
  setColor(LIGHTGREEN);
  cout << "NOMBRES               : " ;
   setColor(WHITE);
  cout<< art.Nombres << endl;
  setColor(LIGHTGREEN);
  cout << "GENERO                : ";
   setColor(WHITE);
  cout<< art.Genero << endl;
  setColor(LIGHTGREEN);
  cout << "FECHA DE NACIMIENTO   : ";
   setColor(WHITE);
   mostrar_fecha(art.FechaNac);
   setColor(LIGHTGREEN);
  cout << endl <<"OBRA SOCIAL           : ";
   setColor(WHITE);
  cout << art.ObraSocial << endl;
  setColor(LIGHTGREEN);
  cout << "----------------------------------------------------" << endl;
}

bool modificar_Obra_social(){
  clrscr();
  struct Paciente reg;
  setColor(LIGHTGREEN);
  cout << "DNI: ";
  setColor(WHITE);
  cin >> reg.Dni;
  int pos;
  pos = buscarPaciente(reg.Dni);
  if (pos >= 0){
    reg = obtenerPaciente(pos);
    mostrarPaciente(reg);
    int nuevaObrasocial;
    setColor(LIGHTGREEN);
    cout << endl << endl << "NUEVA OBRA SOCIAL: ";
    setColor(WHITE);
    cin >> nuevaObrasocial;
    if(nuevaObrasocial > 0){
      reg.ObraSocial = nuevaObrasocial;
      guardarPaciente(reg, pos);
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}
/*
bool agregarStock(){
  clrscr();
  struct Paciente reg;
  cout << "CODIGO: ";
  cin >> reg.codPaciente;
  int pos;
  pos = buscarPaciente(reg.codPaciente);
  if (pos >= 0){
    reg = obtenerPaciente(pos);
    mostrarPaciente(reg);
    int stock;
    cout << endl << endl << "NUEVO STOCK: ";
    cin >> stock;
    if(stock > 0){
      reg.stock += stock;
      guardarPaciente(reg, pos);
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}
*/
bool eliminarPaciente(){
  clrscr();
  struct Paciente reg;
  setColor(LIGHTGREEN);
  cout << "DNI: ";
  setColor(WHITE);
  cin >> reg.Dni;
  int pos;
  pos = buscarPaciente(reg.Dni);
  if (pos >= 0){
    reg = obtenerPaciente(pos);
    mostrarPaciente(reg);
    char opc;
    do{
            setColor(LIGHTGREEN);
      cout << "CONFIRMAR (S/N): ";
    setColor(WHITE);
      cin >> opc;
      opc = toupper(opc);
    }while(opc != 'S' && opc != 'N');
    if (opc == 'S'){
      reg.Estado = false;
      guardarPaciente(reg, pos);
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}

void mostrarPaciente_x_ID(){
  struct Paciente reg;
  int DNI;
  setColor(LIGHTGREEN);
  cout << "DNI DEL PACIENTE: ";
  setColor(WHITE);
  cin >> DNI;

  FILE *p;
  p = fopen(FILE_Paciente, "rb");
  if (p == NULL){
        setColor(LIGHTRED);
    cout << "ERROR: NO EXISTE EL PACIENTE";
    return;
  }
  while (fread(&reg, sizeof(struct Paciente), 1, p)){
    if (reg.Dni==DNI){
      fclose(p);
      mostrarPaciente(reg);
      return;
    }
  }
  fclose(p);
  setColor(LIGHTRED);
  cout << "ERROR: NO EXISTE EL PACIENTE";
  return;
}

void mostrarPacientes(){
  struct Paciente reg;
  FILE *p;
  p = fopen(FILE_Paciente, "rb");
  if (p==NULL){
        setColor(LIGHTRED);
    cout << "ERROR DE ARCHIVO VACIO: NO HAY PACIENTES PARA MOSTRAR";
  }
  else{
    while(fread(&reg, sizeof(struct Paciente), 1, p)){
        if(reg.Estado == true)
        {
          mostrarPaciente(reg);
        }
    }
    fclose(p);
  }
}



#endif // PACIENTES_H_INCLUDED
