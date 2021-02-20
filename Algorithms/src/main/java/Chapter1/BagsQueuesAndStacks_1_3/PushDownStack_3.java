package Chapter1.BagsQueuesAndStacks_1_3;

import java.util.Stack;

/**
 * A push down stack (or simply a stack) is a data structure where the last
 * element set in is returned first. The tabs on an internet browser is an
 * stack. Another example is the email stack.
 * 
 * By stack underflow, we mean a situation where stack is empty, but an item is called for by the client.
 * Stack overflow is when the stack is full, and can't allocate a new space.
 * 
 * As another example, consider the expression ( 1 + ( ( 2 + 3 ) * ( 4 * 5 ) )
 * ). How does Java calculate this expression? Suppose all values are between 0
 * to 9 and we don't have compound expressions like 1 + 2 * 3.
 * 
 * The answer is, we define two stacks, one for operands and one for operator.
 * We move through the expression. If we encounter left paranthesis, we just
 * ignore it. For right ones, we pop the last value put and we calculate the
 * result.
 * 
 * Now, because we assumed we always have outer paranthesis, this code is correct. If we didn't,
 * which would imply we have expressions like 1+(2*3), then we'd have to empty stack one last time 
 * as well. 
 * 
 * Note: We assume that the expression starts and ends with paranthesis.
 */
class ExpressionCalculation{
    public static int calculateExpression(String str){
        Stack<String> ops = new Stack<>();
        Stack<Integer> opr = new Stack<>();

        for (int i = 0; i < str.length(); i++){
            char c = str.charAt(i);

            if (c == '+'){
                ops.push("+");
            } else if (c == '*')
            {
                ops.push("*");
            } else if (c == ')'){
                String op = ops.pop();
                if (op == "+"){
                    opr.push(opr.pop() + opr.pop());
                } else if (op == "*")
                {
                    opr.push(opr.pop() * opr.pop());
                }    
            } else if (c == '('){

            } else {
                opr.push(Character.getNumericValue(c));
            }
        }    
        
        
        return opr.pop();
    }

    public static void main(String[] args) {
        System.out.println(calculateExpression("(1+1)"));
        System.out.println(calculateExpression("(1+(1+1))"));
        System.out.println(calculateExpression("(2*(1+1))"));
        System.out.println(calculateExpression("(2*(1+1))"));
        System.out.println(calculateExpression("((1+1)*((1+1)*(1+1)))"));
    }

}

/**
 * Here's another riddle. How does one calculate a compound expression, like 1 + 2 * 3.
 */