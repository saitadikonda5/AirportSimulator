//
//  ECConsoleUITextField.cpp
//  
//
//  Created by Yufeng Wu on 5/24/23.
//

#include "ECConsoleUITextField.h"
#include "ECTextViewImp.h"
#include "ECConsoleUIItem.h"

using namespace std;

#include "ECConsoleUITextField.h"
#include "ECTextViewImp.h"

ECConsoleUITextField::ECConsoleUITextField(ECTextViewImp *pTextView, int xpos, int ypos, int len)
    : ECConsoleUIItem(xpos, ypos, xpos + len - 1, ypos), textView(pTextView), xpos(xpos), ypos(ypos), length(len) {}


std::string ECConsoleUITextField::GetTextAtRow(int r) const {

    std::string rowString(textView->GetRow(ypos + r));
    return rowString.substr(xpos, length);
}


int ECConsoleUITextField::GetHighlightPosition(int &xLeft, int &xRight) const {
    // Check if the text field is being edited
    if (textView->IsEditing() && textView->GetCursorY() == ypos) {
        std::string textField = textView->GetRow(ypos);
        xLeft = xpos;
        xRight = xpos + textField.length() - 1;
        return ypos;
    }
    
    return -1;
}