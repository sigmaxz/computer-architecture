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
extern char *STD_TEXTIO;
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;

char *ieee_p_2592010699_sub_24166140421859237_503743352(char *, char *, char *, char *);
int ieee_p_3620187407_sub_5109402382352621412_3965413181(char *, char *, char *);


static void work_a_2051083417_3212880686_p_0(char *t0)
{
    char t14[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned char t9;
    int t10;
    int t11;
    unsigned char t12;
    char *t13;
    unsigned int t15;
    int t16;
    int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;

LAB0:    xsi_set_current_line(256, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(282, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 1192U);
    t5 = *((char **)t1);
    t1 = (t0 + 7352U);
    t10 = ieee_p_3620187407_sub_5109402382352621412_3965413181(IEEE_P_3620187407, t5, t1);
    t11 = (t10 - 255);
    t15 = (t11 * -1);
    xsi_vhdl_check_range_of_index(255, 0, -1, t10);
    t18 = (32U * t15);
    t19 = (0 + t18);
    t6 = (t2 + t19);
    t7 = (t0 + 4320);
    t8 = (t7 + 56U);
    t13 = *((char **)t8);
    t21 = (t13 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t6, 32U);
    xsi_driver_first_trans_fast_port(t7);
    xsi_set_current_line(284, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB23;

LAB25:    xsi_set_current_line(288, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 1672U);
    t5 = *((char **)t1);
    t1 = (t0 + 7384U);
    t10 = ieee_p_3620187407_sub_5109402382352621412_3965413181(IEEE_P_3620187407, t5, t1);
    t11 = (t10 - 255);
    t15 = (t11 * -1);
    xsi_vhdl_check_range_of_index(255, 0, -1, t10);
    t18 = (32U * t15);
    t19 = (0 + t18);
    t6 = (t2 + t19);
    t7 = (t0 + 4384);
    t8 = (t7 + 56U);
    t13 = *((char **)t8);
    t21 = (t13 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t6, 32U);
    xsi_driver_first_trans_fast_port(t7);

LAB24:
LAB3:    t1 = (t0 + 4176);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(258, ng0);
    t1 = (t0 + 2568U);
    t5 = *((char **)t1);
    t1 = (t0 + 2896U);
    t6 = (t0 + 15849);
    t8 = (t0 + 7336U);
    t9 = std_textio_file_open2(t1, t6, t8, (unsigned char)0);
    *((unsigned char *)t5) = t9;
    xsi_set_current_line(260, ng0);
    t1 = (t0 + 2568U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)0);
    if (t4 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(272, ng0);
    t1 = (t0 + 15865);
    xsi_report(t1, 23U, (unsigned char)1);
    xsi_set_current_line(273, ng0);
    t1 = (t0 + 15888);
    *((int *)t1) = 0;
    t2 = (t0 + 15892);
    *((int *)t2) = 255;
    t10 = 0;
    t11 = 255;

LAB18:    if (t10 <= t11)
        goto LAB19;

LAB21:
LAB6:    xsi_set_current_line(279, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 4320);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t13 = *((char **)t8);
    memcpy(t13, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(280, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 4384);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t13 = *((char **)t8);
    memcpy(t13, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB3;

LAB5:    xsi_set_current_line(261, ng0);
    t1 = (t0 + 15857);
    *((int *)t1) = 0;
    t5 = (t0 + 15861);
    *((int *)t5) = 255;
    t10 = 0;
    t11 = 255;

LAB8:    if (t10 <= t11)
        goto LAB9;

LAB11:    xsi_set_current_line(270, ng0);
    t1 = (t0 + 2896U);
    std_textio_file_close(t1);
    goto LAB6;

LAB9:    xsi_set_current_line(262, ng0);
    t6 = (t0 + 2896U);
    t9 = std_textio_endfile(t6);
    t12 = (!(t9));
    if (t12 != 0)
        goto LAB12;

LAB14:    xsi_set_current_line(267, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 15857);
    t16 = *((int *)t5);
    t17 = (t16 - 255);
    t15 = (t17 * -1);
    t18 = (32U * t15);
    t19 = (0U + t18);
    t6 = (t0 + 4256);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t13 = (t8 + 56U);
    t21 = *((char **)t13);
    memcpy(t21, t1, 32U);
    xsi_driver_first_trans_delta(t6, t19, 32U, 0LL);

LAB13:
LAB10:    t1 = (t0 + 15857);
    t10 = *((int *)t1);
    t2 = (t0 + 15861);
    t11 = *((int *)t2);
    if (t10 == t11)
        goto LAB11;

LAB17:    t16 = (t10 + 1);
    t10 = t16;
    t5 = (t0 + 15857);
    *((int *)t5) = t10;
    goto LAB8;

LAB12:    xsi_set_current_line(263, ng0);
    t7 = (t0 + 3664);
    t8 = (t0 + 2896U);
    t13 = (t0 + 3072U);
    std_textio_readline(STD_TEXTIO, t7, t8, t13);
    xsi_set_current_line(264, ng0);
    t1 = (t0 + 3664);
    t2 = (t0 + 3072U);
    t5 = (t0 + 2448U);
    t6 = *((char **)t5);
    t5 = (t0 + 7464U);
    std_textio_read4(STD_TEXTIO, t1, t2, t6, t5);
    xsi_set_current_line(265, ng0);
    t1 = (t0 + 2448U);
    t2 = *((char **)t1);
    t1 = (t0 + 7464U);
    t5 = ieee_p_2592010699_sub_24166140421859237_503743352(IEEE_P_2592010699, t14, t2, t1);
    t6 = (t14 + 12U);
    t15 = *((unsigned int *)t6);
    t15 = (t15 * 1U);
    t3 = (32U != t15);
    if (t3 == 1)
        goto LAB15;

LAB16:    t7 = (t0 + 15857);
    t16 = *((int *)t7);
    t17 = (t16 - 255);
    t18 = (t17 * -1);
    t19 = (32U * t18);
    t20 = (0U + t19);
    t8 = (t0 + 4256);
    t13 = (t8 + 56U);
    t21 = *((char **)t13);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t5, 32U);
    xsi_driver_first_trans_delta(t8, t20, 32U, 0LL);
    goto LAB13;

LAB15:    xsi_size_not_matching(32U, t15, 0);
    goto LAB16;

LAB19:    xsi_set_current_line(274, ng0);
    t5 = xsi_get_transient_memory(32U);
    memset(t5, 0, 32U);
    t6 = t5;
    memset(t6, (unsigned char)2, 32U);
    t7 = (t0 + 15888);
    t16 = *((int *)t7);
    t17 = (t16 - 255);
    t15 = (t17 * -1);
    t18 = (32U * t15);
    t19 = (0U + t18);
    t8 = (t0 + 4256);
    t13 = (t8 + 56U);
    t21 = *((char **)t13);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t5, 32U);
    xsi_driver_first_trans_delta(t8, t19, 32U, 0LL);

LAB20:    t1 = (t0 + 15888);
    t10 = *((int *)t1);
    t2 = (t0 + 15892);
    t11 = *((int *)t2);
    if (t10 == t11)
        goto LAB21;

LAB22:    t16 = (t10 + 1);
    t10 = t16;
    t5 = (t0 + 15888);
    *((int *)t5) = t10;
    goto LAB18;

LAB23:    xsi_set_current_line(285, ng0);
    t1 = (t0 + 1832U);
    t5 = *((char **)t1);
    t1 = (t0 + 1672U);
    t6 = *((char **)t1);
    t1 = (t0 + 7384U);
    t10 = ieee_p_3620187407_sub_5109402382352621412_3965413181(IEEE_P_3620187407, t6, t1);
    t11 = (t10 - 255);
    t15 = (t11 * -1);
    t18 = (32U * t15);
    t19 = (0U + t18);
    t7 = (t0 + 4256);
    t8 = (t7 + 56U);
    t13 = *((char **)t8);
    t21 = (t13 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t5, 32U);
    xsi_driver_first_trans_delta(t7, t19, 32U, 0LL);
    xsi_set_current_line(286, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 4384);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB24;

}


extern void work_a_2051083417_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2051083417_3212880686_p_0};
	xsi_register_didat("work_a_2051083417_3212880686", "isim/Processor_test_isim_beh.exe.sim/work/a_2051083417_3212880686.didat");
	xsi_register_executes(pe);
}
