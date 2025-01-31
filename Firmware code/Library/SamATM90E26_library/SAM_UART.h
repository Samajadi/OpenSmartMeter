 

  #ifndef __ATM90E26_UART_H__
  #define __ATM90E26_UART_H__

  #include <Arduino.h>

  #define SoftReset 0x00 //Software Reset
  #define SysStatus 0x01 //System Status
  #define FuncEn 0x02 //Function Enable
  #define SagTh 0x03 //Voltage Sag Threshold
  #define SmallPMod 0x04 //Small-Power Mode
  #define LastData 0x06 //Last Read/Write SPI/UART Value
  #define LSB 0x08 //RMS/Power 16-bit LSB
  #define CalStart 0x20 //Calibration Start Command
  #define PLconstH 0x21 //High Word of PL_Constant
  #define PLconstL 0x22 //Low Word of PL_Constant
  #define Lgain 0x23 //L Line Calibration Gain
  #define Lphi 0x24 //L Line Calibration Angle
  #define Ngain 0x25 //N Line Calibration Gain
  #define Nphi 0x26 //N Line Calibration Angle
  #define PStartTh 0x27 //Active Startup Power Threshold
  #define PNolTh 0x28 //Active No-Load Power Threshold
  #define QStartTh 0x29 //Reactive Startup Power Threshold
  #define QNolTh 0x2A //Reactive No-Load Power Threshold
  #define MMode 0x2B //Metering Mode Configuration
  #define CSOne 0x2C //Checksum 1
  #define AdjStart 0x30 //Measurement Calibration Start Command
  #define Ugain 0x31 //Voltage rms Gain
  #define IgainL 0x32 //L Line Current rms Gain
  #define IgainN 0x33 //N Line Current rms Gain
  #define Uoffset 0x34 //Voltage Offset
  #define IoffsetL 0x35 //L Line Current Offset
  #define IoffsetN 0x36 //N Line Current Offse
  #define PoffsetL 0x37 //L Line Active Power Offset
  #define QoffsetL 0x38 //L Line Reactive Power Offset
  #define PoffsetN 0x39 //N Line Active Power Offset
  #define QoffsetN 0x3A //N Line Reactive Power Offset
  #define CSTwo 0x3B //Checksum 2
  
  
  
  #define APenergy 0x40 //Forward Active Energy
  #define ANenergy 0x41 //Reverse Active Energy
  #define ATenergy 0x42 //Absolute Active Energy
  #define RPenergy 0x43 //Forward (Inductive) Reactive Energy
  #define Rnenerg 0x44 //Reverse (Capacitive) Reactive Energy
  #define Rtenergy 0x45 //Absolute Reactive Energy
  #define EnStatus 0x46 //Metering Status
  
  
  
  #define Irms 0x48 //L Line Current rms
  #define Irms2 0x68 //N Line Current rms
  #define Urms 0x49 //Voltage rms
  #define Pmean 0x4A //L Line Mean Active Power
  #define Qmean 0x4B //L Line Mean Reactive Power
  #define Freq 0x4C //Voltage Frequency
  #define PowerF 0x4D //L Line Power Factor
  #define Pangle 0x4E //Phase Angle between Voltage and L Line Current
  #define Smean 0x4F //L Line Mean Apparent Power
  #define PmeanTwo 0x6A //N Line Mean Active Power
  #define QmeanTwo 0x6B //N Line Mean Reactive Power
  #define PowerFTwo 0x6D //N Line Power Factor
  #define PangleTwo 0x6E //Phase Angle between Voltage and N Line Current
  #define SmeanTwo 0x6F //N Line Mean Apparent Power

class ATM90E26_UART{
	
  public:
  ATM90E26_UART(Stream* UART);
  double   FETCH_mains();
  double   FETCH_LIVECurrent();
  double   FETCH_NEUTRALCurrent();
  double   FETCH_ActivePower();
  double   FETCH_Frequency();
  double   FETCH_PowerFactor();
  double   FETCH_ImportEnergy();
  double   FETCH_ExportEnergy();
  double   FETCH_ActiveEnergy();
		
  void SET_register_values();
  void resetchip();
  unsigned short  FETCH_SysStatus();
  unsigned short  FETCH_MeterStatus();
  unsigned short  FETCH_MeterCSOne();
  unsigned short  FETCH_MeterCSTwo();
		
  private:
  unsigned short AFECHIP(unsigned char RW,unsigned char address, unsigned short val);
  Stream* ATM_UART;
};

#endif
