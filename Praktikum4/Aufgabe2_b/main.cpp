/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matriklnr.: 736476
 * Created on 26. Mai 2014, 13:51
 */

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <map>
#include <string>

using std::endl;
using std::cerr;

/*
 * 
 */
int main() {
    try {
        std::string word;
        int anz = 0;
        std::multimap<int, std::string> mmap;
        std::string dateiname = "p5a2.txt";
        std::ifstream input(dateiname.c_str());
        if (!input) {
            throw std::runtime_error("Fehler!\n");
        }
        while(input){
            input >> anz >> word;
            mmap.insert(std::pair<int, std::string>(anz, word));
        }
        for (std::multimap<int, std::string>::iterator iter(mmap.begin()); iter != mmap.end(); ++iter) {
            std::cout << iter->first << " " << iter->second << endl;
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

