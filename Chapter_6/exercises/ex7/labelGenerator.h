/**
 * File: labelGenerator.h
 * ----------------------
 * Defines the interface for the labelGenerator class
 */


#ifndef _labelGenerator_h
#define _labelGenerator_h

class LabelGenerator {
public:
    LabelGenerator(std::string labelc, int indexc);

    std::string nextLabel();

    std::string toString();

private:
    std::string label;
    int index;
};

std::ostream & operator<<(std::ostream & os, LabelGenerator myLabel);

#endif