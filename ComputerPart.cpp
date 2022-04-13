//
// Created by vesko on 12.04.22 г..
//

#include "ComputerPart.h"
#include <iostream>
#include <cstring>

ComputerPart::ComputerPart() : partType(PartType::UNKNOWN), brand(nullptr), model(nullptr) {}

ComputerPart::ComputerPart(const PartType partType, const unsigned int warranty, const double price, const char* brand, const char* model) :
        partType(partType), warranty(warranty), price(price),
        brand(strcpy(new char[strlen(brand) + 1], brand)),
        model(strcpy(new char[strlen(model) + 1], model))
{
    validateInputData();
}

ComputerPart::ComputerPart(const ComputerPart &other) :
        partType(other.partType), warranty(other.warranty), price(other.price),
        brand(strcpy(new char[strlen(other.brand) + 1], other.brand)),
        model(strcpy(new char[strlen(other.model) + 1], other.model)) {}

ComputerPart::~ComputerPart()
{
    delete[] brand;
    delete[] model;
}

void ComputerPart::validateInputData() const
{
    if (partType <= PartType::UNKNOWN || partType >= PartType::COUNT)
    {
        throw std::out_of_range("Invalid enum value.");
    }
    else if (price < 0)
    {
        throw std::out_of_range("Price should be a positive number.");
    }
}


//ComputerPart& ComputerPart::operator=(const ComputerPart &other)
//{
//    if (this != &other)
//    {
//        setPartType(other.partType);
//        setWarranty(other.warranty);
//        setPrice(other.price);
//        setBrand(other.brand);
//        setModel(other.model);
//    }
//
//    return *this;
//}

PartType ComputerPart::getPartType() const
{
    return partType;
}

unsigned int ComputerPart::getWarranty() const
{
    return warranty;
}

double ComputerPart::getPrice() const
{
    return price;
}

const char* ComputerPart::getBrand() const
{
    return brand;
}

const char* ComputerPart::getModel() const
{
    return model;
}

//void ComputerPart::setPartType(const PartType partType)
//{
//    if (partType <= PartType::UNKNOWN || partType >= PartType::COUNT)
//    {
//        this->partType = PartType::UNKNOWN;
//        return;
//    }
//    this->partType = partType;
//}
//
//void ComputerPart::setWarranty(const unsigned int warranty)
//{
//    this->warranty = warranty;
//}

void ComputerPart::setPrice(const double price)
{
    if (price < 0)
    {
        throw std::out_of_range("Price should be a positive number.");
    }
    this->price = price;
}

//void ComputerPart::setBrand(const char *brand)
//{
//    delete[] this->brand;
//    this->brand = new char[strlen(brand) + 1];
//    strcpy(this->brand, brand);
//}
//
//void ComputerPart::setModel(const char *model)
//{
//    delete[] this->model;
//    this->model = new char[strlen(model) + 1];
//    strcpy(this->model, model);
//}

void ComputerPart::print() const
{
    char partsTypes[static_cast<int>(PartType::COUNT) + 1][256] =
            {"UNKNOWN", "MONITOR", "COMPUTER", "LAPTOP",
             "MOUSE", "KEYBOARD", "HEADPHONES", "CAMERA"};

    std::cout << partsTypes[static_cast<int>(partType) + 1] << ", " << warranty << ", "
              << price << ", " << (brand ? brand : "") << ", " << (model ? model : "") << std::endl;
}

