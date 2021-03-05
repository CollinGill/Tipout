#include <iostream>
#include <vector>

struct Server {
    double bus;
    double expo;
    double bar;
};

struct Employee {
    double hours;
};

using ServerType = std::vector<Server>;
using EmployeeType = std::vector<Employee>;

void getServers(ServerType &servers)
{
    std::cout << "How many servers are there: ";
    int numServers{};
    std::cin  >> numServers;

    std::cout << "Enter in the corresponding tipouts for each server.\n";
    for (int i{0}; i < numServers; ++i) {
        std::cout << "\nServer " << i + 1 << ":\n";

        Server server{};
        std::cout << "Bus: ";
        std::cin >> server.bus;

        std::cout << "Expo: ";
        std::cin >> server.expo; 

        std::cout << "Bar: ";
        std::cin >> server.bar;

        servers.push_back(server);
    }
}

void getEmployees(EmployeeType &bussers, EmployeeType &expos, EmployeeType &bartenders, double &busHours, double &expoHours, double &barHours)
{
    std::cout << "\nHow many bussers: ";
    int numBus{};
    std::cin >> numBus;

    for (int i{0}; i < numBus; ++i) {
        std::cout << "Busser " << i + 1 << " hours: ";
        double hours{};
        std::cin >> hours;
        busHours += hours;

        Employee bus;
        bus.hours = hours;
        bussers.push_back(bus);
    }

    std::cout << "\nHow many expos: ";
    int numExpos{};
    std::cin >> numExpos;

    for (int i{0}; i < numExpos; ++i) {
        std::cout << "Expo " << i + 1 << " hours: ";
        double hours{};
        std::cin >> hours;
        expoHours += hours;

        Employee expo;
        expo.hours = hours;
        expos.push_back(expo);
    }

    std::cout << "\nHow many bartenders: ";
    int numBar{};
    std::cin >> numBar;

    for (int i{0}; i < numBar; ++i) {
        std::cout << "Bartender " << i + 1 << " hours: ";
        double hours{};
        std::cin >> hours;
        barHours += hours;

        Employee bar;
        bar.hours = hours;
        bartenders.push_back(bar);
    }
}   

void calculateTotals(ServerType &servers, double &busTotal, double &expoTotal, double &barTotal)
{
    for (auto server : servers) {
        busTotal += server.bus;
        expoTotal += server.expo;
        barTotal += server.bar;
    }

    std::cout << "How much did the bar tipout: ";
    double barTip{};
    std::cin >> barTip;

    busTotal += barTip / 2.0;
    expoTotal += barTip / 2.0;
}

void printDivde(double busTotal, double expoTotal, double barTotal, EmployeeType &bussers, EmployeeType &expos, EmployeeType &bartenders, double totalBusHours, double totalExpoHours, double totalBarHours)
{
    for (int i{0}; i < bussers.size(); ++i) {
        std::cout << "Busser " << i + 1 << ": " << busTotal * (bussers[i].hours / totalBusHours) << '\n'; 
    }

    for (int i{0}; i < expos.size(); ++i) {
        std::cout << "Expo " << i + 1 << ": " << expoTotal * (expos[i].hours / totalExpoHours) << '\n'; 
    }

    for (int i{0}; i < bartenders.size(); ++i) {
        std::cout << "Bartender " << i + 1 << ": " << barTotal * (bartenders[i].hours / totalBarHours) << '\n'; 
    }
}

int main()
{
    double busTotal{ 0 };
    double expoTotal{ 0 };
    double barTotal{ 0 };

    ServerType servers{};
    getServers(servers);

    calculateTotals(servers, busTotal, expoTotal, barTotal);

    std::cout << "Bus total: " << busTotal << "\nExpo total: " << expoTotal << "\nBar total: " << barTotal << '\n';    

    EmployeeType bussers{};
    EmployeeType expos{};
    EmployeeType bartenders{};

    double totalBusHours{ 0 };
    double totalExpoHours{ 0 };
    double totalBarHours{ 0 };

    getEmployees(bussers, expos, bartenders, totalBusHours, totalExpoHours, totalBarHours);
    //calculateTotals(servers, busTotal, expoTotal, barTotal);
    printDivde(busTotal, expoTotal, barTotal, bussers, expos, bartenders, totalBusHours, totalExpoHours, totalBarHours);

    return 0;
}