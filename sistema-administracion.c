#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Prototipos de funcion
void MenuPrincipal();
void MenuAdministracionHotel();
int SeleccionPrincipal,SeleccionHotel;

int main() {
	do {
		MenuPrincipal();
		printf("\n Selecciona una opcion: ");
		scanf("%i",&SeleccionPrincipal);
		
		if(SeleccionPrincipal == 1) {
			MenuAdministracionHotel();
			printf("\n Selecciona una opcion: ");
			scanf("%i",&SeleccionHotel);
		}
		
	} while(SeleccionPrincipal != 3);
	
	
	
	
	
	
	return 0;
}


void MenuPrincipal() {
	printf("\n ---Menu Principal ---\n");
	printf(" 1. Ingreso Administracion de Hotel.\n");
	printf(" 2. Ingreso Administracion de Restaurant.\n");
	printf(" 3. Cerrar sistema.\n");
}

void MenuAdministracionHotel() {
	printf("\n --- Bienvenido al Sistema de Hoteleria ---\n");
	printf(" 1. Registro de clientes.\n");
	printf(" 2. Checkout del cliente.\n");
	printf(" 3. Mostrar todas las habitaciones.\n");
	printf(" 4. Corte del dia\n");
	printf(" 5. Regresar al menu principal\n");
}

