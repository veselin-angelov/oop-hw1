//
// Created by vesko on 12.04.22 г..
//

#include "ComputerPartWriter.h"


ComputerPartWriter::ComputerPartWriter(const std::ostream& out) : out((std::ofstream&) out) {}

void ComputerPartWriter::write(const ComputerPart& computerPart) const
{
    if (!out.is_open())
    {
        throw std::runtime_error("File not open!");
    }

    char partsTypes[static_cast<int>(PartType::COUNT) + 1][256] =
            {"UNKNOWN", "MONITOR", "COMPUTER", "LAPTOP",
             "MOUSE", "KEYBOARD", "HEADPHONES", "CAMERA"};

    out << "{"
        << partsTypes[static_cast<int>(computerPart.getPartType()) + 1] << "|"
        << computerPart.getBrand() << "|"
        << computerPart.getModel() << "|"
        << computerPart.getWarranty() << "|"
        << computerPart.getPrice() << "}" << std::endl;

    if (!out.good())
    {
        throw std::runtime_error("File failed writing");
    }
}
