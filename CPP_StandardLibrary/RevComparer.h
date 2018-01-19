#pragma once

template <typename T>
class RevComparer
{
public:
    bool operator()(const T param1, const T param2) const
    {
        return (param1 > param2);
    }
};