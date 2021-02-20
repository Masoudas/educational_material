/**
* Question: Not that we should do it, and it's purpuse defeating, and plainly wrong, but how come we're able to write
* while(cin>>x)?
* 
* The answer is that >> is an operator and it returns an instance of istream. Now, istream has an implicit converter that
* is converted through which we can check state of istream.
* 
* Note: cin is kind of odd! First, cin finishes reading cmd when we press enter, but if no input has been put, it will not
* stop reading! This why if we enter a 1000 times without writing a char (not inclusing space) it does not enter.
* Second, when we press enter, it starts returning anything between two spaces (vertical, or space). This is what is
* checked by the while loop in fact. So if I write 'q q' and press enter, the loop is executed twice, printing 'qq'. 
* Then once cin buffer is empty, we stop inside cin, waiting for the buffer to be filled.
* 
* Now we understand why while (cin >> x && x.size()) does not work. When we press enter, x cannot be empty. Moreover, with
* each loop, the stream buffer is put inside x until it finishes, and when it finishes, cin stops for reading again from
* cmd and this whole cycle repeats again. Go figure!
* 
* Question is, how can we stop the loop without using Ctrl + C ? Well, we obviously can't use enter or space or anything
* like that, because the input stream is not interrupted with those babies. Essentially, I can't think of any way to 
* terminate, unless we ask the user to press some special char.  
* 
* At this point, I like to remind that the best way to read from the command line is to use the function getline with
* char \n, which is what we seek! Note that as opposed to cin, this one does not drop spaces!
*/

#include <iostream>
#include <string>

using namespace std;

//int main() {
//	string x{};
//	
//	// Does not stop reading from command line with spaces. Stops with enter, but drops spaces, enter!
//	while (std::cin >> x) {
//		std::cout << x ;
//	}
//
//}