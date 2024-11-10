# Hash Engine

**Hash Engine** is a highly optimized, from-scratch C++ implementation of a hash table data structure.

## Key Features

- **Automatic Resizing**  
  Dynamically adjusts bucket counts based on load factor, resizing to the nearest power of 2, e, 10 to maintain optimal performance without wasting memory.

- **Modular, Template-Based Design**  
  Built with templates, Hash Engine is extensible to handle various key types.

- **Load Balancing and Collision Handling**  
  Uses linked list chaining within buckets to ensure efficient insertion and deletion operations.

- **Memory-Efficient Load Factor Controls**  
  Configurable bucket count and load factor settings help balance memory usage and performance, allowing fine-tuned optimization for different data sets.

---
