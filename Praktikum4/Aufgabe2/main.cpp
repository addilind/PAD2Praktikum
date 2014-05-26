/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 14. Mai 2014, 13:41
 */

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <map>

using std::string;
using std::endl;
using std::cerr;
using std::cout;
using std::ifstream;
using std::ofstream;

/*
 * 
 */
template<class T> string toString(T t) {
    std::stringstream stst;
    stst << t;
    return stst.str();
}
bool checkTrue( bool condition, string description, bool silent=false )
void printTestResult(bool successful, string testType, string description, string expected = "", string actual = "");
bool checkEquals(string exp, string act, string description, bool silent = false);

int main() {
    try {
        string dateiname = "cicero.txt"; //Einen String mit dem Namen dateiname deklarieren und mit dem dateinamen initialisieren
        string dateinameout = "p5a2.txt";
        ifstream input(dateiname.c_str());
        if (!input) {
            throw std::runtime_error("Fehler!\n");
        }
        std::map<string, int> mwordliste; //Speichert die Strings mit ihrer haeufigkeit
        std::multimap<int, string> msort; //Speichert die Strings sortiert auh wenn ehrere shluessel gleih
        string word = "";

        while (input) {
            input >> word;
            std::map<string, int>::iterator eintrag = mwordliste.find(word);
            if (eintrag == mwordliste.end()) {
                mwordliste.insert(std::pair<string, int>(word, 1));
            } else {
                ++(eintrag->second);
            }
        }
        for (std::map<string, int>::iterator iter(mwordliste.begin());
                iter != mwordliste.end(); ++iter) {
            msort.insert(std::pair<int, string>(iter->second, iter->first));
        }
        ofstream outfile(dateinameout.c_str());
        if (!outfile) throw std::runtime_error("Kein Schreibzugriff auf die Datei!");
        for (std::multimap<int, string>::iterator iter(msort.begin()); iter != msort.end(); ++iter) {
            cout << iter->first << " " << iter->second << endl;
            outfile << iter->first << " " << iter->second << endl;
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

void printTestResult(bool successful, string testType, string description, string expected = "", string actual = "") {
    if (!successful) cout << "FAILED test ";
    else cout << "  succeeded test ";
    cout << testType << '(' << description << ')';
    cout << ", expected: " << expected;
    cout << ", actual: " << actual << endl;
}

bool checkEquals(string exp, string act, string description, bool silent = false) {
    bool result(exp == act);
    if (!silent) printTestResult(result, "checkEquals", description, exp, act);
    return result;
}

bool checkTrue( bool condition, string description, bool silent=false ) {
if( !silent ) printTestResult(condition, "checkTrue", description );
return condition; 
}