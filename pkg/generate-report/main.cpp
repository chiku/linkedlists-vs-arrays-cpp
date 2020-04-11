// Author::    Chirantan Mitra
// Copyright:: Copyright (c) 2020. All rights reserved
// License::   MIT

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

bool
replace(std::string& str, const std::string& from, const std::string& to)
{
    size_t startPos = str.find(from);
    if(startPos == std::string::npos) {
        return false;
    }
    str.replace(startPos, from.length(), to);
    return true;
}

int
main()
{
    std::ifstream arrayListFile("./output/arraylist.csv");
    if (!arrayListFile.is_open())
    {
        std::cerr << "Failed to open ./output/arraylist.csv";
        return 1;
    }

    std::ifstream linkedListFile("./output/linkedlist.csv");
    if (!linkedListFile.is_open()) {
        std::cerr << "Failed to open ./output/linkedListFile.csv";
        return 1;
    }

    std::ifstream templateFile("./public/comparison.js.template");
    if (!templateFile.is_open()) {
        std::cerr << "Failed to open ./public/comparison.js.template";
        return 1;
    }

    std::ofstream outputFile("./public/comparison.js");
    if (!linkedListFile.is_open()) {
        std::cerr << "Failed to open ./public/comparison.js";
        return 1;
    }

    std::ostringstream containerSizes, arrayListDurations, linkedListDurations;
    std::string line;

    while(std::getline(arrayListFile, line))
    {
        std::istringstream stream(line);
        std::vector<std::string> tokens;
        for (std::string token; std::getline(stream, token, ','); tokens.push_back(token));

        long count = std::stol(tokens[0]);
        double duration = std::stod(tokens[1]);

        containerSizes << count << ", ";
        arrayListDurations << duration << ", ";
    }

    while(std::getline(linkedListFile, line))
    {
        std::istringstream stream(line);
        std::vector<std::string> tokens;
        for (std::string token; std::getline(stream, token, ','); tokens.push_back(token));

        double duration = std::stod(tokens[1]);

        linkedListDurations << duration << ", ";
    }

    std::string jsTemplate(
        (std::istreambuf_iterator<char>(templateFile)),
        std::istreambuf_iterator<char>()
    );

    replace(jsTemplate, "{{container_sizes}}", containerSizes.str());
    replace(jsTemplate, "{{array_list_durations}}", arrayListDurations.str());
    replace(jsTemplate, "{{linked_list_durations}}", linkedListDurations.str());

    outputFile << jsTemplate;
}
