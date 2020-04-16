#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct deportista{
	string nombre;
	int edad;
	string nacionalidad;
};

void agregar_jugador(){
	Jugador:
		ofstream archivo;
		string nombreArchivo;
		fflush(stdin);
		system("CLS");
		cout<<"Indique nombre de archivo: ";
		getline(cin,nombreArchivo);
		archivo.open(nombreArchivo.c_str(),ios::app);
	
		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");
		archivo.close();
		
		string nombre, nacionalidad;
		char opcion;
		int edad;

		/*Ingreso de datos*/
		fflush(stdin);
		system("CLS");
		cout<<"Ingrese nombre del jugador: "<<endl;
		getline(cin,nombre,'\n');
				
		cout<<"Ingrese nacionalidad (e/n -> e:extranjero/n:nacional): "<<endl;
		cin>>opcion;
		
		opcion = toupper(opcion);
		
		if(opcion == 'E'||opcion == 'N'){
			switch(opcion){
				case 'E':
					nacionalidad = "Extranjero";
					break;
				case 'N':
					nacionalidad = "Nacional";
					break;
			}
			
		}else{
			cout<<"Opcion ingresada no es valida. Intentelo de nuevo."<<endl;
			system("Pause");
			goto Jugador;
		}
		
		cout<<"Ingrese edad del jugador: "<<endl;
		cin>>edad;
		
		archivo.open(nombreArchivo.c_str(),ios::app);
		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");

		archivo<<nombre<<"\t"<<edad<<"\t"<<nacionalidad<<endl;	
		archivo.close();
		
		cout<<"Registro agregado exitosamente."<<endl;
};

void read_file_futbol(){
	 ifstream archivo;
	 string nombreArchivo,s, linea, nombre, nacionalidad, mensaje;
	 int lineas = 0, edad = 0, i = 0;
	 int sueldoFijo = 2500;
	 int bono = 500;
	 int edad1520 = 1400;
	 int edad2125 = 1500;
	 int edad2630 = 1200;
	 int edad30 = 800;
	 int mayorRemuneracion = 0;
	 int cont1520 = 0, cont2125 = 0, cont2630 = 0, cont30 = 0, salarioTotal = 0;
	 int sal1520 = 0, sal2125 = 0, sal2630 = 0, sal30 = 0;
	 	 
	 fflush(stdin);
	 system("CLS");
	 
	 cout<<"Ingrese nombre del archivo: ";
	 getline(cin, nombreArchivo);
	 
	 archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }	
	 
	 while(getline(archivo, s))
		lineas++;
		
     archivo.close();
     system("CLS");
     
     deportista lista[lineas];
     
     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }
	 
	 for(int i = 0; i < lineas; i++){		 
		 archivo>>lista[i].nombre
		 >>lista[i].edad
		 >>lista[i].nacionalidad;
	 }
	 archivo.close();
	 	 
	 for(int i = 0; i < lineas; i++){
	 		 	
		if((lista[i].edad >= 15) && (lista[i].edad <= 20)){
			cont1520++;
			salarioTotal = salarioTotal + sueldoFijo + edad1520;
			sal1520 = sal1520 + sueldoFijo + edad1520;
			if(lista[i].nacionalidad == "Extranjero"){
		 	    salarioTotal = salarioTotal + bono;
				sal1520 = sal1520 + bono; 	
			}
		}
		if((lista[i].edad >= 21) && (lista[i].edad <= 25)){
			cont2125++;
			salarioTotal = salarioTotal + sueldoFijo + edad2125;
			sal2125 = sal2125 + sueldoFijo + edad2125;
			if(lista[i].nacionalidad == "Extranjero"){
		 	    salarioTotal = salarioTotal + bono;
				sal2125 = sal2125 + bono;
			}
		}
		if((lista[i].edad >= 26) && (lista[i].edad <= 30)){
			cont2630++;
			salarioTotal = salarioTotal + sueldoFijo + edad2630;
			sal2630 = sal2630 + sueldoFijo + edad2630;
			if(lista[i].nacionalidad == "Extranjero"){
		 	    salarioTotal = salarioTotal + bono;
				sal2630 = sal2630 + bono;
			}
		}
		if(lista[i].edad >30){
			cont30++;
			salarioTotal = salarioTotal + sueldoFijo + edad30;
			sal30 = sal30 + sueldoFijo + edad30;
			if(lista[i].nacionalidad == "Extranjero"){
		 	    salarioTotal = salarioTotal + bono;
				sal30 = sal30 + bono;
			}
		}
	 }
	 
	 mayorRemuneracion = sal1520;
	 mensaje = "de 15 a 20.";
	 if (sal2125 > mayorRemuneracion){
	 	mayorRemuneracion = sal2125;
	 	mensaje = "de 21 a 25.";
	 }
	 if (sal2630 > mayorRemuneracion){
	 	mayorRemuneracion = sal2630;
	 	mensaje = "de 26 a 30.";
	 }
	 if (sal30 > mayorRemuneracion){
	 	mayorRemuneracion = sal30;
	 	mensaje = "mayores de 30.";
	 }
	 
	 //system("CLS");
	 cout<<"----- Reporte -----"<<endl;
	 cout<<"Salario total a pagar: "<<salarioTotal<<endl;
	 cout<<"- Total de jugadores por edad -"<<endl;
	 cout<<"-- # jugadores entre 15 - 20: "<<cont1520<<endl;
	 cout<<"-- # jugadores entre 21 - 25: "<<cont2125<<endl;
	 cout<<"-- # jugadores entre 26 - 30: "<<cont2630<<endl;
	 cout<<"-- # jugadores mayores de 30: "<<cont30<<endl;
	 cout<<"- Rango de edad mejor remunerado -"<<endl;
	 cout<<"-- "<<mensaje<<" Con una remuneracion total de: "<<mayorRemuneracion<<endl;
	 cout<<"----------------------"<<endl;
};
