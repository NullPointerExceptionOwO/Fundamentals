/**
 * \file Fundamentals/kill/Main.cxx
 * \brief Kill process.
 * \date November 2024
 */

#include <csignal>
#include <iostream>

#define ProgramName "kill"
#define UsageString ""
#define Options ""

/**
 * \brief Show usage message and then quit with exit code 1.
 */
void usage(void);

int main(void)
{
    /* KILL YOURSELF NOW */
    kill(getpid(), SIGSEGV);
}

void usage(void)
{
    std::cerr << "Usage: " << ProgramName << ' ' << UsageString << '\n';
    std::exit(EXIT_FAILURE);
}
