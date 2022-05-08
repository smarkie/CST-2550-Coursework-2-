#ifndef _NODE_H_
#define _NODE_H_

#include <iostream> 
#include <string>
#pragma once

/* 
    node.h
    Author: Smith Rajesh Dbritto
    Created: 04/2022
    Updated: 05/2022
*/

/* Creating structure with public access modifier 
which includes the value and pointer to the next node */
struct node
{
    public:
    std::string Date;
    std::string VRN;
    std::string TimeIn;
    std::string TimeOut;
    std::string filename;
    node* next;
    node(std::string,std::string,std::string,std::string);

};

#endif