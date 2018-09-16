// A simple implementation of (dense) Polynomial
// that supports basic arithmetic operations.

#include <vector>
#include <ostream>
#include <iostream>

using namespace std;

template <typename T>
class Polynomial{
public:
    vector<T> a;

    Polynomial (const vector<T>& c): a(c) {
        cut();
    }

    Polynomial (T c = T()){
        a.push_back(c);
        cut();
    }

    Polynomial<T>& cut() {
        if (a.size() != 0) {
            auto it = --a.end();
            while (*it == T(0) && it != a.begin()) {
                --it;
            }
            a.erase(++it, a.end());
        }
        return *this;
    }

    template <typename Iter>
    Polynomial (Iter first, Iter last) {
        while (first != last){
            a.push_back(*first);
            ++first;
        }
        cut();
    }

    int Degree() const {
        return a.size() - 1;
    }

    T operator [] (int i) const {
        if (Degree() >= i) {
            return a[i];
        } else {
            return T();
        }
    }

    Polynomial<T>& operator += (const Polynomial<T>& other) {
        int i = 0;
        while (i <= Degree() && i <= other.Degree()) {
            this->a[i] += other[i];
            ++i;
        }
        while (i > Degree() && i <= other.Degree()) {
            this->a.push_back(other[i]);
            ++i;
        }
        cut();
        return *this;
    }

    Polynomial<T>& operator -= (const Polynomial<T>& other) {
        int i = 0;
        while (i <= Degree() && i <= other.Degree()) {
            this->a[i] -= other[i];
            ++i;
        }
        while (i > Degree() && i <= other.Degree()) {
            this->a.push_back(T(-1) * other[i]);
            ++i;
        }
        cut();
        return *this;
    }

    Polynomial<T>& operator += (const T& c) {
        a[0] += c;
        cut();
        return *this;
    }

    Polynomial<T>& operator -= (const T& c) {
        a[0] -= c;
        cut();
        return *this;
    }

    typename vector<T>::const_iterator begin() const {
        return a.begin();
    }

    typename vector<T>::const_iterator end() const {
        return a.end();
    }
};

template <typename T>
bool operator == (const Polynomial<T>& that, const Polynomial<T>& other) {
    return (that.a == other.a);
}

template <typename T>
bool operator == (const T& other, const Polynomial<T>& that) {
    if (that.Degree() == -1 && other == T()) {
        return true;
    } else if (that.Degree() == 0 && other == that[0]) {
        return true;
    }
    return false;

}

template <typename T>
bool operator == (const Polynomial<T>& that, const T& other) {
    return (other == that);
}

template <typename T>
bool operator != (const Polynomial<T>& that, const Polynomial<T>& other) {
    return (that.a != other.a);
}

template <typename T>
bool operator != (const T& other, const Polynomial<T>& that) {
    return !(that == other);

}

template <typename T>
bool operator != (const Polynomial<T>& that, const T& other) {
    return !(that == other);

}

template <typename T>
Polynomial<T> operator+ (const Polynomial<T>& that, const Polynomial<T>& other) {
        vector<T> temp;
        int i = 0;
        while (i <= that.Degree() && i <= other.Degree()) {
            temp.push_back(that[i] + other[i]);
            ++i;
        }
        while (i > that.Degree() && i <= other.Degree()) {
            temp.push_back(other[i]);
            ++i;
        }
        while (i <= that.Degree() && i > other.Degree()) {
            temp.push_back(that[i]);
            ++i;
        }
        return Polynomial<T>(temp).cut();
}

template <typename T>
Polynomial<T> operator- (const Polynomial<T>& that, const Polynomial<T>& other) {
        vector<T> temp;
        int i = 0;
        while (i <= that.Degree() && i <= other.Degree()) {
            temp.push_back(that[i] - other[i]);
            ++i;
        }
        while (i > that.Degree() && i <= other.Degree()) {
            temp.push_back(T(-1) * other[i]);
            ++i;
        }
        while (i <= that.Degree() && i > other.Degree()) {
            temp.push_back(that[i]);
            ++i;
        }
        return Polynomial<T>(temp).cut();
}

template <typename T>
Polynomial<T> operator+ (const Polynomial<T>& that, const T& c) {
    return (that + Polynomial<T>(c));
}

template <typename T>
Polynomial<T> operator+ (const T& c, const Polynomial<T>& that) {
    return (that + Polynomial<T>(c));
}

template <typename T>
Polynomial<T> operator- (const Polynomial<T>& that, const T& c) {
    return (that - Polynomial<T>(c));
}

template <typename T>
Polynomial<T> operator- (const T& c, const Polynomial<T>& that) {
    return (Polynomial<T>(c) - that);
}
