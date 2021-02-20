package Chapter2.ElementarySorts_1;

/**
 * The simplest sorting algorithm. We start looking for the smallest element, put it in the first
 * place, then next, and so forth. We also exch() in place, and then start from the second element of
 * the array. 
 * 
 * This algorithm uses ~N^2/2 compares and N exchanges to arrange the array. The algorithm is independent of the 
 * order of the elements in the array.
 * 
 * It is however interesting that the number of array access is linear with this method.
 * 
 * Note that we can salvage one index by writing the first index with i < a.length - 1, because the last index is never compared.
 */
public class SelectionSort_2 {
    public static void sort(Comparable[] a) {
        for (int i = 0; i < a.length; i++) {
            int min = i;
            for (int j = i; j < a.length; j++) {
                if (a[min].compareTo(a[j]) > 0) min = j;
            }

            exch(a, i, min);
        }
        
    }

    private static void exch(Comparable[] a, int i, int j) {
        // Maybe we should add if (i==j) return;
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}
