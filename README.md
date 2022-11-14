# TP_reseaux  
![alt text](https://github.com/KOEHL-HAVRET-TP/TP_reseaux/blob/1c0eb2716b6b108aca59cb3854894e1de56df6ac/Images/schema_projet_bus_et_reseaux.JPG)


## Membres du groupe  
Loïcia KOEHL  
Alix HAVRET  

Configuration de la STM32 : 
![alt text](https://github.com/KOEHL-HAVRET-TP/TP_reseaux/blob/main/Images/Pinout.JPG)

## TP1 - Interrogation des capteurs par le bus I2C

### 1.  Capteur BMP280
    
- **Les adresses I²C possibles pour ce composant**  
    Les adresses possibles : 0x76 (GND) et 0x77 (VDDIO)
        
- **Le registre et la valeur permettant d'identifier ce composant**  
    C’est le registre  0xD0 “id”, qui permet d’identifier ce composant, avec comme valeur 0x58.
     
- **Le registre et la valeur permettant de placer le composant en mode normal**  
    C’est le registre  0xF4 qui permet de modifier le mode du composant. Pour être en mode normal on doit placer 2 bits à 1.
     
- **Les registres contenant l'étalonnage du composant**  
    Le registre calib25...calib00 à l’adresse 0xA1…0x88  permet de contrôler l’étalonnage.
     
- **Les registres contenant la température (ainsi que le format)**  
    Il y a 3 registres contenant la température : temp_xlsb (0xFC) , temp_lsb (0xFB), temp_msb (0xFA)
        
- **Les registres contenant la pression (ainsi que le format)**  
    Il y a 3 registres contenant la pression : press_xlsb (0xF9),  press_lsb (0xF8), press_msb (0xF7).
    Les 2 registres temp_xlsb, et press_xslb sont modifiés en fonction de la résolution du capteur. 
      
- **Les fonctions permettant le calcul de la température et de la pression compensées, en format entier 32 bits.**  
    fonction de calcul pour la pression : double bmp280_compensate_P_double(BMP280_S32_t adc_P)
    fonction de calcul pour la température : double bmp280_compensate_T_double(BMP280_S32_t adc_T) 
    
*Nous avons durant cette partie réutilisé la base de code fournie par Mr BARES, puis nous y avons apporté nos modifications.*  
    
### Configuration du BPM280
Pour utiliser le BMP380 on configure les modes à l'aide des adresses trouvées précédemment. L'ensemble des adresses seront initialisées au début du code pour          simplifier sa lecture  
On visualise les registres correspondant pour vérifier la bonne écriture au sein de ces derniers.  
     
### Récupération de l'étalonnage, de la température et de la pression
Les valeurs de calibration se trouvent sur 25 adresses différentes. Nous avons dans la datasheet 13 valeurs de calibration :  
    
![alt text](https://github.com/KOEHL-HAVRET-TP/TP_reseaux/blob/main/Images/Pinout.JPG)
    
On vérifie la valeur de ces dernières, elles seront utiles dans le calcul de temperatures et de pressions.  
    
### Calcul des températures et des pressions compensées
La datasheet nous fournit 2 codes pour le calcul de la température et de la pression. On utilise ces derniers.  
Dans un premier temps, la temparture et la pression étaient à 0. On utilise le mode debug de CubeIDE pour trouvé le problème.
    
Dans l'idée : jeudi ça fonctionne 
    
Objectif final : L'accéléromètre nous servira de base. Une fois la vitesse récupérée de l'IMU 10 DOF , cette dernière sera envoyée sur le servomoteur pour, contrôler sa vitesse.

## TP2 - Interfaçage STM32 - Raspberry Pi

A l'aide du logiciel Rasberry Pi Imager nous allons télécharger une image sur le carte SD, qui sera ensuite sur la raspberry. Une fois la rasberry alimentée et avec la carte SD elle va chercher à se connecter à un réseau que nous avons configuré dans l'image. C'est en se connectant au routeur que la rasberry obtient une adresse IP.

Pour éviter tout piratage il est necessaire d'être vigilent dans la configuration de l'image que l'on télécharge sur la carte SD, et notamment au mot de passe. Une fois connectée au réseau la rasberry est facilement piratable et son adresse IP peut être récupérée très facilement et rapidement.

Une fois la rasberry connectée on obtient __une adresse IP : 192.168.88.241__

__Dans un terminal :__
La commande ssh@192.168.88.241 nous fait entrer dans la rasberry.
Une fois dans la raspberry il est possible de : 
- créer des dossiers 
- créer des fichiers 
- écrire dans des fichiers
- éxecuter du code

__Installation de minicom :__

sudo apt install minicom
minicom -D /dev/ttyAMA0


## TP3 - Interface Web sur Raspberry Pi et interface API Rest

__Vocabulaire :__  
- Flask : framework web Python avec divers fonctionnalités
- app :application Flask
- route : en developpement Web la route est une URL qui conduit vers l'execution d'une fonction (pour exécuter cette fonction on devra se trouver sur la route/l'URL correspondant), il est possibile de paramétrer nos routes
- def : dans nos routes nous définiront notre fonction qui s'executera lorsque nous seront sur cette route

Sur la raspberry pi on a un utilisateur par défaut qui est celui nous permettant de nous connecter en réseau à cette dernière.  
On va créer un nouvel utilisateur et l'utiliser pour les prochaines étapes.  
__nouvel utilisateur__
user : alixloicia

On crée un premier fichier Web "hello.py" qui contiendra le code du serveur Web nous permettant d'observer les résultats et de débugger.  Ce serveur sera à l'adresse __http://192.168.88.241 :5000__.  


Notre serveur devra être RESTful, il devra être sous forme Json et différencier les différentes méthodes HTTP.  
Le json est un type de fichier simple à générer et facile à lire et à traiter. 

On utilise l'extension RESTED de firefox afin d'oberver les retours des différentes méthodes (GET, POST, PUT, etc) que l'on implémente sur la rasberry.  
Pour faire nos tests, nous devront nous placer sur la bonne adresse correspondant à la "fonction" testée. ?? 
 

## TP4 -Pilotage d'actionneur par bus CAN


## TP5 - Intégration I²C - Serial - REST - CAN
