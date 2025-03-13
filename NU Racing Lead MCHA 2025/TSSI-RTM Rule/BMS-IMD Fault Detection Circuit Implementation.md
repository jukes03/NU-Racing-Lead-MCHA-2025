
Green Light on while red flashing issue
- Green Light to turn off during an IMD or BMS fault 
	- currently, it will remain on as the car will enter LV
		- need to intercept GREEN_SWITCHED_GND and break the signal when IMD or BMS fault occurs 
### Option 1 - Not Used on NU25
What: have red flash function on HIP (TSAL_Discharge)
How: 
- route IMD and BMS to HIP
- CEN changes
	- CEN -> HIP connector change from 12 pin to 18 pin
		- for IMD, BMS and AMBER_SWITCH_GND signals
	- CEN -> UEN connector change from 6 pin to 8 pin
		- to route RED_SWITCHED_GND to the Ready To Move light
- HIP changes
	- CEN -> HIP connector change from 12 pin to 18 pin
		- for IMD, BMS and AMBER_SWITCHED_GND signals
	- route IMD, BMS and AMBER_SWITCHED_GND to/from TSAL_Discharge from/to the 18 pin connector
- TSAL_Discharge changes
	- Use same output of 555 timer already on there for both red and amber flashing (both need to be 2-5 Hz), signal called RED/AMBER_CONT
	- RED/AMBER_CONT:
		- runs to a 12 V OR gate (maybe diode OR gate? (test functionality in LT Spice)) for IMD and BMS
			- output of OR gate (RED_CONT) will run to a MOSFET that will connect output of 555 timer to RED_SWITCHED_GND, this signal will run to the CEN then up to the UEN
	- RED/AMBER_CONT
		- runs to a MOSFET to switch a signal called AMBER_SWITCHED_GND
Pros:
- maintains all functionality of TSSI/Ready To Move on the TSAL_Discharge board 
	- simplicity 
	- contained
Cons
- have to redo HIP and TSAL_Discharge boards
- Need two bigger connectors

### Option 2 - Used on NU25
What: have red flash function on CEN (HFR)
How:
- CEN changes
	- CEN -> UEN connector change from 6 pin to 8 pin
		- to route RED_SWITCHED_GND to the Ready To Move light\
	- Route GREEN_SWITCHED_GND to HFR breakout for detection of BMS/IMD fault
- HFR changes
	- Rename to HFR_TSSI
	- Implement 555 timer circuit for generation of 2-5 Hz signal (named TSSI_RED_CONT) (copy one from TSAL_Discharge)
		- TSSI_RED_CONT:
			- runs to source/drain pin of MOSFET 
	- BMS/IMD signals
		- both run to an AND gate, output of NAND gate called TSSI_RED_TIMER_CONT
			- when BMS or IMD go bad, the output of AND gate will be LOW
			- when BMS and IMD are both good, output of AND gate will be HIGH
	- TSSI_RED_TIMER_CONT signal
		- runs to reset pin of 555 timer
			- this should make so output of 555 timer (TSSI_RED_CONT) is off when BMS/IMD is HIGH
	- MOSFET 
		- Gate pin
			- TSSI_RED_CONT
		- Source pin
			- GND
		- Drain pin
			- 12v, led, 1k resistor, TSSI_RED_SWITCHED_GND  
	- Turn off Green Light during BMS/IMD fault
		- GREEN_SWITCHED_GND into a MOSFET that is only on when BMS AND IMD are HIGH
			- MOSFET
				- Gate pin
					- TSSI_RED_TIMER_CONT
				- Drain pin
					- GREEN_SWITCHED_GND_CONT
				- Source pin
					- GREEN_SWITCHED_GND
Pros:
- do not need to redo HIP and TSAL_Discharge board
- only need 1 connector to change
Cons:
- everything to do with TSSI/RTM not contained on the one board