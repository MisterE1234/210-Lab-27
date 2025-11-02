//COMSC-210|Ethan Aylard|Lab 27
//IDE used: Visual Studio Code
//This project is meant to track levels of friendship with different villagers using std::map:
#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple <int, string>> villagerFriend; // map of villager Friendship levels (name, tuple (friendship level, catchphrase))

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerFriend["Audie"] = {8, "Cowabunga!"};
    villagerFriend["Raymond"] = {5, "What's up?"};
    villagerFriend.insert({"Marshal", {2, "Coo coo ca-choo!"}});

    // access the map using a range-based for loop
    cout << "Villagers, their friendship level, and their favorite catchphrases (range-based for loop):" << endl;
    for (auto pair : villagerFriend) {
        cout << pair.first << ": ";
        for(auto level : get<0>(pair.second))
            cout << "Friendship Level: " << level << ", ";
        for (auto catchphrase : get<1>(pair.second))
            cout << "\"" << catchphrase << "\" ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string>>::iterator it = villagerFriend.begin(); 
                                               it != villagerFriend.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerFriend.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerFriend.find(searchKey);
    if (it != villagerFriend.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite catchphrase: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerFriend.size() << endl;
    villagerFriend.clear();
    cout << "Size after clear: " << villagerFriend.size() << endl;

    return 0;
}