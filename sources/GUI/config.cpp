#include "config.h"

Config config;

using namespace std;

void Config::LoadConfigs() {
	ifstream configFile("config.txt");

	if (configFile.good())
	{
		ReadConfigs();
	}
	else
	{
		CreateConfig();
		ReadConfigs();
	}
}

void Config::ReadConfigs() {
	ifstream configFile("config.txt");

	if (configFile.is_open())
	{
		std::string line;
		while (std::getline(configFile, line))
		{
			line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

			if ((line[0] == '/' && line[1] == '/') || line.empty())
				continue;

			auto delimiterPos = line.find("=");
			string name = line.substr(0, delimiterPos);
			string value = line.substr(delimiterPos + 1);

			SetConfig(name, value);
		}
	}
}

void Config::SetConfig(std::string name, std::string value) {
	stringstream val(value);
	if (name == "aimbot_fov") {
		val >> aFOV;
	}
	else if (name == "desertEagle") {
		val >> desertEagle;
	}
	else if (name == "dualBerettas") {
		val >> dualBerettas;
	}
	else if (name == "fiveSeven") {
		val >> fiveSeven;
	}
	else if (name == "glock18") {
		val >> glock18;
	}
	else if (name == "p2000") {
		val >> p2000;
	}
	else if (name == "p250") {
		val >> p250;
	}
	else if (name == "tec9") {
		val >> tec9;
	}
	else if (name == "ak47") {
		val >> ak47;
	}
	else if (name == "aug") {
		val >> aug;
	}
	else if (name == "awp") {
		val >> awp;
	}
	else if (name == "famas") {
		val >> famas;
	}
	else if (name == "g3sg1") {
		val >> g3sg1;
	}
	else if (name == "galilAr") {
		val >> galilAr;
	}
	else if (name == "m4a4") {
		val >> m4a4;
	}
	else if (name == "scar20") {
		val >> scar20;
	}
	else if (name == "ssg08") {
		val >> ssg08;
	}
	else if (name == "mac10") {
		val >> mac10;
	}
	else if (name == "mp7") {
		val >> mp7;
	}
	else if (name == "mp9") {
		val >> mp9;
	}
	else if (name == "ppBizon") {
		val >> ppBizon;
	}
	else if (name == "p90") {
		val >> p90;
	}
	else if (name == "ump45") {
		val >> ump45;
	}
	else if (name == "mag7") {
		val >> mag7;
	}
	else if (name == "nova") {
		val >> nova;
	}
	else if (name == "sawedOff") {
		val >> sawedOff;
	}
	else if (name == "xm1014") {
		val >> xm1014;
	}
	else if (name == "m249") {
		val >> m249;
	}
	else if (name == "negev") {
		val >> negev;
	}
	else if (name == "usps") {
		val >> usps;
	}
	else if (name == "m4a1s") {
		val >> m4a1s;
	}
	else if (name == "cz75") {
		val >> cz75;
	}
	else if (name == "mp5sd") {
		val >> mp5sd;
	}
	else if (name == "revolver") {
		val >> revolver;
	}
	else if (name == "knife_id") {
		val >> knifeID;
	}
	else if (name == "m9Bayonet") {
		val >> m9Bayonet;
	}
	else if (name == "bayonet") {
		val >> bayonet;
	}
	else if (name == "flip") {
		val >> flip;
	}
	else if (name == "karambit") {
		val >> karambit;
	}
	else if (name == "huntsman") {
		val >> huntsman;
	}
	else if (name == "falchion") {
		val >> falchion;
	}
	else if (name == "navaja") {
		val >> navaja;
	}
	else if (name == "stiletto") {
		val >> stiletto;
	}
	else if (name == "triggerKey") {
		val << std::hex;
		val >> triggerKey;
	}
	else if (name == "aimbotKey") {
		val << std::hex;
		val >> aimbotKey;
	}
	else if (name == "wallhackKey") {
		val << std::hex;
		val >> wallhackKey;
	}
	else if (name == "antiflashKey") {
		val << std::hex;
		val >> antiflashKey;
	}
	else if (name == "radarKey") {
		val << std::hex;
		val >> radarKey;
	}
	else if (name == "bhopKey") {
		val << std::hex;
		val >> bhopKey;
	}
}



void Config::CreateConfig() {
	std::ofstream cfgFile("config.txt");

	string cfgText =
		"// keybinds\n"
		"triggerKey = 0x62\n"
		"aimbotKey = 0x61\n"
		"wallhackKey = 0x60\n"
		"bhopKey = 0x63\n"
		"radarKey = 0x64\n"
		"antiflashKey = 0x65\n"
		"\n"
		"// autoaim FOV\n"
		"aimbot_fov = 5\n"
		"\n"
		"// knife ID (bayonet = 0, flip = 2, karambit = 4, m9bayonet = 5, huntsman = 6, falchion = 7, navaja = 14, stiletto = 16)\n"
		"knife_id = 5\n"
		"\n"
		"// skin layout\n"
		"desertEagle = 37\n"
		"dualBerettas = 625\n"
		"fiveSeven = 979\n"
		"glock18 = 957\n"
		"p2000 = 389\n"
		"p250 = 678\n"
		"tec9 = 179\n"
		"ak47 = 44\n"
		"aug = 690\n"
		"awp = 736\n"
		"famas = 919\n"
		"g3sg1 = 712\n"
		"galilAr = 1038\n"
		"m4a4 = 309\n"
		"scar20 = 597\n"
		"ssg08 = 1048\n"
		"mac10 = 433\n"
		"mp7 = 696\n"
		"mp9 = 1037\n"
		"ppBizon = 676\n"
		"p90 = 359\n"
		"ump45 = 556\n"
		"mag7 = 961\n"
		"nova = 537\n"
		"sawedOff = 638\n"
		"xm1014 = 850\n"
		"m249 = 902\n"
		"negev = 763\n"
		"usps = 1040\n"
		"m4a1s = 587\n"
		"cz75 = 270\n"
		"mp5sd = 915\n"
		"revolver = 522\n"
		"m9Bayonet = 577\n"
		"bayonet = 417\n"
		"flip = 572\n"
		"karambit = 38\n"
		"huntsman = 572\n"
		"falchion = 572\n"
		"navaja = 572\n"
		"stiletto = 572\n"
		;

	cfgFile << cfgText;
}