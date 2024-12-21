#include "zadanie.h"

SentenceFilter::SentenceFilter() : source(""), count(0), isTextSource(false) //{cout << "The constructor without parameters for the SentenceFilter\n";}

SentenceFilter::SentenceFilter(const string& filename, int count)
    : source(filename), count(count), isTextSource(false) //{cout << "The constructor with parameters for the SentenceFilter\n";}

SentenceFilter::SentenceFilter(const string& text, int count, bool isText)
    : source(text), count(count), isTextSource(isText) //{cout << "The constructor with parameters for the SentenceFilter\n";}

SentenceFilter::SentenceFilter(const SentenceFilter& other)
    : source(other.source), count(other.count), isTextSource(other.isTextSource) //{cout << "The copy constructor for the SentenceFilter\n";}

SentenceFilter::~SentenceFilter() //{cout << "The destructor for the SentenceFilter\n";}

void SentenceFilter::result() const { // чтение данных из файла или строки
    string text;
    
    if (isTextSource) {
        text = source;
    } else {
        ifstream file(source);
        if (!file.is_open()) {
            cerr << "Error: " << source << endl;
            return;
        }
        ostringstream buffer; // буфер (запись в output поток)
        buffer << file.rdbuf(); // в буфер из файла
        text = buffer.str(); // в текст строки из буфера
        file.close();
    }

    cout << "Text:\n" << text << "\n\n";

    string* sentences = nullptr;
    int sentenceCount = 0;
    int countw = 0;
    split_into_sent(text, sentences, sentenceCount, countw);

    cout << "Words count: " << countw << endl;

    delete[] sentences;
}

void SentenceFilter::split_into_sent(const string& text, string*& sentences, int& sentenceCount, int& countw) const { // Обратите внимание: countw передаётся по ссылке
    const int maxSentences = 100;
    sentences = new string[maxSentences];
    sentenceCount = 0;
    countw = 0;
    ostringstream sentenceStream;

    for (char ch : text) {
        sentenceStream << ch;
        if (ch == '.' || ch == '!' || ch == '?' || ch == ',' || ch == ' ' || ch == '\n') { 
            if (sentenceCount < maxSentences) {
                string sentence = sentenceStream.str();
                sentences[sentenceCount++] = sentence;
                if (!sentence.empty()) {
                  string word;
                  for (char c : sentence) {
                    if (isalpha(c)) {
                      word += c;
                    } else if (!word.empty()) {
                      if (word.length() <= 4) {
                        countw++;
                      }
                      word = "";
                    }
                  }
                  if (!word.empty() && word.length() <= 4) {
                    countw++;
                  }
                }


                sentenceStream.str("");
                sentenceStream.clear();
            }
        }
    }
    if (!sentenceStream.str().empty() && sentenceCount < maxSentences) {
        sentences[sentenceCount++] = sentenceStream.str();
    }
}


