#include "Vector.h"
#include "Utilities.h"

#include "DemoClass.h"

#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <exception>

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

    PRINT("Non modifying operators demo: ");
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

    // Relational operations
    vector<DemoClass> vec3(3, DemoClass(5)); // vec3 is a vector with 3 objects of DemoClass, each with value 5
    
    PRINT_CONTAINER(vec2);
    PRINT_CONTAINER(vec3);    
    
    if (std::equal(begin(vec3),end(vec3), begin(vec2)) == 0)
        PRINT("equal(vec3, vec2) == 0 is TRUE");
    else
        PRINT("equal(vec3, vec2) == 0 is FALSE");

    
    vector<DemoClass> vec4(vec3);
    if (std::equal(begin(vec4), end(vec4), begin(vec3)) == 0)
        PRINT("equal(vec3, vec4) == 0 is TRUE");
    else
        PRINT("equal(vec3, vec4) == 0 is FALSE");
        
    // TODO: The ==, != , <=, >= , < and > dont seem to be working. I am getting a compiler error:
    // error C2672: 'operator __surrogate_func': no matching overloaded function found
    // Need to figure the reason for this. 

}

void Vector::AssignmentFunctionsDemo()
{
    PRINT("Demonstrating the assign functions in vector");

    vector<DemoClass> vec1;
    vec1.assign(3, DemoClass(123)); // Puts 3 copies of DemoClass with value 123, into vec1
    PRINT("Size of vec1 is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);

    // TODO: Getting a compiler error stating "!= is ambigous" on using the swap functions, 
    // both the member and algorithm functions

    std::list<DemoClass> demoList;
    demoList.push_back(DemoClass(10));
    demoList.push_back(DemoClass(11));
    demoList.push_back(DemoClass(12));
    demoList.push_back(DemoClass(13));

    PRINT("list collection members: ");
    PRINT_CONTAINER(demoList);

    PRINT("Copying into vec2 from the list :");
    vector<DemoClass> vec2;
    vec2.assign(begin(demoList), end(demoList));
    PRINT("Size of vec2 is :" + std::to_string(vec2.size()));
    PRINT_CONTAINER(vec2);
        
    PRINT("Using assign with the initializer list");
    vector<DemoClass> vec3;
    vec3.assign({DemoClass(1), DemoClass(2), DemoClass(3)});
    PRINT("Size of vec3 is :" + std::to_string(vec3.size()));
    PRINT_CONTAINER(vec3);

    //TODO: swap is complaining about an ambigous != operator. Check and fix

    /*PRINT("vec2 is now: ");
    PRINT_CONTAINER(vec2);

    PRINT("vec3 is now: ");
    PRINT_CONTAINER(vec3);

    PRINT("Swapping now : ");
    
    vec2.swap(vec3);*/

    //PRINT("vec2 is now: ");
    //PRINT_CONTAINER(vec2);

    //PRINT("vec3 is now: ");
    //PRINT_CONTAINER(vec3);

    //PRINT("Swapping with swap algo function: ");

    //std::swap(vec2, vec3);

    //PRINT("vec2 is now: ");
    //PRINT_CONTAINER(vec2);

    //PRINT("vec3 is now: ");
    //PRINT_CONTAINER(vec3);
}

void Vector::ElementAccessDemo()
{
    PRINT("Demonstrating element access in vector: \n");

    vector<DemoClass> vec1 = { DemoClass(1), DemoClass(2), DemoClass(3) };

    PRINT_CONTAINER(vec1);

    PRINT("vec1[0] : ");
    auto val = vec1[0]; // Has no error check, behavior undefined if index out of range
    val.PrintValue();

    PRINT("vec1.at(1) : ");
    auto val2 = vec1.at(1); // throws index out of range exception if index out of range
    val2.PrintValue();

    PRINT("vec1.front() : ");
    auto val3 = vec1.front();
    val3.PrintValue();

    PRINT("vec1.back() : ");
    auto val4 = vec1.back();
    val4.PrintValue();

    try
    {
        auto val5 = vec1.at(10);
    }
    catch (std::exception ex)
    {
        PRINT("Exception caught when index not in vector range: " + std::string(ex.what()));
    }
}


void Vector::InsertionDeletionDemo()
{


}

void Vector::Demonstrate()
{
    // This demonstrates the various options available on the vector container.
    // I would recommend reading through the code along with the output for a better understanding

    PRINT("Demonstrating Vectors: \n");

    // Demonstrate the various ways vectors can be initialized:
    InitializationDemo();

    // Demonstrate some non-modifying operations
    NonModifyingOperatorsDemo();

    // Assinment functions demo
    AssignmentFunctionsDemo();

    // Demonstrate how individual elements can be accessed
    ElementAccessDemo();

    // Demonstrate insertions and deletions
    //InsertionDeletionDemo();

    PRINT("End of Vectors Demo");

}