#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Función para calcular IMC
float calcularIMC(float peso, float altura){

    float alturaEnMetros, imc;
    alturaEnMetros = altura / 100;

    imc = peso / (alturaEnMetros * alturaEnMetros);

    return imc;
}

//Funcion para calcular desnutrición por Gonzáles
float calcularDesnutricion(float pesoReal){

    float pesoIdeal, porcentajeDesnutricion;

    printf("Ingrese el peso ideal de acuerdo a la edad del paciente en kilogramos: ");
    scanf("%f", &pesoIdeal);

    porcentajeDesnutricion = 100 - (100 * pesoReal / pesoIdeal);
    
    return porcentajeDesnutricion;
}

//Funcion para determinar el grado de desnutrición
void determinarGradoDesnutricion(float porcentajeDesnutricion){


    if(porcentajeDesnutricion <= 10 && porcentajeDesnutricion >= 0)
        printf("   El paciente no sufre de desnutricion\n\n");
    if(porcentajeDesnutricion <= 24 && porcentajeDesnutricion > 10)
        printf("   El paciente tiene desnutricion leve\n\n");
    if(porcentajeDesnutricion <= 40 && porcentajeDesnutricion > 24)
        printf("   El paciente tiene desnutricion moderada\n\n");
    if(porcentajeDesnutricion > 41)
        printf("   El paciente tiene desnutricion severa\n\n");
    if(porcentajeDesnutricion < 0)
        printf("   El paciente puede padecer sobrepeso u obesidad\n\n");
}

//Función para imprimir ficha medica y submenu diagnostrico malnutricion
void fichaMedica(char nombre[], char generoString[], int edad, float peso, float altura){    

    printf("\t---FICHA MEDICA---\n\n");
    printf("+------------+------------+-------------+-------------+------------+\n");
    printf("|     NOMBRE |     GENERO |        EDAD |      ALTURA |       PESO |\n");
    printf("+------------+------------+-------------+-------------+------------+\n");
    printf("| %10s | %10s |         %3d |    %6.2fcm |    %5.2fkg |\n", nombre, generoString, edad, altura, peso);
    printf("+------------+------------+-------------+-------------+------------+\n");         
}

//Funcion para porcentajes según la altura
void porcentajesSegunAltura(int contPacientes, float cantNiniasAltura140, float cantNiniosAltura140, float cantNiniasAltura140_170, float cantNiniosAltura140_170, float cantNiniasAltura170, float cantNiniosAltura170){

    float porcentajeNinias140, porcentajeNinios140, porcentajeNinias140_170, porcentajeNinios140_170, porcentajeNinias170, porcentajeNinios170;
    
    porcentajeNinias140 = 100 * cantNiniasAltura140 / contPacientes;
    porcentajeNinios140 = 100 * cantNiniosAltura140 / contPacientes;
    porcentajeNinias140_170 = 100 * cantNiniasAltura140_170 / contPacientes;
    porcentajeNinios140_170 = 100 * cantNiniosAltura140_170 / contPacientes;
    porcentajeNinias170 = 100 * cantNiniasAltura170 / contPacientes;
    porcentajeNinios170 = 100 * cantNiniosAltura170 / contPacientes;

    //Imprimir porcentaje niños y niñas altura < 140
    printf("El porcentaje de ninias de altura < 140cm es: %0.2f%c\n", porcentajeNinias140, '%');
    printf("El porcentaje de ninios de altura < 140cm es: %0.2f%c\n\n", porcentajeNinios140, '%');

    //Imprimir porcentaje niños y niñas 140 <= altura <= 170
    printf("El porcentaje de ninias de 140 <= altura <= 170cm es: %0.2f%c\n", porcentajeNinias140_170, '%');
    printf("El porcentaje de ninios de 140 <= altura <= 170cm es: %0.2f%c\n\n", porcentajeNinios140_170, '%');

    //Imprimir porcentaje niños y niñas altura < 140
    printf("El porcentaje de ninias de altura > 170cm es: %0.2f%c\n", porcentajeNinias170, '%');
    printf("El porcentaje de ninios de altura > 170cm es: %0.2f%c\n", porcentajeNinios170, '%');

}


//Funcion promedios de pesos
float promedioPeso(float sumaPesoNinios, int cantNinios){

    float promedioPesoNinios;


    if(cantNinios > 0)
        promedioPesoNinios = sumaPesoNinios / cantNinios;
    else
        promedioPesoNinios = 0;

    return promedioPesoNinios;
}

int verificarDatos(){
    
    int valorCentinela;
    printf("\n\nDesea continuar?\n");
    printf("Si [1] o No [0]: ");
    scanf("%d", &valorCentinela);

    return valorCentinela;
}

//Funcion verificar edad
int verificacionEdad(){

    int edad;

    do{

        printf("Ingrese la edad del paciente: ");
        scanf("%d", &edad);

        if(edad < 5 || edad > 18)
            printf("\t---ERROR INGRESO DE DATOS---\n");

    }while(edad < 5 || edad > 18);

    return edad;
}

//Funcion verificar peso
float verificacionPeso(){

    float peso;

    do{

        printf("Ingrese el peso del paciente en kilogramos: ");
        scanf("%f", &peso);

        if(peso < 0)
            printf("\t---ERROR INGRESO DE DATOS---\n");

    }while(peso < 0);

    return peso;
}

//funcion verificar altura
float verificacionAltura(){

    float altura;

    do{

        printf("Ingrese la altura del paciente en centimetros: ");
        scanf("%f", &altura);

        if(altura < 0)
            printf("\t---ERROR INGRESO DE DATOS---\n");

    }while(altura < 0);

    return altura;
}

//Funcion verificación genero
int verificacionGenero(){

    int genero;

    do{

        printf("1. Femenino\n2. Masculino\n");
        printf("Ingrese el genero del paciente: ");
        scanf("%d", &genero);

    }while(genero < 0 || genero > 2);

    return genero;
}

//Funcion verificar cantidad de pacientes
int verificacionCantPacientes(){

    int cantPacientes;

    do{

        printf("Ingrese la cantidad de pacientes: ");
        scanf("%d", &cantPacientes);
        if(cantPacientes < 0)
            printf("\t---ERROR  DE INGRESO DE DATOS---\n");
    }while(cantPacientes < 0);

    return cantPacientes;
}

//Funcion de log ing
void logIn(){

    int contErrores = 0, valorCentinela;
    char usr[6], contrasenia[9];

    do{

        valorCentinela = 0;

        printf("\t---LOG IN---\n\n");
        printf("Ingrese su usuario: ");
        scanf("%s", &usr);
        printf("Ingrese su contrasenia: ");
        scanf("%s", &contrasenia);

        if((strcmp(usr, "ADMIN") != 0) || (strcmp(contrasenia, "admin123") != 0))
            valorCentinela = 1;
        

        if(valorCentinela == 1){
            printf("\n\t---DATOS INCORRECTOS---\n");
            contErrores++;
        }
        else
            printf("\nACCEDINEDO AL SISTEMA...\n");

        system("pause");
        system("cls");
        if(contErrores == 3)
            exit(EXIT_SUCCESS);

    }while(strcmp(usr, "ADMIN") != 0 || strcmp(contrasenia, "admin123") != 0);

}
