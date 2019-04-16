/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jramiro
 *
 * Created on 8 / d’abril / 2019, 15:46
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
#include <cstdlib>
#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc, char** argv) {

    BST<int> *t= new BST<int>();
    int testArray[]= {2,0,8,45,76,5,3,40};
    for(int i=0;i<8;i++){
        t->insert(testArray[i]);
    }
    t->showPreorder();
    t->showInorder();
    t->showPostorder();
    t->showLeafNodes();
    t->~BST();
    return 0;
}


