#ifndef DOUBLYLIST_HPP
#define DOUBLYLIST_HPP

#include <ostream>

template <typename T> class DoublyList;
template <typename T> std::ostream& operator<<(std::ostream&, const DoublyList<T>&);

template <typename T>
class DoublyList {
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;
        Node() : value(), prev(nullptr), next(nullptr) {}
        Node(const T& v) : value(v), prev(nullptr), next(nullptr) {}
    };

    Node* header;
    Node* trailer;
    int   length;

    void copy(const DoublyList<T>&);

public:
    DoublyList();
    DoublyList(const DoublyList<T>&);
    DoublyList<T>& operator=(const DoublyList<T>&);
    ~DoublyList();

    void append(const T& elem);
    void clear();

    T    getElement(int position) const;
    int  getLength() const;

    void insert(int position, const T& elem);
    bool isEmpty() const;
    void remove(int position);
    bool search(const T& elem) const;
    void replace(int position, const T& elem);

    friend std::ostream& operator<< <>(std::ostream&, const DoublyList<T>&);
};

#include "DoublyList.tpp"   // keep inside the guard

#endif // DOUBLYLIST_HPP
