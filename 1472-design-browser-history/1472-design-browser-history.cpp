class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string s) {
        url = s;
        prev = next = nullptr;
    }
};

class BrowserHistory {
    Node* current;

public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);

        current->next = nullptr;   // remove forward history
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    string back(int steps) {
        while (steps-- && current->prev != nullptr)
            current = current->prev;

        return current->url;
    }

    string forward(int steps) {
        while (steps-- && current->next != nullptr)
            current = current->next;

        return current->url;
    }
};