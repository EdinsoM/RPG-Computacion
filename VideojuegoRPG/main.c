#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.h"
#include <math.h>

/*typedef struct nodo{
    int val;
    struct nodo *sig;
} Nodo;

typedef Nodo* Lista;

Lista newList(){
    return NULL;
}
*/

typedef struct perso { ///Creamos la estructura del personaje
    char nombre[16];
    int ptSalud;
    int ptEnergia;
    Pila* inventario;
//  Lista* habilidades;
    int dano;
    int rango;
    int armadura;
    int evasion;
    int velocidad;
    int ptAccion;
    int posX, posY;
}Perso;

typedef Perso* Personaje;

Personaje newMototaxista(){
    Personaje g = malloc(sizeof(Perso));
    g->nombre[16];
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    g->dano=25;
    g->rango=1;
    g->armadura=40;
    g->evasion=25;
    g->velocidad=2;
    g->posX;
    g->posY;
    g->inventario=newPila();
//  g->habilidades=newList();
    return g;
}
Personaje newPolitiCorrupto(){
    Personaje g = malloc(sizeof(Perso));
    g->nombre[16];
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    g->dano=20;
    g->rango=2;
    g->armadura=0;
    g->evasion=10;
    g->velocidad=4;
    g->posX;
    g->posY;
    g->inventario=newPila();
//    g->habilidades=newList();
    return g;
}
Personaje newMedicoCubano(){
    Personaje g = malloc(sizeof(Perso));
    g->nombre[16];
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    g->dano=15;
    g->rango=1;
    g->armadura=0;
    g->evasion=10;
    g->velocidad=1;
    g->posX;
    g->posY;
    g->inventario=newPila();
//    g->habilidades=newList();
    return g;
}
Personaje newProfesor(){
    Personaje g = malloc(sizeof(Perso));
    g->nombre[16];
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    g->dano=15;
    g->rango=4;
    g->armadura=10;
    g->evasion=20;
    g->velocidad=3;
    g->posX;
    g->posY;
    g->inventario=newPila();
//    g->habilidades=newList();
    return g;
}

Personaje Jugador[2][8]; ///Definimos Jugador como variable global, para usarla en todas las funciones

typedef struct nodoP{
    Personaje Jug;
    struct nodoP* sig;
} NodoP;

typedef NodoP* ListaP;

ListaP newListaP(){
    return NULL;
}

void insertaPersonaje(Personaje J, ListaP *L){
    NodoP *q = malloc(sizeof(NodoP));
    q->Jug = J;
    q->sig = *L;
    *L = q;
}

void escribeLista(ListaP L){
    printf("[");
    while(L->sig!=NULL){
        printf("%c, ", L->Jug->nombre[0]);
        //puts(L->Jug->nombre);
        L = L->sig;
    }
    printf("%c", L->Jug->nombre[0]);
    printf("]");
}

/*
void swap(int *a,int *b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void selectSort(ListaP *L){
    NodoP *p=L,*q,*pm;
    if(p!=NULL){
        while(p->sig!=NULL){
            q=p->sig;pm=p;
            while(q!=NULL){
                if(q->Jugador->velocidad > pm->Jugador->velocidad) pm=q;
                q=q->sig;
            }
            if(pm!=p)swap(&(p->Jugador),&(pm->Jugador));
            p=p->sig;
        }
    }
}

void ordenarTurnos(ListaP *L1, ListaP *L2){     //x es Numero de jugadores
    selectSort(&L1);
    selectSort(&L2);
}

NodoP turno(ListaP *L1, ListaP *L2, nodoP *p, nodoP *q){
    if (p=!NULL) p=p->sig;
    else{
        if (q->sig!=NULL) q=q->sig;
        else {
            p=L1;
            q=L2;
        }
    }
    if (p=!NULL) return p;
    else return q;
}
*/
typedef struct ter{
    Personaje Jugador;
    //enum Efecto efecto;
    //items Lista (Item);
} Ter;

typedef Ter* terreno; //terreno apunta a Ter

terreno newTerreno(){
    terreno t = malloc(sizeof(Ter));
    t->Jugador = NULL;
    // t->efecto = NULL;
    // t->item = NULL;
    return t;
}

terreno espacios[10][20];

enum Efecto{
    Ninguno, Electrificado, Incendiado, Congelado //Ninguno = 0, Electrificado = 1, Incendiado = 2, Congelado = 3;
};

