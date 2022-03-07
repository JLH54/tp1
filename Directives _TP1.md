# Travail Pratique 1

Lors de ce travail pratique, nous voulons mettre en pratique la matière apprise depuis le début du cours.

Mise en situation:
Lors du développement de notre MMORPG Dave's World, les designers expriment vouloir avoir un système d'inventaire
qu'ils pourraient remplir avec des techniques de RNG(random number generator). 

Votre Lead en programmation regarde les besoins exprimés par les designers et vous compile une liste de "features" à implémenter.

## Liste de "Features":
- Utiliser une structure de données qui vous permet d'ajouter dynamiquement des informations à l'inventaire
- La grandeur de l'inventaire doit être dynamique
- Pour la structure de données, nous devons pouvoir:
  - ajouter
  - enlever
  - trier
  - trouver un item relatif à sa position
  - trouver un item relatif à son nom
  - avoir la quantité d'items dans la structure
- Avoir une structure qui va représenter les items. Elle va avoir un nom et une valeur de vente
- On doit avoir une fonction qui permet d'ajouter un item aléatoire. Votre tech lead fournit ces [informations](https://www.geeksforgeeks.org/generating-random-number-range-c/) sur l'aléatoire en C.
- Les designers veulent pouvoir choisir les noms d'items avec leurs valeurs respectives sans modifier le code. Ils vont vous fournir un fichier de type CSV(comma separated value)
  - Lire le fichier. Votre tech lead fournit cette [information](https://www.geeksforgeeks.org/c-fopen-function-with-examples/) à ce sujet
  - Peupler une liste d'items possibles, séparée de l'inventaire, à partir du document. Cette liste sera utilisée lorsque nous ajouterons des items à l'inventaire.
 
 Pour arriver à cette dernière "feature", votre tech lead vous dit qu'une fonction `getline` 
 a été implémenté dans les laboratoires et que vous pouvez la ''copier-coller'' dans votre code.
 Il vous dit aussi que vous pouvez vous baser sur du code dans ce [labo](https://github.com/mundusnine/tech-prog-bart-labo/blob/main/labS4J2/Sources/main.c#L75)
 afin de vous aider.
 
 ## Dans votre Main
 Dans votre application en mode console, votre team lead veut que vous testiez toutes les fonctionnalités. Vous devez alors, dans votre main:
 - Peupler la liste d'items
 - Ajouter l'item nommé "fiole" dans l'inventaire
 - Peupler l'inventaire d'un nombre aléatoire d'items en considérant que la "fiole" a déjà été ajouté.
 Choisir les autres items aléatoirement et les ajouter dans l'inventaire.
 - Imprimer dans la console les items dans l'inventaire
 - Trier la liste d'items dans l'inventaire relatif à leur valeur de vente
 - enlever l'item "fiole" en utilisant son nom.
 - Imprimer dans la console les items dans l'inventaire à nouveau.