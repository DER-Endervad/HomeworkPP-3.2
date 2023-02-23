#include <iostream>
#include <Windows.h>
#include < string.h>

class smart_array {
private:
	int* arr;
	int size = 0;
	int queue = 0;
public:
	smart_array(int input) {
		this->size = input;
		arr = new int[size];
	}

	void add_element(int input) {
		if (queue < size) {
			arr[queue] = input;
			++queue;
		}
		else {
			throw std::runtime_error("Превышен размер массива");
		}
	}

	int get_element(int input) {
		if (input >= 0 && input < size) {
			return arr[input];
		}
		else {
			throw std::runtime_error("Ошибка, указан неправильный индекс элемента.");
		}
	}

	void copy_arr(const smart_array& array) {
		this->size = array.size;
		arr = new int[array.size];
		this->queue = array.queue;
		for (int i = 0; i < size; ++i) {
			arr[i] = array.arr[i];
		}
	}

	~smart_array() {
		delete arr;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		std::cout << "Первый массив, первое значение: " << arr.get_element(1) << std::endl;

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);
		std::cout << "Второй массив, первое значение: " << new_array.get_element(1) << std::endl;

		arr.copy_arr(new_array);
		std::cout << "Первый массив, первое значение: " << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
