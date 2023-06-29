/*
std::fmt contains many traits which govern the display of text. The base form of two
important ones are listed below:
    -   fmt::Debug : Uses the {:?} marker. Format text for debugging purposes.
    -   fmt::Display : Uses the {} marker. Format text in a more elegant, user friendly fashion.

Here, we used fmt::Display because the std library provides implementations for these
types. To print text for custom types, more steps are required. Implementing the fmt::Display trait automatically implements the ToString trait which allows us to convert the type to String
*/

fn main() {
    println!("{1} is {0} and {0} is {1}", "2", "two");
    println!("{0:x} is hex of {0} and {0:b} is the binary of {0}", 10);
    println!(
        "{object} is not {subject}",
        object = "object",
        subject = "subject"
    );

    // You can right-justify text with a specified width. This will
    // output "1". (Four white spaces and a "1", for a total width of 5.)
    println!("{number:>5}", number = 1);

    // You can use named arguments in the format specifier by appending a `$`.
    println!("{number:0>width$}", number = 1, width = 5);
}
