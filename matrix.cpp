#include <vector>
#include <tuple>
#include <ostream>
#include <iostream>

template <typename T>
class Matrix {
public:
    std::vector<std::vector<T>> data;

    Matrix(const std::vector<std::vector<T>>& input)
    : data(input) {}

    std::pair<std::size_t, std::size_t> size() const {
        return {data.size(), data[0].size()};
    }

    Matrix& operator += (const Matrix<T>& m) {
        for (std::size_t i = 0; i != m.data.size(); ++i) {
            for (std::size_t j = 0; j != m.data[0].size(); ++j) {
                this->data[i][j] += m.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator + (const Matrix<T>& other) const {
        std::vector<std::vector<T>> m;
        for (std::size_t i = 0; i != other.data.size(); ++i) {
            m.push_back({});
            for (std::size_t j = 0; j != other.data[0].size(); ++j) {
                m[i].push_back(this->data[i][j] + other.data[i][j]);
            }
        }
        return Matrix(m);
    }

    Matrix& operator *= (long long a) {
        for (std::size_t i = 0; i != this->data.size(); ++i) {
            for (std::size_t j = 0; j != this->data[0].size(); ++j) {
                this->data[i][j] *= a;
            }
        }
        return *this;
    }

    Matrix operator * (long long a) const {
        std::vector<std::vector<T>> m;
        for (std::size_t i = 0; i != this->data.size(); ++i) {
            m.push_back({});
            for (std::size_t j = 0; j != this->data[0].size(); ++j) {
                m[i].push_back(this->data[i][j] * a);
            }
        }
        return Matrix(m);
    }

    Matrix transpose() const {
        std::vector<std::vector<T>> m;
        for (std::size_t i = 0; i != this->data[0].size(); ++i) {
            m.push_back({});
            for (std::size_t j = 0; j != this->data.size(); ++j) {
                m[i].push_back(this->data[j][i]);
            }
        }
        return Matrix(m);
    }

    Matrix& transposed() {
        std::vector<std::vector<T>> m;
        for (std::size_t i = 0; i != this->data[0].size(); ++i) {
            m.push_back({});
            for (std::size_t j = 0; j != this->data.size(); ++j) {
                m[i].push_back(this->data[j][i]);
            }
        }
        *this = Matrix(m);
        return *this;
    }

    Matrix operator * (const Matrix<T>& other) const {
        std::vector<std::vector<T>> m;
        for (std::size_t i = 0; i != this->data.size(); ++i) {
            m.push_back({});
            for (std::size_t j = 0; j != other.data[0].size(); ++j) {
                m[i].push_back(0);
                for (std::size_t k = 0; k != other.data.size(); ++k) {
                    m[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return Matrix(m);
    }

    Matrix& operator *= (const Matrix<T>& other) {
        *this = *this * other;
        return *this;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& m) {
    bool flag1 = false;
    for (auto v : m.data) {
        bool flag2 = false;
        if (flag1) {
            out << "\n";
        } else {
            flag1 = true;
        }
        for (auto e : v) {
            if (flag2) {
                out << "\t";
            } else {
                flag2 = true;
            }
            out << e;
        }
    }
    return out;
}
