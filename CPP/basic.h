#pragma once

//includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

//aliases
template <typename U>
using uptr = std::unique_ptr<U>;

template <typename S>
using sptr = std::shared_ptr<S>;

//functions
void print(const std::string& message);
std::string input(const std::string& message);