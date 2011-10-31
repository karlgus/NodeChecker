#include <cstdio>
#include <iostream>
#include <pugixml.hpp>
#include <cstring>
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
    string date;
    string time;
    string ping_max;
    string ping_avg;
    string ping_min;
};


string exec(char* cmd) {
    FILE* pipe = popen(cmd, "r");   //popen = process open
    if (!pipe) return "ERROR";
    char buffer[128];
    string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
                result += buffer;
    }
    pclose(pipe);
    return result;
}

int main()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("/home/karl/.config/NodeChecker/nodes_result.xml");
    if (result)
    {
        doc.append_child("node").child_value("ip");
    }
    /*pugi::xml_parse_result result = doc.load_file("/home/karl/.config/NodeChecker/nodes.xml");

    vector <Node> nodes;

    /*string date = exec("date \"+%Y.%m.%d\"");         får ut datum i formatet 2011.10.30
    string time = exec("date \"+%H:%M:%S\"");           får ut tid i formatet 12:13:45
    cout << date;
    cout << time;


    if (result)
    {
        pugi::xpath_node_set tools = doc.select_nodes("/nodes/node");

        for(pugi::xpath_node_set::const_iterator it = tools.begin(); it != tools.end(); ++it)
        {
            Node tempnodes;
            pugi::xpath_node node = *it;
            tempnodes.ip = node.node().child_value("ip");
            tempnodes.hostname = node.node().child_value("hostname");
            nodes.push_back(tempnodes);
       }
   }*/

    /*vector <Node_result> nodes_result;

    string host= nodes[0].ip;
    string ping = "ping -c ";
    ping.append(host);
    cout << exec(ping);*/




    return 0;
}
