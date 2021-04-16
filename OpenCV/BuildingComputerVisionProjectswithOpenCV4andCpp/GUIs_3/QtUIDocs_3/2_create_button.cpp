/**
 * Me: One guy had suggested something very interesting over the net. We could add a rectangular box inside the
 * actual image, then define an event for when a user clicks on that area to show an action. This was a very
 * creative idea by that guy!
 * 
 * Not very surprising is the fact that we can create buttons with Qt. Before we move on further, however, note
 * that we have the following function pointer type definition:
 *          typedef void(*cv::MouseCallback) (int event, int x, int y, int flags, void *userdata)
 * 
 *      -   int cv::createButton(
 *              const String& bar_name, ButtonCallback on_change, void* userdata = 0,
 *	            int type = QT_PUSH_BUTTON, bool initial_button_state = false) 	
 *          Attaches a button to the control panel.
 *          The function createButton attaches a button to the control panel. Each button is added to a 
 *          buttonbar to the right of the last button. A new buttonbar is created if nothing was attached to the 
 *          control panel before, or if the last element attached to the control panel was a trackbar or if the 
 *          QT_NEW_BUTTONBAR flag is added to the type.
 * 
 * Note: It's funny. It appears that the buttons one creates would appear on all windows! Hence, one should be
 * cautious about addition of buttons to all windows!
 * 
 * As shown above, we can choose the type of the button as the following enumeration:
 *      -   cv::QtButtonTypes:
 *          -   QT_PUSH_BUTTON 	    :   Push button.
 *          -   QT_CHECKBOX         :   Checkbox button.
 *          -   QT_RADIOBOX         :   Radiobox button.
 *          *-* QT_NEW_BUTTONBAR    :   Button should create a new buttonbar. 
 * 
 * The following are examples:
 * createButton(NULL,callbackButton);//create a push button "button 0", that will call callbackButton.
 * createButton("button2",callbackButton,NULL,QT_CHECKBOX,0);
 * createButton("button3",callbackButton,&value);
 * createButton("button5",callbackButton1,NULL,QT_RADIOBOX);
 * createButton("button6",callbackButton2,NULL,QT_PUSH_BUTTON,1);
 * createButton("button6",callbackButton2,NULL,QT_PUSH_BUTTON|QT_NEW_BUTTONBAR);
 *      // create a push button in a new row
 */