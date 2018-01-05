#pragma once

// This class is just used to print out messages when the constructors and destructors are invoked
class DemoClass
{
    int iValue;
public:
    DemoClass(int iVal = 100); // Default Constructor
    ~DemoClass();

    void SetValue(int iVal);

    int GetValue();

    void PrintValue();

};

