
What do I actually want from this project
- to be able to not have to open up the enclosure of a PCB in order to flash code/read serial from the teensy on the PCB
- connection will need to be one way, for code upload (preferably two way, for serial reading)
	- all the teensys will listen to a main controller, to see if code is needed to be uploaded
	- all teensys will also be able to communicate their serial data back to the main controller
	- main controller (hopefully) will be able to switch between which teensy it is talking to


link to how to use a ESP32 to program teensy: https://electronics.stackexchange.com/questions/736420/using-a-esp32-to-program-a-teensy


### Potential Ways to do OTA on Teensy 

#### ESP32 Implementation
- every esp32 explained: https://www.youtube.com/watch?v=u5unB24lhC4&ab_channel=DroneBotWorkshop
- link to esp32 datasheet https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf
- want an esp32 that has Two-Wire Automotive Interface (TWAI) 
	- TWAI supports CAN 2.0
	- Any GPIO pin on 
- i think the go is ESP32-H2 
	- https://www.espressif.com/sites/default/files/documentation/esp32-h2_datasheet_en.pdf
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
- the above post uses vs2019 or Visual Micro as IDEs which have post-build command. This link shows that Arduino IDE also uses it but will have to investigate and try to convert above post to use Arduino IDE instead of vs2019/VM. https://forum.arduino.cc/t/build-process-add-custom-action-during-execution-e-g-fill-build-date/562986
- another link to people talking about OTA. https://forum.pjrc.com/index.php?threads/ota-sketch-updates-for-teensy.55469/

#### Using Bluetooth
- range on small power bluetooth chips: ~30 m
	- HC05 bluetooth chip: 
		- Rx pin = 3.3v
		- Tx pin = 3.3v but dont have to worry since it transmits
		- pin 34 of command chip must be connected to 3.3v in order for it to stay in command mode 
			- slow blink = command mode
			- fast blink = waiting for something to connect to it
		- coolterm is a serial monitor app that has good information about what is going on
		- speed = 38400
- range on high power bluetooth chips: ~80m
- CP2102 USB-to-Serial converter will have to be used



# Note on Raspberry Pi Code Upload Using Wifi 

It's normally forgotten about, but you can use a Raspberry Pi Zero W or Raspberry Pi 3A for less than the cost of some implementations of WiFi. There can be a bit of a learning curve writing a server daemon to handle the data, but the hardware is pretty rock solid at this point. There are currently a few 5gHz WiFi modules, but almost everything embedded is 2.4gHz due to price and power budget.