Attribute VB_Name = "PCI_8164"
Option Explicit

Declare Function B_8164_initial Lib "8164.dll" Alias "_8164_initial" (existCards As Integer) As Integer
Declare Function B_8164_int_control Lib "8164.dll" Alias "_8164_int_control" (ByVal CardNo As Integer, ByVal intFlag As Integer) As Integer

Declare Function B_8164_int_enable Lib "8164.dll" Alias "_8164_int_enable" (ByVal CardNo As Integer, phEvent As Long) As Integer
Declare Function B_8164_int_disable Lib "8164.dll" Alias "_8164_int_disable" (ByVal CardNo As Integer) As Integer
Declare Function B_8164_get_int_status Lib "8164.dll" Alias "_8164_get_int_status" (ByVal AxisNo As Integer, error_int_status As Long, event_int_status As Long) As Integer
Declare Function B_8164_link_interrupt Lib "8164.dll" Alias "_8164_link_interrupt" (ByVal CardNo As Integer, ByVal lpCallBackProc As Long) As Integer

Declare Function B_8164_set_int_factor Lib "8164.dll" Alias "_8164_set_int_factor" (ByVal AxisNo As Integer, ByVal int_factor As Long) As Integer
Declare Function B_8164_close Lib "8164.dll" Alias "_8164_close" () As Integer
Declare Function B_8164_get_irq_channel Lib "8164.dll" Alias "_8164_get_irq_channel" (ByVal CardNo As Integer, irq_no As Integer) As Integer
Declare Function B_8164_get_base_addr Lib "8164.dll" Alias "_8164_get_base_addr" (ByVal CardNo As Integer, base_addr As Integer) As Integer
Declare Function B_8164_get_io_status Lib "8164.dll" Alias "_8164_get_io_status" (ByVal AxisNo As Integer, io_sts As Integer) As Integer
Declare Function B_8164_motion_done Lib "8164.dll" Alias "_8164_motion_done" (ByVal AxisNo As Integer) As Integer
Declare Function B_8164_get_position Lib "8164.dll" Alias "_8164_get_position" (ByVal AxisNo As Integer, Pos As Double) As Integer
Declare Function B_8164_set_position Lib "8164.dll" Alias "_8164_set_position" (ByVal AxisNo As Integer, ByVal Pos As Double) As Integer
Declare Function B_8164_get_command Lib "8164.dll" Alias "_8164_get_command" (ByVal AxisNo As Integer, CMD As Long) As Integer
Declare Function B_8164_set_command Lib "8164.dll" Alias "_8164_set_command" (ByVal AxisNo As Integer, ByVal CMD As Long) As Integer
Declare Function B_8164_get_error_counter Lib "8164.dll" Alias "_8164_get_error_counter" (ByVal AxisNo As Integer, error_counter As Integer) As Integer
Declare Function B_8164_reset_error_counter Lib "8164.dll" Alias "_8164_reset_error_counter" (ByVal AxisNo As Integer) As Integer
Declare Function B_8164_get_target_pos Lib "8164.dll" Alias "_8164_get_target_pos" (ByVal AxisNo As Integer, Pos As Double) As Integer
Declare Function B_8164_reset_target_pos Lib "8164.dll" Alias "_8164_reset_target_pos" (ByVal AxisNo As Integer, ByVal Pos As Double) As Integer
Declare Function B_8164_get_current_speed Lib "8164.dll" Alias "_8164_get_current_speed" (ByVal AxisNo As Integer, Speed As Double) As Integer
Declare Function B_8164_get_rest_command Lib "8164.dll" Alias "_8164_get_rest_command" (ByVal AxisNo As Integer, rest_command As Long) As Integer
Declare Function B_8164_get_latch_data Lib "8164.dll" Alias "_8164_get_latch_data" (ByVal AxisNo As Integer, ByVal LatchNo As Integer, Pos As Double) As Integer
Declare Function B_8164_check_rdp Lib "8164.dll" Alias "_8164_check_rdp" (ByVal AxisNo As Integer, rdp_command As Long) As Integer
Declare Function B_8164_set_servo Lib "8164.dll" Alias "_8164_set_servo" (ByVal AxisNo As Integer, ByVal on_off As Integer) As Integer
Declare Function B_8164_set_pls_outmode Lib "8164.dll" Alias "_8164_set_pls_outmode" (ByVal AxisNo As Integer, ByVal pls_outmode As Integer) As Integer
Declare Function B_8164_set_pls_iptmode Lib "8164.dll" Alias "_8164_set_pls_iptmode" (ByVal AxisNo As Integer, ByVal pls_iptmode As Integer, ByVal pls_logic As Integer) As Integer
Declare Function B_8164_set_feedback_src Lib "8164.dll" Alias "_8164_set_feedback_src" (ByVal AxisNo As Integer, ByVal src As Integer) As Integer
Declare Function B_8164_set_general_counter Lib "8164.dll" Alias "_8164_set_general_counter" (ByVal AxisNo As Integer, ByVal CntSrc As Integer, ByVal CntValue As Double) As Integer
Declare Function B_8164_get_general_counter Lib "8164.dll" Alias "_8164_get_general_counter" (ByVal AxisNo As Integer, CntValue As Double) As Integer
Declare Function B_8164_d_output Lib "8164.dll" Alias "_8164_d_output" (ByVal CardNo As Integer, ByVal Ch_No As Integer, ByVal Value As Integer) As Integer
Declare Function B_8164_get_dio_status Lib "8164.dll" Alias "_8164_get_dio_status" (ByVal CardNo As Integer, dio_sts As Integer) As Integer

