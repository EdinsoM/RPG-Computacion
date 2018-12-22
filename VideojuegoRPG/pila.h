#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED


typedef struct it{
    char *nombre;//1
    int costo;//funcion efecto
    int n;//este entero definira el case de la
    int rango;
    ///void (*efecto)(int,int);
}It;

typedef It* Item;

typedef struct nodo {
    Item i;
    struct nodo* sig;
} Nodo;

typedef Nodo* Pila;

Pila newPila(){// Crea una pila vacía
    return NULL;
}

int esVacia(Pila p){
    return p == NULL;
}

///Pre: Pila no vacia, p->sig null
Item top(Pila p){
    return p->i;
}

///Pre: Pila no vacía p
void pop(Pila *p){
    Nodo *q = *p;
    *p = (*p)->sig;
    free(q);
}

///Pre: True (Ninguna)
void push(Item x, Pila *p){
    Nodo *q = malloc(sizeof(Nodo));
    q->i = x;
    q->sig = *p;
    *p = q;
}

///  ///   ///  ///  ///  Lista del Terreno ///  ///  ///  ///  ///

typedef Nodo* Lista;

Lista newList(){
    /*Lista p = malloc(sizeof(Nodo));
    p->i = NULL; p->sig = NULL;*/
    return NULL;
}

Item quitardelista(Lista *L){
    if(*L == NULL){
        printf("\nNo hay nada en el terreno");
        return NULL;
    }                                  /// No está imprimiendo
    else {
        Nodo *q = *L;
        *L = (*L)->sig;
        Item j = q->i;
        free(q);
        return j;
        /*Nodo *q = *L;
        q->sig = NULL;
        *L = (*L)->sig;
        return q;*/
    }
}

void AgregaLista(Item x, Lista *L){
    Nodo *a = malloc(sizeof(Nodo));
    a->i = x;
    a->sig = *L;
    *L = a;
}

void escribeLista(Lista L){
    int k = 1;
    if(L != NULL){
        while (L->sig != NULL){
        printf("%d.- %s\n", k,(L->i)->nombre);
        L = L->sig;
        k++;
        }
    printf("%d.- %s\n", k,(L->i)->nombre);
    }
}

///    ///  ///  ///  ///  Pila Inventario  ///  ///  ///  ///  ///

Pila newPila2(){
    Pila p = malloc(sizeof(Nodo));
    p->i=NULL;
    p->sig = NULL;
    return p;

}
int esVacia2(Pila p){
    return p->sig == NULL;
}
Item top2(Pila p){
    if (p->sig != NULL) return (p->sig)->i;
    else return NULL;
}
void pop2(Pila *p){
    Nodo* q = (*p)->sig;
    (*p)->sig = q->sig;
    free(q);
}
void push2(Item x, Pila *p){
    Nodo* q = malloc(sizeof(Nodo));
    q->i = x;
    q->sig = (*p)->sig;
    (*p)->sig = q;
}

#endif // PILA_H_INCLUDED
