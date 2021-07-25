///**********************************************************************************************************************/
PrefixNode::PrefixNode() : PrefixNode('\0') {}

/**********************************************************************************************************************/
PrefixNode::PrefixNode(const char &aCharacter) : childCount(0), isTerminalNode(false), character(aCharacter) {}

/**********************************************************************************************************************/
bool PrefixNode::isTerminal() const {
    return this->isTerminalNode;

}

/**********************************************************************************************************************/
void PrefixNode::setIsTerminal(bool isTerminalState) {
    this->isTerminalNode = isTerminalState;
}

/**********************************************************************************************************************/
char PrefixNode::getCharacter() const {
    return this->character;
}

/**********************************************************************************************************************/
shared_ptr<PrefixNode> PrefixNode::addChild(const char& aCharacter) {
    /**
     * TODO: addChild
     * if child with the character does not exists, creates a new node for it and add it to the children
     */
     for(int i = 0; i < this->childCount; i++) {
         if(this->children[i]->getCharacter() == aCharacter){ /** If we find a match */
             return this->children[i];
         }
     }

     /** If we never found a match */
     shared_ptr<PrefixNode> newChild = make_shared<PrefixNode>(aCharacter); /** Creating child */
     this->childCount++;
     this->children[childCount - 1] = newChild; /** Placing child in next spot over. */
     return newChild;

}

/**********************************************************************************************************************/
shared_ptr<PrefixNode> PrefixNode::getChild(const char &aChar) const noexcept(false) {
    /**
     * TODO: getChild
     * returns the child node (1st level) with that character.
     * if not exists throws logic_error
     */
    for(int i = 0; i < this->childCount; i++)
    {
        if(this->children[i]->getCharacter() == aChar)
            return this->children[i];
    }
    throw logic_error("getChild() called with no existing child."); /** Throws error if we never found */

}

/**********************************************************************************************************************/
ostream& operator<<(ostream& out, const PrefixNode& node){
    node.print(out, "");
    return out;
}

/**********************************************************************************************************************/
void PrefixNode::print(ostream& out, string inPrefix) const {
    string prefix = inPrefix;
    if (this->character != '\0')
        prefix += this->character;

    if (this->isTerminalNode)
        out<< prefix <<endl;

    for (int i = 0; i < this->childCount; i++)
        this->children[i]->print(out, prefix);
}