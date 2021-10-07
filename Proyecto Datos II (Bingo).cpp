/*Proyecto de Datos 3: Bingo
Integrantes:
Arismendi, Juan Diego CI 29.655.485
Morales, Juan Carlos CI 29.655.850
Mata, Luis Eduardo CI 29.655.551
Quintero, David Alejandro CI 30.065.388
Seccion: 0500*/

#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

void DatosCartonJuan();
void DatosCartonAna();
void DatosCartonPedro();

void ColumnaB(int[][5],int,int);
void ColumnaI(int[][5],int,int);
void ColumnaN(int[][5],int,int);
void ColumnaG(int[][5],int,int);
void ColumnaO(int[][5],int,int);

void MostrarCarton(int[][5],int,int);
int ComprobarIgualdad(int[][5],int,int,int[][5],int,int);


void SumaMasAlta_Y_Baja(int,int,int);
void MayorFilaJuan(int[][5],int,int);
void MayorFilaAna(int[][5],int,int);
void MayorFilaPedro(int[][5],int,int);

void ComenzarJuego();
void NumeroNuevo(int[][5],int,int,int[][5],int,int,int[][5],int,int,int[],int);
void ComprobarNumeroNuevoEnCarton(int[][5],int,int);
void PresentarNumerosIngresados(int[],int);
void ComprobarGanador(int[][5],int,int,int&);

void LineasVerticales(int [][5],int,int,int&);
void LineasHorizontales(int[][5],int,int,int&);
void LineasDiagonales(int[][5],int,int,int&);
void CuatroEsquinas(int[][5],int,int,int&);
void MensajeGanador();
void ComprobarRespuesta(int&);
void ModificarCarton(int [][5],int,int,int,char[]);

void Opc1ModificarCarton(char[]);
void Opc2ModificarCarton(int[][5],int,int);

int i,j,k;
int CartonJuan[5][5],CartonAna[5][5],CartonPedro[5][5],Filas[5],NumerosNuevos[75],GanoJuan=0,GanoAna=0,GanoPedro=0,JuegoNuevo=0;
    int SumaJuan= 0,SumaAna= 0,SumaPedro= 0,Igualdad_JuanAna= 0,Igualdad_JuanPedro= 0,Igualdad_AnaPedro=0;
    char Nombre[8];
const int NumeroFilas= 5;
const int NumeroColumnas= 5;
const int FilasNumerosNuevos=75;
const int EspaciosNombre=2;
int main(){

    DatosCartonJuan();
    DatosCartonAna();
    DatosCartonPedro();

    if(ComprobarIgualdad(CartonJuan,NumeroFilas,NumeroColumnas,CartonAna,NumeroFilas,NumeroColumnas)==25){
        cout<<"\nLos cartones de Juan y Ana son iguales, por lo que deberan hacerlos de nuevo";
        DatosCartonJuan();
        DatosCartonAna();
    }
    if(ComprobarIgualdad(CartonJuan,NumeroFilas,NumeroColumnas,CartonPedro,NumeroFilas,NumeroColumnas)==25){
        cout<<"\nLos cartones de Juan y Pedro son iguales, por lo que deberan hacerlos de nuevo";
        DatosCartonJuan();
        DatosCartonPedro();
    }
    if(ComprobarIgualdad(CartonAna,NumeroFilas,NumeroColumnas,CartonPedro,NumeroFilas,NumeroColumnas)==25){
        cout<<"\nLos cartones de Ana y Pedro son iguales, por lo que deberan hacerlos de nuevo";
        DatosCartonAna();
        DatosCartonPedro();
    }
    cout<<"\nCarton de Juan:"<<endl;
    MostrarCarton(CartonJuan,NumeroFilas,NumeroColumnas);
    cout<<"\nCarton de Ana:"<<endl;
    MostrarCarton(CartonAna,NumeroFilas,NumeroColumnas);
    cout<<"\nCarton de Pedro:"<<endl;
    MostrarCarton(CartonPedro,NumeroFilas,NumeroColumnas);


    SumaMasAlta_Y_Baja(SumaJuan,SumaAna,SumaPedro);

    MayorFilaJuan(CartonJuan,NumeroFilas,NumeroColumnas);
    MayorFilaAna(CartonJuan,NumeroFilas,NumeroColumnas);
    MayorFilaPedro(CartonJuan,NumeroFilas,NumeroColumnas);

    ComenzarJuego();




    getch();
    return 0;
}
void DatosCartonJuan(){

    cout<<"\nNumeros del carton de Juan: \n";
    SumaJuan= 0;
    for(j=0;j<5;j++){
        for(i=0;i<5;i++){
            if(j==0){
                cout<<"\nJuan,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna B,recuerda que debe estar comprendido entre 1-15: ";
                cin>>CartonJuan[i][j];
                if(i>0){
                ColumnaB(CartonJuan,NumeroFilas,NumeroColumnas);
                }
            }
            if(j==1){
                cout<<"\nJuan,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna I,recuerda que debe estar comprendido entre 16-30: ";
                cin>>CartonJuan[i][j];
                ColumnaI(CartonJuan,NumeroFilas,NumeroColumnas);
            }
            if(j==2){
                if(i==2){
                    CartonJuan[i][j]=0;
            }
            else{
                cout<<"\nJuan,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna N,recuerda que debe estar comprendido entre 31-45: ";
                cin>>CartonJuan[i][j];
                ColumnaN(CartonJuan,NumeroFilas,NumeroColumnas);}
            }
            if(j==3){
                cout<<"\nJuan,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna G,recuerda que debe estar comprendido entre 46-60: ";
                cin>>CartonJuan[i][j];
                ColumnaG(CartonJuan,NumeroFilas,NumeroColumnas);
            }
            if(j==4){
                cout<<"\nJuan,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna O,recuerda que debe estar comprendido entre 61-75: ";
                cin>>CartonJuan[i][j];
                ColumnaO(CartonJuan,NumeroFilas,NumeroColumnas);
            }
            SumaJuan+=CartonJuan[i][j];
        }
    }
}

