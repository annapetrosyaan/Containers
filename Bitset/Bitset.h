#ifndef __BITSET__
#define __BITSET__

#include <iostream>
#include <string>
#include <fstream>
#include <type_traits>

namespace { const int SIZE = 64; }

template <size_t N> //fixed sequence for N bits
class Bitset
{
public:
    Bitset();
    Bitset(const Bitset&);
    Bitset(const unsigned long long&);
    Bitset(std::string);
    ~Bitset();
public:
    constexpr bool test(const size_t&) const;
    size_t count() const;
    bool none() const noexcept;
    bool any() const noexcept;
    bool all() const noexcept;
    size_t size() const noexcept; // capacity
    bool operator==( const Bitset&) const noexcept;
public:
    Bitset& operator&=( const Bitset&) noexcept;
    Bitset& operator|=( const Bitset&) noexcept;
    Bitset& operator^=( const Bitset&) noexcept;
    Bitset& set() noexcept;
    Bitset& set(std::size_t pos, bool value = true);
    Bitset& reset() noexcept;
    Bitset& reset(size_t);
    Bitset& flip() noexcept;
    Bitset& flip(size_t);
public:
    std::string to_str(const char&,const char&) const;
    unsigned long long to_ullong() const noexcept;
    Bitset operator&(const Bitset&) noexcept;
    Bitset operator|(const Bitset&) noexcept;
    Bitset operator^(const Bitset&) noexcept;
    Bitset operator<<(size_t) const noexcept;
    Bitset operator>>(size_t) const noexcept;
    Bitset& operator<<=(size_t) noexcept;
    Bitset& operator>>=(size_t) noexcept;

public:
    template <size_t S>
    friend std::ostream& operator<<(std::ostream& write,const Bitset& arr);
private:
    void left() noexcept;
    void right() noexcept;
private:
    size_t b_size = N / ::SIZE;
    unsigned long long* b_array = new unsigned long long [N / ::SIZE]{};
};

#include "BitsetImpl.h"

#endif // !__BITSET