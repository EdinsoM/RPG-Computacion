#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.h"
#include <math.h>



typedef struct nodoL{
    int val;
    struct nodoL *sig;
} nodoL;

typedef nodoL* Lista;

Lista newList(){
    return NULL;
}

typedef struct perso { //Creamos la estructura del personaje
    char nombre[16];
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
    g->nombre[16];
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    //g->jugador=q;
    g->dano=25;
    g->rango=1;
    g->armadura=40;
    g->evasion=25;
    g->velocidad=2;
    g->inventario=newPila();
    g->habilidades=newList();
    return g;
}
Personaje newPolitiCorrupto(){
    Personaje g = malloc(sizeof(Perso));
    g->nombre[16];
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    //g->jugador=q;
    g->dano=20;
    g->rango=2;
    g->armadura=0;
    g->evasion=10;
    g->velocidad=4;
    g->inventario=newPila();
    g->habilidades=newList();
    return g;
}
Personaje newMedicoCubano(){
    Personaje g = malloc(sizeof(Perso));
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    //g->jugador=q;
    g->dano=15;
    g->rango=1;
    g->armadura=0;
    g->evasion=10;
    g->velocidad=1;
    g->inventario=newPila();
    g->habilidades=newList();
    return g;
}
Personaje newProfesor(){
    Personaje g = malloc(sizeof(Perso));
    g->ptSalud=100;
    g->ptEnergia=30;
    g->ptAccion=20;
    //g->jugador=q;
    g->dano=15;
    g->rango=4;
    g->armadura=10;
    g->evasion=20;
    g->velocidad=3;
    g->inventario=newPila();
    g->habilidades=newList();
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
    Personaje *Jugador;
    //  enum Efecto efecto;
    // items Lista (Item);
} Ter;

typedef Ter* terreno; //terreno apunta a Ter

terreno newTerreno(){
    terreno t = malloc(sizeof(Ter));
    t -> Jugador = NULL;
    //t->Efecto=NULL;
   // t->item=NULL;
}terreno espacios[10][20];

//espacio[5][8]->Jugador=Jugador 1

void nuevoTerreno(){
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            espacios[i][j]= newTerreno();
        }
    }
}
//void terrenoPelea(){


//}

/*
void imprimirTerreno(){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<20;j++){
            if(espacios[i][j]->Jugador!=NULL){
                printf("%d",espacios[i][j]->Jugador->ptSalud);
            }
            else{
                if(espacios[i][j]->Item!=NULL){
                    printf("*");
                }
                else{
                    if(espacios[i][j]->Efecto!=NULL)printf("▓");
                    else printf("░");
                }
            }
        }
        printf("\n%d",i);
    }
}
*/
typedef struct nodoP{
    Personaje *Jugador;
    struct nodoP *sig;
} NodoP;

typedef NodoP* ListaP;

Lista newListP(){
    return NULL;
}

void swap(int *a,int *b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
/*
void moverseTerreno(int i, int j){
    int k, l;
    if(espacios[i][j]->Jugador->ptAccion> 0){
        printf("Casilla a la que quieras moverte\nColumna:");
        scanf("%d",k);
        printf("\nFila");
        scanf("%d",l);
        if((abs(k-i)<=espacios[i][j]->Jugador->ptAccion)&&(abs(l-j)<=espacios[i][j]->Jugador->ptAccion)){
            if(espacios[k][l]->Jugador==NULL){
                swap(&k,&i);
                swap(&l,&j);
            }else printf("Hay alguien en esa casilla");
        }else printf("No tienes sufiecientes puntos de accion");
    }
}
*/
/*
void qSortL(int a[],int l,int u){
    int i;
    if(l<u){
        int m=l;
        for(i=l+1;i<=u;i++){
            if(a[i]<a[l])swap(&a[++m],&a[i]);
        }
        swap(&a[l],&a[m]);
        qSortL(a,l,m-1);
        qSortL(a,m+1,u);
    }
}
void insertT(int x, Lista *L){
    Nodo*p=malloc(sizeof(Nodo)),*q=*L;
    p->val=x;
    p-sig=NULL;
    if(q==NULL)*L=p;
    else{while (q->sig != NULL)q=q->sig;
        q->sig=p;
    }

}

*/


void selectSort(ListaP *L){
    NodoP*p=L,*q,*pm;
    if(p!=NULL){
        while(p->sig!=NULL){
            q=p->sig;pm=p;
            while(q!=NULL){
                if( q->Jugador->velocidad  > pm->Jugador->velocidad)pm=q;
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

void main(){
    seleccionPersonaje();
    terrenoPelea();
}
