/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/csmajs/svill017/cs161/lab4/cs161_processor/cpu_components.vhd";



static void work_a_3044219816_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    xsi_set_current_line(57, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 4672);
    t4 = 1;
    if (2U == 2U)
        goto LAB5;

LAB6:    t4 = 0;

LAB7:    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 4678);
    t4 = 1;
    if (2U == 2U)
        goto LAB13;

LAB14:    t4 = 0;

LAB15:    if (t4 != 0)
        goto LAB11;

LAB12:    xsi_set_current_line(62, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t5 = (5 - 3);
    t15 = (t5 * 1U);
    t16 = (0 + t15);
    t1 = (t2 + t16);
    t3 = (t0 + 4684);
    t4 = 1;
    if (4U == 4U)
        goto LAB22;

LAB23:    t4 = 0;

LAB24:    if (t4 != 0)
        goto LAB19;

LAB21:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t5 = (5 - 3);
    t15 = (t5 * 1U);
    t16 = (0 + t15);
    t1 = (t2 + t16);
    t3 = (t0 + 4692);
    t4 = 1;
    if (4U == 4U)
        goto LAB30;

LAB31:    t4 = 0;

LAB32:    if (t4 != 0)
        goto LAB28;

LAB29:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t5 = (5 - 3);
    t15 = (t5 * 1U);
    t16 = (0 + t15);
    t1 = (t2 + t16);
    t3 = (t0 + 4700);
    t4 = 1;
    if (4U == 4U)
        goto LAB38;

LAB39:    t4 = 0;

LAB40:    if (t4 != 0)
        goto LAB36;

LAB37:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t5 = (5 - 3);
    t15 = (t5 * 1U);
    t16 = (0 + t15);
    t1 = (t2 + t16);
    t3 = (t0 + 4708);
    t4 = 1;
    if (4U == 4U)
        goto LAB46;

LAB47:    t4 = 0;

LAB48:    if (t4 != 0)
        goto LAB44;

LAB45:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t5 = (5 - 3);
    t15 = (t5 * 1U);
    t16 = (0 + t15);
    t1 = (t2 + t16);
    t3 = (t0 + 4716);
    t4 = 1;
    if (4U == 4U)
        goto LAB54;

LAB55:    t4 = 0;

LAB56:    if (t4 != 0)
        goto LAB52;

LAB53:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t5 = (5 - 3);
    t15 = (t5 * 1U);
    t16 = (0 + t15);
    t1 = (t2 + t16);
    t3 = (t0 + 4724);
    t4 = 1;
    if (4U == 4U)
        goto LAB62;

LAB63:    t4 = 0;

LAB64:    if (t4 != 0)
        goto LAB60;

LAB61:    xsi_set_current_line(75, ng0);
    t1 = (t0 + 4732);
    t3 = (t0 + 2904);
    t6 = (t3 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 4U);
    xsi_driver_first_trans_fast_port(t3);

LAB20:
LAB3:    t1 = (t0 + 2824);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(58, ng0);
    t8 = (t0 + 4674);
    t10 = (t0 + 2904);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t8, 4U);
    xsi_driver_first_trans_fast_port(t10);
    goto LAB3;

LAB5:    t5 = 0;

LAB8:    if (t5 < 2U)
        goto LAB9;
    else
        goto LAB7;

LAB9:    t6 = (t2 + t5);
    t7 = (t1 + t5);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB6;

LAB10:    t5 = (t5 + 1);
    goto LAB8;

LAB11:    xsi_set_current_line(60, ng0);
    t8 = (t0 + 4680);
    t10 = (t0 + 2904);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t8, 4U);
    xsi_driver_first_trans_fast_port(t10);
    goto LAB3;

LAB13:    t5 = 0;

LAB16:    if (t5 < 2U)
        goto LAB17;
    else
        goto LAB15;

LAB17:    t6 = (t2 + t5);
    t7 = (t1 + t5);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB14;

