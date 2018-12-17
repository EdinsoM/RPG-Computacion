#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED


typedef struct it{
    char nombreI[32];//1
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



#endif // PILA_H_INCLUDED
