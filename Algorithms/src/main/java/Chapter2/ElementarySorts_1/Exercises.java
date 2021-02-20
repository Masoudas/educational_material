package Chapter2.ElementarySorts_1;

class Two{
    /** 
     * Because at each iteration we do one exchange, most number of exchanges is N-1, which is the same
     * for a situation where first item is the maximum. 
     * 
     * I really really don't understand what he means by average everytime he says it. An item can be moved once,
     * or N-1 times, or zero times. That's what I would say.
     */
}

class Eight{
    /**
     * Again, I'm not sure about this. But if we have {1,2,3,1,2,3}, it's linear. However with {321321321}
     * it is less than quadratic but not linear. It can't possibly be quadratic, because we can't have more than
     * two comparisons per inner loop!
     * 
     * The solution manual however says (Quadratic. Insertion sort's running time is linear when the array is already sorted or all elements are equal.
     * With three possible values the running time quadratic.)
     */
}

class Thirteen{
    /**
     * A couple of solutions comes to mind, depending on how we view the problem.
     * First, we can define the comparator as shown below, which would act based on rank and suit and then
     * implement a shell sort.
     * 
     * Second option is that we actually know the location of each card in the deck (which is an information we
     * don't have normally with sort algorithms). So then let's just put every card in its location every time we
     * see two cards :D.
     */
    enum Suit{
        DIAMOND, SPADE, HEARTS, CLUB;
    }

    class Card implements Comparable<Card>{
        int rank;
        Suit suit;

        @Override
        public int compareTo(Card o) {
            if (o.suit == suit)
                return rank - o.rank;
            else if (suit == Suit.SPADE)
                return -1;
            else 
                return 1;
        }
    }
}