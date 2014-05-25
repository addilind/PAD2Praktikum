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
    myNode<Elem>* last; // zeigt eins hinter den letzten Knoten

public:

    myList() : first(), last() { //Standartkonstruktor
        last = new myNode<Elem>; //inititalisiert last mit einem neuen Knotenelemnt (reserviert im Heap speicherplatz)
        first = last; //initialisiert den ersten mit dem letzte knoten
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
        delete last; //lösche den letzten Knoten, wenn dp auf das letzte element in der Liste zeigt
    }

    Elem pop_back() {//pop_back-Methode (Knoten vom Ende loeschen)
        if (first == last) {
            throw std::runtime_error("Liste ist leer!\n");
        } // Liste ist schon leer
        myNode<Elem>* tmp = last->pre; //deklariert einen Zeier namens tmp und initialisiert diesen mit dem Zeiger, der auf das Element vor dem letzten Element zeigt
        Elem deleted = last->pre->val;
        if (tmp == first) { //wenn tmp das erste Element der Liste ist
            last->pre = 0; //initialisiere den Zeiger, der auf das Element vor dem letzten Elemnt zeigt, auf 0
            first = last; //setze das erste Element als das letzte(weise dem ersten element der liste das letzte element der liste zu)
        }// letzten Knoten loeschen
        else {
            last->pre = last->pre->pre; //weise dem Zeiger, der auf das ELement vor dem letzten element zeigt, den ZEiger zu der auf das vorletzte element vor dem letzten element zeigt
            last->pre->suc = last; //weise dem Zeiger, der auf das element zeigt, dass nach dem Element kommt, welches vor dem letzten steht, das letzte Element zu
        }
        delete tmp; //lösche tmp
        return deleted;
    }

    void push_back(const Elem& v) {//push_back-Methode (Knoten am Ende einfuegen)
        myNode<Elem>* nn = new myNode<Elem>; //deklariert einen neuen Zeiger mit dem namen nn und definiert ihn als neuen knoten
        nn->val = v; //definiert den Zeiger nn, der auf den Wert im Knoten zeigt mit v
        if (first == last) { // Liste ist leer, d.h. erster Knoten wird eingefuegt
            first = nn; //initialisiert das erste Element der liste mit nn
            last->pre = first; //initialisiert den Zeiger, der auf das Element vor dem ersten ELemtn zeigt mit dem ersten Element
            first->suc = last; //initialisiert den Zeiger, der auf das Element nach dem ersten Element zeigt, mit dem letzten Element
        } else {
            nn->suc = last; //initialisiert den Zeiger, der auf den Wer nach nn Zeigt mit dem letzten ELement
            nn->pre = last->pre; //inititalisiert den Zeiger, der auf den Wert vor nn ZEigt mit dem Zeiger, der auf das Element vor dem letzten Element zeigt
            last->pre->suc = nn; //inititalisiert den Zeiger, der auf das Element zeigt, dass nach dem steht, welches vor dem letzten Element kommt, mit nn
            last->pre = nn; //initialisiert den Zeiger, der auf das Element vor dem letzten ELement zeigt mit nn
        }
    }

    Elem pop_front() { //pop_front-Methode (Knoten vorne loeschen)
        if (first == last) {
            throw std::runtime_error("Liste ist leer!\n");
        } // Liste ist schon leer
        myNode<Elem>* tmp = first->pre; //deklariert einen Zeiger namens tmp und initialisiert diesen mit dem Zeiger, der auf das Element vor dem ersten Zeigt
        Elem deleted = first->suc->val;
        if (tmp == last) { //wenn tmp das letzte Element in der Liste ist
            first->suc = 0; //initialisiert den Zeiger, der hinter das erste element zeigt mit 0
            last = first; //das letzte element ist nun das erste in der liste       
        } else {
            first->suc = first->suc->suc; //weise dem Zeiger, der auf das element nach dem ersten Element zeigt, den Zeiger zu, der auf das element zeigt, welches nach dem kommt, das nach dem ersten element kommt.
            first->suc->pre = first; //weise dem Zeiger, der auf das ELemtn zeigt, welches vor dem kommt, 
        }
        delete tmp; //lösche tmp wieder
        return deleted;
    }

    void push_front(const Elem& v) { //push_front-MEthode (Knoten vorne einfuegen)
        myNode<Elem>* nn = new myNode<Elem>; //deklariert einen neuen Zeiger mit dem namen nn und definiert ihn als neuen knoten
        nn->val = v; //definiert den Zeiger nn, der auf den Wert im Knoten zeigt mit v
        if (first == last) { // Liste ist leer, d.h. erster Knoten wird eingefuegt
            first = nn; //initialisiert das erste Element der liste mit nn
            last->pre = first; //initialisiert den Zeiger, der auf das Element vor dem ersten ELemtn zeigt mit dem ersten Element
            first->suc = last; //initialisiert den Zeiger, der auf das Element nach dem ersten Element zeigt, mit dem letzten Element
        } else {
            nn->suc = first->suc; //initialisiert den Zeiger, der auf den Wer nach nn Zeigt mit dem letzten ELement
            nn->pre = first; //inititalisiert den Zeiger, der auf den Wert vor nn ZEigt mit dem Zeiger, der auf das Element vor dem letzten Element zeigt
            first->suc->pre = nn; //inititalisiert den Zeiger, der auf das Element zeigt, dass nach dem steht, welches vor dem letzten Element kommt, mit nn
            first->suc = nn; //initialisiert den Zeiger, der auf das Element vor dem letzten ELement zeigt mit nn
        }
    }

    Elem del(int index) {//del-Methode (beliebigen Knoten loeschen)
        if (first == last) {
            throw std::runtime_error("Liste ist leer!\n");
        } // Liste ist schon leer
        std::list<myList*>::iterator iter;
        for (iter = first; iter != last; ++iter) {
            if (iter == index) {
                myNode<Elem>* tmp = iter->pre; //deklariert einen Zeiger namens tmp und initialisiert diesen mit dem Zeiger, der auf das Element vor dem ersten Zeigt
                Elem deleted = iter->suc->val;
                if (tmp == last) { //wenn tmp das letzte Element in der Liste ist
                    iter->suc = 0; //initialisiert den Zeiger, der hinter das erste element zeigt mit 0
                    last = iter; //das letzte element ist nun das erste in der liste       
                } else if (tmp == first) {
                    iter->pre = 0; //initialisiert den Zeiger, der hinter das erste element zeigt mit 0
                    first = iter; //das letzte element ist nun das erste in der liste  
                } else {
                    iter->suc = iter->suc->suc; //weise dem Zeiger, der auf das element nach dem ersten Element zeigt, den Zeiger zu, der auf das element zeigt, welches nach dem kommt, das nach dem ersten element kommt.
                    iter->suc->pre = iter->pre; //weise dem Zeiger, der auf das ELemtn zeigt, welches vor dem kommt, 
                }
                delete tmp; //lösche tmp wieder
                return deleted;
            }
        }
        //Liste durchzaehlen bis zum gewünschten Index
        // myNode<Elem>* tmp = index->pre; //deklariert einen Zeiger namens tmp und initialisiert diesen mit dem Zeiger, der auf das Element vor dem ersten Zeigt
        //Elem deleted = index->pre->suc->val;
    }

    void ins(int index, const Elem& v) { //ins-Methode (beliebigen Knoten einfuegen)
        myNode<Elem> nn = new myNode<Elem>;
        nn->val = v;
        if (first == last) {// Liste ist leer, d.h. erster Knoten wird eingefuegt
            first = nn; //initialisiert das erste Element der liste mit nn
            last->pre = first; //initialisiert den Zeiger, der auf das Element vor dem ersten ELemtn zeigt mit dem ersten Element
            first->suc = last; //initialisiert den Zeiger, der auf das Element nach dem ersten Element zeigt, mit dem letzten Element
        } else {
            //Liste bis zum gewünschten Index durchzaehlen
            //nn->suc = Zeiger auf Index->suc
            //nn->pre = Zeiger auf Index
            //index->suc->pre = nn
            //INdex->suc = nn;
        }
    }

    void print() {
        if (first->suc == last) {
            std::cout << "Stack is empty!" << std::endl;
        }
        myNode<Elem>* tmp(first->suc);
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
        myIterator& operator++();
        myIterator& operator--(); // Container ist doppelt verkettete Liste
        Elem& operator*();

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

        myIterator begin();
        myIterator end(); // liefert myIterator auf "eins hinter letztem Element"
        myIterator find(myIterator, myIterator, const Elem&); // finden
        myIterator insert(myIterator, const Elem&); // einfuegen
        myIterator erase(myIterator);

    };

    myIterator myIterator::begin() { // Methode, die myIterator auf erstes Element liefert
        curr = first;
    }
    myIterator myIterator::end(){ // liefert myIterator auf "eins hinter letztem Element"
        curr = end;
    }
    myIterator myIterator::find(myIterator begin, myIterator end, const Elem&){ // finden
        if(begin == end){ //Liste leer
            return;
        }
        
    }
    myIterator myIterator::insert(myIterator, const Elem&){ // einfuegen
        
    }
    myIterator myIterator::erase(myIterator){
        
    }
};



#endif	/* MYLIST_H */

