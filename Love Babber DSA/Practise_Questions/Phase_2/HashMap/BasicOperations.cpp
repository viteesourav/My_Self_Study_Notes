// This Shows the most frequently used methods with map DS...

#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Decalring stl ordered and unorderd_map...
    unordered_map<string, int> map1;
    // map<string, int> map1;

    // Insertion:
    // inserting as pairs in the map.
    map1.insert(make_pair("key1", 1));
    map1.insert(make_pair("key2", 2));
    map1.insert(make_pair("key3", 3));

    // insertion as directly with the keys...
    map1["key4"] = 4;
    map1["key5"] = 5;
    map1["key6"] = 6;

    // Searching the element in map...
    //  cout<<"searching for key5: "<< map1.at("key5")<<endl;
    //  cout<<"searching for key12 [Don't Exist]: "<< map1.at("key12")<<endl; //Throws Error if we try to search a key that dont exist.

    cout << "searching for key3:" << map1["key3"] << endl;
    cout << "searching for key12 [Don't Exist]:" << map1["key12"] << endl; // If dont exist, Returns 0 [Most preffred]

    // check if Key is present or not ? [Returns Boolean]
    cout << "Is key4 present: " << map1.count("key4") << endl;
    cout << "Is key23 [Don't Exist] present: " << map1.count("key23") << endl;

    // Remove a key from the map...
    cout << "Removing the key12 form the Map: " << map1.erase("key12") << endl;                 // Returns 1 as the key successfully deleted...
    cout << "Removing the key234 [Don't exist] form the Map: " << map1.erase("key234") << endl; // Returns 0 as the key is not found...

    // cout<<"Printing the Map Content: "<<endl;

    // Iterate the map...
    //  //1.using auto Keyword...
    //  for(auto ele : map1) {
    //      cout<<ele.first <<" "<<ele.second<<endl;
    //  }

    // 2.using the iterator of the map...
    //  unordered_map<string, int>::iterator it = map1.begin(); //define an iterator and store..
    //  while(it != map1.end()) {
    //      cout<<it->first<<" "<<it->second<<endl;
    //      it++;
    //  }

    return 0;
}