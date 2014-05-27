/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 14. Mai 2014, 13:42
 */

#include <iostream>
#include <fstream>
#include "telnum.h"
#include "telnumbook.h"
#include <stdexcept>
#include <vector>
#include <string>

using std::endl;
using std::cerr;
using std::cout;
using std::cin;
using std::string;

Telnum add_telbook();
void print(const Telnum& telnum);
void menu(TelnumBook& book);
void searchName(TelnumBook& book);
void save(TelnumBook& book);
TelnumBook load();

/*
 * 
 */
int main() {
    try {
        TelnumBook book;
        
        menu(book);

        return 0;

    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}

Telnum add_telbook() {
    Telnum telnum;
    string number;
    string fname;
    string lname;
    string street;
    int hnr;
    int pc;
    string location;
    
    cin.ignore();
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

    print(telnum);

    return telnum;
}

void print(const Telnum& telnum) {
    cout << "Nr. " << telnum.get_telnum() << endl
            << "Vorname " << telnum.get_fname() << endl
            << "Nachname " << telnum.get_lname() << endl
            << "Strasse " << telnum.get_street() << endl
            << "Hausnr. " << telnum.get_hnr() << endl
            << "PLZ. " << telnum.get_pc() << endl
            << "Ort " << telnum.get_location() << endl << endl;
}

void menu(TelnumBook& book) {
    bool exit = false;
    int eingabe = 0;
    
    while (!exit) {
        cout << "0 um das Programm zu beenden." << endl
                << "1 um einen Eintrag im Telefonbuch anzulegen. " << endl
                << "2 um Telefonbuch nach Nummern zu sortieren." << endl
                << "3 um Telefonbuch nach Namen zu sortieren." << endl
                << "4 um Telefonbuch nach Ort zu Sortieren." << endl
                << "5 um im Telefonbuch nach einem Namen zu suchen." << endl
                << "6 um das Telefonbuch zu speichern." << endl
                << "7 um ein Telefonbuch zu laden." << endl;
        cin >> eingabe;
        if (!cin) {
            throw std::runtime_error("Ungueltige Eingabe!");
        }
        switch (eingabe) {
            case 0:
                exit = true;
                break;
            case 1:
                book.push_back(add_telbook());
                break;
            case 2:
                book.sort_by_number();
                break;
            case 3:
                book.sort_by_name();
                break;
            case 4:
                book.sort_by_location();
                break;
            case 5:
                searchName(book);
                break;
            case 6:
                save(book);
                break;
            case 7:
                book = load();
                break;
            default:
                throw std::runtime_error("Ungueltige Eingabe!");
                break;
        }


    for(TelnumBook::iterator iter = book.begin(); iter != book.end(); ++iter)
        print(*iter);
    }
}

void searchName(TelnumBook& book)
{
    string input;
    cout << "Nach welchem Namen moechten Sie suchen? ";
    cin >> input;
    if (!cin) {
        throw std::runtime_error("Fehlerhafte Eingabe!");
    }
    TelnumBook results(book.search_name(input));
    if(results.size() == 0)
        cout << "Name nicht gefunden";
    else for (size_t i(0); i < results.size(); ++i) {
        cout << results.at(i).get_telnum() << endl;
    }
}

void save(TelnumBook& book)
{
    string filename;
    cout << "Dateiname: ";
    cin >> filename;
    if(!cin)
        throw std::runtime_error("Ungueltige Eingabe");
    std::ofstream target(filename.c_str());
    if(!target)
        throw std::runtime_error("Ungueltige Datei");
    book.save_to(target);
    target.close();
}
TelnumBook load()
{
    string filename;
    cout << "Dateiname: ";
    cin >> filename;
    if(!cin)
        throw std::runtime_error("Ungueltige Eingabe");
    std::ifstream source(filename.c_str());
    if(!source)
        throw std::runtime_error("Ungueltige Datei");
    TelnumBook book = TelnumBook::read_from(source);
    source.close();
    
    return book;
}