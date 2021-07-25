
/**********************************************************************************************************************/
PrefixTree::PrefixTree() : rootPtr(make_shared<PrefixNode>()) {};

/**********************************************************************************************************************/
void PrefixTree::add(const string &aWord) {
    /**
     * TODO: add public call
     * uses recursion (see add below)
     */
    add(this->rootPtr, aWord);

}

/**********************************************************************************************************************/
void PrefixTree::add(const shared_ptr<PrefixNode>& ptr, const string &aWord) {
    /**
     * TODO: add (private)
     * recursive call adding the first char of the word, and recursive call with the reminders.
     * Checkout chapter 2 to display word using recursion.
     * Hint: base case len ==1 then the child node is terminal!
     */
     if(aWord.length() == 0) { /** Base case. */
         ptr->setIsTerminal(true);
         return;
     }
     ptr->addChild(aWord[0]); /** If not add character as a child. */
     add(ptr->getChild(aWord[0]), aWord.substr(1)); /** Recursive call. */



}


/**********************************************************************************************************************/
bool PrefixTree::isWordInTree(const string &aWord) const {

    /**
     * TODO: isWordInTree
     * iteratively check if the word is in the tree.
     * hint: check character by character as a sequence of chars. also remember that the word is in the tree
     * if once found the word, the last character node is terminal.
     * E.g., if M-A-N-Y with Y terminal is the only one in the tree, MAN is not in the tree as N is not terminal.
     */


    int i;
    bool isTerminal = false;
    try{ /** Since getChild throws an error when it reaches the end of the word we want to catch it. */
        shared_ptr<PrefixNode> curNode = rootPtr->getChild(aWord[0]); /** Gets the first letter */
        for(i = 0; i < aWord.length(); i++){ /** Sequencing character by character */
            if(curNode->isTerminal())
                isTerminal = true;
            if(aWord[i] == curNode->getCharacter())
                curNode = curNode->getChild(aWord[i + 1]); /** Going to next character in word. */
        }
    }
    catch(logic_error& le){ /** Catching the error when we have reached a leaf */
        if(isTerminal && i == aWord.length() - 1) /** i will let us know we've made the correct amount of iterations */
            return true;
        else
            return false;
    }

}

/**********************************************************************************************************************/
ostream& operator<<(ostream& out, const PrefixTree& tree) {
    out << *tree.rootPtr ;
    return out;
}