Declare Function B_8164_set_alm Lib "8164.dll" Alias "_8164_set_alm" (ByVal AxisNo As Integer, ByVal alm_logic As Integer, ByVal alm_mode As Integer) As Integer
Declare Function B_8164_set_ltc_logic Lib "8164.dll" Alias "_8164_set_ltc_logic" (ByVal AxisNo As Integer, ByVal ltc_logic As Integer) As Integer
Declare Function B_8164_set_pcs_logic Lib "8164.dll" Alias "_8164_set_pcs_logic" (ByVal AxisNo As Integer, ByVal pcs_logic As Integer) As Integer
Declare Function B_8164_set_erc Lib "8164.dll" Alias "_8164_set_erc" (ByVal AxisNo As Integer, ByVal erc_logic As Integer, ByVal erc_on_time As Integer) As Integer
Declare Function B_8164_set_sd Lib "8164.dll" Alias "_8164_set_sd" (ByVal AxisNo As Integer, ByVal Enable As Integer, ByVal sd_logic As Integer, ByVal sd_latch As Integer, ByVal sd_mode As Integer) As Integer
Declare Function B_8164_set_el Lib "8164.dll" Alias "_8164_set_el" (ByVal AxisNo As Integer, ByVal el_mode As Integer) As Integer
Declare Function B_8164_set_move_ratio Lib "8164.dll" Alias "_8164_set_move_ratio" (ByVal AxisNo As Integer, ByVal move_ratio As Double) As Integer
Declare Function B_8164_set_sd_pin Lib "8164.dll" Alias "_8164_set_sd_pin" (ByVal AxisNo As Integer, ByVal TypeA As Integer) As Integer

