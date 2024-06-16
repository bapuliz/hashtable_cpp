#include "HashMap.h"

int main() {
    HashMap h;
    h.insert("hello", 10);
    h.insert("world", 99);
    h.insert("cpppp", 50);
    h.insert("node", 100);
    h.insert("roof", 199);
    h.insert("something", 200);
    h.insert("word", 2000);
    h.insert("word", 2000);

    h.insert("word", 2000);
    h.insert("word", 2000);
    h.insert("word", 2000);
    h.insert("word", 2000);
    h.insert("word", 2000);
    h.insert("word", 17);
    h.remove("word");
    h.remove("something");
    h.remove("cpppp");
    h.remove("world");

    h.print();

    return 0;
}