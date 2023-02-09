#pragma once

#include <string>
#include <unordered_map>
#include <iterator>

#include "string.hpp"
#include "array.hpp"

namespace SpasmImpl
{
typedef std::unordered_map<SPString, long long int> SPObject;
typedef std::vector<SPString> SPObjectKeys;

class SPObjectValue
{
   public:
    explicit SPObjectValue(SPObject s) : m_Value(std::move(s)) {}

    SPObjectValue() = default;
    SPObjectValue(const SPObjectValue&) = default;
    SPObjectValue(SPObjectValue&&) = default;
    SPObjectValue& operator=(const SPObjectValue&) = delete;
    SPObjectValue& operator=(SPObjectValue&&) = default;

    const SPObject& GetValue() const {
        return m_Value;
    }

    long long int Get(SPString s)
    {
        return m_Value.at(s);
    }

    void Put(SPString key, long long int value)
    {
        SPString _key = std::move(key);
        m_Value[_key] = value;
    }
    
    size_t Size()
    {
        return m_Value.size();
    }
    
    const SPObjectKeys Keys() const
    {
        SPObjectKeys keys;
        keys.reserve(m_Value.size());
        for(auto kv : m_Value) {
            keys.push_back(kv.first);
        }
        return keys;
    }

    bool operator==(const SPObjectValue& rhs) const
    {
        return m_Value == rhs.m_Value;
    }

    bool operator==(const SPObject& rhs) const
    {
        return m_Value == rhs;
    }

   private:
    SPObject m_Value;
};
}  // namespace SpasmImpl
