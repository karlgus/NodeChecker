#include <cstdio>
#include <iostream>
#include <pugixml.hpp>
#include <cstring>
#include <vector>
#include <boost/regex.hpp>

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

class PingStatus
{
public:
    string min;
    string avg;
    string max;
};


string exec(string cmd)
{
    char char_cmd[cmd.length()+1];
    strcpy(char_cmd, cmd.c_str());

    FILE* pipe = popen(char_cmd, "r"); //popen = process open
    if (!pipe) return "ERROR";
        char buffer[128];
        string result = "";
    while(!feof(pipe))
    {
        if(fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}


/*PingStatus ping(string ipaddress)
{
    string pingString = "ping -c 3 ";
    pingString.append(ipaddress);

    PingStatus tempPingStatus;
    string pingData = exec(pingString);

    string awkmax = "| sed '$!d' | awk '{ print $4}' | awk -F '/' '{print $3}'";
    string awkmin = "| sed '$!d' | awk '{ print $4}' | awk -F '/' '{print $1}'";
    string awkavg = "| sed '$!d' | awk '{ print $4}' | awk -F '/' '{print $2}'";


    string maxCommand = pingData;
    maxCommand.append(awkmax);

    //tempPingStatus.max = exec(maxCommand);

    string minCommand = pingData;
    minCommand.append(awkmin);
    //tempPingStatus.min = exec(minCommand);

    string avgCommand = pingData;
    avgCommand.append(awkavg);
    //tempPingStatus.avg = exec(avgCommand);

    /*string maxCommand = "echo ";
    maxCommand.append(pingData);
    maxCommand.append(awkmax);*/
    /*cout << maxCommand << endl;
    tempPingStatus.max = exec(maxCommand);
    string minCommand = "echo ";
    minCommand.append(pingData);
    minCommand.append(awkmin);
    //tempPingStatus.min = exec(minCommand);
    string avgCommand = "'echo '";
    avgCommand.append(pingData);
    avgCommand.append(awkavg);
    tempPingStatus.avg;*/
//    return tempPingStatus;
//}

PingStatus ping(string ipaddress)
{
    string pingString = "ping -c 3 ";
    pingString.append(ipaddress);

    PingStatus tempPingStatus;
    string pingData = exec(pingString);
    boost::regex_e1("min",boost::regex::extended);



}


    /*FILE* pipe = popen(cmd, "r");   //popen = process open
    if (!pipe) return "ERROR";
    char buffer[128];
    string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
                result += buffer;
    }
    pclose(pipe);
    return result;
}*/



int main()
{
    /*pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("/home/karl/.config/NodeChecker/nodes_result.xml");
    if (result)
    {
        doc.append_child("node").child_value("ip");
    }
    */
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("/home/karl/.config/NodeChecker/nodes.xml");

    vector <Node> nodes;

    string date = exec("date \"+%Y.%m.%d\"");         // får ut datum i formatet 2011.10.30
    string time = exec("date \"+%H:%M:%S\"");         // får ut tid i formatet 12:13:45
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


    vector <Node_result> nodes_result;

    string awkmax = "| sed '$!d' | awk '{ print $4}' | awk -F '/' '{print $3}'";


    cout << endl;

    for(int i = 0; i < nodes.size();i++)
    {
        Node_result tempresult;

        string host= nodes[i].ip;
        string ping = "ping -c 3 ";
        ping.append(host);
        ping.append(awkmax);
        //cout << ping;
        string pingresult = exec(ping);
        tempresult.ping_max = pingresult;
        nodes_result.push_back(tempresult);
        //cout << nodes_result[i].ping_max;

    }


    for(int i = 0; i< nodes.size();i++)
    {
        Node_result tempresult;
        PingStatus pingStatus = ping(nodes[i].ip);
        tempresult.ping_max = pingStatus.max;
        tempresult.ping_min = pingStatus.min;
        tempresult.ping_avg = pingStatus.avg;
        nodes_result.push_back(tempresult);


    }
    for(int i = 0;i < nodes_result.size(); i++)
    {
        cout << nodes_result[i].ping_avg;
        //cout << "ping avg för host: " << " " << nodes_result[i].ping_avg;
        //cout << "ping min för host: " << " " << nodes_result[i].ping_min;
    }

    return 0;
    }
}
