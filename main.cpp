// pilas_colas_listas.cpp: define el punto de entrada de la aplicación de consola.
//

#include<iostream>
#include "cola.cpp";
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

class pila{

    int primero;
    nodo * pil[5];


    public:
        pila(){primero = -1;}

        bool pilaVacia(){
            if(primero == -1){
                return true;
            }
            return false;
        }

        bool pilaLLena(){
            if((primero + 1) == 5){
                return true;
            }
            return false;
        }

        void agg(nodo * x){
            if(!pilaLLena()){
                primero++;
                pil[primero] = x;
            }else{
                cout << "la pila esta llena" << endl;
            }
        }

        nodo * extraer(){
            if(!pilaVacia()){
                nodo * n = pil[primero];
                primero--;
                return n;
            }
            cout << "la pila esta vacia" << endl;
        }

        void mostrar(){

            int aux = primero;
            while(!pilaVacia() && aux != -1){
                cout << pil[aux--]->obtener_dato() << endl;
            }
        }

};

class listaEnlazada{ //listas simples!

    nodo * inicio;

    public:
        void fijar_inicio(nodo * x){inicio = x;}
        nodo * obtner_inicio(){return inicio;}

        listaEnlazada(){inicio = NULL;}

        void insertar(nodo * x){

            nodo * aux = inicio;
            nodo * pre = NULL;

            //ingresar ordenadamente..
            while(aux != NULL && x->obtener_dato() > aux->obtener_dato()){
                pre = aux;
                aux = aux->obtener_proximo();
            }

            if(inicio != NULL){

                if(pre == NULL){
                    x->fijar_proximo(inicio);
                    inicio = x;
                }else if(aux == NULL){
                    pre->fijar_proximo(x);
                }else{
                    pre->fijar_proximo(x);
                    x->fijar_proximo(aux);
                }

            }else{
                inicio = x;
            }
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

        void agg(nodo * x){

            if(inicio != NULL){
                x->fijar_proximo(inicio);
            }
            inicio = x;

        }


        void invertir(){//invertir una lista simple
            pila * pil = new pila();
            nodo * aux = inicio;
            nodo * aux2;

            while(aux != NULL){
                pil->agg(aux);
                aux = aux->obtener_proximo();
            }

            aux = pil->extraer();
            inicio->fijar_dato(aux->obtener_dato());
            inicio->fijar_proximo(aux->obtener_proximo());
            //cout<<inicio->obtener_dato()<<endl;
            while(!pil->pilaVacia()){
                aux = pil->extraer();
                //cout<<aux2->obtener_dato()<<endl;
                aux2->fijar_dato(aux->obtener_dato());
                aux2->fijar_proximo(inicio);
                inicio = aux2;
            }

            mostrar();

        }
};


int main(){
	int cnt, opc;
	int num;
	listaEnlazada * lista = new listaEnlazada();
	listaDoble * listaD = new listaDoble();
    nodo * busqueda;
    nodoDoble * nd;
    cola * c = new cola();
    pila * p = new pila();

    while(opc != 0){
        cout<<"agregar elemento   >>> press 1"<<endl;
        cout<<"mostrar elementos  >>> press 2"<<endl;
        cout<<"buscar elemento    >>> press 3"<<endl;
        cout<<"eliminar elemento  >>> press 4"<<endl;
        cout<<"invertir lista     >>> press 5"<<endl;
        cout<<"salir?             >>> press 0"<<endl;
        cin>>opc;

        if(opc == 1){
            cout << "introduzca un numero para ingresarlo a la lista" << endl;
            cin >> num;
            nodo * n = new nodo();
            nodoDoble * nd = new nodoDoble();
            n->fijar_dato(num);
            nd->fijarDato(num);
            lista->insertar(n);
            //listaD->agg(nd);
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
        if(opc == 5){
            lista->invertir();
        }

    }


	//getchar();

    return 0;
}
