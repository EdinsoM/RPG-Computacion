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
    char *nombre ;//1
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
    g->inventario;
    g->habilidad;
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
    g->inventario;
    g->habilidad;
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
    g->inventario;
    g->habilidad;
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
    g->inventario;
    g->habilidad;
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

void usarItem(Item i, int x, int y){
    if(i->nombre=="Atamel"){
         espacios[y][x]->Jugador->ptSalud = (espacios[x][y]->Jugador->ptSalud)+30;//un tercio del maximo

    }
    if(i->nombre=="Cafe"){
         espacios[y][x]->Jugador->ptEnergia = (espacios[x][y]->Jugador->ptEnergia)+10;

    }
    if(i->nombre=="granada_hora_del_burro"){
        for(int j=x-1;j<x+2;j++){
             for(int k=y-1;k<y+2;k++){
                espacios[y][x]->efecto = 0;
            }
        }
    }
}

void usarHabilidad(Listaha L, int x, int y, int posX, int posY, int distancia, int ptAccion, int ptEnergia, int k){
    int f = k;
    NodoHA *p = L;

    while(f!=1){
        p=p->sig;
        f--;
    }

    if(p->h->rango >= distancia && ptAccion >= p->h->costoAccion && ptEnergia >= p->h->costoEnergia){
        espacios[posY][posX]->Jugador->ptEnergia=ptEnergia-(p->h->costoEnergia);
        espacios[posY][posX]->Jugador->ptAccion=ptAccion-(p->h->costoAccion);

        if(strcmp(p->h->nombre,"Ramazos")==0){
            espacios[y][x]->Jugador->ptSalud = (espacios[y][x]->Jugador->ptSalud)+30;//un tercio del maximo
            printf("Le echaste unos ramazos a %s y se ha curado 30 puntos de vida \nAhora tiene %d puntos de vida",espacios[y][x]->Jugador->nombre,espacios[y][x]->Jugador->ptSalud);
        }
        if(strcmp(p->h->nombre,"PrenderCandela")==0){
            printf("Prendiste en candela %s y le quitaste %d puntos de vida \n",espacios[y][x]->Jugador->nombre,((espacios[y][x]->Jugador->ptSalud)/3));
            espacios[y][x]->Jugador->ptSalud = (espacios[y][x]->Jugador->ptSalud)-((espacios[y][x]->Jugador->ptSalud)/3);
            espacios[y][x]->efecto = 2;//Casilla incendiada
            printf("Ahora tiene %d puntos de vida",espacios[y][x]->Jugador->ptSalud);
        }
        if(strcmp(p->h->nombre,"PegarPacheco")==0){
            espacios[y][x]->Jugador->ptAccion = 0;
            espacios[y][x]->efecto = 3;//Casilla Congelada
            printf("Le robaste el sueter a %s y ahora se esta muriendo de frio \n",espacios[y][x]->Jugador->nombre);
        }
        if(strcmp(p->h->nombre,"Corrientazo")==0){
            espacios[y][x]->Jugador->ptEnergia = (espacios[y][x]->Jugador->ptEnergia)/2;
            espacios[y][x]->efecto = 1;//Casilla Electrificada
            printf("Hiciste que %s pegara los dedos en un enchufe \n",espacios[y][x]->Jugador->nombre);
        }

    }
    else{
        if(p->h->rango < distancia  ) printf("El objetivo esta fuera de rango\n");
        if(ptAccion < p->h->costoAccion) printf("No posees suficientes puntos de accion\n");
        if(ptEnergia < p->h->costoEnergia) printf("No posees suficientes puntos de energia\n");
    }
}

void atacar(int x, int y, int dano, int armadura, int evasion, int vida){
    if(rand()%101 > evasion ){
        int k;
        k=vida-(dano*(100-armadura))/100;
        printf("\nHas hecho %d dano al personaje %s\n", (dano*(100-armadura))/100, espacios[y][x]->Jugador->nombre);
        espacios[y][x]->Jugador->ptSalud=k;
        printf("\nA %s le queda %d puntos de vida\n",espacios[y][x]->Jugador->nombre,espacios[y][x]->Jugador->ptSalud);
    }
    else printf("El ataque ha sido esquivado");
}

