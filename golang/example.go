/*
Go functions may be closures. A closure is a function value that references variables from outside its body. The function may access and assign to the referenced variables; in this sense the function is "bound" to the variables.

For example, the adder function returns a closure. Each closure is bound to its own sum variable.

ME: Something interesting about the behavior of this function. As we can see, we call the fibonacci function once. Hence, it defines both a and b. Now, because a and b are in memory, we don't have to define them outside the function as globals. We just keep them in the function, and they shall remain in the stack.
*/
package main

import "fmt"

const Pi = 3.14

func main() {
	const World = "世界"
	fmt.Println("Hello", World)
	fmt.Println("Happy", Pi, "Day")

	const Truth = true
	fmt.Println("Go rules?", Truth)
}
