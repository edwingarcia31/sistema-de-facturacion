#include <stdio.h>
#include <stdlib.h>

//Estructura Cliente
struct Cliente{
	int id;
	char cedula[20];
	char nombre[30];
	char direccion[30];
	char telefono[20];
}clientes[100], *pClientes = clientes;

//Estructura Producto
struct Producto{
	int id;
	char nombre[30];
	float valor;
}productos[100], *pProductos = productos;

//Estructura Factura
struct Factura{
	int id;
	int id_cliente;
	int id_producto[100];
	int cantidad[100];
	float valor[100];
	bool estado;
}facturas[100], *pFacturas = facturas;

//Variables globales
int cantClientes = 0;
int cantProductos = 0;
int cantFacturas = 0;

//Prototipo de funciones
void menu();

//Clientes
void menuClientes();
void crearClientes();
void listarClientes();
void modificarClientes();
bool buscarCliente(int);
void mostrarCliente(int id_cliente);

//Productos
void menuProductos();
void crearProductos();
void listarProductos();
void modificarProductos();

//Facturacion
void menuFacturacion();
void mostrarFacturasPagadas();
void mostrarFacturasSinPagar();
void mostrarFacturasCliente();
void hacerCompra();

//Funcion Principal
int main(){
	menu();
	return 0;
}

//Menu principal
void menu(){
	int opcion;
	do{
		printf("\nSistema de Facturacion\n");
		printf("\n*****MENU*****\n");
		printf("1. Clientes\n");
		printf("2. Productos\n");
		printf("3. Facturacion\n");
		printf("0. Salir\n");
		printf("Ingrese su opcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1: menuClientes();
			break;
			case 2: menuProductos();
			break;
			case 3: menuFacturacion();
			break;
			case 0: exit(0);
			break;
			default: printf("\nNo es una opcion valida\n");
		}
	}while(opcion != 0);
	
}

//Clientes
void menuClientes(){
	int opcion;
	do{
		printf("\nSistema de Facturacion\n");
		printf("\n*****MENU CLIENTES*****\n");
		printf("1. Crear Clientes\n");
		printf("2. Listar Clientes\n");
		printf("3. Modificar Clientes\n");
		printf("0. Salir al menu principal\n");
		printf("Ingrese su opcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1: crearClientes();
			break;
			case 2: listarClientes();
			break;
			case 3: modificarClientes();
			break;
			case 0: menu();
			break;
			default: printf("\nNo es una opcion valida\n");
		}
	}while(opcion != 0);
}

void crearClientes(){
	fflush(stdin);
	((pClientes + cantClientes) -> id) = cantClientes + 1;
	printf("Ingrese cedula: ");
	fgets((pClientes + cantClientes) -> cedula, 20, stdin);
	printf("Ingrese Nombre: ");
	fgets((pClientes + cantClientes) -> nombre, 30, stdin);
	printf("Ingrese Direccion: ");
	fgets((pClientes + cantClientes) -> direccion, 30, stdin);
	printf("Ingrese Telefono: ");
	fgets((pClientes + cantClientes) -> telefono, 20, stdin);
	cantClientes += 1;
	printf("\nCliente creado con exito\n");
}

void listarClientes(){
	int i;
	for(i = 0; i < cantClientes; i++){
		printf("CLIENTE No. %d\n", i + 1);
		printf("Id: %d\t", (pClientes + i) -> id);
		printf("Cedula: %s\t", (pClientes + i) -> cedula);
		printf("Nombre: %s\t", (pClientes + i) -> nombre);
		printf("Direccion: %s\t", (pClientes + i) -> direccion);
		printf("Telefono: %s\t", (pClientes + i) -> telefono);
		printf("\n");
	}
}

