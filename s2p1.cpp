#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
class cypher 
{
private:
    std::vector <int> m_fibonachi;
    std::vector <int> m_key;
    std::vector <int> m_Mainkey;

    bool CheckKey(std::vector <int> your_key) {
        std::sort(your_key.begin(), your_key.end());
        for (int i = 0; i < your_key.size(); i++) {
            for (int j = i + 1; j < your_key.size(); j++) {
                if ((your_key[i] == your_key[j])) {
                    std::cout << "error!";
                    return false;
                }
            }
        }
        for (int i = 0; i < your_key.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < m_fibonachi.size(); j++) {
                if (your_key[i] == m_fibonachi[j]) {
                    tmp += 1;
                }
            }
            if (tmp == 0) {
                std::cout << "error!";
                return false;
            }
        }
        return true;
        
    }

    std::vector <int> MainKey (std::vector<int> Vec) {
        std::sort(Vec.begin(), Vec.end());
        return Vec;
    }

    std::vector <std::string> SplitSentence(const std::string& str) {
        std::vector <std::string> words;
        std::string tmp = "";
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ' ') {
                tmp += str[i];
            }
            else if (str[i] == ' ') {
                words.push_back(tmp);
                tmp = "";
            }

        }
        words.push_back(tmp);
            return words;
    }

public:
    cypher() 
    {
        m_fibonachi.push_back(0);
        m_fibonachi.push_back(1);
        for (int i = 2; i < 30; i++) {
            m_fibonachi.push_back(m_fibonachi[i - 1] + m_fibonachi[i - 2]);
        }
    }
    void Set_Key(const std::vector <int>& your_key) {
        
        if ((your_key.size() <= 30) && (CheckKey(your_key))) {
            m_key = your_key;
            m_Mainkey = MainKey(m_key);
        }
        else {
            std::cout << "key does not match conditions"<<"\n";

        }
    }
    std::vector<int> Get_Key() {
        return m_key;
    }

    std::string encode(const std::string& str) {
        std::vector <std::string> words = SplitSentence(str);
        if (words.size() != m_key.size()) {
            std::cout << "error! The number of words must be equal to the number of digits"<<"\n";
        }
        std::string EncodedStr;
        if (words.size() == m_key.size()) {
            for (int i = 0; i < words.size(); i++) {
                for (int j = 0; j < words.size(); j++) {
                    if (m_key[i] == m_Mainkey[j]) {
                        EncodedStr += words[j];
                        if (i != words.size() - 1) {
                            EncodedStr += " ";
                        }
                    }
                }

            }
        }
        return EncodedStr;
    }

   std::string decode(const std::string& str) {
        std::vector <std::string> words = SplitSentence(str);
        if (words.size() != m_key.size()) {
            std::cout << "error! The number of words must be equal to the number of digits" << "\n";
        }
        std::string DecodedStr;
        if (words.size() == m_key.size()) {
            for (int i = 0; i < words.size(); i++) {
                for (int j = 0; j < words.size(); j++) {
                    if (m_Mainkey[i] == m_key[j]) {
                        DecodedStr += words[j];
                        if (i != words.size() - 1) {
                            DecodedStr += " ";
                        }
                    }
                }
            }
        }
        return DecodedStr;
    }
    

    ~cypher() {}

};
int main()
{
    cypher main;
    std::string txt = "Hello, my name is Vitaly.";
    main.Set_Key({2, 8, 5, 1, 3});
    std::string str;
    str = main.encode(txt);
    std::cout << str<<"\n";
    std::cout << main.decode(str) << "\n";

}

