#include <iostream>

#if defined(PART_ONE)

unsigned int solve()
{
    std::string line;
    unsigned int sum = 0;
    while (std::cin >> line)
    {
        size_t i, j;
        unsigned int number;

        // 10's place.
        for (i = 0; i < line.length(); ++i)
        {
            if ('0' <= line[i] && '9' >= line[i])
            {
                number = 10 * (line[i] - '0');
                break;
            }
        }

        // 1's place.
        for (j = line.length() - 1; j >= i; --j)
        {
            if ('0' <= line[j] && '9' >= line[j])
            {
                number += (line[j] - '0');
                break;
            }
        }

        sum += number;
    }

    return sum;
}

#elif defined(PART_TWO)

unsigned int solve()
{
    std::string line;
    unsigned int sum = 0;
    while (std::cin >> line)
    {
        size_t i, j;
        unsigned int number;

        // 10's place; from left-to-right.
        for (i = 0; i <= line.length() - 1; ++i)
        {
            if ('0' <= line[i] && '9' >= line[i])
            {
                number = 10 * (line[i] - '0');
                break;
            } 
        }
    }

    return 0;
}

#endif

int main()
{
    std::cout << solve() << std::endl;
    return 0;
}
