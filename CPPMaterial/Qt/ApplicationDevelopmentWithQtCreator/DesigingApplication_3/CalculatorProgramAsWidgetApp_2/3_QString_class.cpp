/**
 * Found inside the QString header, which is part of the core package.
 * 
 * QString class is the string class of Qt. What I found particularly interesting were some of the static 
 * methods of it, that can be used to get strings form numbers for example, which are quite handy when
 * working with GUIs:
 * 
 *  QString::number()   :   Create an string from the given number.
 *  
 * There are also public method to convert from strig to number:
 * 
 *  QString.toFloat(bool* ok=nullptr)   :   Converts to float, and sets the flag.
 * 
 * 
 * Note that there's also a QStringView.
 */