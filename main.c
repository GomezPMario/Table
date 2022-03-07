#include <stdio.h>
#include <stdlib.h>

#define alturaCeldas 3
#define terceraColumna 5

//Prototipado de las funciones
int selectorLinea();
void encabezado(int primeraColumna, int segundaColumna, int alturaEncabezado, char esquinaIzquierda, char esquinaDerecha, char guion, char pared);
void lineasExteriores(int primeraColumna, int segundaColumna, char guion, char t, char esquinaIzquierda, char esquinaDerecha);
void lineaCentral(int primeraColumna, int segundaColumna, char paredExterior, char paredInterior);
void entreCeldas(int primeraColumna, int segundaColumna, char guion, char tParedIzquierda, char mas, char tParedDerecha);
void imprimirTabla(int primeraColumna, int segundaColumna, int cantidadCeldas, int tipoLinea, int alturaEncabezado, char guion, char pared, char esquinaSuperiorIzquierda,
                   char esquinaSuperiorDerecha, char tNormal, char tParedIzquierda, char tParedDerecha, char tInvertida, char esquinaInferiorIzquierda,
                   char esquinaInferiorDerecha, char mas);
void conformidad(int conforme);

int main()
{
    int primeraColumna = 0;
    int segundaColumna = 0;
    int cantidadCeldas = 0;
    int alturaEncabezado = 0;
    int conforme = 0;

    char esquinaSuperiorIzquierda;
    char esquinaSuperiorDerecha;
    char esquinaInferiorIzquierda;
    char esquinaInferiorDerecha;
    char guion;
    char tNormal;
    char tInvertida;
    char pared;
    char tParedIzquierda;
    char tParedDerecha;
    char mas;
    int tipoLinea;

    printf("\n  %c Bienvenido al proyecto realizado por Mario G%cmez relacionado con el uso de tablas!!\n\n\n",175, 162);

    tipoLinea = selectorLinea();
    if(tipoLinea == 1){
        esquinaSuperiorIzquierda = 218;
        esquinaSuperiorDerecha = 191;
        esquinaInferiorIzquierda = 192;
        esquinaInferiorDerecha = 217;
        guion = 196;
        tNormal = 194;
        tInvertida = 193;
        pared = 179;
        tParedIzquierda = 195;
        tParedDerecha = 180;
        mas = 197;
    }else{
        esquinaSuperiorIzquierda = 201;
        esquinaSuperiorDerecha = 187;
        esquinaInferiorIzquierda = 200;
        esquinaInferiorDerecha = 188;
        guion = 205;
        tNormal = 203;
        tInvertida = 202;
        pared = 186;
        tParedIzquierda = 204;
        tParedDerecha = 185;
        mas = 206;
    }

    printf("\n  %c Introduzca la altura deseada del encabezado: ", 175);
    scanf("%d", &alturaEncabezado);

    //Funcion para limpiar la pantalla
    system("cls");

    printf("\n  %c Introduzca el n%cmero de celdas necesarias para adjuntar los archivos: ", 175, 163);
    scanf("%d", &cantidadCeldas);

    system("cls");

    printf("\n  %c A continuaci%cn, se le va a pedir que introduzca el valor de anchura de la primera columna (longitud del espacio) y de la segunda columna (nombre del archivo):\n\n", 175, 162);
    printf("\t %c Valor de anchura de la primera columna: ", 175);
    scanf("%d", &primeraColumna);
    printf("\n");
    printf("\t %c Valor de anchura de la segunda columna: ", 175);
    scanf("%d", &segundaColumna);

    system("cls");

    //Se le aporta al usuario un resumen de sus datos aportados
    printf("\n  %c La tabla a imprimir contiene los siguientes datos: \n",175);
    if(tipoLinea == 1)printf("\t %c Tipo de l%cnea: L%cnea simple.\n", 126, 161, 161);
    else if(tipoLinea == 2) printf("\t %c Tipo de l%cnea: L%cnea doble.\n", 126, 161, 161);

    printf("\t %c Altura del encabezado: %d\n", 126, alturaEncabezado);
    printf("\t %c Cantidad de celdas que desea imprimir: %d\n", 126, cantidadCeldas);
    printf("\t %c Altura de cada celda excluyendo las filas exteriores: %d\n", 126,alturaCeldas);
    printf("\t %c Valor de anchura de la primera columna (longitud del espacio): %d\n", 126, primeraColumna);
    printf("\t %c Valor de anchura de la segunda columna (nombre del archivo): %d\n", 126, segundaColumna);
    printf("\t %c Valor de anchura de la tercera columna: %d\n", 126, terceraColumna);
    printf("\n\n");

    //Imprimimos la tabla con los datos aportados por el usuario
    imprimirTabla(primeraColumna, segundaColumna, cantidadCeldas, tipoLinea, alturaEncabezado, guion, pared, esquinaSuperiorIzquierda, esquinaSuperiorDerecha, tNormal, tParedIzquierda,
                  tParedDerecha, tInvertida, esquinaInferiorIzquierda, esquinaInferiorDerecha, mas);

    printf("\n\n");

    conformidad(conforme);
}

//Implementacion de las funciones

