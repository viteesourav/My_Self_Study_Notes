#include <bits/stdc++.h>
using namespace std;

void arrarySTL()
{
    // arrays STL
    array<int, 4> a = {1, 2, 3, 4}; // same implementation of int ar[4] = {1,2,3,4}
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << a.at(2) << endl;   // O(1)
    cout << a.empty() << endl; // O(1)
    cout << a.front() << endl; // O(1)
    cout << a.back() << endl;  // O(1)
}

void vectorSTL()
{

    vector<int> v; // capacity->0
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << v.capacity() << endl; // It shows total space available.
    cout << v.size() << endl;     // shows the no of element present.

    cout << v.at(1) << " " << v[1] << endl; // use of both are allowed.
    cout << v.front() << " " << v.back() << endl;

    v.pop_back();
    cout << v.back() << endl;

    for (int i : v)
    { // example of foreach loop
        cout << i << " ";
    }
    cout << endl;

    v.clear(); // reset size = 0

    // Ways to intialize:
    vector<int> a(5, 1); // size -> 5 and all elements 1. 2nd is optional, dy default 0.

    vector<int> copyV(a); // copy vector a.

    //Other ways to define vectors...
    vector<int> v1 = {1,2,3,4,5,6,7};
    vector<vector<int>> v2 = {{1,2}, {2,3}, {4,5}};
    vector<vector<int>> v3 (3, vector<int>(2, 0)); //[[0,0], [0,0], [0,0]]

    for (int i : a)
        cout << i << " ";
    cout << endl;
}

void dequeSTL()
{

    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(8);
    dq.push_front(3);
    dq.push_front(4);
    dq.push_front(5);

    dq.pop_back();  // remove from back
    dq.pop_front(); // remove from front.

    for (int i : dq)
        cout << i << " ";
    cout << endl;

    cout << dq.at(0) << " " << dq[0] << endl;
    cout << dq.front() << " " << dq.back() << endl;
    cout << dq.empty() << endl;

    // removing the First element...
    dq.erase(dq.begin(), dq.begin() + 1); // takes start and end index

    for (int i : dq)
        cout << i << " ";
    cout << endl;

    // to Clear all elements
    dq.clear();
    cout << dq.size() << endl;
}

void listSTL()
{

    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    l.push_front(4);
    l.pop_back();  // remove from back
    l.pop_front(); // remove from front
    cout << l.size() << endl;
    for (int i : l)
        cout << i << " ";
    cout << endl;
    cout << l.front() << " " << l.back() << endl;
    cout << l.empty() << endl;

    // erasing the first element, TC: O(n)
    l.erase(l.begin()); // takes an iterator..
    for (int i : l)
        cout << i << " ";
    cout << endl;

    // copying a list..
    list<int> l1(l);
    for (int i : l1)
        cout << i << " ";
    cout << endl;

    list<int> l2(5, 100); // initialize l2 by 5 times 100 i.e 100 100 100 100 100
}

void stackSTL()
{

    stack<int> st;
    st.push(4);
    st.push(5);
    st.push(6);
    cout << st.size() << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void QueueSTL()
{

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.size() << endl;
    cout << q.front() << " " << q.back() << endl;

    // This how you remove an element from Q
    q.pop();
    cout << q.front() << endl;
}

void priorityQ()
{

    priority_queue<int> maxi; // By default maxHeap

    priority_queue<int, vector<int>, greater<int>> mini; // This is a min heap;

    // maxheap implementation..
    maxi.push(5);
    maxi.push(1);
    maxi.push(10);
    maxi.push(12);
    maxi.push(6);
    cout << maxi.size() << endl;

    // prints from max to min.. since maxHeap
    while (!maxi.empty())
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;

    // miniHeap implementation..
    mini.push(5);
    mini.push(1);
    mini.push(10);
    mini.push(12);
    mini.push(6);
    cout << mini.size() << endl;

    // prints min to max..since minheap
    while (!mini.empty())
    {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;
}

void setSTL()
{

    set<int> s; // stores unique in sorted way...

    s.insert(5); // O(logn)
    s.insert(6);
    s.insert(5);
    s.insert(1);

    for (int i : s)
        cout << i << " ";
    cout << endl;

    // find -->returns the iterator of the find element
    set<int>::iterator pt = s.find(6); // O(logn)
    cout << *pt << endl;

    // erase in set
    set<int>::iterator it = s.begin();
    it++;
    // O(logn)
    s.erase(it); // delets the ele in index 1.
    for (int i : s)
        cout << i << " ";
    cout << endl;

    // count -->checkes if the element is there or not. //O(logn)
    cout << s.count(6) << endl; // true
    cout << s.count(5) << endl; // false.

    // looping using iterator...
    set<int>::iterator itr = s.begin();
    for (auto it = itr; it != s.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void mapSTL()
{

    map<int, string> m;

    m[1] = "first";
    m[2] = "second";
    m[3] = "third";

    m.insert({15, "sourav"}); // another way of inserting.. O(logn)

    for (auto it : m)
        cout << it.first << " " << it.second << endl;

    // count: checks if that key there or not..O(logn)
    cout << m.count(15) << endl; // true
    cout << m.count(10) << endl; // false

    // erase: remove a particular key from map. O(logn)
    m.erase(2);
    for (auto it : m)
        cout << it.first << " " << it.second << endl;

    // find in map O(logn)
    auto it = m.find(3);
    cout << "found the Element: ";
    cout << (*it).first << " " << (*it).second << endl;
}

int main()
{

    // Sequence Containers...
    // arrarySTL();
    // vectorSTL();
    // dequeSTL();
    // listSTL();

    // container adaptors...
    // stackSTL();
    // QueueSTL();
    // priorityQ();

    // container Associative..
    // setSTL();
    mapSTL();

    cout << "STL WorkThrough..." << endl;
    return 0;
}