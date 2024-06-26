#include "HashMap.h"

int main() {
    HashMap<int, int> h;
    // h["word"] = 50;
    h[30] = 50;
    std::cout << h[30] << std::endl;
    h.print();

    return 0;
}