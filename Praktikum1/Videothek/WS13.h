/* 
 * File:   WS13.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 17. März 2014, 14:02
 * 
 * Beinhaltet Deklarationen
 */

#ifndef WS13_H
#define	WS13_H

#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>

using std::cerr;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;

class Borrower{
public:
    Borrower();//Standartkonstruktor
    Borrower(string, int, int); //weiterer Konstruktor
    
    string get_name() const;
    int get_nvids() const;
    int get_ndvds() const;
    
    void set_name(string);
    void inc_nvids();
    void inc_ndvds();
    
private:
    string name;
    unsigned int num_vids;
    unsigned int num_dvds;
    
};

class Video{
public:
    Video();
    Video(string, string);
    
    string get_vidtitle() const;
    string get_viddate() const;
    bool get_vidonshelf() const;
    
    void set_vidonshelf(bool);
    
private:
    string title;
    string date;
    bool on_shelf;
};

class Dvd{
public:
    Dvd();
    Dvd(string, string);
    
    string get_dvdtitle() const;
    string get_dvddate() const;
    bool get_dvdonshelf() const;
    
    void set_dvdonshelf(bool);
    
private:
    string title;
    string date;
    bool on_shelf;
};

class Loan_vid{
public:
    Loan_vid();
    Loan_vid(string, Video*);
    
    string get_lender() const;
    Video* get_borrowed() const;
    void print();
    
private:
    string sLender;
    Video* pBorrowed;
};

class Loan_dvd{
public:
    Loan_dvd();
    Loan_dvd(string, Dvd*);
    
    string get_lender() const;
    Dvd* get_borrowed() const;
    void print();
    
private:
    string sLender;
    Dvd* pBorrowed;
};

void populate_videos(vector<Video>&);
void populate_dvds(vector<Dvd>&);
void populate_borrower(vector<Borrower>&);
void populate_loansvid(vector<Loan_vid>&, vector<Video>&, vector<Borrower>&);
void populate_loansdvd(vector<Loan_dvd>&, vector<Dvd>&, vector<Borrower>&);
void add_borrower(vector<Borrower>&, string);
void add_loansvid(vector<Loan_vid>&, vector<Borrower>&, vector<Video>&, string, string, string);
void add_loansdvd(vector<Loan_dvd>&, vector<Borrower>&, vector<Dvd>&, string, string, string);
Video* get_vid(vector<Video>&, string, string);
Dvd* get_dvd(vector<Dvd>&, string, string);
void print_vids(vector<Video>&);
void print_dvds(vector<Dvd>&);
void print_borrowers(vector<Borrower>&);
void print_loansvid(vector<Loan_vid>&);
void print_loansdvd(vector<Loan_dvd>&);
bool borrower_exists(vector<Borrower>&, string);
bool vidtitle_exists(vector<Video>&, string);
bool dvdtitle_exists(vector<Dvd>&, string);
bool viddate_exists(vector<Video>&, string);
bool dvddate_exists(vector<Dvd>&, string);


#endif	/* WS13_H */

