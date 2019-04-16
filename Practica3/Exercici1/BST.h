/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BST.h
 * Author: Jramiro
 *
 * Created on 8 / d’abril / 2019, 16:30
 */

#ifndef BST_H
#define BST_H

#include "NodeTree.h"

template <class Type> 
class BST{
    public:
        /*Constructors i Destructors*/
        BST();
        BST(const BST& orig); 
        virtual ~BST();
        /*Consultors*/
        int size() const;
        bool isEmpty() const;
        NodeTree<Type>*root();
        bool search(const Type& element);
        void showInorder() const;
        void showPreorder() const;
        void showPostorder() const;
        void showLeafNodes() const;
        /*Modificadors*/
        void insert(const Type& element);
    private:
        int size(NodeTree<Type>* p) const;
        void showPreorder(NodeTree<Type>* p) const;
        void showPostorder(NodeTree<Type>* p) const;
        void showInorder(NodeTree<Type>* p) const;
        void showLeafNodes(NodeTree<Type>* p)const;
        BST(NodeTree<Type>* p);
        void postDelete(NodeTree<Type>* p);
        
        /*Atributs*/
        NodeTree<Type>* pRoot;

};

//Constructor del arbre
template <class Type>
BST<Type>::BST(){
    pRoot = nullptr;
    std::cout<<"Arbre binari creat"<<std::endl;

}
//Constructor copia del arbre
template <class Type>
BST<Type>::BST(const BST& orig){
    if(orig.isEmpty()){
        std::cout<<"Arbre buit"<<std::endl;
    } else{
        NodeTree<Type>* temp = new NodeTree<Type>(orig.pRoot);
        pRoot = temp;
        BST(temp->getLeft());
        BST(temp->getRight());
        std::cout<<"Arbre copia creat"<<std::endl;
    }
}
//Mètode recursiu que ens ajuda a fer el arbre còpia
template <class Type>
BST<Type>::BST(NodeTree<Type>* p){
    if (p==NULL) 
        return;  
    else {
        NodeTree<Type>* temp = new NodeTree<Type>(*p);
        insert(temp);
        // cridem la funció pels dos fills 
        BST(temp->getLeft());
        BST(temp->getRight());
    }
}
//Destructor de l'arbre
template <class Type>
BST<Type>::~BST(){
    if(!isEmpty()){
        std::cout<<"Destruïnt arbre binari"<<std::endl;
        postDelete(pRoot);
        //pRoot=nullptr;
        //delete(pRoot);
    }
    std::cout<<"Arbre binari destruit"<<std::endl;   
}

//Mètode per a eliminar el node que li introduim com a paràmetre
template <class Type>
void BST<Type>::postDelete(NodeTree<Type>* p){
    if(p->getLeft()!=nullptr)
        postDelete(p->getLeft());
    if(p->getRight()!=nullptr)
        postDelete(p->getRight());
    std::cout<<"Eliminat node " << p->getElement() <<std::endl;
    delete(p);
}

template <class Type>
int BST<Type>::size() const{
    size(pRoot);
}

//Mètode per saber el tamany del arbre
template <class Type>
int BST<Type>::size(NodeTree<Type>* p) const{
    if(p == nullptr){
        return 0;
    }else if(p->isExternal()){
        return 1;
    }else{
        int a = size(p->getLeft());
        int b = size(p->getRight());
        return a+b+1;
    }
}

