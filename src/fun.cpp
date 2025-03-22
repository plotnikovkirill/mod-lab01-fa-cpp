// Copyright 2022 UNN-IASR
#include <cmath>
#include <cctype>
#include "fun.h"

unsigned int faStr1(const char* str) {
    unsigned int cnt = 0;
    bool in_word = false;
    bool has_digit = false;

    for (; *str; ++str) {
        if (isspace(*str)) {
            if (in_word && !has_digit) {
                ++cnt;
            }
            in_word = false;
            has_digit = false;
        } else {
            in_word = true;
            if (isdigit(*str)) {
                has_digit = true;
            }
        }
    }

    if (in_word && !has_digit) {
        ++cnt;
    }

    return cnt;
}

unsigned int faStr2(const char* str) {
    unsigned int cnt = 0;
    bool in_word = false;
    bool capital_letter = false;
    bool right_word = true;

    for (; *str; ++str) {
        if (isspace(*str)) {
            if (in_word && capital_letter && right_word) {
                ++cnt;
            }
            in_word = false;
            capital_letter = false;
            right_word = true;
        } else {
            if (!in_word) {
                in_word = true;
                capital_letter = isupper(*str);
            }
            if (in_word && !islower(*str) && !isupper(*str)) {
                right_word = false;
            }
        }
    }

    if (in_word && capital_letter && right_word) {
        ++cnt;
    }
    return cnt;
}

unsigned int faStr3(const char* str) {
    unsigned int total_length = 0;
    unsigned int word_cnt = 0;
    unsigned int cur_length = 0;
    bool in_word = false;

    for (; *str; ++str) {
        if (isspace(*str)) {
            if (in_word) {
                total_length += cur_length;
                word_cnt++;
                cur_length = 0;
            }
            in_word = false;
        } else {
            in_word = true;
            cur_length++;
        }
    }

    if (in_word) {
        total_length += cur_length;
        word_cnt++;
    }

    if (word_cnt == 0) {
        return 0;
    }

    double average_length = static_cast<double>(total_length) / word_cnt;
    return static_cast<unsigned int>(round(average_length));
}
