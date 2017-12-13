#include <stdio.h>
#include <string.h>


typedef struct sempleado {
	int legajo;
	char nombre_completo[40];
	int sector;
	float salario;
} Templeado;

// Guarda el empleado en el archivo
void guardar_empleado(Templeado* empleado, FILE* archivo) {
	fwrite(empleado, sizeof(Templeado), 1, archivo); 
	printf("Guardado %s\n", empleado -> nombre_completo);
}

// Genera 99 empleados para ya tenerlos cargados en el archivo
void guardar_empleados_autogenerados(FILE* archivo) {
	Templeado empleado;
	char nombre[40];
	
	for(int n = 1; n < 100; n++) {
		empleado.legajo = n;
		empleado.sector = 10 * n;
		empleado.salario = 1000 * n;
		
		sprintf(nombre, "Empleado %d", n);
		strcpy(empleado.nombre_completo, nombre);
		
		guardar_empleado(&empleado, archivo); 
	}	
}

void ingresar_empleados_por_teclado(FILE* archivo) {
	int respuesta;
	int legajo;
	int sector;
	char nombre[40];
	float salario;
	Templeado empleado;
	
	while(respuesta != -1) {
		puts("Ingrese el legajo del nuevo empleado:");
		scanf("%d", &legajo);
		empleado.legajo = legajo;
		sprintf(nombre, "Empleado %d", legajo);
		strcpy(empleado.nombre_completo, nombre);
		
		puts("Ingrese el sector del nuevo empleado:");
		
		
		guardar_empleado(&empleado, archivo); 
		
		puts("Inserte -1 si no quiere agregar más empleados");
		scanf("%d", &respuesta);
	}
}

int main() {
	FILE* archivo;

	archivo = fopen("Empleados.dat", "rb+"); //Abrimos el archivo para leer y escribir
	
	if (archivo == NULL) { //Si no hay archivo termina con error
		printf("No se pudo abrir el archivo");
		return 1;
	}
	
	guardar_empleados_autogenerados(archivo);
	
	ingresar_empleados_por_teclado(archivo);
	
	fclose(archivo);
}
