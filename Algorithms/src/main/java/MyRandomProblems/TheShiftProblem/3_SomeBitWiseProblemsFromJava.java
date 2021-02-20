package MyRandomProblems.TheShiftProblem;

/**
 * These solutions made me weep, because they're so elegant.
 */
class SomeBitWiseProblemsFromJava {
    /** Suppose we have 8 bit unsigned and signed. Then suppose assignment would directly be interpreted.
     * Then, what is uchar 127 in signed? 
     * We know that in two's complement is just an interpretation. Hence, 127 + 129 = 256. Hence, 129
     * is interpreted as -1. So, if we say we have -1, then it is equivalent to 129. So, -1 is actually
     * 129. This is just an interpretation! Yes. Sometimes one forgets these things!
     */
    public void unsignedToSigned(){

    }

     /**
	* What is the two's complement representation of -1? We know that -1 + 1 = 0 -> 1 + x = 256. Hence, 255. 
	* What about -160? -160 + 160 = 0 -> 160 + x = 256 -> x = 256 - 160.
	*/
    public void twosComplementFromNegativeValue(){
    }

    /**
     * Problem: For an int, find the number of leading zeros (zeros from right)?
     * Implementation is in the Integer.numberOfLeadingZeros() method of Java.
     * 
     * Solution: This is equivalent to finding the location of first one. The exceptional cases
     * are non-positive numbers, where the number of leading is either zero or 32. Now, get ready
     * to weep.
     * 
     * We suppose it has 31 leading zeros. If a number is greater than 1<<16 (one at the 17th place),
     * then it has less than 16 zeros. Now, shift it 16 places to right. 
     * Then again, if it's greater than 1<<8 (one at 9th place), it has less than 8 ones. So subtract 8 zeros, and continue
     * forward, like this is the quick-sort algorithm.
     * 
     * The point is the two inversions we have here, one is looking for first one, second is reasoning in negations,
     * saying if it's greater than this number, then it has less than these number of zeros.
     */
    public int numberOfLeadingZeros(int i){
        if (i<= 0){
            return i == 0 ? 32 : 0;
        }

        int n = 31;  // n is set to 31, because we now it is not negative.

        if (i <= 1<<16){n-=16; i>>>=16;}
        if (i <= 1<<8){n-=8; i>>>=8;}
        if (i <= 1<<4){n-=4; i>>>=4;}
        if (i <= 1<<2){n-=2; i>>>=2;}
        if (i <= 1<<1){n-=1;}   // Note that we don't check for 0, because we already took care of it!

        return n;
    }

    /**
     * Find the trailing number of zeros in an int? i.e, lsb bits that are zero.
     * See Integer class implementation.
     * 
     * The exceptional case is zero, which has 32.
     * 
     * So, we want to again look for a logarithmic solution. Hence, we first check 16 bits, then 8 bits so forth.
     * Let's say I check 0x00FF. This would imply that either all 16 LSB are zero or not. Hence, the algorithm branches
     * in two possibilies here, which is not Ok. So what I do is that if there's one detected, I shift all the
     * bits, and if not I keep it, so that we write one if loop for both cases.
     * 
     * The implementation of Integer class is slightly different. It shifts everything up and starts checking the
     * LSB. If they are zero, then we shift the number to left and check again. Otherwise, if they are non-zero,
     * we keep the shifted number and start from there, like below in method II
     *
     * 
     */
    public int numberOfTrailingZeroI(int i) {
        if (i == 0) return 32;

        int n = 0;

        if ((i & 0x00ff) == 0 ){n+=16; i >>= 16;}
        if ((i & 0x000f) == 0 ){n+=8; i >>= 8;}
        if ((i & 0x0007) == 0 ){n+=4; i >>= 4;}
        if ((i & 0x0003) == 0 ){n+=2; i >>= 2;}
        if ((i & 0x0001) == 0 ){n+=1; i >>= 1;}
        if ((i & 0x0001) == 0 ){n+=1;}

        return n;
    }

    public int numberOfTrailingZeroII(int i) {
        if (i == 0) return 32;
        
        int n = 31;
        int y;
        y = i << 16; if (y != 0 ){n-=16; i = y;}
        y = i << 8; if (y != 0 ){n-=8; i = y;}
        y = i << 4; if (y != 0 ){n-=4; i = y;}
        y = i << 2; if (y != 0 ){n-=2; i = y;}
        y = i << 1; if (y != 0 ){n-=1; i = y;}
        return n;
    }

    /**
     * Rotate a number n to right by the given int i?
     * 
     * This is an interesting problem. So we might say n << i | n >>> (32 - i).
     */
    public static void rotateLeft(int i, int distance) {
        System.out.println(Integer.rotateLeft(i, distance));
        System.out.println(i << distance | i >>> (32 - distance));
    }

    /**
     * Return zero for zero, -1 for negative and 1 for positive numbers. Aren't simple 
     * numerical comparisons better than this?
     */
    public static int signum(int i) {
        return i >> 31 | (~i) >> 31;
        
    }
}