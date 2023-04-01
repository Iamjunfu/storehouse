///////////////////////////////////////////////////////////////////////////////////////
//
//NAME:     ADDS_21489_EzKit.h
//DATE:     02/06/10
//PURPOSE:  Header file with definitions use in the C-based talkthrough examples
//
////////////////////////////////////////////////////////////////////////////////////////

#ifdef __ECC__ 

#include <cdef21489.h>
#include <def21489.h>
#include <signal.h>

// Function prototypes for this talkthrough code
void	Setup_ADSP21489(void);
void	initPLL_SDRAM(void);
void 	InitDAI(void);
void 	clearDAIpins(void);
void 	Init1939viaSPI(void);
void 	enable_SPORT01_MCM_mode(void);
void 	enable_SPORT01_DMA_channels(void);
void 	enable_SPORT23_MCM_mode(void);
void 	enable_SPORT23_DMA_channels(void);
void	process_AD1939_samples(int);
void	Receive_ADC_Samples(void);
void	Transmit_DAC_Samples(void);

void 	SetupSPI1939(unsigned int);
void 	DisableSPI1939();
void 	Configure1939Register(unsigned char,unsigned char,unsigned char,unsigned int);
unsigned char Get1939Register(unsigned char,unsigned int);

void 	Delay(int i);
void	SinTableInit(void);

/* Insert global variable definitions here */

extern void Delay (int i);
extern float Sine_Table[4000];
extern int Sine_Index;

extern int rx1a_buf[4];
extern int tx0a_buf[4];
extern int tx0b_buf[4];

extern float * DelayLine;
extern int Index;

// input audio channels
extern 	float			Left_Channel_In1;       /* Input values from the AD1939 internal stereo ADCs */			
extern 	float 			Right_Channel_In1;
extern	float			Left_Channel_In2;
extern  float			Right_Channel_In2;

//output audio channels
extern 	float			Left_Channel_Out1;      /* Output values for the 4 AD1939 internal stereo DACs */
extern 	float 			Left_Channel_Out2;      
extern 	float 			Left_Channel_Out3;
extern 	float 			Left_Channel_Out4;
extern 	float			Right_Channel_Out1;
extern 	float			Right_Channel_Out2;
extern 	float			Right_Channel_Out3;
extern 	float			Right_Channel_Out4;



#else
/* Insert Assembly Definitions here.... */

#endif



/* Insert C Definitions here.... */

#define SPIB_MODE (CPHASE | CLKPL)
#define AD1939_CS DS0EN
//#define AD1939_CS DS1EN

#define SELECT_SPI_SLAVE(select) (*pSPIFLG &= ~(spiselect<<8))
#define DESELECT_SPI_SLAVE(select) (*pSPIFLG |= (spiselect<<8))

/* AD1939 TDM Timeslot Definitions for Dual-Line 192 kHz DAC TDM Mode */
#define     Internal_ADC_L1    0
#define     Internal_ADC_R1    1
#define     Internal_ADC_L2    2
#define     Internal_ADC_R2    3

#define     Internal_DAC_L1    0
#define     Internal_DAC_R1    1
#define     Internal_DAC_L2    2
#define     Internal_DAC_R2    3
#define     Internal_DAC_L3    0
#define     Internal_DAC_R3    1
#define     Internal_DAC_L4    2
#define     Internal_DAC_R4    3
