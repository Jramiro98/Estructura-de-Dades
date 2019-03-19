/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flight.cpp
 * Author: Jramiro
 * 
 * Created on March 11, 2019, 1:21 PM
 */

#include "Flight.h"

Flight::Flight() {
    identificador="";
    origen="";
    desti="";
    hora="";
}

Flight::Flight(string identificador, string origen, string desti,string hora){
    this->identificador=identificador;
    this->origen=origen;
    this->desti=desti;
    this->hora=hora;
}
Flight::Flight(const Flight& orig) {
}

Flight::~Flight() {
}

string Flight::getIdentificador(){
    return identificador;
}

void Flight::setIdentificador(string identificador){
    this->identificador=identificador;
}

string Flight::getOrigen(){
    return origen;
}

void Flight::setOrigen(string origen){
    this->origen=origen;
}

string Flight::getDesti(){
    return desti;
}

void Flight::setDesti(string desti){
    this->desti=desti;
}

string Flight::getHora(){
    return hora;
}

void Flight::setHora(string hora){
    this->hora=hora;
}
void Flight::toString(){
    cout<<"Identificador: "<<identificador<< " origen: "<< origen <<" destí: "<< desti << " hora: "<<hora<<endl;
    
}
