Option Strict Off
Option Explicit On
Module PCI_8164
	
	Declare Function B_8164_initial Lib "8164.DLL"  Alias "_8164_initial"(ByRef existCards As Short) As Short
	Declare Function B_8164_int_control Lib "8164.DLL"  Alias "_8164_int_control"(ByVal CardNo As Short, ByVal intFlag As Short) As Short
	
	Declare Function B_8164_int_enable Lib "8164.DLL"  Alias "_8164_int_enable"(ByVal CardNo As Short, ByRef phEvent As Integer) As Short
	Declare Function B_8164_int_disable Lib "8164.DLL"  Alias "_8164_int_disable"(ByVal CardNo As Short) As Short
	Declare Function B_8164_get_int_status Lib "8164.DLL"  Alias "_8164_get_int_status"(ByVal AxisNo As Short, ByRef error_int_status As Integer, ByRef event_int_status As Integer) As Short
	Declare Function B_8164_link_interrupt Lib "8164.DLL"  Alias "_8164_link_interrupt"(ByVal CardNo As Short, ByVal lpCallBackProc As Integer) As Short
	
	Declare Function B_8164_set_int_factor Lib "8164.DLL"  Alias "_8164_set_int_factor"(ByVal AxisNo As Short, ByVal int_factor As Integer) As Short
	Declare Function B_8164_close Lib "8164.DLL"  Alias "_8164_close"() As Short
	Declare Function B_8164_get_irq_channel Lib "8164.DLL"  Alias "_8164_get_irq_channel"(ByVal CardNo As Short, ByRef irq_no As Short) As Short
	Declare Function B_8164_get_base_addr Lib "8164.DLL"  Alias "_8164_get_base_addr"(ByVal CardNo As Short, ByRef base_addr As Short) As Short
	Declare Function B_8164_get_io_status Lib "8164.DLL"  Alias "_8164_get_io_status"(ByVal AxisNo As Short, ByRef io_sts As Short) As Short
	Declare Function B_8164_motion_done Lib "8164.DLL"  Alias "_8164_motion_done"(ByVal AxisNo As Short) As Short
	Declare Function B_8164_get_position Lib "8164.DLL"  Alias "_8164_get_position"(ByVal AxisNo As Short, ByRef Pos As Double) As Short
	Declare Function B_8164_set_position Lib "8164.DLL"  Alias "_8164_set_position"(ByVal AxisNo As Short, ByVal Pos As Double) As Short
	Declare Function B_8164_get_command Lib "8164.DLL"  Alias "_8164_get_command"(ByVal AxisNo As Short, ByRef CMD As Integer) As Short
	Declare Function B_8164_set_command Lib "8164.DLL"  Alias "_8164_set_command"(ByVal AxisNo As Short, ByVal CMD As Integer) As Short
	Declare Function B_8164_get_error_counter Lib "8164.DLL"  Alias "_8164_get_error_counter"(ByVal AxisNo As Short, ByRef error_counter As Short) As Short
	Declare Function B_8164_reset_error_counter Lib "8164.DLL"  Alias "_8164_reset_error_counter"(ByVal AxisNo As Short) As Short
	Declare Function B_8164_get_target_pos Lib "8164.DLL"  Alias "_8164_get_target_pos"(ByVal AxisNo As Short, ByRef Pos As Double) As Short
	Declare Function B_8164_reset_target_pos Lib "8164.DLL"  Alias "_8164_reset_target_pos"(ByVal AxisNo As Short, ByVal Pos As Double) As Short
	Declare Function B_8164_get_current_speed Lib "8164.DLL"  Alias "_8164_get_current_speed"(ByVal AxisNo As Short, ByRef Speed As Double) As Short
	Declare Function B_8164_get_rest_command Lib "8164.DLL"  Alias "_8164_get_rest_command"(ByVal AxisNo As Short, ByRef rest_command As Integer) As Short
	Declare Function B_8164_get_latch_data Lib "8164.DLL"  Alias "_8164_get_latch_data"(ByVal AxisNo As Short, ByVal LatchNo As Short, ByRef Pos As Double) As Short
	Declare Function B_8164_check_rdp Lib "8164.DLL"  Alias "_8164_check_rdp"(ByVal AxisNo As Short, ByRef rdp_command As Integer) As Short
	Declare Function B_8164_set_servo Lib "8164.DLL"  Alias "_8164_set_servo"(ByVal AxisNo As Short, ByVal on_off As Short) As Short
	Declare Function B_8164_set_pls_outmode Lib "8164.DLL"  Alias "_8164_set_pls_outmode"(ByVal AxisNo As Short, ByVal pls_outmode As Short) As Short
	Declare Function B_8164_set_pls_iptmode Lib "8164.DLL"  Alias "_8164_set_pls_iptmode"(ByVal AxisNo As Short, ByVal pls_iptmode As Short, ByVal pls_logic As Short) As Short
	Declare Function B_8164_set_feedback_src Lib "8164.DLL"  Alias "_8164_set_feedback_src"(ByVal AxisNo As Short, ByVal Src As Short) As Short
	Declare Function B_8164_set_general_counter Lib "8164.DLL"  Alias "_8164_set_general_counter"(ByVal AxisNo As Short, ByVal CntSrc As Short, ByVal CntValue As Double) As Short
	Declare Function B_8164_get_general_counter Lib "8164.DLL"  Alias "_8164_get_general_counter"(ByVal AxisNo As Short, ByRef CntValue As Double) As Short
	Declare Function B_8164_d_output Lib "8164.DLL"  Alias "_8164_d_output"(ByVal CardNo As Short, ByVal Ch_No As Short, ByVal Value As Short) As Short
	Declare Function B_8164_get_dio_status Lib "8164.DLL"  Alias "_8164_get_dio_status"(ByVal CardNo As Short, ByRef dio_sts As Short) As Short
	
	Declare Function B_8164_set_alm Lib "8164.DLL"  Alias "_8164_set_alm"(ByVal AxisNo As Short, ByVal alm_logic As Short, ByVal alm_mode As Short) As Short
	Declare Function B_8164_set_ltc_logic Lib "8164.DLL"  Alias "_8164_set_ltc_logic"(ByVal AxisNo As Short, ByVal ltc_logic As Short) As Short
	Declare Function B_8164_set_pcs_logic Lib "8164.DLL"  Alias "_8164_set_pcs_logic"(ByVal AxisNo As Short, ByVal pcs_logic As Short) As Short
	Declare Function B_8164_set_erc Lib "8164.DLL"  Alias "_8164_set_erc"(ByVal AxisNo As Short, ByVal erc_logic As Short, ByVal erc_on_time As Short) As Short
	Declare Function B_8164_set_sd Lib "8164.DLL"  Alias "_8164_set_sd"(ByVal AxisNo As Short, ByVal enable As Short, ByVal sd_logic As Short, ByVal sd_latch As Short, ByVal sd_mode As Short) As Short
	Declare Function B_8164_set_el Lib "8164.DLL"  Alias "_8164_set_el"(ByVal AxisNo As Short, ByVal el_mode As Short) As Short
	Declare Function B_8164_set_move_ratio Lib "8164.DLL"  Alias "_8164_set_move_ratio"(ByVal AxisNo As Short, ByVal move_ratio As Double) As Short
	Declare Function B_8164_set_sd_pin Lib "8164.DLL"  Alias "_8164_set_sd_pin"(ByVal AxisNo As Short, ByVal TypeA As Short) As Short
	
	Declare Function B_8164_set_home_config Lib "8164.DLL"  Alias "_8164_set_home_config"(ByVal AxisNo As Short, ByVal home_mode As Short, ByVal org_logic As Short, ByVal ez_logic As Short, ByVal ez_count As Short, ByVal erc_out As Short) As Short
	Declare Function B_8164_home_move Lib "8164.DLL"  Alias "_8164_home_move"(ByVal AxisNo As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Short
	
	Declare Function B_8164_pulser_vmove Lib "8164.DLL"  Alias "_8164_pulser_vmove"(ByVal AxisNo As Short, ByVal SpeedLimit As Double) As Short
	Declare Function B_8164_pulser_pmove Lib "8164.DLL"  Alias "_8164_pulser_pmove"(ByVal AxisNo As Short, ByVal Dist As Double, ByVal SpeedLimit As Double) As Short
	Declare Function B_8164_pulser_home_move Lib "8164.DLL"  Alias "_8164_pulser_home_move"(ByVal AxisNo As Short, ByVal HomeType As Short, ByVal SpeedLimit As Double) As Short
	Declare Function B_8164_set_pulser_iptmode Lib "8164.DLL"  Alias "_8164_set_pulser_iptmode"(ByVal AxisNo As Short, ByVal InputMode As Short, ByVal Inverse As Short) As Short
	Declare Function B_8164_backlash_comp Lib "8164.DLL"  Alias "_8164_backlash_comp"(ByVal AxisNo As Short, ByVal BCompPulse As Short, ByVal ForwardTime As Short) As Short
	Declare Function B_8164_suppress_vibration Lib "8164.DLL"  Alias "_8164_suppress_vibration"(ByVal AxisNo As Short, ByVal ReserveTime As Short, ByVal ForwardTime As Short) As Short
	
	Declare Function B_8164_tv_move Lib "8164.DLL"  Alias "_8164_tv_move"(ByVal AxisNo As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Short
	Declare Function B_8164_sv_move Lib "8164.DLL"  Alias "_8164_sv_move"(ByVal AxisNo As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal SVacc As Double) As Short
	Declare Function B_8164_emg_stop Lib "8164.DLL"  Alias "_8164_emg_stop"(ByVal AxisNo As Short) As Short
    Declare Function B_8164_sd_stop Lib "8164.DLL" Alias "_8164_sd_stop" (ByVal AxisNo As Short, ByVal Tdec As Double) As Short
    Declare Function B_8164_sd_stop_ex Lib "8164.DLL" Alias "_8164_sd_stop_ex" (ByVal AxisNo As Short, ByVal Tdec As Double) As Short
	Declare Function B_8164_v_change Lib "8164.DLL"  Alias "_8164_v_change"(ByVal AxisNo As Short, ByVal NewVel As Double, ByVal TimeSecond As Double) As Short
	Declare Function B_8164_cmp_v_change Lib "8164.DLL"  Alias "_8164_cmp_v_change"(ByVal AxisNo As Short, ByVal Res_Dist As Double, ByVal OldVel As Double, ByVal NewVel As Double, ByVal Time As Double) As Short
	Declare Function B_8164_p_change Lib "8164.DLL"  Alias "_8164_p_change"(ByVal AxisNo As Short, ByVal NewPos As Double) As Short
	Declare Function B_8164_fix_speed_range Lib "8164.DLL"  Alias "_8164_fix_speed_range"(ByVal AxisNo As Short, ByVal MaxVel As Double) As Short
	Declare Function B_8164_unfix_speed_range Lib "8164.DLL"  Alias "_8164_unfix_speed_range"(ByVal AxisNo As Short) As Short
	Declare Function B_8164_set_continuous_move Lib "8164.DLL"  Alias "_8164_set_continuous_move"(ByVal AxisNo As Short, ByVal conti_logic As Short) As Short
	
	Declare Function B_8164_set_soft_limit Lib "8164.DLL"  Alias "_8164_set_soft_limit"(ByVal AxisNo As Short, ByVal PLimit As Integer, ByVal NLimit As Integer) As Short
	Declare Function B_8164_disable_soft_limit Lib "8164.DLL"  Alias "_8164_disable_soft_limit"(ByVal AxisNo As Short) As Short
	Declare Function B_8164_enable_soft_limit Lib "8164.DLL"  Alias "_8164_enable_soft_limit"(ByVal AxisNo As Short, ByVal Action As Short) As Short
	
	Declare Function B_8164_set_error_counter_check Lib "8164.DLL"  Alias "_8164_set_error_counter_check"(ByVal AxisNo As Short, ByVal Tolerance As Short, ByVal on_off As Short) As Short
	Declare Function B_8164_set_general_comparator Lib "8164.DLL"  Alias "_8164_set_general_comparator"(ByVal AxisNo As Short, ByVal CmpSrc As Short, ByVal CmpMethod As Short, ByVal CmpAction As Short, ByVal Data As Double) As Short
	Declare Function B_8164_set_trigger_comparator Lib "8164.DLL"  Alias "_8164_set_trigger_comparator"(ByVal AxisNo As Short, ByVal CmpSrc As Short, ByVal CmpMethod As Short, ByVal Data As Double) As Short
	Declare Function B_8164_set_trigger_type Lib "8164.DLL"  Alias "_8164_set_trigger_type"(ByVal AxisNo As Short, ByVal TriggerType As Short) As Short
	
	Declare Function B_8164_check_compare_data Lib "8164.DLL"  Alias "_8164_check_compare_data"(ByVal AxisNo As Short, ByVal CompType As Short, ByRef Pos As Double) As Short
	
	Declare Function B_8164_start_tr_move Lib "8164.DLL"  Alias "_8164_start_tr_move"(ByVal AxisNo As Short, ByVal Dist As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_ta_move Lib "8164.DLL"  Alias "_8164_start_ta_move"(ByVal AxisNo As Short, ByVal Pos As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_sr_move Lib "8164.DLL"  Alias "_8164_start_sr_move"(ByVal AxisNo As Short, ByVal Dist As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	Declare Function B_8164_start_sa_move Lib "8164.DLL"  Alias "_8164_start_sa_move"(ByVal AxisNo As Short, ByVal Pos As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	
	Declare Function B_8164_start_tr_move_xy Lib "8164.DLL"  Alias "_8164_start_tr_move_xy"(ByVal CardNo As Short, ByVal Dist As Double, ByVal Dist As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_ta_move_xy Lib "8164.DLL"  Alias "_8164_start_ta_move_xy"(ByVal CardNo As Short, ByVal Pos As Double, ByVal Pos As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_sr_move_xy Lib "8164.DLL"  Alias "_8164_start_sr_move_xy"(ByVal CardNo As Short, ByVal Dist As Double, ByVal Dist As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	Declare Function B_8164_start_sa_move_xy Lib "8164.DLL"  Alias "_8164_start_sa_move_xy"(ByVal CardNo As Short, ByVal Pos As Double, ByVal Pos As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	
	Declare Function B_8164_start_tr_move_zu Lib "8164.DLL"  Alias "_8164_start_tr_move_zu"(ByVal CardNo As Short, ByVal Dist As Double, ByVal Dist As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_ta_move_zu Lib "8164.DLL"  Alias "_8164_start_ta_move_zu"(ByVal CardNo As Short, ByVal Pos As Double, ByVal Pos As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_sr_move_zu Lib "8164.DLL"  Alias "_8164_start_sr_move_zu"(ByVal CardNo As Short, ByVal Dist As Double, ByVal Dist As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	Declare Function B_8164_start_sa_move_zu Lib "8164.DLL"  Alias "_8164_start_sa_move_zu"(ByVal CardNo As Short, ByVal Pos As Double, ByVal Pos As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	
    Declare Function B_8164_start_a_arc_xy Lib "8164.DLL" Alias "_8164_start_a_arc_xy" (ByVal CardNo As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal MaxVel As Double) As Short
    Declare Function B_8164_start_r_arc_xy Lib "8164.DLL" Alias "_8164_start_r_arc_xy" (ByVal CardNo As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal MaxVel As Double) As Short
    Declare Function B_8164_start_a_arc_zu Lib "8164.DLL" Alias "_8164_start_a_arc_zu" (ByVal CardNo As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal MaxVel As Double) As Short
    Declare Function B_8164_start_r_arc_zu Lib "8164.DLL" Alias "_8164_start_r_arc_zu" (ByVal CardNo As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal MaxVel As Double) As Short
	
    Declare Function B_8164_start_tr_line2 Lib "8164.DLL" Alias "_8164_start_tr_line2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal DistX As Double, ByVal DistY As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
    Declare Function B_8164_start_ta_line2 Lib "8164.DLL" Alias "_8164_start_ta_line2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal PosX As Double, ByVal PosY As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
    Declare Function B_8164_start_sr_line2 Lib "8164.DLL" Alias "_8164_start_sr_line2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal DistX As Double, ByVal DistY As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
    Declare Function B_8164_start_sa_line2 Lib "8164.DLL" Alias "_8164_start_sa_line2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal PosX As Double, ByVal PosY As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	
    Declare Function B_8164_start_a_arc2 Lib "8164.DLL" Alias "_8164_start_a_arc2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal MaxVel As Double) As Short
    Declare Function B_8164_start_r_arc2 Lib "8164.DLL" Alias "_8164_start_r_arc2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal MaxVel As Double) As Short
	
    Declare Function B_8164_start_tr_line3 Lib "8164.DLL" Alias "_8164_start_tr_line3" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal DistX As Double, ByVal DistY As Double, ByVal DistZ As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
    Declare Function B_8164_start_ta_line3 Lib "8164.DLL" Alias "_8164_start_ta_line3" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal PosX As Double, ByVal PosY As Double, ByVal PosZ As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
    Declare Function B_8164_start_sr_line3 Lib "8164.DLL" Alias "_8164_start_sr_line3" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal DistX As Double, ByVal DistY As Double, ByVal DistZ As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
    Declare Function B_8164_start_sa_line3 Lib "8164.DLL" Alias "_8164_start_sa_line3" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal PosX As Double, ByVal PosY As Double, ByVal PosZ As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	
	Declare Function B_8164_start_tr_line4 Lib "8164.DLL"  Alias "_8164_start_tr_line4"(ByVal CardNo As Short, ByVal DistX As Double, ByVal DistY As Double, ByVal DistZ As Double, ByVal DistU As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_ta_line4 Lib "8164.DLL"  Alias "_8164_start_ta_line4"(ByVal CardNo As Short, ByVal PosX As Double, ByVal PosY As Double, ByVal PosZ As Double, ByVal PosU As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_sr_line4 Lib "8164.DLL"  Alias "_8164_start_sr_line4"(ByVal CardNo As Short, ByVal DistX As Double, ByVal DistY As Double, ByVal DistZ As Double, ByVal DistU As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	Declare Function B_8164_start_sa_line4 Lib "8164.DLL"  Alias "_8164_start_sa_line4"(ByVal CardNo As Short, ByVal PosX As Double, ByVal PosY As Double, ByVal PosZ As Double, ByVal PosU As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	
    Declare Function B_8164_set_tr_move_all Lib "8164.DLL" Alias "_8164_set_tr_move_all" (ByVal TotalAxes As Short, ByVal AxisArray() As Short, ByVal DistA() As Double, ByVal StrVelA() As Double, ByVal MaxVelA() As Double, ByVal TaccA() As Double, ByVal TdecA() As Double) As Short
	Declare Function B_8164_start_move_all Lib "8164.DLL"  Alias "_8164_start_move_all"(ByVal FirstAxisNo As Short) As Short
	Declare Function B_8164_stop_move_all Lib "8164.DLL"  Alias "_8164_stop_move_all"(ByVal FirstAxisNo As Short) As Short
	
	Declare Function B_8164_config_from_file Lib "8164.DLL"  Alias "_8164_config_from_file"(ByVal file_name As String) As Short
	
	Declare Function B_8164_set_fa_speed Lib "8164.DLL"  Alias "_8164_set_fa_speed"(ByVal AxisNo As Short, ByVal FA_Speed As Double) As Short
	Declare Function B_8164_check_compare_status Lib "8164.DLL"  Alias "_8164_check_compare_status"(ByVal AxisNo As Short, ByRef cmp_sts As Short) As Short
	Declare Function B_8164_check_continuous_buffer Lib "8164.DLL"  Alias "_8164_check_continuous_buffer"(ByVal AxisNo As Short) As Short
	
	Declare Function B_8164_set_auto_compare Lib "8164.DLL"  Alias "_8164_set_auto_compare"(ByVal AxisNo As Short, ByVal SelectSrc As Short) As Short
	Declare Function B_8164_build_compare_function Lib "8164.DLL"  Alias "_8164_build_compare_function"(ByVal AxisNo As Short, ByVal StartP As Double, ByVal EndP As Double, ByVal Interval As Double, ByVal Device As Short) As Short
    Declare Function B_8164_build_compare_table Lib "8164.DLL" Alias "_8164_build_compare_table" (ByVal AxisNo As Short, ByVal TableArray() As Double, ByVal SizeA As Short, ByVal Device As Short) As Short
	
    Declare Function B_8164_set_sa_move_all Lib "8164.DLL" Alias "_8164_set_sa_move_all" (ByVal TotalAx As Short, ByVal AxisArray() As Short, ByVal PosA() As Double, ByVal StrVelA() As Double, ByVal MaxVelA() As Double, ByVal TaccA() As Double, ByVal TdecA() As Double, ByVal SVaccA() As Double, ByVal SVdecA() As Double) As Short
    Declare Function B_8164_set_ta_move_all Lib "8164.DLL" Alias "_8164_set_ta_move_all" (ByVal TotalAx As Short, ByVal AxisArray() As Short, ByVal PosA() As Double, ByVal StrVelA() As Double, ByVal MaxVelA() As Double, ByVal TaccA() As Double, ByVal TdecA() As Double) As Short
    Declare Function B_8164_set_sr_move_all Lib "8164.DLL" Alias "_8164_set_sr_move_all" (ByVal TotalAx As Short, ByVal AxisArray() As Short, ByVal DistA() As Double, ByVal StrVelA() As Double, ByVal MaxVelA() As Double, ByVal TaccA() As Double, ByVal TdecA() As Double, ByVal SVaccA() As Double, ByVal SVdecA() As Double) As Short
	Declare Function B_8164_set_latch_source Lib "8164.DLL"  Alias "_8164_set_latch_source"(ByVal AxisNo As Short, ByVal ltc_src As Short) As Short	
	Declare Function B_8164_set_inp Lib "8164.DLL"  Alias "_8164_set_inp"(ByVal AxisNo As Short, ByVal inp_enable As Short, ByVal inp_logic As Short) As Short
	Declare Function B_8164_set_idle_pulse Lib "8164.DLL"  Alias "_8164_set_idle_pulse"(ByVal AxisNo As Short, ByVal idl_pulse As Short) As Short
	Declare Function B_8164_delay_time Lib "8164.DLL"  Alias "_8164_delay_time"(ByVal AxisNo As Short, ByVal miniSecond As Double) As Short
	Declare Function B_8164_set_pulser_ratio Lib "8164.DLL"  Alias "_8164_set_pulser_ratio"(ByVal AxisNo As Short, ByVal PDV As Short, ByVal PMG As Short) As Short
    Declare Function B_8164_pulser_r_line2 Lib "8164.DLL" Alias "_8164_pulser_r_line2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal DistX As Double, ByVal DistY As Double, ByVal SpeedLimit As Double) As Short
    Declare Function B_8164_pulser_r_arc2 Lib "8164.DLL" Alias "_8164_pulser_r_arc2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal MaxVel As Double) As Short
    Declare Function B_8164_pulser_a_line2 Lib "8164.DLL" Alias "_8164_pulser_a_line2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal PosX As Short, ByVal PosY As Short, ByVal SpeedLimit As Short) As Short
    Declare Function B_8164_pulser_a_arc2 Lib "8164.DLL" Alias "_8164_pulser_a_arc2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal MaxVel As Double) As Double
	
	Declare Function B_8164_escape_home Lib "8164.DLL"  Alias "_8164_escape_home"(ByVal AxisNo As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Short
	Declare Function B_8164_home_search Lib "8164.DLL"  Alias "_8164_home_search"(ByVal AxisNo As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal ORGOffset As Double) As Short
	Declare Function B_8164_set_line_move_mode Lib "8164.DLL"  Alias "_8164_set_line_move_mode"(ByVal AxisNo As Short, ByVal mode As Short) As Short
	
	Declare Function B_8164_verify_speed Lib "8164.DLL"  Alias "_8164_verify_speed"(ByVal StrVel As Double, ByVal MaxVel As Double, ByRef minAccT As Double, ByRef maxAccT As Double, ByVal MaxSpeed As Double) As Double
	
    Declare Function B_8164_start_tr_arc_xyu Lib "8164.DLL" Alias "_8164_start_tr_arc_xyu" (ByVal CardNo As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Short
    Declare Function B_8164_start_ta_arc_xyu Lib "8164.DLL" Alias "_8164_start_ta_arc_xyu" (ByVal CardNo As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Short
	Declare Function B_8164_start_sr_arc_xyu Lib "8164.DLL"  Alias "_8164_start_sr_arc_xyu"(ByVal CardNo As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Short
	Declare Function B_8164_start_sa_arc_xyu Lib "8164.DLL"  Alias "_8164_start_sa_arc_xyu"(ByVal CardNo As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal SVacc As Double) As Short
	Declare Function B_8164_start_tr_arc_yzu Lib "8164.DLL"  Alias "_8164_start_tr_arc_yzu"(ByVal CardNo As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Short
	Declare Function B_8164_start_ta_arc_yzu Lib "8164.DLL"  Alias "_8164_start_ta_arc_yzu"(ByVal CardNo As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Short
	Declare Function B_8164_start_sr_arc_yzu Lib "8164.DLL"  Alias "_8164_start_sr_arc_yzu"(ByVal CardNo As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Short
	Declare Function B_8164_start_sa_arc_yzu Lib "8164.DLL"  Alias "_8164_start_sa_arc_yzu"(ByVal CardNo As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal SVacc As Double) As Short
	
	Declare Function B_8164_start_tr_arc2 Lib "8164.DLL" Alias "_8164_start_tr_arc2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_ta_arc2 Lib "8164.DLL" Alias "_8164_start_ta_arc2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_sr_arc2 Lib "8164.DLL" Alias "_8164_start_sr_arc2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	Declare Function B_8164_start_sa_arc2 Lib "8164.DLL" Alias "_8164_start_sa_arc2" (ByVal CardNo As Short, ByVal AxisArray() As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	
	Declare Function B_8164_start_tr_arc_xy Lib "8164.DLL"  Alias "_8164_start_tr_arc_xy"(ByVal CardNo As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_ta_arc_xy Lib "8164.DLL"  Alias "_8164_start_ta_arc_xy"(ByVal CardNo As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_tr_arc_zu Lib "8164.DLL"  Alias "_8164_start_tr_arc_zu"(ByVal CardNo As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	Declare Function B_8164_start_ta_arc_zu Lib "8164.DLL"  Alias "_8164_start_ta_arc_zu"(ByVal CardNo As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Short
	
	Declare Function B_8164_start_sr_arc_xy Lib "8164.DLL"  Alias "_8164_start_sr_arc_xy"(ByVal CardNo As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	Declare Function B_8164_start_sa_arc_xy Lib "8164.DLL"  Alias "_8164_start_sa_arc_xy"(ByVal CardNo As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	Declare Function B_8164_start_sr_arc_zu Lib "8164.DLL"  Alias "_8164_start_sr_arc_zu"(ByVal CardNo As Short, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	Declare Function B_8164_start_sa_arc_zu Lib "8164.DLL"  Alias "_8164_start_sa_arc_zu"(ByVal CardNo As Short, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR_Renamed As Short, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Short
	
	Declare Function B_8164_set_sync_option Lib "8164.DLL"  Alias "_8164_set_sync_option"(ByVal AxisNo As Short, ByVal sync_stop_on As Short, ByVal cstop_output_on As Short, ByVal sync_option1 As Short, ByVal sync_option2 As Short) As Short
	Declare Function B_8164_mask_axis_stop_int Lib "8164.DLL"  Alias "_8164_mask_axis_stop_int"(ByVal AxisNo As Short, ByVal int_disable As Short) As Short
	Declare Function B_8164_set_axis_option Lib "8164.DLL"  Alias "_8164_set_axis_option"(ByVal AxisNo As Short, ByVal option1 As Short) As Short
	Declare Function B_8164_set_axis_stop_int Lib "8164.DLL"  Alias "_8164_set_axis_stop_int"(ByVal AxisNo As Short, ByVal axis_stop_int As Short) As Short
	Declare Function B_8164_version_info Lib "8164.DLL"  Alias "_8164_version_info"(ByVal CardNo As Short, ByRef HardwareInfo As Short, ByRef SoftwareInfo As Short, ByRef DriverInfo As Short) As Short
	Declare Function B_8164_set_sync_stop_mode Lib "8164.DLL"  Alias "_8164_set_sync_stop_mode"(ByVal AxisNo As Short, ByVal stop_mode As Short) As Short
	
	Declare Function B_8164_set_sync_signal_source Lib "8164.DLL"  Alias "_8164_set_sync_signal_source"(ByVal AxisNo As Short, ByVal sync_axis As Short) As Short
	Declare Function B_8164_set_sync_signal_mode Lib "8164.DLL"  Alias "_8164_set_sync_signal_mode"(ByVal AxisNo As Short, ByVal mode As Short) As Short
    Declare Function B_8164_start_ta_pickplace Lib "8164.DLL" Alias "_8164_start_ta_pickplace" (ByRef AxisPair2 As Short, ByRef Pos3 As Double, ByRef SVel3 As Double, ByRef MVel3 As Double, ByRef AccT3 As Double, ByRef StartPoint2 As Double) As Short

	Declare Function B_8164_set_auto_rdp Lib "8164.DLL"  Alias "_8164_set_auto_rdp"(ByVal CardNo As Short, ByVal on_off As Short) As Short
	
	Declare Function B_8164_read_axis_di Lib "8164.DLL"  Alias "_8164_read_axis_di"(ByVal AxisNo As Short) As Short
	Declare Function B_8164_write_axis_do Lib "8164.DLL"  Alias "_8164_write_axis_do"(ByVal AxisNo As Short, ByVal on_off As Short) As Short
	
	Declare Function B_8164_enable_card_id Lib "8164.DLL"  Alias "_8164_enable_card_id"() As Short
	Declare Function B_8164_check_card Lib "8164.DLL"  Alias "_8164_check_card"(ByVal CardNo As Short) As Short
	Declare Function B_8164_get_pxi_trigger_value Lib "8164.DLL"  Alias "_8164_get_pxi_trigger_value"(ByVal CardNo As Short, ByRef Value As Short) As Short
	Declare Function B_8164_set_pxi_trigger_value Lib "8164.DLL"  Alias "_8164_set_pxi_trigger_value"(ByVal CardNo As Short, ByVal Value As Short) As Short
	Declare Function B_8164_enable_pxi_input Lib "8164.DLL"  Alias "_8164_enable_pxi_input"(ByVal CardNo As Short, ByVal STA As Short, ByVal STP As Short, ByVal CEMG As Short) As Short
	Declare Function B_8164_select_pxi_output Lib "8164.DLL"  Alias "_8164_select_pxi_output"(ByVal CardNo As Short, ByVal source As Short, ByVal pxi_channel As Short) As Short
End Module