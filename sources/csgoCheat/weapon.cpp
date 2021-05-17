#include "weapon.h"


using namespace std;


Item cz75, desertEagle, dualBerettas, fiveSeven, glock18, p250, tec9, usps, revolver, p2000;
Item ak47, aug, awp, famas, g3sg1, galilAr, m4a4, sg553, scar20, ssg08, m4a1s;
Item mac10, mp5sd, mp7, mp9, ppBizon, p90, ump45;
Item mag7, nova, sawedOff, xm1014, m249, negev;
Item bayonet, flip, karambit, m9Bayonet, huntsman, falchion, navaja, stiletto;



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

	//knifeID = config.knifeID;
}




//int desertEagleStock[] = { 711, 805, 527, 231, 757, 37, 1006 };
//int dualBerettasStock[] = { 658, 625, 895, 491, 978 };
//int fiveSevenStock[] = { 837, 660, 427, 979 };
//int glock18Stock[] = { 957, 586, 963, 353, 38, 988 };
//int p2000Stock[] = { 389, 591 };
//int p250Stock[] = { 678, 551, 404, 388, 258, 501 };
//int tec9Stock[] = { 889, 614, 179 };
//int uspStock[] = { 504, 653, 705, 313, 637, 817, 991 };
//int cz75Stock[] = { 270, 643, 543, 350, 1036 };
//int revolverStock[] = { 522, 683, 595 };
//
//int ak47Stock[] = { 959, 801, 801, 675, 639, 639, 302, 490, 282, 44, 1018, 1035 };
//int augStock[] = { 280, 690, 9, 886, 583 };
//int awpStock[] = { 887, 917, 803, 475, 279, 756, 736, 446, 344, 691, 838, 975 };
//int galilArStock[] = { 398, 661, 647, 379, 1013, 981 };
//int famasStock[] = { 919, 604, 723, 626, 529, 999 };
//int g3s61Stock[] = { 511, 712, 628 };
//int m4a4Stock[] = { 309, 844, 512, 255, 971, 664, 588, 400, 449, 384, 167, 985 };
//int scar20Stock[] = { 597, 391, 312, 232 };
//int sg553Stock[] = { 897, 487, 750, 955, 1048 };
//int ssg09Stock[] = { 624, 222, 899 };
//int m4a1sStock[] = { 946, 587, 548, 497, 681, 301, 430, 360, 1001, 714, 644, 1017, 321, 440, 631, 984 };
//
//int mac10Stock[] = { 898, 433, 947, 310, 498, 38, 1009 };
//int mp7Stock[] = { 696, 481, 752, 847 };
//int mp9Stock[] = { 910, 609, 734, 262 };
//int ppBizonStock[] = { 542, 676, 508 };
//int p90Stock[] = { 359, 283, 759, 611 };
//int ump45Stock[] = { 556, 704, 37, 1003 };
//int mp5sdStock[] = { 915, 810, 846 };
//
//int mag7Stock[] = { 948, 737, 961 };
//int novaStock[] = { 537, 62, 356, 746 };
//int sawedOffStock[] = { 256, 720, 638, 638 };
//int xm1014Stock[] = { 850, 393 };
//int m249Stock[] = { 902, 496, 900 };
//int negevStock[] = { 763, 483, 432, 317 };


//int WeaponSkins::GetKnifeSkinID(int _knifeID) {
//	switch (_knifeID){
//	case 0:
//		return bayonet;
//	case 2:
//		return flip;
//	case 4:
//		return karambit;
//	case 5:
//		return m9Bayonet;
//	case 6:
//		return huntsman;
//	case 7:
//		return falchion;
//	case 14:
//		return navaja;
//	case 16:
//		return stiletto;
//	default:
//		break;
//	}
//}


//int WeaponSkins::GetSkinID(int _weaponID) {
//	switch (_weaponID) {
//	case 1:
//		return desertEagle;
//	case 2:
//		return dualBerettas;
//	case 3:
//		return fiveSeven;
//	case 4:
//		return glock18;
//	case 7:
//		return ak47;
//	case 8:
//		return aug;
//	case 9:
//		return awp;
//	case 10:
//		return famas;
//	case 11:
//		return g3sg1;
//	case 13:
//		return galilAr;
//	case 14:
//		return m249;
//	case 16:
//		return m4a4;
//	case 17:
//		return mac10;
//	case 19:
//		return p90;
//	case 262167:
//		return mp5sd;
//	case 24:
//		return ump45;
//	case 25:
//		return xm1014;
//	case 26:
//		return ppBizon;
//	case 27:
//		return mag7;
//	case 28:
//		return negev;
//	case 29:
//		return sawedOff;
//	case 30:
//		return tec9;
//	case 32:
//		return p2000;
//	case 33:
//		return mp7;
//	case 34:
//		return mp9;
//	case 35:
//		return nova;
//	case 36:
//		return p250;
//	case 38:
//		return scar20;
//	case 39:
//		return sg553;
//	case 40:
//		return ssg08;
//	case 262207:
//		return cz75;
//	case 262205:
//		return usps;
//	case 262204:
//		return m4a1s;
//	case 262208:
//		return revolver;
//	default:
//		return 0;
//	}
//}

