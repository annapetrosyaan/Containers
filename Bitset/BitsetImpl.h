#include "Bitset.h"

// ctors 
template <size_t N>
Bitset<N>::Bitset() = default;

template <size_t N>
Bitset<N>::Bitset(const unsigned long long& val)
{
    b_array[0] = val;
}

template <size_t N>
Bitset<N>::Bitset(const Bitset<N>& rhs)
{
   for(int i=0; i < b_size; ++i)
   {
      b_array[i] = rhs[i];
   }
}

template <size_t N>
Bitset<N>::~Bitset()
{
    delete [] b_array;
    b_array = nullptr;
}
// element access and capacity
template <size_t N>
constexpr bool Bitset<N>::test(const size_t& index) const //access specific bit to see its set or not
{
   static_assert(index >= N,"Given index is bigger than size of bitset!");
   return ((b_array[index / ::SIZE]) &  (1ull << (index % ::SIZE))); 
}

template <size_t N>
size_t Bitset<N>::count() const  // number of bits set to true
{
   size_t count{};
   for(int i = 0; i < N; ++i)
   {
       count += test(i);
   }
   return count;
}

template <size_t N>
bool Bitset<N>::none() const noexcept
{
   for(int i=0; i < b_size; ++i)
   {
       if(b_array[i] != 0)
       {
           return false;
           break;
       }
   }
  return true; 
}

template <size_t N>
bool Bitset<N>::any() const noexcept //if one/more bits are 1 returns true
{
   return !none();
}

template <size_t N>
bool Bitset<N>::all() const noexcept
{ 
   return count() == N;
}

template <size_t N>
size_t Bitset<N>::size() const noexcept
{
    return N;
}

template <size_t N>
bool Bitset<N>::operator==(const Bitset<N>& rhs) const noexcept
{
   if (rhs.b_size == this->b_size)
   {
      for(int i = 0 ; i < b_size ; ++i)
      {
         if(b_array[i] != rhs[i])
         {
            return false;
         }
      }
   }
   return true;
}
// modifiers
template <size_t N>
Bitset<N>& Bitset<N>::operator&=( const Bitset& rhs) noexcept
{
   Bitset temp(*this);
   for(int i=0 ; i < b_size ; ++i)
   {
      temp[i] &= rhs.m_array[i];
   }
  return *this;
}

template <size_t N>
Bitset<N>& Bitset<N>::operator|=( const Bitset& rhs) noexcept
{
   Bitset temp(*this);
   for(int i=0 ; i<b_size ; ++i)
   {
      temp[i] |= rhs.b_array[i];
   }
  return *this; 
}

template <size_t N>
Bitset<N>& Bitset<N>::operator^=( const Bitset& rhs) noexcept
{
   Bitset temp(*this);
   for(int i=0 ; i<b_size ; ++i)
   {
      temp[i] ^= rhs.b_array[i];
   }
  return *this; 
}

template <size_t N>
Bitset<N>& Bitset<N>::set() noexcept
{
   for(int i = 0; i < b_size ; ++i)
   {
      b_array[i] = ~(0ull);
   }
   return *this;
}

template <size_t N>
Bitset<N>& Bitset<N>::set(size_t pos,bool value)
{
   b_array[pos / ::SIZE] |= (unsigned long long)value << pos % ::SIZE;
   return *this;
}

template <size_t N>
Bitset<N>& Bitset<N>::reset() noexcept
{
   for(int i= 0; i < b_size ; ++i)
   {
      b_array[i] = 0ull;
   }
  return *this; 
}

template <size_t N>
Bitset<N>& Bitset<N>::reset(size_t pos) //sets bit at pos to false
{
   b_array[pos / ::SIZE ] &= ~(0ull << pos % ::SIZE);
   return *this;
}

template <size_t N>
Bitset<N>& Bitset<N>::flip() noexcept //changes true to false and backwards
{
   for(int i=0 ; i < b_size ; ++i)
   {
      b_array[i] = ~b_array[i];
   }
  return *this;
}

template <size_t N>
Bitset<N>& Bitset<N>::flip(size_t pos)
{
   b_array[pos / ::SIZE ] ^= (1ull << pos % ::SIZE);
   return *this; 
}

template <size_t N>
std::string Bitset<N>::to_str(const char& o,const char& z) const
{
   std::string s;
   for(int i=0 ; i < N ; ++i)
   {
      s.push_back( test(i) == 0 ? z : o);
   }
 return std::string(s.rbegin(),s.rend());
}

template <size_t N>
unsigned long long Bitset<N>::to_ullong() const noexcept
{
 return b_array[0];
}

template <size_t N>
Bitset<N> Bitset<N>::operator&(const Bitset<N>& rhs) noexcept
{
   Bitset temp(*this);
   for(int i=0 ; i < b_size ; ++i)
   {
      temp[i] &= rhs.m_array[i]; 
   }
 return temp;
}

template <size_t N>
Bitset<N> Bitset<N>::operator|(const Bitset<N>& rhs) noexcept
{
   Bitset temp(*this);
   for(int i=0 ; i < b_size ; ++i)
   {
      temp[i] |= rhs.b_array[i];
   }
 return temp;
}

template <size_t N>
Bitset<N> Bitset<N>::operator^(const Bitset<N>& rhs) noexcept
{
   Bitset temp(*this);
   for(int i=0 ; i < b_size ; ++i)
   {
      temp[i] ^= rhs[i];
   }
 return temp;  
}

template <size_t N>
Bitset<N> Bitset<N>::operator<<(size_t pos) const noexcept
{
   Bitset temp(*this);
   for(int i = 0 ; i < pos ; ++i)
   {
      temp.left();
   }
  return temp; 
}

template <size_t N>
Bitset<N> Bitset<N>::operator>>(size_t pos) const noexcept
{
   Bitset temp(*this);
   for(int i = 0 ; i < pos ; ++i)
   {
      temp.right();
   }
  return temp; 
}

template <size_t N>
Bitset<N>& Bitset<N>::operator<<=(size_t pos) noexcept
{
   for(int i = 0 ; i < pos ; ++i)
   {
      left();
   }
  return *this; 
}

template <size_t N>
Bitset<N>& Bitset<N>::operator>>=(size_t pos) noexcept
{
   for (int i = 0 ; i < pos ; ++i)
   {
      right();
   }
  return *this; 
}

// output
template <size_t S>
std::ostream& operator<<(std::ostream& write,const Bitset<S>& arr) noexcept
{
    return write << arr.to_string();
} 

template <size_t N>
void Bitset<N>::left() noexcept
{
   bool b = false, a = false;
   for(int i=0 ; i < b_size ; ++i)
   {
      a = b_array[i] & 1ull << ::SIZE - 1;
      b_array[i] <<= 1;
      b_array[i] |= b;
      b = a;
   }
}

template <size_t N>
void Bitset<N>::right() noexcept
{
   bool b = false, a = false;
   for(int i = b_size ; i >= 0 ; --i) 
   {
      a = b_array[i] & 1ull;
      b_array[i] >>= 1;
      b_array[i] |= b;
      b = a;
   }  
}
