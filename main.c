#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "funciones.h"


int main(void){
    
    //variables principales
    float altura, peso, promedioPesoNinios, promedioPesoNinias, imc, alturaEnMetros;
    float arrayAlturaNinias[100], arrayIMC[100], arrayAlturas[100], arrayPesos[100], arrayDesnutricion[100];
    int arrayEdades[100];
    int edad, genero;
    char arrayNombres[100][50], arrayNombresNinias[100][50];
    char *generoString;
    char nombre[50];

    //Variables para la clasificación de desnutrición por Gonzales
    float pesoParaEdadPercentil50, porcentajeDesnutricion; 

    //Variables de soporte
    int cantNiniasAltura140, cantNiniasAltura140_170, cantNiniasAltura170;
    int cantNiniosAltura140, cantNiniosAltura140_170, cantNiniosAltura170;
    int contPacientes, contNinios, contNinias;
    int indiceArrayAlturaNinias = 0, indiceArrayNombres = 0, indiceArrayIMC = 0, indiceArrayNombresNinias = 0;
    int indiceArrayEdades = 0, indiceArrayAlturas = 0, indiceArrayPesos = 0, indiceArrayDesnutricion = 0;
    int selectorMenu, cantDiariaPacientes, valorCentinela;
    int i, j;

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

    /*Log in del usuario
      Usuario: ADMIN
      Contraseña: admin123*/
    logIn();

    cantDiariaPacientes = verificacionCantPacientes();
    system("cls");

    //Obtencion datos de los pacientes y operaciones con los mismos
    do{

        do{

            printf("\t---INGRESO DE DATOS---\n\n");
            printf("Nombre del paciente: ");
            scanf("%s", &nombre);
            genero = verificacionGenero();
            edad = verificacionEdad();
            altura = verificacionAltura();
            peso = verificacionPeso();
            valorCentinela = verificarDatos();
            system("cls");

        }while(genero < 0 || genero > 2 || edad < 0 || peso < 0 || altura < 0 || valorCentinela != 1);
        
        //Guardar los nombres de los pacientes en un array
        strcpy(arrayNombres[indiceArrayNombres], nombre);
        indiceArrayNombres++; 

        //Guardar las edades en un array
        arrayEdades[indiceArrayEdades] = edad;
        indiceArrayEdades++;

        //Guardar alturas en un array
        arrayAlturas[indiceArrayAlturas] = altura;
        indiceArrayAlturas++;

        //Guardar los pesos en un array
        arrayPesos[indiceArrayPesos] = peso;
        indiceArrayPesos++;

        //Hacer el genero un string
        switch (genero)
        {
        case 1:
            generoString = "Femenino";

            promedioPesoNinias += peso;

            //Array para guardar la altura de las niñas menores de 10 años y con 35 <= peso <= 50 kg
            if(edad < 10 && peso >= 35 && peso <= 50){

                arrayAlturaNinias[indiceArrayAlturaNinias] = altura;
                indiceArrayAlturaNinias++;

                strcpy(arrayNombresNinias[indiceArrayNombresNinias], nombre);
                indiceArrayNombresNinias++;
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
        fichaMedica(nombre, generoString, edad, peso, altura);
        
        //Calcular el IMC
        imc = calcularIMC(peso, altura);
        arrayIMC[indiceArrayIMC] = imc;
        indiceArrayIMC++;

        //Calcular desnutricion por Gonzales
        printf("NOTA: Revisar la tabla \"peso para edad\" en la carpeta anexos.\n");
        porcentajeDesnutricion = calcularDesnutricion(peso);
        arrayDesnutricion[indiceArrayDesnutricion] = porcentajeDesnutricion;
        indiceArrayDesnutricion++; 

        printf("\nDIAGNOSTICO:\n\n");
        printf("1. El IMC del paciente es: %0.2f\n", imc);
        printf("   NOTA: Revisar la tabla \"IMC para edad\" en la carpeta anexos, para determinar si sufre de obesidad o sobrepeso.\n\n");

        printf("2. El porcentaje de desnutricion es: %0.2f%c\n", porcentajeDesnutricion, '%');
        determinarGradoDesnutricion(porcentajeDesnutricion);
        system("pause");
        system("cls");

        cantDiariaPacientes--;
    }while(cantDiariaPacientes > 0);
    
    contPacientes = contNinias + contNinios;

    promedioPesoNinios = promedioPeso(promedioPesoNinios, contNinios);
    promedioPesoNinias = promedioPeso(promedioPesoNinias, contNinias);

    //Menú para la visualización de los datos obtenidos
    do{
        printf("\t---MENU---\n\n");
        printf("1. Procentajes segun altura\n2. Promedio pesos\n3. Altura de ninias\n4. Datos de los pacientes\n5. Salir\n");
        scanf("%d", &selectorMenu);
        system("cls");

        switch (selectorMenu)
        {
        case 1:
            printf("\t---PORCENTAJES DE NINIOS Y NINIAS SEGUN SU ALTURA---\n\n");

            porcentajesSegunAltura(contPacientes, cantNiniasAltura140, cantNiniosAltura140, cantNiniasAltura140_170, cantNiniosAltura140_170, cantNiniasAltura170, cantNiniosAltura170);
            printf("\n");
            system("pause");
            system("cls");

            break;
        case 2:
            printf("\t---PESO PROMEDIO NINIOS Y NINIAS---\n\n");
            //Imprimir promedio del peso de los niños
            printf("Promedio de peso de ninios: %0.2fkg\n\n", promedioPesoNinios);
            printf("Promedio de peso de ninias: %0.2fkg\n\n", promedioPesoNinias);
            system("pause");
            system("cls");

            break;
        case 3:
            printf("\t---ALTURA DE LAS NINIAS MENORES 10 ANIOS CON 35 <= PESO <= 50---\n\n");

            //Imprimir el array de las niñas menores de 10 años con 35 <= peso <= 50 kg     
            printf("+------------+-------------+\n");
            printf("|     NOMBRE |      ALTURA |\n");
            printf("+------------+-------------+\n");
                
            for(i = 0; i < indiceArrayNombresNinias; i++){

                printf("| %10s |    %6.2fcm | \n", arrayNombresNinias[i], arrayAlturaNinias[i]);
                printf("+------------+-------------+\n");
            }

            printf("\nLas ninias en esta tabla padencen de obesidad o sobrepeso, necesitan tartamiento urgente\n\n");
            system("pause");
            system("cls");

            break;
        case 4:
            
            printf("\t---MOSTRAR DATOS DE LOS PACIENTES---\n\n");
            
            printf("+------------+-------------+-------------+------------+------------+-------------------------+\n");
            printf("|     NOMBRE |        EDAD |      ALTURA |       PESO |        IMC | PORCENTAJE DESNUTRICION |\n");
            printf("+------------+-------------+-------------+------------+------------+-------------------------+\n");
            for(j = 0; j < contPacientes; j++){
                printf("| %10s |         %3d |    %6.2fcm |    %5.2fkg |       %5.2f|                  %6.2f%c|\n", arrayNombres[j], arrayEdades[j], arrayAlturas[j], arrayPesos[j], arrayIMC[j], arrayDesnutricion[j], '%');
                printf("+------------+-------------+-------------+------------+------------+-------------------------+\n");
            }

            printf("\n");
            system("pause");
            system("cls");

            break;
        case 5:

            printf("\t---SALIENDO---\n");
            break;
        default:

            printf("\t---NO EXISTE ESTA OPCION---\n");
            system("pause");
            system("cls");
            break;
    }    

    }while(selectorMenu != 5);
    
    return 0; 
}