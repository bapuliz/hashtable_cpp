#include "HashMap.h"

int main() {
    //  std::srand(std::time(0));

    // size_t size = 169;
    // std::vector<std::string> t;
    // for (int i=1; i < size+1; ++i) {
    //     t.push_back("word" + std::to_string(i) + "_" + generateRandomChar());
    // }
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

    
    // SLL s;
    // s.insertAtBeginning({"hello", 10});
    // s.insertAtBeginning({"lo", 5});
    // s.insertAtBeginning({"how", 199});
    // s.print();

    return 0;
}