/**
 * @file Initializer.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-12-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "../Global/FileManager.hpp"
#include "../Resource/Dict.hpp"

#include <stdexcept>

namespace Module {

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

using path = std::filesystem::path;

class Initializer {
    string word;
    string meaning;

    void read_from_file() {
        fstream src;
        // 1. try open file
        src.open(FileManager::Filename::DictFile, fstream::in);
        if (!src.is_open()) {
            throw std::runtime_error("Cannot open `dict.txt`!");
        }
        // 2. load string
        string token;
        size_t token_num = 0;
        while (src >> token) {
            ++token_num;
            if (token_num % 2 != 0) {
                // 2.1 loaded a `word` token
                word.clear();
                meaning.clear();
                word = token;
            } else {
                // 2.2 loaded a `meaning` token
                meaning = token;
                // now, insert to `Resource::Dict`
                Resource::Dict->insert({ word, meaning });
            }
        }
        // 3. close file
        src.close();
        // 4. check token_num
        if (token_num % 2 != 0) {
            throw std::runtime_error("Num of `original_word` and `meaning` cannot match!");
        }
        // 5. end
        cout << "Successfully loaded dictionary from file..." << endl;
        cout << endl;
    }

public:
    static void init() {
        Initializer init_p;
        init_p.read_from_file();
    }
};

} // namespace Module