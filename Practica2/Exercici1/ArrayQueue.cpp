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

#include "ArrayQueue.h"
#include "iostream"
using namespace std;


ArrayQueue::ArrayQueue(const int _max_size) {
    size=0;
    this->_max_size=_max_size;
    _data.reserve(_max_size);
    _data=vector<int>();
    cout<<"Estructura creada"<<endl;
}

ArrayQueue::~ArrayQueue() {
    
}

void ArrayQueue::enqueue(const int key){
    if (isFull()){
        string error="EXCEPTION: L'estructura està plena";
        throw (error);
    }
    else{
        _data[size]=key;
        size++;
    }
    cout<<"Element "<<key<<" agregat"<<endl;
}
void ArrayQueue::dequeue(){
    int front=getFront();
    if (isEmpty()){
        string error="EXCEPTION: L'estructura està buida";
        throw error;
    }
    else{
        for(int i=0; i<size;i++){
            _data[i]=_data[i+1]; 
        }
        _data[size]=NULL;
        size--;
    }
        cout<<"Element "<<front<<" eliminat"<<endl;

}

bool ArrayQueue::isFull(){
    return size==_max_size;;
}

bool ArrayQueue::isEmpty(){
    return size==0;
}

void ArrayQueue::print(){
    
        cout<<"[";
        for(int i =0;i<size;i++){
            if(size-1==i)
                cout<<_data[i];
            else
            cout << _data[i] << ",";
        }
        cout<<"]"<<endl;
    }


const int  ArrayQueue::getFront(){
    if (isEmpty()){
        string error= "EXCEPTION: L'estructura està buida";
        throw error;
    }
    else 
        return _data[0];
    
}
