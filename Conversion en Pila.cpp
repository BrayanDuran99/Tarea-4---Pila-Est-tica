#include <iostream>
#include <string>
#include "Pila.h"
using namespace std;

void Conversion(char, char);

void Conversion(char Infija[], char Postfija[]){
        Pila pa;
        int i=0, j=0;
            while(Infija[i] != '\0'){
                if(Infija[i] >= 'a' && Infija[i] <= 'z' || Infija[i]>='A' && Infija[i] <= 'Z'){
                    Postfija[j] = Infija[i];
                    i++;
                    j++;
                }
                else
                    if(Infija[i]=='('){
                        pa.push(Infija[i]);
                        i++;
                    }
                    else
                        if(Infija[i]==')'){
                            while( pa.top() != '('){
                                Postfija[j]= pa.pop();
                                j++;
                            }
                            if(pa.top() == '('){
                                pa.pop();
                            }
                            i++;
                        }
                        else
                            if(Infija[i]=='+' || Infija[i]=='-' || Infija[i]=='*' || Infija[i]=='/'){
                                if(Infija[i]=='+' || Infija[i] == '-'){
                                    while(!pa.vacia() && pa.top() != '('){
                                        Postfija[j]=pa.pop();
                                        j++;
                                    }
                                    pa.push(Infija[i]);
                                    i++;
                                }
                                else{
                                    if(Infija[i]=='*' || Infija[i]=='/'){
                                        while(!pa.vacia() && pa.top() != '(' && (pa.top()=='*'|| pa.top()=='/')){
                                            cout<<pa.pop();
                                            Postfija[j]=pa.pop();

                                            j++;
                                        }
                                        pa.push(Infija[i]);
                                        i++;
                                    }
                                }

                            }
                            else{
                                cout<<"CARACTER INVALIDO"<<endl;
                                Infija[i] = '\0';
                            }
            }
            while(!pa.vacia()){
                Postfija[j]=pa.pop();
                j++;
            }
       Postfija[j] = '\0';
}

int main(){
    Pila MiPila;
    int Resp, i, j=0, ptr=0;
    char Infija[TAM], Postfija[TAM];
    cout<<"A continuacion ingresa la notacion a convertir:\n";
    cin>>Infija;
    Conversion(Infija, Postfija);
    cout<< "\nLa cadena infija: \t"  << Infija << endl;
    cout << "\nConvertida en postfija es: \t"  << Postfija << endl;
return 0;
}
