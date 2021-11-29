#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;
 
struct Punto{double x,y;};  
struct Nodo{
    Punto Punto;  
    Nodo *siguiente; 
};

void insertarNodoLista(Nodo *&lista, struct Punto );
void mostrarNodoLista(Nodo *&lista);
void borrarNodo(Nodo *&lista, struct Punto );
double GetPerimetro(Nodo *&lista);

int main(){
    Nodo *lista=NULL;
    Punto b;
    
    insertarNodoLista(lista,b={1,4});
    insertarNodoLista(lista,b={3,4});
    insertarNodoLista(lista,b={3,1});
    insertarNodoLista(lista,b={1,1});


    std::cout<<"El perimetro es:"<<GetPerimetro(lista)<<"\n";

    system("pause");
    return 0; 
};


void insertarNodoLista(Nodo *&lista, struct Punto punto){
    Nodo *new_nodo = new Nodo();
    new_nodo->Punto.x = punto.x;
    new_nodo->Punto.y = punto.y;
    Nodo *aux1=lista;
    Nodo *aux2;
    while ( aux1 != NULL ){
        aux2=aux1;
        aux1=aux1->siguiente;
    }
    if(lista==aux1){
        lista=new_nodo;
        new_nodo->siguiente=aux1;
    }else{
        aux2->siguiente=new_nodo;
        new_nodo->siguiente=aux1;
    }
    std::cout<<"El Vertice {x:"<<new_nodo->Punto.x<<",y:"<<new_nodo->Punto.y<<"} fue insertado exitosamente\n";
};

void mostrarNodoLista(Nodo *&lista){
    Nodo *actual=new Nodo();
    actual=lista;
    while (actual!=NULL){
    std::cout<<"El valor del Vertice es {x:"<<actual->Punto.x<<",y:"<<actual->Punto.y<<"}.\n";
    actual=actual->siguiente;
    }   
};

void borrarNodo(Nodo *&lista, struct Punto punto){ 
    Nodo *nodoBorrar = new Nodo();
    nodoBorrar->Punto.x = punto.x;
    nodoBorrar->Punto.y = punto.y;
    Nodo *aux1=lista;
    Nodo *anterior=NULL;
    while(aux1!=NULL && ( (aux1->Punto.x != (nodoBorrar->Punto.x)) &&  (aux1->Punto.y != (nodoBorrar->Punto.y)) )){
        anterior = aux1;
        aux1=aux1->siguiente;
    }
    if(aux1==NULL){
        std::cout<<"El Vertice no existe\n";}
    else if(anterior==NULL){
        lista=lista->siguiente;
        delete aux1;
        std::cout<<"El Vertice fue eliminado exitosamente\n";
    }
    else{
        anterior->siguiente=aux1->siguiente;
        delete aux1;
        std::cout<<"El Vertice fue eliminado exitosamente\n";
    }
} 


double GetPerimetro(Nodo *&lista){
    double res=0;
    Nodo *temp = lista;
    while(temp->siguiente != nullptr)
    {
        res += sqrt(pow(temp->Punto.x - temp->siguiente->Punto.x, 2) + 
                    pow(temp->Punto.y - temp->siguiente->Punto.y, 2));
        
        temp = temp->siguiente;
    }
    
    res += sqrt(pow(lista->Punto.x - temp->Punto.x, 2) + 
                pow(lista->Punto.y - temp->Punto.y, 2));
    
    return res;
}
