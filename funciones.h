int verificacionEdad();

float verificacionPeso();

float verificacionAltura();

int verificacionGenero();

int verificacionCantPacientes();

float calcularIMC(float peso, float altura);

float calcularDesnutricion(float pesoReal);

void determinarGradoDesnutricion(float porcentajeDesnutricion);

void fichaMedica(char nombre[], char generoString[], int edad, float peso, float altura);

void porcentajesSegunAltura(int contPacientes, float cantNiniasAltura140, float cantNiniosAltura140, float cantNiniasAltura140_170, 
                            float cantNiniosAltura140_170, float cantNiniasAltura170, float cantNiniosAltura170);

float promedioPeso(float sumaPesoNinios, int cantNinios);

void logIn();

int verificarDatos();