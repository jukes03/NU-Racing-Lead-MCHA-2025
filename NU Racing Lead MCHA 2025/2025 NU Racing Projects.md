
https://uoneduau-my.sharepoint.com/:w:/r/personal/c3380136_uon_edu_au/_layouts/15/Doc.aspx?sourcedoc=%7BEF08FA28-BF7A-428C-B0E5-8EFA62EB871A%7D&file=2025%20NU%20Racing%20Projects.docx&fromShare=true&action=default&mobileredirect=true


2025 NU Racing Projects 

This is a list of all potential projects for selection in 2025. These come from personal experience and from recommendations in past reports. 

MECH 

Monoque Design – Josh Bywaters report, Development must continue, but parallel to the space frame until the team is ready and the monoque is better than the space frame 

Carbon fibre development – the team once had carbon fibre parts (AVONE seat and NU16) and such it would be good to use the material again, at first with simple components and then for use in a monoque and aero if brought back into NU Racing design. This should happen parallel to main design, allowing for parts to be directly compared. 

MCHA 

Pouch Cell Accumulator – This project is parallel to the current accumulator and should only be used when the new accumulator is reliable and better than the current. This will involve packaging the new cells as well as working out the temperature and voltage taps for the new cells. This design will involve a MECH and MCHA and will be a challenge to do very well. 

Dynamometer – Josh Dawson’s report, would be able to test accumulator and motor output using a ‘bench car’. Currently we can only spin the motors on the stand to test them without driving.  A dyno would allow for the car’s drivetrain to be loaded at uni to validate designs, this would be great for the design event too. This would require a lot of work, both MECH and MCHA 

- MCHA work would include (taken from Josh Dawson’s report): Creation of a node to replicate the car, essentially a CEN, which has LV, TSMS and HFR switches (safety), LV and HV accumulator ports, expansion ports, extra switches/pots as inputs for throttle, throttle enable and other functions. 
    

Charger – Josh Dawson’s report, will need to be updated with the new HV connectors when chosen, as well as the interlock. The PCB currently has whoopie wires on it so might need an upgrade, as well as the cooling could be tested, as this is a requirement to prove in tech. Fans could be changed with quieter ones. Not heaps of work but all MCHA    

New brake light – Nick Lyall’s report, the brake light could be upgraded to a smaller factor LED that NU Marine use. This would save space and weight but is only enough work for a junior, or maybe a starter project. And enclosure/mount could be designed as part of the project. 

AMS Fault – the AMS fault at comp needs to be fixed, this will require a new canamon and then plenty of testing. If the canamon does not fix it, it is likely the BMS and it will need to be repaired. 

MOTEC Screen: The CAN 1 line is damaged and should be sent away to be repaired. The screen should also be repaired if possible (considering costs). 

Ready To Move (RTM) / Tractive System Status Indicator (TSSI): 

- Ready To Move: amber light to indicate when car is in ready to drive (ready to move). Need to connect this into the TSAL Red Circuitry that is currently on the TSAL_DISCHARGE breakout board. Amber light must flash at 2-5 Hz. EV.5.10 

- Tractive System Status Indicator: need to route BMS and IMD okhs into HIP, then up into the TSAL_DISCHARGE breakout board for new red flash LED. Red flash will be at same frequency that it is right not (2-5 Hz), though it will only flash when there is an IMD or BMS fault. EV.5.11 

- green led functionality will stay the same 

PEN V2.0 - Resize to new pedal box. Change DT connectors to be keyed/coloured. Investigate need for zener diodes. Add capacitors to brake sensor inputs. 

DEN V4.0 - fit to chassis. Change to coloured/keyed connectors. Put back on dials for setting changes (only for torque?). Regen might not need to be switched here since it is not turned on/off during a run, but would be handy during if it was testing?  

EXPANSION BOARD V2.0 - change to coloured/keyed DT connectors. Remove long break in ground plane. Shorten CAN H & L lines. Move transeiver closer to teensy. 

CEN Motherboard V2.0 - change to coloured/keyed DT connectors. Spec fuses to mosfet blocks to correct size (so that they arent all 10 A). Move interpose from LVD to CEN? Leave some empty space around breakout board holders in case of size changes throughout year. Introduce another double MOSFET switching circuit for the second pump (more head room for pump selection). Introduce temperature control circuit for radiator fan (to reduce amount of time that the fan is drawing power). Route BMS and IMD okhs over to the HIP. 

BSPD V3 – Jacob Bush report for recommendations on changes. potentially put pots back on for current thresh voltage divide (introducing them will increase the overall height of the PCB). Removal/Keep resistors to calculate C_REF: I believe that while the low profile of having two resistors for the C_REF value is efficient for overall size of the enclosure. It takes too long to figure out how to calibrate it properly and accurately, as the voltage range for the cut off is very very small. To save on person hours, I believe that the BSPD should have pots on it instead of resistors. This will increase the height of the footprint for the CEN PCB assembly overall, but beneficial in the long term. 

HFR V5 – Jacob Bush report for recommendations on changes. research ‘protection’ circuits for op amps, so that they can be put back on to avoid bms voltage divide. Might be as simple as adding a series resistor with the signal input to the op amp idk. Check and understand differences between HFR circuit on NU23 CEN compared to HFR V4 circuit. 

HIP V2.0 - New master switches (that dont break so damn easy). Add in interlock for HV connectors (ensure the HV connectors have HVIL), could be on the PCB side that the interlock exists? (Or just new HV connectors). Implement BMS and IMD okhs, routing to the TSSI_DISCHARGE change all labelling of HVD to MSD (Manual Service Disconnect), ensure it matches rule EV.5.5. 

TSAL_DISCHARGE V4 / TSSI_DISCHARGE V1– change name to TSSI_DISCHARGE (??). Jacob Bush report for recommendations on changes. Ensure it is a red PCB. Ensure no oopsie wires (make sure all traces are connected on schematic and PCB layout). Implement BMS and IMD okhs so that the red LED on TSSI only flashes when either of these signals go bad (flash at 2-5 Hz). Change so that the current red circuitry is labelled as the amber circuitry. 

LVD 4.0/AIL – Jedd Reeves, Daniel Iverson reports, Need to change the 22 pin molex connector to one that is easier to disconnect and connect, either multiple molex connectors or some other PCB mount connector, Mosfet power switching need to be changed to a relay or 3 sets of double Mosfets, needs to be tested before deciding. AIL or a volt meter needs to work and much earlier in the year. If an AIL is used, should be apart of LVD and should have good reasoning to why it should be used other than a voltmeter. Change to coloured/keyed DT connectors. Maybe move interpose from LVD to CEN (makes it more serviceable). Move LVD to top plate instead of lid. Investigate current draw of fans on start up vs during operation. 

CANaMon V4– could investigate the power consumption of these boards. The switching circuitry is already implemented, only need to code the on/off cycle if Matt Whitworth talked about this power saving stuff in his report could be good to reference. If this is not needed, then could do an iteration and remove the switching circuitry?? If new iteration, ensure traces are as far away from tooling locations as possible.  

Sensors – could stem from an expansion board iteration. The board would interact with the following sensors: shock pots, steering angle sensor and wheel speed sensors 

Motor Controller – ensure someone knows how it works/read haywards report/presentation?