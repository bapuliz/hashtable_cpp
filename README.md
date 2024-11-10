# Hash Engine

**Hash Engine** is a highly optimized, from-scratch C++ implementation of a hash table data structure. Designed for efficient, reliable key-value storage, Hash Engine introduces powerful hashing capabilities, dynamic resizing, and customizable load controls.

## Key Features

- **Custom Hashing Functions**  
  Implements specialized hash functions for `std::string` and `int` types to minimize collisions and ensure balanced data distribution.

- **Automatic Resizing**  
  Dynamically adjusts bucket counts based on load factor, resizing to the nearest power of 2 to maintain optimal performance without wasting memory.

- **Modular, Template-Based Design**  
  Built with templates, Hash Engine is extensible to handle various key types and adaptable to different collision resolution strategies.

- **Load Balancing and Collision Handling**  
  Uses linked list chaining within buckets to ensure efficient insertion and deletion operations, even under high load.

- **Memory-Efficient Load Factor Controls**  
  Configurable bucket count and load factor settings help balance memory usage and performance, allowing fine-tuned optimization for different data sets.

---

Hash Engine is an ideal solution for applications needing high-performance hash tables with customizability and reliable memory management.
