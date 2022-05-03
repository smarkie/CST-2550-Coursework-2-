#include <iostream>
#include <string>
#include "node.h"


    node::node(std::string date,std::string vrn,std::string timein,std::string timeout)
    {
        Date = date;
        VRN = vrn;
        TimeIn = timein;
        TimeOut = timeout;
    }
