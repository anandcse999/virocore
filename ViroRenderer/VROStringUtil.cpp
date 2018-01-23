//
//  VROStringUtil.cpp
//  ViroRenderer
//
//  Created by Raj Advani on 11/7/16.
//  Copyright © 2016 Viro Media. All rights reserved.
//

#include "VROStringUtil.h"
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "VRODefines.h"

std::string VROStringUtil::toString(int i) {
    std::stringstream ss;
    ss << i;
    return ss.str();
}

std::string VROStringUtil::toString(double n, int precision) {
    std::ostringstream ss;
    ss.setf(std::ios::fixed, std::ios::floatfield);
    ss.precision(precision);
    
    ss << n;
    return ss.str();
}

std::wstring VROStringUtil::toWString(int i) {
    std::wstringstream ss;
    ss << i;
    return ss.str();
}

std::wstring VROStringUtil::toWString(double n, int precision) {
    std::wostringstream ss;
    ss.setf(std::ios::fixed, std::ios::floatfield);
    ss.precision(precision);
    
    ss << n;
    return ss.str();
}

int VROStringUtil::toInt(std::string s) {
    return atoi(s.c_str());
}

float VROStringUtil::toFloat(std::string s) {
    return atof(s.c_str());
}

std::vector<std::string> VROStringUtil::split(const std::string &s,
                                              const std::string &delimiters,
                                              bool emptiesOk) {
    
    std::vector<std::string> result;
    size_t current;
    size_t next = -1;
    
    do {
        if (!emptiesOk) {
            next = s.find_first_not_of(delimiters, next + 1);
            if (next == std::string::npos) {
                break;
            };
            
            next -= 1;
        }
        
        current = next + 1;
        next = s.find_first_of(delimiters, current);
        result.push_back(s.substr(current, next - current));
    }
    while (next != std::string::npos);
    
    return result;
}

std::vector<std::wstring> VROStringUtil::split(const std::wstring &s,
                                               const std::wstring &delimiters,
                                               bool emptiesOk) {
    
    std::vector<std::wstring> result;
    size_t current;
    size_t next = -1;
    
    do {
        if (!emptiesOk) {
            next = s.find_first_not_of(delimiters, next + 1);
            if (next == std::wstring::npos) {
                break;
            };
            
            next -= 1;
        }
        
        current = next + 1;
        next = s.find_first_of(delimiters, current);
        result.push_back(s.substr(current, next - current));
    }
    while (next != std::wstring::npos);
    
    return result;
}

bool VROStringUtil::strcmpinsensitive(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if (tolower(a[i]) != tolower(b[i])) {
            return false;
        }
    }
    return true;
}

void VROStringUtil::toLowerCase(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

bool VROStringUtil::startsWith(const std::string &candidate, const std::string &prefix) {
    if (candidate.length() < prefix.length()) {
        return false;
    }
    return 0 == candidate.compare(0, prefix.length(), prefix, 0, prefix.length());
}

bool VROStringUtil::endsWith(const std::string& candidate, const std::string& ending) {
    if (candidate.length() < ending.length()) {
        return false;
    }
    return 0 == candidate.compare(candidate.length() - ending.length(), ending.length(), ending);
}

bool VROStringUtil::replace(std::string &str, const std::string &from, const std::string &to) {
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos) {
        return false;
    }
    str.replace(start_pos, from.length(), to);
    return true;
}

void VROStringUtil::replaceAll(std::string &str, const std::string &from, const std::string &to) {
    if (from.empty()) {
        return;
    }
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}
