#pragma once

#include <vector>

using namespace std;

template <class T> class Mydeque
{
private:
    vector<T> begindq;
    vector<T> enddq;
    size_t index; //
public:
    Mydeque(int value) {
        begindq.reserve(value);
        enddq.reserve(value);
    };
    ~Mydeque() {};
    void push_back(const T element) { enddq.push_back(element); }
    void push_front(const T element) { begindq.push_back(element); }
    void push_front(const T* element, int length) {
        for (int i = 0; i < length; i++) {
            begindq.push_back(element[i]);
        }
    }



    int size() { return (begindq.size() + enddq.size()); }

};
