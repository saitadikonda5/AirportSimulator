//
//  ECConsoleUIListBox.h
//  
//
//  Created by Yufeng Wu on 5/23/23.
//

#ifndef ECConsoleUIListBox_h
#define ECConsoleUIListBox_h

#include <string>
#include <vector>

#include "ECConsoleUIItem.h"

//*****************************************************************************
// Console UI list box: several rows (items) to choose from

class ECConsoleUIListBox : public ECConsoleUIItem
{
public:
    // specifiy the portion of the view for this list box
    ECConsoleUIListBox(int xUL, int yUL, int xLR, int yLR );
    
    // Add a choice item
    void AddChoice(const std::string &text);
    
    // Choose an item
    void Choose(int rIndex);
    
    // Get the chosen one
    int GetChoice() const { return indexChoice; }
    
    // Get displayed text at a specific row
    // Text is relative to the item portion (i.e., relative to (xLR, yLR))
    virtual std::string GetTextAtRow(int r) const;
    
    // Get highlighted part (if any); return the row with highlight
    // if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
    // Assume: at most a single row with highlighted part
    virtual int GetHighlightPosition(int &xLeft, int &xRight) const;

    // Are there any other function you might need to override?
    // Override IsHandlingKeys() to indicate that this class handles keys
    virtual bool IsHandlingKeys() const override { return true; }

    virtual void HdlKeyUp() override
    {
        if (indexChoice > 0) {
        indexChoice--;
        if (indexChoice < first) {
            first = indexChoice;
        }
    }
    }
    
        
    virtual void HdlKeyDown() override 
    {
        if (indexChoice < choices.size() - 1) {
        indexChoice++;
        if (indexChoice >= first + itemCount) {
            first = indexChoice - itemCount + 1;
        }
        }
    }

    int GetNumItems() const { return itemCount; }

    std::string GetChoiceText(int choiceIndex) const;

    void ClearChoices() {
        choices.clear();
        indexChoice = -1;
    }
    
private:
    std::vector<std::string> choices;
    int indexChoice;
    int first;
    int itemCount;
};

#endif /* ECConsoleUIListBox_h */
