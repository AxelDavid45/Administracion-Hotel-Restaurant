#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Prototipos de funcion
void MenuPrincipal();
void MenuAdministracionHotel();
void MenuHabitaciones();
int CalculoCliente(int TipoHabit,int nHabit, int nNoches );

//Variables
int SeleccionPrincipal,SeleccionHotel,SeleccionHabitaciones;
int CantidadNoches,CantidadHabitaciones,precio,Salida;
char ConfirmaCompra;

int main() {
	do {
		MenuPrincipal(); //Manda a llamar al menu
		printf("\n Selecciona una opcion: ");
		scanf("%i",&SeleccionPrincipal);

		if(SeleccionPrincipal == 1) {
			while(SeleccionHotel != 5) {
				MenuAdministracionHotel();
				printf("\n Selecciona una opcion: ");
				scanf("%i",&SeleccionHotel);

				switch(SeleccionHotel) {
					case 1:
						MenuHabitaciones();
						printf("\n Selecciona una opcion: ");
						scanf("%i",&SeleccionHabitaciones);
						printf("\n ¿Cuantas habitaciones desea rentar: ");
						scanf("%i",&CantidadHabitaciones);
						printf("\n ¿Cuantos noches vas a hospedarte: ");
						scanf("%i",&CantidadNoches);
						precio = CalculoCliente(SeleccionHabitaciones,CantidadHabitaciones,CantidadNoches); //Llamamos a la logica de costos
						printf("\n------------------------------------------\n");
						printf("\n Resumen de compra:\n");
						printf("\n Tipo de habitacion: %i\n",SeleccionHabitaciones);
						printf("\n Cantidad de habitaciones a rentar: %i\n",CantidadHabitaciones);
						printf("\n Cantidad de noches a hospedar: %i\n",CantidadNoches);
						printf("\n Tu total es por: %i\n",precio);
						printf("\n---------------------------------------------\n");
						printf("\n Confirmar la compra:\n");
						scanf("%s",&ConfirmaCompra);
					break;
				}
				
			}


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
	printf("\n --- Bienvenido al Sistema de Hoteleria ---\n");
	printf(" 1. Registro de clientes.\n");
	printf(" 2. Checkout del cliente.\n");
	printf(" 3. Mostrar todas las habitaciones.\n");
	printf(" 4. Corte del dia\n");
	printf(" 5. Regresar al menu principal\n");
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
	int precio;

	if(TipoHabit == 1) {
		precio = (500 * nHabit * nNoches);

	} else if(TipoHabit == 2) {
		precio = (850 * nHabit * nNoches);
	} else if(TipoHabit == 3) {
		precio = (2500 * nHabit * nNoches);
	}

	return precio;


}

