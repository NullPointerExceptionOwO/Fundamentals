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
 * \file Fundamentals/dirname/Main.cxx
 * \brief Return the directory portion of a pathname.
 * \date November 2024
 */

#include <iostream>
#include <libgen.h>

#define ProgramName "dirname"
#define UsageString "string..."

/**
 * \brief Show usage message and then quit with exit code 1.
 */
void usage(void);

int main(int argc, char** argv)
{
    if (argc <= 1)
        usage();
    for (int argIndex = 1; argIndex < argc; argIndex++)
        std::cout << dirname(argv[argIndex]) << '\n';
    return EXIT_SUCCESS;
}

void usage(void)
{
    std::cerr << "Usage: " << ProgramName << ' ' << UsageString << '\n';
    std::exit(EXIT_FAILURE);
}
