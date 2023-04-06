
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
        if (m_str != nullptr)
            delete[] m_str;
        m_size = other_str.m_size;
        m_str = new char[m_size + 1];
        std::copy(other_str.m_str, other_str.m_str + m_size+1, this->m_str);
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
        
        String tmp;
        tmp = *this;
        tmp += s2;
        return tmp;
    }

    char& operator [] (size_t a) {
        return m_str[a];
    }

    bool operator == (String& s) {
        return std::strcmp(this->m_str, s.m_str) == 0;
    }

    bool operator < (String& s) {
        return std::strcmp(this->m_str, s.m_str) < 0;
    }

    bool operator > (String& s) {
        return std::strcmp(this->m_str, s.m_str) > 0;
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
    char* inStr = new char[1000000];
    in >> inStr;
    str.m_str = inStr;
    return in;
}

int main()
{
    String s("Hel");
    String a("lo");
    String c(" world!");
    String f("test");
    String s3;
    s += a;
    s3 = s+a;
    std::cout << s<<"\n";
    std::cout << s3;
    bool k = s > a;
    std::cout << k << "\n";
    std::cout << f.c_str()<<"\n";
    std::cout<< s.at(1) << "\n";
    String sCin;
    std::cin >> sCin;
    std::cout << sCin;
}
