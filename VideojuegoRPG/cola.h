#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

///Modelo de representación
typedef struct nodoC {
    int val;
    struct nodoC* sig;
} NodoC;

typedef struct col {
    NodoC* alfa;
    NodoC* omega;
    int size;
} Col;

typedef Col* Cola;

///Pre: True;
Cola newCola(){
    Cola c = malloc(sizeof(Col));
    c->alfa = NULL;
    c->omega = NULL;
    return c;
}

///Pre: True
void queue(int x, Cola *c){ //Supongo que no lleva asterisco ya que no modificamos la lista
    NodoC* q = malloc(sizeof(NodoC));
    q->val = x;
    q->sig = NULL;
    if((*c)->omega != NULL) ((*c)->omega)->sig = q;
    else (*c)->alfa = q;
    (*c)->omega = q;
}

///Pre: !esVacia(c)
void dqueue(Cola *c){
    NodoC* q = (*c)->alfa;
    if((*c)->alfa == (*c)->omega) (*c)->omega = NULL;
    (*c)->alfa = q->sig;
    free(q);
}

int esVaciaC(Cola c){
    return (c->alfa == NULL && c->omega == NULL);
}

int first(Cola c){
    return (c->alfa)->val;
}

#endif // COLA_H_INCLUDED
