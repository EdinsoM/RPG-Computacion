#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.h"
#include <math.h>

typedef struct nodoL{
    int val;
    struct nodoL *sig;
} NodoL;

typedef NodoL * Lista;

Lista newList(){
    return NULL;
}

typedef struct perso { //Creamos la estructura del personaje
    char nombre[16];
    //char tipo[32];
    int ptSalud;
    int ptEnergia;
    Pila* inventario;
    Lista* habilidades;
    int dano;
    int rango;
    int armadura;
    int evasion;
    int velocidad;
    int ptAccion;
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

Personaje Jugador[16]; ///Definimos Jugador como variable global, para usarla en todas las funciones

enum Efecto{
    Ninguno, Electrificado, Incendiado, Congelado //Ninguno = 0, Electrificado = 1, Incendiado = 2, Congelado = 3;
};

int seleccionPersonaje(){

    int seleccion, p, s;

        for(p=0;p<16;p++){

            printf("\nPersonaje %d, tipo: ",p);
            printf("\n(1) Mototaxista \n(2) Politico corrupto \n(3) Medico cubano \n(4) Profesor \n(0) Para salir\n\nOpcion: ");
            scanf("%d", &seleccion);

            if(p==15) printf("\nUltimo personaje (maximo: 16 jugadores)\n");

            if(seleccion == 0){
                if(p == 0) {
                    printf("\nDeben haber 4 jugadores como minimo\n");
                    p--;
                }
                else if(p<4){
                    printf("\nNecesitas %d personajes mas\n", 4-p);
                    p--;
                }
                else break;
            }

            else if(seleccion == 1){
                fflush(stdin);
                Jugador[p] = newMototaxista();
                printf("\nNombre de tu mototaxista: ");
                gets(Jugador[p]->nombre);
            }
            else if(seleccion == 2){
                fflush(stdin);
                Jugador[p] = newPolitiCorrupto();
                printf("\nNombre politico corrupto: ");
                gets(Jugador[p]->nombre);
            }
            else if(seleccion == 3){
                fflush(stdin);
                Jugador[p] = newMedicoCubano();
                printf("\nNombre medico cubano: ");
                gets(Jugador[p]->nombre);
            }
            else if(seleccion == 4){
                fflush(stdin);
                Jugador[p] = newProfesor();
                printf("\nNombre profesor: ");
                gets(Jugador[p]->nombre);
            }
            else{
                printf("\nSelecciona una opcion correcta");
                p--;
            }
        }
        for(int i = 0; i<p; i++){
            printf("\nPersonaje %d: ",i);
            puts(Jugador[i]->nombre);
            printf("Salud %d, ", Jugador[i]->ptSalud);
            printf("energia %d, ", Jugador[i]->ptEnergia);
            printf("accion %d, ", Jugador[i]->ptAccion);
            printf("dano %d, ", Jugador[i]->dano);
            printf("rango %d, ", Jugador[i]->rango);
            printf("armadura %d \n", Jugador[i]->armadura);
        }
    return p;
}

typedef struct ter{
    Personaje Jugador[16];
    enum Efecto efecto;
    // items Lista (Item);
} Ter;

typedef Ter* terreno; //terreno apunta a Ter

terreno espacios[10][20];

void terrenoPelea(int x){

    espacios [1][1] = Jugador[1]->nombre;

    printf("%c", espacios[1][1]);

}

int main(){
    seleccionPersonaje();
    terrenoPelea(10);
    return 0;
}
