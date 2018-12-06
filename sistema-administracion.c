#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Prototipos de funcion
void MenuPrincipal();
void MenuAdministracionHotel();
void MenuHabitaciones();
int CalculoCliente(int TipoHabit,int nHabit, int nNoches );
void VaciarHabitaciones();
void MostrarHabitaciones();
void LlenarHabitacion();
void VaciarHabitacion();


//Variables
int i,j;
int SeleccionPrincipal,SeleccionHotel,SeleccionHabitaciones;
int CantidadNoches,CantidadHabitaciones,precio,Salida;
int Ocupado = 1, Vacio = 0;
char ConfirmaCompra[3];
int Habitaciones[3][5],Fila,Columna;
int AcumuladorHabitacion=0,AcumuladorIngresos=0;

int main() {
	do {
		MenuPrincipal(); //Manda a llamar al menu
		printf("\n Selecciona una opcion: ");
		scanf("%i",&SeleccionPrincipal);
		system("cls");
		SeleccionHotel = 0; // Regresamos a 0 la seleccion para que entre en el while siguiente
		if(SeleccionPrincipal == 1) { //Empieza la administracion del  hotel
			while(SeleccionHotel != 6) {
				MenuAdministracionHotel(); //Llama al menu del hotel
				printf("\n Selecciona una opcion: ");
				scanf("%i",&SeleccionHotel);
				system("cls");

				switch(SeleccionHotel) { // Metemos los datos introducidos en decisiones
					case 1:
						MenuHabitaciones(); //Muestra los tipos de habitaciones
						printf("\n Selecciona una opcion: ");
						scanf("%i",&SeleccionHabitaciones);
						printf("\n ¿Cuantas habitaciones desea rentar: ");
						scanf("%i",&CantidadHabitaciones);
						printf("\n ¿Cuantos noches vas a hospedarte: ");
						scanf("%i",&CantidadNoches);
						precio = CalculoCliente(SeleccionHabitaciones,CantidadHabitaciones,CantidadNoches); //Llamamos a la logica de costos
						AcumuladorHabitacion+=CantidadHabitaciones; // Acumula segun las habitaciones del dia
						AcumuladorIngresos+=precio; // Acumula los ingresos percibidos en el dia
						system("cls");
						// Muestra el resumen del cliente
						printf("\n------------------------------------------\n");
						printf("\n Resumen de compra:\n");
						printf("\n Tipo de habitacion: %i\n",SeleccionHabitaciones);
						printf("\n Cantidad de habitaciones a rentar: %i\n",CantidadHabitaciones);
						printf("\n Cantidad de noches a hospedar: %i\n",CantidadNoches);
						printf("\n Tu total es por: %i\n",precio);
						printf("\n---------------------------------------------\n");
						printf("\n Confirmar la compra (Ejem: Si/No):\n");
						scanf("%s",&ConfirmaCompra);
						system("cls");
						//Confirmamos la compra del cliente
						if(strcmp(ConfirmaCompra,"Si") == 0 || strcmp(ConfirmaCompra,"si") == 0 || strcmp(ConfirmaCompra,"SI") == 0 ) {
							printf("\n Asignale las habitaciones al cliente\n");
							MostrarHabitaciones(); //Muestra una lista de todas la habitaciones
							printf("\n");
							LlenarHabitacion(); //Llena la habitacion que introduzcamos
							system("cls");

						}

						break;

					case 2:
						VaciarHabitacion(); // Este metodo vacia una habitacion especifica que nosotros tecleemos
						break;

					case 3:
						VaciarHabitaciones(); // Este metodo vacia todas las habitaciones
						printf("\n Las Habitaciones se vaciaron exitosamente\n");
						break;
					case 4:
						printf("\n -- Listado de todas tus habitaciones ocupadas y vacias --\n");
						MostrarHabitaciones(); //Muestra las habitaciones disponibles y ocupadas
						break;

					case 5:
						// Mostramos el resumen de lo acumulado
						printf("\n ---Resumen general--- \n\n");
						printf(" El total de ingresos percibidos fueron: %i \n\n",AcumuladorHabitacion);
						printf(" El total de las habitaciones fueron: %i \n",AcumuladorIngresos);
						break;
				}

			}
			SeleccionPrincipal = 0;
		}

	} while(SeleccionPrincipal != 3);






	return 0;
}

