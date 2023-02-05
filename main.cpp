#include <cstdlib>
#include <iostream>

static int ARRAY_START_SZ = 1;
static int ARRAY_GROWTH_FACTOR = 2;

class GrowableArray {
private:
    int *data;
    int arraySize;
    int capacity;

public:
    GrowableArray() {
        data = (int *) malloc(sizeof(int) * ARRAY_START_SZ);
        arraySize = 0;
        capacity = ARRAY_START_SZ;
        std::cout << std::endl;
    }

    ~GrowableArray() {
        free(data);
        data = nullptr;
    }

    bool contains(int num) {
        for (int i = 0; i < arraySize; i++) {
            if (data[i] == num) {
                return true;
            }
        }
        return false;
    }

    void insert(int num, unsigned int index) {
        checkIndex(index);
        arraySize += 1;
        checkAndEnlarge();
        for (int i = arraySize - 1; i-- > 0;) {
            if (i != index) {
                data[i + 1] = data[i];
            } else {
                data[i + 1] = data[i];
                data[i] = num;
                return;
            }
        }
    }

    int lookup(unsigned int index) {
        checkIndex(index);
        return data[index];
    }

    void print() {
        std::cout << "\n";

        for (int i = 0; i < arraySize; i++) {
            std::cout << data[i] << " ";
        }
    }

    int pop() {
        if (arraySize > 0) {
            arraySize -= 1;
            return data[arraySize];
        }
    }

    void push(int value) {
        arraySize += 1;
        checkAndEnlarge();
        data[arraySize - 1] = value;
         if (arraySize == 0) {
            free(data);
            data = nullptr;
        }
    }

private:
    void checkIndex(int index) {
        if (index <= arraySize - 1) {
            return;
        } else {
            throw std::invalid_argument("Invalid Index");
        }
    }

private:
    void checkAndEnlarge() {
        if (arraySize <= capacity) {
            return;
        }
        int newCapacity = capacity * 2;
        int *newArray = (int *) malloc(sizeof(int) * newCapacity);
        if (!newArray) {
            return;
        }
        for (int i = 0; i < arraySize; i++) {
            newArray[i] = data[i];
        }
        free(data);
        data = newArray;
        capacity = newCapacity;
    }

};


int main() {
    GrowableArray arr;
    arr.pop();
    std::cout << arr.contains(0) << std::endl;
    for (int i = 1; i < 8; ++i) {
        arr.push(i);
    }
    std::cout << arr.contains(1) << std::endl;
    std::cout << arr.lookup(2) << std::endl;
    std::cout << arr.lookup(6);
    arr.print();
    arr.insert(50, 0);
    arr.print();
    std::cout << "\n";
    std::cout << arr.pop();
    arr.print();
    arr.push(50);
    arr.print();
}
