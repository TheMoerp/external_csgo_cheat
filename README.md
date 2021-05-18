# TheMoerper external

  

*TheMoerper external* is a lightweight external multicheat. It's just an experimental project and it's not intended for cheating in competitive matchmaking. Nobody likes tryhard cheater!

![Preview](https://github.com/TheMoerp/external_csgo_cheat/blob/master/images/themoerper_ext_preview.png)

### Features
- Wallhack
- Radar
- Autoaim/Aimbot
- Triggerbot
- Bhop script
- Antiflash 
- Skinchanger
 
## Usage

To use it you have to install [Visual Studio](https://visualstudio.microsoft.com/de/downloads/) with the Workload *Desktop development with C++*.
Compile with the *x86* option. If everything is compiled and ready, you need to start cs:go and then run the *csgoCheat.exe*. *csgoCheat.exe* must be in the same directory as *config.txt*.
The cheat will grab the running process and you're ready to go.
Since this is an external cheat some features can be glitchy at times.

There is no patternscan implemented yet you have to update the offsets manually. You can reverse them by hand or look them up at [frk1/hazedumper](https://github.com/frk1/hazedumper/blob/master/csgo.cs) since most of the used offsets are included in this list.

##### Wallhack
Toggle the wallhack with the key **NUM_0**. Enemys will glow red.

##### Radar
Toggle the radar with the key **NUM_5**. Enemys will be marked as spotted on the radar.

##### Autoaim/Aimbot
Toggle the autoaim with the key **NUM_1**. When the crosshair is near the enemy's head and you leftclick, it will automatically shoot the enemy's head. It's most efficient when triggerbot and autoaim aren't on at the same time.

##### Triggerbot
Toggle the triggerbot with the key **NUM_2**. It will shoot if you hover over an enemy hitbox. The shooting interval equals the recovery time of the current weapon.

##### Bhop script
Toggle the bhop script with the key **NUM_3**. Just keep pressing **Space** an start bhopping.

##### Antiflash
Toggle the antiflash with the key **NUM_4**. No more looking away for you :).

##### Skinchanger
Since the knifechanger can be pretty glitchy I recomment to create a autoconfig file for csgo. Just create a file named *autoexec.txt* in `Programm Files (x86)/Steam/steamapps/common/Counter-Strike Global Offensive/csgo/csfg` and write the following lines:
    

    bind f4 "record 1;stop;"
    host_writeconfig

  
Then save it and rename the file to *autoexec.cvg*.

Now everytime the knifemodel or the skins won't load just press **F4** to force update.

You can set custom hotkeys and change the skinlayout in the file *config.txt*.
You can look up skin IDs at [csgostash.com](https://csgostash.com/) and Virtual-Key Codes at [docs.microsoft.com](https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes).
  

#### USE AT YOUR OWN RISK!!!
