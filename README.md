# OpenSpades+
# Revision 12

[![AppVeyor](https://img.shields.io/appveyor/build/nonperforming/openspadesplus?style=flat-square&logo=appveyor&cacheSeconds=60)](https://ci.appveyor.com/project/nonperforming/openspadesplus)
[![Downloads](https://img.shields.io/github/downloads/nonperforming/openspadesplus/total?color=yellow&style=flat-square)](https://github.com/nonperforming/openspadesplus/releases/latest)
[![Latest](https://img.shields.io/github/v/release/nonperforming/openspadesplus?style=flat-square&cacheSeconds=600)](https://github.com/nonperforming/openspadesplus/releases)
[![Discord](https://img.shields.io/discord/1041996994639573012?label=discord&logo=discord&style=flat-square)](https://discord.gg/KgJDe5cBGM)
[![License](https://img.shields.io/github/license/nonperforming/openspadesplus?style=flat-square&cacheSeconds=86400)](https://github.com/nonperforming/openspadesplus/blob/main/LICENSE)

[PLEASE READ THE ENTIRE README.md FILE BEFORE USING](https://github.com/nonperforming/openspadesplus#important)
## What is this?
OpenSpades+ is a modification of [OpenSpades](https://github.com/yvt/openspades) that has many competivive-sided tweaks such as

* The [default settings](https://github.com/nonperforming/openspadesplus/blob/main/info/diff.md) falling more towards competitive play
* No FOV cap (server may limit this)
* No falling blocks hindering visibility and possibly causing lag spikes (can be toggled, server may limit this)
* A crosshair more akin to classic FPS games such as CS:GO (seven to pick from currently, feel free to open a PR to add more!)
* No ragdolls or corpses whatsoever (can be toggled)
* Hiding the view-model for extra screen space (can be toggled)

It also has some other features, though not as major

* More concise messages (messages will **never** give less information than vanilla)
* Cleaner stats interface along with some extras (OS+ revision)
* Extended player name length and no restriction to ASCII only (needs to be tested)
* Shows useful variables in the Preferences menu
* A custom map background (two currently, feel free to open a PR to add more!)
* Encouraging words on the pause menu! (I swear it's not cheating)

This project also aims to be in line with OpenSpades [NotToDo](https://github.com/yvt/openspades/wiki/NotToDo) where applicable

## But what if I want the viewmodel or the default crosshair?
No problem! Almost all the changes here are implemented in such a way so that toggling a variable i.e toggling `p_viewmodel` will turn on or off the change, sometimes with a relaunch. For crosshairs, if you want the default crosshair back but keep all the other changes, you just copy the contents of `Resources/Gfx/Crosshairs/Default` into `Resources/Gfx` for the default crosshair.

## How to build?
[Just build like normal OpenSpades.](https://github.com/yvt/openspades/wiki/Building)
If you are on Linux and have all the dependencies installed there is a convenient [file](https://github.com/nonperforming/openspadesplus/blob/master/build.ps1) that will run all the necessary commands to build OpenSpades+. Occasionally there will be bugs preventing you from launching or building the game (especially in the experimental branch) - in that case, please download the source code from the latest Release or fix the bug yourself (PRs welcome!).

## What if I don't want to/can't build?
Check the [Releases](https://github.com/nonperforming/openspadesplus/releases) tab for the latest stable release. Otherwise, check [AppVeyor](https://ci.appveyor.com/project/nonperforming/openspadesplus/build/artifacts) for the latest bleeding-edge releases.

## Useful console variables
Most, if not all of these variables should be under the Options/Preferences menu, should you need it.

### cg_particles
Default: 0

As simple as it gets. Turn particles on or off along with some extra settings. This can and will hide grenade particles, which may be useful. THIS DOES NOT HIDE TRACERS

### cg_ragdoll
Default: 0

Setting this to 0 (model instead of dynamic ragdoll) seemingly has marginally less impact than when set to 1. There is no point in setting this to 1 if `p_corpse` is set to 0 since OpenSpades+ removes ragdolls and said model.

### r_vsync
Default: 0

Unlimit refresh rate and decrease input delay. ***Highly recommended not to turn this on.***

### r_fullscreen
Default: 1

Launch the game in fullscreen and be immersed in the game.

### cl_fps
Default: 0

No FPS cap.

### cg_environmentalAudio
Default: 1

This turns on those fancy calculations for more precise and accurate sound, though sounds may appear more quiet.

### cg_stats
Default: 1

Show extra information such as accuracy (todo), FPS, ping, etc. ***Highly recommended not to turn this off.***

### cg_fov
Default: 90

FOV is very a preferential thing. For most people 90 FOV is fine; though nobody's judging you, go crazy and set it to 1 or 179 (anything more or less breaks the game - I'm not stopping you though!)

### cg_ejectBrass
Default: 0

Disables the distracting shell casings when firing your weapon, also slightly improving performance. ***Highly recommended not to turn this on.***

### cg_shake
Default: 0

Disables the screen shake on grenades or shooting. It's just an annoyance most of the time.

### cg_holdAimDownSight
Default: 1

This is the default for a reason. It is self explanatory.

### cg_tracersFirstPerson
Default: 0

Remove the bright yellow tracers that are shot by you, the player. Other players' tracers won't be affected. Note that this also affects the minimap.

### cg_skipDeadPlayersWhenDead
Default: 0

Spectate where a player died, which can be great for callouts. ***Highly recommended not to turn this on.***

### cg_stats
Default: 1

Show FPS, Ping, OS+ revision, Accuracy (TODO) and IP (TODO) of connected server when enabled. ***Highly recommended not to turn this off.***

### cg_alertSounds
Default: 1

Turns off the sound when attempting to switch to a weapon with no ammo, or when the server requests it.

### cg_animations
Default: 0

Remove many animations, such at the scope-in animation when aiming down sights.

### p_hurtTint
Default: 1

Turns on or off tinting the screen when damaged (cooldown of 1.5 seconds) (STUB)

### p_hurtBlood
Default: 0

Turns on or off the blood decals when damaged, which may slightly obstruct vision and be a distraction in the most important time in the game - a gunfight (cooldown of 1.5 seconds) (STUB)

### p_viewmodel
Default: 0

Turns the viewmodel on or off.

### p_streamer
Default: 0

Hides the server IP from cg_stats and sanitises player names (STUB)

### p_customClientMessage
Default: Nothing

Append text to your client info - anything you'd like.

### p_showAccuracyUnderMap
Default: 0

(STUB)

### p_showAccuracyInStats
Default: 1

(STUB)

### p_corpse
Default: 0

Spawn corpses/ragdolls when a player dies.

### p_hidePalette
Default: 0

(STUB) Hides the block colo(u)r palette.

### p_fallingBlocks
Default: 0

Shows falling blocks

## Other
### !!IMPORTANT!!
Save files and game files are kept seperate from OpenSpades. This does not include mod `.pak`s or folders, though it is planned for OpenSpades+ to load mods from the folder `OSMods` instead which allows you to have OpenSpades+ specific mods. It is nigh impossible that OpenSpades+ will bork or even modify an OpenSpades install in any way. To use your OpenSpades config file as a template/your config file for OpenSpades+, you can copy your `SPConfig.cfg` over to `OSPlus.cfg` in the same folder. Please notice that OpenSpades+ uses different default options which you may find helpful. You can always set them manually however, see ["Useful console variables"](https://github.com/nonperforming/openspadesplus#useful-console-variables). There is a list of differences between OpenSpades+ and OpenSpades settings [here](https://github.com/nonperforming/openspadesplus/blob/main/info/diff.md)

### To-do:
* Remove ragdolls and corpses cleaner code
* Accuracy in cg_stats or other
* Players left in cg_stats or other
* Reload progress bar below the crosshair or in cg_stats - partially done in the form of percentage in "Reloading" text
* Variable for muzzle flash/light when shooting (player)
* Load mods from a specific folder (i.e. OS+ specific weapon mods/soundmods)
* A streamer mode (disable global chat, Hide IP in stats, sanitize player names) (TODO)
* Show player weapons on the scoreboard if the server allows it (TODO)
* Show player health on mouse-over and scoreboard when server has /hp or /health enabled (TODO)
* Show weapons on the leaderboard if the server has /weapon enabled (TODO)
* Streamer-friendly (disable chat, hide ip, sanitize player names) ((todo))
* Show IP in cg_stats
* Change teams in the Limbo menu by using the Q, W, and E keys
* Allow ghosts to use the flashlight (bugged currently while in freecam)
* Fix flashlight
* Less harsh and digestible flashlight


### On commit:
Bump OpenSpades+ revision level in OpenSpadesPlus.cpp and in README.md, also in PackageInfo.json

## Statistics
![Alt](https://repobeats.axiom.co/api/embed/7a95a0e7782fa65df3b7786c36c7ab572aef12f4.svg "Repobeats analytics image")