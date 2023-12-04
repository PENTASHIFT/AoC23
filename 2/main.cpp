#include <iostream>

inline char nextSpace(size_t& i, const std::string& line)
{
    for (; ' ' != line[i] && '\0' != line[i]; ++i) { }

    return line[i];
}

inline unsigned int getNumber(size_t i, const std::string& line)
{
    unsigned int number = 0;

    for (size_t ii = i - 1, digit = 1; ' ' != line[ii]; --ii)
    {
        number += (line[ii] - '0') * digit;
        digit *= 10;
    }

    return number;
}

#if defined(PART_ONE)

#define RED_LIM 12
#define GREEN_LIM 13
#define BLUE_LIM 14

unsigned int solve()
{
    size_t i;
    std::string line;

    unsigned int sum = 0;
    while (std::getline(std::cin, line))
    {
        for (i = 0; ':' != line[i]; ++i) { }   // Get to the colon after game #
        unsigned int game = getNumber(i, line);

        i += 2;     // Sets i to be the first digit after the colon.

        while (nextSpace(i, line))  // Space after number of <color> blocks
        {
            unsigned int number = getNumber(i, line);

            char color = line[i + 1];   // First character of the color.

            if (('r' == color && RED_LIM < number) ||
                ('b' == color && BLUE_LIM < number) ||
                ('g' == color && GREEN_LIM < number))
            {
                break;
            }

            if ('\0' == nextSpace(++i, line))     // Space before number of <color> blocks
            {
                sum += game;
                break;
            }
        }
    }

    return sum;
}

#elif defined(PART_TWO)

unsigned int solve()
{
    size_t i;
    std::string line;

    unsigned int sum = 0;
    while (std::getline(std::cin, line))
    {
        unsigned int maxBlue = 0, maxRed = 0, maxGreen = 0;
        for (i = 0; ':' != line[i]; ++i) { }   // Get to the colon after game #
        i += 2;     // Sets i to be the first digit after the colon.

        while (nextSpace(i, line))  // Space after number of <color> blocks
        {
            unsigned int number = getNumber(i, line);

            char color = line[i + 1];   // First character of the color.

            if ('r' == color && maxRed < number)
                maxRed = number;
            else if ('b' == color && maxBlue < number)
                maxBlue = number;
            else if ('g' == color && maxGreen < number)
                maxGreen = number;

            if ('\0' == nextSpace(++i, line))     // Space before number of <color> blocks
                break;
        }

        sum += (maxRed * maxBlue * maxGreen);
    }

    return sum;
}

#endif

int main()
{
    std::cout << solve() << std::endl;
}
