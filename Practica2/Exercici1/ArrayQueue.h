/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayQueue.h
 * Author: Jramiro
 *
 * Created on February 25, 2019, 11:32 AM
 */

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

class ArrayQueue{ 
private:
        int _max_size;
        int size;  
        std::vector<int> _data;
        
    public:
        
        ArrayQueue(const int _max_size);
        
        virtual ~ArrayQueue();
        
        void enqueue(const int key); // encuem un membre a la cua i retorna una excepció si no ha estat possible
        
        void dequeue();   // treu un element de la cua i retorna una excepció si no ha estat possible
        
        bool isFull (); // indica si la cua és plena
        
        bool isEmpty (); // indica si la cua és buida 
        
        void print(); // imprimeix tot el contingut de la cua 
        
        const  int getFront(); // consulta l'element de l'inici de la cua sense eliminar-lo i retorna una excepció si no ha estat possible
};

#endif /* ARRAYQUEUE_H */

