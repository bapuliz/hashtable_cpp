#include "HashMap.h"

int main() {
    HashMap<std::string, int> h;
    h["word"] = 50;
    std::cout << h["word"] << std::endl;
    h.print();

    return 0;
}