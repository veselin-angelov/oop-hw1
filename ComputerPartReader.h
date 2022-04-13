//
// Created by vesko on 13.04.22 г..
//

#ifndef DOM1_COMPUTERPARTREADER_H
#define DOM1_COMPUTERPARTREADER_H


#include <fstream>
#include "ComputerPart.h"

class ComputerPartReader
{
private:
    std::ifstream& in;

public:
    ComputerPartReader() = delete;
    explicit ComputerPartReader(const std::istream& in);

    ComputerPart read() const;
};


#endif //DOM1_COMPUTERPARTREADER_H
