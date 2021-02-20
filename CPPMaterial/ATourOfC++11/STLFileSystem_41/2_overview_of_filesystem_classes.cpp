/**
* File systems are taken from boost library. Some of its components are optional. This means not all functionality 
* of std::filesytem is available on each implementation of the filesystem library. For example, FAT-32 does not 
* support symbolic links.
* 
* The library is based on three concepts: file, filename and path.
* -	file: A file is an object that holds data such that you can write to it or read from it. A file has a name 
*	and a file type. A file type can be a directory, hard link, symbolic link or a regular file.
*		-- A directory is a container for holding other files. The current directory is represented by a dot "."; 
*		the parent directory is represented by two dots "..".
*		-- A hard link associates a name with an existing file (my usual perception of link :D).
*		-- A symbolic link associates a name with a path that may exist.
*		-- A regular file is a directory entry which is neither a directory, a hard link, nor a symbolic link.
* 
* -	file name: A file name is a string that represents a file. It is implementation-defined which characters 
*	are allowed, how long the name could be or if the name is case sensitive.
*
* - A path is a sequence of entries that identifies the location for a file. It has an optional root-name such 
*	as “C:” on Windows, followed by a root-directory such a “/” on Unix. Additional parts can be directories, 
*	hard links, symbolic links, or regular files. A path can be absolute, canonical, or relative.
*	--	An absolute path is a path that identifies a file.
*	--  A canonical path is a path that includes neither a symbolic link nor the relative paths "." 
*		(current directory) or ".."(parent directory).
*	--	A relative path specifies a path relative to a location in the file system. Paths such as "." 
*		(current directory), ".."(parent directory) or "home/rainer" are relative paths. On Unix, 
*		 they do not start at the root-directory "/"
* 
* Question: Can we conclude that a canonical path is more restrictive that an absolute one? I guess so.
* Note that as opposed to for example Java, in C++, path is what matters most, as opposed to file.
*/

