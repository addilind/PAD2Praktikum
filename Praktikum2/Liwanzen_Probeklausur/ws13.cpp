/* 
 * File:   ws13.cpp
 * Author: Doro
 *
 * Created on 14. Januar 2014, 13:35
 * 
 * Beinhaltet die Definitionen
 */

#include "ws13.h"

Liwanze::Liwanze() //Standartkonstruktor
: name(""), loc(ndef) {
}

Liwanze::Liwanze(string n, Region l) //weiterer Konstruktor
: name(n), loc(l) {
}

string Liwanze::get_name() const { //Methode zum auslesen des Namens
    return name;
}

Liwanze::Region Liwanze::get_loc() const {
    return loc;
}

void populate(vector<Liwanze>& Lvz) { // füllt den Übergebenen Vector mit Namen und Regionen
    Lvz.push_back(Liwanze("Joey", Liwanze::amer));
    Lvz.push_back(Liwanze("Johnny", Liwanze::amer));
    Lvz.push_back(Liwanze("DeeDee", Liwanze::amer));
    Lvz.push_back(Liwanze("Tommy", Liwanze::emea));
    Lvz.push_back(Liwanze("Suzy", Liwanze::apac));
    Lvz.push_back(Liwanze("Sheena", Liwanze::amer));
    Lvz.push_back(Liwanze("Papa", Liwanze::ndef));
    Lvz.push_back(Liwanze("Mama", Liwanze::ndef));
}

void print_LvzMembers(vector<Liwanze>& Lvz) { // Gibt jedes Element des Vectors aus    
    for (unsigned int i(0); i < Lvz.size(); i++) {
        Lvz.at(i).print(); //Für jedes Element wird die print()-Methode aufgerufen
    }
}

void Liwanze::print() { //Methode zur Ausgabe
    cout << "Mitgliedsname: " << name << " Region: ";

    switch (loc) { // Ausgabe der Enumeratoren als String
        case amer:
            cout << "Amer";
            break;
        case apac:
            cout << "Apac";
            break;
        case emea:
            cout << "Emea";
            break;
        default:
            cout << "nDef";
            break;
    }
    cout << endl;
}

void add_Liwanze(string eingabe_name, vector<Liwanze>& Lvz) {
    bool name_doppelt(false);
    for (size_t i(0); i < Lvz.size(); i++) { //Vektor bis zum Ende durch zählen
        if (Lvz.at(i).get_name() == eingabe_name) { // Jeden Index vergleichen
            cout << "Name schon vorhanden! Bitte neuen eingeben!" << endl;
            name_doppelt = true; // Wenn Name schon vorhanden, soll er nicht hinzugefügt werden
            break;
        }
    }
    if (name_doppelt == false) { // Falls der Name noch nicht vorhanden ist, soll er hinzugefügt werden
        Lvz.push_back(Liwanze(eingabe_name, Liwanze::ndef));
        print_LvzMembers(Lvz);
    }
}

bool Liwanze::connects(Liwanze* to) { //Überprüft ob zur Liwanze Verbindung besteht
    bool verbindung = false;
    for (size_t i(0); i < connectedFrom.size(); i++) {
        if (to->name == connectedFrom.at(i)) { //Überprüfe ob Verbindung(Zeiger auf ein Objekt in connectsTo zeigt) zu einer Liwanze besteht
            verbindung = true; //Wenn ja setze verbindung true
            cout << "Verbindung 'connectTo' schon vorhanden!" << endl;
        }
    }
    return verbindung;

}

bool Liwanze::connected(Liwanze* from) { //Überprüft ob von Liwanze Verbindung besteht
    bool verbindung = false;
    for (size_t i(0); i < connectsTo.size(); i++) {
        if (from->name == connectsTo.at(i)) { //Überprüfe ob Verbindung(Zeiger von einem Objekt in connectedFrom) von einer Liwanze besteht
            verbindung = true;
            cout << "Verbindung 'connectedFrom' schon vorhanden!" << endl;
        }
    }
    return verbindung;
}

