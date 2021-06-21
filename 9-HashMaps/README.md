# HASH MAPS

## REQUIRED FUNCTIONS

- insert(K key, V value)
- getValue(K key)
- delete(K key)

## HASH MAPS DETAILS

- Hash Functions = Hash Code + Compression Function
- Two same key values can collide. We handle this using a concept called 'Collision Handling'

## COLLISION HANDLING

- Closed Hashing / Separate Chaining - Each array element stores a pointer to the head of a linked list which stores all elements with the same key value
- Open Addressing - Finding alternate index for same key values

  **h(i) = hf(a) + f(i)**

  - Linear Probing = f(i) = i
  - Quadratic Probing = f(i) = i^2
  - Double Hashing = f(i) = i\*h'(a)
