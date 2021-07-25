#ifndef CSCI2421_PREFIXTREE_H
#define CSCI2421_PREFIXTREE_H

#include "iostream"
#include "memory"
#include "PrefixNode.h"

class PrefixTree {
private:
    shared_ptr<PrefixNode> rootPtr;
    /**
     * Adds the word recursively adding one char at a time.
     * @param ptr
     * @param aWord
     */
    void add(const shared_ptr<PrefixNode>& ptr, const string& aWord);

public:
    explicit PrefixTree();

    /**
     * Adds the word to the tree, creating missing nodes.
     * @param aWord
     */
    void add(const string& aWord);

    /**
     * @param aWord
     * @return True if the word is stored in the tree. false otherwise.
     */
    bool isWordInTree(const string& aWord) const;

    /**
     * Prints all the words. Uses Node output operator.
     * @param out
     * @param tree
     * @return
     */
    friend ostream& operator<<(ostream& out, const PrefixTree& tree) ;

};

#include "PrefixTree.cpp"

#endif //CSCI2421_PREFIXTREE_H
