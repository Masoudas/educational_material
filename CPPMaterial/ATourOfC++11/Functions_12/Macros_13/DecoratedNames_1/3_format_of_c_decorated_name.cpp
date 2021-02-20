/*
* The form of decoration for a C function depends on the calling convention used in its declaration, 
* as shown in the following table. This is also the decoration format that is used when C++ code is 
* declared to have extern "C" linkage.
* 
* Calling convention		Decoration
* __cdecl					Leading underscore (_)
* __stdcall					Leading underscore (_) and a trailing at sign (@) followed by 
							the number of bytes in the parameter list in decimal
* __fastcall				Leading and trailing at signs (@) followed by a 
							decimal number representing the number of bytes in the parameter list
* __vectorcall				Two trailing at signs (@@) followed by a decimal number of bytes in the parameter list
* 
*/

