/**
* Bloom filters help us determine whether a given data already exists in our data set with two constrains:
* 1- Search is indeterministic: It may happen that a data does not exist, but the filter falsely says it does. If,
* however, it says that the data does not exist, it definitely does not exist.
* 
* 2- Actual data is not kept: As opposed to the previous data structures, a bloom filter cannot keep the actual
* data.
* 
* We may wonder why such a data structure is helpful. Imagine for example a database of emails. When we want to
* check for a new email address, it's absolutely crucial that the email address does not already exist. However,
* if we say an email address does not exist, we want to be absolutely sure of it.
* 
* Another example is websites like google, that want to show ads to users. We want to be absolutely sure that a
* repetitive add is not shown to the user. In this case, a bloom filter is once again helpful.
* 
*/