/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matrnr.: 736476
 *
 * Created on 6. Juni 2014, 14:53
 */

#include "tree.h"
#include "time.h"
#include <string>
#include <cstdlib>

using std::cerr;
using std::cin;

template<typename T>
void test(T result, T expected, std::string message) {
    std::cout << message << ": ";
    if (result != expected)
        std::cout << "failed [" << result << "]" << std::endl;
    else
        std::cout << "succeded" << std::endl;
}


void random_tree(binTree<char>& target, unsigned int count = 10) {
    for(unsigned int i = 0; i < count; ++i)
    {
        target.insert((std::rand()% 26) +65 );
    }
}

/*
 * 
 */
int main() {
    try {
        std::srand(time(0));
        
        binTree<char> baum;

        test<int>(baum.size(), 0, "Groesse leerer Baum = 0");
        test<int>(baum.height(), -1, "Hoehe leerer Baum = -1");
        baum.insert('s');
        test<int>(baum.size(), 1, "Groesse Baum nur Wurzel = 1");
        test<int>(baum.height(), 0, "Hoehe Baum nur Wurzel = 0");
        baum.insert('o');
        test<int>(baum.size(), 2, "Groesse Baum = 2");
        test<int>(baum.height(), 1, "Hoehe Baum = 1");
        baum.insert('r');
        test<int>(baum.size(), 3, "Groesse Baum = 3");
        test<int>(baum.height(), 2, "Hoehe Baum = 2");
        baum.insert('t');
        test<int>(baum.size(), 4, "Groesse Baum = 4");
        test<int>(baum.height(), 2, "Hoehe Baum = 2");

        test<bool>(baum.find('r') != 0, true, "Suche r erfolgreich");
        test<bool>(baum.find('k') != 0, false, "Suche k nicht erfolgreich");
        
        baum.print_iO(); //In-Order Traversierung
        cout << endl;
        baum.print_lO(); //Levelorder Traversierung
        cout << endl;
        
        test<bool>(baum.empty(), false, "Nichtleerer Baum: empty = false");
        baum.clear();
        test<bool>(baum.empty(), true, "Leerer Baum: empty = true");
        
        baum.insert_top('b');
        baum.insert_top('c');
        baum.insert_top('a');
        baum.insert_top('d');
        
        test<int>(baum.size(), 4, "Groesse Baum = 4");
        test<int>(baum.height(), 3, "Hoehe Baum = 3");
        
        baum.print_iO();
        cout << endl;
        baum.print_lO();
        cout << endl;
        
        baum.clear();
        
        random_tree(baum, 20);
        baum.print_iO();
        cout << endl;
        baum.print_lO();
        cout << endl;

        return 0;
    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}
