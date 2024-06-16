#include "HashMap.h"

int main() {
    HashMap h;
    h["hello"] = 100;
    h["hello"] = 50;
    h["word"] = 1000;
    h.print();


    return 0;
}