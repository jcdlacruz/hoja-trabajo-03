#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct automovil{
	string modelo;
	string color;
	float precioInicial;
	float descuento;
	float precioFinal;
	int edad;
};

void agregar_vehiculo(){
	Vehiculo:
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
		archivo.close();
		
		fflush(stdin);
		system("CLS");
		
		int modelo = 0;
		int color = 0;
		int edad = 0;
		float precio = 0;
		float precioAblanco = 240.50;
		float precioAmetalizado = 330;
		float precioAotros = 270.50;
		float precioBblanco = 300;
		float precioBmetalizado = 360.50;
		float precioBotros = 330;
		string msnModelo;
		string msnColor;
		float desc30 = 0.25;
		float desc3165 = 0;
		float desc66 = 0.30;
		float descuento = 0;
		float precioFinal = 0;
		
		cout<<"Ingrese su edad: ";
		cin>>edad;
		
		if(edad < 18 || edad > 100){
			cout<<"Edad no aplica para compra de vehiculo. Intente de nuevo."<<endl;
			system("Pause");
			goto Vehiculo;
		}
						
		cout<<"-------------------"<<endl;
		cout<<"------ Menu ------"<<endl;
		cout<<"-------------------"<<endl;
		cout<<"1 - Modelo A."<<endl;
		cout<<"2 - Modelo B."<<endl;
		cout<<"-------------------"<<endl;
		cout<<"Seleccione su opcion: ";
		cin>>modelo;
		
		if(modelo != 1 && modelo != 2){
			system("CLS");
			cout<<"Opcion seleccionada, no existe, intente de nuevo."<<endl;
			system("Pause");
			goto Vehiculo;
		}
		
		system("CLS");
		cout<<"-------------------"<<endl;
		cout<<"------ Color ------"<<endl;
		cout<<"-------------------"<<endl;
		cout<<"1 - Blanco."<<endl;
		cout<<"2 - Metalizado."<<endl;
		cout<<"3 - Otro."<<endl;
		cout<<"-------------------"<<endl;
		cout<<"Seleccione su opcion: ";
		cin>>color;
		
		if(color != 1 && color != 2 && color != 3){
			system("CLS");
			cout<<"Opcion seleccionada, no existe, intente de nuevo."<<endl;
			system("Pause");
			goto Vehiculo;
		}
		
		switch(modelo){
			case 1:
				msnModelo = "A";
				switch(color){
					case 1:
						precio = precioAblanco;
						msnColor = "Blanco";
					case 2:
						precio = precioAmetalizado;
						msnColor = "Metalizado";
					case 3:
						precio = precioAotros;
						msnColor = "Otros";
				};
				break;
			case 2:
				msnModelo = "B";
				switch(color){
					case 1:
						precio = precioBblanco;
						msnColor = "Blanco";
					case 2:
						precio = precioBmetalizado;
						msnColor = "Metalizado";
					case 3:
						precio = precioBotros;
						msnColor = "Otros";
				};
				break;
			default:
				cout<<"Se presento un error. Intente de nuevo.";
				system("Pause");
				goto Vehiculo;
				break;
		}
		
		if(edad < 31){
			descuento = desc30;
		}else if(edad > 31){
			descuento = desc66;
		}else{
			descuento = desc3165;
		}
		
		precioFinal = precio + (precio * descuento);
						
		archivo.open(nombreArchivo.c_str(),ios::app);
		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");

		archivo<<msnModelo<<"\t"
  		<<msnColor<<"\t"
  		<<precio<<"\t"
  		<<descuento<<"\t"
  		<<precioFinal<<"\t"
  		<<edad<<endl;	
		
		archivo.close();
		
		cout<<"*Registro guardado exitosamente."<<endl;
		cout<<"Resume cotizacion "<<endl;
		cout<<"- Modelo: "<<msnModelo<<endl;
		cout<<"- Color: "<<msnColor<<endl;
		cout<<"- Precio sin descuento: "<<precio<<endl;
		cout<<"- Descuento: "<<descuento*100<<endl;
		cout<<"- Precio final: "<<precioFinal<<endl;

};

void read_file_vehiculo(){
	 ifstream archivo;
	 string nombreArchivo,s, linea, nombre;
	 	 
	 fflush(stdin);
	 system("CLS");
	 
	 cout<<"Ingrese nombre del archivo: ";
	 getline(cin, nombreArchivo);
	 
	 archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }	
	 
	 int lineas=0;
	 while(getline(archivo, s))
		lineas++;
		
     archivo.close();
     system("CLS");
     
     automovil lista[lineas];
     
     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }
	 
	 for(int i = 0; i < lineas; i++){		 
		 archivo>>lista[i].modelo
		 >>lista[i].color
		 >>lista[i].precioInicial
		 >>lista[i].descuento
		 >>lista[i].precioFinal
		 >>lista[i].edad;
	 }
	 archivo.close();
	 
	 system("CLS");	 	 
	 for(int i = 0; i < lineas; i++){
	 	if(i == 0){
	 		cout<<"Modelo"<<"\t"
				<<"Color"<<"\t"
				<<"Costo"<<"\t"
				<<"Desc"<<"\t"
				<<"Total"<<"\t"
				<<"Edad"<<endl;
		}
		cout<<lista[i].modelo<<"\t"
  		<<lista[i].color<<"\t"
  		<<lista[i].precioInicial<<"\t"
  		<<lista[i].descuento<<"\t"
  		<<lista[i].precioFinal<<"\t"
  		<<lista[i].edad<<endl;
	 }
};
