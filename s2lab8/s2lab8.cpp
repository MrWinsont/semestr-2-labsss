#include <iostream>

template<typename T>
class Stek
{
private:
	unsigned int m_size=0;
	unsigned int m_max_size=0;
	T* m_mas = nullptr;
public:
	Stek(int max_size):m_max_size(max_size)
	{
		try {
			m_mas = new T[max_size];
		}
		catch (const std::bad_alloc& exeption) {
			std::cerr << exeption.what()<<"\n";
		}
	}



	unsigned int Size() {
		return m_size;
	}

	bool Empty() {
		if (m_size == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	void Push(T element) {
		if (m_size < m_max_size) {
			m_mas[m_size] = element;
			m_size++;
		}
		else {
			throw std::overflow_error("Stek is full");
		}
		
	}

	T Pop() {
		if (m_size == 0) {
			throw std::out_of_range("out of range! Stek is empty");
		}
		else {
			T el = m_mas[0];
			for (int i = 0; i < m_size-1; i++) {
				m_mas[i] = m_mas[i + 1];
			}
			--m_size;
			return el;
		}
	}

	void Top() {
		if (m_size == 0) {
			throw std::logic_error("Error! Stek is empty");
		}
		else {

			std::cout<< m_mas[m_size - 1]<<"\n";
		}


	}

	~Stek() {
		if (m_mas != nullptr) {
			delete[] m_mas;
		}
	}


};



int main()
{
	Stek<int> test(2);
	test.Push(3);
	test.Push(1);
	std::cout<<"Stek size is " << test.Size() << "\n";
	try {
		test.Push(1);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what()<<"\n";
	}

	Stek<std::string> str(3);
	try {
		str.Top();
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what()<<"\n";
	}
	std::cout << "stek is empty? " << str.Empty() << "\n";
	str.Push("hello ");
	str.Push("world");
	str.Push("!");
	std::cout << "stek is empty? " << str.Empty() << "\n";
	std::cout << "stek size is " << str.Size()<<"\n";
	try{
		str.Pop();
	}
	
	catch (const std::exception& ex) {
		std::cerr << ex.what() << "\n";
	}
	std::cout << "stek size is " << str.Size() << "\n";
	str.Top();
}

