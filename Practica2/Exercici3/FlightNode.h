/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FlightNode.h
 * Author: Jramiro
 *
 * Created on March 11, 2019, 1:18 PM
 */

#ifndef FLIGHTNODE_H
#define FLIGHTNODE_H
#include "Flight.h"

class FlightNode {
public:
    FlightNode();
    FlightNode(Flight* f);
    FlightNode(const FlightNode& orig);
    virtual ~FlightNode();
    Flight* getElement()const;
    FlightNode* getNext();
    void setNext(FlightNode* n);
    void print()const;
private:
    Flight* _element;
    FlightNode* _next;

};

#endif /* FLIGHTNODE_H */

