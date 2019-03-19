#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string nom;
    int opcio;
    string arr_options[]={"Sortir","Benvinguda"};
    cout<<"*** Inici ***\n";
    cout<<"Hola, com et dius?"<<endl;
    cin>>nom;
    do{
         cout<<"\nHola "<<nom<<", que vols fer?"<<endl;
         for(int i=0; i<sizeof(arr_options)/sizeof(*arr_options);i++){
             cout<<i+1<<"."<<arr_options[i]<<endl;
         }
        cin>>opcio;
        switch(opcio){
            case 1:
                cout<<"\nAdeu!"<<endl;
                break;
            case 2:
                cout<<"\nBenvigut/da a l'assignatura d'estructura de dades "<<nom<<endl;
                break;
            default:
                cout<< "\nHas introduit una opció incorrecta"<<endl;
                break;
                   
        }
    }while(opcio!=1);

  
    return 0;
}
/*
 * Al debuggar es crean la carpeta debug la cual conté els arxius .o del exercici, en el cas d'aquest exercici només es crea el
 * main.o
*/
