/* 
 * File:   tree.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 9. Juni 2014, 10:53
 */

#ifndef TREE_H
#define	TREE_H

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <time.h>
#include <queue>

using std::cout;
using std::endl;

template<class T>
class binTree {
public:

    binTree() : root(0) {
    } //Standardkonstruktor
    
    binTree(const binTree& other): root(0) {
        if(other.root)
            root = new Node(*other.root);
    }

    ~binTree() { //Destruktor
        Node::del_tree(root); //Loeschfunktion mit wurzel aufrufen. Fuehrt dazu das der Baum ab der Wurzel geloscht wird
        root = 0;//die Wurzel auf 0 setzen
    }

    void clear() {
        Node::del_tree(root); //Loeschfunktion mit wurzel aufrufen. Fuehrt dazu das der Baum ab der Wurzel geloscht wird
        root = 0;//Die Wurzel auf 0 setzen
    }

    struct Node { //Knoten-Struct

        Node() : value(0), key(T()), left(0), right(0), parent(0) {
        } //Standardkonstruktor
        
        Node(const Node& other) : value(other.value), key(other.key), left(0), right(0), parent(0)
        {
            if(other.left)
            {
                left = new Node(*other.left);
                left->parent = this;
            }
            if(other.right) {
                right = new Node(*other.right);
                right->parent = this;
            }
        }

        explicit Node(const T& tkey) : value(1), key(tkey), left(0), right(0), parent(0) {

        } //weiterer Konstruktor (setzte den Wert im Knoten auf 1)

        ~Node() {//Destruktor
        }

        //in-order-traversierung

        void in_order(std::ostream& result) {//bekommt einen Knoten uebergeben, wird so lange wieder aufgerufen bis der komplette Baum durchlaufen wurde
            if (left) {//wenn der linke Teilbaum ungleich 0 ist
                left->in_order(result); //rufe die Funktion erneut mit dem linken Folgeknoten auf
            }
            result << key << " ";
            if (right) {//wenn der rechte Teilbaum ungleich 0 ist
                right->in_order(result);
            }
        }

        //Level-order-traversierung
        void level_order(std::ostream& result) {//Bekommt einen Knoten uebergeben
            Node* node = 0;
            std::queue<Node*> q; //erstelle einen Container namens q mit Node* Objekten
            q.push(this); //Schreibe den aktuellen Knoten in den queue Container
            while (!q.empty()) {
                node = q.front();
                q.pop();
                result << node->key << " ";
                if (node->left != 0) {
                    q.push(node->left);
                }
                if (node->right != 0) {
                    q.push(node->right);
                }
            }
        }

        //alle Knoten in einem beliebigen Teilbaum zaehlen

        unsigned int count_nodes() {//bekommt die wurzel gewunschten Teilbaums uebergeben
            unsigned int left_n = 0; //Anzahld er Knoten im linken Teilbaum
            unsigned int right_n = 0; //anzahl der Knoten im rechten Teilbaum

            if (left) {
                left_n = left->count_nodes();
            }
            if (right) {
                right_n = right->count_nodes();
            }
            return left_n + right_n + 1;
        }

        //Schluessel finden

        Node* find(const T& tkey) {
            if (tkey < key) {//pruefe ob der uebergebene Schluessel kleiner als der aktuelle
                if (left) { //rufe die Funktion erneut auf mit dem linken Folgeknoten
                    return left->find(tkey);
                } else {
                    return 0; //wenn der schluessel nicht gefunden
                }
            } else if (tkey > key) {//wenn der Schluessel groesser
                if (right) { //rufe die Funktion erneut auf mit dem rechten Folgeknoten
                    return right->find(tkey);
                } else {
                    return 0;
                }
            } else if (tkey == key) { //wenn der Schluessel gleich
                return this;
            } else { //Wenn alles andere nicht zutrifft
                throw std::runtime_error("This should never happen!"); //werfe einen Fehler
            }
        }

        //Knoten einfuegen

        Node* insert(const T& tkey) {//bekommt einen Knoten und den gewunschten Schluessel uebergeben am Anfang muss der Knoten die Wurzel sein
            if (tkey < key) {//pruefe ob der uebergebene Schluessel kleiner als der aktuelle
                if (left != 0)
                    return left->insert(tkey); //rufe die Funktion erneut auf mit dem linken Folgeknoten
                else {
                    left = new Node(tkey);
                    left->parent = this;
                    return left;
                }
            } else if (tkey > key) {//wenn der Schluessel groesser
                if (right != 0)
                    return right->insert(tkey); //rufe die Funktion erneut auf mit dem linken Folgeknoten
                else {
                    right = new Node(tkey);
                    right->parent = this;
                    return right;
                }
            } else if (tkey == key) { //wenn der Schluessel gleich
                value++; //erhoehe den Wert im Knoten
                return this;
            } else { //Wenn alles andere nicht zutrifft
                throw std::runtime_error("Knoten konnte nicht hinzugefuegt werden!"); //werfe einen Fehler
            }
        }

