#### C++ → Java DSA Cheat Sheet

Core Syntax:

| Concept              | C++                    | Java                                                         |
| -------------------- | ---------------------- | ------------------------------------------------------------ |
| Entry point          | `int main()`           | `public static void main(String[] args)`                     |
| Output               | `cout << x;`           | `System.out.println(x);`                                     |
| Input                | `cin >> x;`            | `Scanner sc = new Scanner(System.in); int x = sc.nextInt();` |
| Header               | `#include`             | `import java.util.*;`                                        |
| Namespace            | `using namespace std;` | `package / import`                                           |
| Const                | `const`                | `final`                                                      |
| Pointers             | ✅ Yes                 | ❌ No                                                       |
| Memory mgmt          | Manual (`new/delete`)   | GC (automatic)                                              |
| Struct/Union         | ✅                     | ❌ (use class)                                              |
| Operator Overload    | ✅                     | ❌                                                          |
| Multiple Inheritance | ✅                     | ❌ (use interfaces)                                         |


Arrays: 
C++:
    int arr[5];
    int n = sizeof(arr)/sizeof(arr[0]);

Java: 
    int[] arr = new int[5];
    int n = arr.length;
    Arrays.sort(arr);
    Arrays.fill(arr, 0);

ArrayList (vector)
| Operation | C++                           | Java                                        |
| --------- | ----------------------------- | ------------------------------------------- |
| Create    | `vector<int> v;`              | `ArrayList<Integer> v = new ArrayList<>();` |
| Add       | `v.push_back(x);`             | `v.add(x);`                                 |
| Access    | `v[i];`                       | `v.get(i);`                                 |
| Update    | `v[i]=x;`                     | `v.set(i, x);`                              |
| Remove    | `v.pop_back();`               | `v.remove(v.size()-1);`                     |
| Size      | `v.size();`                   | `v.size();`                                 |
| Clear     | `v.clear();`                  | `v.clear();`                                |
| Find      | `find(v.begin(), v.end(), x)` | `v.contains(x);`                            |

LinkedList
| Operation    | C++ `list`      | Java `LinkedList` |
| ------------ | --------------- | ----------------- |
| Add front    | `push_front(x)` | `addFirst(x)`     |
| Add back     | `push_back(x)`  | `addLast(x)`      |
| Remove front | `pop_front()`   | `removeFirst()`   |
| Remove back  | `pop_back()`    | `removeLast()`    |
| Size         | `size()`        | `size()`          |

Stack
| Operation | C++              | Java                                 |
| --------- | ---------------- | ------------------------------------ |
| Create    | `stack<int> st;` | `Stack<Integer> st = new Stack<>();` |
| Push      | `st.push(x);`    | `st.push(x);`                        |
| Pop       | `st.pop();`      | `st.pop();`                          |
| Top       | `st.top();`      | `st.peek();`                         |
| Empty     | `st.empty();`    | `st.isEmpty();`                      |


Queue
| Operation | C++             | Java                                     |
| --------- | --------------- | ---------------------------------------- |
| Create    | `queue<int> q;` | `Queue<Integer> q = new LinkedList<>();` |
| Push      | `q.push(x);`    | `q.add(x);` / `q.offer(x);`              |
| Front     | `q.front();`    | `q.peek();`                              |
| Pop       | `q.pop();`      | `q.poll();`                              |
| Empty     | `q.empty();`    | `q.isEmpty();`                           |


dequeue
| Operation  | C++              | Java                                      |
| ---------- | ---------------- | ----------------------------------------- |
| Create     | `deque<int> dq;` | `Deque<Integer> dq = new ArrayDeque<>();` |
| Push front | `push_front(x)`  | `addFirst(x)`                             |
| Push back  | `push_back(x)`   | `addLast(x)`                              |
| Pop front  | `pop_front()`    | `removeFirst()`                           |
| Pop back   | `pop_back()`     | `removeLast()`                            |