void seleccionPersonaje(int x){
    int seleccion, s, p;

        for(int j=0;j<2;j++){

            for(p=0;p<x;p++){

                printf("\nJugador %d, personaje %d, tipo: ",j, p);
                printf("\n(1) Mototaxista \n(2) Politico corrupto \n(3) Medico cubano \n(4) Profesor \n(0) Para salir\n\nOpcion: ");
                scanf("%d", &seleccion);

                if(p==x-1) printf("\nUltimo personaje (maximo: %d personajes)\n",x);

                if(seleccion == 0){
                    if(p == 0) {
                        printf("\nDeben haber %d personajes como minimo\n",x);
                        p--;
                    }
                    else if(p<x){
                        printf("\nNecesitas %d personajes mas\n",x-p);
                        p--;
                    }
                    else break;
                }

                else if(seleccion == 1){
                    fflush(stdin);
                    Jugador[j][p] = newMototaxista();
                    printf("\nNombre de tu mototaxista: ");
                    gets(Jugador[j][p]->nombre);
                    if(j==0) {
                        espacios[p][0]->Jugador = Jugador[j][p];
                        Jugador[j][p]->posX = 0;
                        Jugador[j][p]->posY = p;
                    }
                    if(j==1) {
                        espacios[p][19]->Jugador = Jugador[j][p];
                        Jugador[j][p]->posX = 19;
                        Jugador[j][p]->posY = p;
                    }
                }
                else if(seleccion == 2){
                    fflush(stdin);
                    Jugador[j][p] = newPolitiCorrupto();
                    printf("\nNombre politico corrupto: ");
                    gets(Jugador[j][p]->nombre);
                    if(j==0) {
                        espacios[p][0]->Jugador = Jugador[j][p];
                        Jugador[j][p]->posX = 0;
                        Jugador[j][p]->posY = p;
                    }
                    if(j==1) {
                        espacios[p][19]->Jugador = Jugador[j][p];
                        Jugador[j][p]->posX = 19;
                        Jugador[j][p]->posY = p;
                    }
                }
                else if(seleccion == 3){
                    fflush(stdin);
                    Jugador[j][p] = newMedicoCubano();
                    printf("\nNombre medico cubano: ");
                    gets(Jugador[j][p]->nombre);
                    if(j==0) {
                        espacios[p][0]->Jugador = Jugador[j][p];
                        Jugador[j][p]->posX = 0;
                        Jugador[j][p]->posY = p;
                    }
                    if(j==1) {
                        espacios[p][19]->Jugador = Jugador[j][p];
                        Jugador[j][p]->posX = 19;
                        Jugador[j][p]->posY = p;
                    }

                }
                else if(seleccion == 4){
                    fflush(stdin);
                    Jugador[j][p] = newProfesor();
                    printf("\nNombre profesor: ");
                    gets(Jugador[j][p]->nombre);
                    if(j==0) {
                        espacios[p][0]->Jugador = Jugador[j][p];
                        Jugador[j][p]->posX = 0;
                        Jugador[j][p]->posY = p;
                    }
                    if(j==1) {
                        espacios[p][19]->Jugador = Jugador[j][p];
                        Jugador[j][p]->posX = 19;
                        Jugador[j][p]->posY = p;
                    }
                }
                else{
                    printf("\nSelecciona una opcion correcta");
                    p--;
                }
            }
        }
        for(int j=0;j<2;j++){
            printf("\n\tJugador %d: \n",j);
            for(int i = 0; i<p; i++){
                printf("\nPersonaje %d: ",i);
                puts(Jugador[j][i]->nombre);
                printf("Salud %d, ", Jugador[j][i]->ptSalud);
                printf("energia %d, ", Jugador[j][i]->ptEnergia);
                printf("accion %d, ", Jugador[j][i]->ptAccion);
                printf("dano %d, ", Jugador[j][i]->dano);
                printf("rango %d, ", Jugador[j][i]->rango);
                printf("armadura %d, ",Jugador[j][i]->armadura);
                printf("evasion %d, ",Jugador[j][i]->evasion);
                printf("velocidad %d \n",Jugador[j][i]->velocidad);
            }
        }
}

void terrenoPelea(){
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            espacios[i][j] = newTerreno();
        }
    }
}

