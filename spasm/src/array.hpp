#pragma once

#include <string>
#include <unordered_map>

#include "string.hpp"

namespace SpasmImpl
{
typedef std::unordered_map<size_t, long long int> SPArray;

class SPArrayValue
{
   public:
    explicit SPArrayValue(SPArray s) : m_Value(std::move(s)) {}

    SPArrayValue(size_t _size) {
        size = _size;
    };
    SPArrayValue(const SPArrayValue&) = default;
    SPArrayValue(SPArrayValue&&) = default;
    SPArrayValue& operator=(const SPArrayValue&) = delete;
    SPArrayValue& operator=(SPArrayValue&&) = default;

    const SPArray& GetValue() const {
        return m_Value;
    }

    long long int Get(size_t s) const {
        return m_Value.at(s);
    }

    void Put(size_t idx, long long int value) {
        if (size < idx + 1)
            size = idx + 1;
        m_Value[idx] = value;
    }
    
    size_t Size() const {
        return size;
    }

    bool operator==(const SPArrayValue& rhs) const
    {
        return &m_Value == &rhs.m_Value;
    }

    bool operator==(const SPArray& rhs) const
    {
        return &m_Value == &rhs;
    }

   private:
    size_t size;
    SPArray m_Value;
};
}  // namespace SpasmImpl
