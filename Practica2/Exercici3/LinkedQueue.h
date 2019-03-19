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

#include <stdexcept>

#include "FlightNode.h"
using namespace std;

class LinkedQueue {
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue& orig);
    virtual ~LinkedQueue();
    void enqueue(Flight* key);
    void dequeue();
    bool isEmpty();
    void print();
    const FlightNode* getFront();

private:
    int _size;
    FlightNode* _front;
    FlightNode* _rear;
};

#endif /* LINKEDQUEUE_H */