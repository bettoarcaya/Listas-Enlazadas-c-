
#include<iostream>

using namespace std;
//    const int max = 5;
class cola{


    int primero, ultimo, n, cnt;
    int col[5];

    public:
        cola(){
            primero = ultimo = 0;
        }
        bool colaLLena(){
            if(((ultimo + 1) % 5) == primero){
                return true;
            }
            return false;
        }

        bool colaVacia(){
            if( ultimo == primero){
              return true;
            }
            return false;
        }
        void agg(int x){
            if(!colaLLena()){
                col[ultimo] = x;
                ultimo = (ultimo + 1) % 5;
            }else{
                cout << "cola llena" << endl;
            }

        }

        int extraer(){
            if(!colaVacia()){
                n = col[primero];
                primero = (primero + 1) % 5;
                return n;
            }

            return 0;
        }
        void mostrar(){
            int aux = primero;
            while( !colaVacia() && aux != ultimo ){
                cout << col[aux] << endl;
                aux = (aux + 1) % 5;
            }

        }
};
