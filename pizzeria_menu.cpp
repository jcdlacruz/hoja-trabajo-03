#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct pizzas{
	string nombre;
	int cantidad;
	float precioUnitario;
	float descuento;
	float subTotal;
	float total;
};

void agregar_pizza(){
	Pizza:
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
		
		int i = 0, cantidad = 0;
		float destGrande = 0.10;
		float destFamiliar = 0.15;
		float destFiesta = 0.20;
		float descuento;
		float total;
		float precio;
		int precioGrande = 80;
		int precioFamiliar = 115;
		int precioFiesta = 100;
		string mensaje;
		
		cout<<"-------------------"<<endl;
		cout<<"------ Menu ------"<<endl;
		cout<<"-------------------"<<endl;
		cout<<"1 - Pizza grande Q80."<<endl;
		cout<<"2 - Pizza familiar Q115."<<endl;
		cout<<"3 - Pizza fiesta Q100."<<endl;
		cout<<"-------------------"<<endl;
		cout<<"Seleccione su opcion: ";
		cin>>i;
		
		cout<<"Ingrese cantidad de pizzas: ";
		cin>>cantidad;
		
		switch(i){
			case 1:
				total = cantidad * precioGrande;
				descuento = total * destGrande;
				precio = precioGrande;
				mensaje = "Grande";
				break;
			case 2:
				total = cantidad * precioFamiliar;
				descuento = total * destFamiliar;
				mensaje = "Familiar";
				precio = precioFamiliar;
				break;
			case 3:
				total = cantidad * precioFiesta;
				descuento = total * destFiesta;
				precio = precioFiesta;
				mensaje = "Fiesta";
				break;
			default:
				cout<<"Opcion seleccionada no existe. Intente de nuevo.";
				system("Pause");
				goto Pizza;
				break;
		}
						
		archivo.open(nombreArchivo.c_str(),ios::app);
		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");

		archivo<<mensaje<<"\t"
  		<<cantidad<<"\t"
  		<<precio<<"\t"
  		<<descuento<<"\t"
  		<<total<<"\t"
  		<<total - descuento<<endl;	
		
		archivo.close();
		
		
		
		cout<<"Orden realizada exitosamente."<<endl;
		cout<<"----- Resumen -----"<<endl;
		cout<<"Tipo pizza: "<<mensaje<<endl;
		cout<<"Cantidad: "<<cantidad<<endl;
		cout<<"Sub total: "<<total<<endl;
		cout<<"Descuento: "<<descuento<<endl;
		cout<<"Total: "<<total-descuento<<endl;
		cout<<"-------------------"<<endl;
};

void read_file_pizza(){
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
     
     pizzas lista[lineas];
     
     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }
	 
	 for(int i = 0; i < lineas; i++){		 
		 archivo>>lista[i].nombre
		 >>lista[i].cantidad
		 >>lista[i].precioUnitario
		 >>lista[i].descuento
		 >>lista[i].subTotal
		 >>lista[i].total;
	 }
	 archivo.close();
	 
	 float total=0;
	 float subGrande=0, descGrande=0;
	 float subFamiliar=0, descFamiliar=0;
	 float subFiesta=0, descFiesta=0;
	 	 
	 for(int i = 0; i < lineas; i++){
	 	total = total + lista[i].total;
	 	if(lista[i].nombre == "Grande"){
	 		subGrande = lista[i].total;
	 		descGrande = lista[i].descuento;
 		}
 	 	if(lista[i].nombre == "Familiar"){
	 		subFamiliar = lista[i].total;
	 		descFamiliar = lista[i].descuento;
 		}
 		if(lista[i].nombre == "Fiesta"){
	 		subFiesta = lista[i].total;
	 		descFiesta = lista[i].descuento;
 		}
	 }
	 
	 system("CLS");
	 cout<<"----- Reporte -----"<<endl;
	 cout<<"Total de ventas del dia Q: "<<total<<endl;
	 cout<<"Pizza grande "<<endl;
	 cout<<"- Total Q: "<<subGrande<<endl;
	 cout<<"- Total descuento Q: "<<descGrande<<endl;
	 cout<<"Pizza familiar "<<endl;
	 cout<<"- Total Q: "<<subFamiliar<<endl;
	 cout<<"- Total descuento Q: "<<descFamiliar<<endl;
	 cout<<"Pizza fiesta "<<endl;
	 cout<<"- Total Q: "<<subFiesta<<endl;
	 cout<<"- Total descuento Q: "<<descFiesta<<endl;
	 cout<<"----------------------"<<endl;
};
