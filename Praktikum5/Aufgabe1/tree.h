/* 
 * File:   tree.h
 * Author: Dorothee Müller-Ahlheim
 * Matr.:736476
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

    void clear() { //clear-funktion um den Baum manuell loeschen zu koennen (ruft die del funktion auf)
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

        } //weiterer Konstruktor (setzt den Wert im Knoten auf 1)

        ~Node() {//Destruktor
        }

        //in-order-traversierung (Methode)

        void in_order(std::ostream& result) {//bekommt einen Knoten uebergeben, wird so lange wieder aufgerufen bis der komplette Baum durchlaufen wurde
            if (left) {//wenn der linke Teilbaum ungleich 0 ist
                left->in_order(result); //rufe die Funktion erneut mit dem linken Folgeknoten auf
            }
            result << key << " ";
            if (right) {//wenn der rechte Teilbaum ungleich 0 ist
                right->in_order(result);
            }
        }

        //Level-order-traversierung (Methode)
        void level_order(std::ostream& result) {//Bekommt einen Knoten uebergeben
            Node* node = 0; //Erstellt einen Pointer auf einen neuen Knoten
            std::queue<Node*> q; //erstelle einen Container namens q mit Node* Objekten
            q.push(this); //Schreibe den aktuellen Knoten in den queue Container
            while (!q.empty()) {//solange der queue Container nicht leer ist
                node = q.front(); //zeigt der zeiger auf den ersten Knoten im queue-Container
                q.pop(); //wird das erste Objekt im Container
                result << node->key << " ";
                if (node->left != 0) { //Wenn der linke folgeknoten nicht 0 ist
                    q.push(node->left);//fuege ihn in den Container ein
                }
                if (node->right != 0) { //wenn der rechte Folgeknoten nicht 0 ist
                    q.push(node->right);//fuege den auch in den Container ein
                }
            }
        }

        //alle Knoten in einem beliebigen Teilbaum zaehlen (Methode)

        unsigned int count_nodes() {//bekommt die wurzel gewunschten Teilbaums uebergeben
            unsigned int left_n = 0; //Anzahld er Knoten im linken Teilbaum
            unsigned int right_n = 0; //anzahl der Knoten im rechten Teilbaum

            if (left) { //Wenn der linke Knoten nicht 0 ist
                left_n = left->count_nodes(); //rufe die FUnktion erneut mit dessen linkem Folgeknoten auf
            }
            if (right) { //Wenn auch der rechte Knoten nicht 0 ist
                right_n = right->count_nodes();//rufe auch hier die Funktion erneut mit dessen rechtem Folgeknoten auf
            }
            return left_n + right_n + 1; //Addiere die linken, die rechten und den wurzelknoten zusammen
        }

        //Schluessel finden (Methode)

        Node* find(const T& tkey) {//bekommt einen schluessel uebergeben
            if (tkey < key) {//prueft ob der uebergebene Schluessel kleiner als der aktuelle ist dann muss links gesucht werden
                if (left) { //wenn der linke Knoten nicht leer ist
                    return left->find(tkey); //rufe die funktion erneut mit dem linken knoten auf
                } else { //Ansonsten konnte der Schluessel nicht gefunden werden
                    return 0; //und gibt 0 zurueck
                }
            } else if (tkey > key) {//wenn der Schluessel groesser als der aktuelle schluessel ist muss rechts gesucht werden
                if (right) { //rufe die Funktion erneut auf mit dem rechten Folgeknoten
                    return right->find(tkey);//rufe die Funktion erneut auf mit dem rechten folge Knoten
                } else {//Ansonsten kann der schluessel nicht gefunden werden
                    return 0;//und die funktion gibt 0 zurueck
                }
            } else if (tkey == key) { //wenn der Schluessel gleich dem schluessel im aktuellen Knoten ist
                return this; //Gebe den aktuellen Knoten zurueck
            } else { //Wenn alles andere nicht zutrifft
                throw std::runtime_error("This should never happen!"); //werfe einen Fehler
            }
        }

        //Knoten einfuegen (Methode)

        Node* insert(const T& tkey) {//bekommt gewuenschten Schluessel uebergeben
            if (tkey < key) {//prueft ob der uebergebene Schluessel kleiner als der aktuelle ist, dann muss links eingefuegt werden
                if (left != 0) //wenn der linke Knoten nicht null ist
                    return left->insert(tkey); //rufe die Funktion erneut auf mit dem linken Folgeknoten auf
                else {//wenn der linke Knoten leer sein sollte
                    left = new Node(tkey); //wird er zum neuen Knoten mit dem uebergebenen Schluessel
                    left->parent = this; //sein vorgaenger ist der aktuelle Knoten
                    return left; //und der linke Knoten wird zurueck gegeben
                }
            } else if (tkey > key) {//wenn der Schluessel groesser als der aktuelle ist, muss recht eingefuegt werden 
                if (right != 0) //wenn der rechte Knoten nicht leer ist
                    return right->insert(tkey); //rufe die Funktion erneut auf mit dem linken Folgeknoten
                else {//Ansonsten
                    right = new Node(tkey);//wird er zum neuen Knoten mit uebergebenem Schluessel
                    right->parent = this; //sein Elternknoten ist der aktuelle
                    return right; //und der rechte KNoten wird zurueck gegeben
                }
            } else if (tkey == key) { //wenn der Schluessel gleich ist
                value++; //wird der Wert im Knoten erhoeht
                return this; //und der aktuelle KNoten zurueck gegeben
            } else { //Wenn nichts davon zutrifft
                throw std::runtime_error("Knoten konnte nicht hinzugefuegt werden!"); //werfe einen Fehler
            }
        }

        //Knoten loeschen  (Methode)

        static void del_tree(Node * node) {//bekommt Knoten uebereben
            if (node != 0) { //wenn der Knoten nicht 0 ist
                del_tree(node->left); //rufe die Funktion erneut auf mit dem linken rechten folge Knoten
                del_tree(node->right); //rufe die Funktion mit dem rechten folge Knoten auf

                if (node->parent) { //Wenn der aktuelle Knoten einen elternknoten hatte
                    if (node->parent->left == node) {//pruefe ob der aktuelle Knoten gleich der linke nachfolger seinen Elternknoten ist
                        node->parent->left = 0; //dann setze diesen auf 0
                    }
                    if (node->parent->right == node) { //pruefe ob der aktuelle Knoten gleich dem rechten nachfolger seines Elternknotens ist
                        node->parent->right = 0;//dann setze diesen auf 0
                    }
                }
                delete node; //loesche den uebergebenen Knoten
            }
        }

        //Baumhoehe bestimmen (Methode)

        unsigned int get_height() { //unsigned um negative von vorn herein ausszuschließen
            unsigned int left_h = 0; //hoehe des linken Teilbaums
            unsigned int right_h = 0; //hoehe des rechten Teilbaums

            if (left) { //Wenn der Linke knoten nicht 0 ist
                left_h = left->get_height() + 1; //rekursiver aufruf fuer den linken Teilbaum
            }
            if (right) { //wenn der rechte Knoten nicht 0 ist
                right_h = right->get_height() + 1; //rekursiver aufruf fuer den rechten Teilbaum
            }
            //std::max() liefert den groeßeren wert von links oder rechts. sind beide gleich lang wird der linke zurück gegeben
            return std::max(left_h, right_h); //gibt die gesamthoehe zurück
        }

        //neuen Knoten al Wurzel einfuegen (rotieren)
        
        bool rotateUp() {
            Node* oldparent = parent; //erstellt einen Zeiger auf den Eltern Knoten des aktuellen Knoten und nennt diesen oldparent
            if (oldparent == 0)//wenn der eltern knoten 0 ist
                return false;//gebe false zurueck
            if (oldparent->left == this) //wenn der aktuelle Knoten der linke nachfolger seines Eltern Knotens ist (Rechtsrotieren)
            {
                parent = oldparent->parent; //wird der Elternknoten des aktuellen Elternknotens der neue Elternknoten des aktuellen Knotens
                oldparent->left = right; //und der linke nachfolger des alten Elternknotens wird zum rechten

                if (parent) { //solange der Elternknoten nicht leer ist (also der aktuelle noch einen Elternknoten hat)
                    if (parent->left == oldparent) //und der linke nachfolger des aktuellen Eltern knotens der alte Elternknoten ist
                        parent->left = this;//wird der linke nachfolger des eltern knotens der aktuelle
                    else //andernfalls
                        parent->right = this; //wird der rechte nachfolger des elternknotens der aktuelle
                }

                if (right) {//wenn der rechte Knoten nicht leer ist
                    right->parent = oldparent;//wird der rechte eltern knoten zum alten elternknoten (also dem des vorherigen elternknotens)
                }

                oldparent->parent = this; // und der neue elternteil des vorherigen elternknbotens wird der aktuelle
                right = oldparent; //der rechte wird dann der alte Elternknoten

            } else { //Ist der aktuelle KNoten nicht der linke (sondern der rechte nachfolger seines Elternknotens) muss Linksrotiert werden
                parent = oldparent->parent;//der neue Elternknoten wird zum Elternknoten des alten Elternknotens
                oldparent->right = left; //und der linke KNoten des aktuellen wird zum rechten des alten Elternknotens

                if (parent) { //wenn der Elternknoten nicht leer ist
                    if (parent->left == oldparent) //wenn der linke KNoten vom aktuellen Elterknoten dem alten Elternknoten entspricht
                        parent->left = this; //wird der aktuelle Knoten zum linken Knoten des aktuellen Elternknotens
                    else//wenn der linke nachfolger nicht dem alten Elternknoten entspricht
                        parent->right = this; //wird der aktuelle Knoten zum rechten Knoten des aktuellen Elternknotens
                }

                if (left) { //wenn der linke Knoten nicht leer ist
                    left->parent = oldparent; //wird der alte elternknoten zum eltern knoten des linken KNotens
                }

                oldparent->parent = this; //der neue Elternknoten des alten Elternknotens ist der aktuelle
                left = oldparent; //und der linke nachfolger wird der alte Elternknoten

            }
            return true; //wenn die rotation erfolgreich verlaufen ist, gib true zurueck
        }

    private:
        int value; //Wert der Knoten (wie oft der Schluessel vorkommt)
        T key; //Schluessel und gleichzeitig eltern Knoten
        Node* left; //linker Kindsknoten
        Node* right; //rechter Kindsknoten
        Node* parent; //elternknoten
    };
    
    //liefert den wurzelknoten
    binTree<T>::Node* get_root() const {
        return root;
    }
    
    //liefert die Anzahl der Knoten im Baum
    unsigned int size() {
        if (root) {
            return root->count_nodes();//gebe das ergebnis der count_nodes-methode von Node zurueck
        }
        return 0;
    }

    //liefert die Hohe des Baums (Beginn bei Ebene 0)
    unsigned int height() {
        if (root) {
            return root->get_height();//gebe das ergebnis der get_height-methode von Node zurueck
        }
        return -1;
    }

    binTree<T>::Node* find(const T& tkey) { //Sucht einen gewuenschten Schluessel im Baum
        if (root) { //Wenn root ungleich 0
            return root->find(tkey); //gebe das ergebnis der find-methode von Node zurueck
        }
        return 0; //ansonsten gebe 0 zurueck
    }

    void print_iO() { //Ausgabe der In-Order Traversierung
        if (root) { //Solange die Wurzel nicht leer ist
            root->in_order(std::cout);
        } else { //Ansonsten
            cout << "Der Baum ist leer!" << endl; //ist der Baum leer
        }
    }

    void print_lO() {//Ausgabe der Level-Order Traversierung
        if (root) {//Solange die Wurzel nicht leer ist
            root->level_order(std::cout);
        } else {//Ansonsten
            cout << "Der Baum ist leer!" << endl;//ist der Baum leer
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
        } else {//ansonsten
            Node* newelem = root->insert(tkey);//fuege einen neuen KNoten ein
            while (newelem->rotateUp()) { //un rotiere diesen an die Wurzel
            }
            root = newelem; //die wurzel ist nun das neue element
        }
    }
private:
    Node* root;
};

#endif	/* TREE_H */

