-------------------------------------------------------------------------------
Example: C Sample-based Talkthrough (using 192 kHz sample rates)
Target: ADSP-21489
Date: February 23, 2010
Tools: VisualDSP++ 5.0
Hardware: ADSP-21489 EZ-board
Author: VS
-------------------------------------------------------------------------------
This project contains a talkthrough example using the onboard AD1939 to acquire
and output an audio stream. The digital audio data is available for processing
in the file SPORT1_ISR_processor_samples_.asm. The block size is 256 samples per audio channel.
The output on OUT2 is delayed and the user can expect to hear an echo effect.

The AD1939 can be set up for 192 Khz Sampling rate.  The ADC is connected 
to SPORT 1A. DAC1 is connected to SPORT 0A, DAC2 to SPORT 0A.

All channels of the codec are accessed in  TDM mode. See initSRU.c for the 
details of which DAI pins are used to access the codec. 

NOTE: The AD1939 is operating in Dual-Line TDM mode where DAC1/2 are on DSDATA1
      and DAC3/4 are on DSDATA3 pins.

-------------------------------------------------------------------------------
Instructions: Apply an input signal to J4/J5 bottom rows on the ADSP-21489 
              EZ-board, and attach an output device to the selected middle 
              or top row channels on J4/J5. Input to ADC1  gives output on 
              DAC OUT1 and DAC OUT2 and Input to ADC2 gives output on
              DAC OUT3 and DAC OUT4.
              
Input/Output combinations:
              J4 bottom row RCA connectors - ADC IN 1 Left/Right Channels
	          - J4 middle row RCA connectors - DAC OUT 1 Left/Right Channel
                  - J5 middle row RCA connectors - DAC OUT 2 Left/Right Channels
              
              J5 bottom row RCA connectors - ADC IN 2 Left/Right Channels
                  - J4 top row RCA connectors - DAC OUT 3 Left/Right Channels
                  - J5 top row RCA connectors - DAC OUT 4 Left/Right Channels
                  - Headphone jack (H)
                  
                  
|  J8 |      J4       |     J5        |
---------------------------------------
|     | *O3l* | *O3r* | *O4l* | *O4r* |
|     | +O1l+ | +O1r+ | +O2l+ | +O2r+ |
| *H* | +I1l+ | +I1r+ | *I2l* | *I2r* |
---------------------------------------

Switch settings for rev 0.1 EZ-Board:
SW1 		ON, ON, ON, ON, ON, ON, ON, ON
SW2 		ON, ON, ON, ON, OFF, OFF, ON, ON
SW3 		ALL ON
SW15-18 	ON, OFF, ON, OFF, ON, OFF
SW23 		ALL ON
SW24 		ALL OFF
SW25 		ALL OFF

NOTE:  If the application is halted within the VDSP system, the executable should 
       be reloaded to the target to ensure proper operation.
       
-------------------------------------------------------------------------------
Source Files contained in this directory:
21489 AD1939 C Sampled-Based Talkthru 192 kHz.dpj      VisualDSP project file
ad1939.h                       Macro Definitions for AD1939 registers
ADDS_21489_EzKit.h             Includes and external declarations used for all files
init1939viaSPI.c               ADSP-21489 source - AD1939 SPI Control Port Subroutines
initSRU.c                      Set up the DAI pins and SRU to connect to the AD1939
init_PLL_SDRAM.c               Configures core for 400 MHz and enables SDRAM memory
main.c                         Main section to call setup routines
Process_audio.c                Process the multiple audio data streams
SPORT01_TDM_init.c             Initialize the SPORT DMA to communicate with the AD1939
SPORT1_ISR_process_samples_.asm  Process SPORT 1 interrupts
-------------------------------------------------------------------------------
Dependencies contained in VisualDSP++ default include path:
def21489.h              Header file with generic definitions for ADSP-21489
SRU.h                   Header file with SRU definitions and Macros

*******************************************************************************
Analog Devices, Inc.
DSP Division
Three Technology Way
Norwood, MA 02062

(c) 2010 Analog Devices, Inc.  All rights reserved.
*******************************************************************************
