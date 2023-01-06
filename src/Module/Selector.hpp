/**
 * @file Selector.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief Select between `register new words` and `query existing words` modes.
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include "Deleter.hpp"
#include "Querier.hpp"
#include "Register.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

namespace Module {

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Selector {
    void show_modes() {
        cout << "本字典可用功能如下：" << endl;
        cout << endl;
        cout << "1. 添加/修改释义" << endl;
        cout << "2. 查询单词" << endl;
        cout << "3. 删除单词" << endl;
        cout << "4. 显示所有单词和释义" << endl;
        cout << "5. 退出" << endl;
        cout << endl;
        cout << "请输入 `相应数字` 以做出选择 >>> ";
    }
    void goto_register() {
        Register::registry();
    }
    void goto_querier() {
        Querier::query();
    }
    void goto_deleter() {
        Deleter::delete_word();
    }
    void show_all() {
        if (Resource::Dict->empty()) {
            cout << "字典为空" << endl;
            cout << endl;
            return;
        }
        cout << "下面，为您显示当前字典中的 `所有` 单词和释义：" << endl;
        cout << endl;
        for (auto& [word, meaning] : *Resource::Dict) {
            cout << word << " => " << meaning << endl;
        }
        cout << endl;
    }
    void get_mode() {
        while (true) {
            show_modes();
            string mode;
            cin >> mode;
            cout << endl;
            if (mode == "1") {
                goto_register();
            } else if (mode == "2") {
                goto_querier();
            } else if (mode == "3") {
                goto_deleter();
            } else if (mode == "4") {
                show_all();
            } else if (mode == "5") {
                cout << "谢谢使用!" << endl;
                cout << endl;
                exit(0);
            } else {
                cout << "您输入的功能尚未开发，请重新输入！" << endl;
            }
            cout << endl;
        }
    }

public:
    static void select_mode() {
        Selector selector;
        selector.get_mode();
    }
};

} // namespace Module