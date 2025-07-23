#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include <string>

using namespace std;

struct NumberList {
    int size;
    int numbers[100];

    NumberList() {
        size = 0;
    }

    void add(int number) {
        numbers[size] = number;
        size++;
    }

    void remove(int index) {
        for (int i = index; i < size - 1; i++) {
            numbers[i] = numbers[i + 1];
        }
        size--;
    }

    int get(int index) {
        return numbers[index];
    }

    bool set(int index, int number) {
        if (index <= 0 || index > size) {
            return false;
        }

        numbers[index] = number;
        return true;
        
    }

    bool contains(int number) {
        for (int i = 0; i < size; i++) {
            if (numbers[i] == number) {
                return true;
            }
        }
        return false;
    }

    void clear() {
        size = 0;
    }

    NumberList copy() {
        NumberList other;
        for (int i = 0; i < other.size; i++) {
            numbers[i] = other.numbers[i];
        }
        size = other.size;
        return other;
    }

    string toString() {
        string result = "[";
        for (int i = 0; i < size; i++) {
            result += to_string(numbers[i]);
            if (i < size - 1) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }
};

NumberList generateNumberListWithRandomNumbers(int size, int min, int max) {
    NumberList result;
    
    for (int i = 0; i < size; i++) {
        result.add(rand() % (max - min + 1) + min);
    }

    return result;
}

NumberList getNumberListWithoutRepetitions(NumberList list) {
    NumberList result; 

    for (int i = 0; i < list.size; i++) {
        if (!result.contains(list.numbers[i])) {
            result.add(list.numbers[i]);
        }
    }

    return result;
}

NumberList getNumberListWithNumberOfRepetitions(NumberList list, NumberList listWithoutRepetitions) {
    NumberList result; 

    for (int i = 0; i < listWithoutRepetitions.size; i++) {
        int number = listWithoutRepetitions.numbers[i];
        int count = 0;

        
        for (int j = 0; j < list.size; j++) {
            if (list.numbers[j] == number) {
                count++;
            }
        }

        
        result.add(number);
        result.add(count); 
    }

    return result;
}


#endif /* NUMBERLIST_H */