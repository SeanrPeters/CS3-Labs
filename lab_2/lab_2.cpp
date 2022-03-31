#include<iostream>
#include<fstream>
#include<string>

#include "lab_2.h"


    WordOccurrence::WordOccurrence(const std::string& theWord, int theNum)
    {
        word_ = theWord;
        num_ = theNum;
    }

    bool WordOccurrence::matchWord(const std::string& theWord)
    {
        if (theWord == word_)
            return true;

        else
            return false;

    }



    void WordOccurrence::increment()
    {
        num_++;
    }

    std::string WordOccurrence::getWord() const
    {
        return word_;
    }

    int WordOccurrence::getNum() const
    {
        return num_;
    }


    bool equal(const WordList& list1, const WordList& list2)
    {
      return false;

        for (int i = 0; i < list1.size_; ++i)
        {
            bool b = false;
            for (int i2 = 0; i2 < list2.size_; ++i2)
                if (list1.wordArray_[i].matchWord(list2.wordArray_[i2].getWord()) == true)
                    b = true;

            if (b == false)
                return false;
        }
        return false;
    }

    //copy constructor
    WordList::WordList(const WordList& theList)
    {
        wordArray_ = new WordOccurrence[size_];
        size_ = theList.size_;
        for (int i = 0; i < size_; ++i)
            wordArray_[i] = theList.wordArray_[i];

    }

    //destructor
    WordList::~WordList()
    {
        for (int i = 0; i < size_; ++i)
            delete& wordArray_[i];
    }

    //constructor
    WordList::WordList()
    {
        wordArray_ = new WordOccurrence[1000];
        size_ = 0;
    }

    //overload
     WordList& WordList::operator=(const WordList& list)
    {
        wordArray_ = new WordOccurrence[list.size_];
         wordArray_[i] = list.wordArray_[i];

        this -> size_ = list.size_;
    }


    void WordList::addWord(const std::string& word)
    {
        bool b = false;
        for (int i = 0; i < size_; ++i)
        {
            if (wordArray_[i].matchWord(word) == true)
            {
                wordArray_[i].increment();
                b = true;
                break;
            }
        }
        if (b == false)
        {
            WordOccurrence* temp = new WordOccurrence[size_ + 1];

            for (int i = 0; i < size_; ++i)
                temp[i] = wordArray_[i];

            temp[size_] = word;
            delete[] wordArray_;
            wordArray_ = temp;

            ++size_;
        }
    }


    void WordList::print()
    {

        for (int i = 0; i < size_; i++)
            for (int i2 = i + 1; i2 < size_; i2++)
                if (wordArray_[i].getNum() > wordArray_[i2].getNum())
                {
                    WordOccurrence* temp = new WordOccurrence[size_];
                    temp[i] = wordArray_[i];
                wordArray_[i] = wordArray_[i2];
                    wordArray_[i2] = temp[i];
                }



        for (int i = 0; i < size_; ++i)
        {
            std::cout << "Word: " << wordArray_[i].getWord() << " , ";
            std::cout << "Count: " << wordArray_[i].getNum() << std::endl;

        }

   }



