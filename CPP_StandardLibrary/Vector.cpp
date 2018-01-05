#include "Vector.h"
#include "Utilities.h"

#include "DemoClass.h"

#include <vector>
#include <algorithm>
#include <string>

using std::vector;


void Vector::InitializationDemo()
{
    // The following are the ways the vectors can be initialized

    // Create an empty vector
    vector<DemoClass> vec1;
    vec1.push_back(DemoClass(555)); // Create a single value
    PRINT("Size of vec1 is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);

    // Create vec2 as a copy of vec1
    vector<DemoClass> vec2(vec1);
    PRINT("Size of vec2 is :" + std::to_string(vec2.size()));
    PRINT_CONTAINER(vec2);

    // Copy assignment
    vector<DemoClass> vec3 = vec2;
    PRINT("Size of vec3 is :" + std::to_string(vec3.size()));
    PRINT_CONTAINER(vec3);

    // Move constructor, vec3 values are undefined after this
    vector<DemoClass> vec4(std::move(vec3));
    PRINT("Size of vec4 is :" + std::to_string(vec4.size()));
    PRINT_CONTAINER(vec4);

    // Move assignment, vec4 values are undefined after this
    vector<DemoClass> vec5 = std::move(vec4);
    PRINT("Size of vec5 is :" + std::to_string(vec5.size()));
    PRINT_CONTAINER(vec5);

    // Create a vector with 5 elements of DemoClass initialized by the default constructor
    vector<DemoClass> vec6(5);
    PRINT("Size of vec6 is :" + std::to_string(vec6.size()));

    // Create a vector vec7 with 3 copies of the demo class object
    DemoClass demo(10101);
    vector<DemoClass> vec7(3, demo);
    PRINT("Size of vec7 is :" + std::to_string(vec6.size()));
    PRINT_CONTAINER(vec7);

    // Create a vector vec8 by copying the first two elements from vec7
    vector<DemoClass> vec8(begin(vec7), begin(vec7) + 2);
    PRINT("Size of vec8 is :" + std::to_string(vec8.size()));
    PRINT_CONTAINER(vec8);

    // Create a vactor vec9 using the initializer list
    vector<DemoClass> vec9({ DemoClass(1), DemoClass(2), DemoClass(3) });
    PRINT("Size of vec9 is :" + std::to_string(vec9.size()));
    PRINT_CONTAINER(vec9);

    // Create a vactor vec1- using the initializer list
    vector<DemoClass> vec10 = { DemoClass(5), DemoClass(6), DemoClass(7), DemoClass(8) };
    PRINT("Size of vec10 is :" + std::to_string(vec10.size()));
    PRINT_CONTAINER(vec10);
}

void Vector::NonModifyingOperatorsDemo()
{
    // This function demonstrates the non-modifying operations that can be performed on vectors

    // Checking for emptiness
    vector<DemoClass> vec1;
    if (vec1.empty() == true)
        PRINT("vec1 is empty");

    vec1.push_back(DemoClass(1234)); // Create a single value
    if (vec1.empty() == true)
        PRINT("vec1 is empty");
    else
        PRINT("vec1 is NOT empty");

    // Checking the current vector size
    vector<DemoClass> vec2(10);
    PRINT("Size of vec2 is :" + std::to_string(vec2.size()));    

    // Max size:
    PRINT("Max Size of vec1 is :" + std::to_string(vec1.max_size()));
    PRINT("Max Size of vec2 is :" + std::to_string(vec2.max_size()));

    // Capacity:
    PRINT("Capacity of vec1 is :" + std::to_string(vec1.capacity()));
    PRINT("Capacity of vec2 is :" + std::to_string(vec2.capacity()));

    // Reserver:
    vec2.reserve(100);
    PRINT("Capacity of vec2 after reserving for 100 is :" + std::to_string(vec2.capacity()));

    // Shrink to fit:
    vec2.shrink_to_fit();
    PRINT("Capacity of vec2 after shrink_to_fit is :" + std::to_string(vec2.capacity()));

    PRINT("Checking the comparison operators:");

    // == check between vectors, calls the == on all the individual elements
    vector<DemoClass> vec3(3, DemoClass(5)); // vec3 is a vector with 3 objects of DemoClass, each with value 5
    
    PRINT_CONTAINER(vec2, "vec2");
    PRINT_CONTAINER(vec3, "vec3");

    if (vec3 == vec2)
        PRINT("vec3 == vec2 is TRUE");
    else
        PRINT("vec3 == vec2 is FALSE");

    vector<DemoClass> vec4(vec3); // Make vec4 a copy of vec3.

    PRINT_CONTAINER(vec4, "vec4");

    if (vec3 == vec4)
        PRINT("vec3 == vec4 is TRUE");
    else
        PRINT("vec3 == vec4 is FALSE");

    // != check on vectors calls the != on all the elements of the vectors
    if (vec3 != vec2)
        PRINT("vec3 != vec2 is TRUE");
    else
        PRINT("vec3 != vec2 is FALSE");

}

void Vector::Demonstrate()
{
    // This demonstrates the various options available on the vector container.
    // I would recommend reading through the code along with the output for a better understanding

    PRINT("Demonstrating Vectors: \n");

    // Demonstrate the various ways vectors can be initialized:
    InitializationDemo();

    NonModifyingOperatorsDemo();

    PRINT("End of Vectors Demo");

}