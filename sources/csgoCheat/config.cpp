#include <iostream>
#include <fstream>

#include "config.h"

Config config;

using namespace std;

void Config::LoadConfigs() {
	ifstream configFile("config.txt");

	string configName;
	while((configFile >> configName >> value) || (configFile >> configName)) {
		
		if(configName == "wallhack_r:") {
			whR = value;
		}
		else if(configName == "wallhack_g:") {
			whG = value;
		}
		else if (configName == "wallhack_b:") {
			whB = value;
		}
		else if (configName == "aimlock_r:") {
			alR = value;
		}
		else if (configName == "aimlock_g:") {
			alG = value;
		}
		else if (configName == "aimlock_b:") {
			alB = value;
		}
		else if (configName == "aimbot_fov:") {
			aFOV = value;
		}
		else if (configName == "desertEagle:") {
			desertEagle = value;
		}
		else if (configName == "dualBerettas:") {
			dualBerettas = value;
		}
		else if (configName == "fiveSeven:") {
			fiveSeven = value;
		}
		else if (configName == "glock18:") {
			glock18 = value;
		}
		else if (configName == "p2000:") {
			p2000 = value;
		}
		else if (configName == "p250:") {
			p250 = value;
		}
		else if (configName == "tec9:") {
			tec9 = value;
		}
		else if (configName == "ak47:") {
			ak47 = value;
		}
		else if (configName == "aug:") {
			aug = value;
		}
		else if (configName == "awp:") {
			awp = value;
		}
		else if (configName == "famas:") {
			famas = value;
		}
		else if (configName == "g3sg1:") {
			g3sg1 = value;
		}
		else if (configName == "galilAr:") {
			galilAr = value;
		}
		else if (configName == "m4a4:") {
			m4a4 = value;
		}
		else if (configName == "scar20:") {
			scar20 = value;
		}
		else if (configName == "ssg08:") {
			ssg08 = value;
		}
		else if (configName == "mac10:") {
			mac10 = value;
		}
		else if (configName == "mp7:") {
			mp7 = value;
		}
		else if (configName == "mp9:") {
			mp9 = value;
		}
		else if (configName == "ppBizon:") {
			ppBizon = value;
		}
		else if (configName == "p90:") {
			p90 = value;
		}
		else if (configName == "ump45:") {
			ump45 = value;
		}
		else if (configName == "mag7:") {
			mag7 = value;
		}
		else if (configName == "nova:") {
			nova = value;
		}
		else if (configName == "sawedOff:") {
			sawedOff = value;
		}
		else if (configName == "xm1014:") {
			xm1014 = value;
		}
		else if (configName == "m249:") {
			m249 = value;
		}
		else if (configName == "negev:") {
			negev = value;
		}
		else if (configName == "usps:") {
			usps = value;
		}
		else if (configName == "m4a1s:") {
			m4a1s = value;
		}
		else if (configName == "cz75:") {
			cz75 = value;
		}
		else if (configName == "mp5sd:") {
			mp5sd = value;
		}
		else if (configName == "revolver:") {
			revolver = value;
		}
		else if (configName == "knife_id:") {
			knifeID = value;
		}
		else if (configName == "m9Bayonet:") {
			m9Bayonet = value;
		}
		else if (configName == "bayonet:") {
			bayonet = value;
		}
		else if (configName == "flip:") {
			flip = value;
		}
		else if (configName == "karambit:") {
			karambit = value;
		}
		else if (configName == "huntsman:") {
			huntsman = value;
		}
		else if (configName == "falchion:") {
			falchion = value;
		}
		else if (configName == "navaja:") {
			navaja = value;
		}
		else if (configName == "stiletto:") {
			stiletto = value;
		}
	}
}