int selectorLinea(){
    int tipoLinea = 0;

    printf("  %c %cC%cmo desea visualizar la tabla%c\n",175, 168, 162, 63);
    printf("\t1. L%cnea simple.\n", 161);
    printf("\t2. L%cnea doble.\n", 161);
    printf("\n  %c Su valor seleccionado es: ",175);
    scanf("%d", &tipoLinea);
    printf("\n");

    while(tipoLinea != 1 && tipoLinea != 2){
        printf("  %c Error: el valor introducido es incorrecto. Por favor ingrese un valor correcto.\n",175);
        printf("\t  %c Su valor actual seleccionado es: ",175);
        scanf("%d", &tipoLinea);
        printf("\n");
    }

    //Funcion para limpiar la pantalla
    system("cls");

    return tipoLinea;
}

void encabezado(int primeraColumna, int segundaColumna, int alturaEncabezado, char esquinaIzquierda, char esquinaDerecha, char guion, char pared){
    int anchuraTotal = primeraColumna + segundaColumna + terceraColumna;

    lineasExteriores(primeraColumna, segundaColumna, guion, guion, esquinaIzquierda, esquinaDerecha);
    for(int i = 0; i < alturaEncabezado; i++){
        lineaCentral(primeraColumna, segundaColumna, pared, ' ');
    }
}

void lineasExteriores(int primeraColumna, int segundaColumna, char guion, char t, char esquinaIzquierda, char esquinaDerecha){
    printf("%c", esquinaIzquierda);
    //Imprimimos la anchura de la primera columna
    for (int i = 0; i < primeraColumna; i++){
        printf("%c", guion);
    }
    printf("%c", t);

    //Imprimimos la anchura de la segunda columna
    for(int i = 0; i < segundaColumna; i++){
        printf("%c", guion);
    }
    printf("%c", t);

    //Imprimimos la anchura de la tercera columna
    for (int i = 0; i < terceraColumna; i++){
        printf("%c", guion);
    }
    printf("%c", esquinaDerecha);
    printf("\n");
}

void lineaCentral(int primeraColumna, int segundaColumna, char paredExterior, char paredInterior){
    printf("%c", paredExterior);
    for (int i = 0; i < primeraColumna; i++){
        printf(" ");
    }
    printf("%c", paredInterior);

    for(int i = 0; i < segundaColumna; i++){
        printf(" ");
    }
    printf("%c", paredInterior);

    for (int i = 0; i < terceraColumna; i++){
        printf(" ");
    }
    printf("%c", paredExterior);
    printf("\n");
}

void entreCeldas(int primeraColumna, int segundaColumna, char guion, char tParedIzquierda, char mas, char tParedDerecha){
    printf("%c", tParedIzquierda);

    for (int i = 0; i < primeraColumna; i++){
        printf("%c", guion);
    }
    printf("%c", mas);

    for(int i = 0; i < segundaColumna; i++){
        printf("%c", guion);
    }
    printf("%c", mas);

    for (int i = 0; i < terceraColumna; i++){
        printf("%c", guion);
    }
    printf("%c", tParedDerecha);
    printf("\n");
}

void imprimirTabla(int primeraColumna, int segundaColumna, int cantidadCeldas, int tipoLinea, int alturaEncabezado, char guion, char pared, char esquinaSuperiorIzquierda,
                   char esquinaSuperiorDerecha, char tNormal, char tParedIzquierda, char tParedDerecha, char tInvertida, char esquinaInferiorIzquierda,
                   char esquinaInferiorDerecha, char mas){

    encabezado(primeraColumna, segundaColumna, alturaEncabezado, esquinaSuperiorIzquierda, esquinaSuperiorDerecha, guion, pared);
    lineasExteriores(primeraColumna, segundaColumna, guion, tNormal, tParedIzquierda, tParedDerecha);
    for(int i = 0; i < (cantidadCeldas - 1); i++){
        for(int j = 0; j < alturaCeldas; j++){
            lineaCentral(primeraColumna, segundaColumna, pared, pared);
        }
        entreCeldas(primeraColumna, segundaColumna, guion, tParedIzquierda, mas, tParedDerecha);
    }
    for(int i = 0; i < alturaCeldas; i++){
        lineaCentral(primeraColumna, segundaColumna, pared, pared);
    }
    lineasExteriores(primeraColumna, segundaColumna, guion, tInvertida, esquinaInferiorIzquierda, esquinaInferiorDerecha);
}

void conformidad(int conforme){
    printf("  %c %cEst%c conforme con el resultado de su tabla%c\n",175, 168, 160, 63);
    printf("\t %c 1. S%c \n", 126, 161);
    printf("\t %c 2. No, elegir de nuevo \n", 126);
    printf("\n  %c Su valor seleccionado es: ",175);
    scanf("%d", &conforme);

    //Comprobamos si el valor introducido por el usuario es correcto
    while(conforme != 1 && conforme != 2){
        printf("  %c Error: el valor introducido es incorrecto. Por favor ingrese un valor correcto.\n",175);
        printf("\t  %c Su valor actual seleccionado es: ",175);
        scanf("%d", &conforme);
        printf("\n");
    }

    system("cls");

    if (conforme == 2) return main();
}
