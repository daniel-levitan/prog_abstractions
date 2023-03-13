/**
 * File: labelGenerator.cpp
 * ------------------------
 * Implements the interface for the labelGenerator class
 */

#import <iostream>
#import <sstream>
#import <string>
#import "labelGenerator.h"

// auxiliary prototypes
std::string integerToString(int n);

/**
 * Constructors: LabelGenerator
 * Usage:        Date LabelGenerator(std::string labelc);
 * ---------------------------------------------------------------
 * Initializes a label object. The constructor takes one parameter and 
 * initializes the object with it.
 */

LabelGenerator::LabelGenerator(std::string labelc, int indexc) {
    label = labelc;
    index = indexc;
}

std::string LabelGenerator::nextLabel() {
    index++;
    return label + integerToString(index);
}

std::string LabelGenerator::toString() {
    return label + integerToString(index);
}

std::ostream & operator<<(std::ostream & os, LabelGenerator myLabel) {
    return os << myLabel.toString();
}


// auxiliary functions
std::string integerToString(int n) {
    std::ostringstream stream;
    stream << n;
    return stream.str();
}

