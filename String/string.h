#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstddef>
#include <initializer_list>

namespace STL
{
class String
{
public:
    String();
    String(int);
    ~String();
    String(unsigned int, char);
    String(const char*);
    String(const String &);
    String(String&&);
    String& operator=(const String& obj);
    String& operator=(String&& );
public:
    String operator+(const String &)const;
    String operator+(const char);
    String& operator+=(const String &);
    bool operator>(const String &) const;
    bool operator<(const String &) const;
    bool operator==(const String &) const;
    bool operator!=(const String &) const;
    bool operator>=(const String &) const;
    bool operator<=(const String &) const;
public:
    void push_back(char symbol);
    char pop_back();
    void resize(const int ,char);
    char erase(const int );
    String& erase(const int,int);
    int find(const char) const;
    int find(const char*) const;
    bool empty();
    void replace (int, const char*); 
    void insert(const int, char );
    void insert(const int,const char*);
    void clear();
public:    
    char& operator[](const unsigned index);
    const char& operator[](const unsigned index) const;
    char& at(const unsigned index);
    const char& at(const unsigned index) const;
    inline int size() const {return m_size;}
private:
        int m_capacity;
        char* m_buffer;
        int m_size;
        const static int LIM = 100;

}; //class String

//Utiliy
size_t strlen(const char *s)
{
  size_t count = 0;
  while(*s!='\0')
  {
      count++;
      s++;
  }
  return count;
}

} //namespace STL

#endif //STRING_H