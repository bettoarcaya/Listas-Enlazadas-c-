// pilas_colas_listas.cpp: define el punto de entrada de la aplicación de consola.
//

#include<iostream>
#include "cola.cpp";
#include "pila.cpp";
#include "listaDoble.cpp"

using namespace std;


class nodo {
	int dato;
	nodo * proximo;


public:
	nodo() {
		proximo = NULL;
	}

	void fijar_dato(int x) {dato = x;}
	int obtener_dato() { return dato; }

	void fijar_proximo(nodo * x) { proximo = x; }
	nodo * obtener_proximo() { return proximo; }


};

class listaEnlazada{ //listas simples!

    nodo * inicio;

    public:
        void fijar_inicio(nodo * x){inicio = x;}
        nodo * obtner_inicio(){return inicio;}

        listaEnlazada(){inicio = NULL;}

        void insertar(nodo * x){
            if(inicio != NULL){
                x->fijar_proximo(inicio);
            }
            inicio = x;
        }

        void mostrar(){

            nodo * aux = inicio;
            while(aux != NULL){
                cout << aux->obtener_dato() << endl;
                aux = aux->obtener_proximo();
            }

        }

        nodo * buscar(int k){

            nodo * aux = inicio;
            while(aux != NULL && aux->obtener_dato() != k){
                aux = aux->obtener_proximo();
            }

            return aux;
        }

        void eliminar(int k){

            nodo * posterior = NULL;
            nodo * aux = inicio;

            while(aux != NULL && aux->obtener_dato() != k){
                posterior = aux;
                aux = aux->obtener_proximo();
            }
            if(aux != NULL){
                if(posterior != NULL){
                    posterior->fijar_proximo(aux->obtener_proximo());
                }else{
                    inicio = aux->obtener_proximo();
                }
            }else{
                cout << "el valor no se encuentra en la lista" << endl;
            }

            mostrar();
        }
};


int main(){
	int cnt, opc;
	int num;
	listaEnlazada * lista = new listaEnlazada();
    nodo * busqueda;
    cola * c = new cola();
    pila * p = new pila();

    listaDoble * listaD = new listaDoble();

    nodoDoble * n = new nodoDoble();
    nodoDoble * n1 = new nodoDoble();
    nodoDoble * n2 = new nodoDoble();
    nodoDoble * n3 = new nodoDoble();

    n->fijarDato(25);
    n1->fijarDato(5);
    n2->fijarDato(10);
    n3->fijarDato(40);

    listaD->agg(n);
    listaD->agg(n1);
    listaD->agg(n2);
    listaD->agg(n3);

    listaD->eliminar(25);

    /*while(opc != 0){
        cout<<"agregar elemento   >>> press 1"<<endl;
        cout<<"mostrar elementos  >>> press 2"<<endl;
        cout<<"buscar elemento    >>> press 3"<<endl;
        cout<<"eliminar elemento  >>> press 4"<<endl;
        cout<<"salir?             >>> press 0"<<endl;
        cin>>opc;

        if(opc == 1){
            cout << "introduzca un numero para ingresarlo a la lista" << endl;
            cin >> num;
            nodo * n = new nodo();
            n->fijar_dato(num);
            lista->insertar(n);
        }

        if(opc == 2){
            lista->mostrar();
        }

        if(opc == 3){
            cout << "introduzca el numero a buscar" << endl;
            cin >> num;
            busqueda = lista->buscar(num);
            if(busqueda != NULL){
                cout << busqueda->obtener_dato() << endl;
            }else{
                cout << "el numero no esta en la lista" << endl;
            }
        }

        if (opc == 4){
            cout << "introduzca el numero a eliminar" << endl;
            cin >> num;
            lista->eliminar(num);
        }

    }*/


	//getchar();

    return 0;
}
