# Text Based RPG
 Authors: [Stanton Zeng](https://github.com/Lionblaze218), [Jacob Yee](https://github.com/yeetfarm), [Cruz Ramirez](https://github.com/Qrooz)
 
## Project Description

###### Why this project?
We decided a text-based RPG is interesting to us because it sounds like it would be the most fun to implement, as well as being a great choice for applying design patterns as right off the bat we could visualize what patterns could be applicable. 

###### Language and Tools
We will be using C++, CMake(googletest), valgrind, libraries, github, our computers, and discord to communicate with each other.

###### Inputs
Inputs would include: the user choosing the character they want to play as, which option to select at various steps of the game (e.g. attack, run, access inventory, use a heal item, etc.)

###### Outputs
Outputs would include: Feedback to the user on character health remaining, what attack was used, what action is/was being done, confirmation or summary of what action/character the user chose

###### Design Pattern 1: Strategy
We picked Strategy as one of our major design patterns as the text-based RPG will be acting very dynamic considering it is based off of the player’s choices. This works well since all of our characters will have an attack option, but each character has their own different attacks. This makes the attack function the perfect candidate to have our strategy design pattern to revolve around, as it is universal but slightly different per character. Choosing the algorithms we need during runtime from a pool of similar algorithms is essential for the game's operating speed and efficiency.  Our code has to be flexible, but due to the nature of RPG's, we can reuse and change a lot of our code. For that reason Strategy would be a good choice of a design pattern to help organize our code in an systematic way. 

###### Design Pattern 2: State
State pattern also seems like it would be useful for the project, if applied to the character classes of the user’s character. An example of state pattern use could be something like  if the character’s health gets lowered, then the class can change its behavior such as allowing the character to do more or less damage or open up new ability options for the user. Another example would be if the user gets attacked by the slime enemy their speed is reduced for the next turn. Some problems that we might encounter would be the organization of abilities of the user character and when they would be activated. A state design pattern could be used to neatly organize when the program would have to operate differently under different circumstances. 

###### OMT Class Diagram
![OMT Diagram](https://user-images.githubusercontent.com/81598801/117375515-fe941b00-ae83-11eb-974d-bb45a820891c.jpeg)
###### OMT Description
The OMT diagram depicts the strategy pattern of our project through the character class being split up into many different character choices as well as enemy types that all define their own attack function which is abstract in the base class. The user gets to decide between the four character choices, and once they do the program will use that character type throughout their adventure. Throughout the adventure, the player will be presented with different options at runtime: attack, heal via potion, or concede. These options are presented in different functions for the Character class. 

