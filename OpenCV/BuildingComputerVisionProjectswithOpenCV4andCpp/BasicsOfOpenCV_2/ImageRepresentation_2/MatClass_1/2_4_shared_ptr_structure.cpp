/**
 * Note that essentially, Mat has a shared pointer like structure, meaning once the last user of data matrix is 
 * garbage collected, then the entire underlying matrix goes out of structure in an automatic manner, just like a
 * shared_ptr would do so.
 * 
 */