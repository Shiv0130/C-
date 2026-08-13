//#include <iostream>

//using namespace std;

//int main()
//{
    //cout << "Hello world!" << endl;
  //  return 0;
//}

//1.
/*#include <iostream>
#include <queue>

using namespace std;

class queueType {
public:
    void addQueue(int value) {
        q.push(value);
    }
    void deleteQueue() {
        if (!q.empty()) q.pop();
    }
    int front() {
        return q.front();
    }
    bool isEmptyQueue() {
        return q.empty();
    }

private:
    queue<int> q;
};

int main() {
    queueType queue;
    int x, y;
    x = 4; y = 5;
    queue.addQueue(x);
    queue.addQueue(y);
    x = queue.front();
    queue.deleteQueue();
    queue.addQueue(x + 5);  // Adds 9
    queue.addQueue(16);
    queue.addQueue(x);       // Adds 4
    queue.addQueue(y - 3);   // Adds 2

    cout << "Queue Elements: ";
    while (!queue.isEmptyQueue()) {
        cout << queue.front() << " ";
        queue.deleteQueue();
    }
    cout << endl;

    return 0;
}*/

//2.
/*#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class stackType {
public:
    void push(int value) {
        s.push(value);
    }
    void pop() {
        if (!s.empty()) s.pop();
    }
    int top() {
        return s.top();
    }
    bool isEmptyStack() {
        return s.empty();
    }

private:
    stack<int> s;
};

class queueType {
public:
    void addQueue(int value) {
        q.push(value);
    }
    void deleteQueue() {
        if (!q.empty()) q.pop();
    }
    int front() {
        return q.front();
    }
    bool isEmptyQueue() {
        return q.empty();
    }

private:
    queue<int> q;
};

int main() {
    stackType stack;
    queueType queue;
    int x;

    stack.push(0);
    queue.addQueue(0);
    cin >> x; // Assume input: 15 28 14 22 64 35 19 32 7 11 13 30 -999

    while (x != -999) {
        switch (x % 4) {
            case 0:
                stack.push(x);
                break;
            case 1:
                if (!stack.isEmptyStack()) {
                    cout << "Stack Element = " << stack.top() << endl;
                    stack.pop();
                } else {
                    cout << "Sorry, the stack is empty." << endl;
                }
                break;
            case 2:
                queue.addQueue(x);
                break;
            case 3:
                if (!queue.isEmptyQueue()) {
                    cout << "Queue Element = " << queue.front() << endl;
                    queue.deleteQueue();
                } else {
                    cout << "Sorry, the queue is empty." << endl;
                }
                break;
        }
        cin >> x;
    }

    cout << "Stack Elements: ";
    while (!stack.isEmptyStack()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;

    cout << "Queue Elements: ";
    while (!queue.isEmptyQueue()) {
        cout << queue.front() << " ";
        queue.deleteQueue();
    }
    cout << endl;

    return 0;
}*/

//5.
/*#include <iostream>
#include <queue>

using namespace std;

class linkedQueueType {
public:
    void addQueue(int value) {
        q.push(value);
    }
    void deleteQueue() {
        if (!q.empty()) q.pop();
    }
    int front() {
        return q.front();
    }
    int back() {
        return q.back();
    }
    bool isEmptyQueue() {
        return q.empty();
    }

private:
    queue<int> q;
};

int main() {
    linkedQueueType queue;
    queue.addQueue(10);
    queue.addQueue(20);
    cout << queue.front() << endl;  // Outputs: 10
    queue.deleteQueue();
    queue.addQueue(2 * queue.back()); // Adds 40
    queue.addQueue(queue.front());     // Adds 20
    queue.addQueue(5);                 // Adds 5
    queue.addQueue(queue.back() - 2); // Adds 18

    linkedQueueType tempQueue = queue;
    while (!tempQueue.isEmptyQueue()) {
        cout << tempQueue.front() << " ";
        tempQueue.deleteQueue();
    }
    cout << endl;

    cout << queue.front() << " " << queue.back() << endl; // Outputs: 20 18

    return 0;
}*/

//12.
/*#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
void reverseQueue(queue<T>& q) {
    stack<T> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}*/

//13.
/*#include <iostream>
#include <queue>

using namespace std;

class queueType {
public:
    void addQueue(int value) {
        q.push(value);
    }
    void deleteQueue() {
        if (!q.empty()) q.pop();
    }
    int queueCount() {
        return q.size();
    }
    bool isEmptyQueue() {
        return q.empty();
    }

private:
    queue<int> q;
};*/




