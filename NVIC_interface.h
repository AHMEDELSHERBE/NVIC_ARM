#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
#include "STD_TYPES.h"

/* Options of Group Priority and sub Piriority Using System control block core peripheral*/

/* in (SCB => AIRCR) 4 bits for group and 0 sub => 4bits in (IPR) to determine group number	*/
#define Option_1    0x05FA0300

/* in (SCB => AIRCR) 3 bits for Group and 1 bit for sub										*/
#define Option_2    0x05FA0400

/* in (SCB => AIRCR) 2 bits for Group and 2 bit for sub										*/
#define Option_3    0x05FA0500

/* in (SCB => AIRCR) 1 bits for Group and 3 bit for sub										*/
#define Option_4    0x05FA0600

/* in (SCB => AIRCR) 0 bits for Group and 4 bit for sub										*/
#define Option_5    0x05FA0700

void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
 u8 MNVIC_voidReadActiveFlag(u8 Copy_u8IntNumber);

 void MNVIC_voidSetPriority(s8 Copy_s8IntNumber, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u8Option);

#endif
