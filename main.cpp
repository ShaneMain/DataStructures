#include <cstdlib>
#include <iostream>

static int ARRAY_START_SZ = 8;
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
        for (int i = 0; i < 8; ++i) {
            (data)[i] = i;
            arraySize +=1;
        }

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
        capacity += 1;
        int *newArray = (int *) malloc(sizeof(int) * capacity);
        int newSize = 0;
        bool passedIndex = false;
        for(int i = 0; i < capacity; i++ ){

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
        arraySize = newSize;
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
        int newSize = 0;
        int *newArray = (int *) malloc(sizeof(int) * capacity);
        for(int i = 0; i < capacity; i++ ){
            if(i < arraySize - 1){
                newArray[i] = data[i];
                newSize += 1;
            }
            else{
                int lastNum = data[i];
                data = newArray;
                arraySize = newSize;
                return lastNum;
            }
        }
    }

    void push(int value){
        int newSize = 0;
        capacity += 1;
        int *newArray = (int *) malloc(sizeof(int) * capacity);
        for(int i = 0; i < capacity; i++ ){
            if(i < arraySize) {
                newArray[i] = data[i];
                newSize += 1;
            } else {
                newArray[i] = value;
                newSize +=1 ;
                data = newArray;
                arraySize = newSize;
                break;
            }
        }
    }
};


int main() {
    GrowableArray arr;
    std::cout << arr.contains(1) << std::endl;
    std::cout << arr.lookup(2);
    arr.print();
    arr.insert(50, 4);
    arr.print();
    std::cout << "\n";
    std::cout << arr.pop();
    arr.print();
    arr.push(1);
    arr.print();
}
