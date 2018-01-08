#pragma once

//#include <utility>
//using std::rel_ops::operator!=;
//using std::rel_ops::operator>;
//using std::rel_ops::operator<=;
//using std::rel_ops::operator>=;

// This class is just used to print out messages when the constructors and destructors are invoked
class DemoClass
{
    int iValue;
public:
    DemoClass(int iVal = 100); // Default Constructor
    ~DemoClass();

    void SetValue(int iVal);

    int GetValue() const;

    void PrintValue();

    // Overloaded operators:

    // Equal to operator:
    bool operator == (const DemoClass &);

    // No Equal to operator:
    //bool operator != (DemoClass &);

    // Lesser than operator:
    //bool operator < (const DemoClass &);

    // Greater than operator:
    //bool operator > (DemoClass &);

    // Lesser than or equal to operator:
    //bool operator <= (DemoClass &);

    // Greater than or equal to operator:
    //bool operator >= (DemoClass &);

    bool Equal(DemoClass &rhs);

};
// Equal to operator:
bool operator== (DemoClass &lhs, DemoClass &rhs);

// Not Equal to operator:
bool operator != (DemoClass &lhs, DemoClass &rhs);

// Lesser than operator:
bool operator < (DemoClass &lhs, DemoClass &rhs);

// Greater than operator:
bool operator > (DemoClass &lhs, DemoClass &rhs);

// Lesser than or equal to operator:
bool operator <= (DemoClass &lhs, DemoClass &rhs);

// Greater than or equal to operator:
bool operator >= (DemoClass &lhs, DemoClass &rhs);

// Compares two classes and returns true if they match
bool Equal(DemoClass &lhs, DemoClass &rhs);