// Metodo que muestra el menu principal
void MenuPrincipal() {
	printf("\n ---Menu Principal ---\n");
	printf(" 1. Ingreso Administracion de Hotel.\n");
	printf(" 2. Ingreso Administracion de Restaurant.\n");
	printf(" 3. Cerrar sistema.\n");
}

//Metodo que muestra el menu del hotel
void MenuAdministracionHotel() {
	printf("\n --- Bienvenido al Sistema de Hoteles ---\n");
	printf(" 1. Registro de clientes.\n");
	printf(" 2. Checkout del cliente.\n");
	printf(" 3. Vaciar todas las habitaciones.\n");
	printf(" 4. Mostrar todas las habitaciones.\n");
	printf(" 5. Corte del dia\n");
	printf(" 6. Regresar al menu principal\n");
}

//Metodo que muestra el menu de las habitaciones
void MenuHabitaciones() {
	printf("\n -- Nuestras Habitaciones Disponibles --\n");
	printf(" 1. Habitacion sencilla: $500 pesos\n");
	printf(" 2. Habitacion doble: $850 pesos\n");
	printf(" 3. Habitacion Suite Presidencial: $2500 pesos\n");
}

//Funcion que calcula los precios de las habitaciones
int CalculoCliente(int TipoHabit,int nHabit, int nNoches ) {
	int precio; //variable que retornamos

	// Calculos dependiendo del tipo de habitacion
	if(TipoHabit == 1) {
		precio = (500 * nHabit * nNoches);

	} else if(TipoHabit == 2) {
		precio = (850 * nHabit * nNoches);
	} else if(TipoHabit == 3) {
		precio = (2500 * nHabit * nNoches);
	}

	return precio; //Retornamos la variable con los datos
}

// Metodo que vacia completamente las habitaciones
void VaciarHabitaciones() {
	// Este for pone cada posicion de la matriz con ceros
	for(i =  0; i<3; i++) {
		for(j = 0; j< 5; j++) {
			Habitaciones[i][j] = Vacio;
		}
	}
	system("cls");
}

//Metodo que imprime las habitaciones
void MostrarHabitaciones() {
	printf("\n");
	//Este for recorre toda la matriz e imprime las habitaciones
	for(i =  0; i<3; i++) {
		for(j = 0; j< 5; j++) {
			printf("Habitacion %i %i = %i ",i,j,Habitaciones[i][j]);
		}
		printf("\n\n\n");
	}
}

void LlenarHabitacion() {
	//Este for llena las habitaciones con unos dependiendo del numero de habitaciones que el usuario elija
	for(i = 0; i < CantidadHabitaciones; i++) {
		printf("\nHabitacion(Ejem. 0 0): ");
		scanf("%i %i",&Fila,&Columna);
		if (Habitaciones[Fila][Columna] == Ocupado) { //Este if hace que las habitaciones no se repitan
			printf(" Habitacion ocupada, elige otra \n");
			LlenarHabitacion();//Se llama de nuevo a la funcion para que vuelva a repetir el proceso

		} else {// Si no se repite lo guarda
			Habitaciones[Fila][Columna] = Ocupado;
		}
	}
}

//Este metodo vacia especificamente una habitacion
void VaciarHabitacion() {
	char SalidaCheckout[3] = "Si"; //Iniciamos en si para que entre al while

	while(strcmp(SalidaCheckout,"si") == 0 || strcmp(SalidaCheckout,"Si") == 0 || strcmp(SalidaCheckout,"SI") == 0) {
		printf("\n Lista de habitaciones \n");
		MostrarHabitaciones();
		printf("\n");
		fflush(stdin);
		printf("¿Que habitacion deseas vaciar?(Ejem. 0 0 ): \n");
		scanf("%i %i",&Fila,&Columna); // Guardamos la habitacion con fila y columna
		Habitaciones[Fila][Columna] = Vacio; // Le colocamos el valor de vacio
		system("cls");
		printf("\n Se ha desocupado la habitacion [%i][%i] exitosamente\n",Fila,Columna);
		printf("¿Deseas desocupar otra habitacion?: ");
		scanf("%s",&SalidaCheckout);
		system("cls");
	}
	system("cls");

}
