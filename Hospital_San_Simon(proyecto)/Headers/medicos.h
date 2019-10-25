#ifndef MEDICOS_H_INCLUDED
#define MEDICOS_H_INCLUDED
struct Medico{

    int NroMatricula;
    char Apellidos[50];
    char Nombres[50];
    int Especialidad;
    float Sueldo;
   /*
  char codMedico[5];
  char desc[30];
  int stock;
  float pu;
  bool estado;*/
};

const char *FILE_Medico = "Archivos/Medicos.dat";

long cantidadRegistosMedico(){
  long bytes=0;
  FILE *p;
  p = fopen(FILE_Medico, "rb");
  if (p == NULL){
    return 0;
  }
  fseek(p, 0, SEEK_END);
  bytes = ftell(p);
  fclose(p);
  return bytes/sizeof(struct Medico);
}
/*
int buscarMedicoVec(struct Medico *v, int tam, int *valor){
  int i;
  for(i=0; i<tam; i++){
    if( v[i].NroMatricula==valor ){
      return i;
    }
  }
  return -1;
}*/
int buscarMedico(int NROMATRICULA){
  int i=0;
  FILE *p;
  p = fopen(FILE_Medico, "rb");
  if (p==NULL){
    return -1;
  }
  struct Medico reg;
  while(fread(&reg, sizeof(struct Medico), 1, p)){
    if(NROMATRICULA==reg.NroMatricula ){
      fclose(p);
      return i;
    }
    i++;
  }
  fclose(p);
  return -1;
}
struct Medico obtenerMedico(int pos){
  struct Medico reg;
  FILE *p;
  p = fopen(FILE_Medico, "rb");
  if (p == NULL){
        setColor(LIGHTRED);
    cout<<"ERROR: NO EXISTE EL MEDICO SOLICITADO";
  }
  else{
    fseek(p, pos*sizeof(struct Medico), SEEK_SET);
    fread(&reg, sizeof(struct Medico), 1, p);
    fclose(p);
  }
  return reg;
}

bool guardarMedico(struct Medico reg, int pos){
  FILE *p;

  if(pos >= 0){
    //MODIFICACION
    p = fopen(FILE_Medico, "rb+");
    if (p == NULL){
      return false;
    }
    fseek(p, sizeof(struct Medico) * pos, SEEK_SET);
  }
  else{
    //ALTA
    p = fopen(FILE_Medico, "ab");
    if (p == NULL){
      return false;
    }
    fseek(p, 0, SEEK_END);
  }
  fwrite(&reg, sizeof(struct Medico), 1, p);
  fclose(p);
  return true;
}

