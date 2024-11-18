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
 * \file Fundamentals/echo/Main.c
 * \brief Write arguments to standard output
 * \date November 2024
 */

#include <stdio.h>
#include <stdlib.h>

/* #define ProgramName "echo" */

int main(int argc, char** argv)
{
    ++argv; /* Seek to actual arguments */
    while (*argv != NULL) {
        printf("%s", *argv);
        if (*++argv != NULL)
            putchar(' ');
    }
    putchar('\n');
    return EXIT_SUCCESS;
}
