#include "iostream"
#include "string"
#include "PrefixTree.h"

using namespace std;

/**
 * Testing Program. Not required for the homework.
 * @return
 */
int main(){



    shared_ptr<PrefixTree> treePtr = make_shared<PrefixTree>();

    string words[] = {"HABITAT", "HABIT", "HABITUAL", "HABITUATE", "HOUSE", "HORSE", "WEEKEND",  "WEEK"};
    string notWords[] = {"HABI","HABITATION", "WEEKLY", "DAY"};

    for (const string& word: words) {
        cout<< "Adding " << word << endl;
        treePtr->add(word);
    }

    cout <<endl <<" **************** Check For Words in Tree ****************"<<endl;
    for (const string& word: words) {
        cout << "Checking " << word << " is in the tree ? " << boolalpha << treePtr->isWordInTree(word) << endl;
    }

    cout <<endl <<" **************** Check For Words NOT IN Tree ****************"<<endl;
    for (const string& word: notWords) {
        cout << "Checking " << word << " is in the tree ? " << boolalpha << treePtr->isWordInTree(word) << endl;
    }

    cout <<endl <<" **************** WORDS IN TREE ****************"<<endl;
    cout<< *treePtr <<endl;


    return 0;
}

/** EXPECTED OUTPUT after implementing:

Adding HABITAT
Adding HABIT
Adding HABITUAL
Adding HABITUATE
Adding HOUSE
Adding HORSE
Adding WEEKEND
Adding WEEK

 **************** Check For Words in Tree ****************
Checking HABITAT is in the tree ? true
Checking HABIT is in the tree ? true
Checking HABITUAL is in the tree ? true
Checking HABITUATE is in the tree ? true
Checking HOUSE is in the tree ? true
Checking HORSE is in the tree ? true
Checking WEEKEND is in the tree ? true
Checking WEEK is in the tree ? true

 **************** Check For Words NOT IN Tree ****************
Checking HABI is in the tree ? false
Checking HABITATION is in the tree ? false
Checking WEEKLY is in the tree ? false
Checking DAY is in the tree ? false

 **************** WORDS IN TREE ****************
HABIT
HABITAT
HABITUAL
HABITUATE
HOUSE
HORSE
WEEK
WEEKEND

 */