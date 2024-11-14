/*
 * Copyright (C) 2024  menadione
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * \file Fundamentals/yes/Main.cxx
 * \brief Main function for yes command
 * \date November 2024
 */

#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::string yesOutput;
    if (argc <= 1)
        yesOutput = "y";
    else
        for (int i = 1; i < argc; ++i)
            yesOutput += std::string(argv[i]) + ' ';
    /*
     * Writing into stdout until EOF is received
     */
    while (std::cout << yesOutput << '\n')
        ;
    return EXIT_FAILURE;
}
