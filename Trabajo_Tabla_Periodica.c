#include <stdio.h>
#include <string.h>

int main(){
	
	printf("------------------------------------------\n");
	printf("------Programa de la Tabla Periodica------\n");
	printf("------------------------------------------\n\n\n");
	
	printf("Menu de opciones.\n\n");
	
	printf("\t1. Introduce tus credenciales.\n\n");
	
	printf("\t2. Descripcion breve de la tabla periodica.\n\n");
	
	printf("\t3. Introduce el numero del elemento y te decimos grupo y periodo.\n\n");
	
	printf("\t4. Introduce el nombre del elemento y te damos una breve descripcion.\n\n");
	
	printf("\t5. Cerrar el programa.\n\n");
	
	//------------------------------------------------------------------------------------------------------------------
	
	printf("--------------------------------------------------------------------------------\n\n");
	
	int opcion,nelemento;
	
	printf("Introduce una de las opciones del menu\n");
	
	scanf( "%d" , &opcion );
	
	
	do{
		
		system("cls");
		
		switch(opcion){
		
			case 1:printf("Introduce tus credenciales.\n");
			break;
		
			case 2:printf("La tabla periodica fue inventada por Mendeliev en...\n");
			break;
		
			case 3:printf("Indica el numero que quieres.\n");
				   scanf("%d",&nelemento);
			break;
		
			case 4:printf("Introduce el nombre abreviado ( Ejemplo-->Sodio: Na).\n");
			break;
		
			case 5:printf("Gracias por haber usado nuestro programa.\n");
			break;
		
			default: printf("Por favor introduzca un valor entre 1 y 5.\n\n");
			
			scanf( "%d" , &opcion );
			
			//return 0;
			//system("pause");
		}
		
	}while(opcion < 1 && opcion > 5);

	//system("cls");
	
}
