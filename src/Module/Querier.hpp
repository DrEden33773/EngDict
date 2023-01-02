/**
 * @file Querier.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief Query existing words
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include "../Resource/Dict.hpp"

#include <iostream>
#include <string>

namespace Module {

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Querier {
    string word {};

    void show_tips() {
        cout << "`查询模块` 可以查询 `已有单词` 的释义" << endl;
        cout << endl;
        cout << "请输入一个单词 >>> ";
    }
    void input_word() {
        cin >> word;
        cout << endl;
    }
    void try_to_show_meaning() {
        if (Resource::Dict->contains(word)) {
            cout << "您输入的单词的释义为：" << endl;
            cout << "\t" << Resource::Dict->at(word) << endl;
        } else {
            cout << "您输入的单词尚未存在" << endl;
        }
        cout << endl;
    }

public:
    static void query() {
        Querier querier;
        querier.show_tips();
        querier.input_word();
        querier.try_to_show_meaning();
    }
};

} // namespace Module