#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp;
        try
        {
            for (int i = 0; i < MAX_VAL + 1; i++)
                std::cout << "tmp[" << i << "]:\t" << tmp[i] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\t';
            std::cerr << "You tried to access past the last element of the array" << std::endl;
        }
        tmp = numbers;
        Array<int> test(tmp);

        try
        {
            for (int i = 0; i < MAX_VAL + 1; i++)
        {
            if (tmp[i] != test[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
             //std::cout << "tmp[" << i << "]:\t" << tmp[i] << std::endl; //uncomment these two lines to see the arrays have the same values
             //std::cout << "test[" << i << "]:\t" << test[i] << std::endl;
        }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\t';
            std::cerr << "You tried to access past the last element of the array" << std::endl;
        }

        std::cout << std::endl << "test[1]:\t" << test[1] << std::endl;
        std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl << std::endl;

        test[1] = 123456789;

        std::cout << "test[1]:\t" << test[1] << std::endl;
        std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "index was -2" << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "tried to access past the last element of the array" << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     std::cout << numbers[i] << std::endl;
    // }
	try {
        Array<int> arr1(5);
        for (size_t i = 0; i < arr1.size(); ++i) {
            arr1[i] = static_cast<int>(i * 10);
            std::cout << "arr1[" << i << "] = " << arr1[i] << std::endl;
        }

        Array<int> arr2 = arr1; // Copy constructor
        arr2[2] = 100;          // Modify a copy

        Array<int> arr3;
        arr3 = arr2;            // Copy assignment operator

        std::cout << "arr3[2] = " << arr3[2] << std::endl;

        // Test out-of-bounds access
        arr1[10] = 42; // This will throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	return 0;
}
