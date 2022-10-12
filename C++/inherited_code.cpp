#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

class BadLengthException{
    public :
    int l;
    BadLengthException(int len) {
        l = len;
    }
    int what() {
        return l;
    }
};