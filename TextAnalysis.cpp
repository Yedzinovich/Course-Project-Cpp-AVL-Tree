
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include<bits/stdc++.h>
#include "TextAnalysis.h"

//template <class T>
void TextAnalysis::setText(std::string text) {
    this->text = text;
}

//template <class T>
void TextAnalysis::statistics() {

    std::ifstream myfile(text);

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
        std::string str;

        while(!myQueue.empty()){
            if(myQueue.front().size()>3) {
                numUpToTreeLetters++;
                str = myQueue.front();
                upToTree.push(str);
            }
            myQueue.pop();

        }
    generateTxtReport();

}

//template <class T>
void TextAnalysis::generateTxtReport() {

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

    int count = 1;

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


    char ch = 'A';
    std::string str;
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


















