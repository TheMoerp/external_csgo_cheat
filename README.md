# CS:GO Moerper

  

CS:GO Moerper is an external multicheat. It's just an experimental project and it's not intended for cheating in competitive matchmaking. Nobody likes tryhard cheater!

  

### Features
- Wallhack
- Autoaim/Aimbot
- Triggerbot
- Bhop script
- Skinchanger

 
## Usage

To use it you have to install *Visual Studio* with the Workload *Desktop development with C++*.
If everything is compiled and ready, you need to start cs:go and then start the *csgoCheat.exe*.
The cheat will grab the running process and you're ready to go.
Since this is an external cheat some features can be glitchy at times.

In case the cheat doesn't work check the offsets at [frk1/hazedumper](https://github.com/frk1/hazedumper/blob/master/csgo.cs)

##### Wallhack
Toggle the wallhack with the key **NUM_0**. Enemys will glow red.
##### Autoaim/Aimbot
Toggle the autoaim with the key **NUM_1**. When the crosshair is near the enemy's head and you leftclick, it will automatically shoot the enemy's head. It's most efficient when triggerbot and autoaim aren't on at the same time.

You can change the FOV in which the enemy has to be to trigger the autobot in the file *Aimbot1.h*:

    const int AIM_FOV = 5;

##### Triggerbot
Toggle the triggerbot with the key **NUM_2**. It will shoot if you hover over an enemy hitbox. The shooting interval equals the recovery time of the current weapon.

##### Bhop script
Toggle the bhop script with the key **NUM_3**. Just keep pressing **Space** an start bhopping.
##### Skinchanger
The standart skinlayout is set my some nice skins. You can also get a new random skinlayout everytime you die. To toggle the randomness press **NUM_x**.

  

Since the knifechanger can be pretty glitchy I recomment to create a autoconfig file for csgo. Just create a file named autoexec.txt in `Programm Files (x86)/Steam/steamapps/common/Counter-Strike Global Offensive/csgo/csfg` and write the following lines:

    

    bind f4 "record 1;stop;"
    host_writeconfig

  

Then save it and rename the file to *autoexec.cvg*.

Now everytime the knifemodel or the skins won't load just press *F4* to force update.

If you wish you can adjust the skinlayouts in the *WeaponSkins.cpp* file.

    void WeaponSkins::StandartSkinLayout() {
    // Weapons
	desertEagle = 37;
	dualBerettas = 625;
	[...]
	revolver = 522;
	
	// Knifes
	knifeID = 5;
	m9Bayonet = 572;  // KID: 5
	[...]
	}

Just look up the skin IDs at [csgostash](https://csgostash.com/).

  
  

#### USE AT YOUR OWN RISK!!!
