#include <iostream>
#include <stdio.h>

typedef struct salumno {
	int lu;
	char nombre[5];
	int materias;
} Talumno;


int main() 
{
	FILE *arch;
	Talumno alum;
	
	

	arch = fopen("Alumno.dat", "rb+"); //Abrimos el archivo
	
	if (arch == NULL) { //Si no hay archivo
		printf("No se pudo abrir el archivo");
		return 1;
	}
	
	fread(&alum, sizeof(Talumno), 1, arch);
	while(!feof(arch)) {
		printf("Leyendo alumno: %d\n", alum.lu);
		
		if (alum.lu > 0 && alum.lu < 1000) { // Si el legajo es válido
			printf("Baja logica de %d\n", alum.lu);
			alum.lu = (-1) * alum.lu; // Baja lógica (poniendo el legajo en negativo)
			fseek(arch, (-1) * (int) sizeof(Talumno), SEEK_CUR); // Regresa con el puntero al princpio del registro de alumno (para sobreescribir)
			fwrite(&alum, sizeof(Talumno), 1, arch); // Sobreescribe el alumno con el legajo negativo
			fseek(arch, 0, SEEK_CUR); // ?? 
		}
		
		fread(&alum, sizeof(Talumno), 1, arch);
	}
	fclose(arch);
	printf("Todo piola!");
}
