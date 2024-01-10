#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"
#include "Cpplib.h"

using namespace std;

int main() {
    // Create a stack of stashes
    Stack stashStack;

    // Open input file
    ifstream inputFile("input.txt");

    // Read lines from input file and store in stashes
    string line;
    Stash* currentStash = new Stash;
    currentStash->initialize(sizeof(string));
    while (getline(inputFile, line)) {
        currentStash->add(&line);
        if (currentStash->count() == 5) {
            stashStack.push(currentStash);
            currentStash = new Stash;
            currentStash->initialize(sizeof(string));
        }
    }
    if (currentStash->count() > 0) {
        stashStack.push(currentStash);
    }

    // Print lines in original order by popping stashes from stack
    while (!stashStack.isEmpty()) {
        Stash* stash = (Stash*)stashStack.pop();
        for (int i = 0; i < stash->count(); i++) {
            cout << *(string*)stash->fetch(i) << endl;
        }
        stash->cleanup();
        delete stash;
    }

    // Close input file
    inputFile.close();

    return 0;
}
