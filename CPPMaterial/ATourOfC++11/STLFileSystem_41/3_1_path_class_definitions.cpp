/**
* The path name has the following syntax:
* 
* 1- root-name(optional): identifies the root on a filesystem with multiple roots (such as "C:" or "//myserver"). 
*	In case of ambiguity, the longest sequence of characters that forms a valid root-name is treated as the 
*	root-name. The standard library may define additional root-names besides the ones understood by the OS API.
*	(Me: In linux, it's empty, or perhaps the host name!)
* 
* 2- root-directory(optional): a directory separator that, if present, marks this path as absolute. 
*	If it is missing (and the first element other than the root name is a file name), then the path is relative 
*	and requires another path as the starting location to resolve to a file name. (In linux, it's /).
*
* 3- Zero or more of the following:
*	-	Filename: sequence of characters that aren't directory separators or preferred directory separators
*		(additional limitations may be imposed by the OS or file system). This name may identify a file, a hard 
		link, a symbolic link, or a directory). Two special cases are:
*		- dot: the file name consisting of a single dot character . is a directory name that refers to the current
*		  directory
*		- dot-dot: the file name consisting of two dot characters .. is a directory name that refers to the parent
*		  directory.
*	-	directory-separators: the forward slash character / or the alternative character provided as
*		path::preferred_separator. If this character is repeated, it is treated as a single directory separator:
*		/usr///////lib is the same as /usr/lib
* 
* A path normalization algorithm is as follows:
* -	If the path is empty, stop (normal form of an empty path is an empty path)
* - Replace each directory-separator (which may consist of multiple slashes) with a single 
*	path::preferred_separator.
* -	Replace each slash character in the root-name with path::preferred_separator.
* - Remove each dot and any immediately following directory-separator.
* - Remove each non-dot-dot filename immediately followed by a directory-separator and a dot-dot, along with 
*	any immediately following directory-separator.
* - If there is root-directory, remove all dot-dots and any directory-separators immediately following them.
* - If the last filename is dot-dot, remove any trailing directory-separator.
* - If the path is empty, add a dot (normal form of ./ is .)
*/

