#pragma once


class Vector
{
    // Prevent instantiation
    Vector() = delete;
    ~Vector() = delete;

    static void InitializationDemo();
    static void NonModifyingOperatorsDemo();

public:

    static void Demonstrate();
};

