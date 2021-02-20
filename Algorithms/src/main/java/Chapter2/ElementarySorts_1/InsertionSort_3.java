package Chapter2.ElementarySorts_1;

/**
 * Insertion sort is very simple. We can think of it as trying to order a deck of card. Each time a card comes out,
 * we look at whether it's smaller or bigger than the other cards, and we shift the cards right to place it in order.
 * 
 * For implementation, as we iterate through the elements, we compare each one with the one before it, and exchange 
 * the two (instead of moving all the elements forward).
 * 
 * The worst case of this algorithm needs ~N^2/2 comparisons and ~N^2/2 exchanges. The best case it needs N-1 comparisons 
 * and zero exchanges. On average we expect to move every element half way the vector (Why? Because 
 * for every case that we have to move them N-1 positions, there's a case we don't move at all), 
 * hence the average case is N^2/4 move and N^2/4 exchange.
 * 
 * One interesting difference between insertion and selection sort is that whereas selection sort only
 * touches element on the right of current element, insertion only touches element on the left.
 * 
 */
public class InsertionSort_3 {
    public static void sort(Comparable[] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = i; j > 0 && a[j].compareTo(a[j-1]) < 0; j--) { // Note the fact that here, we say j > 0.
                exch(a, j-1, j);
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
