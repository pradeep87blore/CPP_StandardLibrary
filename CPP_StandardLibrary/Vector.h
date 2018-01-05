#pragma once


class Vector
{
    // Prevent instantiation
    Vector() = delete;
    ~Vector() = delete;

    static void InitializationDemo();
    static void NonModifyingOperatorsDemo();
    static void AssignmentFunctionsDemo();
    static void ElementAccessDemo();

public:

    static void Demonstrate();
};

