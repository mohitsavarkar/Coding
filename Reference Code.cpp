#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <memory>

// ==========================================
// 10. FUNCTION TEMPLATES
// ==========================================
// Generic function that works with any numeric type
template <typename T>
T addNumbers(T a, T b) {
    return a + b;
}

// ==========================================
// 11. INHERITANCE & 12. POLYMORPHISM
// ==========================================
// Base Class
class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& name) : name(name) {}

    // Virtual destructor for safe dynamic dispatch cleanup
    virtual ~Animal() = default;

    // Pure virtual function making this an abstract base class
    virtual void makeSound() const = 0;

    std::string getName() const { return name; }
};

// Derived Class
class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {}

    // Polymorphic override
    void makeSound() const override {
        std::cout << name << " says: Woof! Woof!" << std::endl;
    }
};

// ==========================================
// 8. FUNCTIONS & 9. GETTING THINGS OUT OF FUNCTIONS
// ==========================================
// Returns values using multiple mechanisms:
// 1. Value return
// 2. Output reference parameter
// 3. Pointer output parameter
int calculateStats(int a, int b, int& sumRef, int* diffPtr) {
    sumRef = a + b;        // Output via reference
    if (diffPtr) {
        *diffPtr = a - b;  // Output via pointer
    }
    return a * b;          // Output via direct return value
}

// ==========================================
// 9. FUNCTION OVERLOADING
// ==========================================
void printMessage(const std::string& msg) {
    std::cout << "String Message: " << msg << std::endl;
}

void printMessage(int value) {
    std::cout << "Integer Message: " << value << std::endl;
}

// ==========================================
// MAIN EXECUTION
// ==========================================
int main() {
    // --------------------------------------
    // 1. VARIABLES & DATA TYPES
    // --------------------------------------
    int age = 25;
    double pi = 3.14159;
    char grade = 'A';
    bool isCppFun = true;

    // --------------------------------------
    // 2. OPERATIONS ON DATA
    // --------------------------------------
    int doubleAge = age * 2;
    bool isAdultAndFun = (age >= 18) && isCppFun;

    std::cout << "--- 1 & 2. Variables & Operations ---\n";
    std::cout << "Double Age: " << doubleAge << " | Is Adult & Fun: " << std::boolalpha << isAdultAndFun << "\n\n";

    // --------------------------------------
    // 3. FLOW CONTROL
    // --------------------------------------
    std::cout << "--- 3. Flow Control ---\n";
    if (grade == 'A') {
        std::cout << "Excellent score!\n";
    } else {
        std::cout << "Keep practicing!\n";
    }

    // --------------------------------------
    // 4. LOOPS
    // --------------------------------------
    std::cout << "\n--- 4. Loops ---\n";
    std::cout << "Counting up: ";
    for (int i = 1; i <= 3; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    // --------------------------------------
    // 5. ARRAYS, POINTERS & REFERENCES
    // --------------------------------------
    std::cout << "\n--- 5. Arrays, Pointers & References ---\n";
    int numbers[3] = {10, 20, 30};

    // Reference (alias to an existing variable)
    int& refToFirst = numbers[0];
    refToFirst = 15; // Modifies numbers[0]

    // Pointer (stores memory address)
    int* ptrToArr = numbers; // Points to numbers[0]

    std::cout << "Array element 0 (via reference): " << numbers[0] << "\n";
    std::cout << "Array element 1 (via pointer arithmetic): " << *(ptrToArr + 1) << "\n";

    // --------------------------------------
    // 6. CHARACTER MANIPULATION & STRINGS
    // --------------------------------------
    std::cout << "\n--- 6. Character Manipulation & Strings ---\n";
    std::string text = "cpp programming";
    
    // Character manipulation
    for (char& c : text) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    std::cout << "Uppercase String: " << text << "\n";

    // --------------------------------------
    // 7. FUNCTIONS & RETURN MECHANISMS
    // --------------------------------------
    std::cout << "\n--- 7. Functions & Outputs ---\n";
    int sum = 0;
    int diff = 0;
    int product = calculateStats(8, 3, sum, &diff);

    std::cout << "Product (return): " << product << "\n";
    std::cout << "Sum (ref out): " << sum << "\n";
    std::cout << "Diff (ptr out): " << diff << "\n";

    // --------------------------------------
    // 8. FUNCTION OVERLOADING
    // --------------------------------------
    std::cout << "\n--- 8. Function Overloading ---\n";
    printMessage("Hello C++");
    printMessage(42);

    // --------------------------------------
    // 9. LAMBDA FUNCTIONS
    // --------------------------------------
    std::cout << "\n--- 9. Lambda Functions ---\n";
    int multiplier = 3;
    
    // Lambda capturing 'multiplier' by value
    auto multiplyBy = [multiplier](int val) {
        return val * multiplier;
    };

    std::cout << "Lambda result (5 * 3): " << multiplyBy(5) << "\n";

    // --------------------------------------
    // 10. FUNCTION TEMPLATES
    // --------------------------------------
    std::cout << "\n--- 10. Function Templates ---\n";
    std::cout << "Template Add Ints: " << addNumbers(10, 20) << "\n";
    std::cout << "Template Add Doubles: " << addNumbers(2.5, 4.3) << "\n";

    // --------------------------------------
    // 11 & 12. INHERITANCE & POLYMORPHISM
    // --------------------------------------
    std::cout << "\n--- 11 & 12. Inheritance & Polymorphism ---\n";
    // Using smart pointer to manage polymorphic dynamic allocation
    std::unique_ptr<Animal> myPet = std::make_unique<Dog>("Buddy");
    
    // Runtime polymorphism via virtual function call
    myPet->makeSound();

    return 0;
}