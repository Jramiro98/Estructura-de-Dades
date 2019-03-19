/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: Jramiro
 *
 * Created on February 25, 2019, 1:20 PM
 */
#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
/*Classe node, la qual conté tots els atributs i mètodes que pertanyen als nodes, la classe està feta
 * com a template. 
 * element és un atribut on es guardà l'element que volem afegir
 * next apunta a la direcció del següent element
 */
class Node{
public:
    Node<T>(T element);//constructor del node
    virtual ~Node<T>();//destructor del node
    T getElement();//retorna l'element que ha guardat
    Node<T>* getNext();//retorna l'adreça del seguent node
    void setNext(Node<T>* n);//modifica l'adreça del següent node    
    void setElement(T element);

private:
    T element;
    Node<T>* next;
};

template <class T>
Node<T>::Node(T element) {
    this->element=element;
    next=nullptr;
}

template <class T>
Node<T>::~Node<T>(){
    this-> setNext(0);
    delete next;
}

template <class T>
T Node<T>::getElement(){
    return this->element;
}
template<class T>
void Node<T>::setElement(T element){
    this->element=element;
}

template <class T>
Node<T>* Node<T>::getNext(){
    return this->next;
}
template <class T>
void Node<T>::setNext(Node<T>* next){
    this->next=next;
}


#endif /* NODE_H */

