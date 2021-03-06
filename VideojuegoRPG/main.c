#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.h"
#include <math.h>
#include <windows.h>
#include <mmsystem.h>

#define Normal 176
#define Cualquiera 178

Item newpociondesalud(){
    Item i=malloc(sizeof(It));
    i->nombre="Atamel";
    i->costo=3;
    i->rango=0;
    /// i->efecto=Aguinaldo;
    return i;
}
Item newpociondeEnergia(){
    Item i=malloc(sizeof(It));
    i->nombre="Cafe";
    i->costo=3;
    i->rango=0;
    /// i->efecto=Incendiar;
    return i;
}
Item newgranadaanuladora(){
    Item i=malloc(sizeof(It));
    i->nombre="granada_hora_del_burro";
    i->costo=5;
    i->rango=5;
    /// i->efecto=VisaNegada;
    return i;
}

typedef struct ha{
    char *nombre ;
    int costoEnergia;
    int costoAccion;
    int rango;
    /// void (*efecto)(int,int);
}HA;

typedef HA* Habilidad;

Habilidad newRestaurar(){
    Habilidad j=malloc(sizeof(HA));
    j->nombre="Ramazos";
    j->costoEnergia=5;
    j->costoAccion=4;
    j->rango=2;
    ///j->efecto=Aguinaldo;
    return j;
}
Habilidad newIncendiar(){
    Habilidad j=malloc(sizeof(HA));
    j->nombre="PrenderCandela";
    j->costoEnergia=2;
    j->costoAccion=7;
    j->rango=3;
    /// j->efecto=Incendiar;
    return j;
}
Habilidad newCongelar(){
    Habilidad j=malloc(sizeof(HA));
    j->nombre="PegarPacheco";
    j->costoEnergia=4;
    j->costoAccion=4;
    j->rango=3;
    /// j->efecto=VisaNegada;
    return j;
}
Habilidad newElectrocutar(){
    Habilidad j=malloc(sizeof(HA));
    j->nombre = "Corrientazo";
    j->costoEnergia=10;
    j->costoAccion=5;
    j->rango=4;
    /// j->efecto=Corrientazo;
    return j;
}

typedef struct nodeha{
    Habilidad h;
    struct nodeha* sig;
}NodoHA;

typedef NodoHA * Listaha;

Listaha newListaha(){
    //Listaha L = malloc(sizeof(NodoHA));
    //L->h = NULL;
    //L->sig = NULL;
    return NULL;
}

void agregar(Habilidad x, Listaha *L){
    NodoHA *p = malloc(sizeof(NodoHA));
    p->h = x;
    p->sig = *L;
    *L = p;
}

void escribeListaH(Listaha L){
    int k = 1;
    if(L != NULL){
        while (L->sig != NULL){
            printf("%d.- %s\n", k,(L->h)->nombre);
            //puts(L->(h*nombre));
            L = L->sig;
            k++;
        }
        printf("%d.- %s\n", k,(L->h)->nombre);
    }
}

