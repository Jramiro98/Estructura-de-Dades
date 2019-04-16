/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeTree.h
 * Author: Jramiro
 *
 * Created on 8 / d’abril / 2019, 15:46
 */

#include <iostream>
#ifndef NODETREE_H
#define NODETREE_H


template <class Type>
class NodeTree{
    public:
        NodeTree(const Type& data);//Constructor amb paràmetres
        NodeTree(const NodeTree& orig);//Constructor còpia
        virtual ~NodeTree(); // destructor 
        /*Consultors*/
        NodeTree<Type>* getRight() const; //Retorna el fill dret
        NodeTree<Type>* getLeft() const; //Retorna el fill esquerre
        NodeTree<Type>* getParent() const; //Retorna el pare
        bool hasRight() const;//Retorna true si te fill esquerre
        bool hasLeft() const;//Retorna true si te fill dret
        bool isRoot() const;//Retorna true si és l'arrel
        bool isExternal() const;//Retorna true si es un node extern
        const Type& getElement() const;  //Retonra el element
        /*Modificadors*/
        void setData(const Type& data); //Setter de la data
        void setRight(NodeTree<Type>* newRight); //Setter del fill esquerre
        void setLeft(NodeTree<Type>* newLeft); //Setter del fill dret
        void setParent(NodeTree<Type>* newParent); //Setter del pare
    private:
        NodeTree<Type>* pParent;
        NodeTree<Type>* pLeft;
        NodeTree<Type>* pRight;
        Type data;
        
};

//Constructor sense elements
template<class Type>
NodeTree<Type>::NodeTree(const Type& data){
    pParent=nullptr;
    pLeft=nullptr;
    pRight=nullptr;
    this->data=data;
    
}
//Constructor amb còpia
template <class Type>
NodeTree<Type>::NodeTree(const NodeTree& orig){
    data=orig.getElement();
    pRight=orig.getRight();
    pLeft=orig.getLeft();
    pParent=orig.getParent();

}   
//Destructor
template<class Type>
NodeTree<Type>::~NodeTree(){
    pParent=nullptr;
    delete pParent;
    pLeft=nullptr;
    delete pLeft;
    pRight=nullptr;
    delete pRight;
}
//Retorna el fill dret
template <class Type>
NodeTree<Type>* NodeTree<Type>::getRight() const{
    return pRight;
}
//Retorna el fill esquerre
template <class Type>
NodeTree<Type>* NodeTree<Type>::getLeft() const{
    return pLeft;
}

//Retorna el pare
template <class Type>
NodeTree<Type>* NodeTree<Type>::getParent() const{
    return pParent;
}

//Retorna true si té fill dret
template <class Type>
bool NodeTree<Type>::hasRight() const{
    return pRight!=nullptr;
}

//Retorna true si té fill esquerre
template <class Type>
bool NodeTree<Type>::hasLeft() const{
    return pLeft!=nullptr;
}

//Retorna true si el node es arrel
template <class Type>
bool NodeTree<Type>::isRoot() const{
    return pParent==nullptr;
}
//Retorna true si no te fill esquerra i dret es a dir que es extenr
template <class Type>
bool NodeTree<Type>::isExternal() const{
    return (!hasLeft() && !hasRight());
}

//retorna el element que té el node
template <class Type>
const Type& NodeTree<Type>::getElement() const{
    return data;
}


//setter de data
template <class Type>
void NodeTree<Type>::setData(const Type& data){
    this->data=data;
}

//setter del fill dret
template<class Type>
void NodeTree<Type>::setRight(NodeTree<Type>* newRight){
    pRight=newRight;
}

//setter del fill esquerra
template <class Type>
void NodeTree<Type>::setLeft(NodeTree<Type>* newLeft){
    pLeft=newLeft;
}

//setter del pare
template <class Type>
void NodeTree<Type>::setParent(NodeTree<Type>* newParent){
    pParent=newParent;
}

#endif /* NODETREE_H */

