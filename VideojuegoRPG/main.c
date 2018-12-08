#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.h"

typedef struct nodoL{
    int val;
    struct nodo *sig;
} NodoL;

typedef NodoL * Lista;

Lista newList(){
    return NULL;
}

typedef struct perso {
    char nombre[16] ;//1
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

} Perso;

typedef Perso* Personaje;

Personaje newMototaxista(n[16],q){//q es el numero de jugador
    Personaje g=malloc(sizeof(Perso));
    g->nombre=nombre;
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    g->jugador=q;
    g->dano=10;
    g->rango=1;
    g->armadura=40;
}
Personaje newPolitiCorrupto(n[16],q){//q es el numero de jugador
    Personaje g=malloc(sizeof(Perso));
    g->nombre=nombre;
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    g->jugador=q;
}
Personaje newMedicoCubano(n[16],q){//q es el numero de jugador
    Personaje g=malloc(sizeof(Perso));
    g->nombre=nombre;
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    g->jugador=q;
}

Personaje newProfesor(n[16],q){//q es el numero de jugador
    Personaje g=malloc(sizeof(Perso));
    g->nombre=nombre;
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    g->jugador=q;
}

typedef struct terreno{
    personaje Personaje*;
    efecto Efecto (enum);
    items Lista (Item);
} Terreno[10][20];

int main()
{
    for(int i = 0; i<20;i++){
        for(int j = 0; j<10;j++) printf("%d",ter[j][i]);
    }
    printf("Hello world\n");
    return 0;
}
