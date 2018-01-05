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

    // Overloaded operators:
    
    // Equal to operator:
    bool operator == (DemoClass &);

    // No Equal to operator:
    bool operator != (DemoClass &);

    // Lesser than operator:
    bool operator < (DemoClass &);

    // Greater than operator:
    bool operator > (DemoClass &);

    // Lesser than or equal to operator:
    bool operator <= (DemoClass &);

    // Greater than or equal to operator:
    bool operator >= (DemoClass &);
};

