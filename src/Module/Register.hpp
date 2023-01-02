/**
 * @file Register.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief Register new words
 * @version 0.1
 * @date 2023-01-02
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

class Register {
    string word {};
    string meaning {};
    bool   if_exist = false;

    void show_tips_of_word() {
        cout << "`释义模块` 可以为 `新的单词` 添加释义 或修改 `已有单词` 的释义" << endl;
        cout << endl;
        cout << "请输入一个单词 >>> ";
    }
    void input_word() {
        cin >> word;
        cout << endl;
    }
    void show_tips_of_meaning() {
        if_exist = Resource::Dict->contains(word);
        if (if_exist) {
            cout << "您输入的单词已存在，原释义为：" << endl;
            cout << "\t" << Resource::Dict->at(word) << endl;
            cout << "请输入新释义 >>> ";
        } else {
            cout << "您输入的单词尚未存在，请输入释义 >>> ";
        }
    }
    void input_meaning() {
        cin >> meaning;
        cout << endl;
    }
    void update_mem_dict() {
        Resource::Dict->insert_or_assign(word, meaning);
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
    void show_changes() {
        if (if_exist) {
            cout << "您修改了单词 `" << word << "` 的释义为：" << endl;
            cout << "\t" << meaning << endl;
        } else {
            cout << "您添加了单词 `" << word << "` ，释义为：" << endl;
            cout << "\t" << meaning << endl;
        }
        cout << endl;
    }

public:
    static void registry() {
        Register reg;
        reg.show_tips_of_word();
        reg.input_word();
        reg.show_tips_of_meaning();
        reg.input_meaning();
        reg.update_mem_dict();
        reg.sync_in_file();
        reg.show_changes();
    }
};

} // namespace Module