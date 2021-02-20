/**
 * Accumulator is a data type that holds the running average of a set of data.
 */
package Chapter1.DataAbstractions_1_2;

import java.util.concurrent.atomic.LongAccumulator;
import java.util.function.LongBinaryOperator;
class AccumulatorExample{
    public static void main() {

        LongAccumulator acc  = new LongAccumulator(new Imp(),0l);
        acc.accumulate(10);
        
    }
 }

 class Imp implements LongBinaryOperator{

     @Override
     public long applyAsLong(long left, long right) {
         return left + right;
     }
     
 }