Map / HashMap
| Operation | C++                             | Java                                            |
| --------- | ------------------------------- | ----------------------------------------------- |
| Create    | `unordered_map<string,int> mp;` | `HashMap<String,Integer> mp = new HashMap<>();` |
| Insert    | `mp["a"]=10;`                   | `mp.put("a",10);`                               |
| Access    | `mp["a"];`                      | `mp.get("a");`                                  |
| Check key | `mp.count("a");`                | `mp.containsKey("a");`                          |
| Default   | —                               | `mp.getOrDefault("a", 0);`                      |
| Erase     | `mp.erase("a");`                | `mp.remove("a");`                               |
| Size      | `mp.size();`                    | `mp.size();`                                    |

Set / HashSet
| Operation | C++                     | Java                                    |
| --------- | ----------------------- | --------------------------------------- |
| Create    | `unordered_set<int> s;` | `HashSet<Integer> s = new HashSet<>();` |
| Add       | `s.insert(x);`          | `s.add(x);`                             |
| Check     | `s.count(x);`           | `s.contains(x);`                        |
| Remove    | `s.erase(x);`           | `s.remove(x);`                          |
| Size      | `s.size();`             | `s.size();`                             |

Priority Queue (Heap)
| Type     | C++                                            | Java                                              |
| -------- | ---------------------------------------------- | ------------------------------------------------- |
| Max Heap | `priority_queue<int>`                          | `new PriorityQueue<>(Collections.reverseOrder())` |
| Min Heap | `priority_queue<int,vector<int>,greater<int>>` | `new PriorityQueue<>()`                           |
| Push     | `pq.push(x)`                                   | `pq.add(x)`                                       |
| Pop      | `pq.pop()`                                     | `pq.poll()`                                       |
| Top      | `pq.top()`                                     | `pq.peek()`                                       |


Iterations:
C++:
    for (auto x : v) cout << x;
    for (auto &p : mp) cout << p.first << " " << p.second;

Java:
    for (int x : v) System.out.println(x);
    for (Map.Entry<String,Integer> e : mp.entrySet())
        System.out.println(e.getKey() + " " + e.getValue());


String: 
| Operation     | C++                            | Java                                         |
| ------------- | ------------------------------ | -------------------------------------------- |
| Create        | `string s = "abc";`            | `String s = "abc";`                          |
| Concatenate   | `s += "x";`                    | `s += "x";`                                  |
| Substring     | `s.substr(0,3);`               | `s.substring(0,3);`                          |
| Reverse       | `reverse(s.begin(), s.end());` | `new StringBuilder(s).reverse().toString();` |
| Compare       | `s1 == s2`                     | `s1.equals(s2)`                              |
| Lexicographic | `s1 < s2`                      | `s1.compareTo(s2)`                           |
| Length        | `s.size()`                     | `s.length()`                                 |

Sorting: 
| Type              | C++                        | Java                         |
| ----------------- | -------------------------- | ---------------------------- |
| Array             | `sort(a, a+n);`            | `Arrays.sort(a);`            |
| Vector/List       | `sort(v.begin(),v.end());` | `Collections.sort(v);`       |
| Descending        | `greater<int>()`           | `Collections.reverseOrder()` |
| Custom Comparator | `[](a,b){ return a>b; }`   | `(a,b)->b-a`                 |

Math & Constaints:
| C++         | Java                |
| ----------- | ------------------- |
| `max(a,b)`  | `Math.max(a,b)`     |
| `min(a,b)`  | `Math.min(a,b)`     |
| `abs(a)`    | `Math.abs(a)`       |
| `pow(a,b)`  | `Math.pow(a,b)`     |
| `sqrt(a)`   | `Math.sqrt(a)`      |
| `rand()`    | `Math.random()`     |
| `INT_MAX`   | `Integer.MAX_VALUE` |
| `INT_MIN`   | `Integer.MIN_VALUE` |
| `LLONG_MAX` | `Long.MAX_VALUE`    |

Other:
| Concept     | C++                 | Java                             |
| ----------- | ------------------- | -------------------------------- |
| Pair        | `pair<int,int>`     | Custom `class Pair { int f,s; }` |
| Tuple       | `tuple<int,string>` | Custom class or record           |
| Pass by ref | `void f(int &x)`    | `void f(int x)` (copy only)      |
| Exception   | Optional            | Mandatory checked exceptions     |
| Template    | `template<class T>` | `class<T>` (Generics)            |
| Destructor  | `~Class()`          | GC only (no explicit destructor) |
