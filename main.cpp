#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "AVLTree.cpp"
#include<bits/stdc++.h>

/****************************************************************************************************/
/* Programmer: Inna Yedzinovich                                                                     */
/* Date: 10/23/2017                                                                                 */
/* Purpose: Analyze .txt file and generate a .txt report with a statistics and warnings in the text */
/* Professor: Anna Salvati                                                                          */
/****************************************************************************************************/

//************************** main program ************************/
/*int main() {

    std::string text("C:\\Users\\Inna\\Desktop\\C++\\Tree Project\\example.txt");
    int totalNumOfWords = 0 ;            //int counter for total number of words on the text
    int numOfUniqueWords = 0;            //int counter for total number of unique words on the text
    int numUpToTreeLetters = 0;          //int counter for unique words with up to tree letters
    int avgWords = 0;                    //int counter for average words length
    int avgSentence = 0;                 //int counter for average sentence length
    int totalSentence = 0;               //int counter for total number of sentences
    std::string word;                    //string variable for word
    std::stack<std::string> upToTree;    //stack data structure as a temporary container for unique words with up to tree letters
    int countLetters = 0;                //int counter for number of letters in the word
    std::queue<std::string> myQueue;     //queue data structure as a container for all the data in the tree
    AVLTree<std::string> tree;           //object of the AVLTree
    std::string str;

    std::ifstream myfile(text);          //ifstream opens the .txt file with given as a string parameter name

    if(myfile.is_open()) {
        while (myfile >> word) {

            std::transform(word.begin(), word.end(), word.begin(), ::tolower);

            countLetters+=word.size();

            if (word.back() == '!' || word.back() == '?' || word.back() == '.')
                totalSentence++;

            while (ispunct(word.back()))
                word.pop_back();

            while(ispunct(word.front()))
                word.erase(0,1);

            totalNumOfWords++;
            tree.insertItem(word);

        }
        myfile.close();

    }
    else std::cout << "Unable to open file"<<"\n";

    avgSentence = totalNumOfWords/totalSentence;
    avgWords = countLetters/totalNumOfWords;
    numOfUniqueWords = tree.nodeCount();

    tree.inorder(myQueue);

    while(!myQueue.empty()){
        if(myQueue.front().size()>3) {
            numUpToTreeLetters++;
            str = myQueue.front();
            upToTree.push(str);
        }
        myQueue.pop();

    }

    std::ofstream output;
    output.open("C:\\Users\\Inna\\Desktop\\C++\\Tree Project\\report.txt");

    output<<"FILE NAME: "<<"report.txt"<<"\n";
    output<<"\t\t\t\tSTATISTICAL SUMMARY"<<"\n\n";

    output<< "\nTOTAL NUMBER OF SENTENCES " << totalSentence
          << "\nTOTAL NUMBER OF WORDS: " << totalNumOfWords
          << "\nTOTAL NUMBER OF “UNIQUE” WORDS: " << numOfUniqueWords
          << "\nTOTAL NUMBER OF “UNIQUE” WORDS OF MORE THAN THREE LETTERS: " << numUpToTreeLetters
          << "\nAVERAGE SENTENCE LENGTH: " << avgSentence<<" words"
          <<"\nAVERAGE WORD LENGTH: " << avgWords<< " characters ";
    output<<std::endl<<std::endl;

    output<<"\t\t\t\tSTLE WARNINGS\n\n";
    output<<"WORDS USED TOO OFTEN: "
            "(WORDS OF MORE THAN 3 LETTERS THAT ARE USED MORE THAN 5% "
            "OF THE TOTAL NUMBER OF WORDS OF MORE THAN 3 LETTERS )\n\n";

    short count = 1;    //counter to display the order of too often used words

    while(!upToTree.empty()){
        if(tree.getCount(upToTree.top())*numUpToTreeLetters/100>5)
            output<<"\t"<<count++<<") "<<upToTree.top()<<"\n";
        upToTree.pop();
    }

    output<<std::endl;
    if(avgSentence>10)
        output<<"AVERAGE SENTENCE LENGTH TOO LONG - "<<avgSentence<<" words\n";
    if(avgWords>5)
        output<<"AVERAGE WORD LENGTH TOO LONG - "<<avgWords<<" characters\n";

    char ch = 'A';      //character variable to hold fist character of the word
    tree.inorder(myQueue);

    while(!myQueue.empty()){

        str = myQueue.front();

        if(ch!=str.at(0)) {
            ch = str.at(0);
            output<<"\n  "<<(char)::toupper(str.at(0))<<"\n";
            output<<"--------"<<"\n";
        }
        output<<myQueue.front()<<"\n";
        myQueue.pop();
    }
    output.close();



}
 */