#include "changeskinlayout.h"

using namespace std;

ChangeSkinLayout::ChangeSkinLayout(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    setWindowTitle("Skinlayout");

    lineAK47 = ui.lineAK47;
    lineAUG = ui.lineAUG;
    lineAWP = ui.lineAWP;
    lineCZ75 = ui.lineCZ75;
    lineDesartEagle = ui.lineDesartEagle;
    lineDualBerettas = ui.lineDualBerettas;
    lineFAMAS = ui.lineFAMAS;
    lineFiveSeven = ui.lineFiveSeven;
    lineG35G1 = ui.lineG35G1;
    lineGalilAR = ui.lineGalilAR;
    lineGlock18 = ui.lineGlock18;
    lineKnifeSkin = ui.lineKnifeSkin;
    lineM249 = ui.lineM249;
    lineM4A1S = ui.lineM4A1S;
    lineM4A4 = ui.lineM4A4;
    lineMAC10 = ui.lineMAC10;
    lineMAG7 = ui.lineMAG7;
    lineMP5SD = ui.lineMP5SD;
    lineMP7 = ui.lineMP7;
    lineMP9 = ui.lineMP9;
    lineNegev = ui.lineNegev;
    lineNova = ui.lineNova;
    lineP2000 = ui.lineP2000;
    lineP250 = ui.lineP250;
    lineP90 = ui.lineP90;
    linePPBizon = ui.linePPBizon;
    lineRevolver = ui.lineRevolver;
    lineSCAR20 = ui.lineSCAR20;
    lineSG553 = ui.lineSG553;
    lineSSG08 = ui.lineSSG08;
    lineSawedOff = ui.lineSawedOff;
    lineTec9 = ui.lineTec9;
    lineUMP45 = ui.lineUMP45;
    lineUSPS = ui.lineUSPS;
    lineXM1014 = ui.lineXM1014;
    lineKnife = ui.lineKnifeSkin;

    comboKnife = ui.comboKnifeModel;

    pushConfirm = ui.pushConfirm;
}


void ChangeSkinLayout::LoadSkinConfig() {
    ifstream skinlayout("skinlayout.txt");

    if (skinlayout.good()) {

        if (skinlayout.is_open()) {
            string line;
            while (getline(skinlayout, line)) {
                auto delimiterPos = line.find("=");
                string name = line.substr(0, delimiterPos);
                string value = line.substr(delimiterPos + 1);

                int cz75, desertEagle, dualBerettas, fiveSeven, glock18, p2000, p250, tec9, ak47, aug, awp, famas, g3sg1,
                    galilAr, m4a4, scar20, sg553, ssg08, mac10, mp5sd, mp7, mp9, ppBizon, p90, ump45, mag7, nova, sawedOff,
                    xm1014, m249, negev, usps, m4a1s, revolver, knifeModel, knifeSkin;

                stringstream val(value);
                if (name == "desertEagle") {
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
                    val >> knifeModel;
                }
                else if (name == "knife_skin") {
                    val >> knifeSkin;
                }

                lineAK47->setText(QString::number(ak47));
                lineAUG->setText(QString::number(aug));
                lineAWP->setText(QString::number(awp));
                lineCZ75->setText(QString::number(cz75));
                lineDesartEagle->setText(QString::number(desertEagle));
                lineDualBerettas->setText(QString::number(dualBerettas));
                lineFAMAS->setText(QString::number(famas));
                lineFiveSeven->setText(QString::number(fiveSeven));
                lineG35G1->setText(QString::number(g3sg1));
                lineGalilAR->setText(QString::number(galilAr));
                lineGlock18->setText(QString::number(glock18));
                lineKnifeSkin->setText(QString::number(knifeSkin));
                lineM249->setText(QString::number(m249));
                lineM4A1S->setText(QString::number(m4a1s));
                lineM4A4->setText(QString::number(m4a4));
                lineMAC10->setText(QString::number(mac10));
                lineMAG7->setText(QString::number(mag7));
                lineMP5SD->setText(QString::number(mp5sd));
                lineMP7->setText(QString::number(mp7));
                lineMP9->setText(QString::number(mp9));
                lineNegev->setText(QString::number(negev));
                lineNova->setText(QString::number(nova));
                lineP2000->setText(QString::number(p2000));
                lineP250->setText(QString::number(p250));
                lineP90->setText(QString::number(p90));
                linePPBizon->setText(QString::number(ppBizon));
                lineRevolver->setText(QString::number(revolver));
                lineSCAR20->setText(QString::number(scar20));
                lineSG553->setText(QString::number(sg553));
                lineSSG08->setText(QString::number(ssg08));
                lineSawedOff->setText(QString::number(sawedOff));
                lineTec9->setText(QString::number(tec9));
                lineUMP45->setText(QString::number(ump45));
                lineUSPS->setText(QString::number(usps));
                lineXM1014->setText(QString::number(xm1014));
            }
        }
    }
}


void ChangeSkinLayout::SaveSkinLayout() {

}
