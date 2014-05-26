#include "telnumbook.h"
#include <algorithm>

using std::sort;

TelnumBook::TelnumBook() {
};

TelnumBook::TelnumBook(const vector<Telnum>& vbook) //weiterer Konstruktor
: vector<Telnum>(vbook) {

}

TelnumBook::TelnumBook(const TelnumBook& source) //copy-Konstruktor
: vector<Telnum> (source) {
}

int TelnumNumberPred(const Telnum& a, const Telnum& b) { //Praedikat
    //    return (a.get_telnum() < b.get_telnum()) ? -1 :
    //        (a.get_telnum() == b.get_telnum()) ? 0 : 1;

    if (a.get_telnum() < b.get_telnum())
        return -1;
    if (a.get_telnum() == b.get_telnum())
        return 0;
    return 1;
}

int TelnumNamePred(const Telnum& a, const Telnum& b) { //Praedikat fuer Sort Name
    if (a.get_lname() < b.get_lname())
        return -1;
    if (a.get_lname() > b.get_lname())
        return 1;
    //Nachname gleich
    if (a.get_fname() < b.get_fname())
        return -1;
    if (a.get_fname() > b.get_fname())
        return 1;
    return 0;
}

int TelnumLocPred(const Telnum& a, const Telnum& b) {
    if (a.get_location() < b.get_location())
        return -1;
    if (a.get_location() == b.get_location())
        return 0;
    return 1;
}

void TelnumBook::sort_by_number() { //Sortieren nach Name
    sort(begin(), end(), TelnumNumberPred); //sort methode aus standardbibliothek mit iterator auf begin, end und praedikat
}

void TelnumBook::sort_by_name() {
    sort(begin(), end(), TelnumNamePred);
}

void TelnumBook::sort_by_location() {
    sort(begin(), end(), TelnumLocPred);
}

class SearchNamePred {//functor
public:

    SearchNamePred() : target("") { //Standardkonstruktor
    } 

    SearchNamePred(string tar) : target(tar) { //weiterer Konstruktor
    }
    string target; // Attribut

    bool operator() (const Telnum& a) { //()-Operator
        return a.get_lname() == target || a.get_fname() == target;
    }
};

TelnumBook TelnumBook::search_name(string slname) {
    TelnumBook result;
    TelnumBook::iterator startsearch = begin();
    while (true) {
        startsearch = std::find_if(startsearch, end(), SearchNamePred(slname));
        if (startsearch == end()) {
            break;
        }
        result.push_back(*startsearch);
        startsearch++;
        if (startsearch == end()) {
            break;
        }
    }
    return result;
}
