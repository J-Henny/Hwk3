#ifndef CSCI2421_PREFIXNODE_H
#define CSCI2421_PREFIXNODE_H

#include "iostream"
#include "memory"
#include "string"

using namespace std;

class PrefixNode {
private:
    static const int ALPHABET_SIZE = 26;

    shared_ptr<PrefixNode> children[ALPHABET_SIZE];
    int childCount;

    char character;
    bool isTerminalNode;

    /**
     * Recursively prints to the output stream.
     * @param out
     * @param prefix
     */
    void print(ostream& out, string prefix) const ;

public:
    explicit PrefixNode();
    explicit PrefixNode(const char& aCharacter);

    char getCharacter() const;

    bool isTerminal() const;
    void setIsTerminal(bool isTerminalState= true);

    /**
     * Check if the character is already a child. If so, return that pointer, otherwise, creates the node and returns.
     * @param character
     * @return
     */
    shared_ptr<PrefixNode> addChild(const char& aCharacter);

    /**
     * Returns the pointer to the node of the aChar if exists.
     * @param aChar
     * @return a pointer to the node containing the aChar.
     * @throws logic_error if there's no node for the aChar.
     */
    shared_ptr<PrefixNode> getChild(const char& aChar) const noexcept(false);


    friend ostream& operator<<(ostream& out, const PrefixNode& node);

};
#include "PrefixNode.cpp"


#endif //CSCI2421_PREFIXNODE_H
