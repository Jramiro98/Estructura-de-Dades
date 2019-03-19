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

#include "LinkedQueue.h"

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
    options[0] = "Inserir element a la cua";
    options[1] = "Treure element de la cua";
    options[2] = "Consultar el primer element";
    options[3] = "Imprimir tot el contingut de la LinquedQueue";
    options[4] = "Sortir";
    
    cout << "\nHola, que vols fer?\n" << endl;
    for(int i = 0; i<options.size(); i++){
        cout << i+1 << ". " << options[i] << endl;
    }
    cin >> opcio;
    return opcio;
}
void casProva1(){
    //Cas de prova 1:
    cout<<"Cas de prova 1:"<<endl;
    LinkedQueue<int> *prova1 = new LinkedQueue<int>();
    try{
        prova1->enqueue(10);
    }catch(string error){
        cout << error << endl;
    }try{
        prova1->enqueue(20);
    }catch(string error){
        cout << error << endl;
    }try{
        prova1->enqueue(30);
    }catch(string error){
        cout << error << endl;
    }try{
        prova1->print();
    }catch(string error){
        cout << error << endl;
    }try{
        prova1->dequeue();
    }catch(string error){
        cout << error << endl;
    }try{
        prova1->enqueue(40);
    }catch(string error){
        cout << error << endl;    
    }try{
        prova1->print();
    }catch(string error){
        cout << error << endl;
    } 
}
void casProva2(){
    //Cas de prova 2:
    cout<<"Cas de prova 2:"<<endl;
    LinkedQueue<int> *prova2 = new LinkedQueue<int>();
    try{
        prova2->enqueue(10);
    }catch(string error){
        cout << error << endl;
    }try{
        cout<<prova2->getFront()<<endl;
    }catch(string error){
        cout << error << endl;
    }try{
        prova2->enqueue(20);
    }catch(string error){
        cout << error << endl;
    }try{
        prova2->enqueue(30);
    }catch(string error){
        cout << error << endl;
    }try{
        prova2->print();
    }catch(string error){
        cout << error << endl;
    }try{
        prova2->dequeue();
    }catch(string error){
        cout << error << endl;
    }try{
        cout<<prova2->getFront()<<endl;
        
    }catch(string error){
        cout << error << endl;
    } try{
        prova2->dequeue();
    }catch(string error){
        cout << error << endl;   
    } try{
        prova2->dequeue();
    }catch(string error){
        cout << error << endl; 
    } try{
    prova2->dequeue();
    }catch(string error){
        cout << error << endl;    
    }try{
        prova2->print();
    }catch(string error){
        cout << error << endl;
    } 
}
int main(int argc, char** argv) {
    
    casProva1();
    casProva2();
    int opcio=0;
    int element;
    LinkedQueue<int> *queue = new LinkedQueue<int>();
    do{
        opcio=menuOpcions();
        switch(opcio){
            case 1:
                cout<<"Quin element vols inserir?"<<endl;
                cin>>element;
                try{
                    queue->enqueue(element);
                
                }catch(string error){
                    cout<<error<<endl;
                    break;
                }
                break;
            case 2:
                try{
                    queue->dequeue();
                }catch(string error){
                    cout<<error<<endl;
                    break;
                }
                break;  
            case 3:
                try{
                cout<<queue->getFront()<<endl;   
                }catch(string error){
                    cout<<error<<endl;
                    break;
                }
                break;
            case 4:
                queue->print();
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
