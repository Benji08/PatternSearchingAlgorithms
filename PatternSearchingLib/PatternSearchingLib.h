#pragma once
#include <iomanip>
#include <iostream>
#include <vector>
#include <cstring>
#define d 256

template <typename CharType>
void computeLPSArray(CharType& pat, int pat_length, int* lps)
{
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pat_length) {
        if (pat[i] == pat[length]) {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0) {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

template <typename CharType>
std::vector<int> NaiveSearch(CharType& pattern, CharType& text){
    std::vector<int> index;
    int pat_length = pattern.size();
    int txt_length = text.size();
    for (int i = 0; i <= txt_length - pat_length; i++) {
        int j;
        for (j = 0; j < pat_length; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == pat_length)
            index.push_back(i);
    }
    return index;
}

template <typename CharType>
std::vector<int> KMPSearch(CharType& pattern, CharType& text){
    std::vector<int> index;
    int pat_length = pattern.size();
    int txt_length = text.size();
    int lps[pat_length];

    computeLPSArray(pattern, pat_length, lps);

    int i = 0;
    int j = 0;
    while (i < txt_length) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == pat_length) {
            index.push_back(i - j);
            j = lps[j - 1];
        }

        else if (i < txt_length && pattern[j] != text[i]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return index;
}

template <typename CharType>
std::vector<int> RKSearch(CharType& pattern, CharType& text, int q){
    std::vector<int> index;
    int pat_length = pattern.size();
    int txt_length = text.size();
    int i, j;
    int hash_pat_value = 0;
    int hash_txt_value = 0;
    int h = 1;

    for (i = 0; i < pat_length - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < pat_length; i++)
    {
        hash_pat_value = (pattern[i] + d * hash_pat_value ) % q;
        hash_txt_value = (text[i] + d * hash_txt_value) % q;
    }

    for (i = 0; i <= txt_length - pat_length; i++)
    {

        if (hash_pat_value == hash_txt_value )
        {
            for (j = 0; j < pat_length; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }

            }

            if (j == pat_length){
                index.push_back(i);
            }
        }

        if ( i < txt_length-pat_length )
        {
            hash_txt_value = (text[i + pat_length] + d * (hash_txt_value - text[i] * h)) % q;

            if (hash_txt_value < 0)
                hash_txt_value = (hash_txt_value + q);
        }
    }
    return index;
}
