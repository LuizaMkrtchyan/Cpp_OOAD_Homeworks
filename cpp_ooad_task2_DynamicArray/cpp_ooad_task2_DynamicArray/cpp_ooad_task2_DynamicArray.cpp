#include <iostream>

class DynamicArray {
private:
	int* arr;
	int size;
	int capacity;
public:
	DynamicArray() {
		size = 0;
		capacity = 5;
		arr = new int[capacity];
	}
	DynamicArray(int size, int capacity) {
		this->size = size;
		this->capacity = capacity;
		this->arr = new int[capacity];
	}
	void Push(int value) {
		if (size == capacity) {
			capacity *= 2;
			int* tmp = new int[capacity];
			for (int i = 0; i < size; ++i)
			{
				tmp[i] = arr[i];
			}
			delete[] arr;
			arr = tmp;
			tmp = nullptr;
		}
		arr[size] = value;
		++size;
	}
	DynamicArray(const DynamicArray& object){
		int* tmp = new int[object.capacity];
		for (int i = 0; i < object.size; ++i) {
			tmp[i] = object.arr[i];
		}
		arr = tmp;
		tmp = nullptr;
		size = object.size;
		capacity = object.capacity;
	}
	~DynamicArray() {
		delete[] arr;
	}
	int getArrElement(int index) {
		return arr[index];
	}
};
int main()
{
	DynamicArray myarr;
	myarr.Push(2);
	myarr.Push(4);
	DynamicArray myarr2 = myarr;
	myarr2.Push(6);
	std::cout << myarr.getArrElement(2); //garbage value




}
