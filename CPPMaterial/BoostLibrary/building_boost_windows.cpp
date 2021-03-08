/**
* To build boost for windows, all we had to do was to download the zip files, then unzip them. After that,
* we first run the bootstrap, and once the 'b2.exe' is created, all we need to do is to run it. 
* 
* Suggested options for b2 are as follows:
* '--prefix=DESTINATION --architecture=platform_architecture'
* 
* Surprisingly enough, boost is compiled for x86 on my x64 machine. This probably is not a big deal, as most
* of the content of the project are in header files.
*/