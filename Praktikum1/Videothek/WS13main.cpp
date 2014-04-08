/* 
 * File:   WS13main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matrnr.: 736476
 *
 * Created on 17. März 2014, 13:56
 */

#include "WS13.h"

/*
 * 
 */
int main() {
    try {
        vector<Video> vVideos;
        vector<Dvd> vDvds;
        vector<Borrower> vBorrowers;
        vector<Loan_vid> vLoans_vid;
        vector<Loan_dvd> vLoans_dvd;
        populate_videos(vVideos);
        populate_dvds(vDvds);
        print_vids(vVideos);
        print_dvds(vDvds);
        populate_borrower(vBorrowers);
        print_borrowers(vBorrowers);
        populate_loansvid(vLoans_vid, vVideos, vBorrowers);
        populate_loansdvd(vLoans_dvd, vDvds, vBorrowers);
        string eingabe_name("noName");
        string title("NoTitle");
        string date("01.01.2014");
        string eingabe_ent("leer");
        int eingabe(3);

        while (eingabe != 0) {
            cout << "Eingabeoptionen:\n1 um einen Namen der Datenbank hinzuzufuegen." << endl;
            cout << "2 um eine Ausleihe hinzuzufuegen!" << endl;
            cout << "0 um das Programm zu beenden!" << endl;

            cin >> eingabe;
            if (!cin) {
                throw std::runtime_error("Fehlerhafte Eingabe!\n");
            }

            switch (eingabe) {
                case 0:
                    return 0;
                case 1:
                    while (eingabe_name != "q") {
                        cout << "Geben Sie einen Namen ein, den Sie hinzufuegen wollen: ";
                        cin >> eingabe_name;
                        if (!cin) {
                            throw std::runtime_error("Fehlerhafte Eingabe!\n");
                        }
                        if (eingabe_name != "q") {
                            add_borrower(vBorrowers, eingabe_name);
                        } else return 0;
                    }
                case 2:
                    while (eingabe_name != "q") {
                        cout << "Geben Sie einen Ausleiher ein: " << endl;
                        cin >> eingabe_name;
                        if (!cin) {
                            throw std::runtime_error("Fehlerhafte Eingabe!\n");
                        }
                        if (eingabe_name != "q") {
                            if (borrower_exists(vBorrowers, eingabe_name) == false) {
                                cout << "Ausleiher nicht in Datenbank enthalten! Bitte neuen Namen eingeben!" << endl;
                            } else {
                                cout << "Geben Sie 'Video', wenn Sie ein Video"
                                        " oder 'Dvd' ein, wenn sie eine Dvd ausleihen wollen: ";
                                cin >> eingabe_ent;
                                if (!cin) {
                                    throw std::runtime_error("Fehlerhafte Eingabe!\n");
                                }
                                if (eingabe_ent != "q") {
                                    if (eingabe_ent == "Video"){
                                        cout << "Geben Sie einen Videotitel und das Erscheinungsdatum an: " << endl;
                                        cin >> title >> date;
                                        if(!cin){
                                            throw std::runtime_error("Fehlerhafte Eingabe!\n");
                                        }
                                        if ((vidtitle_exists(vVideos, title) == true && (viddate_exists(vVideos, date) == true))) {
                                            add_loansvid(vLoans_vid, vBorrowers, vVideos, title, date, eingabe_name);
                                        }
                                        else cout << "Dieses Video existiert nicht!" << endl;
                                    }
                                    else if (eingabe_ent == "Dvd"){
                                        cout << "Geben Sie einen Dvdtitel und das Erscheinungsdatum an: " << endl;
                                        cin >> title >> date;
                                        if(!cin){
                                            throw std::runtime_error("Fehlerhafte Eingabe!\n");
                                        }
                                        if ((dvdtitle_exists(vDvds, title) == true && (dvddate_exists(vDvds, date) == true))) {
                                            add_loansdvd(vLoans_dvd, vBorrowers, vDvds, title, date, eingabe_name);
                                        }
                                        else cout << "Diese Dvd existiert nicht!" << endl;
                                    }
                                }
                                else return 0;
                            }
                            
                        }
                        else return 0;
                    }
            }

        }








    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}
