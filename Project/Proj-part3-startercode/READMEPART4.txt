To run my code, I was in the Proj-part3-startercode directory. This folder is in a larger Project folder that additionally contains 
the folder Proj-part1-startercode. I used this command:

    g++ -std=c++11 \
    ECConsoleUITextLabel.cpp \
    ECTextViewImp.cpp \
    ECConsoleUIView.cpp \
    ECConsoleUIListBox.cpp \
    ECConsoleUITextField.cpp \
    ECConsoleUiButton.cpp \
    ../Proj-part1-startercode/ECAirlineSimulator.cpp \
    ../Proj-part1-startercode/ECFlightItinerary.cpp \
    ../Proj-part1-startercode/ECAirport.cpp \
    ../Proj-part1-startercode/ECAirlineFinancial.cpp \
    ../Proj-part1-startercode/ECAirlineOperation.cpp \
    ../Proj-part1-startercode/ECAirlineTicketing.cpp \
    ../Proj-part1-startercode/ECFlight.cpp \
    -o test

And to run the executable, use the command:     ./test input.txt

Running the code, there is complete functionality in my UI. Some aspects of how it looks are slightly off but it is still full functional in
every way. Some issues with the application are that in the source and destination listboxes the same airport shows up twice sometimes, and also
rather than having a second button to display every flight available, I just had this information always available as it does not change. Other
than this, everything else works as intended and the search for flights button correctly takes in the inputs from the list boxes and displays
itineraries. To help me debug this, I alos include what the search button is doing in each attmempt in an output file called flight_search.txt,
just to make it clearer what the inputs and output itineraries were. I didnt comment this code out, as it makes it clearer when running the
application what is being done (but its not neccessary at all to actually look at this output file still)

Screenshots are included in the gradescope submission

Video link: https://youtu.be/yeGOJ1ZWyvY
