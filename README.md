# Road Fighter C++
A Road Fighter like game written in C++.
Installation requirements: CMake 3.10 and SFML 2.4.2
Binaries will be installed to /bin/, libraries to /lib/.
Installation via CLion: open project and run 'build all'.
Installation via command line: cmake ./ && make

## Guide
### Goal
To achieve the **highest score** possible. High scores will be kept in a save file in the **saves folder**.
### Score
You will **lose points** upon the following events:
 - *Driving backwards*: constant amount of points lost
 - *Crashing into a heavy vehicle*: 200 points lost
 - *Crashing into a light vehicle*: 100 points lost

You will **earn points** upon the following events:
 - *Driving forward*: constant amount of points earned
 - *Hitting passable vehicles*: 200 points earned

You will also **earn points** for finishing in a certain **position**:
 - *1st place*: 2000 points earned
 - *2nd place*: 1000 points earned
 - *3rd place*: 500 points earned

### Effects
There are different types of **effects** upon the following events:
 - *Crashing into a heavy vehicle*: your speed will decrease strongly and your motor will be disabled for a short duration
 - *Crashing into a light vehicle*: your speed will decrease
 - *Hitting passable vehicles*: the laser type bullets will make them vanish into thin air
 - *Hitting other racers*: other racers have strong protection and bullets will only slow them down

Other racers will experience the same effects, although they won't be able to shoot bullets.

### Ammo

 - Ammo capacity is **limited** to 20 bullets
 - You gain 5 bullets for each **ammo drop** you pick up
 - At the **start** of the game, you will already hold 5 bullets

### Controls

 - ***Up** arrow*: accelerate
 - ***Down** arrow:* decelerate
 - ***Left** arrow*: steer left
 - ***Right** arrow*: steer right
 - ***Space** bar*: shoot bullet (one bullet per space press)
 - ***Escape***: quit game

