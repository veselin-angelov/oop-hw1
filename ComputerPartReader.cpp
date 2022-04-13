//
// Created by vesko on 13.04.22 г..
//

#include <iostream>
#include "ComputerPartReader.h"


ComputerPartReader::ComputerPartReader(const std::istream &in) : in((std::ifstream&) in) {}

ComputerPart ComputerPartReader::read() const
{
    if (!in.is_open())
    {
        throw std::runtime_error("File not open!");
    }

//    char partsTypes[static_cast<int>(PartType::COUNT) + 1][256] =
//            {"UNKNOWN", "MONITOR", "COMPUTER", "LAPTOP",
//             "MOUSE", "KEYBOARD", "HEADPHONES", "CAMERA"};

    ComputerPart computerPart;
    char delimiter;
    char type[256] = {};

    in >> delimiter;
    if (in.good())
        std::cout << delimiter << std::endl;

    in >> type;
    if (in.good())
        std::cout << type << std::endl;

//    out << "{"
//        << partsTypes[static_cast<int>(computerPart.getPartType()) + 1] << "|"
//        << computerPart.getBrand() << "|"
//        << computerPart.getModel() << "|"
//        << computerPart.getWarranty() << "|"
//        << computerPart.getPrice() << "}" << std::endl;

    if (!in.good())
    {
        throw std::runtime_error("File failed reading");
    }

    in.close();

    return computerPart;
}
