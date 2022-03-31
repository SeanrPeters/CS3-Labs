
//Sean Peters
//2/1/2022

#include node_template.hpp

#ifndef LAB_3_HPP_
#define LAB_3_HPP_

template <typename T>
class node {
public:

    node() : next_(nullptr) {}


    T getData()const { return data_; }
    void setData(const T& data) { data_ = data; }


    node<T>* getNext() const;
    void setNext(node<T>* const);

private:
    T data_;
    node<T>* next_;
};

template <typename T>
class Collection {
public:
    void add(const T);
    void remove(const T);
    T last() const;
    void print();
    friend bool equal(const Collection<T>&, const Collection<T>&);



private:
    node<T>* first;
};

