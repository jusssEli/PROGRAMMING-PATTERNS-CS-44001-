#ifndef WORD_LIST_HPP
#define WORD_LIST_HPP
#include <iostream>
#include <string>
#include <fstream>
using std::cout; using std::string; using std::endl;
class WordOccurrence {
public:
    WordOccurrence(const string& word="", int num=1) : word_(word), num_(num){};
    bool matchWord(const string &); // returns true if word matches stored
    // WordOccurrence* matchWord(const string &);
    void increment(); // increments number of occurrences
    string getWord() const; 
    int getNum() const;

private:
    string word_;
    int num_ ; // number of times word occurs
};

class WordList{
public:
    // add copy constructor, destructor, overloaded assignment
    WordList(int num = 0){size_ = num; wordArray_ = new WordOccurrence[size_];};
    WordList(const WordList&);
    ~WordList();
    WordList& operator=(const WordList rhs);
    // implement comparison as friend
    friend bool equal(const WordList&, const WordList&);

    void addWord(const string &);
    void print();
    void sorterer();
    // Only use for testing purposes
    WordOccurrence * getWords() const {return wordArray_;};
    int getSize() const {return size_;};
private:
    WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
                                // may or may not be sorted
    int size_;
};

#endif