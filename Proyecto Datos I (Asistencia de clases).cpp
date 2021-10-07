/*
Proyecto I Algoritmos y estructura de datos I: Asistencia
Integrantes:
Luis Eduardo Mata CI 29.655.551
Juan Diego Arismendi CI 29.655.485
Juan Carlos Morales CI 29.655.850
David Quintero CI 30.065.388
Seccion: 0500
*/
#include<iostream>
using namespace std; 

int main(){
	int Cantidad, UnaClase, ContClase, opc1,ContTotal,NivelComprension,MujerComprension3,Edad,HombreClase2,HombreClase3,MujerComprension;
	char Sexo;
	cout<<"Indique la cantidad de alumnos que cursan la materia: ";cin>>Cantidad;
	ContClase=1 ;
	UnaClase= 0;
	HombreClase2= 0,HombreClase3= 0;
	MujerComprension3 = 0;
	int Diferencia = 0,AlumnosMayores= 0,Bandera= 0,opc2, opc3, opc4;
	float Porcentaje= 0,Promedio= 0,AsisClase1,AsisClase2,AsisClase3;
	ContClase= 1;AsisClase1=0;AsisClase2=0;AsisClase3=0;
	if(Cantidad>0){
		
		while(ContClase<=Cantidad){
			Bandera= 0;
			cout<<"\n\nIndique su sexo utilizando una M o una F (en mayuscula): ";cin>>Sexo;
			if((Sexo!='F') && (Sexo!='M')){
				cout<<"\nEl sexo introducido no es valido";
				ContClase-= 1;
			}
			else{
			cout<<"\nIndique su edad: ";cin>>Edad;
			cout<<"\n\tAsistencia de la clases de Algoritmos y base de datos."<<endl;
			cout<<"\nOpcion 1.Si observo al menos una clase";
			cout<<"\nOpcion 2.Si no observo ninguna clase"<<endl;
			cin>>opc1;						
			
			switch(opc1){
				case 1:UnaClase+=1;break;			
				case 2:break;
				default:cout<<"\nLa opcion ingresada no se encuentra disponible, se le volveran a solicitar todos sus datos";
				Bandera+= 1;break;
			}
			if(Bandera>0){
				ContClase-=1;
			}
			else{
			if(opc1==2){
			}
			else{
			cout<<"\n\tAsistencia de la clase de Lectura, escritura y asignacion."<<endl;
			cout<<"\nOpcion 1.Si observo la clase de Lectura, escritura y asignacion";
			cout<<"\nOpcion 2.Si no observo la clase de lectura, escritura y asignacion"<<endl;
			cin>>opc2;
			switch(opc2){
				case 1:AsisClase1+=1;break;
				case 2:break;
				default:cout<<"\nLa opcion ingresada no se encuentra disponible, se le volveran a solicitar todos sus datos";
				Bandera+= 1;break;
			}
			if(Bandera>0){
				ContClase-=1;
				if(opc1==1){
					UnaClase-= 1;
				}
			}
			else{
			
			cout<<"\t\nAsistencia de la clase de Condicionales."<<endl;
			cout<<"\nOpcion 1.Si observo la clase de Condicionales";
			cout<<"\nOpcion 2.Si no observo la clase de condicionales"<<endl;
			cin>>opc3;
			switch(opc3){
				case 1:AsisClase2+= 1;break;
				case 2:break;
				default:cout<<"\nLa opcion ingresada no se encuentra disponible, se le volveran a solicitar todos sus datos";
				Bandera+= 1;break;
			}
			if(Bandera>0){
				ContClase-=1;
				if(opc1==1){
					UnaClase-= 1;
				}
				if(opc2==1){
					AsisClase1-=1;
				}
			}
			else{
			
			if(opc3==1){
				if((Sexo=='M') &&(Edad>20)){
					HombreClase2+= 1;
			}
		}
			if(opc3==1){
				if(Sexo=='F'){
				cout<<"Indique puntuando entre 1-10 su nivel de comprension de la clase de Condicionales: ";cin>>NivelComprension;
					if(NivelComprension>3){
						MujerComprension3+= 1;
				}
				}
			}
			cout<<"\t\nAsistencia de la clase de Ciclos."<<endl;
			cout<<"\nOpcion 1.Si observo la clase de ciclos";
			cout<<"\nOpcion 2.Si no observo la clase de ciclos"<<endl;
			cin>>opc4;
			switch(opc4){
				case 1:AsisClase3+=1;break;
				case 2:break;
				default:cout<<"\nLa opcion ingresada no se encuentra disponible, se le volveran a solicitar todos sus datos";
				Bandera+= 1;break;
			}
			if(Bandera>0){
				ContClase-=1;
				if(opc1==1){
					UnaClase-= 1;
				}
				if(opc2){
					AsisClase1-= 1;
				}
				if(opc2){
					AsisClase2-= 1;
				}
				if(opc3==1){
				if((Sexo=='M') &&(Edad>20)){
					HombreClase2-= 1;
				}
				if(NivelComprension>3){
						MujerComprension3-= 1;
				}
				
			}
		}
			
			if(opc4==1){
			if((Sexo=='M') &&(Edad>20)){
				HombreClase3+= 1;
			}
		}
			if(Edad>=18){
				AlumnosMayores+= 1;
			}
	

}
}
}
}
}
	
	ContClase+= 1;
}
	

	Promedio= (AsisClase1 + AsisClase2 + AsisClase3)/3;
	
	cout<<"\nLa cantidad de alumnos que observaron al menos una clase es: "<<UnaClase<<endl;
	cout.precision(3);
	cout<<"\nEl promedio de clases vistas por los alumnos es: "<<Promedio<<endl;
	cout<<"\nLa cantidad de alumnos mayores de edad es: "<<AlumnosMayores<<endl;
	cout<<"\nLa cantidad de mujeres con un nivel de comprension mayor a 3 en la clase de condicionales es: "<<MujerComprension3<<endl;
	cout<<"\nLa cantidad de alumnos que observaron la clase de Lectura, escritura y asignacion es: "<<AsisClase1<<endl;
	cout<<"\nLa cantidad de alumnos que observaron la clase de condicionales es: "<<AsisClase2<<endl;
	cout<<"\nLa cantidad de personas que vieron la clase de ciclos es: "<<AsisClase3<<endl;
	if (AsisClase1>AsisClase2) {
	
		Diferencia = AsisClase1 - AsisClase2;
		Porcentaje = (Diferencia * 100) / AsisClase1;
		cout<<"\nLa asistencia de la clase 'Lectura, Escritura y Asignacion' a la clase de 'Condicionales' disminuyo un "<<Porcentaje<<"%"<<endl; 
	}
	else if (AsisClase1<AsisClase2) {
			Diferencia = AsisClase2 - AsisClase1;
			Porcentaje = (Diferencia * 100) / AsisClase1;
			cout<<"\nLa asistencia de la clase 'Lectura, Escritura y Asignacion' en comparacion a la clase de 'Condicionales' aumento un "<<Porcentaje<<"%"<<endl;
		}
		else {
			cout<<"\nLa asistencia en las clases 'Lectura, Escritura y Asignacion' y 'Condicionales' no aumento ni disminuyo"<<endl;
		}
	if (HombreClase2>HombreClase3) {
		Diferencia = HombreClase2 - HombreClase3;
		Porcentaje = (Diferencia * 100) / HombreClase2;
		cout<<"\nLa asistencia de los hombres mayores a 20 años de la clase 'Condicionales' en comparacion a la clase de 'Ciclos' disminuyo un "<<Porcentaje<<"%"<<endl;
	}
	else	if  (HombreClase2<HombreClase3) {
			Diferencia  = HombreClase3 - HombreClase2;
			Porcentaje = (Diferencia * 100) / HombreClase2;
			cout<<"\nLa asistencia de los hombres mayores a 20 años de la clase 'Condicionales' en comparacion a la clase de 'Ciclos' aumento un "<<Porcentaje<<"%"<<endl;
			}
			
			else {
				cout<<"\nLa asistencia de los hombres mayores a 20 años en las clases 'Lectura, Escritura y Asignacion' y 'Condicionales' no aumento ni disminuyo"<<endl;
				}
	
}
	else{
		cout<<"\nLa cantidad ingresada no es valida";
	}
	
	
	return 0;
}
 	

