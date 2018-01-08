#include "DemoClass.h"
#include "Utilities.h"


#define NO_DEBUG_HERE // Enable this flag to prevent debug prints


DemoClass::~DemoClass()
{
#ifndef NO_DEBUG_HERE
    PRINT("DemoClass destructor called for class with value : " + std::to_string(iValue));
#endif
}


DemoClass::DemoClass(int iVal): iValue(iVal)
{
#ifndef NO_DEBUG_HERE
    PRINT("DemoClass constructor called for class with value : " + std::to_string(iValue));
#endif
}

void DemoClass::SetValue(int iVal = 100)
{
    this->iValue = iVal;
}

int DemoClass::GetValue() const
{
    return iValue;
}

void DemoClass::PrintValue()
{
    PRINT(std::to_string(iValue));
}

//// Equal to operator
bool DemoClass::operator== (const DemoClass &rhs)
{
    if (rhs.GetValue() == this->GetValue())
        return true;
    else
        return false;
}

// Compares two classes and returns true if they match
bool DemoClass::Equal(DemoClass &rhs)
{
    if (this->GetValue() == rhs.GetValue())
        return true;
    else
        return false;

}

//
//// Lesser than operator:
//bool DemoClass::operator < (const DemoClass &rhs)
//{
//    if (this->GetValue() < rhs.GetValue())
//        return true;
//
//    return false;
//}

// Equal to operator
bool operator== (DemoClass &lhs, DemoClass &rhs)
{
    if (rhs.GetValue() == lhs.GetValue())
        return true;
    else
        return false;
}

// Not Equal to operator:
bool operator != (DemoClass &lhs, DemoClass &rhs)
{
    if (rhs.GetValue() != lhs.GetValue())
        return true;

    return false;
}

// Lesser than operator:
bool operator < (DemoClass &lhs, DemoClass &rhs)
{
    if (lhs.GetValue() < rhs.GetValue())
        return true;

    return false;
}

// Greater than operator:
bool operator > (DemoClass &lhs, DemoClass &rhs)
{
    if (lhs.GetValue() > rhs.GetValue())
        return true;

    return false;
}

// Lesser than or equal to operator:
bool operator <= (DemoClass &lhs, DemoClass &rhs)
{
    if (lhs.GetValue() <= rhs.GetValue())
        return true;

    return false;
}

// Greater than or equal to operator:
bool operator >= (DemoClass &lhs, DemoClass &rhs)
{
    if (lhs.GetValue() >= rhs.GetValue())
        return true;

    return false;
}


// Compares two classes and returns true if they match
bool Equal(DemoClass &lhs, DemoClass &rhs)
{
    if (lhs.GetValue() == rhs.GetValue())
        return true;
    else 
        return false;
}