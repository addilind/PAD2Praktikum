#include "testhelper.h"
#include <iostream>

using std::cout;
using std::endl;

void printTestResult(bool successful, string testType, string description, string expected, string actual) {
    if (!successful)
        cout << "FAILED test ";
    else cout << "  succeeded test ";
    cout << testType << '(' << description << ')';
    cout << ", expected: " << expected;
    cout << ", actual: " << actual << endl;
}

bool checkEquals(string exp, string act, string description, bool silent) {
    bool result(exp == act);
    if (!silent)
        printTestResult(result, "checkEquals", description, exp, act);
    return result;
}

bool checkTrue( bool condition, string description, bool silent) {
    if( !silent )
        printTestResult(condition, "checkTrue", description );
    return condition; 
}
