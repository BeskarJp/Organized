# 🧩 ./organized  

**organized** est un projet pour gérer et trier dynamiquement du matériel de laboratoire robotique via shell.  

Ce projet met l'accent sur la manipulation de **listes chaînées**, la **gestion rigoureuse de la mémoire** et l'implémentation d'**algorithmes de tri multi-critères**.  



## 📘 Objectif du projet  

L'objectif est de créer un système de gestion de stocks capable d'organiser cinq types de matériels :  
- **Actuators** : boutons, leviers...  
- **Devices** : radios, enregistreurs...  
- **Processors** : puces Intel, AMD...  
- **Sensors** : capteurs de mouvement, thermiques...  
- **Wires** : câbles USB, HDMI...  

Le programme attribue un identifiant (ID) unique à chaque matériel ajouté et permet de les supprimer, de les afficher ou de les trier par **TYPE**, **NAME** ou **ID** (croissant ou décroissant).  



## ⚙️ Commandes du Shell  

### `add <TYPE> <NAME>`
Ajoute un ou plusieurs matériels à la liste.  
- Affiche : `TYPE n°ID - "NAME" added.`  

### `del <ID>`
Supprime un ou plusieurs matériels de la liste via leur identifiant.  
- Affiche : `TYPE n°ID - "NAME" deleted.`  

### `disp`
Affiche l'intégralité du matériel présent dans l'atelier, dans l'ordre actuel de la liste.  

### `sort <TAG> [-r]`
Trie la liste selon un ou plusieurs critères (jusqu'à 3).  
- **TAGS** : `TYPE`, `NAME`, `ID`.  
- **-r** : Inverse l'ordre du critère précédent.  



## 🔨 Exemples d'utilisations

### Ajout et Affichage

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
