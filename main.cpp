#include <cstdlib>
#include <iostream>

static int ARRAY_START_SZ = 8;
static int ARRAY_GROWTH_FACTOR = 2;

class GrowableArray {
private:
    int* data;
    int arraySize;

public:
    GrowableArray() {
        data = (int*)malloc(sizeof(int) * ARRAY_START_SZ);
        arraySize = ARRAY_START_SZ;
        for (int i = 0; i < 8; ++i) {
            (data)[i] = i;
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
        int *newArray = (int *) malloc(sizeof(int) * ARRAY_START_SZ);
        bool pastIndex = false;
        for(int i = 0; i < arraySize+1; i++ ){

            if(pastIndex){
                newArray[i] = data[i - 1];
            }
            if(i != index && !pastIndex){
                newArray[i] = data[i];
            } else {
                if(!pastIndex){
                    pastIndex = true;
                    newArray[i] = num;
                }
            }
        }
        data = newArray;
    }

    int lookup(unsigned int index) {
        return data[index];
     }

    void print(){
        std::cout << "\n";

        for(int i = 0; i < arraySize; i++ ){
            std::cout << data[i] << " ";
            };
        }
};


int main() {
    GrowableArray arr;
    std::cout << arr.contains(1) << std::endl;
    std::cout << arr.lookup(2);
    arr.print();
    arr.insert(50, 4);
    arr.print();
}
