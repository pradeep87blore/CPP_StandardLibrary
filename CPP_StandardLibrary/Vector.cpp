#include "Vector.h"
#include "Utilities.h"

#include "DemoClass.h"

#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <exception>

using std::vector;

typedef vector<DemoClass> DemoClassVec;

void Vector::InitializationDemo()
{
    // The following are the ways the vectors can be initialized

    // Create an empty vector
    DemoClassVec vec1;
    vec1.push_back(DemoClass(555)); // Create a single value
    PRINT("Size of vec1 is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);

    // Create vec2 as a copy of vec1
    DemoClassVec vec2(vec1);
    PRINT("Size of vec2 is :" + std::to_string(vec2.size()));
    PRINT_CONTAINER(vec2);

    // Copy assignment
    DemoClassVec vec3 = vec2;
    PRINT("Size of vec3 is :" + std::to_string(vec3.size()));
    PRINT_CONTAINER(vec3);

    // Move constructor, vec3 values are undefined after this
    DemoClassVec vec4(std::move(vec3));
    PRINT("Size of vec4 is :" + std::to_string(vec4.size()));
    PRINT_CONTAINER(vec4);

    // Move assignment, vec4 values are undefined after this
    DemoClassVec vec5 = std::move(vec4);
    PRINT("Size of vec5 is :" + std::to_string(vec5.size()));
    PRINT_CONTAINER(vec5);

    // Create a vector with 5 elements of DemoClass initialized by the default constructor
    DemoClassVec vec6(5);
    PRINT("Size of vec6 is :" + std::to_string(vec6.size()));

    // Create a vector vec7 with 3 copies of the demo class object
    DemoClass demo(10101);
    DemoClassVec vec7(3, demo);
    PRINT("Size of vec7 is :" + std::to_string(vec6.size()));
    PRINT_CONTAINER(vec7);

    // Create a vector vec8 by copying the first two elements from vec7
    DemoClassVec vec8(begin(vec7), begin(vec7) + 2);
    PRINT("Size of vec8 is :" + std::to_string(vec8.size()));
    PRINT_CONTAINER(vec8);

    // Create a vactor vec9 using the initializer list
    DemoClassVec vec9({ DemoClass(1), DemoClass(2), DemoClass(3) });
    PRINT("Size of vec9 is :" + std::to_string(vec9.size()));
    PRINT_CONTAINER(vec9);

    // Create a vactor vec1- using the initializer list
    DemoClassVec vec10 = { DemoClass(5), DemoClass(6), DemoClass(7), DemoClass(8) };
    PRINT("Size of vec10 is :" + std::to_string(vec10.size()));
    PRINT_CONTAINER(vec10);
}

void Vector::NonModifyingOperatorsDemo()
{
    // This function demonstrates the non-modifying operations that can be performed on vectors

    PRINT("Non modifying operators demo: ");
    // Checking for emptiness
    DemoClassVec vec1;
    if (vec1.empty() == true)
        PRINT("vec1 is empty");

    vec1.push_back(DemoClass(1234)); // Create a single value
    if (vec1.empty() == true)
        PRINT("vec1 is empty");
    else
        PRINT("vec1 is NOT empty");

    // Checking the current vector size
    DemoClassVec vec2(10);
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
    DemoClassVec vec3(3, DemoClass(5)); // vec3 is a vector with 3 objects of DemoClass, each with value 5
    
    PRINT_CONTAINER(vec2);
    PRINT_CONTAINER(vec3);    
    
    if (std::equal(begin(vec3),end(vec3), begin(vec2)) == 0)
        PRINT("equal(vec3, vec2) == 0 is TRUE");
    else
        PRINT("equal(vec3, vec2) == 0 is FALSE");

    
    DemoClassVec vec4(vec3);
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

    DemoClassVec vec1;
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
    DemoClassVec vec2;
    vec2.assign(begin(demoList), end(demoList));
    PRINT("Size of vec2 is :" + std::to_string(vec2.size()));
    PRINT_CONTAINER(vec2);
        
    PRINT("Using assign with the initializer list");
    DemoClassVec vec3;
    vec3.assign({DemoClass(1), DemoClass(2), DemoClass(3)});
    PRINT("Size of vec3 is :" + std::to_string(vec3.size()));
    PRINT_CONTAINER(vec3);

    PRINT("vec2 is now: ");
    PRINT_CONTAINER(vec2);

    PRINT("vec3 is now: ");
    PRINT_CONTAINER(vec3);

    PRINT("Swapping now : ");
    
    vec2.swap(vec3);

    PRINT("vec2 is now: ");
    PRINT_CONTAINER(vec2);

    PRINT("vec3 is now: ");
    PRINT_CONTAINER(vec3);

    PRINT("Swapping with swap algo function: ");

    std::swap(vec2, vec3);

    PRINT("vec2 is now: ");
    PRINT_CONTAINER(vec2);

    PRINT("vec3 is now: ");
    PRINT_CONTAINER(vec3);
}

void Vector::ElementAccessDemo()
{
    PRINT("Demonstrating element access in vector: \n");

    DemoClassVec vec1 = { DemoClass(1), DemoClass(2), DemoClass(3) };

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
    DemoClassVec vec1;
    PRINT("Size of vec1 at the beginning is :" + std::to_string(vec1.size()));
    
    DemoClass d1(1), d2(2), d3(3);

    vec1.push_back(d1);
    vec1.push_back(d2);
    vec1.push_back(d3);
    PRINT("Size of vec1 after 3 push_back operations is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);

    // Ensure to check if the vector is not empty, before running pop_back.
    // Running pop_back on an empty vector is undefined behavior and might cause a crash
    // Note that VS is doing an assert in debug mode but does nothing for release modes
    if(!vec1.empty())
        vec1.pop_back();
    if (!vec1.empty())
        vec1.pop_back();

    PRINT("Size of vec1 after 2 pop_back operations is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);

    // Use insert to insert elements at the beginning
    vec1.insert(begin(vec1), d2);
    vec1.insert(begin(vec1), d3);
    PRINT("After call to insert(begin(vec1),...) twice");
    PRINT_CONTAINER(vec1);

    vec1.insert(begin(vec1), 5, d3);
    PRINT("After call to insert(begin(vec1),5, d3)");
    PRINT_CONTAINER(vec1);

    std::list<DemoClass> demoList;
    demoList.push_back(DemoClass(111));
    demoList.push_back(DemoClass(121));
    demoList.push_back(DemoClass(112));
    demoList.push_back(DemoClass(222));

    PRINT("This list shall be inserted into the vector: ");
    PRINT_CONTAINER(demoList);

    vec1.insert(begin(vec1) + 2, begin(demoList), end(demoList));
    PRINT("After call to insert from the list (starting at begin(vec1) + 2 position:");
    PRINT_CONTAINER(vec1);

    vec1.insert(begin(vec1) , { DemoClass(-11), DemoClass(-22), DemoClass(-33) });
    PRINT("After call to insert(begin(vec1) , {initializer list})");
    PRINT_CONTAINER(vec1);

    PRINT("Emplacing 333 and -333 into the vector, at the beginning:");
    vec1.emplace(begin(vec1), 333);
    vec1.emplace(begin(vec1), -333);

    PRINT_CONTAINER(vec1);

    PRINT("Emplacing 12345 and -12345 into the vector, at the back:");
    vec1.emplace_back(12345);
    vec1.emplace_back(-12345);

    PRINT_CONTAINER(vec1);

    PRINT("Erasing the first element:");
    vec1.erase(begin(vec1));
    PRINT("Size of vec1 is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);
    
    PRINT("Erasing the 2nd, 3rd, 4th and 5th elements:");
    vec1.erase(begin(vec1) + 2, begin(vec1) + 6); // This is a half open range, hence 2-5 are removed
    PRINT("Size of vec1 is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);

    PRINT("Using resize to increase the size of the vector:");
    vec1.resize(vec1.size() + 5);
    PRINT("Size of vec1 is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);

    PRINT("Using resize to decrease the size of the vector. The last 5 elements shall get removed as per this operation:");
    vec1.resize(vec1.size() - 5);
    PRINT("Size of vec1 is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);

    PRINT("Using resize to increase the size of the vector and add DemoClass(123) as the new members:");
    vec1.resize(vec1.size() + 5, DemoClass(123));
    PRINT("Size of vec1 is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);

    PRINT("Clearing the contents of the vector, thereby removing all the elements:");
    vec1.clear();
    PRINT("Size of vec1 is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);

    // Vectors dont provide an option to directly remove elements at a specific position.
    // We can make use of the STL algorithms, along with erase, to achieve the same.
    vec1.assign({ DemoClass(10), DemoClass(20), DemoClass(30) });
    PRINT("Demonstrating removing a specific element:\nSize of vec1 is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);
    vec1.erase(std::remove(begin(vec1), end(vec1), DemoClass(10)));
    PRINT("After removing all elements with value 10, size of vec1 is :" + std::to_string(vec1.size()));
    PRINT_CONTAINER(vec1);

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
    InsertionDeletionDemo();

    PRINT("End of Vectors Demo");

}