/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flight.h
 * Author: Jramiro
 *
 * Created on March 11, 2019, 1:21 PM
 */

#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>

using namespace std;

class Flight {
public:
    Flight();
    Flight(string identificador, string origen, string desti,string hora);
    Flight(const Flight& orig);
    virtual ~Flight();
    string getIdentificador();
    void setIdentificador(string identificador);
    string getOrigen();
    void setOrigen(string origen);
    string getDesti();
    void setDesti(string desti);
    string getHora();
    void setHora(string hora);
    void toString();
private:
    string identificador, desti, origen,hora;
};

#endif /* FLIGHT_H */

