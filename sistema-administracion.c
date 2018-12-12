#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Structs restaurant
struct desayunos {
    char nombre[40];
};
struct comidas {
    char nombre[50];
};
struct postres {
    char nombre[40];
};
struct aguas {
    char nombre[40];
};
struct rest {
    struct desayunos desayunos;
    struct comidas comidas;
    struct postres postres;
    struct aguas aguas;
};

//Prototipos de hotel
void MenuPrincipal();
void MenuAdministracionHotel();
void MenuHabitaciones();
int CalculoCliente(int TipoHabit,int nHabit, int nNoches );
void VaciarHabitaciones();
void MostrarHabitaciones();
void LlenarHabitacion();
void VaciarHabitacion();

//Prototipos de restaurant
void MenuRestaurantPrincipal();
void MostrarDesayunos();
void MostrarBebidas();
void MostrarPostres();
void MostrarComidas();
void LlenarArregloInformaacion();
int CalculoPagoCliente(int CantidadPlatillos, int Precio);

//Variables restaurant
int tot=0, nPlatillos,nComidas,nPostres,nVasos,elec,ganan,
    SelecPrincipalRestaurant;
char fin, DesicionCase[2] = "s";
struct rest restaurante [10];

//Variables globales
int i,j;

//Variables hotel
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
        SeleccionHotel = 0;  // Regresamos a 0 la seleccion para que entre en el while siguiente
        if(SeleccionPrincipal == 1) { //Empieza la administracion del  hotel
            while(SeleccionHotel != 6) {
                MenuAdministracionHotel(); //Llama al menu del hotel
                printf("\n Selecciona una opcion: ");
                scanf("%i",&SeleccionHotel);
                system("cls");

                switch(SeleccionHotel) { // Metemos los datos introducidos en decisiones
                    case 1: // Registro del cliente
                        MenuHabitaciones(); //Muestra los tipos de habitaciones
                        printf("\n Selecciona una opcion: ");
                        scanf("%i",&SeleccionHabitaciones);
                        printf("\n ¿Cuantas habitaciones desea rentar: ");
                        scanf("%i",&CantidadHabitaciones);
                        printf("\n ¿Cuantos noches vas a hospedarte: ");
                        scanf("%i",&CantidadNoches);
                        precio = CalculoCliente(SeleccionHabitaciones,CantidadHabitaciones,
                                                CantidadNoches); //Llamamos a la logica de costos
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
                        if(strcmp(ConfirmaCompra,"Si") == 0 || strcmp(ConfirmaCompra,"si") == 0
                                || strcmp(ConfirmaCompra,"SI") == 0 ) {
                            printf("\n Asignale las habitaciones al cliente\n");
                            MostrarHabitaciones(); //Muestra una lista de todas la habitaciones
                            printf("\n");
                            LlenarHabitacion(); //Llena la habitacion que introduzcamos
                            system("cls");

                        }

                        break;

                    case 2: //Vaciar una habitacion en particular
                        VaciarHabitacion(); // Este metodo vacia una habitacion especifica que nosotros tecleemos
                        break;

                    case 3: //Vaciar todas las habitaciones
                        VaciarHabitaciones(); // Este metodo vacia todas las habitaciones
                        printf("\n Las Habitaciones se vaciaron exitosamente\n");
                        break;
                    case 4: //Lista las habitacciones ocupadas y vacias
                        printf("\n -- Listado de todas tus habitaciones ocupadas y vacias --\n");
                        MostrarHabitaciones(); //Muestra las habitaciones disponibles y ocupadas
                        break;

                    case 5: //Resumen general de ventas
                        // Mostramos el resumen de lo acumulado
                        printf("\n ---Resumen general--- \n\n");
                        printf(" El total de ingresos percibidos fueron: %i \n\n",AcumuladorHabitacion);
                        printf(" El total de las habitaciones fueron: %i \n",AcumuladorIngresos);
                        break;
                }

            }
            SeleccionPrincipal = 0; //Regresa a 0 la seleccion para que non haya problema al repetir
        }
        // If del Restaurant
        if(SeleccionPrincipal == 2) { //Si se selecciona el numero 2 del menu principal entra a esta comparacion
            LlenarArregloInformaacion(); //Este metodo llena los arreglos de structs con los datos del menu
            while(SelecPrincipalRestaurant != 6) {
                MenuRestaurantPrincipal(); //muestra el menu principal del restauran
                scanf("%i",&SelecPrincipalRestaurant);

                switch(SelecPrincipalRestaurant) {
                    case 1: // Case de desayunos
                        
						while(strcmp(DesicionCase,"s") == 0) {
						
                        system("cls");
                        MostrarDesayunos(); //muestra el menu de desayunos
                        printf("\nSelecciona tu desayuno: ");
                        scanf("%i",&elec);
                        printf("\nCuantos platillos deseas comprar?: \n");
                        scanf("%i",&nPlatillos);

                        switch(elec) { // Switch para calcular el pago por comidas
                            case 1:
                                tot = CalculoPagoCliente(nPlatillos,25); //este metodo calcula el pago pasando la cantidad y precio
                                ganan+=tot; //acumulador de ventas totales
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 2:
                                tot = CalculoPagoCliente(nPlatillos,30);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 3:
                                tot = CalculoPagoCliente(nPlatillos,25);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 4:
                                tot = CalculoPagoCliente(nPlatillos,28);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 5:
                                tot = CalculoPagoCliente(nPlatillos,15);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 6:
                                tot=CalculoPagoCliente(nPlatillos,27);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 7:
                                tot = CalculoPagoCliente(nPlatillos,30);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 8:
                                tot = CalculoPagoCliente(nPlatillos,28);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 9:
                                tot=CalculoPagoCliente(nPlatillos,26);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 10:
                                tot = CalculoPagoCliente(nPlatillos,35);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
							}
							printf("\nDeseas comprar otro platillo? (s o n): ");
							scanf("%s",&DesicionCase);
						}
						break;
                    case 2: // Case de las comidas
						 while(strcmp(DesicionCase,"s") == 0) {
						 
						system("cls");
                        MostrarComidas(); //Muestra el menu de comidas
                        printf("\nSelecciona una opcion: ");
                        scanf("%i",&elec);
                        printf("cuantos platos deseas comprar?\n");
                        scanf("%i",&nComidas);

                        switch(elec) { //switch de las comidas decisiones
                            case 1:
                                tot=CalculoPagoCliente(nComidas,35);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 2:
                                tot=CalculoPagoCliente(nComidas,40);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 3:
                                tot= CalculoPagoCliente(nComidas,35);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 4:
                                tot= CalculoPagoCliente(nComidas,40);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 5:
                                tot=CalculoPagoCliente(nComidas,37);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 6:
                                tot= CalculoPagoCliente(nComidas,48);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 7:
                                tot= CalculoPagoCliente(nComidas,50);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 8:
                                tot=CalculoPagoCliente(nComidas,46);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 9:
                                tot= CalculoPagoCliente(nComidas,38);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 10:
                                tot= CalculoPagoCliente(nComidas,55);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                        		}
                        		printf("\nDeseas comprar otro platillo? (s o n): ");
							scanf("%s",&DesicionCase);
                        }
                        break;
                    case 3: //case de los postres
						 while(strcmp(DesicionCase,"s") == 0) {
                        system("cls");
                        MostrarPostres(); //Muestra el menu de postres
                        printf("\nSelecciona una opcion por favor: ");
                        scanf("%i",&elec);
                        printf("Cuantos platillos deseas comprar?\n");
                        scanf("%i",&nPostres);

                        switch(elec) { //Switch de postres decisiones
                            case 1:
                                tot = CalculoPagoCliente(nPostres,20);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 2:
                                tot = CalculoPagoCliente(nPostres,30);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 3:
                                tot = CalculoPagoCliente(nPostres,30);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 4:
                                tot = CalculoPagoCliente(nPostres,30);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 5:
                                tot = CalculoPagoCliente(nPostres,45);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 6:
                                tot = CalculoPagoCliente(nPostres,15);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 7:
                                tot = CalculoPagoCliente(nPostres,45);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 8:
                                tot = CalculoPagoCliente(nPostres,28);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 9:
                                tot = CalculoPagoCliente(nPostres,37);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 10:
                                tot = CalculoPagoCliente(nPostres,10);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                       	 		}
                       	 		printf("\nDeseas comprar otro platillo? (s o n): ");
							scanf("%s",&DesicionCase);
                        }
                        break;
                    case 4: // case de las bebidas
						 while(strcmp(DesicionCase,"s") == 0) {
                        system("cls");
                        MostrarBebidas(); //Muestra el menu de bebidas
                        printf("\nSelecciona una opcion por favor: ");
                        scanf("%i",&elec);
                        printf("Cuantos vasos deseas comprar?\n");
                        scanf("%i",&nVasos);

                        switch(elec) { //Switch con las desiciones de las bebidas
                            case 1:
                                tot= CalculoPagoCliente(nVasos,15);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 2:
                                tot = CalculoPagoCliente(nVasos,15);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 3:
                                tot = CalculoPagoCliente(nVasos,15);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 4:
                                tot = CalculoPagoCliente(nVasos,15);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 5:
                                tot = CalculoPagoCliente(nVasos,15);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 6:
                                tot = CalculoPagoCliente(nVasos,25);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 7:
                                tot = CalculoPagoCliente(nVasos,15);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 8:
                                tot = CalculoPagoCliente(nVasos,15);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 9:
                                tot = CalculoPagoCliente(nVasos,15);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                            case 10:
                                tot = CalculoPagoCliente(nVasos,20);
                                ganan += tot;
                                printf("\nEl total a pagar es: %i",tot);
                                break;
                        		}
                        		printf("\nDeseas comprar otro platillo? (s o n): ");
								scanf("%s",&DesicionCase);
                        }
                        break;
                    case 5: //Ingresos del dia
                        printf("--------INGRESOS DEL DIA-----------\n\n");
                        printf("Ingresos: %i pesos\n",ganan);
                        printf("\n---------------------------------------");
                        printf("\nPara salir presiona enter..");
                        getch(); //espera el enter para salir
                        break;
                } //Fin del switch
                strcpy(DesicionCase,"s"); // Lo que hace es que resetea la variable para volver a ejecutar los whiles de los casos
                system("cls");
            } //Fin del while
            SelecPrincipalRestaurant = 0; //vuelve a 0 la seleccion para que no genere problemas al repetir el bucle
        } //fin del if

    } while(SeleccionPrincipal != 3); //fin del bucle de todo el sistema

    return 0;
}

