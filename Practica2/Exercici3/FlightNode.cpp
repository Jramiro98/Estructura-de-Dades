/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FlightNode.cpp
 * Author: Jramiro
 * 
 * Created on March 11, 2019, 1:18 PM
 */

#include "FlightNode.h"

FlightNode::FlightNode(Flight* f) {
    this->_element = f;
    this->_next=nullptr;
}
FlightNode::FlightNode(const FlightNode& orig) {

}
FlightNode::FlightNode() {

}
FlightNode::~FlightNode() {
    //this->setNext(nullptr);
    delete _next;
}

Flight* FlightNode::getElement() const {
    return this->_element;
}
    
FlightNode* FlightNode::getNext(){
    return this->_next;
}

void FlightNode::setNext(FlightNode* n){
    this->_next=n;
}

void FlightNode::print() const {
    cout << this->_element->getIdentificador() << "," << this->_element->getOrigen() << "," << this->_element->getDesti() << "," << this->_element->getHora();
}