void modificarClientes(){
	int idClienteModificar, i, opcion;
	listarClientes();
	printf("Ingrese id cliente modificar: ");
	scanf("%d", &idClienteModificar);
	if(buscarCliente(idClienteModificar)){
		do{
			printf("\n*****MENU EDITAR CLIENTES*****\n");
			printf("1. Editar Cedula\n");
			printf("2. Editar Nombre\n");
			printf("3. Editar Direccion\n");
			printf("4. Editar Telefono\n");
			printf("5. Editar Todos los Campos\n");
			printf("0. Regresar\n");
			printf("Ingrese su opcion: ");
			scanf("%d", &opcion);
			fflush(stdin);
			switch(opcion){
				case 1: 
					printf("Ingrese nueva cedula: ");
					fgets((pClientes + (idClienteModificar - 1)) -> cedula, 20, stdin);
					printf("Cliente actualizado con exito\n");
				break;
				case 2:
					printf("Ingrese nuevo nombre: ");
					fgets((pClientes + (idClienteModificar - 1)) -> nombre, 30, stdin);
					printf("Cliente actualizado con exito\n");
				break;
				case 3:
					printf("Ingrese nueva direccion: ");
					fgets((pClientes + (idClienteModificar - 1)) -> direccion, 30, stdin);
					printf("Cliente actualizado con exito\n");
				break;
				case 4:
					printf("Ingrese nuevo telefono: ");
					fgets((pClientes + (idClienteModificar - 1)) -> telefono, 30, stdin);
					printf("Cliente actualizado con exito\n");
				break;
				case 5:
					printf("Ingrese nueva cedula: ");
					fgets((pClientes + (idClienteModificar - 1)) -> cedula, 20, stdin);
					printf("Ingrese nuevo nombre: ");
					fgets((pClientes + (idClienteModificar - 1)) -> nombre, 30, stdin);
					printf("Ingrese nueva direccion: ");
					fgets((pClientes + (idClienteModificar - 1)) -> direccion, 30, stdin);
					printf("Ingrese nuevo telefono: ");
					fgets((pClientes + (idClienteModificar - 1)) -> telefono, 30, stdin);
					printf("Cliente actualizado con exito\n");
				break;
				case 0: menuClientes();
				default: printf("\nNo es una opcion valida\n");
			}
		}while(opcion != 0);
	}else{
		printf("El cliente ingresado no existe\n");
	}
}

bool buscarCliente(int idClienteModificar){
	int i;
	for(i = 0; i < cantClientes; i++){
		if(idClienteModificar == pClientes[i].id){
			return true;
		}
	}
	return false;
}

void mostrarCliente(int id_cliente){
	printf("CLIENTE No. %d\n", id_cliente);
	printf("Id: %d\t", ((pClientes + (id_cliente - 1)) -> id));
	printf("Cedula: %s\t", ((pClientes + (id_cliente - 1)) -> cedula));
	printf("Nombre: %s\t", ((pClientes + (id_cliente - 1)) -> nombre));
	printf("Direccion: %s\t", ((pClientes + (id_cliente - 1)) -> direccion));
	printf("Telefono: %s\t", ((pClientes + (id_cliente - 1)) -> telefono));
	printf("\n");
}

//Productos
void menuProductos(){
	int opcion;
	do{
		printf("\nSistema de Facturacion\n");
		printf("\n*****MENU PRODUCTOS*****\n");
		printf("1. Crear Productos\n");
		printf("2. Listar Productos\n");
		printf("3. Modificar Productos\n");
		printf("0. Salir al menu principal\n");
		printf("Ingrese su opcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1: crearProductos();
			break;
			case 2: listarProductos();
			break;
			case 3: modificarProductos();
			break;
			case 0: menu();
			break;
			default: printf("\nNo es una opcion valida\n");
		}
	}while(opcion != 0);
}

void crearProductos(){
	fflush(stdin);
	pProductos[cantProductos].id = cantProductos + 1;
	printf("Ingrese nombre del producto: ");
	fgets(pProductos[cantProductos].nombre, 30, stdin);
	printf("Ingrese valor del producto: ");
	scanf("%f", &pProductos[cantProductos].valor);
	cantProductos += 1;
	printf("\nProducto creado con exito\n");
}