bool cargarMedico(){
  clrscr();
  struct Medico reg;
   setColor(LIGHTGREEN);
  cout << "NRO. DE MATRICULA: ";
   setColor(WHITE);
  cin >> reg.NroMatricula;
  ///VALIDAR QUE EL CODIGO NO SE REPITA:
  int pos;
  pos = buscarMedico(reg.NroMatricula);
  if (pos >= 0){
        setColor(LIGHTRED);
    cout<<"ERROR:YA EXISTE ESE MEDICO "<<endl;
  system("pause");
    return false;
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
  cout << " ESPECIALIDAD: ";
   setColor(WHITE);
  cin >> reg.Especialidad;

  while(reg.Especialidad<1 || reg.Especialidad>20){
        setColor(LIGHTRED);
     cout << "ERROR ESPECIALIDAD: TIENE QUE SER UN NRO ENTRE 1 Y 20 "<<endl;
     setColor(LIGHTGREEN);
  cout << "ESPECIALIDAD: ";
  setColor(WHITE);
  cin >> reg.Especialidad;

}


   setColor(LIGHTGREEN);
  cout << " SUELDO:$";
   setColor(WHITE);
  cin >> reg.Sueldo;
  while(reg.Sueldo<0){
        setColor(LIGHTRED);
     cout << "ERROR SUELDO: TIENE QUE SER UN NRO REAL POSITIVO "<<endl;
     setColor(LIGHTGREEN);
  cout << "SUELDO:$";
  setColor(WHITE);
  cin >> reg.Sueldo;

}


  ///GRABAR MEDICO EN DISCO:
  guardarMedico(reg, -1);
  system("cls");
  return true;
}

void mostrarMedico(Medico art){
    setColor(LIGHTGREEN);
  cout << "----------------------------------------------------" << endl;
  setColor(LIGHTGREEN);
  cout << "NRO. DE MATRICULA                   : " ;
  setColor(WHITE);
  cout<< art.NroMatricula << endl;
  setColor(LIGHTGREEN);
  cout << "APELLIDOS             : ";
  setColor(WHITE);
  cout<< art.Apellidos << endl;
  setColor(LIGHTGREEN);
  cout << "NOMBRES               : ";
  setColor(WHITE);
  cout << art.Nombres << endl;
  setColor(LIGHTGREEN);
  cout << "ESPECIALIDAD          : ";
  setColor(WHITE);
  cout << art.Especialidad << endl;
  setColor(LIGHTGREEN);
  cout << "SUELDO                :$";
  setColor(WHITE);
  cout<< art.Sueldo << endl;
  setColor(LIGHTGREEN);
  cout << "----------------------------------------------------" << endl;
}

bool modificar_sueldo(){
  clrscr();
  struct Medico reg;
  setColor(LIGHTGREEN);

  cout << "NRO. DE MATRICULA: ";
  setColor(WHITE);
  cin >> reg.NroMatricula;
  int pos;
  pos = buscarMedico(reg.NroMatricula);
  if (pos >= 0){
    reg = obtenerMedico(pos);
    mostrarMedico(reg);
    int nuevoSueldo;
    setColor(LIGHTGREEN);

    cout << endl << endl << "NUEVO IMPORTE DE SUELDO: ";
    setColor(WHITE);
    cin >> nuevoSueldo;
    if(nuevoSueldo > 0){
      reg.Sueldo = nuevoSueldo;
      guardarMedico(reg, pos);
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
  struct Medico reg;
  cout << "CODIGO: ";
  cin >> reg.codMedico;
  int pos;
  pos = buscarMedico(reg.codMedico);
  if (pos >= 0){
    reg = obtenerMedico(pos);
    mostrarMedico(reg);
    int stock;
    cout << endl << endl << "NUEVO STOCK: ";
    cin >> stock;
    if(stock > 0){
      reg.stock += stock;
      guardarMedico(reg, pos);
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

bool eliminarMedico(){
  clrscr();
  struct Medico reg;
  cout << "NRO. DE MATRICULA: ";
  cin >> reg.NroMatricula;
  int pos;
  pos = buscarMedico(reg.NroMatricula);
  if (pos >= 0){
    reg = obtenerMedico(pos);
    mostrarMedico(reg);
    char opc;
    do{
      cout << "CONFIRMAR (S/N): ";
      cin >> opc;
      opc = toupper(opc);
    }while(opc != 'S' && opc != 'N');
    if (opc == 'S'){
      reg.Estado = false;
      guardarMedico(reg, pos);
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
void mostrarMedico_x_ID(){
  struct Medico reg;
  int NROMATRICULA;
  setColor(LIGHTGREEN);
  cout << "NRO. DE MATRICULA DEL MEDICO: ";
  setColor(WHITE);
  cin >> NROMATRICULA;

  FILE *p;
  p = fopen(FILE_Medico, "rb");
  if (p == NULL){
        setColor(LIGHTRED);
    cout << "ERROR: NO EXISTE EL MEDICO";
    return;
  }
  while (fread(&reg, sizeof(struct Medico), 1, p)){
    if (reg.NroMatricula==NROMATRICULA){
      fclose(p);
      mostrarMedico(reg);
      return;
    }
  }
  fclose(p);
  setColor(LIGHTRED);
  cout << "ERROR: NO EXISTE EL MEDICO";
  return;
}

void mostrarMedicos(){
  struct Medico reg;
  FILE *p;
  p = fopen(FILE_Medico, "rb");
  if (p==NULL){
        setColor(LIGHTRED);
    cout << "ERROR DE ARCHIVO VACIO: NO HAY MEDICOS PARA MOSTRAR";
  }
  else{
    while(fread(&reg, sizeof(struct Medico), 1, p)){

          mostrarMedico(reg);

    }
    fclose(p);
  }
}




#endif // MEDICOS_H_INCLUDED
