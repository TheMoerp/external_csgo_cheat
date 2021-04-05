#include <iostream>
#include <ctime>
#include <cstdlib>

#include "WeaponSkins.h"


WeaponSkins weaponSkins;
using namespace std;


int desertEagleStock[] = { 711, 805, 527, 231, 757, 37, 1006 };
int dualBerettasStock[] = { 658, 625, 895, 491, 978 };
int fiveSevenStock[] = { 837, 660, 427, 979 };
int glock18Stock[] = { 957, 586, 963, 353, 38, 988 };
int p2000Stock[] = { 389, 591 };
int p250Stock[] = { 678, 551, 404, 388, 258, 501 };
int tec9Stock[] = { 889, 614, 179 };
int uspStock[] = { 504, 653, 705, 313, 637, 817, 991 };

int ak47Stock[] = { 959, 801, 801, 675, 639, 639, 302, 490, 282, 44 };
int augStock[] = { 280, 690, 9, 886, 583 };
int awpStock[] = { 887, 917, 803, 475, 279, 756, 736, 446, 344, 691, 838, 975 };
int galilArStock[] = { 398, 661, 647, 379, 1013 };
int famasStock[] = { 919, 604, 723, 626, 529, 999 };
int g3s61Stock[] = { 511, 712, 628 };
int m4a4Stock[] = { 309, 844, 512, 255, 971, 664, 588, 400, 449, 384, 167 };
int scar20Stock[] = { 597, 391, 312, 232 };
int sg553Stock[] = { 897, 487, 750, 955 };
int ssg09Stock[] = { 624, 222, 899 };
int m4a1sStock[] = { 946, 587, 548, 497, 430, 360, 1001, 714, 644, 1017, 321, 440, 631, 984 };

int mac10Stock[] = { 898, 433, 947, 310, 498, 38, 1009 };
int mp7Stock[] = { 696, 481, 752, 847 };
int mp9Stock[] = { 910, 609, 734, 262 };
int ppBizonStock[] = { 542, 676, 508 };
int p90Stock[] = { 359, 283, 759, 611 };
int ump45Stock[] = { 556, 704, 37, 1003 };

int mag7Stock[] = { 948, 737, 961 };
int novaStock[] = { 537, 62, 356, 746 };
int sawedOffStock[] = { 256, 720, 638, 638 };
int xm1014Stock[] = { 850, 393 };
int m249Stock[] = { 902, 496, 900 };
int negevStock[] = { 763, 483, 432, 317 };


int WeaponSkins::GetSkinID(int _weaponID) {
	switch (_weaponID) {
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
	case 23:
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
	case 63:
		return cz75;
	case 262205:
		return usps;
	case 262204:
		return m4a1s;
	default:
		return 0;
	}
}


int WeaponSkins::getRandomSkinID(int *_skinStock, int _length) {
	srand((unsigned)time(0));
	return _skinStock[rand() % (_length / sizeof(_skinStock[0]))];
}


bool WeaponSkins::AliveCheck() {
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	int health = mem.ReadMemory<int>(localPlayer + offsets.m_iHealth);
	if (health == 0) {
		return false;
	} 
	else {
		return true;
	}
}


void WeaponSkins::ChangeSkinLayout() {
	desertEagle = getRandomSkinID(desertEagleStock, sizeof(desertEagleStock));
	dualBerettas = getRandomSkinID(dualBerettasStock, sizeof(dualBerettasStock));
	fiveSeven = getRandomSkinID(fiveSevenStock, sizeof(fiveSevenStock));
	glock18 = getRandomSkinID(glock18Stock, sizeof(glock18Stock));
	p2000 = getRandomSkinID(p2000Stock, sizeof(p2000Stock));
	p250 = getRandomSkinID(p250Stock, sizeof(p250Stock));
	tec9 = getRandomSkinID(tec9Stock, sizeof(tec9Stock));
	ak47 = getRandomSkinID(ak47Stock, sizeof(ak47Stock));
	aug = getRandomSkinID(augStock, sizeof(augStock));
	awp = getRandomSkinID(awpStock, sizeof(awpStock));
	famas = getRandomSkinID(famasStock, sizeof(famasStock));
	g3sg1 = getRandomSkinID(g3s61Stock, sizeof(g3s61Stock));
	galilAr = getRandomSkinID(galilArStock, sizeof(galilArStock));
	m4a4 = getRandomSkinID(m4a4Stock, sizeof(m4a4Stock));
	scar20 = getRandomSkinID(scar20Stock, sizeof(scar20Stock));
	sg553 = getRandomSkinID(sg553Stock, sizeof(sg553Stock));
	ssg08 = getRandomSkinID(ssg09Stock, sizeof(ssg09Stock));
	mac10 = getRandomSkinID(mac10Stock, sizeof(mac10Stock));
	mp7 = getRandomSkinID(mp7Stock, sizeof(mp7Stock));
	mp9 = getRandomSkinID(mp9Stock, sizeof(mp9Stock));
	ppBizon = getRandomSkinID(ppBizonStock, sizeof(ppBizonStock));
	p90 = getRandomSkinID(p90Stock, sizeof(p90Stock));
	ump45 = getRandomSkinID(ump45Stock, sizeof(ump45Stock));
	mag7 = getRandomSkinID(mag7Stock, sizeof(mag7Stock));
	nova = getRandomSkinID(novaStock, sizeof(novaStock));
	sawedOff = getRandomSkinID(sawedOffStock, sizeof(sawedOffStock));
	xm1014 = getRandomSkinID(xm1014Stock, sizeof(xm1014Stock));
	m249 = getRandomSkinID(m249Stock, sizeof(m249Stock));
	negev = getRandomSkinID(negevStock, sizeof(negevStock));
	usps = getRandomSkinID(uspStock, sizeof(uspStock));
	m4a1s = getRandomSkinID(m4a1sStock, sizeof(m4a1sStock));

	cout << "Skin Layout Changed." << endl;
}


void WeaponSkins::RandomSkinChanger() {
	if (!AliveCheck() && alive) {
		alive = false;
		ChangeSkinLayout();
	} 
	else if (AliveCheck() && !alive) {
		alive = true;
	}
}