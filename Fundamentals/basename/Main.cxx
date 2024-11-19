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
 * \file Fundamentals/basename/Main.cxx
 * \brief Return non-directory portion of a pathname
 * \date November 2024
 */

#include <iostream>
#include <libgen.h>
#include <string_view>

#define ProgramName "basename"
#define UsageString "string [suffix]"

/**
 * \brief Show usage message and then quit with exit code 1.
 */
void usage(void);

int main(int argc, char** argv)
{
    if (argc <= 1 || argc >= 4)
        usage();
    std::string_view baseName = basename(argv[1]);
    const std::string suffix = argc == 3 ? argv[2] : "";
    if (!suffix.empty() && baseName.length() > suffix.length()
        && baseName.ends_with(suffix))
        baseName.remove_suffix(suffix.length());
    std::cout << baseName << '\n';
    return EXIT_SUCCESS;
}

void usage(void)
{
    std::cerr << "Usage: " << ProgramName << ' ' << UsageString << '\n';
    std::exit(EXIT_FAILURE);
}
