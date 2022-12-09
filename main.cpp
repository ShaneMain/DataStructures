#include <cstdlib>
#include <iostream>

static int ARRAY_START_SZ = 1;
static int ARRAY_GROWTH_FACTOR = 2;

class GrowableArray {
private:
    int* data;
    int arraySize;
    int capacity;

public:
    GrowableArray() {
        data = (int*)malloc(sizeof(int) * ARRAY_START_SZ);
        arraySize = 0;
        capacity = ARRAY_START_SZ;
        std::cout << std::endl;
    }

    bool contains(unsigned int num) {
        for(int i = 0; i < arraySize; i++ ){

            if(data[i] == num){
                return true;
            }
        }
        return false;
    }

    void insert(int num, unsigned int index) {
        lookup(index);
        arraySize += 1;
        checkAndEnlarge();
        bool passedIndex = false;
        int storedValue;
        int nextStoredValue;
        for(int i = 0; i < arraySize; i++ ) {
            if(passedIndex){
                nextStoredValue = data[i];
                data[i] = storedValue;
                storedValue = nextStoredValue;
            }
            if (i == index) {
                storedValue = data[i];
                data[i] = num;
                passedIndex = true;
            }
        }
    }

    int lookup(unsigned int index) {
        if(index <= arraySize-1) {
            return data[index];
        } else {
            throw std::invalid_argument( "Invalid Index");
        }
     }

    void print(){
        std::cout << "\n";

        for(int i = 0; i < arraySize; i++ ){
            std::cout << data[i] << " ";
            }
        }

    int pop(){
        if(arraySize > 0){
            arraySize -= 1;
            return data[arraySize];
        }
    }

    void push(int value){
        arraySize += 1;
        checkAndEnlarge();
        data[arraySize - 1] = value;
    }

    private: void checkAndEnlarge(){
        while(arraySize > capacity){
            int newCapacity = capacity * 2;
            int *newArray = (int *) malloc(sizeof(int) * newCapacity);
            for(int i = 0; i < arraySize; i++ ){
                newArray[i] = data[i];
            }
            free(data); //not sure if this fixes the memory leak
            data = newArray;
            capacity = newCapacity;
        }
    }
};


int main() {
    GrowableArray arr;
    arr.pop();
    for (int i = 1; i < 8; ++i) {
        arr.push(i);
    }
    std::cout << arr.contains(1) << std::endl;
    std::cout << arr.lookup(2);
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
