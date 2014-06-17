/* 
 * File:   main.cpp
 * Author: Dorothee Müller-Ahlheim
 * Matrnr.: 736476
 *
 * Created on 6. Juni 2014, 14:54
 */

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using std::string;
using std::cerr;
using std::endl;
using std::cout;
using std::cin;
using std::vector;

template<typename T>
void swap(vector<T>& vs, unsigned int a, unsigned int b) {
    T tmp = vs.at(a);
    vs.at(a) = vs.at(b);
    vs.at(b) = tmp;
}

template<typename T>
void quicksort(vector<T>& vs, unsigned int begin, unsigned int end) {
    T pivot = vs.at(end);
    unsigned int ui = begin;
    unsigned int oi = end - 1;

    while (ui < oi) { //Solange die Zeiger nicht aufs selbe Element zeigen
        bool complete = false;
        while (vs.at(ui) < pivot) {//Solange nach rechts bis ein Partner groeßer als Pivot
            ++ui;
            if (ui == oi) {
                complete = true;
                break;
            }
        }
        while (vs.at(oi) > pivot) {
            --oi;
            if (ui == oi) {
                complete = true;
                break;
            }
        }
        if (complete)
            break;

        swap<T>(vs, ui, oi);
        ui++;
        if (ui == oi) {
            break;
        }
        oi--;
    }
    if (vs.at(oi) > pivot) { //wenn das Element groeßer ist als das Privot
        swap<T>(vs, oi, end); //Pivot mit unterem element des oberen index tauschen
    }
    if (begin < oi - 1 && oi >= 2)
        quicksort<T>(vs, begin, oi - 1);
    if (oi + 1 < end)
        quicksort<T>(vs, oi + 1, end);
}

template<typename T>
void test(T result, T expected, std::string message) {
    std::cout << message << ": ";
    if (result != expected)
        std::cout << "failed [" << result << "]" << std::endl;
    else
        std::cout << "succeeded" << std::endl;
}

int main() {
    try {
        vector<char> vs;
        vs.push_back('A');
        vs.push_back('S');
        vs.push_back('O');
        vs.push_back('R');
        vs.push_back('T');
        vs.push_back('I');
        vs.push_back('N');
        vs.push_back('G');
        vs.push_back('E');
        vs.push_back('X');
        vs.push_back('A');
        vs.push_back('M');
        vs.push_back('P');
        vs.push_back('L');
        vs.push_back('E');

        quicksort<char>(vs, 0, (vs.size() - 1));

        for (size_t i = 0; i < vs.size(); i++) {
            cout << vs.at(i) << ' ';
        }
        cout << endl;

        test<char>(vs.at(0), 'A', "A");
        test<char>(vs.at(1), 'A', "A");
        test<char>(vs.at(2), 'E', "E");
        test<char>(vs.at(3), 'E', "E");
        test<char>(vs.at(4), 'G', "G");
        test<char>(vs.at(5), 'I', "I");
        test<char>(vs.at(6), 'L', "L");
        test<char>(vs.at(7), 'M', "M");
        test<char>(vs.at(8), 'N', "N");
        test<char>(vs.at(9), 'O', "O");
        test<char>(vs.at(10), 'P', "P");
        test<char>(vs.at(11), 'R', "R");
        test<char>(vs.at(12), 'S', "S");
        test<char>(vs.at(13), 'T', "T");
        test<char>(vs.at(14), 'X', "X");

        vector<int> vi;
        vi.push_back(10);
        vi.push_back(7);
        vi.push_back(8);
        vi.push_back(6);
        vi.push_back(2);
        vi.push_back(5);
        vi.push_back(1);
        vi.push_back(14);
        vi.push_back(4);

        quicksort<int>(vi, 0, (vi.size() - 1));

        for (size_t i = 0; i < vi.size(); i++) {
            cout << vi.at(i) << ' ';
        }
        cout << endl;


        test<int>(vi.at(0), 1, "1");
        test<int>(vi.at(1), 2, "2");
        test<int>(vi.at(2), 4, "4");
        test<int>(vi.at(3), 5, "5");
        test<int>(vi.at(4), 6, "6");
        test<int>(vi.at(5), 7, "7");
        test<int>(vi.at(6), 8, "8");
        test<int>(vi.at(7), 10, "10");
        test<int>(vi.at(8), 14, "14");

        vector<string> vstr;
        vstr.push_back("Abc");
        vstr.push_back("xyz");
        vstr.push_back("HALLO!");

        quicksort<string>(vstr, 0, (vstr.size() - 1));

        for (size_t i = 0; i < vstr.size(); i++) {
            cout << vstr.at(i) << ' ';
        }
        cout << endl;

        test<string>(vstr.at(0), "Abc", "Abc");
        test<string>(vstr.at(1), "HALLO!", "HALLO!");
        test<string>(vstr.at(2), "xyz", "xyz");

        return 0;
    } catch (std::exception& e) {
        cerr << "Ausnahme: " << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannte Ausnahme: " << endl;
        return -1;
    }
}
