
### Option 1
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

### Option 2
What: have red flash function on CEN (HFR)
How:
- CEN changes
	- CEN -> UEN connector change from 6 pin to 8 pin
		- to route RED_SWITCHED_GND to the Ready To Move light
- HFR changes
	- Rename to HFR_RTM
	- Implement 555 timer circuit for RED_CONT generation at 2-5 Hz
	- RED_CONT:
		- runs to a 12 V OR gate (maybe diode OR gate? (test functionality in LT Spice)) for IMD and BMS
			- output of OR gate (RED_CONT) will run to a MOSFET that will connect output of 555 timer to RED_SWITCHED_GND, this signal will run up to the UEN
Pros:
- do not need to redo HIP and TSAL_Discharge board
- only need 1 connector to change
Cons:
- everything to do with TSSI/RTM not contained on the one board