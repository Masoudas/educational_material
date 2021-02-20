package MyRandomProblems.TheShiftProblem;

/*
 * How can we check that the result of multiplication, summation or other has not overflown in java?
 * And How do we avoid it in general?
 * 
 * As we know, many languages don't indicate when overflow occurs. Hence for example, 16 * 16 results in an 
 * overflow with byte type, as well as -17 * 16 for example. 
 * 
 * 
 * To check for overflow with multiplication would be this. Find the greatest byte that is one in both 
 * operands and see if the sum of them exceed the range.
 * 
 * 
 */
class MultiplicationMySolution{

    public static void main(String[] args) {
        int x1 = 10;
        int x2 = 20;
        System.out.println(16 >>> 3);

        System.out.println(getGreatesPowerUsingJava(1));

        int p1 = getGreatestPowerOfTwo(x1);
        int p2 = getGreatestPowerOfTwo(x2);

        if ((p1 < 0 && p2 < 0) || (p1 > 0 && p2 > 0)) {
            if ( p1 + p2 >= 32 ) System.out.println("overflow");
        } else {
            if ( p1 + p2 > 32 ) System.out.println("overflow");

        }

    }

    /**
     * We avoid the sign byte, and just check if the abs value.
     */
    public static int getGreatestPowerOfTwo(int x){
        if (x == Integer.MIN_VALUE) return 32;
        
        if (x < 0) x = -x;

        int p = 0;
        for (int i = 1; i < 30; i++) {
            x >>= 1;    
            if ((x & 0x0001) == 0x0001) p = i;
        }

        return p;
    }

    public static int getGreatesPowerUsingJava(int x) {
        if (x == Integer.MIN_VALUE) return 32;
        if (x < 0) x = -x;

        return 32 - Integer.numberOfLeadingZeros(x) - 1;
        
    }
}