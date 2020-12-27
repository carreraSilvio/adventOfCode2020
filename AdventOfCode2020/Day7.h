#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include "Utils.h"
#include <map>

#pragma once
class Day7
{
public:
    map<string, vector<string>> bagMap;
    const string SHINY_GOLD_BAG = "shiny gold";

    void run(string inputPath) 
    {
        //Read input, parse and calc solution
        fstream newfile;
        newfile.open(inputPath, ios::in);
        if (newfile.is_open())
        {
            string line;
            
            while (getline(newfile, line))
            {
                //Each line is a bag relation description
                //cout << "line " << line << "\n";

                vector<string> lineSplit = Utils::split_by_string(line, "contain");
                string parentData = lineSplit[0];
                string childrenData = lineSplit[1];

                //cout << "leftSide - " << parentData << "\n";
                //cout << "rightSide - " << childrenData << "\n";

                //Create parent bag
                string parentBag = create_bag(parentData);
                //cout << "parentBag - " << parentBag.name << "\n";

                //Create children bags if any
                vector<string> childrenDataSplit = Utils::contains_string(childrenData, ",") ? Utils::splitAll(childrenData, ',') : vector<string> { childrenData };
                vector<string> innerBags = vector<string>();

                for (string childData : childrenDataSplit)
                {
                    if (Utils::contains_string(childData, "no")) 
                    {
                        //cout << "no child bags" << "\n";
                        break;
                    }
                    string childBag = create_bag(childData);
                    //cout << "childBag - " << childBag.name << "\n";
                    Utils::trim_whitespace(childBag);
                    innerBags.push_back(childBag);
                }
                Utils::trim_whitespace(parentBag);
                bagMap.insert(pair<string, vector<string>>(parentBag, innerBags));
                //currentGroup->process_person_answers(line);

            }
            newfile.close();
        }

        //Sum bags that have inner gold ones
        int totalShinyBagParents = 0;
        for (pair<string, vector<string>>bag : bagMap)
        {
            if (does_bag_contain(bag.first, SHINY_GOLD_BAG)) 
            {
                //cout << bag.first << " does contain " << SHINY_GOLD_BAG << endl;
                totalShinyBagParents++;
            }
            else 
            {
                //cout << bag.first << " DOES NOT CONTAIN "  << SHINY_GOLD_BAG <<  endl;
            }
        }

        cout << "totalShinyBagParents is " << totalShinyBagParents << endl;
    }

    bool does_bag_contain(string parentBag, string innerBagName) 
    {
        try 
        {
            vector<string> innerBags = bagMap.at(parentBag);

            for (string innerBag : innerBags)
            {
                if (innerBag == SHINY_GOLD_BAG)
                {
                    return true;
                }
                if (does_bag_contain(innerBag, SHINY_GOLD_BAG)) 
                {
                    return true;
                }
            }
            return false;
        }
        catch (exception e) 
        {
            return false;
        }
    }

    string create_bag(string fullData) 
    {
        vector<string> dataSplit = Utils::splitAll(fullData, ' ');
        string name = "";
        for (string entry : dataSplit)
        {
            if (Utils::is_number(entry)) 
            {
                continue; // we dont care about the amount
            }
            else if (entry != "bags" &&
                entry != "bags," &&
                entry != "bag" &&
                entry != "bag," &&
                entry != "bag." &&
                entry != "bags."
                )
            {
                name = name + (name.length() > 0 ? " " : "") + entry;
            }
        }
        return name;
    }

    
};

