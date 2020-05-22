// TRABAJO ----->  Tabla Periodica

/*Programa que nos aporta informacion sobre la tabla periodica e incluye algunos cuestionarios a realizar.
  El programa posee varias opciones, que voy a escribir brevemente para que el usuario tenga el trabajo esquematizado y se sepa las funciones
  que puede realizar:
t1. Introduce tus credenciales. EN ESTA OPCION NOS PODEMOS REGISTRAR PUDIENDO PONER EL NUMERO DE PERSONAS QUE SE VAN A REGISTRAR	
t2. Mirar credenciales previamente introducidas. ESTA OPCION NOS APORTA TODOS LOS USUARIOS QUE SE HAN IDO REGISTRANDO EN EL PROGRAMA
t3. Introduce el numero del elemento y te decimos informacion sobre el.	OPCION EN LA CUAL, EL PROGRAMA NOS FACILITARA ALGUNOS DATOS BASICOS 
																		SOBRE LOS ELEMNTOS DE LA TABLA PERIODICA QUE NOS AYUDARAN A LA REALIZACION 
																		DE LOS CUESTIONARIOS PROPUESTOS EN LAS SIGUIENTES OPCIONES
t4. Realizar Cuestionario 1. OPCION QUE TE DERIVA A UN SIMPLE CUESTIONARIO EL CUAL TE DARA TU CALIFICACION OBTENIDA
t5. Realizar Cuestionario 2. TIENE LA MISMA FUNCIONALIDAD QUE LA ANTERIOR OPCIO PERO TENDREMOS DISTINTAS PREGUNTAS
t6. Cerrar el programa.
*/


#include <stdio.h>
#include <string.h>

// Estructuras

struct TTabla {      // Estructura que almacena todos los simbolos para la creación de la tabla periódica.
	char elemento[3];
};

struct TCredenciales{// Estructura usada tanto para escribir como leer en por parte de las funciones de las credenciales.
	char nombre[50];
	char apellidos[100];
};

struct TElementos{// Estructura que será utilizada para imprimir en la opción 3 del menú.
	char nombre[50];
	char simbolo[3];
	int nAtomico;
	float masaAtomica;
	int periodo;
	int grupo;
};


// Declaración de funciones

void dibujamenu();
void tablaperiodica(struct TTabla clase[]);
void Credenciales(struct TCredenciales vector[]); // Puesto que las funciones son de no retorno de valor, todo está programado par funcionar con 
void elementos(struct TElementos elemento[]);	  // paso por referencia, tomando simpre las estructuras previas.
void verCredenciales(struct TCredenciales vector[]);
void Cuestionario1();
void Cuestionario2();


//------------------------------//

int main(){ 
	
	int opcion,numero;
	
	struct TTabla clase[500];
	
	struct TCredenciales vector[1000];
	
	struct TElementos elemento[1000];
	
	int i,nelemento = 0;
	
	int tabla /*,credenciales, vercredenciales*/;
	
	FILE*pfichero1;
	
	FILE*pfichero2;
	
	FILE*pfichero3;
	
//------------------------------//	
	
	pfichero1 = fopen("Tabla.txt","r");//Iniciamos el fichero unicamente en modo lectura.
	
	if(pfichero1 == NULL){
		
		printf("No se ha podido crear el fichero.\n");
		return 0;
	}
	
	pfichero2 = fopen("Elementos.txt","r");//Iniciamos el fichero unicamente en modo lectura.
	
	if(pfichero2 == NULL){
		
		printf("No se ha podido crear el fichero.\n");
		return 0;
	}
	
	pfichero3 = fopen("Credenciales.txt","a+");// Iniciamos el fichero y si no existe lo crea dándole el nombre asignado. Además lo ponemos tanto en modo escritura como lectura.
	
	if(pfichero3 == NULL){
		
		printf("No se ha podido crear el fichero.\n");
		return 0;
	}
	
	while(fscanf(pfichero1, "%s" , clase[nelemento].elemento) != EOF){ // Escaneamos el fichero que dará lugar a la tabla periodica y lo guardamos en la estructura tabla.
		
		nelemento++;	
	}
	
	
	for(i=0;i<nelemento;i++){ // Escaneamos el fichero que contiene toda la información de los elementos de la tabla periódica y la guardamos en la estructura elemento.
		
		fscanf(pfichero2,"%s %s %d %f %d %d", elemento[i].nombre, elemento[i].simbolo, &elemento[i].nAtomico, &elemento[i].masaAtomica, &elemento[i].periodo, &elemento[i].grupo);
	}
	
	

	fclose(pfichero1);
	
	fclose(pfichero2);
	
	
	dibujamenu(); //Dibujamos el menú con el banner.
	
	tablaperiodica(clase);	// Dibujamos la tabla periódica.
		
	
	do{
		printf("\n\nIntroduce una de las opciones del menu (0 para ver las opciones)\n");
		scanf( "%d" , &opcion );
		switch(opcion){
			
			case 0:
				system("cls");// Utilizado para limpair la pantalla.
				dibujamenu();
			break;
			
			case 1:printf("Introduce tus credenciales.\n");
				   Credenciales(vector);
			break;
		
			case 2:printf("Mirar credenciales previamente introducidas.\n");
				   verCredenciales(vector);
			break;
		
			case 3:printf("Indica el numero de un elemento y te decimos informacion de el.\n");
				   elementos(elemento);
			break;
		
			case 4:printf("Ha entrado al Cuestionario 1.\n");
				   Cuestionario1();
			break;
		
			case 5:printf("Ha entrado al Cuestionario 2.\n");
				   Cuestionario2();
			break;	
		
			case 6:printf("Gracias por haber usado nuestro programa.\n");
			break;
		
			default: printf("Por favor introduzca un valor entre 1 y 6.\n");
		
		}
		
	}while(opcion!=6);
	
}


