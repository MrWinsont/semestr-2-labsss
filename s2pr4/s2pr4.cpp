#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector <std::string> Electricity = { "Меркурий 230","Нева МТ314","Энергомера CE308" };
std::vector <std::string> Discrete = { "Reallab NL-16HV","Приборэлектро PRE-16","Энергосервис ЭНМВ-1-24" };
std::vector <std::string> Heating = { "Ouman S203","Овен ТРМ232" };

class Main
{
private:
	std::string m_str;
public:
	explicit Main(const std::string& str) {
		m_str = str;
	}

	void poll() {
		std::cout << m_str << "\n";
	}

	~Main() {}

};

class ElectricalEnergy : public Main {
public:
	explicit ElectricalEnergy(const std::string& device): Main(device) {
		
	}

};

class DiscreteSignals : public Main {
public:
	explicit DiscreteSignals(const std::string& device) : Main(device) {

	}
		
};

class HeatingControl : public Main {
public:
	explicit HeatingControl(const std::string& device) : Main(device) {

	}
};

int main()
{
	std::vector<ElectricalEnergy> meter;
	std::vector<DiscreteSignals> device;
	std::vector<HeatingControl> heat;

	setlocale(LC_ALL, "ru");

	std::ifstream file;
	file.open("configuration.txt");
	std::string tmp;

	while (getline(file, tmp)) {
		for (int i = 0; i < Electricity.size(); i++) {
			if (Electricity[i] == tmp) {
				meter.push_back(ElectricalEnergy(tmp));
				tmp = "";
				break;
			}
		}
		for (int i = 0; i < Discrete.size(); i++) {
			if (Discrete[i] == tmp) {

				device.push_back(DiscreteSignals(tmp));
				tmp = "";
				break;
			}
		}
		for (int i = 0; i < Heating.size(); i++) {
			if (Heating[i] == tmp) {
				heat.push_back(HeatingControl(tmp));
				tmp = "";
				break;
			}
		}
	}
	file.close();
}
