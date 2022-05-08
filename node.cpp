/* 
    node.cpp
    Author: Smith Rajesh Dbritto
    Created: 04/2022
    Updated: 05/2022

    References: 
	cjamesm (2012) ‘Answer to “How to loop back to the beginning of a switch statement after a case”’, Stack Overflow. Available at: 			https://stackoverflow.com/a/13089413 (Accessed: 6 May 2022).

	How to read CSV file in C++? - Java2Blog (2021). Available at: https://java2blog.com/read-csv-filein-cpp/ (Accessed: 6 May 2022).

	Input/output with files - C++ Tutorials (no date). Available at:
	https://www.cplusplus.com/doc/tutorial/files/ (Accessed: 20 April 2022).

	Read data from csv file and store it to linked list || Search data from linked list || in C++ - YouTube
	(no date). Available at: https://www.youtube.com/ (Accessed: 6 May 2022).
*/

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
