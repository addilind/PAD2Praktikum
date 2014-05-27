/* 
 * File:   testhelper.h
 * Author: unknown
 *
 * Created on 27. Mai 2014, 01:01
 */

#ifndef TESTHELPER_H
#define	TESTHELPER_H

#include <string>
#include <sstream>
#include <stdexcept>

using std::string;

template<class T> string toString(T t) {
    std::stringstream stst;
    stst << t;
    return stst.str();
}

bool checkTrue( bool condition, string description, bool silent=false );
void printTestResult(bool successful, string testType, string description, string expected = "", string actual = "");
bool checkEquals(string exp, string act, string description, bool silent = false);

#endif	/* TESTHELPER_H */

