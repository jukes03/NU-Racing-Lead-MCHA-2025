


link to how to use a ESP32 to program teensy: https://electronics.stackexchange.com/questions/736420/using-a-esp32-to-program-a-teensy


### Potential Ways to do OTA on Teensy 
#### Central Hub Idea 1 (CAN)
- uploading code would have to go over can
- have a node that has x amount of plug in spots that has access to can network (will require teensy as well) 
- Cannot work since CAN can only handle 8 bytes per message. An arduino code file converted to .hex can be up to 256 bytes 
#### Central Hub Idea 2 (USB Cable) 
- have a usb programming wire run from each node to this central spot 
- won’t work for teensy’s in accum 
- this idea is probably the most messy/hard to do physically. strain relief on each programming cable would have to be ensured 
#### Raspberry Pi Idea
- have a raspberry pi connected to each teensy
- raspberry pi’s are connected to a wifi network, able to upload arduino machine code to pi’s via a dropbox (the hard part) and pi’s will upload the code to the teensy 
- https://youtu.be/-sMqQ66Yfeg?si=lM6Mu9yZUVXu2XT7
- Note on using raspberry pi with wifi [[#Note on Raspberry Pi Code Upload Using Wifi]]
- raspberry pi zero w costs ~$17/per. if this solution used on PEN, DEN, CEN, LVD. cost of 4 zero w boards = ~$70 (without shipping) https://au.mouser.com/ProductDetail/Raspberry-Pi/SC0019?qs=rQFj71Wb1eUTUmywZo0nqA==&mgh=1&vip=1&utm_id=17753636782&gad_source=1&gclid=CjwKCAiAmrS7BhBJEiwAei59i7g14KScnwzBXGTiHLhKAXN522A6jLd2SccHkmvNfGDLalqMMriNwBoCtIIQAvD_BwE
#### Using OTA 
- Over-The-Air is a wireless programming method that Arduino created. Though it was only created for Arduino boards 
- The following link shows how to implement OTA on teensy 3.x and 4.x. https://www.fpaynter.com/2021/10/over-the-air-ota-firmware-updates-for-teensy-3-x-4-x/
- the above post uses vs2019 or Visual Micro as IDEs which have post-build command. Thing link shows that Arduino IDE also uses it but will have to investigate and try to convert above post to use Arduino IDE instead of vs2019/VM. https://forum.arduino.cc/t/build-process-add-custom-action-during-execution-e-g-fill-build-date/562986
- another link to people talking about OTA. https://forum.pjrc.com/index.php?threads/ota-sketch-updates-for-teensy.55469/

# Note on Raspberry Pi Code Upload Using Wifi 

It's normally forgotten about, but you can use a Raspberry Pi Zero W or Raspberry Pi 3A for less than the cost of some implementations of WiFi. There can be a bit of a learning curve writing a server daemon to handle the data, but the hardware is pretty rock solid at this point. There are currently a few 5gHz WiFi modules, but almost everything embedded is 2.4gHz due to price and power budget.