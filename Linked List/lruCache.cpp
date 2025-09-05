// Problem Statement :- https://leetcode.com/problems/lru-cache/description/

// Brute Force :- Put and Get operations are very easy. But remember, store them in order, say we had :- put (1, 1) and then put (2, 2)
// It then caled get(1), so we got (1, 1) for it, but it was accessed, so now they should be stored like :- (1, 1) comes ahead and (2, 2) went behind. So as to first delete (2, 2) as (1, 1) was recently accessed.
// Say we then came across (3, 3), if size = 2, we now have to eliminate and we eliminated from behind i.e. (2, 2) and now we have :- (1, 1) (3, 3)
// If an element which want to get is not present then send -1 for that.
// Now this deletion can be simulated using a vector in which we delete from front and push to back where element at back is the latest entry.
// Btw, if a new element with same key as one alr present in cache comes, we still have to delete that from cache, and insert the new one.

// Optimal Approach :- The costly operation is erase, as we have to traverse. One way is to using a DLL and a map to store key and their address and value pair. 
// With addresses, we can insert and delete nodes in O(1) in DLL. This also allows moving to the front by unlinking and relinking at head.
// In vector, push back was easy. But in DLL pushing in back is hard so we will push in front only. The node at head i.e. at front will be the latest used node in DLL.
// For checking dupliacte key in putting and even getting key is very easy with map.
// While getting you ahve to also put that node in front now. So use map to get it's address and go to that and erase it, and then put the node in front, then update the address in map with the new one.
// Ofc when cache fills and a new node comes we have to pop from back and then insert the new node in front.
// To avoid manually maintaining pointers, use DLL STL.

#include <bits/stdc++.h>
using namespace std;

// // Brute Force
// class LRUCache {
// public:
//     vector<pair<int, int>> cache;
//     int n;

//     LRUCache(int capacity) {
//         n = capacity;
//     }
    
//     int get(int key) {
//         for (int i = 0; i < cache.size(); i++) {
//             if (cache[i].first == key) {
//                 int val = cache[i].second;
//                 pair<int, int> temp = cache[i];
//                 cache.erase(cache.begin() + i);
//                 cache.push_back(temp);
//                 return val;
//             }
//         }

//         return -1;
//     }
    
//     void put(int key, int value) {
//         for (int i = 0; i < cache.size(); i++) {
//             if (cache[i].first == key) {
//                 cache.erase(cache.begin() + i);
//                 cache.push_back({key, value});
//                 return;
//             }
//         }

//         if (cache.size() == n) {
//             cache.erase(cache.begin());
//             cache.push_back({key, value});
//         } else {
//             cache.push_back({key, value});
//         }

//         return;
//     }
// };

// Optimal Approach
class LRUCache {
public:
    list<int> dll; // DLL to maintain order of keys: front = most recent, back = least recent
    map<int, pair<list<int>::iterator, int>> mp; 
    // Map stores key -> {iterator to DLL node, value}
    // Iterator helps us find & erase a key from DLL in O(1) time.
    
    int n; // capacity left (decreases when inserting, increases when deleting)

    // Helper function: move accessed/updated key to front (most recently used)
    void makeRecentlyUsed(int key) {
        dll.erase(mp[key].first);   // Remove old position of key from DLL
        dll.push_front(key);        // Reinsert key at the front (most recent)
        mp[key].first = dll.begin(); // Update iterator in map to new position
    }

    // Constructor: set cache capacity
    LRUCache(int capacity) {
        n = capacity;    
    }
    
    // Get value for a key
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1; // Key not found
        } 
        makeRecentlyUsed(key);       // Mark as recently used
        return mp[key].second;       // Return the value
    }
    
    // Insert or update a key-value pair
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Key already exists → update value and move to front
            mp[key].second = value;
            makeRecentlyUsed(key);
        } else {
            // Key does not exist → insert at front
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--; // Reduce capacity
        }

        // If cache exceeds capacity → remove least recently used (back of DLL)
        if (n < 0) {
            int key_to_delete = dll.back(); // Least recently used key
            dll.pop_back();                 // Remove from DLL
            mp.erase(key_to_delete);        // Remove from map
            n++;                            // Restore capacity count
        }
    }
};

int main() {

}