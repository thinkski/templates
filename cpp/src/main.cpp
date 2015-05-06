//////////////////////////////////////////////////////////////////////////////
//
// @file   main.cpp
// @brief  Top-level file
//
// @author Joe Developer <user@domain.com>
// @copy   Copyright 2015 Company. All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////

// C++ Standard Library
#include <iostream>

// Boost Library
#include <boost/program_options.hpp>

// Generated by autoconf. Defines version information.
#include <config.h>


//////////////////////////////////////////////////////////////////////////////
//
// @brief
//
// @param  argc  Argument count
// @param  argv  Argument vector
//
// @return System code. Zero for success. Non-zero for error (see errno.h).
//
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    boost::program_options::options_description desc("Allowed options");

    desc.add_options()
        ("help,h", "produce help message")
        ("version,v", "print version information")
    ;

    boost::program_options::variables_map vm;
    boost::program_options::store(
        boost::program_options::parse_command_line(argc, argv, desc),
        vm);
    boost::program_options::notify(vm);

    // Print help information and exit successfully
    if (vm.count("help")) {
        std::cout << desc << std::endl
                  << "Report bugs to: <" PACKAGE_BUGREPORT ">" << std::endl
                  << std::endl;
        exit(0);
    }

    // Print version information and exit successfully
    if (vm.count("version")) {
        std::cout << PACKAGE_STRING << std::endl
                  << "Copyright (C) 2015 Company. "
                  << "All rights reserved." << std::endl
                  << std::endl;
        exit(0);
    }

    return 0;
}
