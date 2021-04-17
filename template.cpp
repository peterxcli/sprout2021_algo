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

void radix_sort(int array[], int n){
    vector<int> bucket[10];
    for(int radix = 1, r = 0; r < 10; radix *= 10, r++) {
        for(int i = 0; i < 10; i++)
            bucket[i].clear();
        for(int i = 0; i < n; i++){
            int digit = (array[i]/radix) % 10;
            bucket[digit].push_back(array[i]);
        }
        int len = 0;
        for(int i = 0; i < 10; i++) {
            int m = bucket[i].size();
            for(int j = 0; j < m; j++)
                array[len++] = bucket[i][j];
        }
    }
}

void radix_sort(vector<int> &array){
    int n = array.size();
    vector<int> bucket[10];
    for(int radix = 1, r = 0; r < 10; radix *= 10, r++) {
        for(int i = 0; i < 10; i++)
            bucket[i].clear();
        for(int i = 0; i < n; i++){
            int digit = (array[i]/radix) % 10;
            bucket[digit].push_back(array[i]);
        }
        int len = 0;
        for(int i = 0; i < 10; i++) {
            int m = bucket[i].size();
            for(int j = 0; j < m; j++)
                array[len++] = bucket[i][j];
        }
    }
}

void merge_sort(int array[], int n){
    if(n < 2) return;
    int len1 = n / 2;
    int len2 = n - len1;
    int *array1 = array;
    int *array2 = array + len1;
    merge_sort(array1 , len1);
    merge_sort(array2 , len2);

    int *tmp = new int[n];
    int len = 0;
    int pos1 = 0, pos2 = 0;
    while( len < n ){
        if( pos2 == len2 || ( pos1 < len1 && array1[pos1] <= array2[pos2] ) )
            tmp[len++] = array1[pos1++];
        else
            tmp[len++] = array2[pos2++];
    }
    for( int i=0; i<n; i++)
        array[i] = tmp[i];
    delete[] tmp;
}
