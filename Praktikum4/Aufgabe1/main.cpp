/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 14. Mai 2014, 13:40
 */

#include "mylist.h"
#include <ctime>
#include <cstdlib>

using std::endl;
using std::cerr;
using std::cout;
using std::cin;

/*
 * 
 */
int main() {
    try {
        myList<int> mylist;
        int input = 0;
        bool exit(false);
        std::srand(std::time(0));
        while (!exit) {
            cout << " 1: Zufallszahl am Listenanfang hinzufuegen" << endl;
            cout << " 2: Zufallszahl am Listenende hinzufuegen" << endl;
            cout << " 3: Zahl vom Listenanfang loeschen" << endl;
            cout << " 4: Zahl vom Listenende loeschen" << endl;
            cout << " 5: Zufallszahl irgendwo in Liste einfuegen" << endl;
            cout << " 6: Zahl irgendwo in Liste loeschen" << endl;
            cout << " 7: Liste ausgeben" << endl;
            cin >> input;
            if (!cin) throw std::runtime_error("Inkorrekte Eingabe!");
            switch (input) {
                case 7:
                    mylist.print();
                    break;
                case 6:
                    mylist.print();
                    cout << "An welcher Stelle wollen Sie eine Zahl loeschen?";
                    cin >> input;
                    if (!cin) throw std::runtime_error("Inkorrekte Eingabe!");
                    mylist.del(input);
                    break;
                case 5: {
                    mylist.print();
                    cout << "An welcher Stelle wollen Sie eine Zufallszahl einfuegen? ";
                    cin >> input;
                    if (!cin) throw std::runtime_error("Inkorrekte Eingabe!");
                    int rnd = std::rand() % 1000;
                    cout << "Zufallszahl: "<<rnd<<endl;
                    mylist.ins(input, rnd);
                    break;
                }
                case 4:
                    cout << "Geloeschter Wert war: " << mylist.pop_back() << endl;
                    break;
                case 3:
                    cout << "Geloeschter Wert war: " << mylist.pop_front() << endl;
                    break;
                case 2: {
                    int rnd = std::rand() % 1000;
                    cout << "Zufallszahl: "<<rnd<<endl;
                    mylist.push_back(rnd);
                    break;
                }
                case 1: {
                    int rnd = std::rand() % 1000;
                    cout << "Zufallszahl: "<<rnd<<endl;
                    mylist.push_front(rnd);
                    break;
                }
                case 0:
                    exit = true;
                    break;
                default:
                    cout << "Inkorrekte Eingabe!";
                    break;
            }
            cout << endl;
        }


        return 0;

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}

