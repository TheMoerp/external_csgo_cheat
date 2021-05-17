#include "weapon.h"


using namespace std;


Item cz75, desertEagle, dualBerettas, fiveSeven, glock18, p250, tec9, usps, revolver, p2000;
Item ak47, aug, awp, famas, g3sg1, galilAr, m4a4, sg553, scar20, ssg08, m4a1s;
Item mac10, mp5sd, mp7, mp9, ppBizon, p90, ump45;
Item mag7, nova, sawedOff, xm1014, m249, negev;
Item bayonet, flip, karambit, m9Bayonet, huntsman, falchion, navaja, stiletto;


// Returns an Item object matching to the paramter id
Item GetItemByID(int itemID) {
	Item unknownItem;
	unknownItem.skinID = 0;
	switch (itemID) {
	case 1:
		return desertEagle;
	case 2:
		return dualBerettas;
	case 3:
		return fiveSeven;
	case 4:
		return glock18;
	case 7:
		return ak47;
	case 8:
		return aug;
	case 9:
		return awp;
	case 10:
		return famas;
	case 11:
		return g3sg1;
	case 13:
		return galilAr;
	case 14:
		return m249;
	case 16:
		return m4a4;
	case 17:
		return mac10;
	case 19:
		return p90;
	case 262167:
		return mp5sd;
	case 24:
		return ump45;
	case 25:
		return xm1014;
	case 26:
		return ppBizon;
	case 27:
		return mag7;
	case 28:
		return negev;
	case 29:
		return sawedOff;
	case 30:
		return tec9;
	case 32:
		return p2000;
	case 33:
		return mp7;
	case 34:
		return mp9;
	case 35:
		return nova;
	case 36:
		return p250;
	case 38:
		return scar20;
	case 39:
		return sg553;
	case 40:
		return ssg08;
	case 262207:
		return cz75;
	case 262205:
		return usps;
	case 262204:
		return m4a1s;
	case 262208:
		return revolver;
	case 500:
		return bayonet;
	case 505:
		return flip;
	case 512:
		return falchion;
	case 522:
		return stiletto;
	case 508:
		return m9Bayonet;
	case 520:
		return navaja;
	case 509:
		return huntsman;
	default:
		return unknownItem;
	}
}


// Returns the DefinitionID of a knife
int GetKnifeItemDefinitionID(int knifeID) {
	switch (knifeID) {
	case 0:
		return 500;
	case 2:
		return 505;
	case 4:
		return 507;
	case 5:
		return 508;
	case 6:
		return 509;
	case 7:
		return 512;
	case 14:
		return 520;
	case 16:
		return 522;
	default:
		break;
	}
}


// Loads skin config
void LoadSkinConfig() {
	cz75.rstTime = 243;
	desertEagle.rstTime = 812;
	dualBerettas.rstTime = 525;
	fiveSeven.rstTime = 201;
	glock18.rstTime = 201;
	p2000.rstTime = 350;
	p250.rstTime = 346;
	usps.rstTime = 392;
	ak47.rstTime = 350;
	aug.rstTime = 369;
	awp.rstTime = 430;
	famas.rstTime = 350;
	g3sg1.rstTime = 251;
	galilAr.rstTime = 545;
	m4a4.rstTime = 301;
	m4a1s.rstTime = 339;
	scar20.rstTime = 545;
	sg553.rstTime = 453;
	ssg08.rstTime = 143;
	mac10.rstTime = 400;
	mp5sd.rstTime = 438;
	mp7.rstTime = 438;
	mp9.rstTime = 258;
	ppBizon.rstTime = 332;
	p90.rstTime = 350;
	ump45.rstTime = 400;
	mag7.rstTime = 461;
	nova.rstTime = 461;
	sawedOff.rstTime = 506;
	m249.rstTime = 829;
	negev.rstTime = 301;

	cz75.skinID = config.cz75;
	desertEagle.skinID = config.desertEagle;
	dualBerettas.skinID = config.dualBerettas;
	fiveSeven.skinID = config.fiveSeven;
	glock18.skinID = config.glock18;
	p2000.skinID = config.p2000;
	p250.skinID = config.p250;
	tec9.skinID = config.tec9;
	ak47.skinID = config.ak47;
	aug.skinID = config.aug;
	awp.skinID = config.awp;
	famas.skinID = config.famas;
	g3sg1.skinID = config.g3sg1;
	galilAr.skinID = config.galilAr;
	m4a4.skinID = config.m4a4;
	scar20.skinID = config.scar20;
	sg553.skinID = config.sg553;
	ssg08.skinID = config.ssg08;
	mac10.skinID = config.mac10;
	mp5sd.skinID = config.mp5sd;
	mp7.skinID = config.mp7;
	mp9.skinID = config.mp9;
	ppBizon.skinID = config.ppBizon;
	p90.skinID = config.p90;
	ump45.skinID = config.ump45;
	mag7.skinID = config.mag7;
	nova.skinID = config.nova;
	sawedOff.skinID = config.sawedOff;
	xm1014.skinID = config.xm1014;
	m249.skinID = config.m249;
	negev.skinID = config.negev;
	usps.skinID = config.usps;
	m4a1s.skinID = config.m4a1s;
	revolver.skinID = config.revolver;
	bayonet.skinID = config.bayonet;
	flip.skinID = config.flip;
	karambit.skinID = config.karambit;
	m9Bayonet.skinID = config.m9Bayonet;
	huntsman.skinID = config.huntsman;
	falchion.skinID = config.falchion;
	navaja.skinID = config.navaja;
	stiletto.skinID = config.stiletto;
}