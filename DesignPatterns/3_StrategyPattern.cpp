#include <algorithm>
#include <iostream>

class SortStrategy {
public:
    virtual void sort(int arr[], int size) = 0;
    virtual ~SortStrategy() {}
};


class BubbleSort : public SortStrategy {
public:
    void sort(int arr[], int size) override {
        std::cout << "Using Bubble Sort" << std::endl;
        std::sort(arr, arr + size);
    }
};

class QuickSort : public SortStrategy {
public:
    void sort(int arr[], int size) override {
        std::cout << "Using Quick Sort" << std::endl;
        std::sort(arr, arr + size);
    }
};

class SortContext {
private:
    SortStrategy* strategy;

public:
    SortContext(SortStrategy* strategy) : strategy(strategy) {}

    void setStrategy(SortStrategy* newStrategy) {
        strategy = newStrategy;
    }

    void performSort(int arr[], int size) {
        strategy->sort(arr, size);
    }
};

int main() {
    int arr[] = {5, 3, 8, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    SortContext context(new BubbleSort());
    context.performSort(arr, size);

    SortContext context2(new QuickSort());
    context2.performSort(arr, size);

    return 0;
}

/*
    Explanation
    Strategy Interface (SortStrategy): 
        Defines a common interface for sorting algorithms, ensuring they all have a sort method.

    Concrete Strategies (BubbleSort and QuickSort): 
        Implement the SortStrategy interface and provide specific sorting algorithms (std::sort in this 
        case).
    Context Class (SortContext): 
        Uses a strategy object (SortStrategy) to perform sorting. It can switch between different 
        sorting strategies at runtime using the setStrategy method.
    Client Code (main function): 
        Creates instances of SortContext with different sorting strategies (BubbleSort and QuickSort) 
        and uses them to sort an array.

*/