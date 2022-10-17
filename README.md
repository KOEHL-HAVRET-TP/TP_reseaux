# TP_reseaux
## test
Configuration de la STM32 : 
UART 1 
UART 2
I2C 


TP1 - Bus I2C

1.  Capteur BMP280
    
Mise en œuvre du BMP280
Les adresses I²C possibles pour ce composant.
    Les adresses possibles : 0x76 (GND) et 0x77 (VDDIO)
        
Le registre et la valeur permettant d'identifier ce composant
    C’est le registre  0xD0 “id”, qui permet d’identifier ce composant, avec comme valeur 0x58.
     
Le registre et la valeur permettant de placer le composant en mode normal
    C’est le registre  0xF4 qui permet de modifier le mode du composant. Pour être en mode normal on doit placer 2 bits à 1.
     
Les registres contenant l'étalonnage du composant
    Le registre calib25...calib00 à l’adresse 0xA1…0x88  permet de contrôler l’étalonnage.
     
Les registres contenant la température (ainsi que le format)
    Il y a 3 registres contenant la température : temp_xlsb (0xFC) , temp_lsb (0xFB), temp_msb (0xFA)
        
Les registres contenant la pression (ainsi que le format)
    Il y a 3 registres contenant la pression : press_xlsb (0xF9),  press_lsb (0xF8), press_msb (0xF7).
    Les 2 registres temp_xlsb, et press_xslb sont modifiés en fonction de la résolution du capteur. 
      
Les fonctions permettant le calcul de la température et de la pression compensées, en format entier 32 bits.
    fonction de calcul pour la pression : double bmp280_compensate_P_double(BMP280_S32_t adc_P)
    fonction de calcul pour la température : double bmp280_compensate_T_double(BMP280_S32_t adc_T) 

TP2 - Interfaçage STM32 - Raspberry

A l'aide du logiciel Rasberry Pi Imager nous allons télécharger une image sur le carte SD, qui sera ensuite sur la raspberry. Une fois la rasberry alimentée et avec la carte SD elle va chercher à se connecter à un réseau que nous avons configuré dans l'image. C'est en se connectant au routeur que la rasberry obtient une adresse IP.

Pour éviter tout piratage il est necessaire d'être vigilent dans la configuration de l'image que l'on télécharge sur la carte SD, et notamment au mot de passe. Une fois connectée au réseau la rasberry est facilement piratable et son adresse IP peut être récupérée très facilement et rapidement.

Une fois la rasberry connectée on obtient une adresse IP : 192.168.88.241

Dans un terminal : 
La commande ssh@192.168.88.241 nous fait entrer dans la rasberry.


Installation de minicom :

sudo apt install minicom
minicom -D /dev/ttyAMA0




TP3 - Interface REST

TP4 - Bus CAN


TP5 - Intégration I²C - Serial - REST - CAN
