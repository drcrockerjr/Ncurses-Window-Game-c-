# Ncurses-Window-Game-c++

This is an game that I created for my computer science university course.



How to Appease:
- in order to not lose the game by touching the TA("T" blocks), the player("*") must collect at least one programming skill("$") and press "p" while within range of the TA. This will cause the TA to change from:

TTT-->AAA
TTT-->AAA

The TA will remain in this form for ten turns(ten key presses). In this form the player may touch the TA until this time passes.



AI functionality:
The game allows for the player to press the "a" key in order to determine a move to make based on the following conditions:

- if the player has no programming skills currently, the ai move will move the player towards the closest programming skill.
- if the player has at least one programming skill and is in proximity of an unappeased TA, the ai move will appease the TA. 



How to Win:
- You win the game by collecting at least 3 "Programming Skills"("$") character and then reaching the instructor("%").



How to Lose:
- One way to lose lose the game by touching the instructor("%") without having at least 3 programming skills("$")
- The second way to lose the game is by touching a TA, ("T" blocks), without appeasing that TA with at least one programming skill.
