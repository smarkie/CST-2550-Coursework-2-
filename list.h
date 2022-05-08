#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <fstream>
#include <string>
#include "node.h" 
#pragma once

/* 
    list.h
    Author: Smith Rajesh Dbritto
    Created: 04/2022
    Updated: 05/2022

    Reference: *link
*/

class list
{    
    
    public:
        list();
        list(std::string Filepath);
        node *head;
        node *tail;
        void insert(std::string date,std::string vrn,std::string timein,std::string timeout);
        void display();
        void search();
    
};

#endif