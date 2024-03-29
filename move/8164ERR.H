#ifndef _8164ERR_H

#define _8164ERR_H

enum {
    ERR_NoError,			//0
    ERR_BoardNoInit,                    //1
    ERR_InvalidBoardNumber,             //2
    ERR_InitializedBoardNumber,         //3
    ERR_BaseAddressError,               //4
    ERR_BaseAddressConflict,            //5
    ERR_DuplicateBoardSetting,          //6
    ERR_DuplicateIrqSetting,            //7
    ERR_PCIBiosNotExist,                //8
    ERR_PCIIrqNotExist,                 //9
    ERR_PCICardNotExist,                //10
    ERR_SpeedError,   		        //11
    ERR_MoveRatioError,			//12
    ERR_PosOutOfRange,			//13
    ERR_AxisAlreadyStop,		//14
    ERR_AxisArrayError,			//15
    ERR_SlowDownPointError,		//16
    ERR_CompareMethodError,		//17
    ERR_CompareNoError,			//18
	ERR_CompareAxisError,		//19
	ERR_CompareTableSizeError,	//20
	ERR_CompareFunctionError,	//21
	ERR_CompareTableNotReady,	//22
	ERR_CompareLineNotReady,	//23
	ERR_NoCardFound,		//24
	ERR_LatchNoError,		//25
	ERR_AxisRangeError,		//26
	ERR_DioNoError,			//27
	ERR_PChangeSlowDownPointError,  //28
    ERR_SpeedChangeError,               //29
	ERR_CardNoError,		//30
	ERR_LinkIntError,		//31
	ERR_HardwareCompareAxisWrong,	//32
	ERR_AutoCompareSourceWrong,		//33
	ERR_CompareDeviceTypeError,			//34
	ERR_PulserHomeTypeError,		//35
	ERR_EventAlreadyEnable,			//36
	ERR_EventNotEnableYet,			//37
	ERR_LineArcParameterError,		//38
	ERR_ConfigFileOpenError,		//39
	ERR_CompareFIFONotReady,		//40
	ERR_EventInitError,				//41
	ERR_MemAllocError,				//42
	ERR_FIFOSourceERROR,			//43
	ERR_OtherProcessExist,			//44
	ERR_DelayTimeError,				//45
	ERR_DelayDistError,				//46
	ERR_FIFOModeOn,					//47
	ERR_FIFOBusy,					//48
	ERR_OpenDriverFailed,			//49
	ERR_OSVersionError,				//50
	ERR_OwnerSet,				    //51
	ERR_SignalHandle,			    //52
	ERR_SignalNotify,			    //53	
	ERR_AllocateMemory,		    	//54
	ERR_VChangeTimeError,			//55
	ERR_EventInvalid,				//56
	ERR_ErrorIntCome,				//57
	ERR_Unknown,					//58
	ERR_WaitAbandoned,				//59
	ERR_WaitDelayTimeOut,			//60
	ERR_NoSeqAttached,				//61
	ERR_CardTypeWrong,				//62
	ERR_RotarySourceWrong,			//63
	ERR_PXISourceWrong,				//64
	ERR_PXIChannelWrong,			//65
	ERR_PulseModeError,				//66
	ERR_EventMapRangeError,			//67
	ERR_EventTypeError,				//68
	ERR_AAModeWrong,				//69
	ERR_MotionBusy,					//70
	ERR_ArraySizeTooBig,			//71
	ERR_UserCodeWrite,				//72
	ERR_SecurityCode,				//73
	ERR_CompareDataNotReady,		//74
	ERR_ParameterError,				//75
	ERR_PitchCompensationWrong,		//76
	ERR_CanNotPitchCompensation,	//77
	ERR_CanNotUseInPitchCompMode,	//78
	ERR_PitchCompNotEnable,			//79
};

#endif
