/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 ); // capacity

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

*/

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {

    }

    int get(int key) {

        auto it = _map.find(key);
        if(it != _map.end()){
            _cache.splice(_cache.begin(), _cache, it->second);
            return it->second->second;
        }
        return -1;

    }

    void put(int key, int value) {

        auto it = _map.find(key);
        if(it != _map.end()){
            it->second->second = value;
            _cache.splice(_cache.begin(), _cache, it->second);
            return;
        }

        if(_map.size() == _capacity){
            auto it = _cache.back();
            _map.erase(it.first);
            _cache.pop_back();
        }

        _cache.emplace_front(key, value);
        _map[key] = _cache.begin();
        return;

    }

private:
    int _capacity;
    list<pair<int,int>> _cache;
    unordered_map<int, list<pair<int,int>>::iterator> _map;

};
