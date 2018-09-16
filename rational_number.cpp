#include <cmath>

int GCD(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (a && b)
        if (a >= b)
           a %= b;
        else
           b %= a;
    return a | b;
}

class Rational {
 private:
    int num, den;

 public:
    Rational(int x = 0, int y = 1)
    : num(x)
    , den(y) {
        int k = GCD(num, den);
        if (num * den < 0) {
            num = -1 * std::abs(num) / k;
        } else {
            num = std::abs(num) / k;
        }
        den = std::abs(den) / k;
    }

    int numerator() const {
        return num;
    }

    int denominator() const {
        return den;
    }

    Rational operator - () const {
        return {-num, den};
    }

    Rational operator + () const {
        return *this;
    }

    Rational& operator += (const Rational& v) {
        *this = Rational(num * v.den + den * v.num, den * v.den);
        return *this;
    }

    Rational& operator -= (const Rational& v) {
        *this = Rational(num * v.den - den * v.num, den * v.den);
        return *this;
    }

    Rational& operator *= (const Rational& v) {
        *this = Rational(num * v.num, den * v.den);
        return *this;
    }

    Rational& operator /= (const Rational& v) {
        *this = Rational(num * v.den, den * v.num);
        return *this;
    }

    Rational& operator++ () {
        num += den;
        return *this;
    }

    Rational& operator-- () {
        num -= den;
        return *this;
    }

    Rational operator--(int) {
        Rational temp = *this;
        --*this;
        return temp;
    }

    Rational operator++(int) {
        Rational temp = *this;
        ++*this;
        return temp;
    }
};

Rational operator + (const Rational& u, const Rational& v) {
    return {u.numerator() * v.denominator() + v.numerator() * u.denominator(),
    v.denominator() * u.denominator()};
}

Rational operator - (const Rational& u, const Rational& v) {
    return {u.numerator() * v.denominator() - v.numerator() * u.denominator(),
    v.denominator() * u.denominator()};
}

Rational operator - (const int u, const Rational& v) {
    return (Rational(u) - v);
}

Rational operator + (const int u, const Rational& v) {
    return (Rational(u) + v);
}

Rational operator - (const Rational& u, const int v) {
    return (u - Rational(v));
}

Rational operator + (const Rational& u, const int v) {
    return (u + Rational(v));
}

Rational operator * (const Rational& u, const Rational& v) {
    return {u.numerator() * v.numerator(), v.denominator() * u.denominator()};
}

Rational operator / (const Rational& u, const Rational& v) {
    return {u.numerator() * v.denominator(), v.numerator() * u.denominator()};
}

Rational operator / (const int u, const Rational& v) {
    return (Rational(u) / v);
}

Rational operator * (const int u, const Rational& v) {
    return (Rational(u) * v);
}

Rational operator / (const Rational& u, const int v) {
    return (u / Rational(v));
}

Rational operator * (const Rational& u, const int v) {
    return (u * Rational(v));
}

bool operator == (const Rational& u, const Rational& v) {
        return (u.numerator() == v.numerator()) && (u.denominator() == v.denominator());
}

bool operator != (const Rational& u, const Rational& v) {
        return (u.numerator() != v.numerator()) || (u.denominator() != v.denominator());
}

bool operator == (const Rational& u, const int v) {
    return (u == Rational(v));
}

bool operator == (const int u, const Rational& v) {
    return (v == Rational(u));
}

bool operator != (const Rational& u, const int v) {
    return (u != Rational(v));
}

bool operator != (const int u, const Rational& v) {
    return (v != Rational(u));
}