typedef struct perso { ///Creamos la estructura del personaje
    char nombre[16];
    int ptSalud;
    int ptEnergia;
    Pila inventario;
    Listaha habilidad;
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
    g->nombre[16] = "\0";
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=10;
    g->dano=25;
    g->rango=1;
    g->armadura=40;
    g->evasion=25;
    g->velocidad=2;
    g->posX = 0;
    g->posY = 0;
    g->inventario = NULL;
    g->habilidad = NULL;
    return g;
}
Personaje newPolitiCorrupto(){
    Personaje g = malloc(sizeof(Perso));
    g->nombre[16] = "\0";
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=10;
    g->dano=20;
    g->rango=2;
    g->armadura=0;
    g->evasion=10;
    g->velocidad=4;
    g->posX = 0;
    g->posY = 0;
    g->inventario = NULL;
    g->habilidad = NULL;
    return g;
}
Personaje newMedicoCubano(){
    Personaje g = malloc(sizeof(Perso));
    g->nombre[16] = "\0";
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=10;
    g->dano=15;
    g->rango=1;
    g->armadura=0;
    g->evasion=10;
    g->velocidad=1;
    g->posX = 0;
    g->posY = 0;
    g->inventario = NULL;
    g->habilidad = NULL;
    return g;
}
Personaje newProfesor(){
    Personaje g = malloc(sizeof(Perso));
    g->nombre[16] = "\0";
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=10;
    g->dano=15;
    g->rango=4;
    g->armadura=10;
    g->evasion=20;
    g->velocidad=3;
    g->posX = 0;
    g->posY = 0;
    g->inventario = NULL;
    g->habilidad = NULL;
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

enum Efecto{
    Ninguno, Electrificado, Incendiado, Congelado //Ninguno = 0, Electrificado = 1, Incendiado = 2, Congelado = 3;
};

void insertaPersonaje(Personaje J, ListaP *L){
    NodoP *q = malloc(sizeof(NodoP));
    q->Jug = J;
    q->sig = *L;
    *L = q;
}

void escribeListaP(ListaP L){
    printf("[");
    while(L->sig!=NULL){
        printf("%c, ", L->Jug->nombre[0]);
        //puts(L->Jug->nombre);
        L = L->sig;
    }
    printf("%c", L->Jug->nombre[0]);
    printf("]");
}

typedef struct ter{
    Personaje Jugador;
    enum Efecto efecto;
    Lista item;
} Ter;

typedef Ter* terreno; //terreno apunta a Ter

terreno newTerreno(){
    terreno t = malloc(sizeof(Ter));
    t->Jugador = NULL;
    t->efecto = Ninguno;
    t->item = newList();
    return t;
}

terreno espacios[10][20];

void usarItem(Item i, int x, int y){

    if(strcmp(i->nombre,"Atamel") == 0){
        espacios[y][x]->Jugador->ptSalud = (espacios[y][x]->Jugador->ptSalud)+30;//un tercio del maximo
        printf("\nLe diste un Atamel a %s\n", espacios[y][x]->Jugador->nombre);
        PlaySound(TEXT("Atamel.wav"),NULL,SND_SYNC);
    }
    if(strcmp(i->nombre,"Cafe") == 0){
         espacios[y][x]->Jugador->ptEnergia = (espacios[y][x]->Jugador->ptEnergia)+10;
         printf("\nLe diste un marron claro a %s y agarro energia\n", espacios[y][x]->Jugador->nombre);
         PlaySound(TEXT("Energia.wav"),NULL,SND_SYNC);
    }
    if(strcmp(i->nombre,"granada_hora_del_burro") == 0){
        for(int j=x-1;j<x+2;j++){
             for(int k=y-1;k<y+2;k++){
                if(j<=0) j = 0; if(j>=19) j = 19; if(k<=0) k = 0; if (k>=10) k = 10;
                espacios[k][j]->efecto = Ninguno;
            }
        }
        printf("\nBorron y cuenta nueva, chamit@\n");
        PlaySound(TEXT("Granada.wav"),NULL,SND_SYNC);
    }
}

void usarHabilidad(Listaha L, int x, int y, int posX, int posY, int distancia, int ptAccion, int ptEnergia, int k){
    int f = k;
    NodoHA *p = L;

    while(f!=1){
        p=p->sig;
        f--;
    }

    if(p->h->rango >= distancia && ptAccion >= p->h->costoAccion && ptEnergia >= p->h->costoEnergia && (x != posX || y != posY)){

        espacios[posY][posX]->Jugador->ptEnergia=ptEnergia-(p->h->costoEnergia);
        espacios[posY][posX]->Jugador->ptAccion=ptAccion-(p->h->costoAccion);

        if(strcmp(p->h->nombre,"Ramazos")==0){
            espacios[y][x]->Jugador->ptSalud = (espacios[y][x]->Jugador->ptSalud)+30;//un tercio del maximo
            printf("\nLe echaste unos ramazos a %s y se ha curado 30 puntos de vida \nAhora tiene %d puntos de vida\n",espacios[y][x]->Jugador->nombre,espacios[y][x]->Jugador->ptSalud);
            PlaySound(TEXT("Ramazos.wav"),NULL,SND_SYNC);
        }
        if(strcmp(p->h->nombre,"PrenderCandela")==0){
            printf("Prendiste en candela %s y le quitaste %d puntos de vida\n",espacios[y][x]->Jugador->nombre,((espacios[y][x]->Jugador->ptSalud)/3));
            PlaySound(TEXT("Fuego.wav"),NULL,SND_SYNC);
            espacios[y][x]->Jugador->ptSalud = (espacios[y][x]->Jugador->ptSalud)-((espacios[y][x]->Jugador->ptSalud)/3);
            espacios[y][x]->efecto = Incendiado;//Casilla incendiada
            printf("\nAhora tiene %d puntos de vida",espacios[y][x]->Jugador->ptSalud);
        }
        if(strcmp(p->h->nombre,"PegarPacheco")==0){
            espacios[y][x]->Jugador->ptAccion = 0;
            espacios[y][x]->efecto = Congelado;//Casilla Congelada
            printf("\nLe robaste el sueter a %s y ahora se esta muriendo de frio\n",espacios[y][x]->Jugador->nombre);
            PlaySound(TEXT("PegarPacheco.wav"),NULL,SND_SYNC);
        }
        if(strcmp(p->h->nombre,"Corrientazo")==0){
            espacios[y][x]->Jugador->ptEnergia = (espacios[y][x]->Jugador->ptEnergia)/2;
            espacios[y][x]->efecto = Electrificado;//Casilla Electrificada
            printf("\nHiciste que %s pegara los dedos en un enchufe\n",espacios[y][x]->Jugador->nombre);
            PlaySound(TEXT("Corrientazo.wav"),NULL,SND_SYNC);
        }
    }
    else{
        if(p->h->rango < distancia) {
            printf("\nEl objetivo esta fuera de rango\n");
            PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
        }
        else if(ptAccion < p->h->costoAccion) {
            printf("\nNo posees suficientes puntos de accion\n");
            PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
        }
        else if(ptEnergia < p->h->costoEnergia) {
            printf("\nNo posees suficientes puntos de energia\n");
            PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
        }
        if(x == posX && y == posY){
            printf("\nNada vivo tu, chamo\n");
            PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
        }
    }
}

void atacar(int x, int y, int dano, int armadura, int evasion, int vida){
    if(rand()%51 > evasion ){
        int k;
        k=vida-(dano*(100-armadura))/100;
        printf("\nHas hecho %d dano al personaje %s\n", (dano*(100-armadura))/100, espacios[y][x]->Jugador->nombre);
        espacios[y][x]->Jugador->ptSalud=k;
        if(espacios[y][x]->Jugador->ptSalud == 0) printf("\nA %s le queda 0 puntos de vida\n",espacios[y][x]->Jugador->nombre,espacios[y][x]->Jugador->ptSalud);
        else printf("\nA %s le queda %d puntos de vida\n",espacios[y][x]->Jugador->nombre,espacios[y][x]->Jugador->ptSalud);
    }
    else printf("\nEl ataque ha sido esquivado\n");
}

void Yriarte(int a){

    int partidaNueva;

    printf("\nElegiste al personaje oculto: Yriarte");
    printf("\nYriarte clavo a todos personajes del equipo contrario");
    printf("\nGana el equipo del jugador %d", a);
    PlaySound(TEXT("Yriarte.wav"),NULL,SND_SYNC);
    printf("\n\nQuieren jugar de nuevo? Si (1), no (0): ");
    scanf("%d", &partidaNueva);
    if(partidaNueva) main();
    else printf("\nAdios!!!");
}

void swap(Personaje *a,Personaje *b){
    Personaje temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void selectSort(ListaP *L){
    NodoP *p=*L,*q,*pm;
    if(p!=NULL){
        while(p->sig!=NULL){
            q=p->sig;pm=p;
            while(q!=NULL){
                if(q->Jug->velocidad >= pm->Jug->velocidad) pm=q;
                q=q->sig;
            }
            if(pm!=p)swap(&(p->Jug),&(pm->Jug));
            p=p->sig;
        }
    }
}

void ordenarTurnos(ListaP *L0, ListaP *L1){
    selectSort(L0);
    selectSort(L1);
}

int estaEn(char a[], int n, char *x){
    int k = 0;
    while(k<n && a[k] != *x){
        k++;
    }
    return k<n;
}

void seleccionPersonaje(int x, Listaha h, Pila i){

    char iniciales[16];

    int seleccion, s, p, inicialesIguales;

        for(int j=0;j<2;j++){

            for(p=0;p<x;p++){

                printf("\nJugador %d, personaje %d, tipo: ",j, p);
                printf("\n(1) Mototaxista \n(2) Politico corrupto \n(3) Medico cubano \n(4) Profesor \n(0) Salir\n\nOpcion: ");
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
                    inicialesIguales = 1;
                    while(inicialesIguales){
                        printf("\nNombre de tu mototaxista: ");
                        gets(Jugador[j][p]->nombre);

                        if(j==0) iniciales[j+p] = Jugador[j][p]->nombre[0];
                        if(j==1) iniciales[j+p+x] = Jugador[j][p]->nombre[0];

                        if(j==0){
                            if(estaEn(iniciales, j+p, &Jugador[j][p]->nombre[0])){
                                printf("\nElige otro nombre\n");
                                inicialesIguales = 1;
                            }
                            else{
                                Jugador[j][p]->habilidad = h;
                                Jugador[j][p]->inventario = i;
                                inicialesIguales=0;
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
                        }
                        else if(j==1){
                            if(estaEn(iniciales, j+p+x, &Jugador[j][p]->nombre[0])){
                                printf("\nElige otro nombre\n");
                                inicialesIguales = 1;
                            }
                            else{
                                Jugador[j][p]->habilidad = h;
                                Jugador[j][p]->inventario = i;
                                inicialesIguales=0;
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
                        }
                    }
                }
                else if(seleccion == 2){
                    fflush(stdin);
                    Jugador[j][p] = newPolitiCorrupto();
                    inicialesIguales = 1;
                    while(inicialesIguales){
                        printf("\nNombre de tu politico corrupto: ");
                        gets(Jugador[j][p]->nombre);

                        if(j==0) iniciales[j+p] = Jugador[j][p]->nombre[0];
                        if(j==1) iniciales[j+p+x] = Jugador[j][p]->nombre[0];

                        if(j==0){
                            if(estaEn(iniciales, j+p, &Jugador[j][p]->nombre[0])){
                                printf("\nElige otro nombre\n");
                                inicialesIguales = 1;
                            }
                            else{
                                Jugador[j][p]->habilidad = h;
                                Jugador[j][p]->inventario = i;
                                inicialesIguales=0;
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
                        }
                        else if(j==1){
                            if(estaEn(iniciales, j+p+x, &Jugador[j][p]->nombre[0])){
                                printf("\nElige otro nombre\n");
                                inicialesIguales = 1;
                            }
                            else{
                                Jugador[j][p]->habilidad = h;
                                Jugador[j][p]->inventario = i;
                                inicialesIguales=0;
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
                        }
                    }
                }
                else if(seleccion == 3){
                    fflush(stdin);
                    Jugador[j][p] = newMedicoCubano();
                    inicialesIguales = 1;
                    while(inicialesIguales){
                        printf("\nNombre de tu medico cubano: ");
                        gets(Jugador[j][p]->nombre);

                        if(j==0) iniciales[j+p] = Jugador[j][p]->nombre[0];
                        if(j==1) iniciales[j+p+x] = Jugador[j][p]->nombre[0];

                        if(j==0){
                            if(estaEn(iniciales, j+p, &Jugador[j][p]->nombre[0])){
                                printf("\nElige otro nombre\n");
                                inicialesIguales = 1;
                            }
                            else{
                                Jugador[j][p]->habilidad = h;
                                Jugador[j][p]->inventario = i;
                                inicialesIguales=0;
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
                        }
                        else if(j==1){
                            if(estaEn(iniciales, j+p+x, &Jugador[j][p]->nombre[0])){
                                printf("\nElige otro nombre\n");
                                inicialesIguales = 1;
                            }
                            else{
                                Jugador[j][p]->habilidad = h;
                                Jugador[j][p]->inventario = i;
                                inicialesIguales=0;
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
                        }
                    }
                }
                else if(seleccion == 4){
                    fflush(stdin);
                    Jugador[j][p] = newProfesor();
                    inicialesIguales = 1;
                    while(inicialesIguales){
                        printf("\nNombre de tu profesor: ");
                        gets(Jugador[j][p]->nombre);

                        if(j==0) iniciales[j+p] = Jugador[j][p]->nombre[0];
                        if(j==1) iniciales[j+p+x] = Jugador[j][p]->nombre[0];

                        if(j==0){
                            if(estaEn(iniciales, j+p, &Jugador[j][p]->nombre[0])){
                                printf("\nElige otro nombre\n");
                                inicialesIguales = 1;
                            }
                            else{
                                Jugador[j][p]->habilidad = h;
                                Jugador[j][p]->inventario = i;
                                inicialesIguales=0;
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
                        }
                        else if(j==1){
                            if(estaEn(iniciales, j+p+x, &Jugador[j][p]->nombre[0])){
                                printf("\nElige otro nombre\n");
                                inicialesIguales = 1;
                            }
                            else{
                                Jugador[j][p]->habilidad = h;
                                Jugador[j][p]->inventario = i;
                                inicialesIguales=0;
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
                        }
                    }
                }
                else if(seleccion == 5){
                    Yriarte(j);
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
                printf("\nrango %d, ", Jugador[j][i]->rango);
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
    printf("\n\t\t\t  ");
    for(int a=0;a<20;a++){
        printf("%c",a+65);
    }
    for(int i=0;i<10;i++){ ///espacios[y][x]
        printf("\n\t\t\t%d ",i);
        for(int j=0;j<20;j++){
            if(espacios[i][j]->Jugador == NULL && espacios[i][j]->item == NULL && espacios[i][j]->efecto == Ninguno) printf("%c", Normal); ///Falta verificar las casillas para efectos e items
            else if(espacios[i][j]->Jugador != NULL) printf("%c", espacios[i][j]->Jugador->nombre[0]);
            else if(espacios[i][j]->item != NULL) printf("*");
            else if(espacios[i][j]->efecto != Ninguno) printf("%c", Cualquiera);
        }
    }printf("\n");
}

void movimientoPersonaje(terreno E, Personaje J, int x, int y){
    //if(espacios[y][x]->Jugador == NULL){
    espacios[y][x]->Jugador = J;
    E->Jugador = NULL;
    //}
    //else printf("\nHay alguien en esta casilla\n");
}

int calculaPuntos(int PosJugx, int x, int PosJugy, int y){ ///Tambien sirve para calcular distancias
    if(abs(PosJugx-x) > abs(PosJugy-y)) return abs(PosJugx-x);
    else return abs(PosJugy-y);
}

int inicio(Listaha h, Pila i){
    int cantidad;
    printf("\n\nCon cuantos personajes vas a jugar? Minimo 2, maximo 8 por jugador: ");
    scanf("%d", &cantidad);
    if(cantidad>=2 && cantidad<=8){
        printf("\nCuentas con los siguientes personajes: \n");
        printf("\nEl mototaxista: un jinete oriundo de Catia o Petare, \ncapaz de arrebatar tus pertenencias montado en su fiel potro Empire Keeway\n");
        printf("\n salud 100, energia 30, accion 10, dano 25, \n rango 1, armadura 40, evasion 25, velocidad 2\n");
        printf("\nEl politico corrupto: imagina cualquier politico Venezolano \ncon una cuenta de banco m�s modesta y bingo, este es tu personaje\n");
        printf("\n salud 100, energia 30, accion 10, dano 20, \n rango 2, armadura 0, evasion 10, velocidad 2\n");
        printf("\nEl medico cubano: un misterioso sujeto que dice venir de \n'La isla de la felicidad'... Yo no estaria tan seguro\n");
        printf("\n salud 100, energia 30, accion 10, dano 15, \n rango 1, armadura 0, evasion 10, velocidad 1\n");
        printf("\nEl profesor: son bastante subestimados por su humildad, \npero son seres magicos capaces de sobrevivir con un sueldo equivalente a \nuna chicha con canela\n");
        printf("\n salud 100, energia 30, accion 10, dano 15, \n rango 4, armadura 10, evasion 20, velocidad 3\n");
        printf("\nElige tus personajes: \n");
        seleccionPersonaje(cantidad, h, i);
    }
    else inicio(h, i);
    return cantidad;
}

void turno(ListaP La, ListaP Lb){

    NodoP *t0, *t1;

    t0 = La; /// t0 y t1 son apuntadores a las listas creadas anteriormente, se van a ir desplazando a lo largo de las listas, apuntando a los personajes
    t1 = Lb; /// que les jugar

    int seguir0 = 1, seguir1 = 1, partidaNueva;

    ///Hice 3 while, el primero que es infinito (cuya condicion hay que cambiar) permite la asignaci�n de los turnos y de los puntos a cada personaje
    ///en la medida que les toque jugar.

    ///Los otros 2 se utilizan a modo de recursion, si el personaje de turno decide no jugar m�s, ya sea por ceder el turno o porque no tiene puntos
    ///de accion, entonces selecciona la opcion 0, cierra el ciclo y se abre siguiente ciclo, que corresponde al del jugador 2, una vez este cede el turno
    ///el while infinito permite volver al ciclo del jugador 1, y asi vamos

    PlaySound(TEXT("Inicio.wav"),NULL,SND_SYNC);

    fflush(stdin);
    while(!(La == NULL || Lb == NULL)){

        int seguir0 = 1, seguir1 = 1;

        t0->Jug->ptEnergia = t0->Jug->ptEnergia+5;
        t0->Jug->ptAccion = t0->Jug->ptAccion+5; ///Aqui se suman los 5 puntos al personaje del jugador 1
        PlaySound(TEXT("Siguiente.wav"),NULL,SND_SYNC);

        while(seguir0){ ///Empieza a jugar el personaje del jugador 1

            char x;
            int y, h, puntos, aceptar; //calculaPuntos

            if(t0->Jug->ptSalud<=0){
                t0 = t0->sig;
                t0->Jug->ptEnergia = t0->Jug->ptEnergia+5;
                t0->Jug->ptAccion = t0->Jug->ptAccion+5;
            }
            else{
                if(espacios[t0->Jug->posY][t0->Jug->posX]->item != NULL) printf("\n\t\tPENDIENTE PERRO CALIENTE!!! Hay items aqui\n");
                printf("\n\t\tJugador 0: Juega el personaje %s\n", t0->Jug->nombre);
                printf("\n\t\t%s: Salud = %d\tEnergia = %d\tPtAccion = %d\n", t0->Jug->nombre,t0->Jug->ptSalud,t0->Jug->ptEnergia,t0->Jug->ptAccion);
                printf("\nQue quieres hacer?\n\n 1)Mostrar tablero\n 2)Consultar casilla\n 3)Atacar\n 4)Moverse\n 5)Usar habilidad\n 6)Usar item\n 7)Terminar turno\n 8)Inventario\n 9)Datos de tu personaje\n");//1)Mostrar tablero\n 2)Consultar casilla\n 3)Atacar\n 4)Moverse\n 5)Usar habilidad\n 6)Usar item\n 7)Terminar turno\n 8)Inventario\n
                printf("\nOpcion: ");
                scanf("%d",&h);

                if(h==1) imprimeTerreno(); ///Imprimimos el terreno

                else if(h==2) { ///Consultar Casilla
                    printf("\nQue casilla quieres observar?:"); printf(" X = "); scanf(" %c",&x); printf("Y = "); scanf("%d",&y);

                    if(!isupper(x)) x=(int)x-97;
                    else x=(int)x-65;

                    if(espacios[y][x]->Jugador == NULL && espacios[y][x]->efecto == Ninguno /*&&  espacios[y][x]->Item == NULL */) printf("\nAqui no hay nada, ALO?\n");
                    else{
                        if(espacios[y][x]->Jugador != NULL){
                            printf("\nAqui se encuentra %s, tiene %d puntos de vida, %d puntos de energia y \n%d puntos de accion\n",espacios[y][x]->Jugador->nombre,espacios[y][x]->Jugador->ptSalud,espacios[y][x]->Jugador->ptEnergia,espacios[y][x]->Jugador->ptAccion);
                        }
                        if(espacios[y][x]->efecto != 0){
                            if (espacios[y][x]->efecto == Electrificado) printf("\nEsta casilla hace que le pegues los dedos a un enchufe...\n");
                            if (espacios[y][x]->efecto == Incendiado) printf("\nEsta casilla esta prendida en candela\n");
                            if (espacios[y][x]->efecto == Congelado) printf("\nEn esta casilla esta pegando tremendo frio\n");
                        }
                        if(espacios[y][x]->item != NULL) printf("\nAqu� hay un item, pero no te voy a decir cual\n");
                    }
                }

                else if(h==3){ ///Atacar
                    printf("\nA donde quieres atacar?:"); printf(" X = "); scanf(" %c",&x); printf("Y = "); scanf("%d",&y);

                    if(!isupper(x)) x=(int)x-97;
                    else x=(int)x-65; ///Hacemos casting porque necesitamos el valor en ASCII del char x, le restamos 65 (o 97 si es minuscula) para tener las coordenadas en n�meros, del 0 al 19

                    puntos = calculaPuntos(t0->Jug->posX, x, t0->Jug->posY, y);
                    if(espacios[y][x]->Jugador != NULL) {
                        if(t0->Jug->rango >= puntos && t0->Jug->ptAccion > 1 && (x != t0->Jug->posX || y != t0->Jug->posY)){
                            t0->Jug->ptAccion = t0->Jug->ptAccion-puntos;
                            PlaySound(TEXT("Ataque.wav"),NULL,SND_SYNC);
                            atacar(x, y, t0->Jug->dano, espacios[y][x]->Jugador->armadura, espacios[y][x]->Jugador->evasion, espacios[y][x]->Jugador->ptSalud);

                            ///Ahora escaneamos el estado de los personajes del jugador 1, si alguno tiene vida negativa o nula, se elimina de la lista

                            NodoP *t1Scan, *q;
                            t1Scan = Lb;

                            if(t1Scan->Jug->ptSalud <= 0){
                                Lb = Lb->sig;
                                espacios[t1Scan->Jug->posY][t1Scan->Jug->posX]->Jugador = NULL;
                                espacios[t1Scan->Jug->posY][t1Scan->Jug->posX]->item = t1Scan->Jug->inventario;
                                printf("\nHas acabado con %s\n",t1Scan->Jug->nombre);
                                t1 = t1->sig;
                                PlaySound(TEXT("Kill.wav"),NULL,SND_SYNC);
                                free(t1Scan);
                            }
                            else{
                                while(t1Scan->sig != NULL && (t1Scan->sig->Jug->ptSalud > 0) ){
                                    t1Scan = t1Scan->sig;
                                }
                                if(t1Scan->sig != NULL){
                                    q = t1Scan->sig;
                                    t1Scan->sig = q->sig;
                                    espacios[t1Scan->Jug->posY][t1Scan->Jug->posX]->Jugador = NULL;
                                    espacios[t1Scan->Jug->posY][t1Scan->Jug->posX]->item = t1Scan->Jug->inventario;
                                    printf("\nHas acabado con %s\n",t1Scan->Jug->nombre);
                                    t1 = t1->sig;
                                    PlaySound(TEXT("Kill.wav"),NULL,SND_SYNC);
                                    free(q);
                                }
                            }
                            if(Lb == NULL){
                                printf("\n\nGana el equipo del jugador 0\n");
                                PlaySound(TEXT("Final.wav"),NULL,SND_SYNC);
                                printf("\nQuieren jugar de nuevo? Si (1), no (0): ");
                                scanf("%d", &partidaNueva);
                                if(partidaNueva) main();
                                else printf("\nAdios!!!");
                            }
                        }
                        else{
                            if(t0->Jug->rango < puntos ){
                                printf("\nEl objetivo esta fuera de rango\n");
                                PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
                            }
                            if(t0->Jug->ptAccion <= 1){
                                printf("\nNo posees suficientes puntos de accion\n");
                                PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
                            }
                            if(x == t0->Jug->posX && y == t0->Jug->posY){
                                printf("\nAlo?\n");
                                PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
                            }
                        }
                    }
                    else printf("\nNo hay nadie en esta casilla\n");
                    printf("\nElegir otra opcion (1), ceder el turno (0): ");
                    scanf("%d", &seguir0);
                }

                else if(h == 4){ ///Moverse
                    printf("\nA donde te quieres mover?:"); printf(" X = "); scanf(" %c",&x); printf("Y = "); scanf("%d",&y);
                    //calculaPuntos = (abs(t0->Jug->posX-x) + abs(t0->Jug->posY-y)); ///Tambien sirve para calcular distancias

                    if(!isupper(x)) x=(int)x-97;
                    else x=(int)x-65;

                    puntos = calculaPuntos(t0->Jug->posX, x, t0->Jug->posY, y);

                    ///En la estructura de personaje agregu� 2 par�metros: posX y posY, permiten ver la posicion del personaje dentro del tablero
                    ///sin la necesidad de saber cual estructura espacios[i][j] lo est� apuntando

                    printf("\nNecesitas %d puntos para moverte, aceptar (1), rechazar (0): ", puntos);
                    scanf("%d", &aceptar);

                    if(aceptar == 1 && t0->Jug->ptAccion>=puntos){
                        if(espacios[y][x]->Jugador == NULL){
                            t0->Jug->ptAccion = t0->Jug->ptAccion-puntos; ///Restamos los puntos de accion
                            PlaySound(TEXT("Movimiento.wav"),NULL,SND_SYNC);
                            movimientoPersonaje(espacios[t0->Jug->posY][t0->Jug->posX], t0->Jug, x, y);///Mandamos la casilla que apunta al jugador, mandamos al jugador y mandamos las coordenadas a las que se quiera mover.
                            imprimeTerreno();
                            t0->Jug->posX = x; ///Actualizamos la coordenada x del personaje de turno
                            t0->Jug->posY = y; ///Actualizamos la coordenada y del personaje de turno

                            if(espacios[t0->Jug->posY][t0->Jug->posX]->item != NULL) printf("\n\t\tPENDIENTE PERRO CALIENTE!!! Hay items aqui\n");
                            if(espacios[t0->Jug->posY][t0->Jug->posX]->efecto == Incendiado){
                                t0->Jug->ptSalud = t0->Jug->ptSalud-(t0->Jug->ptSalud)/3;
                                printf("\nFUEGOOOOOOOOOOOOOOOOOOO\n");
                                printf("\nAhora tienes %d de vida\n", t0->Jug->ptSalud);
                                PlaySound(TEXT("Fuego.wav"),NULL,SND_SYNC);
                                espacios[t0->Jug->posY][t0->Jug->posX]->efecto = Ninguno;
                            }
                            if(espacios[t0->Jug->posY][t0->Jug->posX]->efecto == Electrificado){
                                t0->Jug->ptEnergia = (t0->Jug->ptEnergia)/2;
                                printf("\nEsto es culpa de la iguana, segun Corpoelec\n");
                                PlaySound(TEXT("Corrientazo.wav"),NULL,SND_SYNC);
                                espacios[t0->Jug->posY][t0->Jug->posX]->efecto = Ninguno;
                            }
                            if(espacios[t0->Jug->posY][t0->Jug->posX]->efecto == Congelado){
                                t0->Jug->ptAccion = 0;
                                printf("\nNo viste al motorizado con parrillero?\n");
                                PlaySound(TEXT("PegarPacheco.wav"),NULL,SND_SYNC);
                                espacios[t0->Jug->posY][t0->Jug->posX]->efecto = Ninguno;
                            }
                        }
                        else{
                            printf("\nHay alguien en esta casilla\n");
                            PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
                        }
                        printf("\n%s, tienes %d puntos de accion, que deseas hacer?\n", t0->Jug->nombre ,t0->Jug->ptAccion);
                        printf("\nElegir otra opcion (1), ceder el turno (0): ");
                        scanf("%d", &seguir0);
                    }
                    else if(aceptar == 1 && t0->Jug->ptAccion<puntos){
                        printf("\nNo te alcanzan los puntos de accion, que deseas hacer?\n");
                        PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
                        printf("\nElegir otra opcion (1), ceder el turno (0): ");
                        scanf("%d", &seguir0);
                    }
                }

                else if(h==5){///Usar Habilidad
                    int k;
                    printf("\n");
                    escribeListaH(t0->Jug->habilidad);
                    printf("\nQue habilidad quieres usar? Opcion: ");
                    scanf("%d",&k);
                    printf("\nEn que casilla quieres utilizar la habilidad?:"); printf(" X = "); scanf(" %c",&x); printf("Y = "); scanf("%d",&y);

                    if(!isupper(x)) x=(int)x-97;
                    else x=(int)x-65;
                    if(espacios[y][x]->Jugador != NULL) {
                        puntos = calculaPuntos(t0->Jug->posX, x, t0->Jug->posY, y);
                        usarHabilidad(t0->Jug->habilidad, x, y, t0->Jug->posX, t0->Jug->posY, puntos, t0->Jug->ptAccion, t0->Jug->ptEnergia, k);
                    }
                    else printf("\nNo hay nadie en esta casilla\n");
                    printf("\nElegir otra opcion (1), ceder el turno (0): ");
                    scanf("%d", &seguir0);
                }

                else if(h==6){///Usar item
                    int k;
                    if (esVacia(t0->Jug->inventario))printf("\nNo posees NADA en tu inventario\n");
                    else{
                        Item a = top(t0->Jug->inventario);
                        printf("\n%s\n",a->nombre);
                        printf("\nDeseas utilizar este Item? Si (1), no (0): ");
                        scanf("%d",&k);
                        if(k==1){
                            printf("\nEn donde quieres utilizar el Item?:"); printf(" X = "); scanf(" %c",&x); printf("Y = "); scanf("%d",&y);

                            if(!isupper(x)) x=(int)x-97;
                            else x=(int)x-65;

                            puntos = calculaPuntos(t0->Jug->posX, x, t0->Jug->posY, y);
                            if(t0->Jug->rango > puntos && t0->Jug->ptAccion > a->costo){
                                t0->Jug->ptAccion = t0->Jug->ptAccion - a->costo;
                                usarItem(a, x, y);
                                pop(&(t0->Jug->inventario));
                            }
                            else{
                                if(t0->Jug->ptAccion < a->costo) printf("\nNo te alcanzan los puntos de accion, que deseas hacer?\n");
                                if(a->rango < puntos) printf("\nEl objetivo esta fuera de rango\n");
                                PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
                                printf("\nElegir otra opcion (1), ceder el turno (0): ");
                                scanf("%d", &seguir0);
                            }
                        }
                        else{
                            printf("\nElegir otra opcion (1), ceder el turno (0): ");
                            scanf("%d", &seguir0);
                        }
                    }
                }

                else if(h==7) seguir0 = 0; ///Cedemos el turno

                else if(h==8) { ///Mostramos el inventario

                    int s, y = t0->Jug->posY, x = t0->Jug->posX;

                    printf("\nLas opciones que puede usar:\n\n 1)Recoger item\n 2)Soltar item\n 3)Consultar tope\n 4)Volver\n");
                    printf("\nDiga cual quiere usar: ");
                    scanf("%d",&s);

                    if(s==1){
                        if(espacios[y][x]->item == NULL) printf("\n\t Aqui no hay nada, chiwire. Elige otra opcion\n");
                        else {
                            Item j = quitardelista(&(espacios[y][x]->item));
                            push(j,&(t0->Jug->inventario));
                            printf("\n\t Has agregado %s del terreno a tu inventario\n", j->nombre);
                        }
                    }
                    else if (s==2){
                        if(esVacia(t0->Jug->inventario)) printf("\n\t 'Tas es limpio, chiwire. Elige otra opcion\n");
                        else {
                            Item j = top(t0->Jug->inventario);
                            pop(&(t0->Jug->inventario));
                            AgregaLista(j, &(espacios[y][x]->item));
                            printf("\n\t Has soltado %s al terreno \n", j->nombre);
                        }
                    }
                    else if (s==3){
                        if(esVacia(t0->Jug->inventario)){
                            printf("\n\t 'Tas es limpio, chiwire. Elige otra opcion\n");
                        }
                        else{
                            Item j = top(t0->Jug->inventario);
                            printf("\n\t Arriba del inventario tienes: %s\n", j->nombre);
                        }
                    }
                    else if (s==4){
                        break;
                    }
                }
                else if(h==9){ ///Mostramos las estad�sticas del jugador de turno
                    printf("\n%s, posees lo siguiente: ",t0->Jug->nombre);
                    printf("Salud %d, ",t0->Jug->ptSalud);
                    printf("energia %d, ",t0->Jug->ptEnergia);
                    printf("accion %d, ",t0->Jug->ptAccion);
                    printf("dano %d, ",t0->Jug->dano);
                    printf("\nrango %d, ",t0->Jug->rango);
                    printf("armadura %d, ",t0->Jug->armadura);
                    printf("evasion %d, ",t0->Jug->evasion);
                    printf("velocidad %d\n",t0->Jug->velocidad);
                }
            }
        }

        ///Si salimos del ciclo, el apuntador t0 que se desplaza por la lista ahora va a apuntar al siguiente personaje, que ser� seleccionado cuando retornemos
        ///al primer while
        t0 = t0->sig;
        if(t0 == NULL) t0 = La;

        ///Ahora entramos al segundo while, empiezan a jugar los personajes del jugador 2

        t1->Jug->ptEnergia = t1->Jug->ptEnergia+5;
        t1->Jug->ptAccion = t1->Jug->ptAccion+5; ///Se suman 5 puntos de accion para el personaje del jugador 2
        PlaySound(TEXT("Siguiente.wav"),NULL,SND_SYNC);

        while(seguir1){
            char x;
            int y, h, puntos,aceptar;

            if(t1->Jug->ptSalud<=0){
                t1 = t1->sig;
                t1->Jug->ptEnergia = t1->Jug->ptEnergia+5;
                t1->Jug->ptAccion = t1->Jug->ptAccion+5;
            }

            else{
                if(espacios[t1->Jug->posY][t1->Jug->posX]->item != NULL) printf("\n\t\tPENDIENTE PERRO CALIENTE!!! Hay items aqui\n");
                printf("\n\t\tJugador 1: Juega el personaje %s\n", t1->Jug->nombre);
                printf("\n\t\t%s: Salud = %d\tEnergia = %d\tPtAccion = %d\n", t1->Jug->nombre,t1->Jug->ptSalud,t1->Jug->ptEnergia,t1->Jug->ptAccion);
                printf("\nQue quieres hacer?\n\n 1)Mostrar tablero\n 2)Consultar casilla\n 3)Atacar\n 4)Moverse\n 5)Usar habilidad\n 6)Usar item\n 7)Terminar turno\n 8)Inventario\n 9)Datos de tu personaje\n");//1)Mostrar tablero\n 2)Consultar casilla\n 3)Atacar\n 4)Moverse\n 5)Usar habilidad\n 6)Usar item\n 7)Terminar turno\n 8)Inventario\n
                printf("\nOpcion: ");
                scanf("%d",&h);

                if(h==1) imprimeTerreno(); ///Imprimimos el terreno

                else if(h==2) { ///Consultar Casilla
                    printf("\nQue casilla quieres observar?:"); printf(" X = "); scanf(" %c",&x); printf("Y = "); scanf("%d",&y);

                    if(!isupper(x)) x=(int)x-97;
                    else x=(int)x-65;

                    if(espacios[y][x]->Jugador == NULL /*&& espacios[y][x]->efecto == 0 /*&&  espacios[y][x]->Item == NULL */) printf("\nAqui no hay nada, ALO?\n");
                    else{
                        if(espacios[y][x]->Jugador != NULL){
                            printf("\nAqui se encuentra %s, tiene %d puntos de vida, %d puntos de energia y %d puntos de accion\n",espacios[y][x]->Jugador->nombre,espacios[y][x]->Jugador->ptSalud,espacios[y][x]->Jugador->ptEnergia,espacios[y][x]->Jugador->ptAccion);
                        }
                        if(espacios[y][x]->efecto != 0){
                            if (espacios[y][x]->efecto == Electrificado) printf("\nEsta casilla hace que le pegues los dedos a un enchufe...\n");
                            if (espacios[y][x]->efecto == Incendiado) printf("\nEsta casilla esta prendida en candela\n");
                            if (espacios[y][x]->efecto == Congelado) printf("\nEn esta casilla esta pegando tremendo frio\n");
                        }
                        /*
                        if(espacios[y][x]->item != NULL){ No se
                        }
                        */
                    }
                }
                else if(h==3){///Atacar
                    printf("\nA donde quieres atacar?:"); printf(" X = "); scanf(" %c",&x); printf("Y = "); scanf("%d",&y);

                    if(!isupper(x)) x=(int)x-97;
                    else x=(int)x-65;

                    puntos = calculaPuntos(t1->Jug->posX, x, t1->Jug->posY, y);
                    if(espacios[y][x]->Jugador != NULL) {
                        if(t1->Jug->rango >= puntos && t1->Jug->ptAccion > 1 && (y != t1->Jug->posY || x != t1->Jug->posX)){
                            t1->Jug->ptAccion = t1->Jug->ptAccion-puntos;
                            PlaySound(TEXT("Ataque.wav"),NULL,SND_SYNC);
                            atacar(x, y, t1->Jug->dano, espacios[y][x]->Jugador->armadura, espacios[y][x]->Jugador->evasion, espacios[y][x]->Jugador->ptSalud);

                            ///Ahora escaneamos el estado de los personajes del jugador 0, si alguno tiene vida negativa o nula, se elimina de la lista

                            NodoP *t0Scan, *q;
                            t0Scan = La;

                            if(t0Scan->Jug->ptSalud <= 0){
                                La = La->sig;
                                espacios[t0Scan->Jug->posY][t0Scan->Jug->posX]->Jugador = NULL;
                                espacios[t0Scan->Jug->posY][t0Scan->Jug->posX]->item = t0Scan->Jug->inventario;
                                printf("\nHas acabado con %s\n",t0Scan->Jug->nombre);
                                t0 = t0->sig;
                                PlaySound(TEXT("Kill.wav"),NULL,SND_SYNC);
                                free(t0Scan);
                            }
                            else{
                                while(t0Scan->sig != NULL && (t0Scan->sig->Jug->ptSalud > 0) ){
                                    t0Scan = t0Scan->sig;
                                }
                                if(t0Scan->sig != NULL){
                                    q = t0Scan->sig;
                                    t0Scan->sig = q->sig;
                                    espacios[t0Scan->Jug->posY][t0Scan->Jug->posX]->Jugador = NULL;
                                    espacios[t0Scan->Jug->posY][t0Scan->Jug->posX]->item = t0Scan->Jug->inventario;
                                    printf("\nHas acabado con %s\n",t0Scan->Jug->nombre);
                                    t0 =t0->sig;
                                    PlaySound(TEXT("Kill.wav"),NULL,SND_SYNC);
                                    free(q);
                                }
                            }
                            if(La == NULL){
                                printf("\n\nGana el equipo del jugador 1\n");
                                PlaySound(TEXT("Final.wav"),NULL,SND_SYNC);
                                printf("\nQuieren jugar de nuevo? Si (1), no (0): ");
                                scanf("%d", &partidaNueva);
                                if(partidaNueva) main();
                                else printf("\nAdios!!!\n");
                            }
                        }
                        else{
                            if(t1->Jug->rango < puntos ){
                                printf("\nEl objetivo esta fuera de rango\n");
                                PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
                            }
                            if(t1->Jug->ptAccion <= 1){
                                printf("\nNo posees suficientes puntos de accion\n");
                                PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
                            }
                            if(y == t1->Jug->posY && x == t1->Jug->posX){
                                printf("\nAlo?\n");
                                PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
                            }
                        }
                    }
                    else printf("\nNo hay nadie en esta casilla\n");
                    printf("\nElegir otra opcion (1), ceder el turno (0): ");
                    scanf("%d", &seguir1);
                }
                else if(h == 4){ ///Movimiento
                    printf("\nA donde te quieres mover?:"); printf(" X = "); scanf(" %c",&x); printf("Y = "); scanf("%d",&y);
                    //calculaPuntos = (abs(t1->Jug->posX-x) + abs(t1->Jug->posY-y)); ///Tambien sirve para calcular distancias

                    if(!isupper(x)) x=(int)x-97;
                    else x=(int)x-65;

                    puntos = calculaPuntos(t1->Jug->posX, x, t1->Jug->posY, y);

                    ///En la estructura de personaje agregu� 2 par�metros: posX y posY, permiten ver la posicion del personaje dentro del tablero
                    ///sin la necesidad de saber cual estructura espacios[i][j] lo est� apuntando

                    printf("\nNecesitas %d puntos para moverte, aceptar (1), rechazar (0): ", puntos);
                    scanf("%d", &aceptar);

                    if(aceptar == 1 && t1->Jug->ptAccion>=puntos){
                        if(espacios[y][x]->Jugador == NULL){
                            t1->Jug->ptAccion = t1->Jug->ptAccion-puntos; ///Restamos los puntos de accion
                            PlaySound(TEXT("Movimiento.wav"),NULL,SND_SYNC);
                            movimientoPersonaje(espacios[t1->Jug->posY][t1->Jug->posX], t1->Jug, x, y);///Mandamos la casilla que apunta al jugador, mandamos al jugador y mandamos las coordenadas a las que se quiera mover.
                            imprimeTerreno();
                            t1->Jug->posX = x; ///Actualizamos la coordenada x del personaje de turno
                            t1->Jug->posY = y; ///Actualizamos la coordenada y del personaje de turno
                            if(espacios[t1->Jug->posY][t1->Jug->posX]->item != NULL) printf("\n\t\tPENDIENTE PERRO CALIENTE!!! Hay items aqui\n");
                            if(espacios[t1->Jug->posY][t1->Jug->posX]->efecto == Incendiado){
                                t1->Jug->ptSalud = t1->Jug->ptSalud-(t1->Jug->ptSalud)/3;
                                printf("\nFUEGOOOOOOOOOOOOOOOOOOO\n");
                                printf("\nAhora tienes %d de vida\n", t1->Jug->ptSalud);
                                PlaySound(TEXT("Fuego.wav"),NULL,SND_SYNC);
                                espacios[t1->Jug->posY][t1->Jug->posX]->efecto = Ninguno;
                            }
                            if(espacios[t1->Jug->posY][t1->Jug->posX]->efecto == Electrificado){
                                t1->Jug->ptEnergia = (t1->Jug->ptEnergia)/2;
                                printf("\nEsto es culpa de la iguana, segun Corpoelec\n");
                                PlaySound(TEXT("Corrientazo.wav"),NULL,SND_SYNC);
                                espacios[t1->Jug->posY][t1->Jug->posX]->efecto = Ninguno;
                            }
                            if(espacios[t1->Jug->posY][t1->Jug->posX]->efecto == Congelado){
                                t1->Jug->ptAccion = 0;
                                printf("\nNo viste al motorizado con parrillero?\n");
                                PlaySound(TEXT("PegarPacheco.wav"),NULL,SND_SYNC);
                                espacios[t1->Jug->posY][t1->Jug->posX]->efecto = Ninguno;
                            }
                        }
                        else printf("\nHay alguien en esta casilla\n");
                        printf("\n%s, tienes %d puntos de accion, que deseas hacer?\n", t1->Jug->nombre ,t1->Jug->ptAccion);
                        printf("\nElegir otra opcion (1), ceder el turno (0): ");
                        scanf("%d", &seguir1);
                    }
                    else if(aceptar == 1 && t1->Jug->ptAccion<puntos){
                        printf("\nNo te alcanzan los puntos de accion, que deseas hacer?\n");
                        PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
                        printf("\nElegir otra opcion (1), ceder el turno (0): ");
                        scanf("%d", &seguir1);
                    }
                }
                else if(h==5){///Usar Habilidad
                    int k;
                    printf("\n");
                    escribeListaH(t1->Jug->habilidad);
                    printf("\nQue habilidad quieres usar? Opcion: ");
                    scanf("%d",&k);
                    printf("\nEn que casilla quieres utilizar la habilidad?:"); printf(" X = "); scanf(" %c",&x); printf("Y = "); scanf("%d",&y);

                    if(!isupper(x)) x=(int)x-97;
                    else x=(int)x-65;

                    if(espacios[y][x]->Jugador != NULL) {
                        puntos = calculaPuntos(t1->Jug->posX, x, t1->Jug->posY, y);
                        usarHabilidad(t1->Jug->habilidad, x, y, t1->Jug->posX, t1->Jug->posY, puntos, t1->Jug->ptAccion,t1->Jug->ptEnergia,k);
                    }
                    else printf("\nNo hay nadie en esta casilla\n");
                    printf("\nElegir otra opcion (1), ceder el turno (0): ");
                    scanf("%d", &seguir1);
                }
                else if(h==6){///Usar item
                    int k;
                    if (esVacia(t1->Jug->inventario)) printf("\nNo posees NADA en tu inventario\n");
                    else{
                        Item a = top(t1->Jug->inventario);
                        printf("\n%s\n",a->nombre);
                        printf("\nDeseas utilizar este Item? Si (1), no (0): ");
                        scanf("%d",&k);
                        if(k==1){
                            printf("\nEn donde quieres utilizar el Item?:"); printf(" X = "); scanf(" %c",&x); printf("Y = "); scanf("%d",&y);

                            if(!isupper(x)) x=(int)x-97;
                            else x=(int)x-65;

                            puntos = calculaPuntos(t1->Jug->posX, x, t1->Jug->posY, y);
                            if(t1->Jug->rango > puntos && t1->Jug->ptAccion > a->costo){
                                t1->Jug->ptAccion = t1->Jug->ptAccion - a->costo;
                                usarItem(a, x, y);
                                pop(&(t1->Jug->inventario));
                            }
                            else{
                                if(t1->Jug->ptAccion < a->costo) printf("\nNo te alcanzan los puntos de accion, que deseas hacer?\n");
                                if(a->rango < puntos) printf("\nEl objetivo esta fuera de rango\n");
                                PlaySound(TEXT("Error.wav"),NULL,SND_SYNC);
                                printf("\nElegir otra opcion (1), ceder el turno (0): ");
                                scanf("%d", &seguir1);
                            }
                        }
                        else{
                            printf("\nElegir otra opcion (1), ceder el turno (0): ");
                            scanf("%d", &seguir1);
                        }
                    }
                }

                else if(h==7) seguir1 = 0; ///Ceder turno

                else if(h==8) { ///Mostramos el inventario

                    int s, y = t1->Jug->posY, x = t1->Jug->posX;

                    printf("\nLas opciones que puede usar:\n\n 1)Recoger item\n 2)Soltar item\n 3)Consultar tope\n 4)Volver\n");
                    printf("\nDiga cual quiere usar: ");
                    scanf("%d",&s);

                    if(s==1){
                        if(espacios[y][x]->item == NULL) printf("\n\t Aqui no hay nada, chiwire. Elige otra opcion\n");
                        else {
                            Item j = quitardelista(&(espacios[y][x]->item));
                            push(j,&(t1->Jug->inventario));
                            printf("\n\t Has agregado %s del terreno a tu inventario\n", j->nombre);
                        }
                    }
                    else if (s==2){
                        if(esVacia(t1->Jug->inventario)) printf("\n\t 'Tas es limpio, chiwire. Elige otra opcion\n");
                        else {
                            Item j = top(t1->Jug->inventario);
                            pop(&(t1->Jug->inventario));
                            AgregaLista(j, &(espacios[y][x]->item));
                            printf("\n\t Has soltado %s al terreno \n", j->nombre);
                        }
                    }
                    else if (s==3){
                        if(esVacia(t1->Jug->inventario)){
                            printf("\n\t 'Tas es limpio, chiwire. Elige otra opcion\n");
                        }
                        else{
                            Item j = top(t1->Jug->inventario);
                            printf("\n\t Arriba del inventario tienes: %s\n", j->nombre);
                        }
                    }
                    else if (s==4){
                        break;
                    }
                }
                else if(h==9){///Mostrar estad�sticas
                    printf("\n%s posees lo siguiente: ", t1->Jug->nombre);
                    printf("Salud %d, ", t1->Jug->ptSalud);
                    printf("energia %d, ", t1->Jug->ptEnergia);
                    printf("accion %d, ", t1->Jug->ptAccion);
                    printf("dano %d, ", t1->Jug->dano);
                    printf("\nrango %d, ", t1->Jug->rango);
                    printf("armadura %d, ",t1->Jug->armadura);
                    printf("evasion %d, ",t1->Jug->evasion);
                    printf("velocidad %d\n",t1->Jug->velocidad);
                }
            }
        }
        t1 = t1->sig;
        if(t1 == NULL) t1 = Lb;

        if(La == NULL){
            printf("\n\nGana el equipo del jugador 1\n");
            PlaySound(TEXT("Final.wav"),NULL,SND_SYNC);
        }
        if(Lb == NULL) {
            printf("\n\nGana el equipo del jugador 0\n");
            PlaySound(TEXT("Final.wav"),NULL,SND_SYNC);
        }
    }

    printf("\nQuieren jugar de nuevo? Si (1), no (0): ");
    scanf("%d", &partidaNueva);
    if(partidaNueva) main();
    else printf("\nAdios!!!");

}

void main(){

    printf("\nBienvenido a la Batalla de Gallos 2018.");
    int a;

    terrenoPelea();

    Habilidad R = newRestaurar();
    Habilidad I = newIncendiar();
    Habilidad C = newCongelar();
    Habilidad E = newElectrocutar();

    Listaha habilidades = newListaha();

    agregar(E, &habilidades);
    agregar(C, &habilidades);
    agregar(I, &habilidades);
    agregar(R, &habilidades);
    //escribeListaH(habilidad);

    Item Sa = newpociondesalud();
    Item En = newpociondeEnergia();
    Item An = newgranadaanuladora();

    Pila items = newPila();

    push(Sa, &items);
    push(En, &items);
    push(An, &items);

    a = inicio(habilidades, items);

    ListaP L0 = newListaP();
    for(int i=0;i<a;i++){
        insertaPersonaje(Jugador[0][i], &L0); ///Insertamos los personajes del primer jugador en una lista
    }

    ListaP L1 = newListaP();
    for(int i=0;i<a;i++){
        insertaPersonaje(Jugador[1][i], &L1); ///Insertamos los personajes del segundo jugador en otra lista
    }

    ordenarTurnos(&L0,&L1);

    printf("\nPersonajes ordenados de acuerdo a su velocidad\n");
    printf("\nIniciales de los personajes del jugador 0: "); escribeListaP(L0); ///Esta funci�n presenta errores al momento de imprimir,
    printf("\nIniciales de los personajes del jugador 1: "); escribeListaP(L1); ///es posible que haya que hacer una limpieza de buffer.
    printf("\n");

    for(int i = 0;i<10;i++){
        espacios[rand()%10][rand()%20]->efecto = rand()%4;
    }

    for(int i = 0;i<5;i++){
        AgregaLista(Sa, &(espacios[rand()%10][rand()%20]->item));
    }
    for(int i = 0;i<5;i++){
        AgregaLista(En, &(espacios[rand()%10][rand()%20]->item));
    }
    for(int i = 0;i<5;i++){
        AgregaLista(An, &(espacios[rand()%10][rand()%20]->item));
    }

    imprimeTerreno();

    turno(L0,L1);///Enviamos ambas listas para empezar a asignar los turnos a cada jugador
}
