#include <iostream>
#include <fstream>
#include <cstring>
#include "ComputerPart.h"
#include "ComputerPartWriter.h"
#include "ComputerPartReader.h"


int main() {
    std::ofstream out("test.txt", std::ios::app);
    std::ifstream in("test.txt");

    try
    {
        ComputerPart computerPart(PartType::MONITOR, 2, 250.0, "Acer", "C27F390FHR");
        ComputerPart computerPart1(static_cast<const PartType>(1), 5, 250.0, "Samsung", "C27F390FHR");
    //    ComputerPart computerPart2 = computerPart;
//        ComputerPart computerPart3;
    //    computerPart1 = computerPart2;

    //    computerPart2.setPrice(20);

//        char* brand = const_cast<char *>(computerPart.getBrand());
//        strcpy(brand, "asd");

        computerPart.print();
        computerPart1.print();
    //    computerPart2.print();
    //    computerPart3.setPrice(220.99);
//        computerPart3.print();


        ComputerPartWriter computerPartWriter(out);
        ComputerPartReader computerPartReader(in);

        computerPartWriter.write(computerPart);
        computerPartWriter.write(computerPart1);

        ComputerPart computerPart2 = computerPartReader.read();
        out.close();
        in.close();
    }
    catch (std::exception& e)
    {
        out.close();
        in.close();
        std::cout << e.what() << std::endl;
    }

    return 0;
}
