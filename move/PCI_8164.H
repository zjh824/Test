#ifndef _P8164_1_H

#define _P8164_1_H

#include "motion.h"

#ifdef _MYWACOMC
	#include "type_wef.h"
#else
	#include "type_def.h"
#endif

#if defined _MYWIN32
//	#define _WIN32_WINNT 0x0400
	#include <windows.h>
#endif

#if defined _MYWINCE
	#include <windows.h>
#endif

#define MAX_PCI_CARDS   (I16)12
#define MAX_MPC_CARDS	(I16)4
#define MAX_EVENTA		(I16)6
#define AXIS_PER_CARD 	(I16)4

#define CARD0 (I16)0
#define CARD1 (I16)1
#define CARD2 (I16)2
#define CARD3 (I16)3
#define CARD4 (I16)4
#define CARD5 (I16)5
#define CARD6 (I16)6
#define CARD7 (I16)7
#define CARD8 (I16)8
#define CARD9 (I16)9
#define CARD10 (I16)10
#define CARD11 (I16)11

#ifdef __cplusplus
extern "C" {
#endif
#if defined(_MYWIN32) || defined(_MYHYPERK)
	I16 FNTYPE _8164_initial(I16 *existCards);
#else
	I16 FNTYPE _8164_initialx(U16 BaseAddress,U16 IRQNo);
#endif

#if defined(_MYWIN32) || defined (_MYWINCE)
I16 FNTYPE _8164_int_enable(I16 CardNo,HANDLE *phEvent);
I16 FNTYPE _8164_int_disable(I16 CardNo);
I16 FNTYPE _8164_get_int_status(I16 AxisNo, U32 *error_int_status, U32 *event_int_status );
I16 FNTYPE _8164_link_interrupt(I16 CardNo,void ( __stdcall *callbackAddr)(I16 IntAxisNoInCard));
I16 FNTYPE _8164_set_auto_compare(I16 AxisNo ,I16 SelectSrc);
I16 FNTYPE _8164_build_compare_function(I16 AxisNo, F64 Start, F64 End, F64 Interval, I16 Device);
I16 FNTYPE _8164_build_compare_table(I16 AxisNo, F64 *TableArray, I32 Size, I16 Device);

I16 FNTYPE _8164_delay_time_mt(I16 AxisNo,F64 miniSecond, I32 Timeout_ms, HANDLE waitEvent);

I16 FNTYPE _8164_int_enableA(I16 CardNo,HANDLE *phEvent);
I16 FNTYPE _8164_int_disableA(I16 CardNo);
I16 FNTYPE _8164_map_axis_event(I16 AxisNo, I16 EventNo, U32 IntFactor );
#endif

#ifdef _MYLINUX
    I16 FNTYPE _8164_int_enable(I16 CardNo, void (*event_handler1)(int), void (*event_handler2)(int),        void (*event_handler3)(int), void (*event_handler4)(int));
    I16 FNTYPE _8164_int_disable(I16 CardNo);
	I16 FNTYPE _8164_get_int_status(I16 AxisNo, U32 *error_int_status, U32 *event_int_status );
	I16 FNTYPE _8164_set_auto_compare(I16 AxisNo ,I16 SelectSrc);
	I16 FNTYPE _8164_build_compare_function(I16 AxisNo, F64 Start, F64 End, F64 Interval);
	I16 FNTYPE _8164_build_compare_table(I16 AxisNo, F64 *TableArray, I32 Size);
#endif

#if defined(_MYHYPERK)
I16 FNTYPE _8164_int_enable(I16 CardNo,I32 ThreadID);
I16 FNTYPE _8164_int_disable(I16 CardNo);
I16 FNTYPE _8164_get_int_status(I16 AxisNo, U32 *error_int_status, U32 *event_int_status );
I16 FNTYPE _8164_set_auto_compare(I16 AxisNo ,I16 SelectSrc);
I16 FNTYPE _8164_build_compare_function(I16 AxisNo, F64 Start, F64 End, F64 Interval, I16 Device);
I16 FNTYPE _8164_build_compare_table(I16 AxisNo, F64 *TableArray, I32 Size, I16 Device);
#endif

#ifdef _MPC  // MPC-8164 Only
I16 FNTYPE _8164_write_do(I16 CardNo, U16 value);
U16 FNTYPE _8164_read_di(I16 CardNo);
I16 FNTYPE _8164_set_el_logic(I16 AxisNo, U16 logic);
I16 FNTYPE _8164_get_el_logic(I16 AxisNo, U16 *logic);
#endif

I16 FNTYPE _8164_set_security_key(I16 CardNo, U16 old_secu_code, U16 New_secu_code);
I16 FNTYPE _8164_check_security_key( I16 CardNo, U16 secu_code);
I16 FNTYPE _8164_reset_security_key(I16 CardNo);

I16 FNTYPE _8164_set_user_code( I16 CardNo, U16 *DataArr, U16 ArrSize );
I16 FNTYPE _8164_get_user_code( I16 CardNo, U16 *DataArr, U16 ArrSize );

I16 FNTYPE _8164_int_control(U16 cardNo, U16 intFlag );
I16 FNTYPE _8164_set_int_factor(I16 AxisNo, U32 int_factor );
I16 FNTYPE _8164_close(void);
I16 FNTYPE _8164_get_irq_channel(I16 cardNo, U16 *irq_no );
I16 FNTYPE _8164_get_base_addr(I16 cardNo, U16 *base_addr );
I16 FNTYPE _8164_get_io_status(I16 AxisNo, U16 *io_sts);
I16 FNTYPE _8164_motion_done(I16 AxisNo);
I16 FNTYPE _8164_get_position(I16 AxisNo, F64 *pos);
I16 FNTYPE _8164_set_position(I16 AxisNo, F64 pos);
I16 FNTYPE _8164_get_command(I16 AxisNo, I32 *cmd);
I16 FNTYPE _8164_set_command(I16 AxisNo, I32 cmd);
I16 FNTYPE _8164_get_error_counter(I16 AxisNo, I16 *error);
I16 FNTYPE _8164_reset_error_counter(I16 AxisNo);
I16 FNTYPE _8164_get_target_pos(I16 AxisNo, F64 *pos);
I16 FNTYPE _8164_reset_target_pos(I16 AxisNo, F64 pos);
I16 FNTYPE _8164_get_current_speed(I16 AxisNo, F64 *speed);
I16 FNTYPE _8164_get_rest_command(I16 AxisNo, I32 *rest_command);
I16 FNTYPE _8164_get_latch_data(I16 AxisNo, I16 LatchNo, F64 *Pos);
I16 FNTYPE _8164_check_rdp(I16 AxisNo, I32 *rdp_command);
I16 FNTYPE _8164_set_servo(I16 AxisNo, I16 on_off);
I16 FNTYPE _8164_set_pls_outmode(I16 AxisNo, I16 pls_outmode);
I16 FNTYPE _8164_set_pls_iptmode(I16 AxisNo, I16 pls_iptmode, I16 pls_logic);
I16 FNTYPE _8164_set_feedback_src(I16 AxisNo, I16 Src);
I16 FNTYPE _8164_set_general_counter(I16 AxisNo,I16 CntSrc, F64 CntValue);
I16 FNTYPE _8164_get_general_counter(I16 AxisNo, F64 *CntValue);

// PCI-8164 Only
I16 FNTYPE _8164_d_output(I16 CardNo, I16 Ch_No, I16 value);
I16 FNTYPE _8164_get_dio_status(I16 CardNo, U16 *dio_sts);

I16 FNTYPE _8164_set_alm(I16 AxisNo, I16 alm_logic, I16 alm_mode);
I16 FNTYPE _8164_set_inp(I16 AxisNo, I16 inp_enable, I16 inp_logic);
I16 FNTYPE _8164_set_ltc_logic(I16 AxisNo, I16 ltc_logic);
I16 FNTYPE _8164_set_pcs_logic(I16 AxisNo, I16 pcs_logic);
I16 FNTYPE _8164_set_erc(I16 AxisNo, I16 erc_logic, I16 erc_on_time);
I16 FNTYPE _8164_set_sd(I16 AxisNo, I16 enable, I16 sd_logic, I16 sd_latch, I16 sd_mode);
I16 FNTYPE _8164_set_el(I16 AxisNo, I16 el_mode);
I16 FNTYPE _8164_set_move_ratio(I16 AxisNo, F64 move_ratio);
I16 FNTYPE _8164_set_sd_pin(I16 AxisNo, I16 Type);

I16 FNTYPE _8164_set_home_config(I16 AxisNo, I16 home_mode, I16 org_logic, I16 ez_logic, I16 ez_count, I16 erc_out);
I16 FNTYPE _8164_home_move(I16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc);

I16 FNTYPE _8164_pulser_vmove(I16 AxisNo,F64 SpeedLimit);
I16 FNTYPE _8164_pulser_pmove(I16 AxisNo, F64 Dist,F64 SpeedLimit);
I16 FNTYPE _8164_pulser_home_move(I16 AxisNo, I16 HomeType,F64 SpeedLimit);
I16 FNTYPE _8164_set_pulser_iptmode(I16 AxisNo,I16 InputMode, I16 Inverse);
I16 FNTYPE _8164_backlash_comp(I16 AxisNo, I16 BCompPulse, I16 Mode);
I16 FNTYPE _8164_suppress_vibration(I16 AxisNo, U16 ReverseTime, U16 ForwardTime);

// Pitch compensate function
I16 FNTYPE _8164_set_pitch_compensate(I16 AxisNo, I16 TableSize, I32 *PTableArray, I32 *NTableArray, I32 TableInterval);
I16 FNTYPE _8164_enable_pitch_compensate(I16 AxisNo, I16 Enable);
I16 FNTYPE _8164_calculate_amove_pitch_compensate( I16 AxisNo, F64 Pos, F64 *Result );
I16 FNTYPE _8164_calculate_rmove_pitch_compensate( I16 AxisNo, F64 Dist, F64 *Result );
I16 FNTYPE _8164_get_pitch_table_target_pos( I16 AxisNo, F64 *TargetPos );

I16 FNTYPE _8164_tv_move(I16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc);
I16 FNTYPE _8164_sv_move(I16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc, F64 SVacc);
I16 FNTYPE _8164_emg_stop(I16 AxisNo);
I16 FNTYPE _8164_sd_stop(I16 AxisNo,F64 Tdec);
I16 FNTYPE _8164_sd_stop_ex(I16 AxisNo,F64 Tdec);
I16 FNTYPE _8164_v_change(I16 AxisNo, F64 NewVel, F64 Time);
I16 FNTYPE _8164_cmp_v_change(I16 AxisNo, F64 Res_Dist, F64 OldVel, F64 NewVel, F64 Time);
I16 FNTYPE _8164_p_change(I16 AxisNo, F64 NewPos);
I16 FNTYPE _8164_fix_speed_range(I16 AxisNo, F64 MaxVel);
I16 FNTYPE _8164_unfix_speed_range(I16 AxisNo);
I16 FNTYPE _8164_set_continuous_move(I16 AxisNo, I16 conti_logic);

I16 FNTYPE _8164_set_soft_limit(I16 AxisNo, I32 PLimit, I32 NLimit);
I16 FNTYPE _8164_disable_soft_limit(I16 AxisNo);
I16 FNTYPE _8164_enable_soft_limit(I16 AxisNo, I16 Action);

I16 FNTYPE _8164_set_error_counter_check(I16 AxisNo, I16 Tolerance, I16 On_Off);
I16 FNTYPE _8164_set_general_comparator(I16 AxisNo, I16 CmpSrc, I16 CmpMethod, I16 CmpAction, F64 Data);
I16 FNTYPE _8164_set_trigger_comparator(I16 AxisNo, I16 CmpSrc, I16 CmpMethod, F64 Data);
I16 FNTYPE _8164_set_trigger_type(I16 AxisNo, I16 TriggerType);

I16 FNTYPE _8164_check_compare_data(I16 AxisNo, I16 CompType, F64 *Pos);

I16 FNTYPE _8164_start_tr_move(I16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec);
I16 FNTYPE _8164_start_ta_move(I16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8164_start_sr_move(I16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
I16 FNTYPE _8164_start_sa_move(I16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);

// Speed Profile Calculation
I16 FNTYPE _8164_get_tr_move_profile(I16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 *pStrVel, F64 *pMaxVel, F64 *pTacc, F64 *pTdec, F64 *pTconst );
I16 FNTYPE _8164_get_ta_move_profile(I16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 *pStrVel, F64 *pMaxVel, F64 *pTacc, F64 *pTdec, F64 *pTconst );
I16 FNTYPE _8164_get_sr_move_profile(I16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec,F64 *pStrVel, F64 *pMaxVel, F64 *pTacc, F64 *pTdec, F64 *pSVacc, F64 *pSVdec, F64 *pTconst);
I16 FNTYPE _8164_get_sa_move_profile(I16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec,F64 *pStrVel, F64 *pMaxVel, F64 *pTacc, F64 *pTdec, F64 *pSVacc, F64 *pSVdec, F64 *pTconst);

I16 FNTYPE _8164_start_tr_move_xy(I16 CardNo, F64 DistX, F64 DistY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8164_start_ta_move_xy(I16 CardNo, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8164_start_sr_move_xy(I16 CardNo, F64 DistX, F64 DistY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
I16 FNTYPE _8164_start_sa_move_xy(I16 CardNo, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);

I16 FNTYPE _8164_start_tr_move_zu(I16 CardNo, F64 DistX, F64 DistY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8164_start_ta_move_zu(I16 CardNo, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8164_start_sr_move_zu(I16 CardNo, F64 DistX, F64 DistY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
I16 FNTYPE _8164_start_sa_move_zu(I16 CardNo, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);

I16 FNTYPE _8164_start_a_arc_xy(I16 CardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 MaxVel);
I16 FNTYPE _8164_start_r_arc_xy(I16 CardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR,F64 MaxVel);
I16 FNTYPE _8164_start_a_arc_zu(I16 CardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 MaxVel);
I16 FNTYPE _8164_start_r_arc_zu(I16 CardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 MaxVel );

I16 FNTYPE _8164_start_tr_line2(I16 CardNo, I16 *AxisArray, F64 DistX, F64 DistY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8164_start_ta_line2(I16 CardNo, I16 *AxisArray, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8164_start_sr_line2(I16 CardNo, I16 *AxisArray, F64 DistX, F64 DistY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
I16 FNTYPE _8164_start_sa_line2(I16 CardNo, I16 *AxisArray, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);

I16 FNTYPE _8164_start_r_arc2(I16 CardNo, I16 *AxisArray, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 MaxVel);
I16 FNTYPE _8164_start_a_arc2(I16 CardNo, I16 *AxisArray, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 MaxVel);

I16 FNTYPE _8164_start_tr_line3(I16 CardNo, I16 *AxisArray, F64 DistX, F64 DistY, F64 DistZ, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8164_start_ta_line3(I16 CardNo, I16 *AxisArray, F64 PosX, F64 PosY, F64 PosZ, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8164_start_sr_line3(I16 CardNo, I16 *AxisArray, F64 DistX, F64 DistY, F64 DistZ, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
I16 FNTYPE _8164_start_sa_line3(I16 CardNo, I16 *AxisArray, F64 PosX, F64 PosY, F64 PosZ, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);

I16 FNTYPE _8164_start_tr_line4(I16 CardNo, F64 DistX, F64 DistY, F64 DistZ, F64 DistU, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8164_start_ta_line4(I16 CardNo, F64 PosX, F64 PosY, F64 PosZ, F64 PosU, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _8164_start_sr_line4(I16 CardNo, F64 DistX, F64 DistY, F64 DistZ, F64 DistU, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
I16 FNTYPE _8164_start_sa_line4(I16 CardNo, F64 PosX, F64 PosY, F64 PosZ, F64 PosU, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);

I16 FNTYPE _8164_set_tr_move_all(I16 TotalAxes, I16 *AxisArray, F64 *DistA, F64 *StrVelA, F64 *MaxVelA, F64 *TaccA, F64 *TdecA);
I16 FNTYPE _8164_start_move_all(I16 FirstAxisNo);
I16 FNTYPE _8164_stop_move_all(I16 FirstAxisNo);

I16 FNTYPE _8164_config_from_file(char *file_name);

I16 FNTYPE _8164_set_fa_speed(I16 AxisNo, F64 FA_Speed);
I16 FNTYPE _8164_check_compare_status(I16 AxisNo, U16 *cmp_sts);
I16 FNTYPE _8164_check_continuous_buffer(I16 AxisNo);

#ifdef _WINNT
I16 FNTYPE _8164_try_leave_critical_section(void);
#endif

// New
I16 FNTYPE _8164_set_sa_move_all(I16 TotalAx, I16 *AxisArray, F64 *PosA, F64 *StrVelA, F64 *MaxVelA, F64 *TaccA, F64 *TdecA, F64 *SVaccA, F64 *SVdecA);
I16 FNTYPE _8164_set_ta_move_all(I16 TotalAx, I16 *AxisArray, F64 *PosA, F64 *StrVelA, F64 *MaxVelA, F64 *TaccA, F64 *TdecA);
I16 FNTYPE _8164_set_sr_move_all(I16 TotalAx, I16 *AxisArray, F64 *DistA, F64 *StrVelA, F64 *MaxVelA, F64 *TaccA, F64 *TdecA, F64 *SVaccA, F64 *SVdecA);
I16 FNTYPE _8164_set_latch_source(I16 AxisNo, I16 ltc_src);
I16 FNTYPE _8164_reset_counter_when_latch(I16 AxisNo, I16 EnableByBit);
I16 FNTYPE _8164_set_idle_pulse(I16 AxisNo, I16 idl_pulse);
I16 FNTYPE _8164_delay_time(I16 AxisNo,F64 miniSecond);
I16 FNTYPE _8164_set_pulser_ratio(I16 AxisNo,I16 PDV, I16 PMG);
I16 FNTYPE _8164_pulser_r_line2(I16 CardNo,I16 *AxisArray, F64 DistX, F64 DistY, F64 SpeedLimit);
I16 FNTYPE _8164_pulser_r_arc2(I16 CardNo, I16 *AxisArray, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 MaxVel);
I16 FNTYPE _8164_pulser_a_line2(I16 CardNo,I16 *AxisArray, F64 PosX, F64 PosY, F64 SpeedLimit);
I16 FNTYPE _8164_pulser_a_arc2(I16 CardNo, I16 *AxisArray, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 MaxVel);
I16 FNTYPE _8164_reset_counter_after_home(I16 AxisNo, I16 EnableByBit);

I16 FNTYPE _8164_escape_home(I16 AxisNo, F64 SrVel,F64 MaxVel,F64 Tacc);
I16 FNTYPE _8164_home_search(I16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc, F64 ORGOffset);
I16 FNTYPE _8164_set_line_move_mode(I16 AxisNo, I16 Mode);

F64 FNTYPE _8164_verify_speed(F64 StrVel,F64 MaxVel,F64 *minAccT,F64 *maxAccT, F64 MaxSpeed);

I16 FNTYPE _8164_start_tr_arc_xyu(I16 CardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc);
I16 FNTYPE _8164_start_ta_arc_xyu(I16 CardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc);
I16 FNTYPE _8164_start_sr_arc_xyu(I16 CardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc, F64 SVacc);
I16 FNTYPE _8164_start_sa_arc_xyu(I16 CardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc, F64 SVacc);
I16 FNTYPE _8164_start_tr_arc_yzu(I16 CardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc);
I16 FNTYPE _8164_start_ta_arc_yzu(I16 CardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc);
I16 FNTYPE _8164_start_sr_arc_yzu(I16 CardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc, F64 SVacc);
I16 FNTYPE _8164_start_sa_arc_yzu(I16 CardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc, F64 SVacc);

I16 FNTYPE _8164_start_tr_arc2(I16 CardNo, I16 *AxisArray, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel,F64 MaxVel, F64 Tacc,F64 Tdec);
I16 FNTYPE _8164_start_ta_arc2(I16 CardNo, I16 *AxisArray, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec);
I16 FNTYPE _8164_start_sr_arc2(I16 CardNo, I16 *AxisArray, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel,F64 MaxVel, F64 Tacc,F64 Tdec,F64 SVacc,F64 SVdec);
I16 FNTYPE _8164_start_sa_arc2(I16 CardNo, I16 *AxisArray, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec,F64 SVacc,F64 SVdec);

I16 FNTYPE _8164_start_tr_arc_xy(I16 CardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel,F64 MaxVel,F64 Tacc,F64 Tdec);
I16 FNTYPE _8164_start_ta_arc_xy(I16 CardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel,F64 MaxVel,F64 Tacc,F64 Tdec);
I16 FNTYPE _8164_start_tr_arc_zu(I16 CardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel,F64 MaxVel,F64 Tacc,F64 Tdec);
I16 FNTYPE _8164_start_ta_arc_zu(I16 CardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel,F64 MaxVel,F64 Tacc,F64 Tdec);

I16 FNTYPE _8164_start_sr_arc_xy(I16 CardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel,F64 MaxVel, F64 Tacc,F64 Tdec,F64 SVacc,F64 SVdec);
I16 FNTYPE _8164_start_sa_arc_xy(I16 CardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel,F64 MaxVel, F64 Tacc,F64 Tdec,F64 SVacc,F64 SVdec);
I16 FNTYPE _8164_start_sr_arc_zu(I16 CardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel,F64 MaxVel, F64 Tacc,F64 Tdec,F64 SVacc,F64 SVdec);
I16 FNTYPE _8164_start_sa_arc_zu(I16 CardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel,F64 MaxVel, F64 Tacc,F64 Tdec,F64 SVacc,F64 SVdec);

I16 FNTYPE _8164_set_sync_option(I16 AxisNo, I16 sync_stop_on, I16 cstop_output_on, I16 sync_option1, I16 sync_option2);
I16 FNTYPE _8164_mask_axis_stop_int(I16 AxisNo, I16 int_disable);
I16 FNTYPE _8164_set_axis_option(I16 AxisNo, I16 option);
I16 FNTYPE _8164_set_axis_stop_int(I16 AxisNo, I16 axis_stop_int);
I16 FNTYPE _8164_version_info(I16 CardNo, U16 *HardwareInfo, U16 *SoftwareInfo, U16 *DriverInfo);
I16 FNTYPE _8164_version_info_ex(I16 CardNo, U16 *HardwareInfo, I32 *SoftwareInfo, I32 *DriverInfo);
I16 FNTYPE _8164_set_sync_stop_mode(I16 AxisNo, I16 stop_mode);

I16 FNTYPE _8164_mask_output_pulse(I16 AxisNo,I16 Mask);
I16 FNTYPE _8164_set_sync_signal_source(I16 AxisNo, I16 sync_axis);
I16 FNTYPE _8164_set_sync_signal_mode(I16 AxisNo, I16 mode);

I16 FNTYPE _8164_set_auto_rdp(I16 CardNo,I16 on_off);

I16 FNTYPE _8164_start_ta_pickplace(I16 *AxisPair2, F64 *Pos3, F64 *SVel3, F64 *MVel3, F64 *AccT3, F64 *StartPoint2);
I16 FNTYPE _8164_set_rotary_counter(I16 AxisNo, I16 reset_src);
I16 FNTYPE _8164_set_auto_compare2(I16 AxisNo ,I16 SelectSrc);
I16 FNTYPE _8164_set_fifo_data(I16 AxisNo ,I32 Data);

I16 FNTYPE _8164_force_cmp_output(I16 AxisNo);
I16 FNTYPE _8164_dwell_move(I16 AxisNo, F64 miniSecond);

I16 FNTYPE _8164_set_move_para(I16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec,I16 C_Type,I16 M_Type,F64 SVacc,F64 SVdec);
I16 FNTYPE _8164_fast_tr_move(I16 AxisNo, F64 Dist);
//I16 FNTYPE _8164_tri_tr_move(I32 Dist);
//I16 FNTYPE _8164_tri_get_xz_position(F64 *xpos, F64 *zpos);
//I16 FNTYPE _8164_tri_get_xz_cmd(I32 *xcmd, I32 *zcmd);
I16 FNTYPE _8164_set_erc_off_time(I16 AxisNo, I16 erc_off_time);
I16 FNTYPE _8164_get_latest_speed_setting(I16 AxisNo,F64 *StrVel,F64 *MaxVel);
I16 FNTYPE _8164_get_latest_t_acc_setting(I16 AxisNo,F64 *Tacc,F64 *Tdec);
I16 FNTYPE _8164_get_latest_s_acc_setting(I16 AxisNo,F64 *Tacc,F64 *Tdec);

#ifdef _PCI  // PXI-8164 Only
void FNTYPE _8164_enable_card_id();
I16 FNTYPE _8164_check_card(I16 CardNo);
U16 FNTYPE _8164_read_axis_di(I16 AxisNo);
I16 FNTYPE _8164_write_axis_do(I16 AxisNo, I16 on_off);
I16 FNTYPE _8164_get_pxi_trigger_value(I16 CardNo, U16 *value);
I16 FNTYPE _8164_set_pxi_trigger_value(I16 CardNo, U16 Value);
I16 FNTYPE _8164_enable_pxi_input(I16 CardNo, I16 STA, I16 STP, I16 CEMG);
I16 FNTYPE _8164_select_pxi_output(I16 CardNo, I16 source, I16 pxi_channel);
#endif

// PCI-8164IL Only
I16 FNTYPE _8164_il_get_position(I16 AxisNo, F64 *cmp_pos);
I16 FNTYPE _8164_il_set_position(I16 AxisNo, F64 cmp_pos);
I16 FNTYPE _8164_il_set_compare(I16 AxisNo, F64 smaller, F64 bigger);
I16 FNTYPE _8164_il_get_compare(I16 AxisNo, F64 *smaller, F64 *bigger);
I16 FNTYPE _8164_il_set_int(I16 AxisNo, I16 enable);
I16 FNTYPE _8164_il_get_status(I16 CardNo, I16 *comp_sts);
I16 FNTYPE _8164_il_get_int_status(I16 cardNo, I16 *comp_int);
I16 FNTYPE _8164_il_set_counter_mode(I16 AxisNo, I16 mode);
I16 FNTYPE _8164_il_set_interlock(I16 CardNo, I16 control);
I16 FNTYPE _8164_il_set_counter_src(I16 AxisNo, I16 src);

I16 FNTYPE _8164_async_avoid(I16 CardNo, I32 Boundary, I16 cmp_mode, I16 Enable_Mode);
I16 FNTYPE _8164_aa_set_counter_mode(I16 CardNo, I16 axis0_mode, I16 axis1_mode, I16 cnt_src);
I16 FNTYPE _8164_aa_get_boundary(I16 CardNo, F64 *boundary);
I16 FNTYPE _8164_aa_reset_error_value(I16 CardNo, F64 err_value);
I16 FNTYPE _8164_aa_get_error_value(I16 CardNo, F64 *err_value);
I16 FNTYPE _8164_aa_release_sd_latch(I16 CardNo);

I16 FNTYPE _8164_read_register(I16 AxisNo,U16 CmdNo,I32 *RegData);

// Reserved Function
I16 FNTYPE _8164_set_counter1(I16 AxisNo, I32 Pos);
I16 FNTYPE _8164_get_counter1(I16 AxisNo, I32 *Pos);
I16 FNTYPE _8164_set_counter2(I16 AxisNo, I32 Pos);
I16 FNTYPE _8164_get_counter2(I16 AxisNo, I32 *Pos);
I16 FNTYPE _8164_set_counter3(I16 AxisNo, I32 Pos);
I16 FNTYPE _8164_get_counter3(I16 AxisNo, I32 *Pos);
I16 FNTYPE _8164_set_counter4(I16 AxisNo, I32 Pos);
I16 FNTYPE _8164_get_counter4(I16 AxisNo, I32 *Pos);
I16 FNTYPE _8164_get_inter_status(I16 AxisNo, U32 *inter_sts);
I16 FNTYPE _8164_get_env(I16 AxisNo, I16 env_no, U32 *env_value_h, U32 *env_value_s );
I16 FNTYPE _8164_get_rmd(I16 AxisNo, U32 *rmd_value_h, U32 *rmd_value_s );
I16 FNTYPE _8164_get_sts(I16 AxisNo, U32 *sts);
I16 FNTYPE _8164_cpld_write(I16 CardNo, U16 Offset, U16 Data);
U16 FNTYPE _8164_cpld_read(I16 CardNo, U16 Offset);
I16 FNTYPE _8164_software_reset(I16 cardNo);
I16 FNTYPE _8164_preset_cmp_v_change(I16 AxisNo, F64 FromSpeed, F64 ToSpeed, F64 Time, F64 RampDist);
I16 FNTYPE _8164_set_compare_mode(I16 AxisNo, I16 CompNo, I16 CmpSrc, I16 CmpMethod, I16 CmpAction);
I16 FNTYPE _8164_set_compare_data(I16 AxisNo, I16 CompNo, F64 Pos);
I16 FNTYPE _8164_get_sync_latch_data(I16 CardNo, I16 EnableBit, F64 *LatchPos);
I16 FNTYPE _8164_get_rest_arc_command(I16 AxisNo, I32 *rest_command);
I16 FNTYPE _8164_get_slow_down_point(I16 AxisNo, I32 *SDP);
I16 FNTYPE _8164_application_option(I16 OptionCode);

#if defined(_MSDOS)  || defined(_MYWATCOMC)
	I16 FNTYPE _8164_get_int_type(I16 AxisNo, U16 *int_type);
	I16 FNTYPE _8164_enter_isr(I16 AxisNo);
	I16 FNTYPE _8164_leave_isr(I16 AxisNo);
	I16 FNTYPE _8164_get_event_int(I16 AxisNo, U32 *event_int);
	I16 FNTYPE _8164_get_error_int(I16 AxisNo, U32 *error_int);
	#if defined(_PCI)
	I16 FNTYPE _8164_get_irq_status(U16 cardNo, U16 *sts);
	I16 FNTYPE _8164_not_my_irq(I16 CardNo);
	#endif
	I16 FNTYPE _8164_set_auto_compare(I16 AxisNo ,I16 SelectSrc);
	I16 FNTYPE _8164_build_compare_function(I16 AxisNo, F64 Start, F64 End, F64 Interval);
	I16 FNTYPE _8164_build_compare_table(I16 AxisNo, F64 *TableArray, I32 Size);

	// ISR
	void interrupt _8164_isr0 (void);
	void interrupt _8164_isr1 (void);
	void interrupt _8164_isr2 (void);
	void interrupt _8164_isr3 (void);
	void interrupt _8164_isr4 (void);
	void interrupt _8164_isr5 (void);
	void interrupt _8164_isr6 (void);
	void interrupt _8164_isr7 (void);
	void interrupt _8164_isr8 (void);
	void interrupt _8164_isr9 (void);
	void interrupt _8164_isra (void);
	void interrupt _8164_isrb (void);
#endif

#ifdef __cplusplus
}
#endif

#endif
