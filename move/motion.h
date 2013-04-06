// PCI8164/MPC8164
#ifndef _MOTION
#define _MOTION

#define SOFT_VERSION 31118
//#define REG_LOG

// ========== Choose Function Model Name =============
#define _ADLINK
//#define _NPM


// =========== Choose Board Interface ================
#define _PCI		// PCI Bus
//#define _MPC		// ISA Bus


// =========== Choose OS =================
#define _MYWIN32
//#define _MSDOS
//#define _MYLINUX
//#define _MYWINCE

// =========== Choose Compiler =============
#define _MSC
//#define _BC31
//#define _MYWATCOMC
//#define _PLATFORMBUILDER

/////////////////////////////////////////////////////////////////////

#if defined(_MYWIN32)

	#if defined( _MSC )
	  #define FNTYPE PASCAL
	  #define _OUTPORTB _outp
	  #define _OUTPORTW _outpw
	  #define _OUTPORTD _outpd
	  #define _INPORTB _inp
	  #define _INPORTW _inpw
	  #define _INPORTD _inpd
	  #define _SLEEP Sleep
	#endif

#elif defined (_MSDOS)

	#if defined( _BC31 )
	  #define FNTYPE
	  #define _OUTPORTB outportb
	  #define _OUTPORTW outport
	  #define _INPORTB inportb
	  #define _INPORTW inport
	  #define _SLEEP   delay
	#elif defined (_WATCOMC)
	  #define FNTYPE
	  #define _OUTPORTB outp
	  #define _OUTPORTW outpw
	  #define _INPORTB inp
	  #define _INPORTW inpw
	  #define _SLEEP   delay
	#endif
#elif defined ( _MYLINUX)

  #define FNTYPE
  #define _SLEEP(t) usleep(1000*t)

#elif defined (_MYWINCE )

	#ifdef _PLATFORMBUILDER
	  #define FNTYPE
	  #define _OUTPORTB _outp
	  #define _OUTPORTW _outpw
	  #define _OUTPORTD _outpd
	  #define _INPORTB _inp
	  #define _INPORTW _inpw
	  #define _INPORTD _inpd
	  #define _SLEEP Sleep
	#endif

#endif


#endif