//Mètode que retorna true si l'arbre està buit
template <class Type>
bool BST<Type>::isEmpty() const{
    return pRoot==nullptr;
}
//Mètode que retorna l'arrel
template <class Type>
NodeTree<Type>* BST<Type>::root(){
    return pRoot;
}
//Mètode que retorna true si troba el  element que li introduim com a paràmetre dintre del arbre
template <class Type>
bool BST<Type>::search(const Type& element){
    bool trobat = false;
    bool end = false;
    NodeTree<Type>* temp = pRoot;
    while(!trobat && !end){
        if(!temp){
            end = true;
        }else if(temp->getElement() == element){
            trobat = true;
        }else if(temp->getElement() > element){
            temp = temp->getLeft();
        }else if(temp->getElement() <= element){
            temp = temp->getRight();
        }
    }
    return trobat;
}
//Mètode per a fer el printInorder del arbre
template <class Type>
void BST<Type>::showInorder() const{
     if(isEmpty()){
        std::cout << "Arbre buit" << std::endl;
    }else{
        std::cout<<"Inordre = { ";
        showInorder(pRoot);
        std::cout<<"}"<<std::endl;
    }
}
//Mètode recursiu per a fer el printInorder del arbre
template <class Type>
void BST<Type>::showInorder(NodeTree<Type>* p) const{
if (p==nullptr){
        std::cout<<"";
        
    }
    else{
        showInorder(p->getLeft());
        std::cout<<p->getElement()<<" ";
        showInorder(p->getRight());
    }
}
//Mètode per a fer el printPreorder del arbre
template <class Type>
void BST<Type>::showPreorder() const{
     if(isEmpty()){
        std::cout << "Arbre buit" << std::endl;
    }else{
        std::cout<<"Preordre = { ";
        showPreorder(pRoot);
        std::cout<<"}"<<std::endl;
    }
}
//Mètode recursiu per a fer el printPreorder del arbre
template <class Type>
void BST<Type>::showPreorder(NodeTree<Type>* p) const{
if (p==nullptr){
        std::cout<<"";  
    }
    else{
        std::cout<<p->getElement()<<" ";
        showPreorder(p->getLeft());
        showPreorder(p->getRight());
    }
}
//Mètode per a fer el printPostorder del arbre
template <class Type>
void BST<Type>::showPostorder() const{
     if(isEmpty()){
        std::cout << "Arbre buit" << std::endl;
    }else{
        std::cout<<"Postordre = { ";
        showPostorder(pRoot);
        std::cout<<"}"<<std::endl;
    }
}
//Mètode recursiu per a fer el printInorder del arbre
template <class Type>
void BST<Type>::showPostorder(NodeTree<Type>* p) const{
if (p==nullptr){
        std::cout<<"";
        
    }
    else{
        showPostorder(p->getLeft());
        showPostorder(p->getRight());
        std::cout<<p->getElement()<<" ";
    }
}

//Mètode per a mostrar els nodes fulla
template <class Type>
void BST<Type>::showLeafNodes() const{
    if(isEmpty()){
        std::cout << "Arbre buit" << std::endl;
    }else{
        std::cout<<"Fulles = { ";
        showLeafNodes(pRoot);
        std::cout<<" }"<<std::endl;
    }
}
//Mètode recursiu per a mostrar els nodes fulla del arbre
template <class Type>
void BST<Type>::showLeafNodes(NodeTree<Type>* p) const{

    if (p->getLeft()==nullptr && p->getRight()==nullptr){
        std::cout<<p->getElement()<< " ";
    }
    else if (p->getLeft()==nullptr){
        showLeafNodes(p->getRight());
    }
    else if (p->getRight()==nullptr){
        showLeafNodes(p->getLeft());
    }
    else{
         showLeafNodes(p->getLeft());
         showLeafNodes(p->getRight());
         
    }
}
//Mètode per a inserir un nou node al arbre
template<class Type>
void BST<Type>::insert(const Type& element){
    NodeTree<Type>* node = new NodeTree<Type>(element); 

    if(search(element)){
        std::cout<<"EXCEPTION: L'element ja existeix"<<std::endl;
    }else if (isEmpty()) {   
        pRoot=node;
        std::cout<<"Inserta a l'arbre element "<<element<<std::endl;
    } else{ 
        NodeTree<Type>* auxiliar= pRoot;
        NodeTree<Type>* parent;
        while(auxiliar!=0){
            if(element>auxiliar->getElement()){
                parent=auxiliar;
                auxiliar=auxiliar->getRight();
            }else{
                parent=auxiliar;
                auxiliar=auxiliar->getLeft();
            }
            
        }
        if(element> parent->getElement()){
            node->setParent(parent);
            parent->setRight(node);
        }else{
            node->setParent(parent);
            parent->setLeft(node);
        }
        std::cout<<"Inserta a l'arbre element "<<element<<std::endl;

    }
}

#endif /* BST_H */

