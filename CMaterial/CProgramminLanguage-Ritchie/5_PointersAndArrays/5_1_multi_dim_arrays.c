/**
 * In the following example, we use a multi-dim array to convert a given day to a particular day of month,
 * or day of year. It's a very interesting implementation, and essentially adds and subtracts days of the
 * month based on the year being leap or not. I actually didn't know that the Gregorian calendar is so
 * bizzare!
 * 
 * In C, a two-dimensional array is really a one-dimensional array, each of whose elements is an array. Hence 
 * subscripts are written as arr[i][j] rather than arr[i,j].
 * 
 * Other than this notational distinction, a two-dimensional array can be treated in much the same way as in 
 * other languages. Elements are stored by rows, so the rightmost subscript, or column, varies fastest as 
 * elements are accessed in storage order.
 */

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	for (i = 1; i < month; i++)
		day += daytab[leap][i];

	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	
	*pmonth = i;
	*pday = yearday;
}