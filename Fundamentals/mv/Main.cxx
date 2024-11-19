/*
 * Copyright (C) 2024  menadione
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * \file Fundamentals/mv/Main.cxx
 * \brief (M)o(v)e
 * \date November 2024
 */

/* TODO: Rewrite in C */

#include <cstdio>
#include <filesystem>
#include <iostream>
#include <unistd.h>
#include <vector>

#define ProgramName "mv"
/* #define UsageString "" */
#define Options "if"

namespace fs = std::filesystem;

/**
 * \brief Show usage message and then quit with exit code 1.
 */
void usage(void);

int main(int argc, char** argv)
{
    bool confirm = false;
    int option;
    while ((option = getopt(argc, argv, Options)) != -1) {
        switch (option) {
        case 'i':
            confirm = true;
            break;
        case 'f':
            confirm = false;
            break;
        default:
            usage();
        }
    }
    /*
     * Getting files list&count without parameters
     */
    int filesCount = argc - optind;
    char** argvFilesOnly = argv + optind;
    if (filesCount <= 1) {
        std::cerr << ProgramName << ": " << "Too few arguments provided.\n";
        usage();
    }
    /* Last one is target directory/file */
    const fs::path target(fs::weakly_canonical(argvFilesOnly[filesCount - 1]));
    const bool isTargetADir = fs::is_directory(target);
    for (int argvIndex = 0; argvIndex < filesCount - 1; ++argvIndex) {
        const fs::path toMove(argvFilesOnly[argvIndex]);
        if (!fs::exists(toMove)) {
            std::cerr << ProgramName << ": " << toMove
                      << ": No such file or directory\n";
            return EXIT_FAILURE;
        }
        /* FIXME: Implement -i argument */
        if (confirm) { }
        try {
            fs::rename(toMove, isTargetADir ? target / toMove.filename() : target);
        } catch (const fs::filesystem_error& e) {
            std::cerr << "Failed to move " << toMove << " to " << target << " ("
                      << e.what() << ")\n";
        }
    }
    return EXIT_SUCCESS;
}

void usage(void)
{
    std::cerr << "Usage: " << ProgramName << ' ' << "[-if] source_file target_file"
              << '\n';
    std::cerr << "       " << ProgramName << ' ' << "[-if] source_file... target_dir"
              << '\n';
    std::exit(EXIT_FAILURE);
}