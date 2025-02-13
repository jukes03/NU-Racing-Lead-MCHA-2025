Hello engineer friend,

To set up your system's file, please follow the list below
- Copy and paste this file structure (aa_TEMPLATE_FILESTRUCTURE) into a folder with the name of your PCB/system
	- eg: CEN
- How we number the versions of PCBs/Code iterations:
	- PCBs, 
		- please follow the version number you have been given by the Lead MCHA
	- Code, 
		- if a major change to the code has occurred, please increase the version number by 1 
			- if unsure what this means, please speak to the Lead MCHA
- Then follow and maintain the structure

PS clone Racing-NU24 repo from GitHub to see how we did it last year if unsure on the file structure

PPS good on you for opening this file :D

Example file structure:
\Github
	\Racing-NU25
		\PCB_NAME      (e.g CEN)
			\Kicad_Project_Folder      (e.g CEN_V2.1)
				\DDR_EXCEL FILE      (e.g CEN_V2.1_DDR.xlsx)
				\Schematic PDF      (e.g CEN_V2.1_Schematic.PDF)
				\Datasheets           (Folder)
                                        \Datasheet_1      (e.g Component_1.PDF)
                                        \Datasheet_2      (e.g Component_2.PDF)