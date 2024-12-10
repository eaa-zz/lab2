#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

class SentenceFilter {
private:
    string source;
    int count;
    bool isTextSource;
    void split_into_sent(const string& text, string*& sentences, int& sentenceCount, int& countw) const;

public:
    SentenceFilter();
    SentenceFilter(const string& filename, int count);
    SentenceFilter(const string& text, int count, bool isText);
    SentenceFilter(const SentenceFilter& other);
    ~SentenceFilter();
    void result() const;
};