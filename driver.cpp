#include <iostream>
#include "DoublyList.hpp"

int main() {
    DoublyList<int> L;
    L.append(10);
    L.append(20);
    L.insert(1, 15);     // 10,15,20

    std::cout << L;      // prints list
    std::cout << "len=" << L.getLength() << '\n';

    std::cout << "pos0=" << L.getElement(0) << '\n';
    std::cout << (L.search(20) ? "found 20\n" : "no 20\n");

    L.replace(1, 99);    // 10,99,20
    std::cout << L;

    L.remove(0);         // 99,20
    std::cout << "len=" << L.getLength() << '\n';
    std::cout << L;

    return 0;
}
