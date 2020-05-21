#include <stdio.h>
#include <string.h>

//Tabla

struct TTabla {
	char elemento[3];
};

struct TCredenciales{
	char nombre[50];
	char apellidos[100];
};

struct TElementos{
	char elemento[50];
	char simbolo[2];
	int nAtomico;
	float masaAtomica;
	int periodo;
	int grupo;
};


//declaración de funciones
void dibujamenu();
char tablaperiodica(struct TTabla clase[]);
char Credenciales(struct TCredenciales vector[]);
char elementos(struct TElementos elemento[]);
char verCredenciales(struct TCredenciales vector[]);
void Cuestionario1();
void Cuestionario2();


int main(){
	
	int opcion,numero;
	
	struct TTabla clase[500];
	
	struct TCredenciales vector[1000];
	
	struct TElementos elemento[1000];
	
	int i,nelemento = 0;
	
	int tabla, credenciales, vercredenciales;
	
	FILE*pfichero1;
	
	FILE*pfichero2;
	
	FILE*pfichero3;
	
	//------------------------------------------------------------------------------	
	pfichero1 = fopen("Tabla.txt","r");
	
	if(pfichero1 == NULL){
		
		printf("No se ha podido crear el fichero.\n");
		return 0;
	}
	
	pfichero2 = fopen("Elementos.txt","r");
	
	if(pfichero2 == NULL){
		
		printf("No se ha podido crear el fichero.\n");
		return 0;
	}
	
	pfichero3 = fopen("Credenciales.txt","a+");
	
	if(pfichero3 == NULL){
		
		printf("No se ha podido crear el fichero.\n");
		return 0;
	}
	
	while(fscanf(pfichero1, "%s" , clase[nelemento].elemento) != EOF){
		
		nelemento++;	
	}
	
	/*i=0;
	
	while(fscanf(pfichero2, "%s" , elemento[i].elemento)!= EOF){
			i++;
	}
	
	printf("%d\n",i);*/


	
	fclose(pfichero1);
	
	fclose(pfichero2);
	
	
	dibujamenu();
	
	tabla = tablaperiodica(clase);	
		
	
	do{
		printf("\nIntroduce una de las opciones del menu\n");
		scanf( "%d" , &opcion );
		switch(opcion){
		
			case 1:printf("Introduce tus credenciales.\n");
				   credenciales = Credenciales(vector);
			break;
		
			case 2:printf("Mirar credenciales previamente introducidas.\n");
					vercredenciales = verCredenciales(vector);
			break;
		
			case 3:printf("Indica el numero de un elemento y te decimos informacion de el.\n");
				   scanf("%d",&numero);
			break;
		
			case 4:printf("Ha entrado al Cuestionario 1.\n");
				   Cuestionario1();
			break;
		
			case 5:printf("Ha entrado al Cuestionario 2.\n");
				   Cuestionario2();
			break;	
		
			case 6:printf("Gracias por haber usado nuestro programa.\n");
			break;
		
			default: printf("Por favor introduzca un valor entre 1 y 5.\n");
			
			//
		
		}
		
	}while(opcion!=6);
	
	
	
	//system("cls");
	
}



void dibujamenu(){
	
	
	printf("------------------------------------------\n");
	printf("------Programa de la Tabla Periodica------\n");
	printf("------------------------------------------\n\n\n");
	
	printf("Menu de opciones.\n\n");
	
	printf("\t1. Introduce tus credenciales.\n\n");
	
	printf("\t2. Mirar credenciales previamente introducidas.\n\n");
	
	printf("\t3. Introduce el numero del elemento y te decimos grupo y periodo.\n\n");
	
	printf("\t4. Realizar Cuestionario 1.\n\n");
	
	printf("\t5. Realizar Cuestionario 2.\n\n");
	
	printf("\t6. Cerrar el programa.\n\n");
	
	printf("--------------------------------------------------------------------------------\n\n");
}

