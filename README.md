# Text Based RPG
 > Authors: \<[Stanton Zeng](https://github.com/Lionblaze218)\>
 > \<[Jacob Yee](https://github.com/yeetfarm)\>
 > \<[Cruz Ramirez](https://github.com/Qrooz)\>
 >
## Project Description
 > We decided a text-based RPG is interesting to us because it sounds like it would be the most fun to implement, as well as being a great choice for applying design patterns as right off the bat we could visualize what patterns could be applicable. We will be using C++, CMake(googletest), valgrind, libraries, github, our computers, and discord to communicate with each other.
 > 
 >Inputs would include: the user choosing the character they want to play as, which option to select at various steps of the game (e.g. attack, run, access inventory, use a heal item, etc.)
 >Outputs would include: Feedback to the user on character health remaining, what attack was used, what action is/was being done, confirmation or summary of what action/character the user chose
 >
 >We plan on using the design patterns of Strategy and State. We picked Strategy as one of our major design patterns as the text-based RPG will be acting very dynamic considering it is based off of the player’s choices. An example of this would be when the player is choosing their characters, the objects and classes will switch accordingly, but might result in a handful of buggy code. Similarly, a lot of actions can be confused within the code since not every character will do the same thing. Our code has to be flexible, and for that reason Strategy would be a good choice of a design pattern to help fix these issues down the line. State pattern seems like it would be useful if applied to the character classes of the user’s character. An example of state pattern use could be something like  if the character’s health gets lowered, then the class can change its behavior such as allowing the character to do more or less damage or open up new ability options for the user. Some problems that we might encounter would be the organization of abilities of the user character and when they would be activated, but a state design pattern could be used to neatly organize.
 
