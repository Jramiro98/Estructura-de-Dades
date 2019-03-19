/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayQueue.cpp
 * Author: Jramiro
 * 
 * Created on February 25, 2019, 11:32 AM
 */

#include "LinkedQueue.h"
#include "iostream"
using namespace std;


LinkedQueue::LinkedQueue() {
    this->_size = 0;
    this->_front = nullptr;
    this->_rear = nullptr;
    cout << "Estructura creada" << endl;
}

LinkedQueue::LinkedQueue(const LinkedQueue& queue) {
    FlightNode * aux = queue._front;
    this->_front = nullptr;
    this->_rear = nullptr;
    this->_size = 0;
    while (aux) {
        FlightNode* aux2 = new FlightNode(aux->getElement());
        if (!this->_front) {
            this->_front = aux2;
        } else {
            this->_rear->setNext(aux2);
        }
        this->_rear = aux2;
        this->_size++;
        aux = aux->getNext();
    }
}   
   
LinkedQueue::~LinkedQueue() {
    FlightNode* aux = this->_front;
    FlightNode* nodeDelete;
    while (aux) {
        nodeDelete = aux;
        aux = aux->getNext();
        delete nodeDelete;
    }
    cout << "Estructura eliminada" << endl;
}

void LinkedQueue::enqueue(Flight* key) {
    FlightNode* aux = new FlightNode(key);
    if (this->isEmpty()) {
        this->_front = aux;
    } else {
        this->_rear->setNext(aux);
    }
    this->_rear = aux;
    cout << "Element agregat" << endl;
    this->_size++;
}


void LinkedQueue::dequeue() {
     if (isEmpty()){
        string error="EXCEPTION: L'estructura està buida";
        throw error;
    }
    else{
        this->_front = this->_front->getNext();
        this->_size--;  
    }
        

}

const FlightNode* LinkedQueue::getFront() {
 if (isEmpty()){
        string error= "EXCEPTION: L'estructura està buida";
        throw error;
    }
    else
        return _front;
}

bool LinkedQueue::isEmpty() {
    return _size==0;
}
void LinkedQueue::print() {
 FlightNode* aux = this->_front;
 cout<<"[";
    while (aux) {
        aux->print();
        aux = aux->getNext();
        if (aux)
            cout <<endl;
    }
    cout<<"]"<<endl;
}