//int WeaponSkins::GetRandomSkinID(int *_skinStock, int _length) {
//	srand((unsigned)time(0));
//	return _skinStock[rand() % (_length / sizeof(_skinStock[0]))];
//}
//
//
//bool WeaponSkins::AliveCheck() {
//	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
//	int health = mem.ReadMemory<int>(localPlayer + offsets.m_iHealth);
//	if (health == 0) {
//		return false;
//	} 
//	else {
//		return true;
//	}
//}
//
//
//void WeaponSkins::ChangeSkinLayout() {
//	desertEagle = GetRandomSkinID(desertEagleStock, sizeof(desertEagleStock));
//	dualBerettas = GetRandomSkinID(dualBerettasStock, sizeof(dualBerettasStock));
//	fiveSeven = GetRandomSkinID(fiveSevenStock, sizeof(fiveSevenStock));
//	glock18 = GetRandomSkinID(glock18Stock, sizeof(glock18Stock));
//	p2000 = GetRandomSkinID(p2000Stock, sizeof(p2000Stock));
//	p250 = GetRandomSkinID(p250Stock, sizeof(p250Stock));
//	tec9 = GetRandomSkinID(tec9Stock, sizeof(tec9Stock));
//	ak47 = GetRandomSkinID(ak47Stock, sizeof(ak47Stock));
//	aug = GetRandomSkinID(augStock, sizeof(augStock));
//	awp = GetRandomSkinID(awpStock, sizeof(awpStock));
//	famas = GetRandomSkinID(famasStock, sizeof(famasStock));
//	g3sg1 = GetRandomSkinID(g3s61Stock, sizeof(g3s61Stock));
//	galilAr = GetRandomSkinID(galilArStock, sizeof(galilArStock));
//	m4a4 = GetRandomSkinID(m4a4Stock, sizeof(m4a4Stock));
//	scar20 = GetRandomSkinID(scar20Stock, sizeof(scar20Stock));
//	sg553 = GetRandomSkinID(sg553Stock, sizeof(sg553Stock));
//	ssg08 = GetRandomSkinID(ssg09Stock, sizeof(ssg09Stock));
//	mac10 = GetRandomSkinID(mac10Stock, sizeof(mac10Stock));
//	mp7 = GetRandomSkinID(mp7Stock, sizeof(mp7Stock));
//	mp9 = GetRandomSkinID(mp9Stock, sizeof(mp9Stock));
//	ppBizon = GetRandomSkinID(ppBizonStock, sizeof(ppBizonStock));
//	p90 = GetRandomSkinID(p90Stock, sizeof(p90Stock));
//	ump45 = GetRandomSkinID(ump45Stock, sizeof(ump45Stock));
//	mag7 = GetRandomSkinID(mag7Stock, sizeof(mag7Stock));
//	nova = GetRandomSkinID(novaStock, sizeof(novaStock));
//	sawedOff = GetRandomSkinID(sawedOffStock, sizeof(sawedOffStock));
//	xm1014 = GetRandomSkinID(xm1014Stock, sizeof(xm1014Stock));
//	m249 = GetRandomSkinID(m249Stock, sizeof(m249Stock));
//	negev = GetRandomSkinID(negevStock, sizeof(negevStock));
//	usps = GetRandomSkinID(uspStock, sizeof(uspStock));
//	m4a1s = GetRandomSkinID(m4a1sStock, sizeof(m4a1sStock));
//	cz75 = GetRandomSkinID(cz75Stock, sizeof(cz75Stock));
//	mp5sd = GetRandomSkinID(mp5sdStock, sizeof(mp5sdStock));
//	revolver = GetRandomSkinID(revolverStock, sizeof(revolverStock));
//	cout << "Skin Layout Changed" << endl;
//	
//}


//void LoadSkinConfig() {
//	cz75 = config.cz75;
//	desertEagle = config.desertEagle;
//	dualBerettas = config.dualBerettas;
//	fiveSeven = config.fiveSeven;
//	glock18 = config.glock18;
//	p2000 = config.p2000;
//	p250 = config.p250;
//	tec9 = config.tec9;
//	ak47 = config.ak47;
//	aug = config.aug;
//	awp = config.awp;
//	famas = config.famas;
//	g3sg1 = config.g3sg1;
//	galilAr = config.galilAr;
//	m4a4 = config.m4a4;
//	scar20 = config.scar20;
//	sg553 = config.sg553;
//	ssg08 = config.ssg08;
//	mac10 = config.mac10;
//	mp5sd = config.mp5sd;
//	mp7 = config.mp7;
//	mp9 = config.mp9;
//	ppBizon = config.ppBizon;
//	p90 = config.p90;
//	ump45 = config.ump45;
//	mag7 = config.mag7;
//	nova = config.nova;
//	sawedOff = config.sawedOff;
//	xm1014 = config.xm1014;
//	m249 = config.m249;
//	negev = config.negev;
//	usps = config.usps;
//	m4a1s = config.m4a1s;
//	revolver = config.revolver;
//	knifeID = config.knifeID;
//	bayonet = config.bayonet;
//	flip = config.flip;
//	karambit = config.karambit;
//	m9Bayonet = config.m9Bayonet;
//	huntsman = config.huntsman;
//	falchion = config.falchion;
//	navaja = config.navaja;
//	stiletto = config.stiletto;
//}


//void WeaponSkins::RandomSkinChanger() {
//	if (!AliveCheck() && alive) {
//		alive = false;
//		ChangeSkinLayout();
//	} 
//	else if (AliveCheck() && !alive) {
//		alive = true;
//	}
//}