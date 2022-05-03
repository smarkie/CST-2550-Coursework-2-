#include <iostream>
#include <string>
#pragma once

struct node
{
    public:
    std::string Date;
    std::string VRN;
    std::string TimeIn;
    std::string TimeOut;
    node* next;
    node(std::string,std::string,std::string,std::string);

};

