/*******************************************************
 * file_name  : timer.c
 * DIR:/28335_APP/bsp/src/timer.c
 * Created on : 2017��8��11��-����10:21:59
 * Author     : admin
 * Version    :
 *
 ******************************************************/
#include "timer.h"
#include "os.h"
void CPU_timer1_init(void)
{
	EALLOW;
		SysCtrlRegs.PCLKCR3.bit.CPUTIMER1ENCLK = 1;
	EDIS;
	InitCpuTimers();
	ConfigCpuTimer(&CpuTimer1, 150, 100);
	CpuTimer1Regs.TCR.all = 0x4001; // Use write-only instruction to set TSS bit = 0
}
__interrupt void CPU_timer1_isr(void)
{
	taskclock();

}