void listarProductos(){
	int i;
	for(i = 0; i < cantProductos; i++){
		printf("Producto No. %d\n", i + 1);
		printf("Id: %d\t", pProductos[i].id);
		printf("Nombre del producto: %s\t", pProductos[i].nombre);
		printf("Valor del producto $ %.2f\t", pProductos[i].valor);
		printf("\n");
	}
}

void modificarProductos(){

}

//Facturacion
void menuFacturacion(){
	int opcion;
	do{
		printf("\nSistema de Facturacion\n");
		printf("\n*****MENU FACTURAS*****\n");
		printf("1. Mostrar Facturas Pagadas\n");
		printf("2. Mostrar Facturas sin Pagar\n");
		printf("3. Mostrar Facturas por Cliente\n");
		printf("4. Hacer Compra\n");
		printf("0. Salir al menu principal\n");
		printf("Ingrese su opcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1: mostrarFacturasPagadas();
			break;
			case 2: mostrarFacturasSinPagar();
			break;
			case 3: mostrarFacturasCliente();
			break;
			case 4: hacerCompra();
			break;
			case 0: menu();
			break;
			default: printf("\nNo es una opcion valida\n");
		}
	}while(opcion != 0);
}

void mostrarFacturasPagadas(){
	int i, j;
	float total = 0;
	for(i = 0; i < cantFacturas; i++){
		printf("FACTURA No. %d\n", i + 1);
		printf("DATOS DEL CLIENTE \n");
		printf("Cedula: %s\t", (pClientes + (((pFacturas + i) -> id_cliente)) - 1) -> cedula);
		printf("Nombre: %s\t", (pClientes + (((pFacturas + i) -> id_cliente)) - 1) -> nombre);
		printf("Direccion: %s\t", (pClientes + (((pFacturas + i) -> id_cliente)) - 1) -> direccion);
		printf("Telefono: %s\t", (pClientes + (((pFacturas + i) -> id_cliente)) - 1) -> telefono);
		printf("\nDETALLES DE LA COMPRA \n");
		printf("Nombre \t");
		printf("Cantidad \t");
		printf("Valor \t");
		for(j = 0; j < 2; j++){
			printf("%s\t", (pProductos + ((pFacturas + i) -> id_producto[j])) -> nombre);
			printf("%d\t", (pFacturas + i) -> cantidad[j]);
			printf("$ %.2f\t", (pFacturas + i) -> valor[j]);
			total += (pFacturas + i) -> valor[j];
			printf("\n");
		}
		printf("Total Pagado %.2f\n", total);
	}
}

void mostrarFacturasSinPagar(){

}

void mostrarFacturasCliente(){

}

void hacerCompra(){
	int id_cliente, id_producto, iterador_vector = 0, cantidad, valor;
	int opcion;
	printf("\nSistema de Facturacion\n");
	printf("\n*****MENU COMPRAS*****\n");
	listarClientes();
	printf("Ingrese el id del cliente: ");
	scanf("%d", &id_cliente);
	if(buscarCliente(id_cliente)){
		mostrarCliente(id_cliente);
		((pFacturas + cantFacturas) -> id) = cantFacturas + 1;
		((pFacturas + cantFacturas) -> id_cliente) =id_cliente;
		//Comprar productos
		do{
			listarProductos();
			printf("Ingrese el id del producto: ");
			scanf("%d", &id_producto);
			((pFacturas + cantFacturas) -> id_producto[iterador_vector]) = id_producto;
			printf("Ingrese cantidad producto: ");
			scanf("%d", &cantidad);
			((pFacturas + cantFacturas) -> cantidad[iterador_vector]) = cantidad;
			((pFacturas + cantFacturas) -> valor[iterador_vector]) = cantidad * (pProductos + (id_producto - 1)) -> valor;
			((pFacturas + cantFacturas) -> estado) = true;
			iterador_vector += 1;
			printf("Presione 0(salir) o cualquier cualquier numero para agregar mas productos: ");
			scanf("%d", &opcion);
		}while(opcion != 0);
		cantFacturas += 1;
	}else{
		printf("El cliente no existe\n");
		menuFacturacion();
	}
}