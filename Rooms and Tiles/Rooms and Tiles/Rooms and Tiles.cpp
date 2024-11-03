// Rooms and Tiles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>
#include <random>

using namespace std;



struct PairHash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& pair) const {
        // Combine hashes of the two elements
        return std::hash<T1>()(pair.first) ^ (std::hash<T2>()(pair.second) << 1);
    }
};



enum class TileType {
    Floor,
    Wall,
    Door
};

enum class ObjectType {
    Player,

    Slime,
    Goblin,
    Demon,

    Consumable,
    Weapon,

    Pot,
    Chest
};



class TileObject {


    ObjectType objectType;

public:
    TileObject(ObjectType type) {
        objectType = type;
    }

    ObjectType GetObjectType() {
        return objectType;
    }
};



class Room {
    pair<int, int> roomCoordinates;
    int roomSizeX;
    int roomSizeY;



    unordered_map<pair<int, int>, TileType, PairHash> tiles;
    unordered_map<pair<int, int>, TileObject*, PairHash> objects;

public:

    Room(pair<int, int> coordinates) {
        roomCoordinates = coordinates;

        GenerateRandomRoom();
    }

    Room(pair<int, int> coordinates, int sizeX, int sizeY) {
        roomCoordinates = coordinates;

        roomSizeX = sizeX;
        roomSizeY = sizeY;

        GenerateRoom();
    }



    void GenerateRoom() {
        for (int x = 0; x < roomSizeX; x++) {
            for (int y = 0; y < roomSizeY; y++) {

                pair<int, int> tile(x, y);

                if (x == 0 or y == 0 or x == roomSizeX - 1 or y == roomSizeY - 1) {

                    if (x == roomSizeX / 2 or y == roomSizeY / 2) {
                        tiles[tile] = TileType::Door;
                    }
                    else {
                        tiles[tile] = TileType::Wall;
                    }
                    
                }
                else {
                    tiles[tile] = TileType::Floor;
                    AttemptToGenerateObject(tile);
                }

            }
        }
    }



    void GenerateRandomRoom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<mt19937::result_type> dist(5, 30);

        roomSizeX = dist(gen);
        roomSizeY = dist(gen);


        GenerateRoom();
    }



    void AttemptToGenerateObject(pair<int, int> coordinates) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<mt19937::result_type> dist(1, 1000);

        int chance = dist(gen);

        //Enemy
        if (chance <= 10) {
            chance = dist(gen);

            //Slime
            if (chance <= 500) {
                
                TileObject* slime = new TileObject(ObjectType::Slime);

                objects[coordinates] = slime;

            }
            //Goblin
            else if (chance <= 800) {

                TileObject* goblin = new TileObject(ObjectType::Goblin);

                objects[coordinates] = goblin;

            }
            //Demon
            else {
                TileObject* demon = new TileObject(ObjectType::Demon);

                objects[coordinates] = demon;
            }

        }
        //Item
        else if(chance <= 15) {
            chance = dist(gen);

            //Consumable
            if (chance <= 750) {

                TileObject* consumable = new TileObject(ObjectType::Consumable);

                objects[coordinates] = consumable;

            }
            //Weapon
            else {

                TileObject* weapon = new TileObject(ObjectType::Weapon);

                objects[coordinates] = weapon;

            }
        }
        //Treasure
        else if(chance <= 25) {
            chance = dist(gen);

            //Pot
            if (chance <= 900) {

                TileObject* pot = new TileObject(ObjectType::Pot);

                objects[coordinates] = pot;

            }
            //Chest
            else {

                TileObject* chest = new TileObject(ObjectType::Chest);

                objects[coordinates] = chest;

            }
        }
    }



    string TileToString(TileType type) {
        switch (type) {
            case TileType::Floor:   return "   ";
            case TileType::Wall: return "[X]";
            case TileType::Door:  return " ~ ";
        }
    }



    string ObjectToString(TileObject* object) {
        ObjectType type = object->GetObjectType();

        switch (type) {
            case ObjectType::Player:  return " P ";

            case ObjectType::Slime:  return " S ";
            case ObjectType::Goblin:  return " G ";
            case ObjectType::Demon:  return " D ";

            case ObjectType::Consumable:  return " c ";
            case ObjectType::Weapon:  return " w ";

            case ObjectType::Pot:  return " u ";
            case ObjectType::Chest:  return "(o)";
        }
    }



    void RenderRoom() {

        cout << endl;
        cout << endl;
        cout << endl;

        for (int x = 0; x < roomSizeX; x++) {
            cout << "\t";
            for (int y = 0; y < roomSizeY; y++) {

                pair<int, int> tile(x, y);

                if (objects[tile] != nullptr) {
                    cout << ObjectToString(objects[tile]);
                }
                else {
                    cout << TileToString(tiles[tile]);
                }

                
            }
            cout << endl;
        }


        cout << endl;
        cout << endl;
        cout << endl;
    }
};



int main()
{
    pair<int, int> coords(0, 0);

    Room* room = new Room(coords);


   
    room->RenderRoom();
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
