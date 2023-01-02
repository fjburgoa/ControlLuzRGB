/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////

#include "si_toolchain.h"
#include "C8051F300_defs.h"

// Peripheral specific initialization functions,
// Called from the Init_Device() function
void Reset_Sources_Init()
{
    RSTSRC    = 0x04;
}

void PCA_Init()
{
    PCA0MD    &= ~0x40;
    PCA0MD    = 0x00;
}

void Timer_Init()
{
    TCON      = 0x10;
    TMOD      = 0x02;
    CKCON     = 0x02;
    TH0       = 0x56;
}

void ADC_Init()
{
    AMX0SL    = 0x86;
    ADC0CF    = 0xF9;
    ADC0CN    = 0x81;
}

void Voltage_Reference_Init()
{
    REF0CN    = 0x08;
}

void Port_IO_Init()
{
    // P0.0  -  Unassigned,  Push-Pull,  Digital
    // P0.1  -  Unassigned,  Push-Pull,  Digital
    // P0.2  -  Unassigned,  Push-Pull,  Digital
    // P0.3  -  Unassigned,  Open-Drain, Digital
    // P0.4  -  Skipped,     Open-Drain, Analog
    // P0.5  -  Skipped,     Open-Drain, Analog
    // P0.6  -  Skipped,     Open-Drain, Analog
    // P0.7  -  Unassigned,  Push-Pull,  Digital

    P0MDIN    = 0x8F;
    P0MDOUT   = 0x87;
    XBR0      = 0x70;
    XBR2      = 0x40;
}

void Oscillator_Init()
{
    OSCICN    = 0x07;
}

void Interrupts_Init()
{
    EIE1      = 0x04;
    IE        = 0x82;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Reset_Sources_Init();
    PCA_Init();
    Timer_Init();
    ADC_Init();
    Voltage_Reference_Init();
    Port_IO_Init();
    Oscillator_Init();
    Interrupts_Init();
}
