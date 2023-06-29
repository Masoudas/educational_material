/*
fmt::Display may be cleaner than fmt::Debug but this presents a problem for the std library. How should ambiguous types be displayed? For example, if the std library implemented a single style for all Vec<T> , what style should it be? Would it be either of these two?

    -   Vec<path> : /:/etc:/home/username:/bin (split on : )
    -   Vec<number> : 1,2,3 (split on , )

No, because there is no ideal style for all types and the std library doesn't presume to dictate
one. fmt::Display is not implemented for Vec<T> or for any other generic containers. fmt::Debug must then be used for these generic cases. This is not a problem though because for any new container type which is not generic, fmt::Display can be implemented.
*/

use std::fmt; // Import `fmt`

// A structure holding two numbers. `Debug` will be derived so the results can be contrasted with `Display`.
#[derive(Debug)]
struct MinMax(i64, i64);

// Implement `Display` for `MinMax`.
impl fmt::Display for MinMax {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        // Use `self.number` to refer to each positional data point.
        write!(f, "({}, {})", self.0, self.1)
    }
}

// Define a structure where the fields are nameable for comparison.
#[derive(Debug)]
struct Point2D {
    x: f64,
    y: f64,
}

// Similarly, implement `Display` for `Point2D`.
impl fmt::Display for Point2D {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        // Customize so only `x` and `y` are denoted.
        write!(f, "x: {}, y: {}", self.x, self.y)
    }
}

fn main() {
    let minmax = MinMax(0, 14);
    println!("Compare structures:");
    println!("Display: {}", minmax);
    println!("Debug: {:?}", minmax);

    let big_range = MinMax(-300, 300);
    let small_range = MinMax(-3, 3);
    println!(
        "The big range is {big} and the small is {small}",
        small = small_range,
        big = big_range
    );

    let point = Point2D { x: 3.3, y: 7.2 };
    println!("Compare points:");
    println!("Display: {}", point);
    println!("Debug: {:?}", point);
    // Error. Both `Debug` and `Display` were implemented, but `{:b}`
    // requires `fmt::Binary` to be implemented. This will not work.
    // println!("What does Point2D look like in binary: {:b}?", point);

    /* So, fmt::Display has been implemented but fmt::Binary has not, and therefore cannot be
    used. std::fmt has many such traits and each requires its own implementation. This is
    detailed further in std::fmt .*/
}
