#pragma once

#include <utility>

#include "Vector.h"
#include <unordered_map>

template <typename Key>
constexpr bool HashHasDefault()
{
    return std::is_same<Key, int>::value;
}

template <typename Key>
struct Hash
{
    static_assert(HashHasDefault<Key>(),
                  "The hash function for given key type is not provided by default.");

    int operator()(const Key key) const;
};

template <>
struct Hash<int>
{
    int operator()(const int key) const
    {
        return key % 7;
    }
};

// @Summary: Base abstract template class for separating chaining hash table
// and probing hash table.
template <typename Key, typename T, typename Hash = Hash<Key>,
          typename KeyEqual = std::equal_to<Key>, typename TEqual = std::equal_to<T>>
class HashMap
{
    class const_iterator
    {

    };

    class iterator : public const_iterator
    {

    };

public:
    using hash_type    = Hash;
    using key_type     = Key;
    using key_equal    = KeyEqual;
    using mapped_type  = T;
    using mapped_equal = TEqual;
    using value_type   = std::pair<key_type, mapped_type>;

    virtual const_iterator cbegin() const = 0;
    virtual const_iterator cend() const = 0;
    virtual iterator       begin() const = 0;
    virtual iterator       end() const = 0;

    virtual void clear() = 0;
    virtual bool find(const key_type& itemKey) const = 0;
    virtual bool insert(const value_type& item) = 0;
    virtual void rehash() = 0;
    virtual bool remove(const value_type& item) = 0;
    virtual void reserve(int n) = 0;
};

// @Summary: Close hashing, or probing hash table implementation.
template <typename Key, typename T, typename Hash = Hash<Key>,
          typename KeyEqual = std::equal_to<Key>, typename TEqual = std::equal_to<T>>
class CloseHashMap :
    public HashMap <Key, T, Hash, KeyEqual, TEqual>
{
    // NOTE(Wuxiang): For making Intellisense work.
private:
    using base         = HashMap<Key, T, Hash, KeyEqual, TEqual>;
    using hash_type    = typename base::hash_type;
    using key_type     = typename base::key_type;
    using key_equal    = typename base::key_equal;
    using mapped_type  = typename base::mapped_type;
    using mapped_equal = typename base::mapped_equal;
    using value_type   = typename base::value_type;

    using const_iterator = typename base::const_iterator;
    using iterator       = typename base::iterator;

public:
    /************************************************************************/
    /* Inner Class Declaration                                              */
    /************************************************************************/
    struct HashBucket
    {
        value_type item;
        bool       itemActive;

        // Provide a default constructor for array initialization
        HashBucket(const value_type& item = value_type(), bool itemActive = false);
        HashBucket(value_type&& item, bool itemActive = false);
    };

public:
    /************************************************************************/
    /* Class Declaration                                                    */
    /************************************************************************/
    CloseHashMap();
    virtual ~CloseHashMap();

    virtual const_iterator cbegin() const override;
    virtual const_iterator cend() const override;
    virtual iterator       begin() const override;
    virtual iterator       end() const override;

    virtual void clear() final override;
    virtual bool find(const key_type& itemKey) const override;
    virtual bool insert(const value_type& item) override;
    virtual void rehash() override;
    virtual bool remove(const value_type& item) override;
    virtual void reserve(int n) override;

protected:
    key_equal          m_keyEqual;
    mapped_equal       m_mappedEqual;

    hash_type          m_hash;
    Vector<HashBucket> m_hashBuckets;
};

// @Summary: Open hashing, or separate chaining hash table implementation.
template <typename Key, typename T, typename Hash = Hash<Key>,
          typename Equal = std::equal_to<Key>>
class OpenHashMap : public HashMap<Key, T, Hash, Equal>
{
};
