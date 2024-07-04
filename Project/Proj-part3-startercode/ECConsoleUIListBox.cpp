//
//  ECConsoleUIListBox.cpp
//  
//
//  Created by Yufeng Wu on 5/23/23.
//

#include "ECConsoleUIListBox.h"
#include "ECConsoleUIItem.h"
#include <iostream>


// Constructor
ECConsoleUIListBox::ECConsoleUIListBox(int xUL, int yUL, int xLR, int yLR)
    : ECConsoleUIItem(xUL, yUL, xLR, yLR), indexChoice(0) {}

// Add a choice item
void ECConsoleUIListBox::AddChoice(const std::string &text)
{
    choices.push_back(text);
}

// Choose an item
void ECConsoleUIListBox::Choose(int rIndex)
{
    if (rIndex >= 0 && rIndex < choices.size())
    {
        indexChoice = rIndex;
    }
}

// Get displayed text at a specific row
std::string ECConsoleUIListBox::GetTextAtRow(int r) const
{
    if (r <= GetYLR() && r>= GetYUL()){
        int choiceIndex = r - GetYUL() + first;
        if (choiceIndex >= 0 && choiceIndex < choices.size())
        {
            return choices[choiceIndex];
        }
        return "";
        }

        
    return "";
}

// return the row with highlight
int ECConsoleUIListBox::GetHighlightPosition(int &xLeft, int &xRight) const
{
    int highlightIndex = indexChoice - first;

    if (highlightIndex >= 0 && highlightIndex < itemCount)
    {
        xLeft = GetXUL();
        xRight = GetXLR();
        return highlightIndex;
    }

    return -1;
}


std::string ECConsoleUIListBox::GetChoiceText(int choiceIndex) const
{
    // Check if the choice index is within the bounds of the choices vector
    if (choiceIndex >= 0 && choiceIndex < choices.size())
    {
        // Return the text of the choice at the given index
        return choices[choiceIndex];
    }
    
    // Return an empty string if the choice index is out of bounds
    return "";
}