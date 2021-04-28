
# CS:GO Moerper

CS:GO Moerper is an external multicheat. It's just an experimental project and it's not intended for cheating in competitive matchmaking. Nobody likes tryhard cheater!

### Features
- Wallhack
- Autoaim/Aimbot
- Triggerbot
- Bhop script
- Skinchanger (only weapons)

## Usage

To use it you have to install *Visual Studio* with the Workload *Desktop development with C++*.
If everything is compiled and ready, you need to start cs:go and then start the *csgoCheat.exe*.
The cheat will grab the running process and you're ready to go.
Since this is an external cheat some features can be glitchy at times.

  

##### Wallhack
Toggle the wallhack with the key **X**. Enemys will glow red.

##### Autoaim/Aimbot
Toggle the autoaim with the key **C**. When the crosshair is near the enemy's head and you leftclick, it will automatically shoot the enemy's head. It's most efficient when triggerbot and autoaim aren't on at the same time.

##### Triggerbot
Toggle the triggerbot with the key **V**. It will shoot if you hover over an enemy hitbox. The shooting interval equals the recovery time of the current weapon.

##### Bhop script
Toggle the bhop script with the key **N**. Just keep pressing **Space** an start bhopping.
##### Skinchanger
The standart skinlayout is set my some nice skins. You can also get a new random skinlayout everytime you die. To toggle the randomness press **L**.

Since the knifechanger can be pretty glitchy I recomment to create a autoconfig file for csgo. Just create a file named autoexec.txt in `Programm Files (x86)/Steam/steamapps/common/Counter-Strike Global Offensive/csgo/csfg` and write the following lines:

    bind f4 "record 1;stop;"
    host_writeconfig

Then save it and rename the file to *autoexec.cvg*.
Now everytime the knifemodel or the skins won't load just press *F4* to force update.

If you wish you can adjust the skinlayouts in the *WeaponSkins.cpp* file. Just look up the skin IDs at [csgostash](https://csgostash.com/).


#### USE AT YOUR OWN RISK!!!