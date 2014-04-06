/* 
 * File:   main.cpp
 * Author: Dorothee Mueller-Ahlheim
 * Matnr.: 736476
 *
 * Created on 17. März 2014, 09:04
 * 
 * Ein Programm zur Berechnung des Kapitalwerts, gerundet auf drei Stellen hinter dem Komma,
 * mit einem festen Zinssatz, auf die dritte Stelle hinter dem Komma gerundet.
 * 
 */

#include "NPV.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using std::cerr;
using std::endl;
using std::cout;
using std::cin;

int main() {
    try {
		cout << "PAD 2-1: Kapitalwertberechnung" << endl <<endl;
		cout << "Zuf\x84llige Werte verwenden [J/N]: ";
		char useRandom = 0;
		cin >> useRandom;
		if (!cin)
			throw std::runtime_error("Ungueltige Eingabe");

		switch (useRandom)
		{
			case 'Y':
			case 'y':
			case 'J':
			case 'j':
			{
				cout << "Anzahl zuf\x84lliger Werte: ";
				size_t randomCount = 0;
				cin >> randomCount;
				if (!cin)
					throw std::runtime_error("Ungueltige Eingabe");
				NPV instanz(randomCount);//Konstruktor zur Erzeugung der Zufallsdaten aufrufen

				// Zufaellig generierte Werte zur Kontrolle ausgeben
				cout.precision(10); //Zinzsatz mit ausreichend Nachkommastellen darstellen
				cout << endl << "Generierte Werte:" << endl
					 << "\tZinzsatz: " << instanz.get_irate() << endl
					 << "\tZufl\x81sse:" << endl;
				for (size_t i = 0; i < instanz.get_inv().size(); i++)
				{
					cout << "\t" << instanz.get_inv().at(i);
				}
				cout << endl << endl;

				//Ergebnis ausgeben
				cout << std::fixed; //Keine Exponentialschreibweise
				cout.precision(3);
				cout << "Kapitalwert C0: " << static_cast<double>(instanz.reckoning(3)) << endl;
				cout.precision(5);//Mit mehr Nachkommastellen ausgeben, um Rundung zu ueberpruefen
				cout << "[Gerundet " << static_cast<double>(instanz.reckoning(3))
					<< ", ungerundet " << static_cast<double>(instanz.reckoning()) << "]" << endl;
				break;
			}
			default:
			{
				cout << "Zinzsatz: ";
				double interestRate = 0.0;
				cin >> interestRate;
				if (!cin)
					throw std::runtime_error("Ungueltige Eingabe");

				NPV instanz(interestRate); //Instanz mit Zinzsatz und leerem investmentsVektor anlegen

				cout << "Zufl\x81sse eingeben [Abfl\x81sse als negativen Wert, zum fertigstellen q]:" << endl;
				char peekChar = 0;
				double valueInput = 0.0;
				while (cin)
				{
					cout << "Zufluss: ";
					cin >> peekChar;
					if (peekChar == 'q')
						break; // Eingabe beenden
					cin.putback(peekChar);// Zeichen != q, zurueckstellen

					cin >> valueInput; //Wert einlesen

					if (!cin)
						throw std::runtime_error("Ungueltige Eingabe");

					instanz.add_inv(valueInput); //Impliziter cast double -> long double (Praezision wird erhoeht)
				}
				cout << endl;

				//Ergebnis ausgeben
				cout << std::fixed; //Keine Exponentialschreibweise
				cout.precision(3);
				cout << "Kapitalwert C0: " << static_cast<double>(instanz.reckoning(3)) << endl;
				cout.precision(5);//Mit mehr Nachkommastellen ausgeben, um Rundung zu ueberpruefen
				cout << "[Gerundet " << static_cast<double>(instanz.reckoning(3)) 
					 << ", ungerundet " << static_cast<double>(instanz.reckoning()) << "]" << endl;
				break;
			}
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
