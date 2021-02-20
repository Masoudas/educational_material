package MyRandomProblems.Recursion;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;
import java.util.stream.Stream;

public class CalculateALineOfOperationProblem {
    /**
     * So suppose we only have numbers from one to nine, and two operations * and +.
     * Write a program that calculates an expression such as 1 + 2 * 3 or 2 * 1 + 3?
     * 
     * Answer: It's best to assume a11 * a12 ... + a21 * a22 * ... + ... 
     * The simplest method is just to break down the expression on plus signs and sum the
     * results. It is very ugly though.
     */
    public static int methodI(String expr){
        if (expr.length() == 0) return 0;

        String[] ops = expr.split("\\+");

        int result = 0;
        for (String str : ops) {
            int i = 0;
            int temp_res = Character.getNumericValue(str.charAt(i++));
            while (i < str.length()) {
                temp_res *= Character.getNumericValue(str.charAt(++i));
                i++;
            }
            result += temp_res;
        }

        return result;
    }

    /**
     * In this attempt, we try to integrate the splitting into the expression. The only problem we have here is that
     * the last expression comes after the plus sign, so we need to integrate it by adding the last temp
     * result just before shooting everything out.
     */
    public static int methodII(String expr) {
        if (expr.length() == 0) return 0;


        int result = 0;
        int temp_res = 1;
        for(int i = 0; i < expr.length(); i++) {
            char c = expr.charAt(i);
            
            if (c == '+'){
                result += temp_res;
                temp_res = 1;
            }
            else {
                if (c != '*'){
                    temp_res *= Character.getNumericValue(c);
                }
            }
            
        }

        return result + temp_res;

    }

    public static void main(String[] args) {
        System.out.println(methodI("1*6*7*4+1*1+1*1"));
        System.out.println(methodI("1*6*7*4+1"));
        System.out.println(methodI("1+1"));
        System.out.println(methodI("1+1*1"));

        System.out.println(methodII("1*6*7*4+1*1+1*1"));
        System.out.println(methodII("1*6*7*4+1"));
        System.out.println(methodII("1+1"));
        System.out.println(methodII("1+1*1"));
    }
}