// --- funciones y metodos de el hotal----

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
        if (Habitaciones[Fila][Columna] ==
                Ocupado) { //Este if hace que las habitaciones no se repitan
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

    while(strcmp(SalidaCheckout,"si") == 0 || strcmp(SalidaCheckout,"Si") == 0
            || strcmp(SalidaCheckout,"SI") == 0) {
        printf("\n Lista de habitaciones \n");
        MostrarHabitaciones();
        printf("\n");
        fflush(stdin);
        printf("¿Que habitacion deseas vaciar?(Ejem. 0 0 ): \n");
        scanf("%i %i",&Fila,&Columna); // Guardamos la habitacion con fila y columna
        Habitaciones[Fila][Columna] = Vacio; // Le colocamos el valor de vacio
        system("cls");
        printf("\n Se ha desocupado la habitacion [%i][%i] exitosamente\n",Fila,
               Columna);
        printf("¿Deseas desocupar otra habitacion?: ");
        scanf("%s",&SalidaCheckout);
        system("cls");
    }
    system("cls");

}
// ---Fin metodos del hotel ---

//Metodos del restaurant --
void MenuRestaurantPrincipal() { //Menu principal del restaurant
    printf("\nBienvenido al restaurante del hotel\n");
    printf("En nuestro menu tenemos lo siguiente: \n");
    printf("1. Desayunos\n");
    printf("2. Comidas\n");
    printf("3. Postres\n");
    printf("4. Aguas\n");
    printf("5. Mostrar ganancias del dia\n");
    printf("6. Regresar al menu principal.\n");
    printf("\nSelecciona una opcion por favor: ");
}

