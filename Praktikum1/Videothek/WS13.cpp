/* 
 * File:   WS13.h
 * Author: Dorothee Müller-Ahlheim
 *
 * Created on 17. März 2014, 14:02
 * 
 * Beinhaltet Definitionen
 * 
 */

#include "WS13.h"


Borrower::Borrower()
        : name(""),
        num_vids(0),
        num_dvds(0)
{}

Borrower::Borrower(string s, int a, int b)
        :name(s),
        num_vids(a),
        num_dvds(b)
{}

string Borrower::get_name() const {
    return name;
}

int Borrower::get_nvids() const {
    return num_vids;
}

int Borrower::get_ndvds() const {
    return num_dvds;
}

void Borrower::set_name(string eingabe_name){
    name = eingabe_name;
}

void Borrower::inc_nvids() {
    num_vids += 1;
}

void Borrower::inc_ndvds() {
    num_dvds += 1;
}

Video::Video()
        :title(""),
        date("1.1.2014"),
        on_shelf(true)
{}

Video::Video(string stitle, string sdate)
        :title(stitle),
        date(sdate),
        on_shelf(true)
{}

string Video::get_vidtitle() const {
    return title;
}

string Video::get_viddate() const {
    return date;
}

bool Video::get_vidonshelf() const {
    return on_shelf;
}

void Video::set_vidonshelf(bool leihe){
    on_shelf = leihe;
}

void populate_videos(vector<Video>& vVideos){
    vVideos.push_back(Video("Casshern", "03.2004"));
}

void print_vids(vector<Video>& vVideos) {
    for (size_t i(0); i<vVideos.size(); i++) {
        cout << "Titel: " << vVideos.at(i).get_vidtitle() << "\t" << "Erscheinungsdatum: " << vVideos.at(i).get_viddate() << endl;
    }
}

Dvd::Dvd()
        :title(""),
        date("1.1.2014"),
        on_shelf(true)
{}

Dvd::Dvd(string stitle, string sdate)
        :title(stitle),
        date(sdate),
        on_shelf(true)
{}

string Dvd::get_dvdtitle() const {
    return title;
}

string Dvd::get_dvddate() const {
    return date;
}

bool Dvd::get_dvdonshelf() const {
    return on_shelf;
}

void Dvd::set_dvdonshelf(bool leihe){
    on_shelf = leihe;
}

void populate_dvds(vector<Dvd>& vDvds){
    vDvds.push_back(Dvd("Casshern", "03.2004"));
}

void print_dvds(vector<Dvd>& vDvds) {
    for (size_t i(0); i<vDvds.size(); i++) {
        cout << "Titel: " << vDvds.at(i).get_dvdtitle() << "\t" << "Erscheinungsdatum: " << vDvds.at(i).get_dvddate() << endl;
    }
}

void populate_borrower(vector<Borrower>& vBorrowers){
    vBorrowers.push_back(Borrower("LillyVanilly", 0, 0));
    vBorrowers.push_back(Borrower("PromiBonni", 0, 0));
    vBorrowers.push_back(Borrower("HansKanns", 0, 0));
}

void print_borrowers(vector<Borrower>& vBorrowers){
    for (size_t i(0); i<vBorrowers.size(); i++){
        cout << "Leihender: " << vBorrowers.at(i).get_name() << endl;
        cout << "Anzahl ausgeliehener Videos: " << vBorrowers.at(i).get_nvids() << endl;
        cout << "Anzahl ausgeliehener Dvds: " << vBorrowers.at(i).get_ndvds() << endl;        
    }
}

void add_borrower(vector<Borrower>& vBorrowers, string eingabe_name){
    bool name_vorhanden(false);
    for(size_t i(0); i<vBorrowers.size(); i++){
        if (vBorrowers.at(i).get_name() == eingabe_name){
        cout << "Der Name ist schon registriert! Bitte einen neuen eingeben!" << endl;
        name_vorhanden = true;
        return;
        }
    }
    if (name_vorhanden == false){
        vBorrowers.push_back(Borrower(eingabe_name, 0, 0));
    }
}

Loan_vid::Loan_vid()
        :sLender(""),
        pBorrowed(0)
{}

Loan_vid::Loan_vid(string slend, Video* pborrow)
        :sLender(slend),
        pBorrowed(pborrow)
{}

string Loan_vid::get_lender() const {
    return sLender;
}

Video* Loan_vid::get_borrowed() const {
    return pBorrowed;
}

void Loan_vid::print() {
    cout << sLender << " hat das Video " << pBorrowed->get_vidtitle() << " ("
            << pBorrowed->get_viddate() << ") ausgeliehen." << endl; 
}

void print_loansvid(vector<Loan_vid>& vLoans_vid){
    for (size_t i(0); i<vLoans_vid.size(); i++){
        vLoans_vid.at(i).print();
    }
}

Video* get_vid(vector<Video>& vVideos, string title, string date) {
    Video* pVid(0);
    for(size_t i(0); i<vVideos.size(); i++){
        if(vVideos.at(i).get_vidtitle() == title){
            if(vVideos.at(i).get_viddate() == date){
                pVid = &(vVideos.at(i));
            }
        }
    }
    return pVid;
}