char tablaperiodica(struct TTabla clase[]){
	
	int k,nelemento=118,longitud;
	
	printf("%s",clase[0].elemento);
	printf("                                                  ");
	printf("%s",clase[1].elemento);
	printf("\n");
		
	for(k=2; k<=3; k++){
		printf("%s ", clase[k].elemento);
		longitud=strlen(clase[k].elemento);
		if (longitud==1){
			printf(" ");
		}
	}
		
	printf("                              ");
		
	for(k=4; k<=9; k++){
		printf("%s ", clase[k].elemento);
		longitud=strlen(clase[k].elemento);
		if (longitud==1){
			printf(" ");
		}
	}
		
	printf("\n");
		
	for(k=10; k<=11; k++){
		printf("%s ", clase[k].elemento);
		longitud=strlen(clase[k].elemento);
		if (longitud==1){
			printf(" ");
		}
	}
		
	printf("                              ");
		
	for(k=12; k<=17; k++){
		printf("%s ", clase[k].elemento);
		longitud=strlen(clase[k].elemento);
		if (longitud==1){
			printf(" ");
		}
	}
		
	printf("\n");
		
	for(k=18; k<=35; k++){
		printf("%s ", clase[k].elemento);
		longitud=strlen(clase[k].elemento);
		if (longitud==1){
			printf(" ");
		}
	}
	
	printf("\n");
		
	for(k=36; k<=53; k++){
		printf("%s ", clase[k].elemento);
		longitud=strlen(clase[k].elemento);
		if (longitud==1){
			printf(" ");
		}
	}

	printf("\n");
	
	for(k=54; k<=71; k++){
		printf("%s ", clase[k].elemento);
		longitud=strlen(clase[k].elemento);
		if (longitud==1){
			printf(" ");
		}
	}
	
	printf("\n");
		
	for(k=72; k<=89; k++){
		printf("%s ", clase[k].elemento);
		longitud=strlen(clase[k].elemento);
		if (longitud==1){
			printf(" ");
		}
	}

	printf("\n\n      ");
	
	for(k=90; k<=103; k++){
		printf("%s ", clase[k].elemento);
		longitud=strlen(clase[k].elemento);
		if (longitud==1){
			printf(" ");
		}
	}
	
	printf("\n      ");
	
	for(k=104; k<=nelemento-1 ;k++){
		printf("%s ", clase[k].elemento);
		longitud=strlen(clase[k].elemento);
		if (longitud==1){
			printf(" ");
		}
	}
	printf("\n");	
}

char Credenciales(struct TCredenciales vector[]){
	
	system("cls");
	
	int personas,i;
	
	FILE*pfichero3;
	
	pfichero3 = fopen("Credenciales.txt","a+");
	
	printf("Cuantas credenciales (personas) quieres meter:\n");
	scanf("%d",&personas);
	
	for(i=0 ; i<personas ; i++){
		
		fflush(stdin);
		scanf("%s %s",vector[i].nombre, vector[i].apellidos);
		fprintf( pfichero3, "%s	%s\n", vector[i].nombre, vector[i].apellidos );
		
	}
	
	fclose(pfichero3);
	//return 0;
}

char elementos(struct TElementos elemento[]){
	
}


char verCredenciales(struct TCredenciales vector[]){
	
	int i, j=0;
	
	FILE*pfichero3;
	
	pfichero3 = fopen("Credenciales.txt","a+");
	
	while(fscanf(pfichero3, "%s %s\n" , vector[j].nombre, vector[j].apellidos) != EOF){
		
		j++;	
		
	}
	
	for(i=0 ; i<j ; i++){
		fflush(stdin);
		printf("%d.- %s %s\n", i+1, vector[i].nombre, vector[i].apellidos);
	}
	
}

