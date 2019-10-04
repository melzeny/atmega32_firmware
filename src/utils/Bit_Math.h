#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define Set_Bit(Var,BitNo)       Var |= (1<<BitNo)
#define Clr_Bit(Var,BitNo)       Var &= ~(1<<BitNo)
#define Toggle_Bit(Var,BitNo)    Var ^= (1<<BitNo)
#define Get_Bit(Var,BitNo)       ((Var >> BitNo) & 0b00000001)



#endif
