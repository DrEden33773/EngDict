/**
 * @file Dict.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-12-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <map>
#include <memory>
#include <string>
#include <unordered_map>

namespace Resource {

using std::map;
using std::shared_ptr;
using std::string;
using std::unordered_map;

using dict_t = map<string, string>;

static const shared_ptr<dict_t> Dict = std::make_shared<dict_t>();

} // namespace Resource