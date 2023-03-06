
#include <iostream>
class String 
{
private:
    size_t m_size = 1;
    char* m_str = nullptr;

public:
    String() = default;

    String(const char* str) {
        m_size = strlen(str);
        m_str = new char[m_size + 1];
        std::copy(str, str + m_size, m_str);
        m_str[m_size] = 0;
    }

    String(String& other_str)
    {
        m_size = other_str.m_size;
        m_str = new char[m_size + 1];
        std::copy(other_str.m_str, other_str.m_str + m_size, m_str);
    }

    String& operator = (const String& other_str) {
        delete[] m_str;
        m_size = other_str.m_size;
        m_str = new char[m_size + 1];
        std::copy(other_str.m_str, other_str.m_str + m_size, m_str);
        return *this;
    }
    String& operator += (const String& s1) {
        m_size = this->m_size + s1.m_size;
        auto tempstr = m_str;
        
        m_str = new char[m_size+1];
        std::copy(tempstr,tempstr + strlen(tempstr), m_str);
        std::copy(s1.m_str,s1.m_str + s1.m_size+1,m_str + strlen(tempstr));
        delete[] tempstr;
        return *this;
    }
    
    String operator + (const String& s2) {
        m_size = this->m_size + s2.m_size;

        char* tempstr = new char[m_size + 1];
        std::copy(m_str, m_str + strlen(m_str), tempstr);
        std::copy(s2.m_str, s2.m_str + s2.m_size+1, tempstr + strlen(m_str));
        return tempstr;
    }

    char& operator [] (size_t a) {
        return m_str[a];
    }

    bool operator < (String& s) {
        if (m_size < s.m_size) {
            return 0;
        }
        else
            return 1;
    }
    bool operator > (String& s) {
        if (m_size > s.m_size) {
            return 0;
        }
        else
            return 1;
    }
    bool operator == (String& s) {
        if (m_size == s.m_size) {
            return 1;
        }
        else
            return 0;
    }

    size_t length() {
        return m_size;
    }

    char* c_str() {
        return m_str;
    }

    int find(const char& a) {
        for (int i = 0; i < m_size; i++) {
            if (m_str[i] == a) {
                return i;
            }
        }
        return -1;
    
    }

    char at(int i) {
        if ((i >= 0) && (i < m_size)) {
            return m_str[i];
        }
        return -1;
    } 
    
    
    void print() {
        for (int i = 0; i < m_size; i++) {
            std::cout << m_str[i];
        }
        std::cout << "\n";
    }

    friend std::ostream& operator << (std::ostream& os, const String& str);
    friend std::istream& operator >> (std::istream& in, String& str);
    ~String() {
        if (m_str != nullptr)
            delete[] m_str;
    }


};

std::ostream& operator << (std::ostream& out, const String& str) {
    out << str.m_str;
    return out;
}

std::istream& operator >> (std::istream& in, String& str) {
    char* inStr = new char[1000];
    in >> inStr;
    str.m_str = inStr;
    return in;
}

int main()
{
    String s("hel");
    String a("lo");
    String c(" world!");
    String s3;
    s3 = s + a + c;
    s3.print();
    bool k = s < a;
    std::cout << k << "\n";
    std::cout << s.c_str();
    std::cout<< s.at(1) << "\n";
    String sCin;
    std::cin >> sCin;
    std::cout << sCin;
}
