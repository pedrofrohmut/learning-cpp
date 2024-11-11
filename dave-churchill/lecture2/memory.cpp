#include <iostream>

#define LEN(arr) sizeof(arr) / sizeof(arr[0])

// If you do not pass the variable as an instance the variable will be copied and
// the address will be lost. The &x would point to the address of the copy instead
void describe(const int& x)
{
    std::cout << "Addr: " << &x << ", value: " << x << ", size: " << sizeof(x) << "\n";
}

template <typename T>
class DynamicArray
{
    size_t arr_size;
    T * arr;
public:
    DynamicArray(size_t size) :
        arr_size(size),
        arr(new T[size]()) // new T[size]() 'with the ()' will initialize all to zero
    {
        std::cout << "Array initialized\n";
    }

    ~DynamicArray()
    {
        std::cout << "Cleaning up the IntArray memory allocated\n";
        delete[] this->arr;
    }

    size_t size() const
    {
        return this->arr_size;
    }

    T get(size_t pos) const
    {
        return this->arr[pos];
    }

    void set(size_t pos, T val)
    {
       this->arr[pos] = val;
    }

    void print() const
    {
        for (size_t i = 0; i < this->arr_size; ++i) {
            std::cout << "[" << i << "]: " << this->get(i) << "\n";
        }
    }

    // Having const versions allows the compiler to do some nice optimizations
    // so is good to always make a const version if possible
    const T& operator [] (size_t index) const
    {
        return this->arr[index];
    }

    // When you have the const and non-const version of the operator overload funtions
    // The compiler will know when to use one or another.
    // When you making your custom data structure make sure to have both versions
    T& operator [] (size_t index)
    {
        return this->arr[index];
    }

};

int main(int argc, char * argv[])
{
    // Stack allocated arrays
    std::cout << "\nStatic array (Stack allocated)\n";
    const int arr[10] = {0};
    const size_t arr_len = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < arr_len; ++i) {
        describe(arr[i]);
    }

    // Heap allocated arrays
    std::cout << "\nDynamic array (Heap allocated)\n";
    const size_t dy_size = 10;
    const int* dy_arr = new int[dy_size];
    for (size_t i = 0; i < dy_size; ++i) {
        describe(dy_arr[i]);
    }
    // Heap allocated arrays should be freed after used (mainly on loops, single
    // pass can be clean up by the Operation System)
    delete[] dy_arr;

    // Dynamic array wrapped by a class to use RAII
    std::cout << "\nDynamicArray<T> - Dynamic array with RAII (Heap allocated)\n";
    DynamicArray<float> my_arr(10);

    // Setting values with a setter
    my_arr.set(7, 42.24);
    my_arr.set(2, 69.96);
    my_arr.set(6, 666.66);

    // Setting values with operator overload
    my_arr[1] = 12.34;
    my_arr[5] = 55.55;
    my_arr[6] = 999.99; // It changes the value already set on position 6

    std::cout << my_arr[3] << "\n";

    std::cout << "My array size: " << my_arr.size() << std::endl;
    my_arr.print();

    return 0;
}
