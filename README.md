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
We picked Strategy as our major design patterns as the text-based RPG will be acting very dynamic considering it is based off of the player’s choices. This works well since all of our characters will have an attack option, but each character has their own different attacks. This makes the attack function the perfect candidate to have our strategy design pattern to revolve around, as it is universal but slightly different per character. Choosing the algorithms we need during runtime from a pool of similar algorithms is essential for the game's operating speed and efficiency.  Our code has to be flexible, but due to the nature of RPG's, we can reuse and change a lot of our code. For that reason Strategy would be a good choice of a design pattern to help organize our code in an systematic way. 

###### Design Pattern 2: Abstract Factory
Since our game revolves around different playable characters that all are under the character class. What we can do is use the Abstract Factory design pattern to implements more detailed sub-classes from these said characters to give them special equipment, items, or actions. Similar to the use of the Strategy design pattern, our game has to be flexible enough to handle these somewhat similar but different in their own way functions and algorithms, as we have multiple classes revolving around the character class. This will make the ability to choose your character and be as unique, quite easy and simple for the user. 

###### OMT Class Diagram
![OMT Diagram](https://user-images.githubusercontent.com/81598801/118554612-87c61000-b716-11eb-8f6f-6765d02df622.jpeg)

###### OMT Description
The OMT diagram depicts the strategy pattern of our project through the character class being split up into many different character choices as well as enemy types that all define their own attack function which is abstract in the base class. The![Uploading OMT Diagram.jpeg…]()
 user gets to decide between the four character choices, and once they do the program will use that character type throughout their adventure. Throughout the adventure, the player will be presented with different options at runtime: attack, heal via potion, or concede. These options are presented in different functions for the Character class. 

