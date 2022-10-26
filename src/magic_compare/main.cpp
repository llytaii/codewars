// Challenge:
// https://www.codewars.com/kata/59ad0147485a4d9d3f0000a9

#include <iostream>
#include <string>
#include <vector>

template <class T>
class MagicCompare
{
public:
    MagicCompare(T t) : value{t} {};
    T value{};
    // *
    friend MagicCompare operator*(const MagicCompare &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs.value * rhs.value};
    }
    friend MagicCompare operator*(const MagicCompare &lhs, const double &rhs)
    {
        return MagicCompare{rhs * lhs.value};
    }
    friend MagicCompare operator*(const double &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs * rhs.value};
    }
    friend MagicCompare operator*(const MagicCompare &lhs, const int &rhs)
    {
        return MagicCompare{rhs * lhs.value};
    }
    friend MagicCompare operator*(const int &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs * rhs.value};
    }
    // +=
    MagicCompare &operator+=(const MagicCompare &other)
    {
        value += other.value;
        return *this;
    }
    // <
    friend MagicCompare operator<(const int &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs} < rhs;
    }
    friend MagicCompare operator<(const MagicCompare &lhs, const int &rhs)
    {
        return lhs < MagicCompare{rhs};
    }
    friend MagicCompare operator<(const double &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs} < rhs;
    }
    friend MagicCompare operator<(const MagicCompare &lhs, const double &rhs)
    {
        return lhs < MagicCompare{rhs};
    }
    friend MagicCompare operator<(const MagicCompare &lhs, const MagicCompare &rhs)
    {
        MagicCompare tmp = rhs.value;
        tmp.last_result = lhs.last_result && lhs.value < rhs.value;
        return tmp;
    }

    // >
    friend MagicCompare operator>(const int &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs} > rhs;
    }
    friend MagicCompare operator>(const MagicCompare &lhs, const int &rhs)
    {
        return lhs > MagicCompare{rhs};
    }
    friend MagicCompare operator>(const double &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs} > rhs;
    }
    friend MagicCompare operator>(const MagicCompare &lhs, const double &rhs)
    {
        return lhs > MagicCompare{rhs};
    }
    friend MagicCompare operator>(const MagicCompare &lhs, const MagicCompare &rhs)
    {
        MagicCompare tmp = rhs.value;
        tmp.last_result = lhs.last_result && lhs.value > rhs.value;
        return tmp;
    }

    // !=
    friend MagicCompare operator!=(const int &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs} != rhs;
    }
    friend MagicCompare operator!=(const MagicCompare &lhs, const int &rhs)
    {
        return lhs != MagicCompare{rhs};
    }
    friend MagicCompare operator!=(const double &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs} != rhs;
    }
    friend MagicCompare operator!=(const MagicCompare &lhs, const double &rhs)
    {
        return lhs != MagicCompare{rhs};
    }
    friend MagicCompare operator!=(const MagicCompare &lhs, const MagicCompare &rhs)
    {
        MagicCompare tmp = rhs.value;
        tmp.last_result = lhs.last_result && lhs.value != rhs.value;
        return tmp;
    }

    // ==
    friend MagicCompare operator==(const int &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs} == rhs;
    }
    friend MagicCompare operator==(const MagicCompare &lhs, const int &rhs)
    {
        return lhs == MagicCompare{rhs};
    }
    friend MagicCompare operator==(const double &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs} == rhs;
    }
    friend MagicCompare operator==(const MagicCompare &lhs, const double &rhs)
    {
        return lhs == MagicCompare{rhs};
    }
    friend MagicCompare operator==(const MagicCompare &lhs, const MagicCompare &rhs)
    {
        MagicCompare tmp = rhs.value;
        tmp.last_result = lhs.last_result && lhs.value == rhs.value;
        return tmp;
    }
    // >=
    friend MagicCompare operator>=(const int &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs} >= rhs;
    }
    friend MagicCompare operator>=(const MagicCompare &lhs, const int &rhs)
    {
        return lhs >= MagicCompare{rhs};
    }
    friend MagicCompare operator>=(const double &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs} >= rhs;
    }
    friend MagicCompare operator>=(const MagicCompare &lhs, const double &rhs)
    {
        return lhs >= MagicCompare{rhs};
    }
    friend MagicCompare operator>=(const MagicCompare &lhs, const MagicCompare &rhs)
    {
        MagicCompare tmp = rhs.value;
        tmp.last_result = lhs.last_result && lhs.value >= rhs.value;
        return tmp;
    }

    // <=
    friend MagicCompare operator<=(const int &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs} <= rhs;
    }
    friend MagicCompare operator<=(const MagicCompare &lhs, const int &rhs)
    {
        return lhs <= MagicCompare{rhs};
    }
    friend MagicCompare operator<=(const double &lhs, const MagicCompare &rhs)
    {
        return MagicCompare{lhs} <= rhs;
    }
    friend MagicCompare operator<=(const MagicCompare &lhs, const double &rhs)
    {
        return lhs <= MagicCompare{rhs};
    }
    friend MagicCompare operator<=(const MagicCompare &lhs, const MagicCompare &rhs)
    {
        MagicCompare tmp = rhs.value;
        tmp.last_result = lhs.last_result && lhs.value <= rhs.value;
        return tmp;
    }

    operator bool() const { return last_result; }
    operator int() const { return value; }
    operator double() const { return value; }

    void operator++() { ++value; }
    void operator--() { --value; }

private:
    mutable bool last_result{true};
};

using Integer = MagicCompare<int>;

int main()
{
    for (Integer i = 0; i < 3; ++i)
        if (5 > i < 7 != i)
            std::cout << "true" << std::endl;
    Integer i = 5;
    std::vector<int> v;
    v.push_back(i);
}