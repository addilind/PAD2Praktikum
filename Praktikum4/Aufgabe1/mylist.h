/* 
 * File:   mylist.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 17. Mai 2014, 11:17
 */

#ifndef MYLIST_H
#define	MYLIST_H

#include "mynode.h"
#include <iterator>
#include <iostream>
#include <stdexcept>

template<class Elem> class myList {
    myNode<Elem>* first; // zeigt auf den ersten Knoten
    myNode<Elem>* last;  // zeigt eins hinter den letzten Knoten / auf den Waechterknoten

public:

    myList() : first(), last() { //Standardkonstruktor
        last = new myNode<Elem>; //inititalisiert last mit einem neuen Knotenelemnt (reserviert im Heap Speicherplatz)
        first = last;   //initialisiert den ersten mit dem letzte knoten
        last->suc = 0; //der Zeiger, der vom letzten auf das Element nach dem letzten zeigt wird auf 0 gesetzt
        last->pre = 0; //der Zeiger, der vom letzten auf das Element vor dem letzten zeigt, wird auf 0 gesetzt
    }
    
    

    ~myList() { //Destruktor

        myNode<Elem>* dp = first; //deklariert einen Zeiger namens dp und inititalisiert diesen mit dem ersten element
        myNode<Elem>* tmp = 0; //deklariert einen Zeiger namens tmp und inititalisiert diesen mit 0
        while (dp != last) { //solange der Zeiger dp nicht auf das letzte element der liste zeigt
            tmp = dp->suc; //schreibe den zeiger, der auf das Element nach dp zeigt in tmp
            delete dp; //lösche dp
            dp = tmp; //schreibe tmp in dp (in dp steht jetzt der Zeiger, der auf das Element nach dp gezeigt hat)
        }
        delete last; //loesche den letzten Knoten, wenn dp auf das letzte element in der Liste zeigt
    }

    Elem pop_back() {//pop_back-Methode (Knoten vom Ende loeschen)
        if (first == last) {
            throw std::runtime_error("Liste ist leer!\n");
        } // Liste ist schon leer
        myNode<Elem>* tmp = last->pre; //deklariert einen Zeier namens tmp und initialisiert diesen mit dem Zeiger, der auf das Element vor dem Waechter zeigt
        Elem deleted = last->pre->val;
        if (tmp == first) { //wenn tmp das erste Element der Liste ist (=die Liste hat nur 1 Element)
            last->pre = 0; //Waechterknoten auf 0-Pointer setzen
            first = last; //setze das erste Element als das letzte
        }// letzten Knoten loeschen
        else {
            last->pre = last->pre->pre; //weise dem Zeiger, der auf das letze Element zeigt das vorletzte Element zu
            last->pre->suc = last; 
        }
        delete tmp; //lösche tmp/altes letztes Element
        return deleted;
    }

    void push_back(const Elem& v) {//push_back-Methode (Knoten am Ende einfuegen)
        myNode<Elem>* nn = new myNode<Elem>;
        nn->val = v;
        if (first == last) { // Liste ist leer, d.h. erster Knoten wird eingefuegt
            first = nn; 
            last->pre = first;
            first->suc = last;
        } else {
            nn->suc = last;
            nn->pre = last->pre;
            last->pre->suc = nn;
            last->pre = nn;
        }
    }

    Elem pop_front() { //pop_front-Methode (Knoten vorne loeschen)
        if (first == last) {
            throw std::runtime_error("Liste ist leer!\n");
        } // Liste ist schon leer
        
        Elem deleted = first->val;
        if (first->suc == last) {//Liste hat nur noch 1 Element
            first = last;//Liste ist nach pop leer
        } else {
            first = first->suc;
        }
        delete first->pre; //lösche aus der Liste entfernten Knoten
        first->pre = 0;
        return deleted;
    }

    void push_front(const Elem& v) { //push_front-MEthode (Knoten vorne einfuegen)
        myNode<Elem>* nn = new myNode<Elem>; //deklariert einen neuen Zeiger mit dem namen nn und definiert ihn als neuen knoten
        nn->val = v;
        if (first == last) { // Liste ist leer, d.h. erster Knoten wird eingefuegt
            first = nn;
            last->pre = first;
            first->suc = last;
        } else {
            nn->suc = first;
            nn->pre = 0;
            first->pre = nn;
            first = nn;
        }
    }

    Elem del(int index) {//del-Methode (beliebigen Knoten loeschen)
        if (first == last) {
            throw std::runtime_error("Liste ist leer!\n");
        } // Liste ist schon leer  
        myNode<Elem>* pelem = first;
        for (; index > 0 && pelem != last; --index)
            pelem = pelem->suc;

        if (pelem == last)
            throw std::runtime_error("Ungueltiger Index");
        //pelem zeigt auf zu loeschendes Elem
        return del(pelem);
    }

    Elem del(myNode<Elem>* pelem) {
        if (pelem == last)
            throw std::runtime_error("Waechter nicht loeschbar");
        Elem deleted = pelem->val;

        if (pelem->pre == 0) // pelem == first
        {
            pelem->suc->pre = 0;
            first = pelem->suc;
        } else {
            pelem->pre->suc = pelem->suc;
            pelem->suc->pre = pelem->pre;
        }
        delete pelem;
        return deleted;
    }

    void ins(int index, const Elem& v) { //ins-Methode (beliebigen Knoten einfuegen)

        myNode<Elem>* pelem = first;
        for (; index > 0 && pelem->suc != 0; --index) {
            pelem = pelem->suc;
        }

        if (index > 0) {
            throw std::runtime_error("Ungueltiger Index");
        }
        ins(pelem, v);
    }

    myNode<Elem>* ins(myNode<Elem>* pelem, const Elem& v) {
        if (pelem == 0)
            throw std::runtime_error("Ungueltiger Pointer");
        myNode<Elem>* nn = new myNode<Elem>;
        nn->val = v;

        nn->suc = pelem;
        nn->pre = pelem->pre;

        if (pelem == first) {
            first = nn;
            pelem->pre = nn;
        } else {
            nn->suc->pre = nn;
            nn->pre->suc = nn;
        }
        return nn;
    }

    void print() {
        if (first == last) {
            std::cout << "Liste ist leer!" << std::endl;
        }
        myNode<Elem>* tmp(first);
        while (tmp != last) {
            std::cout << "Aktueller Wert im Knoten: " << tmp->val << std::endl;
            tmp = tmp->suc;
        }
    }

    //-----Iterator-----

    class myIterator {
    private:
        myNode<Elem>* curr; // der aktuelle Knoten
    public:

        myIterator()
        : curr(0) {
        }

        explicit myIterator(myNode<Elem>* p)
        : curr(p) {
        }

        myIterator& operator++() {
            if (curr == 0)
                throw std::runtime_error("Ungueltiger Iterator");
            curr = curr->suc;
            return *this;
        }

        myIterator& operator--() {
            if (curr == 0)
                throw std::runtime_error("Ungueltiger Iterator");
            curr = curr->pre;
            return *this;
        }

        Elem& operator*() {
            if (curr == 0)
                throw std::runtime_error("Ungueltiger Iterator");
            return *curr;
        }

        bool operator==
        (const myList<Elem>::myIterator& other) const {
            return curr == other.curr;
        }

        bool operator!=
        (const myList<Elem>::myIterator& other) const {
            return curr != other.curr;
        }

        myNode<Elem>* get_curr() const { // zum Debuggen
            return curr;
        }

        void invalidate() {
            curr = 0;
        }
    };

    myIterator begin() { // Methode, die myIterator auf erstes Element liefert
        return myIterator(first);
    }

    myIterator end() { // liefert myIterator auf "eins hinter letztem Element"
        return myIterator(last);
    }

    myIterator insert(myIterator iter, const Elem& elem) { // einfuegen
        return myIterator(ins(iter.get_curr(), elem));
    }

    myIterator erase(myIterator iter) {
        myIterator afterDeleted = ++(myIterator(iter));
        del(iter.get_curr());
        iter.invalidate();
        return afterDeleted;
    }
};



#endif	/* MYLIST_H */

