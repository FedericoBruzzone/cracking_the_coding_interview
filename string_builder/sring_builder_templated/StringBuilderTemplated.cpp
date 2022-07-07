#include "StringBuilderTemplated.h"

template <class... Args>
StringBuilder::StringBuilder(Args&&... args)
{
    append(std::forward<Args>(args)...);
}

template <class T>
StringBuilder& StringBuilder::append(const T& arg)
{
    _data << arg;
    return *this;
}

template <class T, class... Args>
StringBuilder& StringBuilder::append(const T& arg, Args&&... args)
{
    _data << arg;
    append(std::forward<Args>(args)...);
    return *this;
}

std::string StringBuilder::toString() const
{
    return _data.str();
}

StringBuilder::operator std::string() const
{
    return toString();
}

template <class T>
StringBuilder& StringBuilder::operator<<(const T& object)
{
    return append(object);
}