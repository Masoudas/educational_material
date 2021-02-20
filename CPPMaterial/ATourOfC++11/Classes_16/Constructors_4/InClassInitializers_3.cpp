/**
 * We can initialize each class member directly when declared. That way, each
 * constructor would be responsible for initializing a certain potion of the class.
 * 
 */
class Date {
    int d{ 0 };
    int m{ 1 };
    int y{ 2 };
public:
    Date(int, int, int);//day,  month,  year
    Date(int, int);//day,  month,  today’s year
    Date(int);     //day,  today’s month and year
    Date();        //default Date: today
    Date(const char*);  //date in string representation//...
};