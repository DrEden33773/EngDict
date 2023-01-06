/**
 * @file Deleter.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-01-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include "../Global/FileManager.hpp"
#include "../Resource/Dict.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

namespace Module {

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

class Deleter {
    string word;

    void show_tips() {
        cout << "`删除模块` 可以删除 `已有单词` 和它对应的释义" << endl;
        cout << endl;
        cout << "请输入一个单词 >>> ";
    }
    void input_word() {
        cin >> word;
        cout << endl;
    }
    void try_to_delete_meaning() {
        if (Resource::Dict->contains(word)) {
            Resource::Dict->erase(word);
            cout << "您输入的单词的释义已删除" << endl;
        } else {
            cout << "您输入的单词不存在，自动跳过" << endl;
        }
        cout << endl;
    }
    void sync_in_file() {
        fstream file;
        file.open(FileManager::Filename::DictFile, fstream::out | fstream::trunc);
        if (!file.is_open()) {
            throw std::runtime_error("无法打开文件，同步未完成");
        }
        for (auto& [_word, _meaning] : *Resource::Dict) {
            file << _word << " " << _meaning << endl;
        }
        file.close();
    }

public:
    static void delete_word() {
        Deleter deleter;
        deleter.show_tips();
        deleter.input_word();
        deleter.try_to_delete_meaning();
        deleter.sync_in_file();
    }
};

} // namespace Module
