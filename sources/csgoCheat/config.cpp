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
}



void Config::CreateConfig() {
	std::ofstream cfgFile("config.txt");

	string cfgText =
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








//void Config::LoadConfigs() {
//	ifstream configFile("config.txt");
//
//	string name;
//	while((configFile >> name >> value) || (configFile >> name)) {
//		
//		if(name == "wallhack_r") {
//			whR = value;
//		}
//		else if(name == "wallhack_g") {
//			whG = value;
//		}
//		else if (name == "wallhack_b") {
//			whB = value;
//		}
//		else if (name == "aimlock_r") {
//			alR = value;
//		}
//		else if (name == "aimlock_g") {
//			alG = value;
//		}
//		else if (name == "aimlock_b") {
//			alB = value;
//		}
//		else if (name == "aimbot_fov") {
//			aFOV = value;
//		}
//		else if (name == "desertEagle") {
//			desertEagle = value;
//		}
//		else if (name == "dualBerettas") {
//			dualBerettas = value;
//		}
//		else if (name == "fiveSeven") {
//			fiveSeven = value;
//		}
//		else if (name == "glock18") {
//			glock18 = value;
//		}
//		else if (name == "p2000") {
//			p2000 = value;
//		}
//		else if (name == "p250") {
//			p250 = value;
//		}
//		else if (name == "tec9") {
//			tec9 = value;
//		}
//		else if (name == "ak47") {
//			ak47 = value;
//		}
//		else if (name == "aug") {
//			aug = value;
//		}
//		else if (name == "awp") {
//			awp = value;
//		}
//		else if (name == "famas") {
//			famas = value;
//		}
//		else if (name == "g3sg1") {
//			g3sg1 = value;
//		}
//		else if (name == "galilAr") {
//			galilAr = value;
//		}
//		else if (name == "m4a4") {
//			m4a4 = value;
//		}
//		else if (name == "scar20") {
//			scar20 = value;
//		}
//		else if (name == "ssg08") {
//			ssg08 = value;
//		}
//		else if (name == "mac10") {
//			mac10 = value;
//		}
//		else if (name == "mp7") {
//			mp7 = value;
//		}
//		else if (name == "mp9") {
//			mp9 = value;
//		}
//		else if (name == "ppBizon") {
//			ppBizon = value;
//		}
//		else if (name == "p90") {
//			p90 = value;
//		}
//		else if (name == "ump45") {
//			ump45 = value;
//		}
//		else if (name == "mag7") {
//			mag7 = value;
//		}
//		else if (name == "nova") {
//			nova = value;
//		}
//		else if (name == "sawedOff") {
//			sawedOff = value;
//		}
//		else if (name == "xm1014") {
//			xm1014 = value;
//		}
//		else if (name == "m249") {
//			m249 = value;
//		}
//		else if (name == "negev") {
//			negev = value;
//		}
//		else if (name == "usps") {
//			usps = value;
//		}
//		else if (name == "m4a1s") {
//			m4a1s = value;
//		}
//		else if (name == "cz75") {
//			cz75 = value;
//		}
//		else if (name == "mp5sd") {
//			mp5sd = value;
//		}
//		else if (name == "revolver") {
//			revolver = value;
//		}
//		else if (name == "knife_id") {
//			knifeID = value;
//		}
//		else if (name == "m9Bayonet") {
//			m9Bayonet = value;
//		}
//		else if (name == "bayonet") {
//			bayonet = value;
//		}
//		else if (name == "flip") {
//			flip = value;
//		}
//		else if (name == "karambit") {
//			karambit = value;
//		}
//		else if (name == "huntsman") {
//			huntsman = value;
//		}
//		else if (name == "falchion") {
//			falchion = value;
//		}
//		else if (name == "navaja") {
//			navaja = value;
//		}
//		else if (name == "stiletto") {
//			stiletto = value;
//		}
//	}
//}