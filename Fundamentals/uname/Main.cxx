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
 * \file Fundamentals/uname/Main.cxx
 * \brief Show (u)nix (name)
 * \date November 2024
 */

#include <cstring>
#include <iostream>
#include <sys/utsname.h>
#include <unistd.h>

#define ProgramName "uname"
#define UsageString "-[amnrsv]"
#define Options "amnrsv"

/* Bitmasks for options */
#define MFlag (1 << 0)
#define NFlag (1 << 1)
#define RFlag (1 << 2)
#define SFlag (1 << 3)
#define VFlag (1 << 4)

/**
 * \brief Show usage message and then quit with exit code 1.
 */
void usage(void);

/**
 * \brief Print given elements and separate them using space.
 * \param[in] element Element to print
 */
void printElement(const char*);

int main(int argc, char** argv)
{
    utsname systemUname;
    int flags = 0;
    int option;
    while ((option = getopt(argc, argv, Options)) != -1) {
        switch (option) {
        case 'a':
            flags |= (MFlag | NFlag | RFlag | SFlag | VFlag);
            break;
        case 'm':
            flags |= MFlag;
            break;
        case 'n':
            flags |= NFlag;
            break;
        case 'r':
            flags |= RFlag;
            break;
        case 's':
            flags |= SFlag;
            break;
        case 'v':
            flags |= VFlag;
            break;
        default:
            usage();
        }
    }
    if (optind != argc)
        usage();
    /*
     * When flags are not provided
     * we default to -s.
     */
    if (!flags)
        flags = SFlag;
    if (uname(&systemUname)) {
        std::cerr << std::strerror(errno) << '\n';
        return EXIT_FAILURE;
    }
    /*
     * Print information about this system
     */
    if (flags & SFlag)
        printElement(systemUname.sysname);
    if (flags & NFlag)
        printElement(systemUname.nodename);
    if (flags & RFlag)
        printElement(systemUname.release);
    if (flags & VFlag)
        printElement(systemUname.version);
    if (flags & MFlag)
        printElement(systemUname.machine);
    std::cout << '\n';
    return EXIT_SUCCESS;
}

void usage(void)
{
    std::cerr << "Usage: " << ProgramName << ' ' << UsageString << '\n';
    std::exit(EXIT_FAILURE);
}

void printElement(const char* element)
{
    static bool useSpaces = false;
    if (useSpaces)
        std::cout << ' ';
    std::cout << element;
    useSpaces = true;
}
