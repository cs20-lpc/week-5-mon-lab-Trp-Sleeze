#include <stdexcept>
#include <ostream>

template <typename T>
DoublyList<T>::DoublyList()
: header(new Node), trailer(new Node), length(0) {
    header->next  = trailer;
    trailer->prev = header;
}

template <typename T>
DoublyList<T>::DoublyList(const DoublyList<T>& copyObj)
: header(new Node), trailer(new Node), length(0) {
    header->next  = trailer;
    trailer->prev = header;
    copy(copyObj);
}

template <typename T>
DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
DoublyList<T>::~DoublyList() {
    clear();
    delete header;
    delete trailer;
    header = trailer = nullptr;
}

template <typename T>
void DoublyList<T>::append(const T& elem) {
    Node* n    = new Node(elem);
    Node* last = trailer->prev;
    last->next = n;
    n->prev    = last;
    n->next    = trailer;
    trailer->prev = n;
    ++length;
}

template <typename T>
void DoublyList<T>::clear() {
    while (header->next != trailer) {
        Node* first = header->next;
        header->next = first->next;
        first->next->prev = header;
        delete first;
    }
    length = 0;
}

template <typename T>
void DoublyList<T>::copy(const DoublyList<T>& copyObj) {
    Node* cur = copyObj.header->next;
    while (cur != copyObj.trailer) {
        append(cur->value);
        cur = cur->next;
    }
}

template <typename T>
T DoublyList<T>::getElement(int position) const {
    if (position < 0 || position >= length) return T();
    Node* curr = header->next;
    for (int i = 0; i < position; ++i) curr = curr->next;
    return curr->value;
}

template <typename T>
int DoublyList<T>::getLength() const { return length; }

template <typename T>
void DoublyList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > length) return;
    if (position == length) { append(elem); return; }

    Node* after = header->next;
    for (int i = 0; i < position; ++i) after = after->next;

    Node* before = after->prev;
    Node* n = new Node(elem);

    n->prev = before;
    n->next = after;
    before->next = n;
    after->prev  = n;

    ++length;
}

template <typename T>
bool DoublyList<T>::isEmpty() const {
    return length == 0 && header->next == trailer && trailer->prev == header;
}

template <typename T>
void DoublyList<T>::remove(int position) {
    if (position < 0 || position >= length) return;

    Node* victim = header->next;
    for (int i = 0; i < position; ++i) victim = victim->next;

    Node* before = victim->prev;
    Node* after  = victim->next;

    before->next = after;
    after->prev  = before;

    delete victim;
    --length;
}

template <typename T>
bool DoublyList<T>::search(const T& elem) const {
    Node* curr = header->next;
    while (curr != trailer) {
        if (curr->value == elem) return true;
        curr = curr->next;
    }
    return false;
}

template <typename T>
void DoublyList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= length) return;
    Node* curr = header->next;
    for (int i = 0; i < position; ++i) curr = curr->next;
    curr->value = elem;
}

template <typename T>
std::ostream& operator<<(std::ostream& outStream, const DoublyList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    } else {
        typename DoublyList<T>::Node* curr = myObj.header->next;
        while (curr != myObj.trailer) {
            outStream << curr->value;
            if (curr->next != myObj.trailer) outStream << " <--> ";
            curr = curr->next;
        }
        outStream << '\n';
    }
    return outStream;
}
