/* 
 * File:   pro.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 12. Mai 2014, 10:05
 */

#ifndef PRO_H
#define	PRO_H

#include "bas.h"

class Pro : public Bas {
public:

    Pro();
    Pro(string sname, bool bgender, int iage);
    bool get_gen() const;
    int get_age() const;
    void set_age(int iage);
    void print() const;
private:
    bool gender;
    int age;
};

class Roo : public Bas {
public:
    
    Roo();
    Roo(string sname, string scolor, int iprice);
    string get_col() const;
    int get_price() const;
    void set_price(int iprice);
    void print() const;
    
private:
    string color;
    int price;

};

#endif	/* PRO_H */

