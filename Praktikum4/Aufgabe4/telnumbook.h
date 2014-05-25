/* 
 * File:   telnumbook.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 23. Mai 2014, 14:13
 */

#ifndef TELNUMBOOK_H
#define	TELNUMBOOK_H

#include <vector>
#include "telnum.h"

using std::vector;

class TelnumBook:public vector<Telnum>{ //Um MEthoden von Vector nutzen zu koennen (z.b. add)
 
public:   
    TelnumBook();
    TelnumBook(const vector<Telnum>& vbook);
    TelnumBook(const TelnumBook& source); //copy-Konstruktor
    
    void sort_by_number();
    void sort_by_name();
    void sort_by_location();
    
    TelnumBook search_lname(string slname);
    
};

#endif	/* TELNUMBOOK_H */