Loan_dvd::Loan_dvd()
        :sLender(""),
        pBorrowed(0)
{}

Loan_dvd::Loan_dvd(string slend, Dvd* pborrow)
        :sLender(slend),
        pBorrowed(pborrow)
{}

string Loan_dvd::get_lender() const {
    return sLender;
}

Dvd* Loan_dvd::get_borrowed() const {
    return pBorrowed;
}

void Loan_dvd::print() {
    cout << sLender << " hat die Dvd " << pBorrowed->get_dvdtitle() << " ("
            << pBorrowed->get_dvddate() << ") ausgeliehen." << endl; 
}

void print_loansdvd(vector<Loan_dvd>& vLoans_dvd){
    for (size_t i(0); i<vLoans_dvd.size(); i++){
        vLoans_dvd.at(i).print();
    }
}

Dvd* get_dvd(vector<Dvd>& vDvds, string title, string date) {
    Dvd* pDvd(0);
    for(size_t i(0); i<vDvds.size(); i++){
        if(vDvds.at(i).get_dvdtitle() == title){
            if(vDvds.at(i).get_dvddate() == date){
                pDvd = &(vDvds.at(i));
            }
        }
    }
    return pDvd;
}

void populate_loansvid(vector<Loan_vid>& vLoans_vid, vector<Video>& vVideos, vector<Borrower>& vBorrowers){
    
    
    print_vids(vVideos);
    print_loansvid(vLoans_vid);
}

void populate_loansdvd(vector<Loan_dvd>& vLoans_dvd, vector<Dvd>& vDvds, vector<Borrower>& vBorrowers){
    
    
    print_dvds(vDvds);
    print_loansdvd(vLoans_dvd);
}

void add_loansvid(vector<Loan_vid>& vLoans_vid, vector<Borrower>& vBorrowers, vector<Video>& vVideos, string title, string date, string eingabe_name){
    for(size_t i(0); i<vBorrowers.size(); i++){
        if(vBorrowers.at(i).get_name() == eingabe_name){
            vLoans_vid.push_back(Loan_vid(vBorrowers.at(i).get_name(), get_vid(vVideos, title, date)));
            vBorrowers.at(i).inc_nvids();
            vVideos.at(i).set_vidonshelf(false);
            print_loansvid(vLoans_vid);
        }
    }
}

void add_loansdvd(vector<Loan_dvd>& vLoans_dvd, vector<Borrower>& vBorrowers, vector<Dvd>& vDvds, string title, string date, string eingabe_name){
    for(size_t i(0); i<vBorrowers.size(); i++){
        if(vBorrowers.at(i).get_name() == eingabe_name){
            vLoans_dvd.push_back(Loan_dvd(vBorrowers.at(i).get_name(), get_dvd(vDvds, title, date)));
            vBorrowers.at(i).inc_ndvds();
            vDvds.at(i).set_dvdonshelf(false);
            print_loansdvd(vLoans_dvd);
        }
    }
}

bool borrower_exists(vector<Borrower>& vBorrowers, string eingabe_name){
    bool is_borrower = false;
    for(size_t i(0); i<vBorrowers.size(); i++){
        if(vBorrowers.at(i).get_name() == eingabe_name) {
            is_borrower = true;
            break;
        }
    }
    return is_borrower;
}

bool vidtitle_exists(vector<Video>& vVideos, string title){
    bool is_vidtitle = false;
    for(size_t i(0); i<vVideos.size(); i++){
        if(vVideos.at(i).get_vidtitle() == title) {
            is_vidtitle = true;
            if(vVideos.at(i).get_vidonshelf() == false){
                cout << "Das Video ist schon verliehen!" << endl;
                is_vidtitle = false;
            }
        }
    }
    return is_vidtitle;
}

bool dvdtitle_exists(vector<Dvd>& vDvds, string title){
    bool is_dvdtitle = false;
    for(size_t i(0); i<vDvds.size(); i++){
        if(vDvds.at(i).get_dvdtitle() == title) {
            is_dvdtitle = true;
            if(vDvds.at(i).get_dvdonshelf() == false){
                cout << "Die Dvd ist schon verliehen!" << endl;
                is_dvdtitle = false;
            }
        }
    }
    return is_dvdtitle;
}

bool viddate_exists(vector<Video>& vVideos, string date){
    bool is_viddate = false;
    for(size_t i(0); i<vVideos.size(); i++){
        if(vVideos.at(i).get_viddate() == date) {
            is_viddate = true;
            if(vVideos.at(i).get_vidonshelf() == false){
                cout << "Das Video ist schon verliehen!" << endl;
                is_viddate = false;
            }
        }
    }
    return is_viddate;
}

bool dvddate_exists(vector<Dvd>& vDvds, string date){
    bool is_dvddate = false;
    for(size_t i(0); i<vDvds.size(); i++){
        if(vDvds.at(i).get_dvddate() == date) {
            is_dvddate = true;
            if(vDvds.at(i).get_dvdonshelf() == false){
                cout << "Die Dvd ist schon verliehen!" << endl;
                is_dvddate = false;
            }
        }
    }
    return is_dvddate;
}





















