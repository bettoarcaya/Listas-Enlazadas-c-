#include <iostream>

using namespace std;

class nodoDoble{

    nodoDoble * proximo;
    nodoDoble * previo;
    int dato;

    public:
        nodoDoble(){ proximo = previo = NULL; }

        void fijarDato(int x){ dato = x; }
        int obtenerDato(){return dato;}

        void fijarProximo(nodoDoble * x){ proximo = x; }
        nodoDoble * obtenerProximo(){ return proximo; }

        void fijarPrevio(nodoDoble * x){ previo = x; }
        nodoDoble * obtenerPrevio() { return previo; }
};

class listaDoble{

    nodoDoble * inicio;

    public:
        listaDoble(){inicio = NULL;}


        void agg(nodoDoble * x){

            if(inicio != NULL){
               x->fijarProximo(inicio);
               inicio->fijarPrevio(x);
            }

            inicio = x;
        }

        nodoDoble * buscar(int k){

            nodoDoble * aux = inicio;
            while(aux != NULL && aux->obtenerDato() != k){
                aux = aux->obtenerProximo();
            }

            return aux;

        }

        void mostrar(){

            nodoDoble * aux = inicio;
            while(aux != NULL){
                cout << aux->obtenerDato() << endl;
                aux = aux->obtenerProximo();
            }
        }

        void eliminar(int k){

            nodoDoble * aux = inicio;
            while(aux != NULL && aux->obtenerDato() != k){
                aux = aux->obtenerProximo();
            }

            if(aux != NULL){
                nodoDoble * pre = aux->obtenerPrevio();
                nodoDoble * pro = aux->obtenerProximo();


                if(pre == NULL){
                    pro->fijarPrevio(pre);
                    inicio = pro;
                }
                if(pro == NULL){
                    pre->fijarProximo(pro);
                }
                if(pre != NULL && pro != NULL){
                    pre->fijarProximo(pro);
                    pro->fijarPrevio(pre);
                }

            }

            mostrar();

        }

};