void Cuestionario1(){
	
	char simbolo ,platino[5], platinosol[5]= "Pt", fluor, plata[5], platasol[5]= "Ag",  rodio[5], rodiosol[5]= "Rh", wolframio ;
	int resultado, contAciertos=0, contErrores=0, errores=0, aciertos=0, nota;
	
	system("cls");
	
	printf("___PRIMER CUESTIONARIO___\n\n");
	
	printf("NOTA: Las respuetas correctas sumaran 2 puntos y las erroneas restaran 1 punto \n\n");
	
	fflush(stdin);
	
	//1PREGUNNTA
	printf("Que simbolo tiene el elemento quimico platino \n\n");
	gets(platino);
    
    resultado = strcmp(platino, platinosol);
	if (resultado == 0) {
		printf("VERDADERO\n");
		contAciertos+=2;
		aciertos++;
	} else {
		printf("FALSO\n");
		contErrores++;
		errores++;
	}
    
    
    //2PREGUNNTA
    printf("Que simbolo tiene el elemento quimico fluor \n\n");
	scanf("%c",&fluor);
	
	if (fluor == 'F') {
		printf("VERDADERO\n");
		contAciertos+=2;
		aciertos++;
	} else {
		printf("FALSO\n");
		contErrores++;
		errores++;
	}
	
	fflush(stdin);
	
    //3PREGUNNTA
    printf("Que simbolo tiene el elemento quimico plata \n\n");
	gets(plata);
    
    resultado = strcmp(plata, platasol);
	if (resultado == 0) {
		printf("VERDADERO\n");
		contAciertos+=2;
		aciertos++;
	} else {
		printf("FALSO\n");
		contErrores++;
		errores++;
	}
	
	//4PREGUNNTA
	printf("Que simbolo tiene el elemento quimico rodio \n\n");
	gets(rodio);
    
    resultado = strcmp(rodio, rodiosol);
	if (resultado == 0) {
		printf("VERDADERO\n");
		contAciertos+=2;
		aciertos++;
	} else {
		printf("FALSO\n");
		contErrores++;
		errores++;
	}
	
	//5PREGUNNTA
	printf("Que simbolo tiene el elemento quimico wolframio \n\n");
	scanf("%c",&wolframio);
	
	if (wolframio == 'W') {
		printf("VERDADERO\n");
		contAciertos+=2;
		aciertos++;
	} else {
		printf("FALSO\n");
		contErrores++;
		errores++;
	}
    
    
    printf("Tus respuestas acertadas han sido %i\n\n", aciertos);
    printf("Tus respuestas erroneas han sido %i\n\n", errores);
    
    
	nota=contAciertos-contErrores;
	if (nota<0){
		nota=0;
	}
    printf("Tu calificacion es: %i", nota);
}

void Cuestionario2(){
	
		char simbolo;
	int h, ne, bi, cl, ba, contAciertos=0, contErrores=0, errores=0, aciertos=0, nota;

	system("cls");
	
	printf("___SEGUNDO CUESTIONARIO___\n\n");
	
	printf("NOTA: Las respuetas correctas sumaran 2 puntos y las erroneas restaran 1 punto \n\n");
	
	
	//1PREGUNNTA
	printf("Escribe cual es el numero atomico del Hidrogeno \n\n");
	scanf("%i",&h);
    
	if (h == 1) {
		printf("VERDADERO\n");
		contAciertos+=2;
		aciertos++;
	} else {
		printf("FALSO\n");
		contErrores++;
		errores++;
	}
    
    //2PREGUNNTA
	printf("Escribe cual es el numero atomico del Neon \n\n");
	scanf("%i",&ne);
    
	if(ne == 10){
		printf("VERDADERO\n");
		contAciertos+=2;
		aciertos++;
	} else {
		printf("FALSO\n");
		contErrores++;
		errores++;
	}
	
	//3PREGUNNTA
	printf("Escribe cual es el numero atomico del Bismuto \n\n");
	scanf("%i",&bi);
    
	if (bi == 83) {
		printf("VERDADERO\n");
		contAciertos+=2;
		aciertos++;
	} else {
		printf("FALSO\n");
		contErrores++;
		errores++;
	}
	
	//4PREGUNNTA
	printf("Escribe cual es el numero atomico del Cloro \n\n");
	scanf("%i",&cl);
    
	if (cl == 17){
		printf("VERDADERO\n");
		contAciertos+=2;
		aciertos++;
	} else {
		printf("FALSO\n");
		contErrores++;
		errores++;
	}
	
	//5PREGUNNTA
	printf("Escribe cual es el numero atomico del Bario \n\n");
	scanf("%i",&ba);
    
	if (ba == 56) {
		printf("VERDADERO\n");
		contAciertos+=2;
		aciertos++;
	} else {
		printf("FALSO\n");
		contErrores++;
		errores++;
	}
    
    printf("Tus respuestas acertadas han sido %i\n\n", aciertos);
    printf("Tus respuestas erroneas han sido %i\n\n", errores);
    
	nota=contAciertos-contErrores;
	if (nota<0){
		nota=0;
	}
    printf("Tu calificacion es: %i", nota);
    
}
