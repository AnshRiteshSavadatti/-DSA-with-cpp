/*
    A typical implementation of the Singleton pattern in C++ involves:

        -Making the constructor, copy constructor, and assignment operator private to prevent direct 
        instantiation and copying.
        -Providing a static method to access the single instance.

*/

#include <iostream>
#include <mutex>

class Singleton {
private:
    static Singleton* instance;
    static std::mutex mtx;
    // Private constructor to prevent instantiation
    Singleton() {}

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Static method to provide global access to the instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mtx);
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }

    void showMessage() {
        std::cout << "Hello, I am a Singleton instance!" << std::endl;
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

int main() {
    // Get the single instance of Singleton
    Singleton* singleton = Singleton::getInstance();
    singleton->showMessage();

    return 0;
}

/*
Explanation of the Implementation

Private Constructor: The constructor is private to prevent creating instances directly.

Static Instance: A static pointer to the single instance is declared. It is initialized to nullptr.

Static Method (getInstance()): This method checks if the instance is nullptr. If it is, it creates 
the instance. This ensures that only one instance is created. It uses a mutex to make the method 
thread-safe.

Delete Copy Constructor and Assignment Operator: These are deleted to prevent copying the singleton 
instance.

Mutex for Thread Safety: A mutex is used to ensure that only one instance is created even when accessed 
by multiple threads simultaneously.

Key Points
Thread Safety: In a multithreaded environment, it's crucial to ensure that only one instance is 
created, which is why a mutex is used.

Lazy Initialization: The instance is created only when it is first requested, which is known as 
lazy initialization.

Global Access: The getInstance() method provides a way to access the single instance globally.
The Singleton pattern is a powerful tool for ensuring controlled access to a single instance of a 
class, but it should be used judiciously to avoid potential issues such as hidden dependencies and 
difficulties in testing.
*/