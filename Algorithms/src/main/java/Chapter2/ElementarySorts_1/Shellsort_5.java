package Chapter2.ElementarySorts_1;

/**
 * The idea of the shell sort is to first partially order sub-arrays of the original array, and then
 * finally order the entire array. The reason why this is useful is because for example with [4 2 3 1], if we 
 * were to somehow partially order the inversion 1 and 4, then insertion sort would not take long.
 * 
 * The idea is that we choose a value h. Then starting from i = h, we comapre i with i - h, i - 2h ,...
 * and exchange it if necessary. This way we would sort a shell of the set (i.e, h, 2h, 3h ...)
 * Then we increase i by one, until we reach i < N. Now we decrease h,
 * until at the last step, we implement with h = 1, which is the actual insertion sort.
 * (Me: I think the point we're taking from this exercise is the idea of working with a sub-vector
 * of a vector in place, and not making a copy).
 * 
 * How do we choose h? What is suggested is while (h < N / 3) h = 3 * h + 1. I don't know why this way.
 * 
 * 
 * It has been proven that this algorithm has a good performance, and in the absence of other sorting algorithms
 * (like for example in embedded programming environments) it should be used as a good alternative.
 * 
 * 
 */
class ShellSort{
    public static void sort(Comparable[] a) {
        int N = a.length;
        int h = 1;
        while (h < N / 3) h = 3 * h + 1;

        while (h >= 1) {
            for (int i = h; i < a.length; i++) {
                for (int j = i; j > 0 && a[j].compareTo(a[j-h]) < 0; j-=h) {
                    exch(a, j-h, j);
                    
                }
                
            }
            
        }
    }

    private static void exch(Comparable[] a, int i, int j) {
        // Maybe we should add if (i==j) return;
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

}