#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void mp();

void menu_futbol();
void menu_pizerria();
void menu_vehiculo();
void read_file_futbol();
void read_file_pizza();
void read_file_vehiculo();
void agregar_jugador();
void agregar_pizza();
void agregar_vehiculo();

int main(){
	mp();
}

void mp(){
	MenuPrincipal:
			int i;
			system("CLS");
			cout<<"-------------------"<<endl;
			cout<<"Menu Principal"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"1 - Menu club futbol"<<endl;
			cout<<"2 - Menu pizzeria"<<endl;
			cout<<"3 - Menu seguro vehiculos"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"4 - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;
			
			switch(i){
				case 1:
					{menu_futbol();}
					system("cls");
					goto MenuPrincipal;
					break;
				case 2:
					{menu_pizerria();}
					system("cls");
					goto MenuPrincipal;
					break;
				case 3:
					{menu_vehiculo();}
					system("cls");
					goto MenuPrincipal;
					break;	
				case 4:
					break;
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar. "<<endl;
					system("Pause");
					goto MenuPrincipal;
					break;
			}
}

void menu_futbol(){
	MenuFutbol:
			int i;
			system("CLS");
			cout<<"-------------------"<<endl;
			cout<<"Menu Club Futbol"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"1 - Agregar jugador"<<endl;
			cout<<"2 - Reporte de planilla"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"3 - Regresar a menu principal"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"4 - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;
			
			switch(i){
				case 1:
					{agregar_jugador();}
					system("Pause");
					system("cls");
					goto MenuFutbol;
					break;
				case 2:
					{read_file_futbol();}
					system("Pause");
					system("cls");
					goto MenuFutbol;
					break;
				case 3:
					break;	
				case 4:
					exit(1);
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar."<<endl;
					system("Pause");
					goto MenuFutbol;
					break;
			}
}

void menu_pizerria(){
	MenuPizzeria:
			int i;
			system("CLS");
			cout<<"-------------------"<<endl;
			cout<<"Menu Pizzeria"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"1 - Realizar pedido"<<endl;
			cout<<"2 - Generar reporte"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"3 - Regresar a menu principal"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"4 - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;
			
			switch(i){
				case 1:
					{agregar_pizza();}
					system("Pause");
					system("cls");
					goto MenuPizzeria;
					break;
				case 2:
					{read_file_pizza();}
					system("Pause");
					system("cls");
					goto MenuPizzeria;
					break;
				case 3:
					break;
				case 4:
					exit(1);
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar. "<<endl;
					system("Pause");
					goto MenuPizzeria;
					break;
			}
}

void menu_vehiculo(){
	MenuVehiculo:
			int i;
			system("CLS");
			cout<<"-------------------"<<endl;
			cout<<"Menu Seguro Vehiculo"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"1 - Cotizar seguro"<<endl;
			cout<<"2 - Leer archivo"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"3 - Regresar a menu principal"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"4 - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;
			
			switch(i){
				case 1:
					{agregar_vehiculo();}
					system("Pause");
					system("cls");
					goto MenuVehiculo;
					break;
				case 2:
					{read_file_vehiculo();}
					system("Pause");
					system("cls");
					goto MenuVehiculo;
					break;
				case 3:
					break;
				case 4:
					exit(1);
				default:
					system("cls");
					cout<<"No existe la opcion, vuelva a intentar: "<<endl;
					system("Pause");
					goto MenuVehiculo;
					break;
			}
}
