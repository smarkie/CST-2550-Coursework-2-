#include <iostream>
#include <fstream>
#include "node.h"
#pragma once

class list
{   
    
    public:
        list();
        list(std::string Filepath);
        node* head;
        node *tail;
        void insert(std::string date,std::string vrn,std::string timein,std::string timeout);
        void display();
        void search();

};