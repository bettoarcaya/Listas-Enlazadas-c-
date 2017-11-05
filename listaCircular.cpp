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


class listaCircular{ //lista doble circular

    nodoDoble * Sentinel;

    public:
        listaCircular(){
            Sentinel = new nodoDoble();
            Sentinel->fijarProximo(Sentinel);
            Sentinel->fijarPrevio(Sentinel);
        }

        void agg(nodoDoble * x){

            x->fijarProximo(Sentinel->obtenerProximo());
            Sentinel->obtenerProximo()->fijarPrevio(x);
            Sentinel->fijarProximo(x);
            x->fijarPrevio(Sentinel);

        }

        nodoDoble * buscar(int k){
            nodoDoble * aux = Sentinel->obtenerProximo();

            while(aux != Sentinel && aux->obtenerDato() != k){
                aux = aux->obtenerProximo();
            }

            return aux;
        }

        void eliminar(int k){

            nodoDoble * aux = Sentinel->obtenerProximo();
            while(aux != Sentinel && aux->obtenerDato() != k){
                aux = aux->obtenerProximo();
            }

            if(aux != Sentinel){
                aux->obtenerPrevio()->fijarProximo(aux->obtenerProximo());
                aux->obtenerProximo()->fijarPrevio(aux->obtenerPrevio());
            }

        }

};

