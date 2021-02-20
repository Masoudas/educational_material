/**
* A Semiregular can be both moved and copied. That describes most types, but there are examples of types that 
* cannot be copied, such as unique_ptr. However, I don’t know of useful types that can be copied but not moved. 
* Types that can neither be moved nor copied, such as type_info, are very rare and tend to reflect system 
* properties.
*/