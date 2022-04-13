//
// Created by vesko on 12.04.22 г..
//

#ifndef DOM1_COMPUTERPART_H
#define DOM1_COMPUTERPART_H


#include "PartType.h"

class ComputerPart
{
private:
    const PartType partType{};
    const unsigned int warranty{};
    double price{};
    const char* const brand{};
    const char* const model{};

    void validateInputData() const;

//    void setPartType(PartType partType);
//    void setWarranty(unsigned int warranty);
//    void setBrand(const char *brand);
//    void setModel(const char *model);

public:
    ComputerPart();
    ComputerPart(PartType partType, unsigned int warranty, double price, const char* brand, const char* model);
    ComputerPart(const ComputerPart& other);
    ~ComputerPart();

    ComputerPart& operator=(const ComputerPart& other) = delete;

    PartType getPartType() const;
    unsigned int getWarranty() const;
    double getPrice() const;
    const char* getBrand() const;
    const char* getModel() const;

    void setPrice(double price);

    void print() const;
};


#endif //DOM1_COMPUTERPART_H
