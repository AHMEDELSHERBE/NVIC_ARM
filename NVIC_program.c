#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
#include "../include/STD_TYPES.h"
#include "../include/NVIC_config.h"
#include "../include/NVIC_interface.h"
#include "../include/NVIC_priv.h"

void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
    if (Copy_u8IntNumber <=31)
    {
        NVIC_ISER0 = (1 << Copy_u8IntNumber);
    }


    else if (Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        NVIC_ISER1 = (1 << Copy_u8IntNumber);
    }

    else
    {
        /**< RETURN ERROR STATUS */
    }
}


void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
    if (Copy_u8IntNumber <=31)
    {
        NVIC_ICER0 = (1 << Copy_u8IntNumber);
    }


    else if (Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        NVIC_ICER1 = (1 << Copy_u8IntNumber);
    }

    else
    {
        /**< RETURN ERROR STATUS */
    }
}



void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
    if (Copy_u8IntNumber <=31)
        {
            NVIC_ISPR0 = (1 << Copy_u8IntNumber);
        }


    else if (Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        NVIC_ISPR1 = (1 << Copy_u8IntNumber);
    }

    else
    {
        /**< RETURN ERROR STATUS */
    }
}


void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
     if (Copy_u8IntNumber <=31)
        {
            NVIC_ICPR0 = (1 << Copy_u8IntNumber);
        }


    else if (Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        NVIC_ICPR1 = (1 << Copy_u8IntNumber);
    }

    else
    {
        /**< RETURN ERROR STATUS */
    }
}

u8 MNVIC_voidReadActiveFlag(u8 Copy_u8IntNumber)
{
    u8 LOC_u8FlagValue;

     if (Copy_u8IntNumber <=31)
        {
           LOC_u8FlagValue = GET_BIT (NVIC_IABR0, Copy_u8IntNumber);
        }


    else if (Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        LOC_u8FlagValue = GET_BIT (NVIC_IABR1, Copy_u8IntNumber);
    }

    else
    {
        /**< RETURN ERROR STATUS */
    }

    return (LOC_u8FlagValue);
}

void MNVIC_voidSetPriority(s8 Copy_s8IntNumber, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u8Option)
{
    u8 LOC_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((Copy_u8Option - Option_1)/256))  ;

    SCB_AIRCR = Copy_u8Option;

    if (Copy_s8IntNumber < 0)
    {
        /*Internal INT*/
    }

    else if  (Copy_s8IntNumber >= 0)
    {
        /*External INT*/
    	NVIC_IPR[Copy_s8IntNumber]=  LOC_u8Priority;
    }

    else
    {
        /*<RETURN Error>*/
    }
}
