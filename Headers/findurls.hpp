#ifndef FINDURLS_HPP
#define FINDURLS_HPP
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;

bool is_url_char(char sc);
vector<std::__cxx11::string> find_URLs(string fileName);

#endif  // FINDURLS_HPP
