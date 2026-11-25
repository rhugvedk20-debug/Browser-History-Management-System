#include <iostream>
#include <string>
using namespace std;

class PageStack {
private:
    string pages[5];  // Stack can hold five page names
    int top = -1;     // -1 means the stack is empty

public:
    bool push(string page) {
        if (top == 4) {
            cout << "The stack is full." << endl;
            return false;
        }

        top++;
        pages[top] = page;
        return true;
    }

    void pop() {
        if (isEmpty()) {
            cout << "The stack is empty." << endl;
            return;
        }

        top--;
    }

    string peek() {
        if (isEmpty()) {
            return "";
        }

        return pages[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void show() {
        if (isEmpty()) {
            cout << "  (empty)" << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << "  " << pages[i] << endl;
        }
    }
};

int main() {
    PageStack backHistory;
    PageStack forwardHistory;
    string currentPage = "Home";
    int choice;

    while (true) {
        cout << "\nCurrent page: " << currentPage << endl;
        cout << "1. Visit a new page" << endl;
        cout << "2. Go back" << endl;
        cout << "3. Go forward" << endl;
        cout << "4. Show history" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";

        if (!(cin >> choice)) {
            cout << "Please enter a number." << endl;
            break;
        }

        if (choice == 1) {
            string newPage;
            cout << "Enter page name: ";
            cin >> newPage;

            // Save the current page first. Change pages only if it fits.
            if (backHistory.push(currentPage)) {
                currentPage = newPage;

                // A new visit clears the old Forward history.
                while (!forwardHistory.isEmpty()) {
                    forwardHistory.pop();
                }
            }
        }
        else if (choice == 2) {
            if (backHistory.isEmpty()) {
                cout << "There is no page to go back to." << endl;
            } else {
                forwardHistory.push(currentPage);
                currentPage = backHistory.peek();
                backHistory.pop();
            }
        }
        else if (choice == 3) {
            if (forwardHistory.isEmpty()) {
                cout << "There is no page to go forward to." << endl;
            } else {
                backHistory.push(currentPage);
                currentPage = forwardHistory.peek();
                forwardHistory.pop();
            }
        }
        else if (choice == 4) {
            cout << "\nBack history (newest first):" << endl;
            backHistory.show();

            cout << "Forward history (next page first):" << endl;
            forwardHistory.show();
        }
        else if (choice == 5) {
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Please choose 1, 2, 3, 4, or 5." << endl;
        }
    }

    return 0;
}