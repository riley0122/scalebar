#pragma once
#include <vector>
#include <iostream>

int run_tests(std::vector<bool> tests, std::vector<std::string> testNames)
{
    int pass_count = 0;
    bool failed = false;
    for (long unsigned int i = 0; i < tests.size(); i++)
    {
        if (!tests[i])
        {
            std::cout << "\x1b[31;49;1m[FAILED]\x1b[0m test: " << testNames[i] << std::endl;
            failed = true;
        }
        else
        {
            std::cout << "\x1b[32;49;1m[PASSED]\x1b[0m test: " << testNames[i] << std::endl;
            pass_count += 1;
        }
    }

    std::cout << "Passed " << pass_count << "/" << tests.size() << " tests." << std::endl;
    if (failed)
    {
        return 1;
    }
    return 0;
}
