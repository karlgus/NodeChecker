
#include <iostream>
#include <pugixml.hpp>
#include <vector>

using namespace std;

class nodes
{
public:
    vector <string> ip;
    vector <string> hostname;
};

class nodes_result : nodes
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

    if (result)
    {

        pugi::xpath_node_set tools = doc.select_nodes("/nodes/node/");

        for(pugi::xpath_node_set::const_iterator it = tools.begin(); it != tools.end(); ++it)
        {
            pugi::xpath_node node = *it;

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
