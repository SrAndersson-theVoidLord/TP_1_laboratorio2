#ifndef CONTROLES_H_INCLUDED
#define CONTROLES_H_INCLUDED
struct Control{

    int Id;
    int Dni;
    int NroMatricula;
    float Costo;
    Fecha FechaControl;
    int Duracion;
    bool Estado;

};




const char *FILE_Control = "Archivos/Controles.dat";

long cantidadRegistosControl(){
  long bytes=0;
  FILE *p;
  p = fopen(FILE_Control, "rb");
  if (p == NULL){
    return 0;
  }
  fseek(p, 0, SEEK_END);
  bytes = ftell(p);
  fclose(p);
  return bytes/sizeof(struct Control);
}

int autonumerarControl () {
FILE *p;
int c=1;
Control reg;
p=fopen(FILE_Control, "rb");
if (p==NULL){
return c;
}
while (fread(&reg,sizeof (Control), 1, p)==1){
    c++;
}
fclose(p);

return c;
}
/*
int buscarControlVec(struct Control *v, int tam, int *valor){
  int i;
  for(i=0; i<tam; i++){
    if( v[i].Dni==valor ){
      return i;
    }
  }
  return -1;
}*/
int buscarControl(int DNI){
  int i=0;
  FILE *p;
  p = fopen(FILE_Control, "rb");
  if (p==NULL){
    return -1;
  }
  struct Control reg;
  while(fread(&reg, sizeof(struct Control), 1, p)){
    if(DNI==reg.Id ){
      fclose(p);
      return i;
    }
    i++;
  }
  fclose(p);
  return -1;
}