void DatosCartonAna(){

    cout<<"\nNumeros del carton de Ana: \n";
    SumaAna= 0;
    for(j=0;j<5;j++){
        for(i=0;i<5;i++){
            if(j==0){
                cout<<"\nAna,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna B,recuerda que debe estar comprendido entre 1-15: ";
                cin>>CartonAna[i][j];
                ColumnaB(CartonAna,NumeroFilas,NumeroColumnas);
            }
            if(j==1){
                cout<<"\nAna,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna I,recuerda que debe estar comprendido entre 16-30: ";
                cin>>CartonAna[i][j];
                ColumnaI(CartonAna,NumeroFilas,NumeroColumnas);
            }
            if(j==2){
                if(i==2){
                    CartonAna[i][j]=0;
            }
            else{
                cout<<"\nAna,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna N,recuerda que debe estar comprendido entre 31-45: ";
                cin>>CartonAna[i][j];
                ColumnaN(CartonAna,NumeroFilas,NumeroColumnas);}
            }
            if(j==3){
                cout<<"\nAna,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna G,recuerda que debe estar comprendido entre 46-60: ";
                cin>>CartonAna[i][j];
                ColumnaG(CartonAna,NumeroFilas,NumeroColumnas);
            }
            if(j==4){
                cout<<"\nAna,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna O,recuerda que debe estar comprendido entre 61-75: ";
                cin>>CartonAna[i][j];
                ColumnaO(CartonAna,NumeroFilas,NumeroColumnas);
            }
            SumaAna+=CartonAna[i][j];
        }
    }
}

void DatosCartonPedro(){

    cout<<"\nNumeros del carton de Pedro: \n";
    SumaPedro= 0;
    for(j=0;j<5;j++){
        for(i=0;i<5;i++){
            if(j==0){
                cout<<"\nPedro,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna B,recuerda que debe estar comprendido entre 1-15: ";
                cin>>CartonPedro[i][j];
                ColumnaB(CartonPedro,NumeroFilas,NumeroColumnas);
            }
            if(j==1){
                cout<<"\nPedro,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna I,recuerda que debe estar comprendido entre 16-30: ";
                cin>>CartonPedro[i][j];
                ColumnaI(CartonPedro,NumeroFilas,NumeroColumnas);
            }
            if(j==2){
                if(i==2){
                    CartonPedro[i][j]=0;
            }
            else{
                cout<<"\nPedro,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna N,recuerda que debe estar comprendido entre 31-45: ";
                cin>>CartonPedro[i][j];
                ColumnaN(CartonPedro,NumeroFilas,NumeroColumnas);}
            }
            if(j==3){
                cout<<"\nPedro,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna G,recuerda que debe estar comprendido entre 46-60: ";
                cin>>CartonPedro[i][j];
                ColumnaG(CartonPedro,NumeroFilas,NumeroColumnas);
            }
            if(j==4){
                cout<<"\nPedro,indica el numero del carton en la posicion "<<"["<<i+1<<"] de la columna O,recuerda que debe estar comprendido entre 61-75: ";
                cin>>CartonPedro[i][j];
                ColumnaO(CartonPedro,NumeroFilas,NumeroColumnas);
            }
            SumaPedro+=CartonPedro[i][j];
        }
    }
}
int ComprobarIgualdad(int Carton1[][5],int Filas,int Columnas,int Carton2[][5],int NumeroF,int NumeroC){
    int Igualdad= 0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(Carton1[i][j]==Carton2[i][j]){
                Igualdad++;
            }
        }
    }
    return Igualdad;
}

