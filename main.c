#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


int main(void){

    //variables principales
    float porcentajeNinias140, porcentajeNinias140_170, porcentajeNinias170;
    float porcentajeNinios140, porcentajeNinios140_170, porcentajeNinios170;
    float altura, peso, promedioPesoNinios, imc, alturaEnMetros;
    float arrayAlturaNinias[100], arrayIMC[100];
    int edad, genero;
    char arrayNombres[100][50];
    char *generoString;
    char nombre[50];

    //Variables de soporte
    int cantNiniasAltura140, cantNiniasAltura140_170, cantNiniasAltura170;
    int cantNiniosAltura140, cantNiniosAltura140_170, cantNiniosAltura170;
    int contPacientes, contNinios, contNinias;
    int indiceArrayAlturaNinias = 0 ;
    int indiceArrayNombres = 0;
    int indiceArrayIMC = 0;
    int valorCentinela, selector, cantDiariaPacientes;
    int i, j, k;

    //Inicialización de varibales de soporte
    contPacientes = 0;
    contNinias = 0;
    contNinios = 0;

    cantNiniasAltura140 = 0;
    cantNiniasAltura140_170 = 0;
    cantNiniasAltura170 = 0;

    cantNiniosAltura140 = 0;
    cantNiniosAltura140_170 = 0;
    cantNiniosAltura170 = 0;

    printf("Ingrese la cantidad de pacientes:\n ");
    scanf("%d", &cantDiariaPacientes);
    system("cls");

    do{

        do{

            printf("\t---INGRESO DE DATOS---\n");
            printf("Nombre del paciente: ");
            scanf("%s", &nombre);
            printf("1. Femenino\n2. Masculino\n");
            scanf("%d", &genero);
            printf("Edad del paciente: ");
            scanf("%d", &edad);
            printf("Peso del paciente: ");
            scanf("%f", &peso);
            printf("Altura del paciente: ");
            scanf("%f", &altura);
            system("cls");

            //Mensajes de error a la entrada de datos
            if(genero < 0 || genero > 2)
                printf("\t---ERROR DATO DE GENERO INCORRECTO--\n");
            if(edad < 0)
                printf("\t---ERROR DATO DE EDAD INCORRECTO--\n");
            if(peso < 0)
                printf("\t---ERROR DATO DE PESO INCORRECTO--\n");
            if(altura < 0)
                printf("\t---ERROR DATO DE ALTURA INCORRECTO--\n");
            system("pause");
            system("cls");

        }while(genero < 0 || genero > 2 || edad < 0 || peso < 0 || altura < 0);
        
        //Calcular el IMC
        alturaEnMetros = altura / (float) 100;
        imc = peso / (alturaEnMetros * alturaEnMetros);
        arrayIMC[indiceArrayIMC] = imc;
        indiceArrayIMC++;

        //Guardar los nombres de los pacientes en un array
        strcpy(arrayNombres[indiceArrayNombres], nombre);
        indiceArrayNombres++; 

        //Hacer explicito el genero
        switch (genero)
        {
        case 1:
            generoString = "Femenino";

            //Array para guardar la altura de las niñas menores de 10 años y con 35 <= peso <= 50 kg
            if(edad < 10 && peso >= 35 && peso <= 50){

                arrayAlturaNinias[indiceArrayAlturaNinias] = altura;
                indiceArrayAlturaNinias++;
            }

            //cantidad de niñas con altura < 140
            if(altura < 140)
                cantNiniasAltura140++;

            //cantidad de niñas con 140 <= altura <= 170
            if(altura >= 140 && altura <= 170)
                cantNiniasAltura140_170++; 

            //cantidad de niñas con altura > 170
            if(altura > 170)
                cantNiniasAltura170++;
            
            contNinias++;
            break;
        case 2:
            generoString = "Masculino";

            //Sacar el promedio del peso de los niños
            promedioPesoNinios += peso;

            //cantidad de niños con altura < 140
            if(altura < 140)
                cantNiniosAltura140++;

            //cantidad de niños con 140 <= altura <= 170
            if(altura >= 140 && altura <= 170)
                cantNiniosAltura140_170++; 

            //cantidad de niños con altura > 170
            if(altura > 170)
                cantNiniosAltura170++;

            contNinios++;

            break;
        }

        //Ficha médica
        printf("\t---FICHA MEDICA---\n");
        printf("Nombre: %s\n", nombre);
        printf("Genero: %s\n", generoString);
        printf("Edad: %d\n", edad);
        printf("Peso: %0.2f\n", peso);
        printf("Altura: %0.2f\n", altura);
        printf("IMC: %0.2f\n", imc);
        system("pause");
        system("cls");

        cantDiariaPacientes--;
    }while(cantDiariaPacientes > 0);
    
    contPacientes = contNinias + contNinios;

    do{

        printf("\t---MENU---\n");
        printf("1. Procentajes segun altura\n2. Promedio pesos ninios\n3. Altura de ninias\n4. IMC de los pacientes\n5. Salir\n");
        scanf("%d", &selector);
        system("cls");

        switch (selector)
        {
        case 1:
            printf("\t---PORCENTAJES DE NINIOS Y NINIAS SEGUN SU ALTURA---\n");

            //Imprimir porcentaje niños y niñas altura < 140
            porcentajeNinias140 = 100 * cantNiniasAltura140 / contPacientes;
            porcentajeNinios140 = 100 * cantNiniosAltura140 / contPacientes;
            printf("El porcentaje de ninias de altura < 140cm es: %f%\n", porcentajeNinias140);
            printf("El porcentaje de ninios de altura < 140cm es: %f%\n\n", porcentajeNinios140);

            //Imprimir porcentaje niños y niñas 140 <= altura <= 170
            porcentajeNinias140_170 = 100 * cantNiniasAltura140_170 / contPacientes;
            porcentajeNinios140_170 = 100 * cantNiniosAltura140_170 / contPacientes;
            printf("El porcentaje de ninias de 140 <= altura <= 170cm es: %f%\n", porcentajeNinias140_170);
            printf("El porcentaje de ninios de 140 <= altura <= 170cm es: %f%\n\n", porcentajeNinios140_170);

            //Imprimir porcentaje niños y niñas altura < 140
            porcentajeNinias170 = 100 * cantNiniasAltura170 / contPacientes;
            porcentajeNinios170 = 100 * cantNiniosAltura170 / contPacientes;
            printf("El porcentaje de ninias de altura > 170cm es: %f%\n", porcentajeNinias170);
            printf("El porcentaje de ninios de altura > 170cm es: %f%\n", porcentajeNinios170);
            system("pause");
            system("cls");

            break;
        case 2:
            printf("\t---PESO PROMEDIO DE NINIOS---\n");
            
            //Imprimir promedio del peso de los niños
            promedioPesoNinios = promedioPesoNinios / ((float) contNinios);
            printf("Promedio de peso de ninios: %0.2f\n", promedioPesoNinios);
            system("pause");
            system("cls");

            break;
        case 3:
            printf("\t---ALTURA DE LAS NINIAS MENORES 10 ANIOS CON 35 <= ALTURA <= 50---\n");

            //Imprimir el array de las niñas menores de 10 años con 35 <= peso <= 50 kg     
            for(i = 0; i < indiceArrayAlturaNinias; i++){

                printf("Estas son las alturas de las ninias: %0.2f\n", arrayAlturaNinias[i]);
            }
            system("pause");
            system("cls");
    
            break;
        case 4:

            printf("\t---MOSTRAR DATOS DE LOS PACIENTES---\n");
            //Imprimir el IMC con los nombres de los pacientes
            
            printf("---\n");
            printf("NOMBRE\n");
            printf("---\n");
            for(j = 0; j < indiceArrayNombres; j++){

                printf("| %10s |", arrayNombres[j]);
            }
            printf("\n---\n");
            printf("IMC\n");
            printf("---\n");
            for(k = 0; k < indiceArrayIMC; k++){

                printf("|      %0.2f |", arrayIMC[k]);
            }
            printf("\n");
            system("pause");
            system("cls");

            break;
        case 5:

            printf("\t---SALIR---\n");
            break;
        }
    
    }while(selector != 5);

    system("pause");
    return 0; 
}


