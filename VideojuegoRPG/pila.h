#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef struct nodo {
    int val;
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
int top(Pila p){
    return p->val;
}

///Pre: Pila no vacía p
void pop(Pila *p){
    Nodo *q = *p;
    *p = (*p)->sig;
    free(q);
}

///Pre: True (Ninguna)
void push(int x, Pila *p){
    Nodo *q = malloc(sizeof(Nodo));
    q->val = x;
    q->sig = *p;
    *p = q;
}

#endif // PILA_H_INCLUDED
