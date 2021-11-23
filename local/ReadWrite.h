#ifndef GALLERYTEC_PROYECTO3_READWRITE_H
#define GALLERYTEC_PROYECTO3_READWRITE_H

#include <bits/stdc++.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * The ReadWrite class will read, write and clear the given file
 */
class ReadWrite {
public:
    /**
     * This method clears all contents in the given file
     */
    void clearFile(string path);

    /**
     * This method will read all of the contents of the given file
     * @return a string containing the data in specified file
     */
    string readFile(string path);

    /**
     * This method will write the contents of the string result variable into the given file
     * @param result the string that contains the data that is going to be written.
     */
    void writeFile(string path , string result);

private:
    /**
     * Returns the location of the present working directory
     * @return
     */
    string getPWD();
};


#endif