void Liwanze::print_tierone() { //Ausgabe der Tier one(connectsTo() & connectsFrom())

    for (size_t i(0); i < connectsTo.size(); i++) {
        cout << "connects To: " << connectsTo.at(i) << std::hex << &connectsTo.at(i) << endl;
    }
    for (size_t i(0); i < connectedFrom.size(); i++) {
        cout << "connected From: " << connectedFrom.at(i) << endl;
    }
    cout << endl;
}

void Liwanze::add_connTo(Liwanze* to) { //Stellt Verbindung zu Liwanze her (Lässt Zeiger auf Objekt zeigen)
    connectsTo.push_back(to->get_name()); //Schreibt Zeiger auf einen Namen in den Vektor rein
}

void Liwanze::add_connFrom(Liwanze* from) { //Stellt Verbindung von Liwanze her (Lässt Zeiger von Objekt zeigen)
    connectedFrom.push_back(from->get_name()); //Schreibt Zeiger auf Namen in den Vektor rein
}

void init_connections(vector<Liwanze>& Lvz) { //Bsp.: Lvz, Joey to Johnny
    make_connection(Lvz, "Joey", "Johnny");
    make_connection(Lvz, "Joey", "DeeDee");
    make_connection(Lvz, "Joey", "Suzy");
    make_connection(Lvz, "Joey", "Sheena");
    make_connection(Lvz, "Johnny", "Joey");
    make_connection(Lvz, "Johnny", "Suzy");
    make_connection(Lvz, "DeeDee", "Suzy");
    make_connection(Lvz, "Tommy", "Suzy");
    make_connection(Lvz, "Sheena", "Joey");

    for (size_t i(0); i < Lvz.size(); i++) {
        cout << Lvz.at(i).get_name() << endl;
        Lvz.at(i).print_tierone();
    }

}

void make_connection(vector<Liwanze>& Lvz, string Liwanze1, string Liwanze2) {
    Liwanze * from(0); //Zeiger mit Namen from
    Liwanze * to(0); //Zeiger mit Namen to

    for (size_t i(0); i < Lvz.size(); i++) {
        if (Lvz.at(i).get_name() == Liwanze1) {
            to = &(Lvz.at(i));
        }
    }
    for (size_t i(0); i < Lvz.size(); i++) {
        if (Lvz.at(i).get_name() == Liwanze2) {
            from = &(Lvz.at(i));
        }
    }

    if (from == 0 || to == 0) {
        throw std::runtime_error("Der Name ist nicht im Netzwerk vorhanden");
    }

    if ((from->connects(to)) == false && (to->connected(from) == false)) {
        cout << "Verbindung zwischen " << Liwanze1 << " und " << Liwanze2 << " wurde erfolgreich hergestellt" << endl;
        from->add_connFrom(to); //Liwanze1 zeigt auf Liwanze2 = Liwanze1 connects to Liwanze2
        to->add_connTo(from); //Liwanze2 zeigt auf Liwanze1 = Liwanze2 connected from Liwanze1
    }
}

void namen_eingeben(vector<Liwanze>& Lvz) {

    string eingabe_name("noName");
    while (eingabe_name != "q") {
        cout << "Geben Sie einen Namen ein (Mit 'q' ins Menue zuruekkehren): " << endl;
        cin >> eingabe_name;
        if (!cin) throw std::runtime_error("Inkorrekte Eingabe!");

        if (eingabe_name != "q") {
            add_Liwanze(eingabe_name, Lvz);
        } else return;
    }
}

void zweinamen_eingeben(vector<Liwanze>& Lvz, string Liwanze1, string Liwanze2) {
    // Überprüfe ob einer der beiden Namen nicht registriert wurde:    
    bool name1_vorhanden(false);
    bool name2_vorhanden(false);
    for (size_t i(0); i < Lvz.size(); i++) { //Vektor bis zum Ende durch zählen
        if (Lvz.at(i).get_name() == Liwanze1) { // Jeden Index vergleichen
            name1_vorhanden = true;
        }
        if (Lvz.at(i).get_name() == Liwanze2) {
            name2_vorhanden = true;
        }
    }
    if (name1_vorhanden == true && name2_vorhanden == true) {
        make_connection(Lvz, Liwanze1, Liwanze2);
    } else {
        cout << "Einer der Namen ist noch nicht vorhanden! Bitte zwei neue eingeben! Mit 'q' abbrechen" << endl;
    }
}


