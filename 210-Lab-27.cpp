//COMSC-210|Ethan Aylard|Lab 27
//IDE used: Visual Studio Code
//This project is meant to track levels of friendship with different villagers using std::map:
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

//Prototype Functions:
int menu();


int main() {

    string searchKey;
    bool exitLoop = false;
    int choice;
    // declarations
    map<string, tuple <int, string, string>> villagerFriend; // map of villager Friendship levels (name, tuple (friendship level, species, catchphrase))

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerFriend["Audie"] = {8, "Human", "Cowabunga!"};
    villagerFriend["Raymond"] = {5, "Mutant", "What's up?"};
    villagerFriend.insert({"Marshal", {2, "Vampire", "Coo coo ca-choo!"}});
    

    //access the map using a range-based for loop
        cout << "Villager details:" << endl;
        for (auto &pair : villagerFriend) {
            cout << pair.first << " [ "; //listing the name of the villager
        //listing the friendship level
            cout << get<0>(pair.second) << ", ";
        //listing the species
            cout << get<1>(pair.second) << ", ";
        //listing the catchphrase
            cout << get<2>(pair.second) << "]" << endl;
    
        }
        
    while(!exitLoop){

        switch(menu()){
            case 1:{ //Increase Friendship:
                cout << "Enter the first name of the villager to increase friendship:";
                cin >> searchKey;
                auto it = villagerFriend.find(searchKey);
                
                if (it != villagerFriend.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
                    cout << "\nFound " << searchKey << " [ ";
        
                    //listing the old friendship level:
                    cout << "Old Friendship: " << get<0>(it->second) << ", ";

                    //updating the friendship level:
                    get<0>(it->second) += 1;

                    //listing the new friendship level:
                    cout << "New Friendship: " << get<0>(it->second) << endl;
                
                    break;
                } 
                
                else{
                    cout << endl << searchKey << " not found." << endl;
                }
                    break;
            }

            case 2:{ //Decrease Friendship:
                    cout << "Enter the first name of the villager to decrease friendship:";
                cin >> searchKey;
                auto it = villagerFriend.find(searchKey);
                
                if (it != villagerFriend.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
                    cout << "\nFound " << searchKey << " [ ";
        
                    //listing the old friendship level:
                    cout << "Current Friendship: " << get<0>(it->second) << ", ";

                    //updating the friendship level:
                    if(get<0>(it->second) > 0){ //if Friendship is above 0 lower the friendship:
                    get<0>(it->second) -= 1;

                    //listing the new friendship level:
                    cout << "New Friendship: " << get<0>(it->second) << endl;
                    }

                    else{ //if friendship is 0 or below already display an error messege:
                        cout << "Friendship cannot go below 0." << endl;
                    }
                
                    break;
                } else{
                    cout << endl << searchKey << " not found." << endl;
                    break;
                }
        
            }
            case 3: { //Search for Villager:
                cout << "Enter the first name of the villager you wish to find:";
                cin >> searchKey;

                auto it = villagerFriend.find(searchKey);
                if (it != villagerFriend.end()) {  // the iterator points to beyond the end of the map
                    
                    cout << "\nFound " << searchKey << " [ ";
        
                    //listing the friendship level
                    cout << get<0>(it->second) << ", ";
                    //listing the species
                    cout << get<1>(it->second) << ", ";
                    //listing the catchphrase
                    cout << get<2>(it->second) << "]" << endl;
            
                    cout << endl;
                } else{
                    cout << endl << searchKey << " not found." << endl;
                }
            break;
            }

            case 4:{ //Exit:
                exitLoop = true;
                cout << "Exiting Program.\n" << endl;
            break;
            }
            default: {//Invalid input:

                cout << "Invalid choice. Please try again." << endl;
            break;
            }
        }
       
        //access the map using a range-based for loop
        cout << "Villager details:" << endl;
        for (auto &pair : villagerFriend) {
            cout << pair.first << " [ "; //listing the name of the villager
        //listing the friendship level
            cout << get<0>(pair.second) << ", ";
        //listing the species
            cout << get<1>(pair.second) << ", ";
        //listing the catchphrase
            cout << get<2>(pair.second) << "]" << endl;
    
        }

    }

    
    
    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerFriend.size() << endl;
    villagerFriend.clear();
    cout << "Size after clear: " << villagerFriend.size() << endl;

    return 0;
}

//menu() display the menu and get user choice:
//Requires: nothing
//Return: an int value representing the user's menu choice
int menu(){
    bool valid = false;
    int choice;

    //a while loop to validate user input:
    while(!valid){
    cout << "1. Increase Friendship\n" << "2. Decrease Friendship\n"
    << "3. Search for Villager\n" << "4. Exit\n" << endl;

    cout << "Enter choice (integer 1-4):";
    cin >> choice;

    //If the user enters a valid choice (1-4), set valid to true to exit the loop, if not restart the loop:
    if(choice == 1 || choice == 2 || choice == 3 || choice == 4){
        valid = true;
    }
    else{
        cin.clear();
        cin.ignore(10000, '\n');
        
        cout << "Invalid choice. Please try again." << endl;
    }
}
    return choice;
}

