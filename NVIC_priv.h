#ifndef NVIC_PRIV_H
#define NVIC_PRIV_H
#include "STD_TYPES.h"
#define NVIC_Based_Adress  0xE000E100
#define NVIC_ISER0  *((u32 *)(NVIC_Based_Adress + 0x000))
#define NVIC_ISER1  *((u32 *)(NVIC_Based_Adress + 0x004))
	/*inturrupt set enable register*/
#define NVIC_ICER0  *((u32 *)(NVIC_Based_Adress + 0x080))
#define NVIC_ICER1  *((u32 *)(NVIC_Based_Adress + 0x084))
/*inturrupt clear enable register*/
#define NVIC_ISPR0   *((u32 *)(NVIC_Based_Adress + 0x100))
#define NVIC_ISPR1   *((u32 *)(NVIC_Based_Adress + 0x104))
/*inturrupt set pending register*/
#define NVIC_ICPR0  *((u32 *)(NVIC_Based_Adress + 0x180))
#define NVIC_ICPR1   *((u32 *)(NVIC_Based_Adress + 0x184))
/*inturrupt clear pinning register*/

/*priority*/


#define  NVIC_IABR0  *((volatile u32 *)(NVIC_Based_Adress + 0x200))
#define  NVIC_IABR1  *((volatile u32 *)(NVIC_Based_Adress + 0x204))

#define NVIC_IPR    ((volatile u8  *)(NVIC_Based_Adress + 0x300))

#define SCB_AIRCR   *((volatile u32 *)(0xE000ED00 + 0x0C))













#endif
