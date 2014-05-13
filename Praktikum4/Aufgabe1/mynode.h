/* 
 * File:   mynode.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 17. Mai 2014, 11:19
 */

#ifndef MYNODE_H
#define	MYNODE_H

template<class Elem> struct myNode { // "fuer alle Typen Elem"
    Elem val; // der Wert vom Typ Elem
    myNode<Elem>* pre; // Zeiger auf vorhergehenden Knoten (predecessor)
    myNode<Elem>* suc; // Zeiger auf nachfolgenden Knoten (successor)
    explicit myNode(const Elem&, myNode<Elem>*, myNode<Elem>*); // Konstruktor
};
// Definition des Konstruktors

template<class Elem>
myNode<Elem>::myNode(const Elem& v = Elem(),
        myNode<Elem>* p = 0,
        myNode<Elem>* s = 0)
: val(v), pre(p), suc(s) {
}

#endif	/* MYNODE_H */

