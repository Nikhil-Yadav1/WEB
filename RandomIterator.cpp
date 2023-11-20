#include <iostream>
#include <iterator>

template <typename T>
class RandomIterator : public std::iterator<std::random_access_iterator_tag, T> {
public:
    // Constructor
    RandomIterator(T* ptr) : ptr_(ptr) {}

    // Overload operators for iterator functionality
    RandomIterator& operator++() {
        ++ptr_;
        return *this;
    }

    RandomIterator operator++(int) {
        RandomIterator tmp = *this;
        ++ptr_;
        return tmp;
    }

    RandomIterator& operator--() {
        --ptr_;
        return *this;
    }

    RandomIterator operator--(int) {
        RandomIterator tmp = *this;
        --ptr_;
        return tmp;
    }

    T& operator*() {
        return *ptr_;
    }

    T* operator->() {
        return ptr_;
    }

    RandomIterator operator+(int n) const {
        return RandomIterator(ptr_ + n);
    }

    RandomIterator operator-(int n) const {
        return RandomIterator(ptr_ - n);
    }

    int operator-(const RandomIterator& other) const {
        return ptr_ - other.ptr_;
    }

    bool operator==(const RandomIterator& other) const {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const RandomIterator& other) const {
        return ptr_ != other.ptr_;
    }

    bool operator<(const RandomIterator& other) const {
        return ptr_ < other.ptr_;
    }

    bool operator>(const RandomIterator& other) const {
        return ptr_ > other.ptr_;
    }

    bool operator<=(const RandomIterator& other) const {
        return ptr_ <= other.ptr_;
    }

    bool operator>=(const RandomIterator& other) const {
        return ptr_ >= other.ptr_;
    }

private:
    T* ptr_;
};

int main() {
    int data[] = {1, 2, 3, 4, 5};
    RandomIterator<int> it(data);

    for (; it != data + 5; ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    return 0;
}