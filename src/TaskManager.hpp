/**
 * @file TaskManager.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-12-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "Global/FileManager.hpp"
#include "Module/Initializer.hpp"
#include "Module/Selector.hpp"

namespace Task {

void run_all_tasks() {
    FileManager::init_all();
    Module::Initializer::init();
    Module::Selector::select_mode();
}

} // namespace Task