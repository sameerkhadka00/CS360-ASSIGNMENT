#include <iostream>
#include <vector>
using namespace std;

class IntegerSet {
private:
    vector<bool> set;

public:
    // Default constructor initializes an empty set
    IntegerSet() : set(101, false) {}

    // Constructor that initializes set from an array of integers
    IntegerSet(const int arr[], int size) : set(101, false) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] >= 0 && arr[i] <= 100) {
                set[arr[i]] = true;
            }
        }
    }

    // Union of two sets
    IntegerSet unionOfSets(const IntegerSet& other) const {
        IntegerSet result;
        for (int i = 0; i <= 100; ++i) {
            result.set[i] = (set[i] || other.set[i]);
        }
        return result;
    }

    // Intersection of two sets
    IntegerSet intersectionOfSets(const IntegerSet& other) const {
        IntegerSet result;
        for (int i = 0; i <= 100; ++i) {
            result.set[i] = (set[i] && other.set[i]);
        }
        return result;
    }

    // Insert an element into the set
    void insertElement(int k) {
        if (k >= 0 && k <= 100) {
            set[k] = true;
        }
    }

    // Delete an element from the set
    void deleteElement(int m) {
        if (m >= 0 && m <= 100) {
            set[m] = false;
        }
    }

    // Check if two sets are equal
    bool isEqualTo(const IntegerSet& other) const {
        for (int i = 0; i <= 100; ++i) {
            if (set[i] != other.set[i]) {
                return false;
            }
        }
        return true;
    }

    // Print the set
    void printSet() const {
        bool empty = true;
        for (int i = 0; i <= 100; ++i) {
            if (set[i]) {
                cout << i << " ";
                empty = false;
            }
        }
        if (empty) {
            cout << "---";
        }
        cout << endl;
    }
};

int main() {
    // Test cases

    // Create sets
    IntegerSet set1;
    IntegerSet set2;
    IntegerSet set3;
    IntegerSet set4;

    // Insert elements into set1
    set1.insertElement(10);
    set1.insertElement(20);
    set1.insertElement(30);

    // Insert elements into set2
    set2.insertElement(20);
    set2.insertElement(40);
    set2.insertElement(60);

    // Insert elements into set3
    set3.insertElement(30);
    set3.insertElement(40);
    set3.insertElement(50);

    // Union of set1 and set2
    IntegerSet unionSet = set1.unionOfSets(set2);
    cout << "Union of set1 and set2: ";
    unionSet.printSet();

    // Intersection of set1 and set2
    IntegerSet intersectionSet = set1.intersectionOfSets(set2);
    cout << "Intersection of set1 and set2: ";
    intersectionSet.printSet();

    // Insert element into set4
    set4.insertElement(80);
    set4.insertElement(90);
    set4.insertElement(100);

    // Delete element from set4
    set4.deleteElement(80);

    // Print set4
    cout << "Set4 after deleting 80: ";
    set4.printSet();

    // Check if set3 is equal to set4
    if (set3.isEqualTo(set4)) {
        cout << "Set3 is equal to set4" << endl;
    } else {
        cout << "Set3 is not equal to set4" << endl;
    }

    return 0;
}
