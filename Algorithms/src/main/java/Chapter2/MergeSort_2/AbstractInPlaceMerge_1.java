package Chapter2.MergeSort_2;

/**
 * This is a complicated algorithm son. So don't worry about the future, or you're not going to get a job.
 * Your job is to understand this algorithm. And now, after 90 minutes, you know one more thing. So you're one less
 * thing stupid.
 * 
 * So let's imagine we have two sorted arrays, say [2 4][1 3]. A good property of these arrays is that each time we choose
 * one element from any of them in increasing index order, then we're sure that the remaining elements in the array are
 * greater. If we also jump from one array to the other, we're sure that this property remains.
 * 
 * So now this is how I create a sorted array from the two, which is [_ _ _ _]. So let's say I keep an index i to array 1
 * and index j to array 2:
 * 1- I'd choose The smallest first element.
 * 2- If either index overflows, the rest of the elements comfortably come from the other array.
 * 3- Each time that I don't know which element to pick, I compare the value of i and j and choose the smaller one.
 * 
 * Now let's implement this:
 */
class Merger{
    public static Comparable[] merge(Comparable[] a, Comparable[] b) {
        Comparable[] merged = new Comparable[a.length];
        int i = 0;
        int j = 0;
        for (int k = 0; k < merged.length; k++) {
            if (i > a.length) merged[k] = a[i++];
            else if (j > b.length) merged[k] = a[j++];
            else if (a[i].compareTo(b[j]) < 0) merged[k] = a[i++];
            else merged[k] = a[j++];    // This last condition says if (a[i].compareTo(b[j])> 0) me
        }

        return merged;
        
    }
}

/**
 * So this is essentially merge sort. The only difference with merge sort is that the arrays are not given explicitly,
 * but rather through a low and high index. The other key thing here is that if we start copying moving the elements in place,
 * we'd lose the elements in the original array. Which is why, at every step of the merge, we actually need a copy of the array.
 * Now, we could create a small array everytime and them destroy it. However, this would be resource consuming. Hence, we 
 * create a large array and every time we need a copy, we copy the elements at hand. Genius!
 */
class MergeSort{
    static Comparable[] aux;
    public static void mergeSort(Comparable[] a) {
        aux = new Comparable[a.length];
        
    }

    /**
     * Node that giving the mid here is completely optional. We have a[lo ... mid] a[mid ... high] to merge
     */
    public static void merge(Comparable[] a, int lo, int mid, int hi) {
        int i = lo; 
        int j = mid + 1;

        for (int k = lo; k <= hi; k++) {
            aux[k] = a[k]; 
        }

        for (int k = lo; k <= hi; k++) {
            if (i > a.length) a[k] = aux[i++];
            else if (j > a.length) a[k] = aux[j++];
            else if (a[i].compareTo(a[j]) < 0) aux[k] = aux[i++];   // Here we could have said aux.compareTo(aux)
            else a[k] = aux[j++];    // This last condition says if (a[i].compareTo(b[j])> 0) me
        }
        
    }

    public static void sort(Comparable[] a, int lo, int hi) {
        if (lo == hi) return;

        int mid = lo + (hi - lo) / 2; // Note that we fall below the middle! Don't forget the shift by lo too!
        
        sort(a, lo, mid);
        sort(a, mid+1, hi);
        
        merge(a, lo, mid, hi);
        
    }

}