#include "HashMap.h"
#include "Vector.cpp"

using namespace std;

/************************************************************************/
/* Inner Class Implementation                                           */
/************************************************************************/
template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::HashBucket::HashBucket(const value_type& item, bool itemActive) :
    item(item),
    itemActive(itemActive)
{

}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::HashBucket::HashBucket(value_type&& item, bool itemActive) :
    item(move(item)),
    itemActive(itemActive)
{

}

/************************************************************************/
/* Class Implementation                                                 */
/************************************************************************/
template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::CloseHashMap() :
    m_hash(),
    m_hashBuckets(100)
{
}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::~CloseHashMap()
{
    clear();
}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
typename CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::const_iterator CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::cbegin() const
{
    // TODO
    return m_list.cbegin();
}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
typename CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::const_iterator CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::cend() const
{
    // TODO
}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
typename CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::iterator CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::begin() const
{
    // TODO
}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
typename CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::iterator CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::end() const
{
    // TODO
}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
void CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::clear()
{
    m_hashBuckets.clear();
}

// TODO(Wuxiang): Should return iterator
template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
bool CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::find(const key_type& itemKey) const
{
    int indexInitial;
    int index = indexInitial = m_hash(itemKey);

    do
    {
        // The buckets guaranteed to not contain this key. because linear probing
        // would insert any item contiguously.
        if (!m_hashBuckets[index].itemActive)
        {
            return false;
        }

        // Further compare the key value, if not the same continue linear search.
        else if (m_keyEqual(m_hashBuckets[index].item.first, itemKey))
        {
            return true;
        }

        index = (index + 1) % m_hashBuckets.size();
    }
    while (index != indexInitial);

    return index < m_hashBuckets.size();
}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
bool CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::insert(const value_type& item)
{
    int indexInitial;
    int index = indexInitial = m_hash(item.first) % m_hashBuckets.size();

    do
    {
        // The buckets has vacant place to insert (confirm the item is not in
        // all the buckets)
        if (!m_hashBuckets[index].itemActive)
        {
            m_hashBuckets[index] = HashBucket(item, true);
            return true;
        }

        // Found the same key in the bucket
        else if (m_hashBuckets[index].itemActive
                 && m_keyEqual(m_hashBuckets[index].item.first, item.first))
        {
            // Found the same key and item in the bucket
            if (m_mappedEqual(m_hashBuckets[index].item.second, item.second))
            {
                return true;
            }

            // Found a different item with the same key in the bucket
            else
            {
                // Replace the item with the inserted one
                m_hashBuckets[index].item.second = item.second;
            }
        }

        index = (index + 1) % m_hashBuckets.size();
    }
    while (index != indexInitial);

    return false;
}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
void CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::rehash()
{
    // TODO
}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
bool CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::remove(const value_type& item)
{
    int indexInitial;
    int index = indexInitial = m_hash(item.first);
    // TODO
    find(item.first);

    do
    {
    }
    while (index != indexInitial);

    return true;
}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename TEqual>
void CloseHashMap<Key, T, Hash, KeyEqual, TEqual>::reserve(int n)
{
    m_hashBuckets.reserve(n);
}
