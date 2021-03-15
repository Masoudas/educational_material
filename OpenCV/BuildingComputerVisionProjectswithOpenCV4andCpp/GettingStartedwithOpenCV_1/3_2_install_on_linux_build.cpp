/**
 * Once the cmake configuration and generation process is complete, the make build scripts are ready to be executed.
 * To be able to run the make, we need to have make installed, which as we recall is part of the famous 'build-essential'
 * package that is installed through 'apt-get' on Debian systems.
 * 
 * Don't forget the famous formula for building the files:
 *  -   First run 'make -j5' to generate the libraries and binaries
 *  -   Then run 'make install' to install the binaries and libs in the destination folder. 
 * 
 * The build task surprisingly enough takes a lot of time! More than Windows!
 */