        //Knoten loeschen  

        static void del_tree(Node * node) {//bekommt Knoten uebereben
            if (node != 0) { //wenn der Knoten nicht 0 ist
                del_tree(node->left); //rufe die Funktion erneut auf mit dem linken rechten folge Knoten
                del_tree(node->right); //rufe die Funktion mit dem rechten folge Knoten auf

                if (node->parent) {
                    if (node->parent->left == node) {
                        node->parent->left = 0;
                    }
                    if (node->parent->right == node) {
                        node->parent->right = 0;
                    }
                }
                delete node; //loesche den uebergebenen Knoten
            }
        }

        //Baumhoehe bestimmen

        unsigned int get_height() { //unsigned um negative von vorn herein ausszuschließen
            unsigned int left_h = 0; //hoehe des linken Teilbaums
            unsigned int right_h = 0; //hoehe des rechten Teilbaums

            if (left) {
                left_h = left->get_height() + 1; //rekursiver aufruf fuer den linken Teilbaum
            }
            if (right) {
                right_h = right->get_height() + 1; //rekursiver aufruf fuer den rechten Teilbaum
            }
            //std::max() liefert den groeßeren wert von links oder rechts. sind beide gleich lang wird der linke zurück gegeben
            return std::max(left_h, right_h); //gibt die gesamthoehe zurück
        }

        bool rotateUp() {
            Node* oldparent = parent;
            if (oldparent == 0)
                return false;
            if (oldparent->left == this) //Rechtsrotieren
            {
                parent = oldparent->parent;
                oldparent->left = right;

                if (parent) {
                    if (parent->left == oldparent)
                        parent->left = this;
                    else
                        parent->right = this;
                }

                if (right) {
                    right->parent = oldparent;
                }

                oldparent->parent = this;
                right = oldparent;

            } else {
                parent = oldparent->parent;
                oldparent->right = left;

                if (parent) {
                    if (parent->left == oldparent)
                        parent->left = this;
                    else
                        parent->right = this;
                }

                if (left) {
                    left->parent = oldparent;
                }

                oldparent->parent = this;
                left = oldparent;

            }
            return true;
        }

    private:
        int value; //Wert der Knoten (wie oft der Schluessel vorkommt)
        T key; //Schluessel und gleichzeitig eltern Knoten
        Node* left; //linker Kindsknoten
        Node* right; //rechter Kindsknoten
        Node* parent;
    }; //wurzel liefern

    binTree<T>::Node* get_root() const {
        return root;
    }

    unsigned int size() {
        if (root) {
            return root->count_nodes();
        }
        return 0;
    }

    unsigned int height() {
        if (root) {
            return root->get_height();
        }
        return -1;
    }

    binTree<T>::Node* find(const T& tkey) {
        if (root) { //Wenn root ungleich 0
            return root->find(tkey);
        }
        return 0;
    }

    void print_iO() {
        if (root) {
            root->in_order(std::cout);
        } else {
            cout << "Der Baum ist leer!" << endl;
        }
    }

    void print_lO() {
        if (root) {
            root->level_order(std::cout);
        } else {
            cout << "Der Baum ist leer!" << endl;
        }
    }
    
    std::string inOrder()
    {
        std::stringstream result;
        root->in_order(result);
        return result.str();
    }
    
    std::string levelOrder()
    {
        std::stringstream result;
        root->level_order(result);
        return result.str();
    }

    bool empty() const { //prueft ob Baum leer
        return (root == 0);
    }

    void insert(const T& tkey) {//bekommt einen Knoten und den gewunschten Schluessel uebergeben am Anfang muss der Knoten die Wurzel sein
        if (root == 0) { //wen der uebergebene Knoten leer ist
            root = new Node(tkey); //Aufruf des weiteren Konstruktors mit key
        } else {
            root->insert(tkey);
        }
    }

    void insert_top(const T& tkey) {
        if (root == 0) { //wen der uebergebene Knoten leer ist
            root = new Node(tkey); //Aufruf des weiteren Konstruktors mit key
        } else {
            Node* newelem = root->insert(tkey);
            while (newelem->rotateUp()) {
            }
            root = newelem;
        }
    }
private:
    Node* root;
};

#endif	/* TREE_H */

