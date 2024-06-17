#include "HashMap.h"

int main() {
    HashMap h;
    h["word"] = 50;
    std::cout << h["word"] << std::endl;
    h.print();

    return 0;
}