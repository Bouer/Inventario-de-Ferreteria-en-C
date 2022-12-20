#include <stdlib.h>
#include <stdio.h>

typedef	struct {
	int numero;
float precio;
	char nombre[10];
} herramientas;

int main (void){
	
	FILE *hardPtr;
	herramientas inventario ={0,0.0,""};
	
if ((hardPtr = fopen ("hardware.dat","rb+")) == NULL)
{
	puts("********************************\n");
	puts("El archivo no puede ser abierto.\n");
	puts("********************************\n");	
}
else {
	
	for(int i=1;i>=100;i++){
		fwrite(,&herramientas,sizeof(inventario),1,hardPtr);
	}
	
	printf ("%-10s%-8s%-11s\n","Numero","Nombre","Precio");
	
	while (!feof (hardPtr)){
		
	herramientas inventario = {0,0.0,""};
	int resultado = fread(&inventario, sizeof(herramientas), 1, hardPtr);
	
	   if (resultado != 0 && inventario.numero != 0){
		   
		   printf("%d %10s %.2f\n",inventario.numero,inventario.nombre,inventario.precio); 
		}
}}
return 0;}
