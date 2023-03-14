#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define TAM 50
#include <iostream>
using namespace std;
class Pila{
private:
    char datos[TAM];
    int ult;
    bool inserta(char , int);
    char elimina(int);
    char recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
public:
    Pila():ult(-1){}
    bool vacia()const;
    bool llena()const;
    int buscar(char);
    bool push(char);
    char pop();
    char top()const;
};

char Pila::top()const{
    return datos[ult];
}

char Pila::pop(){
    char valor[100];
    if(vacia()){
        cout<<"Pila Vacia";
    }
    else{
        return elimina(ultimo());
    }
}

bool Pila::push(char elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem,ultimo()+1);
    }
    return true;
    cout<<elem;
}

int Pila::buscar(char elem){
    int i=0;
    while(i<=ult){
        if(elem ==datos[i]){
            return i;
        }
        i++;
    }
    return -1;
}

void Pila::imprime()const{
    if(!vacia()){
        char x;
        for(int i=0; i<=ult; i++){
            x=datos[i];
            std::cout<<x<<std::endl;
        }
    }
}

bool Pila::vacia()const{
    return ult==-1;
}
bool Pila::llena()const{
    return ult==TAM-1;
}

bool Pila::inserta(char elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

char Pila::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return datos[i];
}

char Pila::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar excPostfijations
    }
    else{
       return datos[pos];
    }
}

int Pila::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}
int Pila::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}


#endif // PILA_H_INCLUDED
