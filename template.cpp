#include <bits/stdc++.h>

using namespace std;

template <class T> struct Node{
    T data;
    Node *nxt;
    Node() {
        nxt = nullptr;
    }
};

template <class T> struct linked_list{
    Node<T> *head, *tail;
    size_t _size;
    linked_list() {
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }
    void merge(linked_list<T> *src) {
        if (src->empty()) return;
        if (empty()) {
            head = src->head;
            tail = src->tail;
            _size = src->_size;
            src->head = nullptr;
            src->tail = nullptr;
            src->_size = 0;
        }
        else {
            tail->nxt = src->head;
            _size += src->_size;
            src->head = nullptr;
            src->tail = nullptr;
            src->_size = 0;
        }
        
    }
    void push_front(T x) {
        if (head == nullptr) {
            head = new Node<T>(); //Create new node of type T
            head->data = x;
            tail = head;
        }
        else {
            Node<T> *temp = new Node<T>();
            temp->nxt = head;
            temp->data = x;
            head = temp;
        }
        _size++;
    }
    void push_back(T x) {
        if (head == nullptr) {
            head = new Node<T>();
            head->data = x;
            tail = head;
        }
        else {
            Node<T>* temp = new Node<T>();
            temp->data = x;
            temp->nxt = nullptr;
            tail->nxt = temp;
            tail = temp;
        }
        _size ++;
    }
    void pop_front() {
        if (empty()) cout << stderr << "empty!";
        Node<T> *temp = head;
        head = head->nxt;
        delete temp;
        _size--;
    }
    void pop_back() {
        // if (empty()) return cout << stderr << "empty!", 0;
        // node<T> *temp = tail;
        // head = head->nxt;
        // delete temp;
        // _size--;
    }
    int size() {
        return _size;
    }
    bool empty() {
        return (_size == 0);
    }
    int front() {
        if (empty()) return cout << stderr << "empty!", 0;
        return head->data;
    }
    int back() {
        if (empty()) return cout << stderr << "empty!", 0;
        return tail->data;
    }
    void print() {
    Node<T> *curr = head;
    while(curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->nxt;
    }
    cout << "\n";
}
};