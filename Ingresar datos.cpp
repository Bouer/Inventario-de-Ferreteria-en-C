#include <stdio.h>
#include <stdlib.h>

typedef	struct {
	
	int   numero;
	char  nombre[20]; 
	int   cantidad;
	float precio;
} herramientas;


char opcion;

void ingresar ();
void listar (void);
void borrar ();

FILE *hardPtr;
herramientas inventario;

int main (void){
	

if ((hardPtr = fopen ("hardware.dat", "ab+")) == NULL){
	puts("********************************\n");
	puts("El archivo no puede ser abierto.\n");
	puts("********************************\n");
}
else{
	for(int i=1;i>=100;i++){
		fwrite(&inventario,sizeof(herramientas),1,hardPtr);}
} fclose(hardPtr);


	puts ("Bienvenido al inventario\n\n");
	puts("(I)ngresar nueva herramienta o modificar");
	puts ("\n(L)listar las herramientas ingresadas");
	puts ("\n(B)orrar una herramienta de la listado");
	printf ("\n\nIngrese opcion: ");
	opcion = getchar();
	
	switch (opcion){
	
	case 'I': ingresar();
	break;
	case 'L': listar ();
	break;
	case 'B': borrar ();
	break;
	}
	
	
		
	system ("PAUSE");
	return 0;
}
void ingresar (void){
	
	herramientas inventario = {0,"",0,0.0};
	printf ("HOLA");
	
	if ((hardPtr = fopen ("hardware.dat","rb+")) == NULL){
		puts("********************************\n");
		puts("El archivo no puede ser abierto.\n");
		puts("********************************\n");	
	}
	else {
	
	
	while (inventario.numero != 0){
		
		printf("%s", "\nIngrese el numero de herramientas: ");
		scanf("%d", &inventario.numero);
		
		puts("\nIngrese el nombre, cantidad y el precio de la herramienta\n");
		
		fscanf (stdin, "%s %d %f", inventario.nombre,&inventario.cantidad, &inventario.precio);
		
		fseek (hardPtr, (inventario.numero - 1) * sizeof(herramientas), SEEK_SET );
		
		fwrite(&inventario, sizeof(herramientas), 1, hardPtr);
		
	}}}

void listar (void){
	
	herramientas inventario = {0,"",0,0.0};
	
	if ((hardPtr = fopen ("hardware.dat","rb+")) == NULL)
	{
		puts("********************************\n");
		puts("El archivo no puede ser abierto.\n");
		puts("********************************\n");	
	}
	else {
		
				
		while (!feof (hardPtr)){
			
			int resultado = fread(&inventario, sizeof(herramientas), 1, hardPtr);
			
			if (resultado != 0 && inventario.numero != 0){
				
				printf("%d\t%20s\t%8d\t%.2f\n",inventario.numero,inventario.nombre,inventario.cantidad,inventario.precio); 
			}
}}}


void borrar (){}
	
