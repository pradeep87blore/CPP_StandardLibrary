#include "Deque.h"
#include "DemoClass.h"
#include "Utilities.h"

#include <deque>
#include <algorithm>
#include <string>
#include <list>
#include <exception>

using std::deque;

typedef deque<DemoClass> DemoClassDeque;

void Deque::InitializationDemo()
{
    DemoClassDeque dq1;
    PRINT("Size of dq1 is :" + std::to_string(dq1.size()));
    PRINT_CONTAINER(dq1);

    dq1.push_front(DemoClass()); // Insert a new element into the deque

    DemoClassDeque dq2(dq1);
    PRINT("dq2 is initialized as a copy of dq1\nSize of dq2 is :" + std::to_string(dq2.size()));
    PRINT_CONTAINER(dq2);

    DemoClassDeque dq3 = dq1;
    PRINT("dq3 is initialized as a copy of dq1 using the = operator\nSize of dq3 is :" + std::to_string(dq3.size()));
    PRINT_CONTAINER(dq3);

    DemoClassDeque dq4(std::move(dq1));
    PRINT("dq4 is initialized by moving dq1 into it.\nSize of dq4 is :" + std::to_string(dq4.size()));
    PRINT_CONTAINER(dq4);

    DemoClassDeque dq5 = (std::move(dq2));
    PRINT("dq5 is initialized by moving dq2 into it, using the = operator.\nSize of dq5 is :" + std::to_string(dq5.size()));
    PRINT_CONTAINER(dq5);

    DemoClassDeque dq6(5);
    PRINT("dq6 is initialized with 5 default DemoClass objects\nSize of dq6 is :" + std::to_string(dq6.size()));
    PRINT_CONTAINER(dq6);

    DemoClassDeque dq7(5, DemoClass(1234));
    PRINT("dq7 is initialized with 5 DemoClass objects initialized to 1234\nSize of dq7 is :" + std::to_string(dq7.size()));
    PRINT_CONTAINER(dq7);

    std::list<DemoClass> lst1 = { DemoClass(1), DemoClass(2), DemoClass(3) };
    PRINT("Creating a list lst1 to act as a source of objects for the deque:");
    PRINT_CONTAINER(lst1);
    
    DemoClassDeque dq8(begin(lst1), end(lst1));
    PRINT("dq8 is initialized as a copy of lst1\nSize of dq8 is :" + std::to_string(dq8.size()));
    PRINT_CONTAINER(dq8);

    DemoClassDeque dq9 = { DemoClass(5), DemoClass(6), DemoClass(7) };
    PRINT("dq9 is initialized by using = with an initializer list\nSize of dq9 is :" + std::to_string(dq9.size()));
    PRINT_CONTAINER(dq9);

    DemoClassDeque dq10{ DemoClass(5), DemoClass(6), DemoClass(7) };
    PRINT("dq10 is initialized by an initializer list\nSize of dq10 is :" + std::to_string(dq10.size()));
    PRINT_CONTAINER(dq10);
    

}

void Deque::NonModifyingOperatorsDemo()
{
    PRINT("Demonstrating non-modifying deque operations: \n");
    DemoClassDeque dq1;
    if (dq1.empty())
    {
        PRINT("Created a new deque. It is empty now\nSize of dq1 is " + std::to_string(dq1.size()));
        PRINT_CONTAINER(dq1);
    }

    PRINT("Size operation : " + std::to_string(dq1.size()));

    PRINT("Size operation : " + std::to_string(dq1.max_size()));

    dq1.push_back(DemoClass(10));
    dq1.push_back(DemoClass(20));
    dq1.push_back(DemoClass(30));

    PRINT("Size of dq1 after inserting 3 elements: " + std::to_string(dq1.size()));
    PRINT("Max size of dq1 after inserting 3 elements: " + std::to_string(dq1.max_size()));

    dq1.shrink_to_fit();

    PRINT("After a shrink_to_fit, size of dq1 after inserting 3 elements: " + std::to_string(dq1.size()));
    PRINT("After a shrink_to_fit, max size of dq1 after inserting 3 elements: " + std::to_string(dq1.max_size()));

    // Even though comparing d1 and d2 works, comparing dq1 and dq2 is failing with the following error:
    // 1>c:\program files (x86)\microsoft visual studio 14.0\vc\include\xutility(2919): 
    // error C2672: 'operator __surrogate_func': no matching overloaded function found
    // TODO: Fix and enable this

    /*DemoClassDeque dq2(dq1);

    DemoClass d1(10), d2(10), d3(20);

    if (d1 == d2)
        PRINT("Both are equal");
    
    if (d1 != d3)
        PRINT("Both are unequal");
    if (dq1 == dq2)
    {
        PRINT("dq1 and dq2 are equal");
    }*/

}

void Deque::AssignmentFunctionsDemo()
{


}

void Deque::ElementAccessDemo()
{
    PRINT("Demonstrating element access operations : ");
    DemoClassDeque dq1 = { DemoClass(1), DemoClass(2), DemoClass(3) };

    PRINT("Size of dq1 after inserting 3 elements: " + std::to_string(dq1.size()));
    PRINT_CONTAINER(dq1);

    PRINT("Element at index 0 (dq1[0]): ");
    dq1[0].PrintValue();

    PRINT("Element at index 1 (dq1.at(1)): ");
    dq1.at(1).PrintValue();

    PRINT("Front of dq1: ");
    dq1.front().PrintValue();

    PRINT("Back of dq1: ");
    dq1.back().PrintValue();

    try
    {
        PRINT("Trying to access an index outside the current deque : ");
        dq1.at(10).PrintValue();
    }
    catch (std::exception ex)
    {
        PRINT("Exception caught : " + std::string(ex.what()));
    }

}

void Deque::InsertionDeletionDemo()
{


}




void Deque::Demonstrate()
{
    // Shows the ways deque can be initialized
    InitializationDemo();

    // Demos the non-modifying operations on the deque
    NonModifyingOperatorsDemo();

    // Shows the assignments functions of the deque
    AssignmentFunctionsDemo();

    // Shows how the elements of the deque can be accessed
    ElementAccessDemo();

    // Shows the insertion deletion operations on the deque
    InsertionDeletionDemo();

}