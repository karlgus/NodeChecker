
#include <iostream>
#include <pugixml.hpp>
#include <vector>

using namespace std;

class Node
{
public:
    string ip;
    string hostname;
};

class Node_result : Node
{
public:
    long int date;
    long int time;
    vector <string> ip;
    vector <string> hostname;
    vector <string> ping_max;
    vector <string> ping_avg;
    vector <string> ping_min;
};


int main()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("nodes.xml");


    vector <Node> nodes;


    if (result)
    {

        pugi::xpath_node_set tools = doc.select_nodes("/nodes/node/");

        for(pugi::xpath_node_set::const_iterator it = tools.begin(); it != tools.end(); ++it)
        {
            Node tempnodes;
            pugi::xpath_node node = *it;
            tempnodes.ip = node.node().child_value("ip");
            nodes.push_back(tempnodes);
            //Nodes.ip = node.node().child_value("ip");
            //Node.push_back(Nodes);
            //nodes.ip = node.node().child_value("ip");
            //test.text = node.node().child_value("ip");

            //test.correctanswer = node.node().child("hostname").attribute("correctanswer").as_int();

            //pugi::xpath_node_set tools2 = node.node().select_nodes("options/option");

            //for(pugi::xpath_node_set::const_iterator it2 = tools2.begin(); it2 != tools2.end(); ++it2)
            //{
            //    pugi::xpath_node node = *it2;
            //    test.optionsnr.push_back(node.node().child_value());
            //}

            //quest.push_back(test);
            //test.optionsnr.clear();
       }

   }

    return 0;
}
