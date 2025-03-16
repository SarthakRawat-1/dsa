// Hashing is a technique used in data structures to map data (keys) to specific locations (buckets) in memory, enabling fast data retrieval.
 
// A hash function takes an input (key) and produces an integer output, called a hash code or hash value.
// This hash value determines the index (or bucket) where the key-value pair will be stored in a hash table.

// A hash code is the intermediate numeric output produced by a hash function before compression. It represents the input data in a numeric form but is not restricted to the size of the hash table.
// Example :- For a string "apple":
// Hash Code: h("apple") = 9348172 (arbitrary example)

// Since hash codes can be very large, a compression function reduces them to fit into the hash table size (usually within 0 to TABLE_SIZE − 1).

// This hash value determines the index (or bucket) where the key-value pair will be stored in a hash table.
// Each entry in the table is called a bucket.

// Collisions occur when two different keys produce the same hash value.
// There are mainly two methods to handle collision :- 
// 1. Separate Chaining     
// 2. Open Addressing (Linear Probing, Quadratic Probing, Double Hashing)

// The load factor measures the fullness of the hash table.
// Load Factor = Total number of Elements / Size of Hash Table
// A higher load factor increases collisions, leading to slower performance.

// If the load factor exceeds a certain threshold, the table size is increased, and all elements are rehashed into the new table.

// Eg :- For eg we have values :- {50, 30, 20, 40, 25}
// Hash Function :- Hash(value) = value % 7
// Index | Value
// --------------
//   0   |  -  
//   1   |  -  
//   2   |  25  
//   3   |  -  
//   4   |  20  
//   5   |  50  
//   6   |  30  
