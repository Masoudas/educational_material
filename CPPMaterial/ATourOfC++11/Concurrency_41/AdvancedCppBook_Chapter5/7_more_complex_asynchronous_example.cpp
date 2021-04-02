/**
* Let's use some pseudocode to show an example where computations are done by another computational unit. For example, 
* let's say we develop an application that performs calculations with currency exchange. The user inputs an amount in one 
* currency, chooses another currency to exchange, and the application shows them the amount in that currency. The 
* application, in the background, sends a request to a remote server that holds all the currency exchange rates. 
* The remote server calculates the amount of the given currency and sends the result back. Your application shows a 
* progress bar at that time and allows the user to perform other operations. When it receives the results, it displays 
* them on the window.
* 
* When implementing the software, we check for if the server if it has a new message. If it does, then we display it.
* Now imagine the classes Currency, Result, and the methods:
*	-	runMessageLoop: This is the function that checks if the server has sent us a message.
*	-	display: For showing the result.
*	-	processResult: The function that gets the result and calls the display function.
*	-	displayProgress: The function that displays the progress of processing this demand.
*	-	getUserInput: The function that asks for the user input.
*	-	sendRequest: The function that sends the request.
* 
* Below is the pseudocode implementation of each method:

void runMessageLoop(){
	while(true){
		if (message){	// If a message is received, then begin the display result loop.
			thread procResult{processResult, result};
		}
	}
}

void processResult(Result){
	display();
}

void display(){}

void displayProgress(){}

void sendRequest(Currency from, Currency to, double amount){}

void getUserInput(){
	Currency from, to;
	double amount;

	thread progress(displayProgress);
	progress.detach();

	thread request(sendRequest, from, to, amount);	// Yes, yes! You can wrap these in reference wrapper.
	request.detach();
}

int main(){
	thread messageLoop(runMessageLoop);
	messageLoop.detach();

	thread userInput(getUserInput);
	userInput.detach();
}

* 
*/