LAB18:    t5 = (t5 + 1);
    goto LAB16;

LAB19:    xsi_set_current_line(63, ng0);
    t9 = (t0 + 4688);
    t11 = (t0 + 2904);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t18 = *((char **)t14);
    memcpy(t18, t9, 4U);
    xsi_driver_first_trans_fast_port(t11);
    goto LAB20;

LAB22:    t17 = 0;

LAB25:    if (t17 < 4U)
        goto LAB26;
    else
        goto LAB24;

LAB26:    t7 = (t1 + t17);
    t8 = (t3 + t17);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB23;

LAB27:    t17 = (t17 + 1);
    goto LAB25;

LAB28:    xsi_set_current_line(65, ng0);
    t9 = (t0 + 4696);
    t11 = (t0 + 2904);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t18 = *((char **)t14);
    memcpy(t18, t9, 4U);
    xsi_driver_first_trans_fast_port(t11);
    goto LAB20;

LAB30:    t17 = 0;

LAB33:    if (t17 < 4U)
        goto LAB34;
    else
        goto LAB32;

LAB34:    t7 = (t1 + t17);
    t8 = (t3 + t17);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB31;

LAB35:    t17 = (t17 + 1);
    goto LAB33;

LAB36:    xsi_set_current_line(67, ng0);
    t9 = (t0 + 4704);
    t11 = (t0 + 2904);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t18 = *((char **)t14);
    memcpy(t18, t9, 4U);
    xsi_driver_first_trans_fast_port(t11);
    goto LAB20;

LAB38:    t17 = 0;

LAB41:    if (t17 < 4U)
        goto LAB42;
    else
        goto LAB40;

LAB42:    t7 = (t1 + t17);
    t8 = (t3 + t17);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB39;

LAB43:    t17 = (t17 + 1);
    goto LAB41;

LAB44:    xsi_set_current_line(69, ng0);
    t9 = (t0 + 4712);
    t11 = (t0 + 2904);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t18 = *((char **)t14);
    memcpy(t18, t9, 4U);
    xsi_driver_first_trans_fast_port(t11);
    goto LAB20;

LAB46:    t17 = 0;

LAB49:    if (t17 < 4U)
        goto LAB50;
    else
        goto LAB48;

LAB50:    t7 = (t1 + t17);
    t8 = (t3 + t17);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB47;

LAB51:    t17 = (t17 + 1);
    goto LAB49;

LAB52:    xsi_set_current_line(71, ng0);
    t9 = (t0 + 4720);
    t11 = (t0 + 2904);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t18 = *((char **)t14);
    memcpy(t18, t9, 4U);
    xsi_driver_first_trans_fast_port(t11);
    goto LAB20;

LAB54:    t17 = 0;

LAB57:    if (t17 < 4U)
        goto LAB58;
    else
        goto LAB56;

LAB58:    t7 = (t1 + t17);
    t8 = (t3 + t17);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB55;

LAB59:    t17 = (t17 + 1);
    goto LAB57;

LAB60:    xsi_set_current_line(73, ng0);
    t9 = (t0 + 4728);
    t11 = (t0 + 2904);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t18 = *((char **)t14);
    memcpy(t18, t9, 4U);
    xsi_driver_first_trans_fast_port(t11);
    goto LAB20;

LAB62:    t17 = 0;

LAB65:    if (t17 < 4U)
        goto LAB66;
    else
        goto LAB64;

LAB66:    t7 = (t1 + t17);
    t8 = (t3 + t17);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB63;

LAB67:    t17 = (t17 + 1);
    goto LAB65;

}


extern void work_a_3044219816_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3044219816_3212880686_p_0};
	xsi_register_didat("work_a_3044219816_3212880686", "isim/Processor_test_isim_beh.exe.sim/work/a_3044219816_3212880686.didat");
	xsi_register_executes(pe);
}
