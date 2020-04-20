#include <stdio.h>
#include <string.h>

//Trabajo que busca informar sobre datos de la tabla periódica con introdución de elemento
//mostrando la tabla y datos.



struct TElemento {
	
	char elemento[3];
};

int main(){
	
	int k,nelemento = 0;
	
	struct TElemento clase[500];
	
	FILE*pfichero;
	//------------------------------------------------------------------------------	
	pfichero = fopen("Tabla.txt","r");
	
	if(pfichero == NULL){
		
		printf("No se ha podido crear el fichero.\n");
		return 0;
	}
	
	while(fscanf(pfichero, "%s" , clase[nelemento].elemento) != EOF){
		
		nelemento++;
		
	}
	
	// Utilizamos un solo iterador puesto que hacemos un solo vector de estructuras con una sola clase
	
	fclose(pfichero);
	
	printf("%s",clase[0].elemento);// Los dos primeros elementos los escribimos fuera del 
	printf("                                                ");// bucle para poder introducir los espacios entre los grupos
	printf("%s",clase[1].elemento);
	printf("\n");
		
	for(k=2 ; k<=3; k++){
			
		printf("%s ", clase[k].elemento);
	}
		
	printf("                            ");
		
	for(k=4 ; k<=9 ;k++){
			
		printf("%s  ", clase[k].elemento);
	}
		
	printf("\n");
		
	for(k=10 ; k<=11; k++){
			
		printf("%s ", clase[k].elemento);
	}
		
	printf("                            ");
		
	for(k=12 ; k<=17 ;k++){
			
		printf("%s ", clase[k].elemento);
	}
		
	printf("\n");
		
	for(k=18 ; k<=35 ;k++){
			
		printf("%s ", clase[k].elemento);
	}
	printf("\n");
		
	for(k=36 ; k<=53 ;k++){
			
		printf("%s ", clase[k].elemento);
	}

	printf("\n");
	
	for(k=54 ; k<=71 ;k++){
			
		printf("%s ", clase[k].elemento);
	}
	
	printf("\n");
	
		
	for(k=72 ; k<=89 ;k++){
			
		printf("%s ", clase[k].elemento);
	}

	printf("\n");
	printf("      ");
	
	for(k=90 ; k<=103 ;k++){
			
		printf("%s ", clase[k].elemento);
	}
	
	printf("\n");
	printf("      ");
	
	for(k=104 ; k<=nelemento-1 ;k++){
			
		printf("%s ", clase[k].elemento);
	}
	
	printf("\n");	
	
//	printf("%s",clase[0].elemento);
	
	//-------------------------------------------------------------------------------
	
	
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
