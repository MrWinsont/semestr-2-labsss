
#include <iostream>

int main()
{
    const int N = 1000;
    int mas_a[N] = {1,2,3,4,5,6,7,8,9,10};
    int mas_b[N];
    long long* ptr1 = (long long*)mas_a;
    long long* ptr2 = (long long*)mas_b;
    int size = sizeof(int) * N / sizeof(long long);

    for (int i = 0; i < size; i++) {
        *ptr2 = *ptr1;
        ptr1++;
        ptr2++;
    }

    int* ptrFor1 = (int*)ptr1;
    int* ptrFor2 = (int*)ptr2;
    int ost = sizeof(int) * N % sizeof(long long);
    for (int i = 0; i < ost; i++) {
        *ptrFor2 = *ptrFor1;
        ptrFor1++;
        ptrFor2++;
    }
    
    
    for (int i = 0; i < N; i++) {
        std::cout << mas_b[i] << "\n";
    }
}