Declare Function B_8164_set_home_config Lib "8164.dll" Alias "_8164_set_home_config" (ByVal AxisNo As Integer, ByVal home_mode As Integer, ByVal org_logic As Integer, ByVal ez_logic As Integer, ByVal ez_count As Integer, ByVal erc_out As Integer) As Integer
Declare Function B_8164_home_move Lib "8164.dll" Alias "_8164_home_move" (ByVal AxisNo As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Integer

Declare Function B_8164_pulser_vmove Lib "8164.dll" Alias "_8164_pulser_vmove" (ByVal AxisNo As Integer, ByVal SpeedLimit As Double) As Integer
Declare Function B_8164_pulser_pmove Lib "8164.dll" Alias "_8164_pulser_pmove" (ByVal AxisNo As Integer, ByVal Dist As Double, ByVal SpeedLimit As Double) As Integer
Declare Function B_8164_pulser_home_move Lib "8164.dll" Alias "_8164_pulser_home_move" (ByVal AxisNo As Integer, ByVal HomeType As Integer, ByVal SpeedLimit As Double) As Integer
Declare Function B_8164_set_pulser_iptmode Lib "8164.dll" Alias "_8164_set_pulser_iptmode" (ByVal AxisNo As Integer, ByVal InputMode As Integer, ByVal Inverse As Integer) As Integer
Declare Function B_8164_backlash_comp Lib "8164.dll" Alias "_8164_backlash_comp" (ByVal AxisNo As Integer, ByVal BCompPulse As Integer, ByVal ForwardTime As Integer) As Integer
Declare Function B_8164_suppress_vibration Lib "8164.dll" Alias "_8164_suppress_vibration" (ByVal AxisNo As Integer, ByVal ReserveTime As Integer, ByVal ForwardTime As Integer) As Integer

Declare Function B_8164_set_pitch_compensate Lib "8164.dll" Alias "_8164_set_pitch_compensate" (ByVal AxisNo As Integer, ByVal TableSize As Integer, PTableArray As Long, NTableArray As Long, ByVal TableInterval As Long) As Integer
Declare Function B_8164_enable_pitch_compensate Lib "8164.dll" Alias "_8164_enable_pitch_compensate" (ByVal AxisNo As Integer, ByVal Enable As Integer) As Integer
Declare Function B_8164_calculate_amove_pitch_compensate Lib "8164.dll" Alias "_8164_calculate_amove_pitch_compensate" (ByVal AxisNo As Integer, ByVal Pos As Double, Result As Double) As Integer
Declare Function B_8164_calculate_rmove_pitch_compensate Lib "8164.dll" Alias "_8164_calculate_rmove_pitch_compensate" (ByVal AxisNo As Integer, ByVal Dist As Double, Result As Double) As Integer
Declare Function B_8164_get_pitch_table_target_pos Lib "8164.dll" Alias "_8164_get_pitch_table_target_pos" (ByVal AxisNo As Integer, TargetPos As Double) As Integer

Declare Function B_8164_tv_move Lib "8164.dll" Alias "_8164_tv_move" (ByVal AxisNo As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Integer
Declare Function B_8164_sv_move Lib "8164.dll" Alias "_8164_sv_move" (ByVal AxisNo As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal SVacc As Double) As Integer
Declare Function B_8164_emg_stop Lib "8164.dll" Alias "_8164_emg_stop" (ByVal AxisNo As Integer) As Integer
Declare Function B_8164_sd_stop Lib "8164.dll" Alias "_8164_sd_stop" (ByVal AxisNo As Integer, ByVal Tdec As Double) As Integer
Declare Function B_8164_sd_stop_ex Lib "8164.dll" Alias "_8164_sd_stop_ex" (ByVal AxisNo As Integer, ByVal Tdec As Double) As Integer
Declare Function B_8164_v_change Lib "8164.dll" Alias "_8164_v_change" (ByVal AxisNo As Integer, ByVal NewVel As Double, ByVal TimeSecond As Double) As Integer
Declare Function B_8164_cmp_v_change Lib "8164.dll" Alias "_8164_cmp_v_change" (ByVal AxisNo As Integer, ByVal Res_Dist As Double, ByVal OldVel As Double, ByVal NewVel As Double, ByVal Time As Double) As Integer
Declare Function B_8164_p_change Lib "8164.dll" Alias "_8164_p_change" (ByVal AxisNo As Integer, ByVal NewPos As Double) As Integer
Declare Function B_8164_fix_speed_range Lib "8164.dll" Alias "_8164_fix_speed_range" (ByVal AxisNo As Integer, ByVal MaxVel As Double) As Integer
Declare Function B_8164_unfix_speed_range Lib "8164.dll" Alias "_8164_unfix_speed_range" (ByVal AxisNo As Integer) As Integer
Declare Function B_8164_set_continuous_move Lib "8164.dll" Alias "_8164_set_continuous_move" (ByVal AxisNo As Integer, ByVal conti_logic As Integer) As Integer

Declare Function B_8164_set_soft_limit Lib "8164.dll" Alias "_8164_set_soft_limit" (ByVal AxisNo As Integer, ByVal PLimit As Long, ByVal NLimit As Long) As Integer
Declare Function B_8164_disable_soft_limit Lib "8164.dll" Alias "_8164_disable_soft_limit" (ByVal AxisNo As Integer) As Integer
Declare Function B_8164_enable_soft_limit Lib "8164.dll" Alias "_8164_enable_soft_limit" (ByVal AxisNo As Integer, ByVal Action As Integer) As Integer

Declare Function B_8164_set_error_counter_check Lib "8164.dll" Alias "_8164_set_error_counter_check" (ByVal AxisNo As Integer, ByVal Tolerance As Integer, ByVal on_off As Integer) As Integer
Declare Function B_8164_set_general_comparator Lib "8164.dll" Alias "_8164_set_general_comparator" (ByVal AxisNo As Integer, ByVal CmpSrc As Integer, ByVal CmpMethod As Integer, ByVal CmpAction As Integer, ByVal Data As Double) As Integer
Declare Function B_8164_set_trigger_comparator Lib "8164.dll" Alias "_8164_set_trigger_comparator" (ByVal AxisNo As Integer, ByVal CmpSrc As Integer, ByVal CmpMethod As Integer, ByVal Data As Double) As Integer
Declare Function B_8164_set_trigger_type Lib "8164.dll" Alias "_8164_set_trigger_type" (ByVal AxisNo As Integer, ByVal TriggerType As Integer) As Integer

Declare Function B_8164_check_compare_data Lib "8164.dll" Alias "_8164_check_compare_data" (ByVal AxisNo As Integer, ByVal CompType As Integer, Pos As Double) As Integer

Declare Function B_8164_start_tr_move Lib "8164.dll" Alias "_8164_start_tr_move" (ByVal AxisNo As Integer, ByVal Dist As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_ta_move Lib "8164.dll" Alias "_8164_start_ta_move" (ByVal AxisNo As Integer, ByVal Pos As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_sr_move Lib "8164.dll" Alias "_8164_start_sr_move" (ByVal AxisNo As Integer, ByVal Dist As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer
Declare Function B_8164_start_sa_move Lib "8164.dll" Alias "_8164_start_sa_move" (ByVal AxisNo As Integer, ByVal Pos As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer

Declare Function B_8164_start_tr_move_xy Lib "8164.dll" Alias "_8164_start_tr_move_xy" (ByVal CardNo As Integer, ByVal Dist As Double, ByVal Dist As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_ta_move_xy Lib "8164.dll" Alias "_8164_start_ta_move_xy" (ByVal CardNo As Integer, ByVal Pos As Double, ByVal Pos As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_sr_move_xy Lib "8164.dll" Alias "_8164_start_sr_move_xy" (ByVal CardNo As Integer, ByVal Dist As Double, ByVal Dist As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer
Declare Function B_8164_start_sa_move_xy Lib "8164.dll" Alias "_8164_start_sa_move_xy" (ByVal CardNo As Integer, ByVal Pos As Double, ByVal Pos As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer

Declare Function B_8164_start_tr_move_zu Lib "8164.dll" Alias "_8164_start_tr_move_zu" (ByVal CardNo As Integer, ByVal Dist As Double, ByVal Dist As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_ta_move_zu Lib "8164.dll" Alias "_8164_start_ta_move_zu" (ByVal CardNo As Integer, ByVal Pos As Double, ByVal Pos As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_sr_move_zu Lib "8164.dll" Alias "_8164_start_sr_move_zu" (ByVal CardNo As Integer, ByVal Dist As Double, ByVal Dist As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer
Declare Function B_8164_start_sa_move_zu Lib "8164.dll" Alias "_8164_start_sa_move_zu" (ByVal CardNo As Integer, ByVal Pos As Double, ByVal Pos As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer

Declare Function B_8164_start_a_arc_xy Lib "8164.dll" Alias "_8164_start_a_arc_xy" (ByVal CardNo As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal MaxVel As Double) As Integer
Declare Function B_8164_start_r_arc_xy Lib "8164.dll" Alias "_8164_start_r_arc_xy" (ByVal CardNo As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal MaxVel As Double) As Integer
Declare Function B_8164_start_a_arc_zu Lib "8164.dll" Alias "_8164_start_a_arc_zu" (ByVal CardNo As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal MaxVel As Double) As Integer
Declare Function B_8164_start_r_arc_zu Lib "8164.dll" Alias "_8164_start_r_arc_zu" (ByVal CardNo As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal MaxVel As Double) As Integer

Declare Function B_8164_start_tr_line2 Lib "8164.dll" Alias "_8164_start_tr_line2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal DistX As Double, ByVal DistY As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_ta_line2 Lib "8164.dll" Alias "_8164_start_ta_line2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal PosX As Double, ByVal PosY As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_sr_line2 Lib "8164.dll" Alias "_8164_start_sr_line2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal DistX As Double, ByVal DistY As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer
Declare Function B_8164_start_sa_line2 Lib "8164.dll" Alias "_8164_start_sa_line2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal PosX As Double, ByVal PosY As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer

Declare Function B_8164_start_a_arc2 Lib "8164.dll" Alias "_8164_start_a_arc2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal MaxVel As Double) As Integer
Declare Function B_8164_start_r_arc2 Lib "8164.dll" Alias "_8164_start_r_arc2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal MaxVel As Double) As Integer

Declare Function B_8164_start_tr_line3 Lib "8164.dll" Alias "_8164_start_tr_line3" (ByVal CardNo As Integer, AxisArray As Integer, ByVal DistX As Double, ByVal DistY As Double, ByVal DistZ As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_ta_line3 Lib "8164.dll" Alias "_8164_start_ta_line3" (ByVal CardNo As Integer, AxisArray As Integer, ByVal PosX As Double, ByVal PosY As Double, ByVal PosZ As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_sr_line3 Lib "8164.dll" Alias "_8164_start_sr_line3" (ByVal CardNo As Integer, AxisArray As Integer, ByVal DistX As Double, ByVal DistY As Double, ByVal DistZ As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer
Declare Function B_8164_start_sa_line3 Lib "8164.dll" Alias "_8164_start_sa_line3" (ByVal CardNo As Integer, AxisArray As Integer, ByVal PosX As Double, ByVal PosY As Double, ByVal PosZ As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer

Declare Function B_8164_start_tr_line4 Lib "8164.dll" Alias "_8164_start_tr_line4" (ByVal CardNo As Integer, ByVal DistX As Double, ByVal DistY As Double, ByVal DistZ As Double, ByVal DistU As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_ta_line4 Lib "8164.dll" Alias "_8164_start_ta_line4" (ByVal CardNo As Integer, ByVal PosX As Double, ByVal PosY As Double, ByVal PosZ As Double, ByVal PosU As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_sr_line4 Lib "8164.dll" Alias "_8164_start_sr_line4" (ByVal CardNo As Integer, ByVal DistX As Double, ByVal DistY As Double, ByVal DistZ As Double, ByVal DistU As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer
Declare Function B_8164_start_sa_line4 Lib "8164.dll" Alias "_8164_start_sa_line4" (ByVal CardNo As Integer, ByVal PosX As Double, ByVal PosY As Double, ByVal PosZ As Double, ByVal PosU As Double, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer

Declare Function B_8164_set_tr_move_all Lib "8164.dll" Alias "_8164_set_tr_move_all" (ByVal TotalAxes As Integer, AxisArray As Integer, DistA As Double, StrVelA As Double, MaxVelA As Double, TaccA As Double, TdecA As Double) As Integer
Declare Function B_8164_start_move_all Lib "8164.dll" Alias "_8164_start_move_all" (ByVal FirstAxisNo As Integer) As Integer
Declare Function B_8164_stop_move_all Lib "8164.dll" Alias "_8164_stop_move_all" (ByVal FirstAxisNo As Integer) As Integer

Declare Function B_8164_config_from_file Lib "8164.dll" Alias "_8164_config_from_file" (ByVal file_name As String) As Integer

Declare Function B_8164_set_fa_speed Lib "8164.dll" Alias "_8164_set_fa_speed" (ByVal AxisNo As Integer, ByVal FA_Speed As Double) As Integer
Declare Function B_8164_check_compare_status Lib "8164.dll" Alias "_8164_check_compare_status" (ByVal AxisNo As Integer, cmp_sts As Integer) As Integer
Declare Function B_8164_check_continuous_buffer Lib "8164.dll" Alias "_8164_check_continuous_buffer" (ByVal AxisNo As Integer) As Integer

Declare Function B_8164_set_auto_compare Lib "8164.dll" Alias "_8164_set_auto_compare" (ByVal AxisNo As Integer, ByVal SelectSrc As Integer) As Integer
Declare Function B_8164_build_compare_function Lib "8164.dll" Alias "_8164_build_compare_function" (ByVal AxisNo As Integer, ByVal StartP As Double, ByVal EndP As Double, ByVal Interval As Double, ByVal Device As Integer) As Integer
Declare Function B_8164_build_compare_table Lib "8164.dll" Alias "_8164_build_compare_table" (ByVal AxisNo As Integer, TableArray As Double, ByVal SizeA As Integer, ByVal Device As Integer) As Integer

Declare Function B_8164_set_sa_move_all Lib "8164.dll" Alias "_8164_set_sa_move_all" (ByVal TotalAx As Integer, AxisArray As Integer, PosA As Double, StrVelA As Double, MaxVelA As Double, TaccA As Double, TdecA As Double, SVaccA As Double, SVdecA As Double) As Integer
Declare Function B_8164_set_ta_move_all Lib "8164.dll" Alias "_8164_set_ta_move_all" (ByVal TotalAx As Integer, AxisArray As Integer, PosA As Double, StrVelA As Double, MaxVelA As Double, TaccA As Double, TdecA As Double) As Integer
Declare Function B_8164_set_sr_move_all Lib "8164.dll" Alias "_8164_set_sr_move_all" (ByVal TotalAx As Integer, AxisArray As Integer, DistA As Double, StrVelA As Double, MaxVelA As Double, TaccA As Double, TdecA As Double, SVaccA As Double, SVdecA As Double) As Integer
Declare Function B_8164_set_latch_source Lib "8164.dll" Alias "_8164_set_latch_source" (ByVal AxisNo As Integer, ByVal ltc_src As Integer) As Integer
Declare Function B_8164_set_inp Lib "8164.dll" Alias "_8164_set_inp" (ByVal AxisNo As Integer, ByVal inp_enable As Integer, ByVal inp_logic As Integer) As Integer
Declare Function B_8164_set_idle_pulse Lib "8164.dll" Alias "_8164_set_idle_pulse" (ByVal AxisNo As Integer, ByVal idl_pulse As Integer) As Integer
Declare Function B_8164_delay_time Lib "8164.dll" Alias "_8164_delay_time" (ByVal AxisNo As Integer, ByVal miniSecond As Double) As Integer
Declare Function B_8164_set_pulser_ratio Lib "8164.dll" Alias "_8164_set_pulser_ratio" (ByVal AxisNo As Integer, ByVal PDV As Integer, ByVal PMG As Integer) As Integer
Declare Function B_8164_pulser_r_line2 Lib "8164.dll" Alias "_8164_pulser_r_line2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal DistX As Double, ByVal DistY As Double, ByVal SpeedLimit As Double) As Integer
Declare Function B_8164_pulser_r_arc2 Lib "8164.dll" Alias "_8164_pulser_r_arc2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal MaxVel As Double) As Integer
Declare Function B_8164_pulser_a_line2 Lib "8164.dll" Alias "_8164_pulser_a_line2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal PosX As Integer, ByVal PosY As Integer, ByVal SpeedLimit As Integer) As Integer
Declare Function B_8164_pulser_a_arc2 Lib "8164.dll" Alias "_8164_pulser_a_arc2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal MaxVel As Double) As Double

Declare Function B_8164_escape_home Lib "8164.dll" Alias "_8164_escape_home" (ByVal AxisNo As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Integer
Declare Function B_8164_home_search Lib "8164.dll" Alias "_8164_home_search" (ByVal AxisNo As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal ORGOffset As Double) As Integer
Declare Function B_8164_set_line_move_mode Lib "8164.dll" Alias "_8164_set_line_move_mode" (ByVal AxisNo As Integer, ByVal mode As Integer) As Integer

Declare Function B_8164_verify_speed Lib "8164.dll" Alias "_8164_verify_speed" (ByVal StrVel As Double, ByVal MaxVel As Double, minAccT As Double, maxAccT As Double, ByVal MaxSpeed As Double) As Double

Declare Function B_8164_start_tr_arc_xyu Lib "8164.dll" Alias "_8164_start_tr_arc_xyu" (ByVal CardNo As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Integer
Declare Function B_8164_start_ta_arc_xyu Lib "8164.dll" Alias "_8164_start_ta_arc_xyu" (ByVal CardNo As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Integer
Declare Function B_8164_start_sr_arc_xyu Lib "8164.dll" Alias "_8164_start_sr_arc_xyu" (ByVal CardNo As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Integer
Declare Function B_8164_start_sa_arc_xyu Lib "8164.dll" Alias "_8164_start_sa_arc_xyu" (ByVal CardNo As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal SVacc As Double) As Integer
Declare Function B_8164_start_tr_arc_yzu Lib "8164.dll" Alias "_8164_start_tr_arc_yzu" (ByVal CardNo As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Integer
Declare Function B_8164_start_ta_arc_yzu Lib "8164.dll" Alias "_8164_start_ta_arc_yzu" (ByVal CardNo As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Integer
Declare Function B_8164_start_sr_arc_yzu Lib "8164.dll" Alias "_8164_start_sr_arc_yzu" (ByVal CardNo As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double) As Integer
Declare Function B_8164_start_sa_arc_yzu Lib "8164.dll" Alias "_8164_start_sa_arc_yzu" (ByVal CardNo As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal SVacc As Double) As Integer

Declare Function B_8164_start_tr_arc2 Lib "8164.dll" Alias "_8164_start_tr_arc2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_ta_arc2 Lib "8164.dll" Alias "_8164_start_ta_arc2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_sr_arc2 Lib "8164.dll" Alias "_8164_start_sr_arc2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer
Declare Function B_8164_start_sa_arc2 Lib "8164.dll" Alias "_8164_start_sa_arc2" (ByVal CardNo As Integer, AxisArray As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer

Declare Function B_8164_start_tr_arc_xy Lib "8164.dll" Alias "_8164_start_tr_arc_xy" (ByVal CardNo As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_ta_arc_xy Lib "8164.dll" Alias "_8164_start_ta_arc_xy" (ByVal CardNo As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_tr_arc_zu Lib "8164.dll" Alias "_8164_start_tr_arc_zu" (ByVal CardNo As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer
Declare Function B_8164_start_ta_arc_zu Lib "8164.dll" Alias "_8164_start_ta_arc_zu" (ByVal CardNo As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double) As Integer

Declare Function B_8164_start_sr_arc_xy Lib "8164.dll" Alias "_8164_start_sr_arc_xy" (ByVal CardNo As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer
Declare Function B_8164_start_sa_arc_xy Lib "8164.dll" Alias "_8164_start_sa_arc_xy" (ByVal CardNo As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer
Declare Function B_8164_start_sr_arc_zu Lib "8164.dll" Alias "_8164_start_sr_arc_zu" (ByVal CardNo As Integer, ByVal OffsetCx As Double, ByVal OffsetCy As Double, ByVal OffsetEx As Double, ByVal OffsetEy As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer
Declare Function B_8164_start_sa_arc_zu Lib "8164.dll" Alias "_8164_start_sa_arc_zu" (ByVal CardNo As Integer, ByVal Cx As Double, ByVal Cy As Double, ByVal Ex As Double, ByVal Ey As Double, ByVal DIR As Integer, ByVal StrVel As Double, ByVal MaxVel As Double, ByVal Tacc As Double, ByVal Tdec As Double, ByVal SVacc As Double, ByVal SVdec As Double) As Integer

Declare Function B_8164_set_sync_option Lib "8164.dll" Alias "_8164_set_sync_option" (ByVal AxisNo As Integer, ByVal sync_stop_on As Integer, ByVal cstop_output_on As Integer, ByVal sync_option1 As Integer, ByVal sync_option2 As Integer) As Integer
Declare Function B_8164_mask_axis_stop_int Lib "8164.dll" Alias "_8164_mask_axis_stop_int" (ByVal AxisNo As Integer, ByVal int_disable As Integer) As Integer
Declare Function B_8164_set_axis_option Lib "8164.dll" Alias "_8164_set_axis_option" (ByVal AxisNo As Integer, ByVal option1 As Integer) As Integer
Declare Function B_8164_set_axis_stop_int Lib "8164.dll" Alias "_8164_set_axis_stop_int" (ByVal AxisNo As Integer, ByVal axis_stop_int As Integer) As Integer
Declare Function B_8164_version_info Lib "8164.dll" Alias "_8164_version_info" (ByVal CardNo As Integer, HardwareInfo As Integer, SoftwareInfo As Integer, DriverInfo As Integer) As Integer
Declare Function B_8164_set_sync_stop_mode Lib "8164.dll" Alias "_8164_set_sync_stop_mode" (ByVal AxisNo As Integer, ByVal stop_mode As Integer) As Integer

Declare Function B_8164_set_sync_signal_source Lib "8164.dll" Alias "_8164_set_sync_signal_source" (ByVal AxisNo As Integer, ByVal sync_axis As Integer) As Integer
Declare Function B_8164_set_sync_signal_mode Lib "8164.dll" Alias "_8164_set_sync_signal_mode" (ByVal AxisNo As Integer, ByVal mode As Integer) As Integer
Declare Function B_8164_start_ta_pickplace Lib "8164.dll" Alias "_8164_start_ta_pickplace" (AxisPair2 As Integer, Pos3 As Double, SVel3 As Double, MVel3 As Double, AccT3 As Double, StartPoint2 As Double) As Integer

Declare Function B_8164_set_auto_rdp Lib "8164.dll" Alias "_8164_set_auto_rdp" (ByVal CardNo As Integer, ByVal on_off As Integer) As Integer

Declare Function B_8164_read_axis_di Lib "8164.dll" Alias "_8164_read_axis_di" (ByVal AxisNo As Integer) As Integer
Declare Function B_8164_write_axis_do Lib "8164.dll" Alias "_8164_write_axis_do" (ByVal AxisNo As Integer, ByVal on_off As Integer) As Integer

Declare Function B_8164_enable_card_id Lib "8164.dll" Alias "_8164_enable_card_id" () As Integer
Declare Function B_8164_check_card Lib "8164.dll" Alias "_8164_check_card" (ByVal CardNo As Integer) As Integer
Declare Function B_8164_get_pxi_trigger_value Lib "8164.dll" Alias "_8164_get_pxi_trigger_value" (ByVal CardNo As Integer, Value As Integer) As Integer
Declare Function B_8164_set_pxi_trigger_value Lib "8164.dll" Alias "_8164_set_pxi_trigger_value" (ByVal CardNo As Integer, ByVal Value As Integer) As Integer
Declare Function B_8164_enable_pxi_input Lib "8164.dll" Alias "_8164_enable_pxi_input" (ByVal CardNo As Integer, ByVal STA As Integer, ByVal STP As Integer, ByVal CEMG As Integer) As Integer
Declare Function B_8164_select_pxi_output Lib "8164.dll" Alias "_8164_select_pxi_output" (ByVal CardNo As Integer, ByVal source As Integer, ByVal pxi_channel As Integer) As Integer

Declare Function B_8164_il_get_position Lib "8164.dll" Alias "_8164_il_get_position" (ByVal AxisNo As Integer, cmp_pos As Double) As Integer
Declare Function B_8164_il_set_position Lib "8164.dll" Alias "_8164_il_set_position" (ByVal AxisNo As Integer, ByVal cmp_pos As Double) As Integer
Declare Function B_8164_il_set_counter_mode Lib "8164.dll" Alias "_8164_il_set_counter_mode" (ByVal AxisNo As Integer, ByVal mode As Integer) As Integer
Declare Function B_8164_il_set_compare Lib "8164.dll" Alias "_8164_il_set_compare" (ByVal AxisNo As Integer, ByVal smaller As Double, ByVal bigger As Double) As Integer
Declare Function B_8164_il_get_compare Lib "8164.dll" Alias "_8164_il_get_compare" (ByVal AxisNo As Integer, smaller As Double, bigger As Double) As Integer
Declare Function B_8164_il_set_interlock Lib "8164.dll" Alias "_8164_il_set_interlock" (ByVal CardNo As Integer, ByVal control As Integer) As Integer
Declare Function B_8164_il_set_counter_src Lib "8164.dll" Alias "_8164_il_set_counter_src" (ByVal AxisNo As Integer, ByVal src As Integer) As Integer

Declare Function B_8164_async_avoid Lib "8164.dll" Alias "_8164_async_avoid" (ByVal CardNo As Integer, ByVal boundary As Long, ByVal cmp_mode As Integer, ByVal Enable As Integer) As Integer
Declare Function B_8164_aa_set_counter_mode Lib "8164.dll" Alias "_8164_aa_set_counter_mode" (ByVal CardNo As Integer, ByVal axis0_mode As Integer, ByVal axis1_mode As Integer, ByVal cnt_src As Integer) As Integer
Declare Function B_8164_aa_get_boundary Lib "8164.dll" Alias "_8164_aa_get_boundary" (ByVal CardNo As Integer, boundary As Double) As Integer
Declare Function B_8164_aa_reset_error_value Lib "8164.dll" Alias "_8164_aa_reset_error_value" (ByVal CardNo As Integer, ByVal err_value As Double) As Integer
Declare Function B_8164_aa_get_error_value Lib "8164.dll" Alias "_8164_aa_get_error_value" (ByVal CardNo As Integer, err_value As Double) As Integer

Declare Function B_8164_cpld_write Lib "8164.dll" Alias "_8164_cpld_write" (ByVal CardNo As Integer, ByVal Offset As Integer, ByVal Data As Integer) As Integer
Declare Function B_8164_cpld_read Lib "8164.dll" Alias "_8164_cpld_read" (ByVal CardNo As Integer, ByVal Offset As Integer) As Integer
Declare Function B_8164_software_reset Lib "8164.dll" Alias "_8164_software_reset" (ByVal CardNo As Integer) As Integer

Declare Function B_8164_aa_release_sd_latch Lib "8164.dll" Alias "_8164_aa_release_sd_latch" (ByVal CardNo As Integer) As Integer

Declare Function B_8164_set_security_key Lib "8164.dll" Alias "_8164_set_security_key" (ByVal CardNo As Integer, ByVal old_secu_code As Integer, ByVal New_secu_code As Integer) As Integer
Declare Function B_8164_check_security_key Lib "8164.dll" Alias "_8164_check_security_key" (ByVal CardNo As Integer, ByVal secu_code As Integer) As Integer
Declare Function B_8164_reset_security_key Lib "8164.dll" Alias "_8164_reset_security_key" (ByVal CardNo As Integer) As Integer

