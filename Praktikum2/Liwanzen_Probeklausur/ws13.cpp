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

void populate(list<Liwanze>& Lvz) { 
    Lvz.push_back(Liwanze("Joey", Liwanze::amer));
    Lvz.push_back(Liwanze("Johnny", Liwanze::amer));
    Lvz.push_back(Liwanze("DeeDee", Liwanze::amer));
    Lvz.push_back(Liwanze("Tommy", Liwanze::emea));
    Lvz.push_back(Liwanze("Suzy", Liwanze::apac));
    Lvz.push_back(Liwanze("Sheena", Liwanze::amer));
}

void print_LvzMembers(list<Liwanze>& Lvz) {
    for (list<Liwanze>::iterator i = Lvz.begin(); i != Lvz.end(); i++) {
        i->print(); //Für jedes Element wird die print()-Methode aufgerufen
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

void add_Liwanze(string eingabe_name, list<Liwanze>& Lvz) {
    for (list<Liwanze>::iterator i = Lvz.begin(); i != Lvz.end(); i++) {
        if (i->get_name() == eingabe_name) { // Jeden Index vergleichen
            cout << "Name schon vorhanden! Bitte neuen eingeben!" << endl;
			return;
        }
    }
    Lvz.push_back(Liwanze(eingabe_name, Liwanze::ndef));
    print_LvzMembers(Lvz);
}

bool Liwanze::connects(Liwanze* to) { //Überprüft ob zur Liwanze Verbindung besteht
	for (list<string>::iterator i = connectedFrom.begin(); i != connectedFrom.end(); i++) {
        if (to->name == *i) { //Überprüfe ob Verbindung(Zeiger auf ein Objekt in connectsTo zeigt) zu einer Liwanze besteht
            cout << "Verbindung 'connectedFrom' schon vorhanden!" << endl;
			return true;
        }
    }
    return false;
}

bool Liwanze::connected(Liwanze* from) { //Überprüft ob von Liwanze Verbindung besteht
	for (list<string>::iterator i = connectsTo.begin(); i != connectsTo.end(); i++) {
		if (from->name == *i) { //Überprüfe ob Verbindung(Zeiger auf ein Objekt in connectsTo zeigt) zu einer Liwanze besteht
			cout << "Verbindung 'connectTo' schon vorhanden!" << endl;
			return true;
		}
	}
	return false;
}

void Liwanze::print_tierone() { //Ausgabe der Tier one(connectsTo() & connectsFrom())

	for (list<string>::iterator i = connectsTo.begin(); i != connectsTo.end(); i++) {
		cout << "connects To: " << *i << std::hex << " Adresse: " <<&(*i) << endl;
	}
	for (list<string>::iterator i = connectedFrom.begin(); i != connectedFrom.end(); i++) {
		cout << "connected From: " << *i << std::hex << " Adresse: " << &(*i) << endl;
	}
    cout << endl;
}

void Liwanze::add_connTo(Liwanze* to) { //Stellt Verbindung zu Liwanze her (Lässt Zeiger auf Objekt zeigen)
    connectsTo.push_back(to->get_name()); //Schreibt Zeiger auf einen Namen in den Vektor rein
}

void Liwanze::add_connFrom(Liwanze* from) { //Stellt Verbindung von Liwanze her (Lässt Zeiger von Objekt zeigen)
    connectedFrom.push_back(from->get_name()); //Schreibt Zeiger auf Namen in den Vektor rein
}

void init_connections(list<Liwanze>& Lvz) { //Bsp.: Lvz, Joey to Johnny
    make_connection(Lvz, "Joey", "Johnny");
    make_connection(Lvz, "Joey", "DeeDee");
    make_connection(Lvz, "Joey", "Suzy");
    make_connection(Lvz, "Joey", "Sheena");
    make_connection(Lvz, "Johnny", "Joey");
    make_connection(Lvz, "Johnny", "Suzy");
    make_connection(Lvz, "DeeDee", "Suzy");
    make_connection(Lvz, "Tommy", "Suzy");
    make_connection(Lvz, "Sheena", "Joey");

    for (list<Liwanze>::iterator i = Lvz.begin(); i != Lvz.end(); i++) {
        cout << i->get_name() << endl;
        i->print_tierone();
    }

}

void make_connection(list<Liwanze>& Lvz, string Liwanze1, string Liwanze2) {
    Liwanze * from(0); //Zeiger mit Namen from
    Liwanze * to(0); //Zeiger mit Namen to

	for (list<Liwanze>::iterator i = Lvz.begin(); i != Lvz.end(); i++) {
        if (i->get_name() == Liwanze1) {
            to = &(*i);
        }
    }
	for (list<Liwanze>::iterator i = Lvz.begin(); i != Lvz.end(); i++) {
        if (i->get_name() == Liwanze2) {
            from = &(*i);
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

void namen_eingeben(list<Liwanze>& Lvz) {

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

void zweinamen_eingeben(list<Liwanze>& Lvz, string Liwanze1, string Liwanze2) {
    // Überprüfe ob einer der beiden Namen nicht registriert wurde:    
    bool name1_vorhanden(false);
	bool name2_vorhanden(false);
	for (list<Liwanze>::iterator i = Lvz.begin(); i != Lvz.end(); i++) {
        if (i->get_name() == Liwanze1) { // Jeden Index vergleichen
            name1_vorhanden = true;
        }
        if (i->get_name() == Liwanze2) {
            name2_vorhanden = true;
        }
    }
    if (name1_vorhanden == true && name2_vorhanden == true) {
        make_connection(Lvz, Liwanze1, Liwanze2);
    } else {
        cout << "Einer der Namen ist noch nicht vorhanden! Bitte zwei neue eingeben! Mit 'q' abbrechen" << endl;
    }
}


