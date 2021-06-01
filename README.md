
# Medieval Escapade
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
We picked Strategy as our major design patterns as the text-based RPG will be acting very dynamic considering it is based off of the player’s choices. This works well since all of our characters will have an attack option, but each character has their own different attacks. This makes the attack function the perfect candidate to have our strategy design pattern to revolve around, as it is universal but slightly different per character. Choosing the algorithms we need during runtime from a pool of similar algorithms is essential for the game's operating speed and efficiency.  Our code has to be flexible, but due to the nature of RPG's, we can reuse and change a lot of our code. For that reason Strategy would be a good choice of a design pattern to help organize our code in an systematic way. 

###### Design Pattern 2: Abstract Factory
Since our game revolves around different playable characters that all are under the character class. What we can do is use the Abstract Factory design pattern to implements more detailed sub-classes from these said characters to give them special equipment, items, or actions. Similar to the use of the Strategy design pattern, our game has to be flexible enough to handle these somewhat similar but different in their own way functions and algorithms, as we have multiple classes revolving around the character class. This will make the ability to choose your character and be as unique, quite easy and simple for the user. 

###### OMT Class Diagram
![OMT Diagram (1)](https://user-images.githubusercontent.com/81598801/119738920-4fb97e00-be36-11eb-80ec-21d8ea6c8c14.jpeg)

###### OMT Description
The OMT diagram depicts the strategy pattern of our project through the character class being able to access a bunch or different attacks for the different characters through the attack classes. The user gets to decide between the four character choices, and once they do the program will use that character type throughout their adventure. Throughout the adventure, the player will be presented with different options at runtime: attack, heal via potion, or concede. These options are presented in different functions to be implemented in the battle options class.

###### Factory OMT Diagram
![Factory OMT (1)](https://user-images.githubusercontent.com/74085680/120268324-71fa3400-c25a-11eb-9bef-db84c8fc5f76.jpeg)

###### Factory OMT Description
Using the factory pattern, the client can create an object of class factory in order to use the factory object's function called Character* createChar() to create a character. The function works by taking in a string representation of the numbers one through four (such as "1","2","3" or "4") and using the number to decide which character the factory should create, which could be from the warrior, archer, assassin, or mage classes which are all subclasses of the base class Character. In this factory pattern the factory class is the factory and the characters such as warrior, archer, assassin, and mage are all concrete products of the pattern.

###### Testing
We tested out our code by creating a multitude of unit tests to match all of the functions that we made. By creating certain scenarios in our testing , we can see if our 
functions are acting accordingly or need any readjusting. An example of this would be how we used the warrior class to fight another dummy warrior class, and tested to make sure the warrior's ability and stats match up to where they need to be. Beyond that, we rigorously tested our game out by simply playing it. With this, we were able to edge out any redundancies, bugs, and logic errors that we previously could not find.  

## Installation/Usage Instructions
To install, use the command "cmake3 ." then "make" and "./main" as pictured below:

![installation](https://user-images.githubusercontent.com/81598801/120249779-d6a09900-c230-11eb-991d-3f26a518e673.png)

The user will then be prompted to enter a character name. For setup, the user will be given options 1-4 to choose the character they wish to play. Inputting 1 will choose the Warrior, 2 for Archer, 3 for Assassin, and 4 for Mage. The Warrior is high health and damage, but a slower character; the Archer has different arrows with different abilities; the Assassin is able to deal poisonous damage that takes the enemy's health even after the turn; the Mage has different spells for attacks. In each turn the user will have 3 options: 1 is to attack with melee weapon; 2 is to heal with a potion that heals 40 HP per potion; 3 is to give up. Which character attacks first is dependent upon who has a greater speed.

![setup](https://user-images.githubusercontent.com/81598801/120250212-2c297580-c232-11eb-8af2-85bc1b997b3d.png)

Narration will be output to guide the user through the game and both player and enemy health will be outted at the start of each turn. An example is shown below:

![runtime](https://user-images.githubusercontent.com/81598801/120250241-4400f980-c232-11eb-9989-f9fd556dda92.png)


