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

    const std::string NUMBERS[] = { 
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };

    while (std::cin >> line)
    {
        size_t i, j;
        unsigned int num;

        bool breakFlag = false;          // Set in nested loops in else conditions.
        size_t length = line.length() - 1;

        // 10's place; from left-to-right.
        for (i = 0; i <= length && !breakFlag; ++i)
        {
            if ('0' <= line[i] && '9' >= line[i])
            {
                num = 10 * (line[i] - '0');
                break;
            } 
            else
            {
                for (size_t number = 0; number < 9; ++number)
                {
                    size_t numberLen = NUMBERS[number].length();

                    if ((length - i) < (numberLen - 1))
                        continue;
                    else if (line.substr(i, numberLen) == NUMBERS[number])
                    {
                        num = 10 * (number + 1);
                        breakFlag = true;
                        break;
                    }
                }
            }
        }
        
        breakFlag = false;

        // 1's place; from right-to-left.
        for (j = length; j >= i && !breakFlag; --j)
        {
            if ('0' <= line[j] && '9' >= line[j])
            {
                num += (line[j] - '0');
                break;
            }
            else
            {
                for (size_t number = 0; number < 9; ++number)
                {
                    size_t numberLen = NUMBERS[number].length();

                    if (j < numberLen - 1)
                        continue;
                    else if (line.substr(j - (numberLen - 1), numberLen) == NUMBERS[number])
                    {
                        num += (number + 1);
                        breakFlag = true;
                        break;
                    }
                }
            }
        }

        std::cout << line << std::endl << num << std::endl << std::endl;
        sum += num;
    }

    return sum;
}

#endif

int main()
{
    std::cout << solve() << std::endl;
    return 0;
}
