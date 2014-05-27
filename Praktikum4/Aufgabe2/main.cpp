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

std::map<string, int> generiereWortliste(ifstream& input)
{
    string word = "";
    std::map<string, int> mwordliste;
    while (input) {
        input >> word;
        std::map<string, int>::iterator eintrag = mwordliste.find(word);
        if (eintrag == mwordliste.end()) {
            mwordliste.insert(std::pair<string, int>(word, 1));
        } else {
            ++(eintrag->second);
        }
    }
    return mwordliste;
}

void flipCopy(std::map<string, int>::iterator begin,
        const std::map<string, int>::iterator& end,
        std::multimap<int, string>& target)
{
    for (; begin != end; ++begin) {
        target.insert(std::pair<int, string>(begin->second, begin->first));
    }
}

int main() {
    try {
        string dateiname = "cicero.txt"; //Einen String mit dem Namen "dateiname" deklarieren und mit dem Dateinamen initialisieren
        string dateinameout = "p5a2.txt";
        ifstream input(dateiname.c_str());
        if (!input) {
            throw std::runtime_error("Kann Datei nicht oeffnen!\n");
        }
        std::map<string, int> mwordliste = generiereWortliste(input); //Speichert die Strings mit ihrer Haeufigkeit
        input.close();
        std::multimap<int, string> msort; //Speichert die Strings sortiert nach Haufigkeit (beachte: evtl doppelte schluessel)
        
        flipCopy(mwordliste.begin(), mwordliste.end(), msort);

        ofstream outfile(dateinameout.c_str());
        if (!outfile) throw std::runtime_error("Kann Ausgabedatei nicht oeffnen!");
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