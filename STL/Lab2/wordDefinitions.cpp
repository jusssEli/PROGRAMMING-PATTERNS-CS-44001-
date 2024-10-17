#include "WordList.hpp"
//class definitions
bool WordOccurrence::matchWord(const std::string & rhs){
    if( word_ == rhs) 
        return true;
    else 
        return false; 
} 

// increments number of occurrences
void WordOccurrence::increment(){
    ++num_;
}
string WordOccurrence::getWord() const{
    return word_;
}
int WordOccurrence::getNum() const{
    return num_;
}
//WordList
//Class
//Definitions
//Copy Constructor
WordList::WordList(const WordList& copy){
    //sets the size to the size of the wordList --- then makes a new array of that size
    //copies the elements from the old array to the new one
    size_ = copy.size_;
    wordArray_ = new WordOccurrence[size_];
    for(int i = 0; i < copy.size_; ++i)
        wordArray_[i] = copy.wordArray_[i];
}
//Destructor
WordList::~WordList(){
    delete [] wordArray_;
}
//Assignment Operator
WordList& WordList::operator=(const WordList rhs){
    //if words are the same, returns left sided word
    if(this == &rhs) return *this;
    //if the word array is null, deallocate memory
    if(wordArray_ != nullptr) delete [] wordArray_; // probably redundant with a destructor
    //sets the size to the size of the wordList array -- then makes a new array of that size
    //similar to copy constructor -- copies the elements from the old array to the new one
    size_ = rhs.size_;
    wordArray_ = new WordOccurrence[size_];
    //by definition: Overloading assignment operator in C++ copies all values of one object to another object so i did that the hard way
    for(int i = 0; i < size_; ++i) {
        wordArray_[i] = rhs.wordArray_[i];
    }
    //returns the new, copied object
    return *this;
    //although there are multiple if statements based on format some may or may not be reached if clause applies, 'cause return...
    // sort(wordArray_, wordArray_ + size_);
}
// void WordList::addWord(const string& rhs){
//     if(o != nullptr){
//         o->increment();
//         return;
//     }
//     size_ = size_ + 1;
//     WordList temp(size_);
//     for(int i = 0; i < temp.size_-1; ++i)
//         temp.wordArray_[i] = wordArray_[i];
//     temp.wordArray_[size_-1] = rhs;
//     delete [] wordArray_;
//     wordArray_ = new WordOccurrence[size_];
//     for(int i = 0; i < temp.size_; ++i)
//         wordArray_[i] = temp.wordArray_[i];
// }
void WordList::addWord(const std::string& rhs){
    //loops through array to find word, if found increment
    for(int i = 0; i < size_; ++i){
        if(wordArray_[i].matchWord(rhs)){
            wordArray_[i].increment();
            return;
        }
    }
    //if word isnt in array, add it and increase size of array
    WordOccurrence *newerArr = new WordOccurrence[size_+1];
    for(int i = 0; i < size_; ++i){
        newerArr[i] = wordArray_[i];
    }
    newerArr[size_] = rhs;
    size_ += 1;
    //adds the contents of wordArray to a new word array. Then deallocates the old array
    delete[] wordArray_;
    wordArray_ = newerArr;
}
void WordList::print(){
    for(int i = 0; i < size_; ++i){
        cout << wordArray_[i].getWord() << " " <<  wordArray_[i].getNum() << std::endl;
    }
}
void WordList::sorterer(){
    //standard inertion sort
    for (int i = 1; i < size_; ++i) {
            WordOccurrence key = wordArray_[i];
            int j = i - 1;

        /* Move elements of wordArray_[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && (wordArray_[j].getNum() > key.getNum() || 
        ((wordArray_[j].getNum() == key.getNum()) && (wordArray_[j].getWord() > key.getWord())))
        ) {
            wordArray_[j + 1] = wordArray_[j];
            j = j - 1;
        }
        wordArray_[j + 1] = key;
    
    }
}
bool equal(const WordList& lhs, const WordList& rhs){
    // checks to see if both wordlists and frequency are exactly the same.  
    if(lhs.size_ != rhs.size_) return false;
    for(int i = 0; i < lhs.size_; ++i) {
    // if anything is different, return false
    if(lhs.wordArray_[i].getWord() != rhs.wordArray_[i].getWord() || lhs.wordArray_[i].getNum() != rhs.wordArray_[i].getNum())
        return false;
  }
  // if everything is the same, return true
  return true;
}
