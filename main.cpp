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

    bool contains(int num) {
        for(int i = 0; i < arraySize; i++ ){

            if(data[i] == num){
                return true;
            }
        }
        return false;
    }

    void insert(int num, int index) {
        if(index > arraySize){
            return;
        }
        arraySize += 1;
        checkAndEnlarge();
        int *newArray = (int *) malloc(sizeof(int) * capacity);
        int newSize = 0;
        bool passedIndex = false;
        for(int i = 0; i < arraySize; i++ ){

            if(passedIndex){
                newArray[i] = data[i - 1];
                newSize += 1;
            }
            if(i != index && !passedIndex){
                newArray[i] = data[i];
                newSize += 1;
            } else {
                if(!passedIndex){
                    passedIndex = true;
                    newArray[i] = num;
                    newSize += 1;
                }
            }
        }
        data = newArray;
        //free(data);
    }

    int lookup(unsigned int index) {
        return data[index];
     }

    void print(){
        std::cout << "\n";

        for(int i = 0; i < arraySize; i++ ){
            std::cout << data[i] << " ";
            }
        }

    int pop(){
        arraySize -= 1;
        return data[arraySize];
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
            for(int i = 0; i < capacity; i++ ){
                newArray[i] = data[i];
            }
            data = newArray;
            capacity = newCapacity;
        }
    }
};


int main() {
    GrowableArray arr;
    for (int i = 1; i < 8; ++i) {
        arr.push(i);
    }
    std::cout << arr.contains(1) << std::endl;
    std::cout << arr.lookup(2);
    arr.print();
    arr.insert(50, 0);
    arr.print();
    std::cout << "\n";
    std::cout << arr.pop();
    arr.print();
    arr.push(50);
    arr.print();
}