void imprimeTerreno(){
    printf("\n   ");
    for(int a=0;a<20;a++){
        if(a<10) printf("|%d|",a);
        else printf("%d|",a);
    }
    for(int i=0;i<10;i++){ ///espacios[y][x]
        printf("\n|%d|",i);
        for(int j=0;j<20;j++){
            if(espacios[i][j]->Jugador == NULL) printf("[N]");
            else printf("[%s]", espacios[i][j]->Jugador->nombre);///Hay un problema, quiero colocar espacios[i][j]->Jugador->nombre[0] para imprimir solo las siglas, pero me da error la consola.
        }
    }printf("\n");
}

void movimientoPersonaje(terreno E, Personaje J, int x, int y){
    espacios[y][x]->Jugador = J;
    E->Jugador = NULL;
}

int inicio(){
    int cantidad;
    printf("\n\nCon cuantos personajes vas a jugar? Minimo 4, maximo 8 por jugador: ");
    scanf("%d", &cantidad);
    if(cantidad>=4 && cantidad<=8) seleccionPersonaje(cantidad);
    else inicio();
    return cantidad;
}

void turno(ListaP La, ListaP Lb){

    NodoP *t0 = malloc(sizeof(NodoP));
    NodoP *t1 = malloc(sizeof(NodoP));

    t0 = La; /// t0 y t1 son apuntadores a las listas creadas anteriormente, se van a ir desplazando a lo largo de las listas, apuntando a los personajes
    t1 = Lb; /// que les jugar

    int seguir0 = 1, seguir1 = 1;

    ///Hice 3 while, el primero que es infinito (cuya condicion hay que cambiar) permite la asignación de los turnos y de los puntos a cada personaje
    ///en la medida que les toque jugar.

    ///Los otros 2 se utilizan a modo de recursion, si el personaje de turno decide no jugar más, ya sea por ceder el turno o porque no tiene puntos
    ///de accion, entonces selecciona la opcion 0, cierra el ciclo y se abre siguiente ciclo, que corresponde al del jugador 2, una vez este cede el turno
    ///el while infinito permite volver al ciclo del jugador 1, y asi vamos

    while(1){
        t0->Jug->ptAccion = t0->Jug->ptAccion+5; ///Aqui se suman los 5 puntos al personaje del jugador 1

        while(seguir0){ ///Empieza a jugar el personaje del jugador 1
            int x, y, h, calculaPuntos, aceptar;
            printf("\nJugador 0: Juega el personaje %s\n", t0->Jug->nombre);
            printf("\n%s, tienes %d puntos de accion\n", t0->Jug->nombre ,t0->Jug->ptAccion);
            printf("\nQue quieres hacer?\n\n1.Moverte\n2.Usar un item\n3.Atacar\n4.Usar una habilidad\n");
            printf("\nOpcion: ");
            scanf("%d",&h);
            if(h == 1){
                printf("A donde te quieres mover?:"); printf(" X = "); scanf("%d",&x); printf("Y = "); scanf("%d",&y);
                calculaPuntos = (abs(t0->Jug->posX-x) + abs(t0->Jug->posY-y));

                ///En la estructura de personaje agregué 2 parámetros: posX y posY, permiten ver la posicion del personaje dentro del tablero
                ///sin la necesidad de saber cual estructura espacios[i][j] lo está apuntando

                printf("Necesitas %d puntos para moverte, aceptar (1), rechazar (0): ", calculaPuntos);
                scanf("%d", &aceptar);

                if(aceptar == 1 && t0->Jug->ptAccion>=calculaPuntos){
                    t0->Jug->ptAccion = t0->Jug->ptAccion-calculaPuntos; ///Restamos los puntos de accion
                    movimientoPersonaje(espacios[t0->Jug->posY][t0->Jug->posX], t0->Jug, x, y);///Mandamos la casilla que apunta al jugador, mandamos al jugador y mandamos las coordenadas a las que se quiera mover.
                    imprimeTerreno();
                    t0->Jug->posX = x; ///Actualizamos la coordenada x del personaje de turno
                    t0->Jug->posY = y; ///Actualizamos la coordenada y del personaje de turno
                    printf("\n%s, tienes %d puntos de accion, que deseas hacer?\n", t0->Jug->nombre ,t0->Jug->ptAccion);
                    printf("\nElegir otra opcion (1), ceder el turno (0): ");
                    scanf("%d", &seguir0);
                }
                else if(aceptar == 1 && t0->Jug->ptAccion<calculaPuntos){
                    printf("No te alcanzan los puntos de accion, que deseas hacer?");
                    printf("\nElegir otra opcion (1), ceder el turno (0): ");
                    scanf("%d", &seguir0);
                }
            }
        }
        ///Si salimos del ciclo, el apuntador t0 que se desplaza por la lista ahora va a apuntar al siguiente personaje, que será seleccionado cuando retornemos
        ///al primer while
        t0 = t0->sig;
        if(t0 == NULL) t0 = La;

        ///Ahora entramos al segundo while, empiezan a jugar los personajes del jugador 2

        t1->Jug->ptAccion = t1->Jug->ptAccion+5; ///Se suman 5 puntos de accion para el personaje del jugador 2

        while(seguir1){
            int x, y, h, calculaPuntos, aceptar;
            printf("\nJugador 1: Juega el personaje %s\n", t1->Jug->nombre);
            printf("\n%s, tienes %d puntos de accion\n", t1->Jug->nombre, t1->Jug->ptAccion);
            printf("\nQue quieres hacer?\n\n1.Moverte\n2.Usar un item\n3.Atacar\n4.Usar una habilidad\n");
            printf("\nOpcion: ");
            scanf("%d",&h);
            if(h == 1){
                printf("A donde te quieres mover?:"); printf(" X = "); scanf("%d",&x); printf("Y = "); scanf("%d",&y);
                calculaPuntos = (abs(t1->Jug->posX-x) + abs(t1->Jug->posY-y));
                printf("Necesitas %d puntos para moverte, aceptar (1), rechazar (0): ", calculaPuntos);
                scanf("%d", &aceptar);

                if(aceptar == 1 && t1->Jug->ptAccion>=calculaPuntos){
                    t1->Jug->ptAccion = t1->Jug->ptAccion-calculaPuntos;
                    movimientoPersonaje(espacios[t1->Jug->posY][t1->Jug->posX], t1->Jug, x, y);
                    imprimeTerreno();
                    t1->Jug->posX = x;
                    t1->Jug->posY = y;
                    printf("\n%s, tienes %d puntos de accion, que deseas hacer?\n", t1->Jug->nombre ,t1->Jug->ptAccion);
                    printf("\nElegir otra opcion (1), ceder el turno (0): ");
                    scanf("%d", &seguir1);
                }
                else if(aceptar == 1 && t1->Jug->ptAccion<calculaPuntos){
                    printf("No te alcanzan los puntos de accion, que deseas hacer?");
                    printf("\nElegir otra opcion (1), ceder el turno (0): ");
                    scanf("%d", &seguir1);
                }
            }
        }
        t1 = t1->sig;
        if(t1 == NULL) t1 = Lb;
    }
}
void main(){

    printf("Bienvenido a la batalla de gallos.");
    int a;
    terrenoPelea();
    a = inicio();

    ListaP L0 = newListaP();
    for(int i=0;i<a;i++){
        insertaPersonaje(Jugador[0][i], &L0); ///Insertamos los personajes del primer jugador en una lista
    }

    ListaP L1 = newListaP();
    for(int i=0;i<a;i++){
        insertaPersonaje(Jugador[1][i], &L1); ///Insertamos los personajes del segundo jugador en otra lista
    }

    printf("\nIniciales de los personajes del jugador 0: "); escribeLista(L0); ///Esta función presenta errores al momento de imprimir,
    printf("\nIniciales de los personajes del jugador 1: "); escribeLista(L1); ///es posible que haya que hacer una limpieza de buffer.
    printf("\n");

    imprimeTerreno();
    turno(L0,L1);///Enviamos ambas listas para empezar a asignar los turnos a cada jugador

    /*
    Jugador[1][1] = newPrueba();
    espacios[0][0]->Jugador = Jugador[1][1];

    imprimeTerreno();

    int x,y,s;
    while(s != 1){
        printf("Casilla a moverte: ");
        scanf("%d",&x);
        scanf("%d",&y);
        movimientoPersonaje(espacios[0][0], Jugador[1][1], x, y);
        imprimeTerreno();
        printf("1 para siguiente turno, 0 para seguir: ");
        scanf("%d",&s);
    }
    imprimeTerreno();
    */
}