void seleccionPersonaje(int x, Listaha h){
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
                    Jugador[j][p]->habilidad = h;
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
                    Jugador[j][p]->habilidad = h;
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
                    Jugador[j][p]->habilidad = h;
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
                    Jugador[j][p]->habilidad = h;
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
            if(espacios[i][j]->Jugador == NULL) printf("[-]");
            else printf("[%c]", espacios[i][j]->Jugador->nombre[0]);
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

int inicio(Listaha h){
    int cantidad;
    printf("\n\nCon cuantos personajes vas a jugar? Minimo 2, maximo 8 por jugador: ");
    scanf("%d", &cantidad);
    if(cantidad>=2 && cantidad<=8) seleccionPersonaje(cantidad,h);
    else inicio(h);
    return cantidad;
}

void turno(ListaP La, ListaP Lb){

    NodoP *t0, *t1;

    t0 = La; /// t0 y t1 son apuntadores a las listas creadas anteriormente, se van a ir desplazando a lo largo de las listas, apuntando a los personajes
    t1 = Lb; /// que les jugar

    int seguir0 = 1, seguir1 = 1, partidaNueva;

    ///Hice 3 while, el primero que es infinito (cuya condicion hay que cambiar) permite la asignación de los turnos y de los puntos a cada personaje
    ///en la medida que les toque jugar.

    ///Los otros 2 se utilizan a modo de recursion, si el personaje de turno decide no jugar más, ya sea por ceder el turno o porque no tiene puntos
    ///de accion, entonces selecciona la opcion 0, cierra el ciclo y se abre siguiente ciclo, que corresponde al del jugador 2, una vez este cede el turno
    ///el while infinito permite volver al ciclo del jugador 1, y asi vamos

    while(!(La == NULL || Lb == NULL)){
        int seguir0 = 1, seguir1 = 1;

        t0->Jug->ptAccion = t0->Jug->ptAccion+5; ///Aqui se suman los 5 puntos al personaje del jugador 1

        while(seguir0){ ///Empieza a jugar el personaje del jugador 1
            int x, y, h, puntos, aceptar; //calculaPuntos

            if(t0->Jug->ptSalud<=0) seguir0 = 0;
            else {
                printf("\nJugador 0: Juega el personaje %s\n", t0->Jug->nombre);
                printf("\n%s: Salud = %d\tEnergia = %d\tPtAccion = %d\n", t0->Jug->nombre,t0->Jug->ptSalud,t0->Jug->ptEnergia,t0->Jug->ptAccion);
                printf("\nQue quieres hacer?\n\n 1)Mostrar tablero\n 2)Consultar casilla\n 3)Atacar\n 4)Moverse\n 5)Usar habilidad\n 6)Usar item\n 7)Terminar turno\n 8)Inventario\n 9)Datos de tu personaje\n\n");//1)Mostrar tablero\n 2)Consultar casilla\n 3)Atacar\n 4)Moverse\n 5)Usar habilidad\n 6)Usar item\n 7)Terminar turno\n 8)Inventario\n
                printf("\nOpcion: ");
                scanf("%d",&h);

                if(h==1) imprimeTerreno(); ///Imprimimos el terreno

                else if(h==2) printf("\nEstas en la casilla [%d][%d]\n", t0->Jug->posX, t0->Jug->posY); ///Mostramos las coordenadas

                else if(h==3){ ///Atacar
                    printf("A donde quieres atacar?:"); printf(" X = "); scanf("%d",&x); printf("Y = "); scanf("%d",&y);
                    puntos = calculaPuntos(t0->Jug->posX, x, t0->Jug->posY, y);
                    if(espacios[y][x]->Jugador != NULL) {
                        if(t0->Jug->rango >= puntos && t0->Jug->ptAccion > 1 ){
                            t0->Jug->ptAccion = t0->Jug->ptAccion-puntos;
                            atacar(x, y, t0->Jug->dano, espacios[y][x]->Jugador->armadura, espacios[y][x]->Jugador->evasion, espacios[y][x]->Jugador->ptSalud);

                        ///Ahora escaneamos el estado de los personajes del jugador 1, si alguno tiene vida negativa o nula, se elimina de la lista

                            NodoP *t1Scan, *q;
                            t1Scan = Lb;

                            if(t1Scan->Jug->ptSalud <= 0){
                                Lb = Lb->sig;
                                espacios[t1Scan->Jug->posY][t1Scan->Jug->posX]->Jugador = NULL;
                                printf("\nHas acabado con %s",t1Scan->Jug->nombre);
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
                                    printf("\nHas acabado con %s",t1Scan->Jug->nombre);
                                    free(q);
                                }
                            }
                            if(Lb == NULL){
                                printf("\n\nGana el equipo del jugador 0\n");
                                printf("\nQuieren jugar de nuevo? Si (1), no (0): ");
                                scanf("%d", &partidaNueva);
                                if(partidaNueva) main();
                                else printf("\nAdios!!!");
                            }
                        }
                        else{
                            if(t0->Jug->rango < puntos ) printf("El objetivo esta fuera de rango\n");
                            if(t0->Jug->ptAccion <= 1) printf("No posees suficientes puntos de accion\n");
                        }
                    }
                    else printf("No hay nadie en esta casilla");
                    printf("\nElegir otra opcion (1), ceder el turno (0): ");
                    scanf("%d", &seguir0);
                }

                else if(h == 4){ ///Moverse
                    printf("A donde te quieres mover?:"); printf(" X = "); scanf("%d",&x); printf("Y = "); scanf("%d",&y);
                    //calculaPuntos = (abs(t0->Jug->posX-x) + abs(t0->Jug->posY-y)); ///Tambien sirve para calcular distancias
                    puntos = calculaPuntos(t0->Jug->posX, x, t0->Jug->posY, y);

                    ///En la estructura de personaje agregué 2 parámetros: posX y posY, permiten ver la posicion del personaje dentro del tablero
                    ///sin la necesidad de saber cual estructura espacios[i][j] lo está apuntando

                    printf("Necesitas %d puntos para moverte, aceptar (1), rechazar (0): ", puntos);
                    scanf("%d", &aceptar);

                    if(aceptar == 1 && t0->Jug->ptAccion>=puntos){
                        if(espacios[y][x]->Jugador == NULL){
                            t0->Jug->ptAccion = t0->Jug->ptAccion-puntos; ///Restamos los puntos de accion
                            movimientoPersonaje(espacios[t0->Jug->posY][t0->Jug->posX], t0->Jug, x, y);///Mandamos la casilla que apunta al jugador, mandamos al jugador y mandamos las coordenadas a las que se quiera mover.
                            imprimeTerreno();
                            t0->Jug->posX = x; ///Actualizamos la coordenada x del personaje de turno
                            t0->Jug->posY = y; ///Actualizamos la coordenada y del personaje de turno
                        }
                        else printf("\nHay alguien en esta casilla\n");
                        printf("\n%s, tienes %d puntos de accion, que deseas hacer?\n", t0->Jug->nombre ,t0->Jug->ptAccion);
                        printf("\nElegir otra opcion (1), ceder el turno (0): ");
                        scanf("%d", &seguir0);
                    }
                    else if(aceptar == 1 && t0->Jug->ptAccion<puntos){
                        printf("No te alcanzan los puntos de accion, que deseas hacer?");
                        printf("\nElegir otra opcion (1), ceder el turno (0): ");
                        scanf("%d", &seguir0);
                    }
                }

                else if(h==5){///Usar Habilidad
                    int k;
                    escribeListaH(t0->Jug->habilidad);
                    printf("Que habilidad quieres usar? Opcion: ");
                    scanf("%d",&k);
                    printf("En que casilla quieres utilizar la habilidad?:"); printf(" X = "); scanf("%d",&x); printf("Y = "); scanf("%d",&y);
                    puntos = calculaPuntos(t0->Jug->posX, x, t0->Jug->posY, y);
                    usarHabilidad(t0->Jug->habilidad, x, y, t0->Jug->posX, t0->Jug->posY, puntos, t0->Jug->ptAccion,t0->Jug->ptEnergia,k);
                    printf("\nElegir otra opcion (1), ceder el turno (0): ");
                    scanf("%d", &seguir0);
                }

                else if(h==6){///Usar item
                    int k;
                    if (esVacia(t0->Jug->inventario))printf("No posees NADA en tu inventario\n");
                    else{
                        Item a = top(t0->Jug->inventario);
                        printf("%s\n",a->nombre);
                        printf("Deseas utilizar este Item?\1)Si\n2)No");
                        scanf("%d",&k);
                        if(k==1){
                            printf("En donde quieres utilizar el Item?:"); printf(" X = "); scanf("%d",&x); printf("Y = "); scanf("%d",&y);
                            puntos = calculaPuntos(t0->Jug->posX, x, t0->Jug->posY, y);
                            if(top(t0->Jug->inventario)->rango>puntos && t0->Jug->ptAccion>top(t0->Jug->inventario)->costo){
                                usarItem(top(t0->Jug->inventario), x, y);
                                pop(t0->Jug->inventario);
                            }
                            else{
                                printf("No te alcanzan los puntos de accion, que deseas hacer?");
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

                }
                else if(h==9){ ///Mostramos las estadísticas del jugador de turno
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

        ///Si salimos del ciclo, el apuntador t0 que se desplaza por la lista ahora va a apuntar al siguiente personaje, que será seleccionado cuando retornemos
        ///al primer while
        t0 = t0->sig;
        if(t0 == NULL) t0 = La;

        ///Ahora entramos al segundo while, empiezan a jugar los personajes del jugador 2

        t1->Jug->ptAccion = t1->Jug->ptAccion+5; ///Se suman 5 puntos de accion para el personaje del jugador 2

        while(seguir1){
            int x, y, h, puntos,aceptar;
            if(t1->Jug->ptSalud<=0) seguir1 = 0;
            else{
                printf("\nJugador 1: Juega el personaje %s\n", t1->Jug->nombre);
                printf("\n%s: Salud = %d\tEnergia = %d\tPtAccion = %d\n", t1->Jug->nombre,t1->Jug->ptSalud,t1->Jug->ptEnergia,t1->Jug->ptAccion);
                printf("\nQue quieres hacer?\n\n 1)Mostrar tablero\n 2)Consultar casilla\n 3)Atacar\n 4)Moverse\n 5)Usar habilidad\n 6)Usar item\n 7)Terminar turno\n 8)Inventario\n 9)Datos de tu personaje\n\n");//1)Mostrar tablero\n 2)Consultar casilla\n 3)Atacar\n 4)Moverse\n 5)Usar habilidad\n 6)Usar item\n 7)Terminar turno\n 8)Inventario\n
                printf("\nOpcion: ");
                scanf("%d",&h);

                if(h==1) imprimeTerreno(); ///Imprimimos el terreno

                else if(h==2) printf("\nEstas en la casilla [%d][%d]", t1->Jug->posX, t1->Jug->posY); ///Muestra en cual casilla estás

                else if(h==3){///Atacar
                    printf("A donde quieres atacar?:"); printf(" X = "); scanf("%d",&x); printf("Y = "); scanf("%d",&y);
                    puntos = calculaPuntos(t1->Jug->posX, x, t1->Jug->posY, y);
                    if(espacios[y][x]->Jugador != NULL) {
                        if(t1->Jug->rango >= puntos && t1->Jug->ptAccion > 1 ){
                            t1->Jug->ptAccion = t1->Jug->ptAccion-puntos;
                            atacar(x, y, t1->Jug->dano, espacios[y][x]->Jugador->armadura, espacios[y][x]->Jugador->evasion, espacios[y][x]->Jugador->ptSalud);

                            ///Ahora escaneamos el estado de los personajes del jugador 0, si alguno tiene vida negativa o nula, se elimina de la lista

                            NodoP *t0Scan, *q;
                            t0Scan = Lb;

                            if(t0Scan->Jug->ptSalud <= 0){
                                Lb = Lb->sig;
                                espacios[t0Scan->Jug->posY][t0Scan->Jug->posX]->Jugador = NULL;
                                printf("\nHas acabado con %s",t0Scan->Jug->nombre);
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
                                    printf("\nHas acabado con %s",t0Scan->Jug->nombre);
                                    free(q);
                                }
                            }
                            if(La == NULL){
                                printf("\n\nGana el equipo del jugador 1\n");
                                printf("\nQuieren jugar de nuevo? Si (1), no (0): ");
                                scanf("%d", &partidaNueva);
                                if(partidaNueva) main();
                                else printf("\nAdios!!!");
                            }
                        }
                        else{
                            if(t1->Jug->rango < puntos ) printf("El objetivo esta fuera de rango\n");
                            if(t1->Jug->ptAccion <= 1) printf("No posees suficientes puntos de accion\n");
                        }
                    }
                    else printf("No hay nadie en esta casilla");
                    printf("\nElegir otra opcion (1), ceder el turno (0): ");
                    scanf("%d", &seguir1);
                }

                else if(h == 4){ ///Movimiento
                    printf("A donde te quieres mover?:"); printf(" X = "); scanf("%d",&x); printf("Y = "); scanf("%d",&y);
                    //calculaPuntos = (abs(t1->Jug->posX-x) + abs(t1->Jug->posY-y)); ///Tambien sirve para calcular distancias
                    puntos = calculaPuntos(t1->Jug->posX, x, t1->Jug->posY, y);

                    ///En la estructura de personaje agregué 2 parámetros: posX y posY, permiten ver la posicion del personaje dentro del tablero
                    ///sin la necesidad de saber cual estructura espacios[i][j] lo está apuntando

                    printf("Necesitas %d puntos para moverte, aceptar (1), rechazar (0): ", puntos);
                    scanf("%d", &aceptar);

                    if(aceptar == 1 && t1->Jug->ptAccion>=puntos){
                        if(espacios[y][x]->Jugador == NULL){
                            t1->Jug->ptAccion = t1->Jug->ptAccion-puntos; ///Restamos los puntos de accion
                            movimientoPersonaje(espacios[t1->Jug->posY][t1->Jug->posX], t1->Jug, x, y);///Mandamos la casilla que apunta al jugador, mandamos al jugador y mandamos las coordenadas a las que se quiera mover.
                            imprimeTerreno();
                            t1->Jug->posX = x; ///Actualizamos la coordenada x del personaje de turno
                            t1->Jug->posY = y; ///Actualizamos la coordenada y del personaje de turno
                        }
                        else printf("\nHay alguien en esta casilla\n");
                        printf("\n%s, tienes %d puntos de accion, que deseas hacer?\n", t1->Jug->nombre ,t1->Jug->ptAccion);
                        printf("\nElegir otra opcion (1), ceder el turno (0): ");
                        scanf("%d", &seguir1);
                    }
                    else if(aceptar == 1 && t1->Jug->ptAccion<puntos){
                        printf("No te alcanzan los puntos de accion, que deseas hacer?");
                        printf("\nElegir otra opcion (1), ceder el turno (0): ");
                        scanf("%d", &seguir1);
                    }
                }

                else if(h==5){///Usar Habilidad
                    int k;
                    escribeListaH(t1->Jug->habilidad);
                    printf("\nQue habilidad quieres usar? Opcion: ");
                    scanf("%d",&k);
                    printf("En que casilla quieres utilizar la habilidad?:"); printf(" X = "); scanf("%d",&x); printf("Y = "); scanf("%d",&y);
                    puntos = calculaPuntos(t1->Jug->posX, x, t1->Jug->posY, y);
                    usarHabilidad(t1->Jug->habilidad, x, y, t1->Jug->posX, t1->Jug->posY, puntos, t1->Jug->ptAccion,t1->Jug->ptEnergia,k);
                    printf("\nElegir otra opcion (1), ceder el turno (0): ");
                    scanf("%d", &seguir1);
                }

                else if(h==6){///Usar item
                    int k;
                    if (esVacia(t1->Jug->inventario))printf("No posees NADA en tu inventario\n");
                    else{
                        Item a = top(t1->Jug->inventario);
                        printf("%s\n",a->nombre);
                        printf("Deseas utilizar este Item?\1)Si\n2)No");
                        scanf("%d",&k);
                        if(k==1){
                            printf("En donde quieres utilizar el Item?:"); printf(" X = "); scanf("%d",&x); printf("Y = "); scanf("%d",&y);
                            puntos = calculaPuntos(t1->Jug->posX, x, t1->Jug->posY, y);
                            if(top(t1->Jug->inventario)->rango>puntos && t1->Jug->ptAccion>top(t1->Jug->inventario)->costo){
                                usarItem(top(t1->Jug->inventario), x, y);
                                pop(t1->Jug->inventario);
                            }
                            else{
                                printf("No te alcanzan los puntos de accion, que deseas hacer?");
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

                else if(h==8) {///Mostrar inventario

                }
                else if(h==9){///Mostrar estadísticas
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

        if(La == NULL) printf("\n\nGana el equipo del jugador 1\n");
        if(Lb == NULL) printf("\n\nGana el equipo del jugador 0\n");
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
    a = inicio(habilidades);

    ListaP L0 = newListaP();
    for(int i=0;i<a;i++){
        insertaPersonaje(Jugador[0][i], &L0); ///Insertamos los personajes del primer jugador en una lista
    }

    ListaP L1 = newListaP();
    for(int i=0;i<a;i++){
        insertaPersonaje(Jugador[1][i], &L1); ///Insertamos los personajes del segundo jugador en otra lista
    }

    printf("\nIniciales de los personajes del jugador 0: "); escribeListaP(L0); ///Esta función presenta errores al momento de imprimir,
    printf("\nIniciales de los personajes del jugador 1: "); escribeListaP(L1); ///es posible que haya que hacer una limpieza de buffer.
    printf("\n");

    imprimeTerreno();
    turno(L0,L1);///Enviamos ambas listas para empezar a asignar los turnos a cada jugador
}
