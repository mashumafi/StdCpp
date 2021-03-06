#pragma once

#include <fstream>
#include <iostream>

template<class T, class U>
class StreamWrapper
{
public:
  StreamWrapper(std::fstream* ios) : m_stream(ios), m_pos(ios->tellg())
  {
  }
  virtual ~StreamWrapper(void)
  {
  }
  void save(void) const
  {
    m_stream->seekp(m_pos, std::ios::beg);
    m_stream->write(reinterpret_cast<const char*>(&m_data), sizeof(T));
    const_cast<U*>(dynamic_cast<const U*>(this))->saved();
  }
  virtual void load(void)
  {
    m_stream->seekg(m_pos, std::ios::beg);
    m_stream->read(reinterpret_cast<char*>(&m_data), sizeof(T)); 
  }
  std::streampos pos(void) const
  {
    return m_pos;
  }
protected:
  T m_data;
  std::fstream* m_stream;
  template<class V> void save(const V* var) const
  {
    m_stream->seekp(m_pos + (reinterpret_cast<const char*>(var) - reinterpret_cast<const char*>(&m_data)), std::ios::beg);
    m_stream->write(reinterpret_cast<const char*>(var), sizeof(V));
    const_cast<U*>(dynamic_cast<const U*>(this))->saved();
  }
  std::streamoff m_pos;
};