void MostrarDesayunos() { //Muestra los desayunos
    printf("Menu de desayunos\n");
    for(i=0; i<10; i++) {
        printf("%s\n",restaurante[i].desayunos.nombre);
    }
}

void MostrarBebidas() { //Muestra todas las bebidas
    printf("Menu de bebidas\n");
    for(i=0; i<10; i++) {
        printf("%s\n",restaurante[i].aguas.nombre);
    }

}

void MostrarPostres() { //muestra el menu de postres
    printf("Menu de postres\n");
    for(i=0; i<10; i++) {
        printf("%s\n",restaurante[i].postres.nombre);
    }
}

void MostrarComidas() { //Muestra el menu de comidas
    printf("Menu de Comidas\n");
    for(i=0; i<10; i++) {
        printf("%s\n",restaurante[i].comidas.nombre);
    }
}
void LlenarArregloInformaacion() { //Este metodo llena el arreglo restaurant con los datos de cada struct usando el comando strcpy
    strcpy(restaurante[0].desayunos.nombre,"1. Huevos con tocino $25");
    strcpy(restaurante[1].desayunos.nombre,"2. Hot cakes $30");
    strcpy(restaurante[2].desayunos.nombre,"3. Pan frances $25");
    strcpy(restaurante[3].desayunos.nombre,"4. Ensalada de frutas con yogur $28");
    strcpy(restaurante[4].desayunos.nombre,"5. Quesadillas $15");
    strcpy(restaurante[5].desayunos.nombre,"6. Sandwich de jamon con queso $27");
    strcpy(restaurante[6].desayunos.nombre,"7. Ensalada de fruta $30");
    strcpy(restaurante[7].desayunos.nombre,"8. Avena con frutas y miel $28");
    strcpy(restaurante[8].desayunos.nombre,"9. Huevo revuelto con champinones $26");
    strcpy(restaurante[9].desayunos.nombre,"10. Platano frito $35");
    strcpy(restaurante[0].comidas.nombre,"1. Hamburguesa $35");
    strcpy(restaurante[1].comidas.nombre,"2. Orden de tacos $40");
    strcpy(restaurante[2].comidas.nombre,"3. Pollo con salsa y tomates secos $35");
    strcpy(restaurante[3].comidas.nombre,"4. Pollo con esparragos $40");
    strcpy(restaurante[4].comidas.nombre,"5. Macarrones con queso descremado $37");
    strcpy(restaurante[5].comidas.nombre,"6. Chile blanco de pollo $48");
    strcpy(restaurante[6].comidas.nombre,
           "7. Pollo a la parrilla con salsa verde $50");
    strcpy(restaurante[7].comidas.nombre,"8. Sopa de noquis $46");
    strcpy(restaurante[8].comidas.nombre,"9. Sandwich de bistec $38");
    strcpy(restaurante[9].comidas.nombre,"10. Burritos $55");
    strcpy(restaurante[0].postres.nombre,"1. Helado de vainilla $20");
    strcpy(restaurante[1].postres.nombre,"2. Pastel de chocolate $30");
    strcpy(restaurante[2].postres.nombre,"3. Pay de limon $30");
    strcpy(restaurante[3].postres.nombre,"4. Pay de queso $30");
    strcpy(restaurante[4].postres.nombre,"5. Banana split $45");
    strcpy(restaurante[5].postres.nombre,"6. Manzana acaramelada $15");
    strcpy(restaurante[6].postres.nombre,"7. Duraznos en almibar $45");
    strcpy(restaurante[7].postres.nombre,"8. Dulce de garbanzo $28");
    strcpy(restaurante[8].postres.nombre,"9. Tarta de manzana $37");
    strcpy(restaurante[9].postres.nombre,"10. Galleta de chocolate $10");
    strcpy(restaurante[0].aguas.nombre,"1. Agua fria $10");
    strcpy(restaurante[1].aguas.nombre,"2. Jugo de naranja $15");
    strcpy(restaurante[2].aguas.nombre,"3. Agua de sandia $15");
    strcpy(restaurante[3].aguas.nombre,"4. Pozol de cacao $15");
    strcpy(restaurante[4].aguas.nombre,"5. Cafe americano $15");
    strcpy(restaurante[5].aguas.nombre,"6. Cafe capuchino $25");
    strcpy(restaurante[6].aguas.nombre,"7. Limonada $15");
    strcpy(restaurante[7].aguas.nombre,"8. Horchata $15");
    strcpy(restaurante[8].aguas.nombre,"9. Jamaica $15");
    strcpy(restaurante[9].aguas.nombre,"10. Pina colada $20");
}

int CalculoPagoCliente(int CantidadPlatillos, int Precio) { //Calcula el pago del cliente
    int resultado;

    resultado = CantidadPlatillos * Precio;

    return resultado;
}
//Fin metodos restaurant
