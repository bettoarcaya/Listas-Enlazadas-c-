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
            Sentinel->fijarPrevio(sentinel);
        }

        void agg(nodoDoble * x){



        }





};