void MostrarCarton(int Carton[][5],int NumeroFilas,int NumeroColumnas){
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cout<<Carton[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}

void SumaMasAlta_Y_Baja(int SumaJuan,int SumaAna,int SumaPedro){
    if ((SumaJuan == SumaAna) or (SumaAna == SumaPedro) or (SumaJuan == SumaPedro)){
		if ((SumaJuan == SumaAna) && (SumaJuan < SumaPedro)){
			cout<<"\n\nEl carton de Pedro tiene la suma de numeros mas alta, con: "<<SumaPedro;
			cout<<"\n\nLos cartones de Juan y Ana tienen la suma de numeros mas baja, con: "<<SumaJuan;
		}
		else if ((SumaJuan == SumaAna) && (SumaJuan>SumaPedro)){
			cout<<"\n\nLos cartones de Juan y Ana tiene la suma de numeros mas alta, con: "<<SumaJuan;
			cout<<"\n\nEl carton de pedro tiene la suma de numeros mas baja, con: "<<SumaPedro;
		}
		else if ((SumaJuan == SumaPedro) && (SumaJuan < SumaAna)){
			cout<<"\n\nEl carton de Ana tiene la suma de numeros mas alta, con: "<<SumaAna;
			cout<<"\n\nLos cartones de Juan y Pedro tienen la suma de numeros mas baja, con: "<<SumaJuan;
		}
		else if ((SumaJuan == SumaPedro) && (SumaJuan > SumaAna)){
			cout<<"\n\nLos cartones de Juan y Pedro tienen la suma de numeros mas alta, con: "<<SumaJuan;
			cout<<"\n\nEl carton de Ana tiene la suma de numeros mas baja, con: "<<SumaAna;
		}
		else if ((SumaAna == SumaPedro) && (SumaAna < SumaJuan)){
			cout<<"\n\nEl carton de Juan tiene la suma de numeros mas alta, con: "<<SumaJuan;
			cout<<"\n\nLos cartones de Ana y Pedro tienen la suma de numeros mas baja, con: "<<SumaAna;
		}
		else if ((SumaAna == SumaPedro) && (SumaPedro > SumaJuan)){
			cout<<"\n\nLos cartones de Ana y pedro tienen la suma de numeros mas alta, con: "<<SumaAna;
			cout<<"\n\nEl carton de Juan tiene la suma de numeros mas baja, con: "<<SumaJuan;
		}
		else {
			cout<<"\n\nLos cartones de los tres tienen la misma suma de numeros con: "<<SumaJuan;
		}
	}


	else {
		if (SumaJuan > SumaAna){
			if (SumaJuan > SumaPedro){
				cout<<"\n\nEl carton de Juan tiene la suma de numeros mas alta, con: "<<SumaJuan;
			}
			else {
				cout<<"\n\nEl carton de Pedro tiene la suma de numeros mas alta, con: "<<SumaPedro;
			}
		}
		else {
			if (SumaAna > SumaPedro){
				cout<<"\n\nEl carton de Ana tiene la suma de numeros mas alta, con: "<<SumaAna;
			}
			else {
				cout<<"\n\nEl carton de Pedro tiene la suma de numeros mas alta, con: "<<SumaPedro;
			}


		if ((SumaJuan < SumaPedro) && (SumaJuan < SumaAna)){
			cout<<"\n\nEl carton de Juan tiene la suma de numeros mas baja, con: "<<SumaJuan;
		}
		else if ((SumaAna < SumaJuan) && (SumaAna < SumaPedro)){
			cout<<"\n\nEl carton de Ana tiene la suma de numeros mas baja, con "<<SumaAna;
		}
		else if ((SumaPedro < SumaJuan)&&(SumaPedro < SumaAna)){
			cout<<"\n\nEl carton de Pedro tiene la suma de numeros mas baja, con: "<<SumaPedro;
		}	}
} }

void MayorFilaJuan(int Carton[][5],int NumeroFilas,int NumeroColumnas){
    int FilaMayor=0,Posicion=0;
    for(j=0;j<5;j++){
        Filas[j]=(Carton[j][0]+ Carton[j][1]+ Carton[j][2]+ Carton[j][3]+ Carton[j][4])/5;
        if(Filas[j]>FilaMayor){
            FilaMayor=Filas[j];
            Posicion= j;
        }
    }
    cout<<"\nEl promedio de fila mas alto de Juan es "<<FilaMayor<<" en la fila #"<<Posicion+1<<endl;
}

void MayorFilaAna(int Carton[][5],int NumeroFilas,int NumeroColumnas){
    int FilaMayor=0,Posicion=0;
    for(j=0;j<5;j++){
        Filas[j]=(Carton[j][0]+ Carton[j][1]+ Carton[j][2]+ Carton[j][3]+ Carton[j][4])/5;
        if(Filas[j]>FilaMayor){
            FilaMayor=Filas[j];
            Posicion= j;
        }
    }
    cout<<"\nEl promedio de fila mas alto de Ana es "<<FilaMayor<<" en la fila #"<<Posicion+1<<endl;
}

void MayorFilaPedro(int Carton[][5],int NumeroFilas,int NumeroColumnas){
    int FilaMayor=0,Posicion=0;
    for(j=0;j<5;j++){
        Filas[j]=(Carton[j][0]+ Carton[j][1]+ Carton[j][2]+ Carton[j][3]+ Carton[j][4])/5;
        if(Filas[j]>FilaMayor){
            FilaMayor=Filas[j];
            Posicion= j;
        }
    }
    cout<<"\nEl promedio de fila mas alto de Pedro es "<<FilaMayor<<" en la fila #"<<Posicion+1<<endl;
}

void ColumnaB(int Carton[][5],int NumeroFilas,int NumeroColumnas){
    while((Carton[i][j]<1) or (Carton[i][j]>15)){
        cout<<"\nEl numero que has ingresado no se encuentra disponible en el intervalo, ingresalo nuevamente, recuerda que debe estar comprendido entre 1-15: ";
        cin>>Carton[i][j];	}
    while((Carton[i][j]==Carton[i-1][j])or(Carton[i][j]==Carton[i-2][j])or(Carton[i][j]==Carton[i-3][j])or(Carton[i][j]==Carton[i-4][j])){            //.
        cout<<"\nNo se pueden repetir numeros en una misma columna, vuelve a ingresar el numero de la columna B en la posicion "<<i+1<<": ";
        cin>>Carton[i][j];
        while((Carton[i][j]<1) or (Carton[i][j]>15)){
            cout<<"\nEl numero que has ingresado no se encuentra disponible en el intervalo, ingresalo nuevamente, recuerda que debe estar comprendido entre 1-15: ";
            cin>>Carton[i][j];	}	}
}
void ColumnaI(int Carton[][5],int NumeroFilas,int NumeroColumnas){
    while((Carton[i][j]<16) or (Carton[i][j]>30)){
        cout<<"\nEl numero que has ingresado no se encuentra disponible en el intervalo, ingresalo nuevamente, recuerda que debe estar comprendido entre 16-30: ";
        cin>>Carton[i][j];	}
    while((Carton[i][j]==Carton[i-1][j])or(Carton[i][j]==Carton[i-2][j])or(Carton[i][j]==Carton[i-3][j])or(Carton[i][j]==Carton[i-4][j])){            //.
        cout<<"\nNo se pueden repetir numeros en una misma columna, vuelve a ingresar el numero de la columna I en la posicion "<<i+1<<": ";
        cin>>Carton[i][j];
        while((Carton[i][j]<16) or (Carton[i][j]>30)){
            cout<<"\nEl numero que has ingresado no se encuentra disponible en el intervalo, ingresalo nuevamente, recuerda que debe estar comprendido entre 16-30: ";
            cin>>Carton[i][j];	}	}
}
void ColumnaN(int Carton[][5],int NumeroFilas,int NumeroColumnas){
    while((Carton[i][j]<31) or (Carton[i][j]>45)){
        cout<<"\nEl numero que has ingresado no se encuentra disponible en el intervalo, ingresalo nuevamente, recuerda que debe estar comprendido entre 31-45: ";
        cin>>Carton[i][j];	}
    while((Carton[i][j]==Carton[i-1][j])or(Carton[i][j]==Carton[i-2][j])or(Carton[i][j]==Carton[i-3][j])or(Carton[i][j]==Carton[i-4][j])){            //.
        cout<<"\nNo se pueden repetir numeros en una misma columna, vuelve a ingresar el numero de la columna N en la posicion "<<i+1<<": ";
        cin>>Carton[i][j];
        while((Carton[i][j]<31) or (Carton[i][j]>45)){
            cout<<"\nEl numero que has ingresado no se encuentra disponible en el intervalo, ingresalo nuevamente, recuerda que debe estar comprendido entre 31-45: ";
            cin>>Carton[i][j];	}	}
}
void ColumnaG(int Carton[][5],int NumeroFilas,int NumeroColumnas){
    while((Carton[i][j]<46) or (Carton[i][j]>60)){
        cout<<"\nEl numero que has ingresado no se encuentra disponible en el intervalo, ingresalo nuevamente, recuerda que debe estar comprendido entre 46-60: ";
        cin>>Carton[i][j];	}
    while((Carton[i][j]==Carton[i-1][j])or(Carton[i][j]==Carton[i-2][j])or(Carton[i][j]==Carton[i-3][j])or(Carton[i][j]==Carton[i-4][j])){            //.
        cout<<"\nNo se pueden repetir numeros en una misma columna, vuelve a ingresar el numero de la columna G en la posicion "<<i+1<<": ";
        cin>>Carton[i][j];
        while((Carton[i][j]<46) or (Carton[i][j]>60)){
            cout<<"\nEl numero que has ingresado no se encuentra disponible en el intervalo, ingresalo nuevamente, recuerda que debe estar comprendido entre 46-60: ";
            cin>>Carton[i][j];	}	}
}
void ColumnaO(int Carton[][5],int NumeroFilas,int NumeroColumnas){
    while((Carton[i][j]<61) or (Carton[i][j]>75)){
        cout<<"\nEl numero que has ingresado no se encuentra disponible en el intervalo, ingresalo nuevamente, recuerda que debe estar comprendido entre 61-75: ";
        cin>>Carton[i][j];	}
    while((Carton[i][j]==Carton[i-1][j])or(Carton[i][j]==Carton[i-2][j])or(Carton[i][j]==Carton[i-3][j])or(Carton[i][j]==Carton[i-4][j])){            //.
        cout<<"\nNo se pueden repetir numeros en una misma columna, vuelve a ingresar el numero de la columna O en la posicion "<<i+1<<": ";
        cin>>Carton[i][j];
        while((Carton[i][j]<61) or (Carton[i][j]>75)){
            cout<<"\nEl numero que has ingresado no se encuentra disponible en el intervalo, ingresalo nuevamente, recuerda que debe estar comprendido entre 61-75: ";
            cin>>Carton[i][j];	}	}
}

void ComenzarJuego(){
    int Respuesta=0;
    cout<<"\n\n\tInicio del Juego"<<endl;
    if(JuegoNuevo==0){
    cout<<"Escriba '1' si desea empezar a jugar o escriba '2' si desea terminar el juego: ";cin>>Respuesta;
        }
    else if(JuegoNuevo>0){
        cout<<"Escriba '1' si desea jugar de nuevo o escriba '2' si desea terminar el juego: ";cin>>Respuesta;
    }

    ComprobarRespuesta(Respuesta);

    if(Respuesta==1){
        cout<<"\n\t\tEl Juego de Bingo ha iniciado"<<endl;
        if(JuegoNuevo>0){
           strcpy(Nombre,"Juan");
           ModificarCarton(CartonJuan,NumeroFilas,NumeroColumnas,Respuesta,Nombre);

           strcpy(Nombre,"Ana");
           ModificarCarton(CartonAna,NumeroFilas,NumeroColumnas,Respuesta,Nombre);

           strcpy(Nombre,"Pedro");
           ModificarCarton(CartonPedro,NumeroFilas,NumeroColumnas,Respuesta,Nombre);
        }
        cout<<"\nAhora se le pediran los numeros en el orden que vayan saliendo,si en algun momento desea ver "<<endl<<"los numeros que hayan salido previamente escriba el numero 0."<<endl;

        NumeroNuevo(CartonJuan,NumeroFilas,NumeroColumnas,CartonAna,NumeroFilas,NumeroColumnas,CartonPedro,NumeroFilas,NumeroColumnas,Filas,FilasNumerosNuevos);
}
    else{
        cout<<"\nEl Juego de Bingo ha finalizado correctamente"<<endl;
}

}
void ComprobarRespuesta(int& Respuesta){
    while(Respuesta<1 || Respuesta>2){
        cout<<"\nLa respuesta ingresada no es valida, por favor indiquela nuevamente: ";cin>>Respuesta;

} }

void NumeroNuevo(int CartonJuan[][5],int NumeroFilas,int NumeroColumnas,int CartonAna[][5],int Fila,int Columnas,int CartonPedro[][5],int Fila2,int Columna,int F[],int FilasNumerosNuevos){
    i=0;
    GanoJuan=0;
    GanoAna=0;
    GanoPedro=0;

    while(GanoJuan==0 && GanoAna==0 && GanoPedro==0){
        cout<<i+1<<". Indique el numero que ha salido: ";cin>>Filas[i];
        while(Filas[i]<0 || Filas[i]>75){
            cout<<"El Numero que ha introducido no es valido, por favor escribalo nuevamente: ";cin>>Filas[i];
        }
        if(Filas[i]==0){
            PresentarNumerosIngresados(Filas,i);
            cout<<i+1<<". Indique el numero que ha salido: ";cin>>Filas[i];
            while(Filas[i]<0 || Filas[i]>75){
                cout<<"El Numero que ha introducido no es valido, por favor escribalo nuevamente: ";cin>>Filas[i];
        }   }

        ComprobarNumeroNuevoEnCarton(CartonJuan,NumeroFilas,NumeroColumnas);
        ComprobarNumeroNuevoEnCarton(CartonAna,NumeroFilas,NumeroColumnas);
        ComprobarNumeroNuevoEnCarton(CartonPedro,NumeroFilas,NumeroColumnas);

        ComprobarGanador(CartonJuan,NumeroFilas,NumeroColumnas,GanoJuan);
        ComprobarGanador(CartonAna,NumeroFilas,NumeroColumnas,GanoAna);
        ComprobarGanador(CartonPedro,NumeroFilas,NumeroColumnas,GanoPedro);

        i++;
    }
    MensajeGanador();
    if(JuegoNuevo==0){
        JuegoNuevo++;
    }
    ComenzarJuego();
}

void ModificarCarton(int Carton[][5],int Fil,int Col,int Respuesta,char Nombre[]){
    int opc=0;
    cout<<"\n"<<Nombre<<" deseas modificar tu carton?,escribe '1' para indicar si y '2' para indicar no: ";cin>>Respuesta;
    ComprobarRespuesta(Respuesta);
    if(Respuesta==1){
        cout<<"Escribe '1' si deseas modificar todo el carton: "<<endl<<"Escribe '2' si deseas modificar solo algunos numeros: ";
        cin>>opc;
        while (opc<1 || opc>2){
            cout<<"La opcion que ingreso no es valida por favor indicala nuevamente: ";cin>>opc;
        }
        if(opc==1){
            Opc1ModificarCarton(Nombre);
        }
        if(opc==2){
            Opc2ModificarCarton(Carton,NumeroFilas,NumeroColumnas);
        }
    }

}
void Opc1ModificarCarton(char Nombre[]){
    if(strcmp(Nombre,"Juan")==0){
        DatosCartonJuan();
            }
    if(strcmp(Nombre,"Ana")==0){
        DatosCartonAna();
            }
    if(strcmp(Nombre,"Pedro")==0){
        DatosCartonPedro();
            }
}
void Opc2ModificarCarton(int Carton[][5],int NumeroFilas, int NumeroColumnas){
    i=0;
    j=1;
    int FinalizarModificacion=1;
    while(FinalizarModificacion==1){
        cout<<"\nIndica la columna del numero que deseas modificar: ";cin>>j;
        while((j>5) || (j<1)){
            cout<<"El numero de columna no es valido, por favor ingreselo nuevamente: ";cin>>j;
                      }
        if(j-1==0){
            cout<<"Indica la fila del numero que deseas modificar: ";cin>>i;
            while((i>5) || (i<1)){
                cout<<"El numero de fila no es valido,por favor ingreselo nuevamente: ";cin>>i;
                    }
            cout<<"Indica el nuevo numero, recuerda que debe estar comprendido entre 1-15 ";
            cin>>Carton[i-1][j-1];
            i-=1;
            j-=1;
            ColumnaB(Carton,NumeroFilas,NumeroColumnas);
            while(Carton[i][j]==Carton[i-4][j] || Carton[i][j]==Carton[i-3][j] || Carton[i][j]==Carton[i-2][j] || Carton[i][j]==Carton[i-1][j] || Carton[i][j]==Carton[i+1][j] || Carton[i][j]==Carton[i+2][j] || Carton[i][j]==Carton[i+3][j] || Carton[i][j]==Carton[i+4][j]){
                cout<<"\nNo se pueden repetir numeros en una misma columna, vuelve a ingresar el numero: ";
                cin>>Carton[i][j];
                ColumnaB(Carton,NumeroFilas,NumeroColumnas);
            }

                }
        if(j-1==1){
            cout<<"Indica la fila del numero que deseas modificar: ";cin>>i;
            while((i>5) || (i<1)){
                cout<<"El numero de fila no es valido,por favor ingreselo nuevamente: ";cin>>i;
                    }
            cout<<"Indica el nuevo numero, recuerda que debe estar comprendido entre 16-30 ";
            cin>>Carton[i-1][j-1];
            i-=1;
            j-=1;
            ColumnaI(Carton,NumeroFilas,NumeroColumnas);
            while(Carton[i][j]==Carton[i-4][j] || Carton[i][j]==Carton[i-3][j] || Carton[i][j]==Carton[i-2][j] || Carton[i][j]==Carton[i-1][j] || Carton[i][j]==Carton[i+1][j] || Carton[i][j]==Carton[i+2][j] || Carton[i][j]==Carton[i+3][j] || Carton[i][j]==Carton[i+4][j]){
                cout<<"\nNo se pueden repetir numeros en una misma columna, vuelve a ingresar el numero: ";
                cin>>Carton[i][j];
                ColumnaI(Carton,NumeroFilas,NumeroColumnas);
            }
                }
        if(j-1==2){
            cout<<"Indica la fila del numero que deseas modificar,exepto la fila 3 que es el centro del carton y no se puede modificar ";cin>>i;
            while((i>5) || (i<1)|| (i==2)){
                if(i-1==2){
                    cout<<"El numero de fila que haz ingresado no se puede modificar, por favor ingreselo nuevamente: ";cin>>i;
                }
                cout<<"El numero de fila no es valido,por favor ingreselo nuevamente: ";cin>>i;
                    }
            cout<<"Indica el nuevo numero, recuerda que debe estar comprendido entre 31-45 ";
            cin>>Carton[i-1][j-1];
            i-=1;
            j-=1;
            ColumnaN(Carton,NumeroFilas,NumeroColumnas);
            while(Carton[i][j]==Carton[i-4][j] || Carton[i][j]==Carton[i-3][j] || Carton[i][j]==Carton[i-2][j] || Carton[i][j]==Carton[i-1][j] || Carton[i][j]==Carton[i+1][j] || Carton[i][j]==Carton[i+2][j] || Carton[i][j]==Carton[i+3][j] || Carton[i][j]==Carton[i+4][j]){
                cout<<"\nNo se pueden repetir numeros en una misma columna, vuelve a ingresar el numero: ";
                cin>>Carton[i][j];
                ColumnaN(Carton,NumeroFilas,NumeroColumnas);
            }
                }
        if(j-1==3){
            cout<<"Indica la fila del numero que deseas modificar: ";cin>>i;
            while((i>5) || (i<1)){
                cout<<"El numero de fila no es valido,por favor ingreselo nuevamente: ";cin>>i;
                    }
            cout<<"Indica el nuevo numero, recuerda que debe estar comprendido entre 46-60 ";
            cin>>Carton[i-1][j-1];
            i-=1;
            j-=1;
            ColumnaG(Carton,NumeroFilas,NumeroColumnas);
            while(Carton[i][j]==Carton[i-4][j] || Carton[i][j]==Carton[i-3][j] || Carton[i][j]==Carton[i-2][j] || Carton[i][j]==Carton[i-1][j] || Carton[i][j]==Carton[i+1][j] || Carton[i][j]==Carton[i+2][j] || Carton[i][j]==Carton[i+3][j] || Carton[i][j]==Carton[i+4][j]){
                cout<<"\nNo se pueden repetir numeros en una misma columna, vuelve a ingresar el numero: ";
                cin>>Carton[i][j];
                ColumnaG(Carton,NumeroFilas,NumeroColumnas);
            }
                }
        if(j-1==4){
            cout<<"Indica la fila del numero que deseas modificar: ";cin>>i;
            while((i>5) || (i<1)){
                cout<<"El numero de fila no es valido,por favor ingreselo nuevamente: ";cin>>i;
                    }
            cout<<"Indica el nuevo numero, recuerda que debe estar comprendido entre 61-75 ";
            cin>>Carton[i-1][j-1];
            i-=1;
            j-=1;
            ColumnaO(Carton,NumeroFilas,NumeroColumnas);
            while(Carton[i][j]==Carton[i-4][j] || Carton[i][j]==Carton[i-3][j] || Carton[i][j]==Carton[i-2][j] || Carton[i][j]==Carton[i-1][j] || Carton[i][j]==Carton[i+1][j] || Carton[i][j]==Carton[i+2][j] || Carton[i][j]==Carton[i+3][j] || Carton[i][j]==Carton[i+4][j]){
                cout<<"\nNo se pueden repetir numeros en una misma columna, vuelve a ingresar el numero: ";
                cin>>Carton[i][j];
                ColumnaO(Carton,NumeroFilas,NumeroColumnas);
            }
                }
        cout<<"\nSi deseas continuar modificando el carton escribe '1' y si deseas finalizar la modificacion escribe '2' "<<endl;
        cin>>FinalizarModificacion;
        ComprobarRespuesta(FinalizarModificacion);
            }
}

void ComprobarNumeroNuevoEnCarton(int Carton[][5],int NumeroFilas,int NumeroColumnas){
    for(j=0;j<5;j++){
        for(k=0;k<5;k++){
            if(Carton[k][j]==Filas[i]){
                Carton[k][j]=0;
            }
        }
    }
}

void PresentarNumerosIngresados(int Filas[],int i){
    int Auxiliar;
    for(j=0;j<i;j++){
        for(k=0;k<i;k++){
            if(Filas[k]>Filas[k+1]){
                Auxiliar= Filas[k];
                Filas[k]= Filas[k+1];
                Filas[k+1]=Auxiliar;
            }
        }
    }
    for(j=0;j<i;j++){
        cout<<Filas[j]<<" ";
    }
}

void ComprobarGanador(int Carton[][5],int NumeroFilas,int NumeroColumnas,int& Ganador){

    LineasVerticales(Carton,NumeroFilas,NumeroColumnas,Ganador);
    LineasHorizontales(Carton,NumeroFilas,NumeroColumnas,Ganador);
    LineasDiagonales(Carton,NumeroFilas,NumeroColumnas,Ganador);
    CuatroEsquinas(Carton,NumeroFilas,NumeroColumnas,Ganador);
}

void MensajeGanador(){
    if((GanoJuan==1) && (GanoAna==1) && (GanoPedro==1)){
        cout<<"\nLos tres han ganado, por lo que hay un empate."<<endl;
    }
    else if((GanoJuan==1) && (GanoAna==1)){
        cout<<"\nJuan y Ana han ganado, por lo que hay un empate."<<endl;
    }
    else if((GanoAna==1) && (GanoPedro==1)){
        cout<<"\nAna y Pedro han ganado, por lo que hay un empate."<<endl;
    }
    else if((GanoJuan==1) && (GanoPedro==1)){
        cout<<"\nJuan y Pedro han ganado, por lo que hay un empate."<<endl;
    }
    else if(GanoJuan==1){
        cout<<"\nJuan ha ganado."<<endl;
    }
    else if(GanoAna==1){
        cout<<"\nAna ha ganado."<<endl;
    }
    else if(GanoPedro==1){
        cout<<"\nPedro ha ganado"<<endl;
    }
}

void LineasVerticales(int Carton[][5],int NumeroFilas,int NumeroColumnas,int& Ganador){
    for(j=0;j<5;j++){
    if((Carton[0][j]==0) && (Carton[1][j]==0)&&(Carton[2][j]==0) && (Carton[3][j]==0) && (Carton[4][j]==0)){
        Ganador++;
    }   }
}

void LineasHorizontales(int Carton[][5],int NumeroFilas,int NumeroColumnas,int& Ganador){
    for(j=0;j<5;j++){
        if((Carton[j][0]==0) && (Carton[j][1]==0)&&(Carton[j][2]==0) && (Carton[j][3]==0) && (Carton[j][4]==0)){
            Ganador++;
    }   }
}

void LineasDiagonales(int Carton[][5],int NumeroFilas,int NumeroColumnas,int& Ganador){
    if(Carton[0][0]==0 && Carton[1][1]==0 && Carton[2][2]==0 && Carton[3][3]==0 && Carton[4][4]==0){
        Ganador++;
    }
    if(Carton[4][0]==0 && Carton[3][1]==0 && Carton[2][2]==0 && Carton[1][3]==0 && Carton[0][4]==0){
        Ganador++;
    }
}

void CuatroEsquinas(int Carton[][5],int NumeroFilas,int NumeroColumnas,int& Ganador){
    if(Carton[0][0]==0 && Carton[0][4]==0 && Carton[4][0]==0 && Carton[4][4]==0){
        Ganador++;
    }
}






