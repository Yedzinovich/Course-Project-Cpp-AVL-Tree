
/***********************************************************************************************/
/* Programmer: Inna Yedzinovich                                                                */
/* Date: 10/23/2017                                                                            */
/* Purpose: This class performs analysis of the text and display its statistics information    */
/*          inside .txt file called 'report.txt'                                               */
/* Professor: Anna Salvati                                                                     */
/***********************************************************************************************/

#ifndef UNTITLED_TEXTANALYSIS_H
#define UNTITLED_TEXTANALYSIS_H

#include "AVLTree.cpp"
#include <iostream>

//template <class T>
class TextAnalysis {
private:
    int totalNumOfWords = 0 ;
    int numOfUniqueWords = 0;
    int numUpToTreeLetters = 0;
    int avgWords = 0;
    int avgSentence = 0;
    int totalSentence = 0;
    std::string text;
    std::string word;
    std::stack<std::string> upToTree;
    int countLetters = 0;
    std::queue<std::string> myQueue;

public:
    AVLTree<std::string> tree;
    void setText(std::string);
    void statistics();
    void generateTxtReport();



};


#endif
