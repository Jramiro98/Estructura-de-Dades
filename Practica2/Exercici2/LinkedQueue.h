/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedQueue.h
 * Author: Jramiro
 *
 * Created on February 25, 2019, 1:19 PM
 */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "Node.h"
#include <iostream>
using namespace std;

template <class Element>
class LinkedQueue {
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue<Element>& queue);
    virtual ~LinkedQueue();
    void enqueue(const Element & element);
    void dequeue();
    bool isEmpty();
    void print();
    const Element& getFront();
private:
    int _size;
    Node<Element> *_front;
    Node<Element> *_rear;
   
};
template <class Element>
LinkedQueue<Element>::LinkedQueue(){
    _size=0;
}
template <class Element>
LinkedQueue<Element>::LinkedQueue(const LinkedQueue<Element>& queue) {//no acaba de funcionar correctament
    _front = new Node<Element>(NULL);
    _rear = new Node<Element>(NULL);
    _front->setNext(_rear);
    Node<Element> *aux = queue->_front->getNext();
    Node<Element> *node = new Node<Element>(aux->getElement());
    int i=0;
    while(i<queue._size()){
        queue->enqueue(node);
        node=aux->getNext();
        i++;
    }
   
}

template <class Element>
LinkedQueue<Element>::~LinkedQueue() {
    if (!isEmpty()) {
        Node<int>* iterador = _front;
        while(iterador != _rear) { 
            iterador = iterador->getNext();
            delete this-> _front;
            this-> _front = iterador;
        }
        delete iterador;
    }
    delete this-> _front;
    delete this-> _rear;
}

template <class Element>
void LinkedQueue<Element>::enqueue(const Element& element){
    Node<Element>* aux= new Node<Element>(element);
    if (this->isEmpty()){
        _front=aux;

    }
    else{
        _rear->setNext(aux);
    }  
    this->_rear=aux;
    _size ++;
    cout<<"Element "<<element<<" agregat"<<endl;
}


template <class Element>
void LinkedQueue<Element>::dequeue(){
    if (isEmpty()){
        string error="EXCEPTION: L'estructura està buida";
        throw error;
    }
    else{
        Node <Element>* aux = new Node <Element>(0);
        aux->setNext(this->_front->getNext());
        cout<<"Element "<<_front->getElement()<<" eliminat"<<endl;
        delete this->_front;
        this->_front=aux->getNext();
        delete aux;
        _size --;   
    }
        

}

template <class Element>
bool LinkedQueue<Element>::isEmpty(){
    return _size==0;
}
template <class Element>
void LinkedQueue<Element>::print(){
    cout<<"[";
    if (!this-> isEmpty()) {
        Node<int>* it = this-> _front;
        while(it != this->_rear) {
            if(_size-1==it->getElement()){
                cout << it->getElement();
                it = it->getNext();
            }
            else{
                cout << it->getElement()<<",";
                it = it->getNext();    
                }
        }
        //Now we print rear
        cout << it->getElement();
    }
    cout<<"]"<<endl;;
}


template <class Element>
const Element& LinkedQueue<Element>::getFront(){
    if (isEmpty()){
        string error= "EXCEPTION: L'estructura està buida";
        throw error;
    }
    else
        return _front->getElement();
}


#endif /* LINKEDQUEUE_H */

