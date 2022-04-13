//
// Created by vesko on 12.04.22 г..
//

#ifndef DOM1_COMPUTERPARTWRITER_H
#define DOM1_COMPUTERPARTWRITER_H


#include <fstream>
#include "ComputerPart.h"

class ComputerPartWriter
{
private:
    std::ofstream& out;

public:
    ComputerPartWriter() = delete;
    explicit ComputerPartWriter(const std::ostream& out);

    void write(const ComputerPart& computerPart) const;
};


#endif //DOM1_COMPUTERPARTWRITER_H