void dibujamenu(){ //Función que muestra el menu usuario
	
	
	printf("------------------------------------------\n");
	printf("------Programa de la Tabla Periodica------\n");
	printf("------------------------------------------\n\n\n");
	
	printf("Menu de opciones.\n\n");
	
	printf("\t1. Introduce tus credenciales.\n\n");
	
	printf("\t2. Mirar credenciales previamente introducidas.\n\n");
	
	printf("\t3. Introduce el numero del elemento y te decimos informacion sobre el.\n\n");
	
	printf("\t4. Realizar Cuestionario 1.\n\n");
	
	printf("\t5. Realizar Cuestionario 2.\n\n");
	
	printf("\t6. Cerrar el programa.\n\n");
	
	printf("--------------------------------------------------------------------------------\n\n");
}

void tablaperiodica(struct TTabla clase[]){
	
	int k,nelemento=118,longitud;
	
	printf("%s",clase[0].elemento);
	printf("                                                  ");
	printf("%s",clase[1].elemento);
	printf("\n");
		
	for(k=2; k<=3; k++){
		printf("%s ", clase[k].elemento);
		longitud=strlen(clase[k].elemento);//En cada bucle para poner la tabla bien ordenada medimos la longitud del símbolo, que puede ser de 1 ó 2 caracteres,
		if (longitud==1){				   //y si longitud = 1 imprimimos un espacio para poder colocar todos los símbolos bien.
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

void Credenciales(struct TCredenciales vector[]){ //Funcion que permite introducir credenciales 
	
	system("cls");
	
	int personas,i;
	
	FILE*pfichero3;
	
	pfichero3 = fopen("Credenciales.txt","a+");
	
	printf("Cuantas credenciales (personas) quieres meter:\n");
	scanf("%d",&personas);
	
	for(i=0 ; i<personas ; i++){
		
		printf("Nombre Apellido:\n");
		fflush(stdin);
		scanf("%s %s",vector[i].nombre, vector[i].apellidos);
		fprintf( pfichero3, "%s	%s\n", vector[i].nombre, vector[i].apellidos );
		
	}
	
	fclose(pfichero3);
	//return 0;
}

void elementos(struct TElementos elemento[]){ // Funcion que detalla una serie de caracteristicas de los elementos quimicos, cuando el usuario introduce un numero atomico cualquiera de la tabla periodica
	
	system("cls");
	int n;
	char seguir;
	
	do{
		printf("Introduce el numero atomico del elemento:\n");
		fflush(stdin);
		scanf("%d",&n);
		if (n<=0||n>118){
			printf("No existe ese elemento\n");
		}
		
		if (n>0&&n<=118){
			printf("\nElemento: %s\nSimbolo: %s\nNumero Atomico: %d\nMasa Atomica: %.3f u\nPeriodo: %d\nGrupo: %d\n",elemento[n-1].nombre,elemento[n-1].simbolo,elemento[n-1].nAtomico,elemento[n-1].masaAtomica,elemento[n-1].periodo,elemento[n-1].grupo);
		}
		
		printf("\nQuieres informacion sobre otro elemento?(s o n)\n");
		fflush(stdin);
		scanf("%c",&seguir);
	}while(seguir=='s');	
	
}


void verCredenciales(struct TCredenciales vector[]){ //Funcion que permite ver las credenciales que se han introducido anteriormente a la hora de usar el programa
	
	system("cls");
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

void Cuestionario1(){ // Funcion Cuestionario 1
	
	char simbolo ,platino[5], platinosol[5]= "Pt", fluor, plata[5], platasol[5]= "Ag",  rodio[5], rodiosol[5]= "Rh", wolframio ;
	int resultado, contAciertos=0, contErrores=0, errores=0, aciertos=0, nota;
	
	system("cls");
	
	printf("___PRIMER CUESTIONARIO___\n\n");
	
	printf("NOTA: Las respuetas correctas sumaran 2 puntos y las erroneas restaran 1 punto \n\n");
	
	
	//1PREGUNNTA
	printf("Que simbolo tiene el elemento quimico platino \n\n");
	fflush(stdin);
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
    fflush(stdin);
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
    fflush(stdin);
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
	fflush(stdin);
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
	fflush(stdin);
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

void Cuestionario2(){ //Funcion Cuestionario 2
	
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
