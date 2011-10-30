#include <iostream>
#include <pugixml.hpp>
#include <vector>
#include <cstdlib>

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
    pugi::xml_parse_result result = doc.load_file("/home/karl/.config/NodeChecker/nodes.xml");


    vector <Node> nodes;

    if (result)
    {
       // pugi::xpath_node_set tools = doc.select_nodes("/nodes/node");
        pugi::xpath_node_set tools = doc.select_nodes("/nodes/node");

        for(pugi::xpath_node_set::const_iterator it = tools.begin(); it != tools.end(); ++it)
        {
            Node tempnodes;
            pugi::xpath_node node = *it;
            tempnodes.ip = node.node().child_value("ip");
            tempnodes.hostname = node.node().child_value("hostname");
            nodes.push_back(tempnodes);
       }

   }

    return 0;
}
