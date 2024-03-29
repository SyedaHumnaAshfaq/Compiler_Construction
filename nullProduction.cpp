#include <iostream>
#include <string>

std::string processRules(std::string input)
{
    std::stringstream ss(input);
    std::string rule;
    std::string processedRules;
    bool replacedFirstA = false; // Flag to indicate if the first 'A' after '->' has been replaced

    while (std::getline(ss, rule, '|'))
    {
        // Replace 'A' with '&' in the current rule after the first 'A' after '->'
        if (replacedFirstA)
        {
            size_t pos = rule.find('A');
            while (pos != std::string::npos)
            {
                rule.replace(pos, 1, "&");
                pos = rule.find('A', pos + 1);
            }
        }

        // Add the processed rule to the result string
        processedRules += rule;
        if (!ss.eof())
        {
            processedRules += '|'; // Add '|' only if it's not the last rule
        }

        // Set flag after encountering '->'
        if (!replacedFirstA && rule.find("->") != std::string::npos)
        {
            replacedFirstA = true;
        }
    }

    return processedRules;
}
}

int main()
{
    std::string input = "A->A|Ad|B|&";
    std::string processedInput = processRules(input);
    std::cout << "Processed rules: " << processedInput << std::endl;
    return 0;
}
