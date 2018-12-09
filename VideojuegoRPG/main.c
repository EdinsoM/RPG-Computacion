#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.h"

typedef struct nodoL{
    int val;
    struct nodoL *sig;
} NodoL;

typedef NodoL * Lista;

Lista newList(){
    return NULL;
}

typedef struct perso { //Creamos la estructura del personaje
    char nombre[16];//1
    //char tipo[32];
    int ptSalud;//1
    int ptEnergia;//1
    Pila* inventario;
    Lista* habilidades;
    int dano;
    int rango;
    int armadura;
    int evasion;
    int velocidad;
    int ptAccion;//1
    int jugador;
}Perso;

typedef Perso* Personaje;

Personaje newMototaxista(){
    Personaje g = malloc(sizeof(Perso));
    //g->tipo[32];
    g->nombre[16];
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    g->dano=10;
    g->rango=1;
    g->armadura=40;
    return g;
}
Personaje newPolitiCorrupto(){
    Personaje g = malloc(sizeof(Perso));
    //g->tipo[32];
    g->nombre[16];
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    g->dano=10;
    g->rango=1;
    g->armadura=40;
    return g;
}
Personaje newMedicoCubano(){
    Personaje g = malloc(sizeof(Perso));
    //g->tipo[32];
    g->nombre[16];
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    g->dano=10;
    g->rango=1;
    g->armadura=40;
    return g;
}
Personaje newProfesor(){
    Personaje g = malloc(sizeof(Perso));
    //g->tipo[32];
    g->nombre[16];
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    g->dano=10;
    g->rango=1;
    g->armadura=40;
    return g;
}

enum Efecto{
    Ninguno, Electrificado, Incendiado, Congelado //Ninguno = 0, Electrificado = 1, Incendiado = 2, Congelado = 3;
};

typedef struct terreno{
    Perso* Personaje;
    enum Efecto efecto;
    // items Lista (Item);
} Terreno[10][20];

void seleccionPersonaje(){

    Personaje Cantidad[16];

    int seleccion, p, s;

        for(p=0;p<16;p++){

            if(p==15) printf("\nUltimo personaje (maximo: 16 jugadores)\n");

            printf("\nPersonaje %d, tipo: ",p);
            printf("\n(1) Mototaxista \n(2) Politico corrupto \n(3) Medico cubano \n(4) Profesor \n(0) Para salir\nOpcion: ");
            scanf("%d", &seleccion);

            if(seleccion == 0) break;

            else if(seleccion == 1){
                fflush(stdin);
                Cantidad[p] = newMototaxista();
                printf("\nNombre de tu mototaxista: ");
                gets(Cantidad[p]->nombre);
            }
            else if(seleccion == 2){
                fflush(stdin);
                Cantidad[p] = newPolitiCorrupto();
                printf("\nNombre politico corrupto: ");
                gets(Cantidad[p]->nombre);
            }
            else if(seleccion == 3){
                fflush(stdin);
                Cantidad[p] = newMedicoCubano();
                printf("\nNombre medico cubano: ");
                gets(Cantidad[p]->nombre);
            }
            else if(seleccion == 4){
                fflush(stdin);
                Cantidad[p] = newProfesor();
                printf("\nNombre profesor: ");
                gets(Cantidad[p]->nombre);
            }
            else{
                printf("\nSelecciona una opcion correcta");
                p--;
            }
        }
        for(int i = 0; i<p; i++){
            printf("\nPersonaje %d: ",i);
            puts(Cantidad[i]->nombre);
            printf("Salud %d, ", Cantidad[i]->ptSalud);
            printf("energia %d, ", Cantidad[i]->ptEnergia);
            printf("accion %d, ", Cantidad[i]->ptAccion);
            printf("dano %d, ", Cantidad[i]->dano);
            printf("rango %d, ", Cantidad[i]->rango);
            printf("armadura %d \n", Cantidad[i]->armadura);
        }
}

int main()
{
    seleccionPersonaje();
    return 0;
}
