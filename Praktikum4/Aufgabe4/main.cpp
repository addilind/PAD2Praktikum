/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 14. Mai 2014, 13:42
 */

#include <iostream>
#include "telnum.h"
#include "telnumbook.h"
#include <stdexcept>
#include <vector>

using std::endl;
using std::cerr;
using std::cout;
using std::cin;

Telnum Eingabe() {
    Telnum telnum;
    string number;
    string fname;
    string lname;
    string street;
    int hnr;
    int pc;
    string location;

    cout << "Geben Sie eine Nummer ein: " << endl;
    if (!std::getline(cin, number)) {
        throw std::runtime_error("Fehlerhafte Eingabe!\n");
    }

    cout << "Geben Sie einen Vornamen ein: " << endl;
    if (!std::getline(cin, fname)) {
        throw std::runtime_error("Fehlerhafte Eingabe!\n");
    }

    cout << "Geben Sie einen Nachnamen ein: " << endl;
    if (!std::getline(cin, lname)) {
        throw std::runtime_error("Fehlerhafte Eingabe!\n");
    }

    cout << "Geben Sie eine Strasse ein: " << endl;
    if (!std::getline(cin, street)) {
        throw std::runtime_error("Fehlerhafte Eingabe!\n");
    }
    
    cout << "Geben Sie eine Hausnummer ein: " << endl;
    cin >> hnr;
    if (!cin) {
        throw std::runtime_error("Fehlerhafte Eingabe!\n");
    }

    cout << "Geben Sie eine Postleitzahl ein: " << endl;
    cin >> pc;
    if (!cin) {
        throw std::runtime_error("Fehlerhafte Eingabe!\n");
    }
    cin.ignore();

    cout << "Geben Sie einen Ort ein: " << endl;
    if (!std::getline(cin, location)) {
        throw std::runtime_error("Fehlerhafte Eingabe!\n");
    }

    telnum = Telnum(number, fname, lname, street, hnr, pc, location);

    return telnum;
}

/*
 * 
 */
int main() {
    try {
        TelnumBook book;
        Telnum input = Eingabe();
        book.push_back(input);

        cout << "Nr. " << input.get_telnum() << endl
                << "Vorname " << input.get_fname() << endl
                << "Nachname " << input.get_lname() << endl
                << "Strasse " << input.get_street() << endl
                << "Hausnr. " << input.get_hnr() << endl
                << "PLZ. " << input.get_pc() << endl
                << "Ort " << input.get_location() << endl;

        book.push_back(Eingabe());
        book.push_back(Eingabe());
        book.push_back(Eingabe());
        book.push_back(Eingabe());
        book.sort_by_number();
        cout << book[0].get_telnum() << "#" << book[1].get_telnum() << "#" << book[2].get_telnum() << "#" << book[3].get_telnum() << "#" << book[4].get_telnum() << endl;
        book.sort_by_name();
        cout << book[0].get_telnum() << "#" << book[1].get_telnum() << "#" << book[2].get_telnum() << "#" << book[3].get_telnum() << "#" << book[4].get_telnum() << endl;
        book.sort_by_location();
        cout << book[0].get_telnum() << "#" << book[1].get_telnum()<< "#" << book[2].get_telnum()<< "#" << book[3].get_telnum()<< "#" << book[4].get_telnum() << endl;
        
//        cout << book.search_lname("Papa"); << endl;
        
        
        return 0;

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}

