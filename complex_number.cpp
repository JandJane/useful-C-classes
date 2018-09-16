#include <math.h>

class Complex {
 private:
    double re, im;

 public:
    Complex(double x = 0.0, double y = 0.0)
    : re(x)
    , im(y) {}

    double Re() const {
        return re;
    }

    double Im() const {
        return im;
    }

    Complex operator - () const {
        return {-re, -im};
    }

    Complex operator + () const {
        return *this;
    }
};

double abs(const Complex& u) {
    return sqrt(u.Re() * u.Re() + u.Im() * u.Im());
}

Complex operator + (const Complex& u, const Complex& v) {
    return {u.Re() + v.Re(), u.Im() + v.Im()};
}

Complex operator - (const Complex& u, const Complex& v) {
    return {u.Re() - v.Re(), u.Im() - v.Im()};
}

Complex operator - (const double u, const Complex& v) {
    return (Complex(u) - v);
}

Complex operator + (const double u, const Complex& v) {
    return (Complex(u) + v);
}

Complex operator - (const Complex& u, const double v) {
    return (u - Complex(v));
}

Complex operator + (const Complex& u, const double v) {
    return (u + Complex(v));
}

Complex operator * (const Complex& u, const Complex& v) {
    return {u.Re() * v.Re() - u.Im() * v.Im(),
    v.Re() * u.Im() + u.Re() * v.Im()};
}

Complex operator / (const Complex& u, const Complex& v) {
    return {(u.Re() * v.Re() + u.Im() * v.Im()) /
    (v.Re() * v.Re() + v.Im() * v.Im()),
    (v.Re() * u.Im() - u.Re() * v.Im()) /
    (v.Re() * v.Re() + v.Im() * v.Im())};
}

Complex operator / (const double u, const Complex& v) {
    return (Complex(u) / v);
}

Complex operator * (const double u, const Complex& v) {
    return (Complex(u) * v);
}

Complex operator / (const Complex& u, const double v) {
    return (u / Complex(v));
}

Complex operator * (const Complex& u, const double v) {
    return (u * Complex(v));
}

bool operator == (const Complex& u, const Complex& v) {
        return (u.Re() == v.Re()) && (u.Im() == v.Im());
}

bool operator != (const Complex& u, const Complex& v) {
        return (u.Re() != v.Re()) || (u.Im() != v.Im());
}

bool operator == (const Complex& u, const double v) {
    return (u == Complex(v));
}

bool operator == (const double u, const Complex& v) {
    return (v == Complex(u));
}

bool operator != (const Complex& u, const double v) {
    return (u != Complex(v));
}

bool operator != (const double u, const Complex& v) {
    return (v != Complex(u));
}
