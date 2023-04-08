
#include <iostream>
template<typename T, typename T2, typename T3>
class Matrix 
{
private:
    T2 N;
    T3 M;
    T** m_matrix = nullptr;

    friend std::ostream& operator << (std::ostream& out, const Matrix& other) {
        for (int i = 0; i < other.N; i++) {
            for (int j = 0; j < other.M; j++) {
                out << other.m_matrix[i][j] << "\t";
            }
            out << "\n";
        }
        return out;
    }


    friend std::istream& operator >> (std::istream& in, Matrix& other) {

        for (int i = 0; i < other.N; i++) {
            for (int j = 0; j < other.M; j++) {
                in >> other.m_matrix[i][j];
            }
        }
        return in;
    }

public:
    Matrix() {}

    Matrix(T2 n,T3 m) 
    {
        N = n;
        M = m;
        m_matrix = new T*[N];
        for (int i = 0; i < N; i++) {
            m_matrix[i] = new T[M];
            for (int j = 0; j < M; j++) {
                m_matrix[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix& other) {
        N = other.N;
        M = other.M;
        m_matrix = new T * [N];
        for (int i = 0; i < N; i++) {
            m_matrix[i] = new T[M];
        }
        for (int i = 0; i < N; i++) {
            for (int j =0;j<M;j++)
                m_matrix[i][j] = other.m_matrix[i][j];
        }
        
    }

    Matrix& operator = (const Matrix& other) {
         
        N = other.N;
        M = other.M;
        m_matrix = new T * [N];
        for (int i = 0; i < N; i++) {
            m_matrix[i] = new T[M];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                m_matrix[i][j] = other.m_matrix[i][j];
        }
        return *this;
    }

    Matrix& operator += (const Matrix& other) {
        if (N != other.N || M != other.M) {
            std::cout << "immposible to sum it"<<"\n";
        }
        else {
            for (int i = 0; i < other.N; i++) {
                for (int j = 0; j < other.M; j++) {
                    m_matrix[i][j] += other.m_matrix[i][j];
                }
            }
        }
        return *this;
    }

    Matrix operator + (const Matrix& other) {
        Matrix temp = *this;
        if (temp.N != other.N || temp.M != other.M) {
            std::cout << "immposible to sum it" << "\n";
        }
        else {
            temp += other;
        }
        return temp;

    }

    Matrix& operator *= (const Matrix& other) {
        if (M != other.N) {
            std::cout << "immposible to multiply it"<<"\n";
        }
        else {
            Matrix temp = *this;
            for (int i = 0; i < N; i++) {
                int k = 0;
                for (int j = 0; j < other.M; j++) {
                    int x_for_mat = 0;
                    for (int l = 0; l < other.M; l++) {
                        x_for_mat += temp.m_matrix[i][l] * other.m_matrix[l][j];
                    }
                    m_matrix[i][k] = x_for_mat;
                    k++;
                }
                
            }
        }
        return *this;
    }

    Matrix operator * (const Matrix& other) {
        Matrix tmp = *this;
        tmp *= other;
        return tmp;
    }

    Matrix& operator ++ () {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                m_matrix[i][j]++;
            }
        }
        return *this;
    }
    
    Matrix operator ++ (int a) {
        Matrix tmp = *this;
        ++(* this);
        return tmp;
    }
    Matrix minor(int i1,int j1) {
        Matrix ans_minor(N - 1, M-1);
        int k=-1;
        int l;
        for (int i = 0; i < N; i++) {
            k++;
            l = 0;
            if (i == i1) {
                i++;
            }
            for (int j = 0; j < M; j++) {
                if (j == j1) {
                    j++;
                }
                ans_minor.m_matrix[k][l] = m_matrix[i][j];
                l++;
            }
        }
        return ans_minor;
    }
    int Det() {
        T ans_det = 0;
        if (N != M) {
            std::cout << "Error! the number of columns should be the same as the number of lines";
        }

        else {
            T k = 0;
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < M; j++) {
                    if ((*this).minor(i, j).N == 1) {
                        ans_det += pow(-1, i + j) * (*this).m_matrix[i][j] * (*this).minor(i, j)[0][0];
                    }
                    else {
                        ans_det += pow(-1,i+j) * (*this).m_matrix[i][j] * (*this).minor(i, j).Det();
                    }
                }
            }
        }
        return ans_det;
    }

    ~Matrix() {
        if (m_matrix != nullptr) {
            for (int i = 0; i < N; i++) {
                delete[] m_matrix[i];
            }
            delete[] m_matrix;
        }
    }

    T* operator [] (int a) {
        return m_matrix[a];
    }
};


int main()
{
    /*Matrix<int, int, int>K(3,3);
    Matrix<int, int, int> F(2, 2);
    std::cin >> F;
    Matrix <int, int, int> M = F;*/
    //F += M;
    //F= M + M;
    //std::cout << F;
    //F[1][1] = 3;
    /*F *= M;
    std::cout << F;*/
    //Matrix<int, int, int>K(2,2);
    Matrix<int, int, int>J(2,2);
    //std::cin >> K;
    std::cin >> J;
    std::cout << J.Det() << "\n";
    //Matrix<int, int, int> L(2,2);
    //L = K * F;
    //K *= F;
    //std::cout << F++;

}

