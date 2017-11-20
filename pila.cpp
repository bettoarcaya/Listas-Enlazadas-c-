#include <iostream>
#include "nodo.cpp"
using namespace std;


/*class pila{

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
                cout << pil[aux--] << endl;
            }
        }

};
*/