int buscarDni(int DNI){
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

int buscarMatricula(int Matricula){
  int i=0;
  FILE *p;
  p = fopen(FILE_Medico, "rb");
  if (p==NULL){
    return -1;
  }
  struct Medico reg;
  while(fread(&reg, sizeof(struct Medico), 1, p)){
    if(Matricula==reg.NroMatricula ){
      fclose(p);
      return i;
    }
    i++;
  }
  fclose(p);
  return -1;
}




struct Control obtenerControl(int pos){
  struct Control reg;
  FILE *p;
  p = fopen(FILE_Control, "rb");
  if (p == NULL){
        setColor(LIGHTRED);
    cout<<"ERROR: NO EXISTE EL CONTROL SOLICITADO";
  }
  else{
    fseek(p, pos*sizeof(struct Control), SEEK_SET);
    fread(&reg, sizeof(struct Control), 1, p);
    fclose(p);
  }
  return reg;
}

bool guardarControl(struct Control reg, int pos){
  FILE *p;

  if(pos >= 0){
    //MODIFICACION
    p = fopen(FILE_Control, "rb+");
    if (p == NULL){
      return false;
    }
    fseek(p, sizeof(struct Control) * pos, SEEK_SET);
  }
  else{
    //ALTA
    p = fopen(FILE_Control, "ab");
    if (p == NULL){
      return false;
    }
    fseek(p, 0, SEEK_END);
  }
  fwrite(&reg, sizeof(struct Control), 1, p);
  fclose(p);
  return true;
}

bool cargarControl(){
  clrscr();
  struct Control reg;
  setColor(LIGHTGREEN);
  reg.Id=autonumerarControl();
  cout<<"ID DE CONTROL:"<<reg.Id<<endl;
  setColor(LIGHTGREEN);
  cout << "DNI: ";
  setColor(WHITE);
  cin >> reg.Dni;
  ///VALIDAR QUE EL CODIGO NO SE REPITA:
  int pos;
  pos = buscarDni(reg.Dni);
  if (pos >= 0){


  ///cin.ignore();
  setColor(LIGHTGREEN);
  cout << "NRO. DE MATRICULA: ";
  setColor(WHITE);
  cin>>reg.NroMatricula;
  pos = buscarMatricula(reg.NroMatricula);
  if (pos >= 0){
  setColor(LIGHTGREEN);
  cout << "COSTO:$";
  setColor(WHITE);
  cin>>reg.Costo;
  if(reg.Costo<=0)return false;
  setColor(LIGHTGREEN);
    cout << "FECHA DEL CONTROL: ";
    setColor(WHITE);
 reg.FechaControl=cargar_fecha() ;
 setColor(LIGHTGREEN);
  cout << "DURACION: ";
  setColor(WHITE);
  cin >> reg.Duracion;
if(reg.Duracion<=0)return false;
  reg.Estado = 1;
  ///GRABAR CONTROL EN DISCO:
  guardarControl(reg, -1);
  return true;

  }
  setColor(LIGHTRED);
  cout<<"ERROR: MATRICULA INEXISTENTE";
  system("pause");
  return false;
}
setColor(LIGHTRED);
cout<<"ERROR: DNI INEXISTENTE";
system("pause");
return false;


}
void mostrarControl(Control art){
     setColor(LIGHTGREEN);
  cout << "----------------------------------------------------" << endl;
   setColor(LIGHTGREEN);
  cout << "ID. DEL TURNO         : " ;
  setColor(WHITE);
  cout<< art.Id << endl;
   setColor(LIGHTGREEN);
  cout << "DNI DEL PACIENTE      : ";
  setColor(WHITE);
  cout << art.Dni << endl;
   setColor(LIGHTGREEN);
  cout << "NRO. DE MATRICULA     : " ;
  setColor(WHITE);
  cout<< art.NroMatricula << endl;
   setColor(LIGHTGREEN);
  cout << "COSTO                 :$";
  setColor(WHITE);
  cout << art.Costo << endl;
   setColor(LIGHTGREEN);

  cout << "FECHA DEL CONTROL     : ";
   mostrar_fecha(art.FechaControl);
    setColor(LIGHTGREEN);
  cout << endl <<"DURACION           : ";
  setColor(WHITE);
  cout << art.Duracion << endl;
   setColor(LIGHTGREEN);
  cout << "----------------------------------------------------" << endl;
}

bool modificar_Control(){
  clrscr();
  struct Control reg;
   setColor(LIGHTGREEN);
  cout << "ID DEL CONTROL: ";
  setColor(WHITE);
  cin >> reg.Id;
  int pos;
  pos = buscarControl(reg.Id);
  if (pos >= 0){
    reg = obtenerControl(pos);
    mostrarControl(reg);
    int nuevaDuracion;
    setColor(LIGHTGREEN);
    cout << endl << endl << "NUEVA DURACION: ";
    setColor(WHITE);
    cin >> nuevaDuracion;
    if(nuevaDuracion > 0){
      reg.Duracion = nuevaDuracion;
      guardarControl(reg, pos);
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
  struct Control reg;
  cout << "CODIGO: ";
  cin >> reg.codControl;
  int pos;
  pos = buscarControl(reg.codControl);
  if (pos >= 0){
    reg = obtenerControl(pos);
    mostrarControl(reg);
    int stock;
    cout << endl << endl << "NUEVO STOCK: ";
    cin >> stock;
    if(stock > 0){
      reg.stock += stock;
      guardarControl(reg, pos);
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
bool eliminarControl(){
  clrscr();
  int Id;
  struct Control reg;
  setColor(LIGHTGREEN);
  cout << "ID DEL CONTROL: ";
  setColor(WHITE);
  cin >> Id;
  int pos;
  pos = buscarControl(Id);
  if (pos >= 0){
    reg = obtenerControl(pos);
    mostrarControl(reg);
    char opc;
    do{setColor(LIGHTGREEN);
      cout << "CONFIRMAR (S/N): ";
      setColor(WHITE);
      cin >> opc;
      opc = toupper(opc);
    }while(opc != 'S' && opc != 'N');
    if (opc == 'S'){
      reg.Estado = false;
      guardarControl(reg, pos);
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

void mostrarControl_x_ID(){
  struct Control reg;
  int ID;
  setColor(LIGHTGREEN);
  cout << "ID DEL CONTROL: ";
  setColor(WHITE);
  cin >> ID;


  FILE *p;
  p = fopen(FILE_Control, "rb");
  if (p == NULL){
        setColor(LIGHTRED);
    cout << "ERROR: NO EXISTE EL CONTROL SOLICITADO";
    return;
  }
  while (fread(&reg, sizeof(struct Control), 1, p)){
    if (reg.Id==ID){
      fclose(p);
      mostrarControl(reg);
      return;
    }
  }
  fclose(p);
  setColor(LIGHTRED);
  cout << "ERROR: NO EXISTE EL CONTROL SOLICITADO";
  return;
}

void mostrarControles(){
  struct Control reg;
  FILE *p;
  p = fopen(FILE_Control, "rb");
  if (p==NULL){
        setColor(LIGHTRED);
    cout << "ERROR DE ARCHIVO VACIO: NO HAY CONTROLES PARA MOSTRAR";
  }
  else{
    while(fread(&reg, sizeof(struct Control), 1, p)){
        if(reg.Estado == true)
        {
          mostrarControl(reg);
        }
    }
    fclose(p);
  }
}



#endif // CONTROLES_H_INCLUDED
