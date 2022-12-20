#include <stdio.h>
#include <stdlib.h>

typedef	struct {
	
	int   numero;
	char  nombre[20]; 
	int   cantidad;
	float precio;
} herramientas;


char opcion;
int cond =0;

void presentacion(void);
void ingresar (void);
void listar (void);
void borrar (void);

FILE *hardPtr;

int main (void){
	
	herramientas inventario = {0,"",0,0.0};
if ((hardPtr = fopen ("hardware.dat", "ab+")) == NULL){
	puts("********************************\n");
	puts("El archivo no puede ser abierto.\n");
	puts("********************************\n");
}
else{
	for(int i=1;i>=100;i++){
		fwrite(&inventario,sizeof(herramientas),1,hardPtr);}
} fclose(hardPtr);
   


    
    puts ("   **********************************\n");
	puts ("   *    Bienvenido al inventario    *\n");
  	puts ("   **********************************\n\n");

	do{
	cond =0;	
	puts("(I)ngresar nueva herramienta o modificar\n");
	puts("(L)listar las herramientas ingresadas\n");
	puts("(B)orrar una herramienta de la listado\n");
	puts("(S)alir del programa...\n\n");
	printf ("Ingrese opcion deseada (En MAY): ");
	opcion = getchar();
	
	
	if (opcion == 'S' || opcion == 's') cond=4;
	
	fflush( stdin );
	system ("cls");
	
	switch (opcion){
	
	case 'I': ingresar();
	break;
	case 'L': listar ();
	
	puts ("\n\n\n\n\n********************************************\n");
	puts ("Vuelva a elegir opcion en el menu principal\n");
	puts ("\n********************************************\n");
	system ("PAUSE");
	system ("cls");
	break;
	case 'B': borrar ();
	break;
}} while (cond !=4);
	
	presentacion ();
		
	return 0;
}
void ingresar (void){
	
	herramientas inventario = {0,"",0,0.0};
		
	if ((hardPtr = fopen ("hardware.dat","rb+")) == NULL){
		puts("********************************\n");
		puts("El archivo no puede ser abierto.\n");
		puts("********************************\n");	
	}
	else{
	
	do{
		
		puts("\nIngrese el numero de la herramienta (0 para finalizar): ");
		scanf("%d", &inventario.numero);
		
		if (inventario.numero !=0){
		puts("\nIngrese el nombre, cantidad y el precio de la herramienta\n");
		
		fscanf (stdin, "%s %d %f", inventario.nombre,&inventario.cantidad, &inventario.precio);
		
		fseek (hardPtr, (inventario.numero - 1) * sizeof(herramientas), SEEK_SET );
		
		fwrite(&inventario, sizeof(herramientas), 1, hardPtr);
		}
		else{ 
			puts ("\n\n********************************************\n");
			puts ("\nSus modificaciones fueron guardadas!!..\n");
			puts ("\nVuelva a elegir opcion en el menu principal\n");
			puts ("\n\n********************************************\n");
			system ("PAUSE");
			system ("cls");
		}
	}while (inventario.numero != 0);
}fclose (hardPtr);
}

void listar (void){
	
	herramientas inventario = {0,"",0,0.0};
	
	if ((hardPtr = fopen ("hardware.dat","rb+")) == NULL)
	{
		puts("********************************\n");
		puts("El archivo no puede ser abierto.\n");
		puts("********************************\n");	
	}
	else {
		
		printf("Numero\tNombre de herramienta\tCantidad\tPrecio\n\n");		
		while (!feof (hardPtr)){
			
			int resultado = fread(&inventario, sizeof(herramientas), 1, hardPtr);
			
			if (resultado != 0 && inventario.numero != 0){
				
				printf("%d\t%20s\t%8d\t%.1f\n",inventario.numero,inventario.nombre,inventario.cantidad,inventario.precio); 
	}}}
fclose (hardPtr);
}


void borrar (){
	
	int salir,N;
	char op,total;
	herramientas inventario = {0,"",0,0.0};
	
	do{
	        salir =0;
			fflush( stdin );
			system ("cls");
		    
			puts ("\n--------------Menu BORRAR--------------\n\n");
			puts ("(L)ista completa\n");
			puts ("(H)erramienta de la lista\n");
			puts ("(S)alir\n");
			puts ("\nElija la opcion deseada para borrar (en MAY):");
			op = getchar();
	
		switch (op){	
	case 'L':
			fflush (stdin);
			puts ("\n");
			listar ();
			puts ("\n\n");
			puts("\n*********************************************\n");
			puts ("¿Desea borrar el registro de herramientas? S/N");
			total= getchar();
			if (total == 'S'){
			 hardPtr = fopen("hardware.dat", "w");
			 puts("\n******************************************\n");
			 puts ("Su registro a sido borrado exitosamente!!\n");
			 puts("******************************************\n");
			}fclose(hardPtr);	
			system ("PAUSE");
			system ("cls");
			fflush (stdin);
		break;
    case 'H':
		 puts ("\n"); 
		 listar ();
		 puts ("\n\n");
	     if ((hardPtr = fopen ("hardware.dat","rb+")) == NULL){
	
	     puts("********************************\n");
	     puts("El archivo no puede ser abierto.\n");
	     puts("********************************\n");}
	     else {
	     do{
	     puts("\nIngrese el numero de la herramienta (0 para finalizar): ");
	     scanf("%d", &inventario.numero);
		 N=0;
      	if (inventario.numero !=0){
	    
	    fseek (hardPtr, (inventario.numero - 1) * sizeof(herramientas), SEEK_SET );
	    if (inventario.numero != N) N=1;
		inventario.numero = 0;
	    fwrite(&inventario, sizeof(herramientas), 1, hardPtr);
		if (N==1){
		puts("\n\n**************************************\n");
		puts("Su herramienta fue borrada con exito!!\n");
		puts("**************************************\n");}
		}}while (inventario.numero != 0);
	}fclose(hardPtr);
	
		 fflush (stdin);
		 system ("PAUSE");
		 system ("cls");
		 
	break;
	case 'S':
	    puts ("\n\n********************************************\n");
	    puts ("\nSus modificaciones fueron guardadas!!..\n");
	    puts ("\nVuelva a elegir opcion en el menu principal\n");
		puts ("\n\n********************************************\n");
		system ("PAUSE");
	    system ("cls");
		fflush (stdin);	
		salir = 4;
	break;}
	fflush (stdin);	
	}while (salir != 4);
}
void presentacion(void){
		
		
		puts("\n\n");
		puts("                   ---------------------------- \n");
		puts("                  |                            |\n");
		puts("                  | Inventario de Herramientas |\n");
		puts("                  |      permite cargar y      |\n");
		puts("                  |    y modificar elementos   |\n");
		puts("                  |       en un registro       |\n");
		puts("                  |                            |\n");
		puts("                   ---------------------------- \n");
		
		puts("\n\n");	
		puts ("        ----------------------------------------");
		puts ("        |  Matias Cabrera - Ouer3D - 05/11/2019 |");
		puts ("        ----------------------------------------\n\n");
		
		system("pause");
		//Todos los derechos reservados para Matias Cabrera 
		system("cls"); //me limpia la pantalla para dar lugar al opcionario.-	
	
	
}
	
