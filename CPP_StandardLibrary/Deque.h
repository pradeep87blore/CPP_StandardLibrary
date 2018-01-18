#pragma once
class Deque
{
    // Prevent instantiation
    Deque() = delete;
    ~Deque() = delete;

    static void InitializationDemo();
    static void NonModifyingOperatorsDemo();
    static void AssignmentFunctionsDemo();
    static void ElementAccessDemo();
    static void InsertionDeletionDemo();

public:
    static void Demonstrate();

};

