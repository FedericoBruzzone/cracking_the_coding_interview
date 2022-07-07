#pragma once

#include <string>
#include <sstream>

class StringBuilder
{
public:
    StringBuilder() = default;

    template <class... Args>
    explicit StringBuilder(Args&&... args);

    template <class T>
    StringBuilder& append(const T& arg);

    template <class T, class... Args>
    StringBuilder& append(const T& arg, Args&&... args);

    std::string toString() const;

    operator std::string() const;

    template <class T>
    StringBuilder& operator<<(const T& object);

private:
    std::ostringstream _data;
};
