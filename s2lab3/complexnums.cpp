
#include <iostream>


class complex 
{
private:
    double m_a;
    double m_b;

public:
    complex() = default;
    
    complex(double a, double b) {
        m_a = a;
        m_b = b;
    }

    complex(complex& other) {
        m_a = other.m_a;
        m_b = other.m_b;
    }

    complex& operator = (const complex& other) {
        m_a = other.m_a;
        m_b = other.m_b;
        return *this;
    
    }

    complex& operator += (complex& other) {
        m_a = m_a + other.m_a;
        m_b = m_b + other.m_b;
        return *this;
    }

    complex operator + (complex& other) {
        complex temp = *this;
        temp.m_a = temp.m_a + other.m_a;
        temp.m_b = temp.m_b + other.m_b;
        return temp;
    }

    complex& operator *= (complex& other) {
        double tmp_a = m_a;
        m_a = tmp_a * other.m_a - m_b * other.m_b;
        m_b = tmp_a * other.m_b + m_b * other.m_a;
        return *this;
    }

    complex operator * (complex& other) {
        complex temp = *this;
        temp *= other;
        return temp;
    }

    complex& operator ++ () {
        m_a += 1;
        return *this;
    }

    complex operator ++ (int a) {
        complex tmp = *this;
        m_a+=1;
        return tmp;
    }

    friend std::ostream& operator << (std::ostream& out, const complex& a);
    friend std::istream& operator >> (std::istream& in, complex& a);

    /*void get() {
        std::cout << m_a<<"\n";
        std::cout << m_b;
    }*/
    
    ~complex() {}

};

std::ostream& operator << (std::ostream& out, const complex& a) {
    if (a.m_b < 0) {
        out << a.m_a << a.m_b << "i";
    }
    else {
        out << a.m_a << "+" << a.m_b << "i";
    }
    return out;
}

std::istream& operator >> (std::istream& in, complex& a) {
    double x;
    double y;
    in >> x >> y;
    a.m_a = x;
    a.m_b = y;
    return in;
}

int main()
{
    complex a (1, 2);
    complex b(2,-3);
    complex c;
    complex z;
    c = a + b;
    std::cout << c << "\n";
    z = a * b;
    std::cout << z << "\n";
    a *= b;
    std::cout << a<<"\n";
    complex j;
    std::cout << b++<<"\n";
    std::cout << b++ << "\n";
    std::cin >> j;
    std::cout << j << "\n";
}

