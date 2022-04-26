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
    //������� ������ �������� � ����� �������
    void push_back(const T element) {
        if (enddq.capacity() == enddq.size())
            enddq.reserve(enddq.size() * 2);
        enddq.push_back(element);
    }
    //������� ������� ������� length � ����� �������
    void push_back(const T* element, int length) {
        if (enddq.capacity() == enddq.size())
            enddq.reserve(enddq.size() * 2);
        for (int i = 0; i < length; i++) {
            enddq.push_back(element[i]);
        }
    }

    //������� ������ �������� � ������ �������
    void push_front(const T element) {
        if (begindq.capacity() == begindq.size())
            begindq.reserve(begindq.size() * 2);
        begindq.push_back(element);
    }

    //������� ������� � ������ �������
    void push_front(const T* element, int length) {
        if (begindq.capacity() == begindq.size())
            begindq.reserve(begindq.size() * 2);
        for (int i = 0; i < length; i++) {
            begindq.push_back(element[i]);
        }

    }
    //������ �������
    int size() { return (begindq.size() + enddq.size()); }

    friend ostream& operator<< (std::ostream& out, const Mydeque& r) {
        for (int i = 0; i < r.begindq.size(); i++)
            out << r.begindq[i];

        for (int i = 0; i < r.enddq.size(); i++)
            out << r.enddq[i];

        return out;
    }
};
