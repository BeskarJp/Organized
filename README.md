# Organized - Robotics Inventory Manager

## Présentation
**Organized** est un projet de première année à **Epitech** consistant à développer un système de gestion et de tri dynamique de matériel de laboratoire robotique via un shell interactif. 

Le projet met l'accent sur la manipulation avancée de **listes chaînées**, une **gestion rigoureuse de la mémoire** (zéro fuite mémoire acceptée) et l'implémentation d'un moteur de **tri multi-critères** performant.

---

## Gestion du Matériel
Le programme permet d'organiser cinq catégories distinctes de composants. Chaque matériel ajouté reçoit un **ID unique** incrémenté automatiquement :

* **Actuators :** Boutons, leviers, servomoteurs...
* **Devices :** Radios, enregistreurs, contrôleurs...
* **Processors :** Puces Intel, AMD, ARM...
* **Sensors :** Capteurs de mouvement, thermiques, laser...
* **Wires :** Câbles USB, HDMI, nappes...

---

## Commandes du Shell

Le programme interprète des commandes spécifiques pour manipuler la liste d'objets en temps réel.

### Interactions & Syntaxe
| Commande | Paramètres | Action |
| :--- | :--- | :--- |
| **`add`** | `<TYPE> <NAME>` | Ajoute un ou plusieurs matériels à l'inventaire. |
| **`del`** | `<ID>` | Supprime un ou plusieurs matériels via leur identifiant. |
| **`disp`** | *(aucun)* | Affiche l'intégralité du matériel présent dans la liste. |
| **`sort`** | `<TAG> [-r]` | Trie la liste par **TYPE**, **NAME** ou **ID**. |

> [!TIP]
> **Tri multi-critères :** Vous pouvez combiner jusqu'à 3 critères (ex: `sort TYPE NAME -r ID`). Le flag `-r` inverse l'ordre du critère qui le précède.

---

## Exemples d'utilisation

### Ajout et Affichage rapide
```bash
$> ./organized
Workshop >> add WIRE usb, ACTUATOR button, DEVICE recorder
WIRE n°0 - "usb" added.
ACTUATOR n°1 - "button" added.
DEVICE n°2 - "recorder" added.
Workshop >> disp
DEVICE n°2 - "recorder"
ACTUATOR n°1 - "button"
WIRE n°0 - "usb"
```

---

## Spécifications Techniques

**Langage :** C

**Binary pour le lancement :** ./organized

**Structure de données :** Listes chaînées dynamiques.

**Algorithmes :** Tri multi-critères stable (Type, Name, ID).

**Gestion mémoire :** Nettoyage complet de la mémoire à la fermeture (Valgrind-friendly).

**Compilation :** Via Makefile (rules: all, clean, fclean, re).
