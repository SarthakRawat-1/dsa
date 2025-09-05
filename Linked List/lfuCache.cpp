// Problem Statement :- https://leetcode.com/problems/lfu-cache/

// Once revise lruCache.cpp
// Use a ordered map (so we can easily find least counter as it will be the first element in map) freq which stores counter i.e. no of times that element appeared and a dll, which stores the element with that counter.
// We will use another map mp to store key and address of node.
// If counter is same, then eliminate the least recently used once.

// Check if key alr exists in mp or not. If not, then this is new. Check if we have capacity left. Let's say this is the first node overall.
// So it's counter will obv be 1 and make a node with key and value in DLL to store in freq map (ofc this will be pushed in front just like in lruCache.cpp) and also in mp we have to put key and address which we can find from that dll.begin().
// Now let's say we got another node. And we still have capacity and this is new key, so insert it in counter 1 dll also but in front again and also add in mp.
// When you are asked to get a key, check if it exists. If it does using mp, go to it's address which is a dll node which has it's key and value. But now as we have accessed it, we have to increase it's counter and hence store it in different dll.
// To make things easier, in our dll node we will also add counter to the node besides key and value. Now when we go to that address, we know that the freq of that. Once accessed, we now have to erase this node from that dll and now put this node in front of dll of counter + 1.
// And now also update this new address of the key in mp too (address is again dll.begin() where dll is dll of the increased/new counter). 

// Ofc for deletion, first ele in freq has least counter. We can also find it's dll and pop the node at back (because if same counters, then pop from back like lru).
// If all nodes were deleted and no dll exists, then also erase that counter entry from freq map.

#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    int cap;   // Maximum capacity of cache
    int size;  // Current number of elements in cache

    // mp stores key -> iterator pointing to node inside list
    unordered_map<int, list<vector<int>>::iterator> mp;

    // freq stores frequency -> DLL of nodes
    // Using ordered map so smallest frequency is at freq.begin()
    map<int, list<vector<int>>> freq;

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    // Helper function: promote a node to higher frequency
    void makeMostFrequentlyUsed(int key) {
        // Current node info: {key, value, frequency}
        auto &vec = (*(mp[key]));
        int val = vec[1];
        int f   = vec[2];

        // Remove from current frequency list
        freq[f].erase(mp[key]);

        // If that list becomes empty, remove this freq entry
        if (freq[f].empty()) {
            freq.erase(f);
        }

        // Increase frequency count
        f++;

        // Insert node into front of new frequency list
        freq[f].push_front(vector<int>({key, val, f}));

        // Update mp with new iterator
        mp[key] = freq[f].begin();
    }
    
    // Return value of key if exists, otherwise -1
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1; // Not found
        }

        auto vec = (*(mp[key]));
        int val = vec[1];

        // Update frequency since node is accessed
        makeMostFrequentlyUsed(key);

        return val;
    }
    
    // Insert or update a key-value pair
    void put(int key, int value) {
        if (cap == 0) {
            return; // No capacity to store anything
        }

        // Case 1: Key already exists -> update value & increase frequency
        if (mp.find(key) != mp.end()) {
            auto &vec = (*(mp[key]));
            vec[1] = value; // update value

            makeMostFrequentlyUsed(key);
        }
        // Case 2: New key and we still have space
        else if (size < cap) {
            size++;

            // New node with freq = 1
            freq[1].push_front(vector<int>({key, value, 1}));

            // Update mp
            mp[key] = freq[1].begin();
        }
        // Case 3: New key but cache is full -> Evict LFU
        else {
            // Get the DLL corresponding to the smallest frequency
            auto &kaun_sa_list = freq.begin()->second;

            // Node to delete = back of DLL (LRU among LFU)
            int key_to_delete = (kaun_sa_list.back())[0];

            // Remove node
            kaun_sa_list.pop_back();

            // If this freq list is now empty, erase it
            if (kaun_sa_list.empty()) {
                freq.erase(freq.begin()->first);
            }

            // Insert new node with freq = 1
            freq[1].push_front(vector<int>({key, value, 1}));

            // Update maps
            mp.erase(key_to_delete);
            mp[key] = freq[1].begin();
        }
    }
};

int main() {
    // Example usage:
    LFUCache lfu(2);
    lfu.put(1, 10);
    lfu.put(2, 20);
    cout << lfu.get(1) << endl; // returns 10
    lfu.put(3, 30);             // evicts key 2 (LFU)
    cout << lfu.get(2) << endl; // returns -1 (not found)
    cout << lfu.get(3) << endl; // returns 30
}