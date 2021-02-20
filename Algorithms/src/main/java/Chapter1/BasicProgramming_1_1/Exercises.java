package Fundamentals.BasicProgramming_1_1;

class One {
    public static void main(String[] args) {
        // && has the highest priority.
        System.out.println(true && false || true);
    }
}

class Eight {
    public static void main(String[] args) {
        System.out.println((char) ('c' + 8));
    }
}

class Nine {
    // This one is interesting. Note that as we know, the increment condition
    // of a for loop happens after the loop is executed for the first time.
    public static void main(String[] args) {
        int N = 10;
        String s = "";
        for (int n = N; n > 0; n = n / 2) {
            s = n % 2 + s;
        }

        System.out.println(s);

        // The same task can be achieved using int parser.
        System.out.println(Integer.toBinaryString(10));
    }
}

class Thirteen {
    public static void main(String[] args) {
        int[][] matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        // int[][] matrix = { { 1, 2 }, { 3, 4 }};
        // int[][] matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13,
        // 14, 15, 16 } };
        // int[][] matrix = new int[5][5];

        long start1 = System.nanoTime();
        doubleLoopVersion(matrix);
        System.out.println("Double loop takes: " + String.valueOf(System.nanoTime() - start1));

        long start2 = System.nanoTime();
        singleLoopVersion(matrix);
        System.out.println("Single loop takes: " + String.valueOf(System.nanoTime() - start2));

        _print(matrix);

    }

    public static void doubleLoopVersion(int[][] matrix) {
        for (int row = 0; row < matrix.length; row++) {
            for (int column = row; column < matrix[0].length; column++) {
                int temp = matrix[row][column];
                matrix[row][column] = matrix[column][row];
                matrix[column][row] = temp;
            }

        }

    }

    private static void _print(int[][] matrix) {
        for (int row = 0; row < matrix.length; row++) {
            for (int column = 0; column < matrix[0].length; column++) {
                System.out.println(
                        String.format("row %03d, column %03d, values %03d  ", row, column, matrix[row][column]));
            }

        }
    }

    public static void singleLoopVersion(int[][] matrix) {
        for (int index = 0; index < matrix.length * matrix.length;) {
            int row = index / matrix.length;
            int column = index % matrix.length;

            int temp = matrix[row][column];
            matrix[row][column] = matrix[column][row];
            matrix[column][row] = temp;

            index++;
            if (index % matrix.length == 0) {
                index += index / matrix.length;
            }

        }
    }
}

/**
 * Exercises
 */
class Fourteen {
    public static void main(String[] args) {
        System.out.println(withoutMath(2) == withMath(2));
        System.out.println(withoutMath(6) == withMath(6));
        System.out.println(withoutMath(4) == withMath(4));
        System.out.println(withoutMath(5) == withMath(5));


    }

    public static int withoutMath(int value) {
        if (value <= 0) {
            return -1;
        }

        if (value < 2) {
            return 0;
        }

        int result = 1;
        int power = 0;
        for (; result < value;) {
            power++;
            result = result << 1;
        }

        if (result > value) {
            return power - 1;
        }
        return power;
    }

    public static int withMath(int value) {
        if (value <= 0) {
            return -1;
        }

        return (int) (Math.log(value) / Math.log(2));
    }

}