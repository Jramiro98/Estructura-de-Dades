/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jramiro
 *
 * Created on February 25, 2019, 1:19 PM
 */

#include <cstdlib>
#include <vector>
#include <fstream>

#include "LinkedQueue.h"
#include "Flight.h"


using namespace std;

/*
 * 
 */

#include <cstdlib>
#include <vector>

#include "LinkedQueue.h"

using namespace std;

/*
 * 
 */

int menuOpcions(){
    int opcio = 0;
    std::vector<string> options(5);
    options[0] = "Llegir un fitxer amb les entrades de vols";
    options[1] = "Eliminar un vol";
    options[2] = "Inserir vol";
    options[3] = "Imprimir cua de vols";
    options[4] = "Sortir";
    
    cout << "\nHola, que vols fer?\n" << endl;
    for(int i = 0; i<options.size(); i++){
        cout << i+1 << ". " << options[i] << endl;
    }
    cin >> opcio;
    return opcio;
}

void opcioCarregarFitxer(LinkedQueue* queue){
    ifstream fitxer("flights.csv");
    string identificador, origen, desti, hora;    
    while(!fitxer.eof()){
        getline(fitxer, identificador, ',');
        getline(fitxer, origen, ',');
        getline(fitxer, desti, ',');
        getline(fitxer, hora, '\n');
        try{
            Flight* f= new Flight(identificador,origen,desti,hora);
            queue->enqueue(f);
        }catch(int e){
            cout << "No s'ha pogut afegir el vol" << endl;
        }
    }
}


int main(int argc, char** argv) {
    
   
    int opcio=0;
    string identificador, desti,origen,hora;
    LinkedQueue queue;
    do{
        opcio=menuOpcions();
        switch(opcio){
            case 1:
                try{
                    opcioCarregarFitxer(&queue);
                }catch(string error){ 
                    cout<<error<<endl;
                }
                break;
                
            case 2:
                try{
                    queue.dequeue();
                }catch(string error){
                    cout<<error<<endl;
                    break;
                }
                break;  
            case 3://cas inserir vols
                cout << "Introdueix el id del vol" << endl;
                cin >> identificador;
                cout << "Introdueix l'origen del vol" << endl;
                cin >> origen;
                cout << "Introdueix el desti del vol" << endl;
                cin >> desti;
                cout << "Introdueix l'hora del vol" << endl;
                cin >> hora;
                try{
                    Flight* f = new Flight(identificador, origen, desti, hora);  
                    queue.enqueue(f);
                }catch(string error){
                    cout<<error<<endl;
                    break;
                }
                break;
            case 4:
                queue.print();
                break;
            case 5:
                cout<<"Adeu"<<endl;
                break;
            default:
                cout<<"\nHas introduit una opció incorrecta"<<endl;
        }
    }while(opcio!=5);
    return 0;
}

/*Tal i com tinc implementat ara el programa quan escolleixo la opció de afegir els vols mitjançant un fitxer els afegeix tots correctament
 menys el primer que no se per quin motiu em posa una , abans de el seu id. */
