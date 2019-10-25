#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED


void back_up_registros();

void back_up_registros(){
    int opc;
    while(true){
            system("cls");
        cout<<"MENÚ CONFIGURACION"<<endl;
cout<<"------------------"<<endl;
cout<<"1) REALIZAR BACKUP DEL REGISTRO "<<endl;
cout<<"2) RESTAURAR BACKUP DEL REGISTRO "<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
cin>>opc;
switch(opc){
case 1:
    system("cls");
    system("copy Archivos\\Pacientes.dat Backups\\Pacientes.bkp");
system("copy Archivos\\Medicos.dat Backups\\Medicos.bkp");
system("copy Archivos\\Controles.dat Backups\\Controles.bkp");
    cout<<"BACK_UP DEL REGISTRO DEL SISTEMA REALIZADO CORRECTAMENTE"<<endl;
    break;

    case 2:
        system("cls");
         system("copy Backups\\Pacientes.bkp Archivos\\Pacientes.dat");
         system("copy Backups\\Medicos.bkp Archivos\\Medicos.dat");
         system("copy Backups\\Controles.bkp Archivos\\Controles.dat");
    cout<<"BACK_UP DEL REGISTRO DE CLIENTES RESTAURADO CORRECTAMENTE"<<endl;
    break;

    case 0:
        return;
    break;
    default:
         system("cls");
            cout<<"OPCION INORRECTA!!!"<<endl<<"POR FAVOR , INGRESE NUEVAMENTE UNA OPCION VALIDA:"<<endl;
            system("pause>nul");
    break;

}

    }

}









#endif // CONFIGURACION_H_INCLUDED
