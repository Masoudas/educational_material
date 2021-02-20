package Chapter2.ElementarySorts_1;

/**
 * As is the case with java, we need only to sort an array of Comparable
 * objects. An object that implements the Comparable API is said to have natural order.
 * Hence, the following API is proposed, where two elements are
 * compared and a method less returns a bool saying whether one object is less
 * than the other.
 * 
 * We should note that putting the assertion method is not sufficient for checking 
 * that the array is sorted! For example, a sort algorithm might just fill the array with
 * equal elements!
 * 
 * Some sort algorithms need no extra memory to sort an array, whereas other might use
 * another array of the same size to do the sorting. We should be cautious about this fact.
 * 
 * The compare method must have three properties:
 * 1- Reflexive: For all v, v=v
 * 2- Antisymmetric: If w < x and x < w, then x = w
 * 3- Transitive: if x<=w and w<=z then x<=z;
 */
class Exaّmple {
    public static void sort(Comparable[] a) {
        /* See Algorithms 2.1, 2.2, 2.3, 2.4, 2.5, or 2.7. */ }

    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    private static void exch(Comparable[] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    private static void show(Comparable[] a) { // Print the array, on a single line.
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
            System.out.println();
    }

    public static boolean isSorted(Comparable[] a) { // Test whether the array entries are in order.
        for (int i = 1; i < a.length; i++)
            if (less(a[i], a[i - 1]))
                return false;
        return true;
    }

    public static void main(String[] args) { // Read strings from standard input, sort them, and print.
        String[] a = null;
        sort(a);
        assert isSorted(a);
        show(a);
    }
}