#include <iostream>
#include <vector>
using namespace std;


class SET {
private:
    int* data;
    int capacity;
    int size;

public:
    SET(){
    this->capacity = 10;
    this->size = 0;
    this->data = new int[capacity];
    }

    int Size() const {
        return size;
    }


    bool belongs_to(int value){
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                return true;
            }
        }
        return false;
    }

    void Insert(int value) {
        if (!belongs_to(value)) {
            if (size >= capacity) {

                capacity *= 2;
                int* newData = new int[capacity];
                for (int i = 0; i < size; ++i) {
                    newData[i] = data[i];
                }
                delete[] data;
                data = newData;
            }
            data[size] = value;
            mergeSort(data, size+1);
            size++;
        }
    }


    void Delete(int value) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (data[i] == value) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            size--;
        }
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << data[i] ;
            if(i != size-1) cout<<",";
        }
        cout << endl;
    }

    void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0; 
    int j = 0; 
    int k = 0; 
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } 
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
        }
        while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
        }

        while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
        }
    }

    void mergeSort(int arr[], int size) {
    if (size <= 1)
        return;
        int mid = size / 2;

        int left[mid];
        int right[size - mid];


        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }
        for (int i = mid; i < size; i++) {
            right[i - mid] = arr[i];
        }

        mergeSort(left, mid);
        mergeSort(right, size - mid);

        merge(arr, left, mid, right, size - mid);
    }

    void Union(SET s){
        int i = 0;
        while(i < s.Size()){
            if(!belongs_to(s.data[i])){
            Insert(s.data[i]);
            }
            i++;
        }
    }

    void Intersection(SET s){
        int i = 0;
        while( i < Size()){
            if(!s.belongs_to(data[i])){
                Delete(data[i]);
                i--;
            }
            i++;
        }
    }

    void Difference(SET s){
        int i = 0;
        while( i < Size()){
            if(s.belongs_to(data[i])){
                Delete(data[i]);
                i--;
            }
            i++;
        }
    }

    void Symmetric_difference(SET s){
        int i = 0;
        while( i < s.Size()){
            if(belongs_to(s.data[i])){
                Delete(s.data[i]);
                i++;
            }
            else{
                Insert(s.data[i]);
                i++;
            }
        }

    }

    void Symmetric_difference1(void){
        while(size>0){
            Delete(data[size]);
            size--;
        }
    }
};



int main() {
    

    return 0;
}
