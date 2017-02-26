/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Mon Jan 16 09:11:52 EST 2017 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_r2cb.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -n 15 -name r2cbIII_15 -dft-III -include r2cbIII.h */

/*
 * This function contains 64 FP additions, 43 FP multiplications,
 * (or, 21 additions, 0 multiplications, 43 fused multiply/add),
 * 48 stack variables, 9 constants, and 30 memory accesses
 */
#include "r2cbIII.h"

static void r2cbIII_15(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP1_732050807, +1.732050807568877293527446341505872366942805254);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP1_902113032, +1.902113032590307144232878666758764286811397268);
     DK(KP1_118033988, +1.118033988749894848204586834365638117720309180);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(60, rs), MAKE_VOLATILE_STRIDE(60, csr), MAKE_VOLATILE_STRIDE(60, csi)) {
	       E TX, Tv, To, TW, Tl, Tx, Ty, Tw;
	       {
		    E TA, Tk, T6, T5, Tz, Th, TI, Tp, Tu, TK, TR, Tn, Td, Tq;
		    {
			 E T1, T2, T3, Ti, Tj;
			 Ti = Ci[WS(csi, 4)];
			 Tj = Ci[WS(csi, 1)];
			 T1 = Cr[WS(csr, 7)];
			 T2 = Cr[WS(csr, 4)];
			 T3 = Cr[WS(csr, 1)];
			 TA = FNMS(KP618033988, Ti, Tj);
			 Tk = FMA(KP618033988, Tj, Ti);
			 {
			      E T7, TP, Tc, T8;
			      T6 = Cr[WS(csr, 2)];
			      {
				   E T4, Tg, Ta, Tb, Tf;
				   T4 = T2 + T3;
				   Tg = T2 - T3;
				   Ta = Cr[WS(csr, 3)];
				   Tb = Cr[WS(csr, 6)];
				   T7 = Cr[0];
				   Tf = FNMS(KP500000000, T4, T1);
				   T5 = FMA(KP2_000000000, T4, T1);
				   TP = Ta - Tb;
				   Tc = Ta + Tb;
				   Tz = FNMS(KP1_118033988, Tg, Tf);
				   Th = FMA(KP1_118033988, Tg, Tf);
				   T8 = Cr[WS(csr, 5)];
			      }
			      TI = Ci[WS(csi, 2)];
			      {
				   E Ts, Tt, TQ, T9;
				   Ts = Ci[WS(csi, 3)];
				   Tt = Ci[WS(csi, 6)];
				   TQ = T7 - T8;
				   T9 = T7 + T8;
				   Tp = Ci[0];
				   Tu = Ts - Tt;
				   TK = Ts + Tt;
				   TX = FMA(KP618033988, TP, TQ);
				   TR = FNMS(KP618033988, TQ, TP);
				   Tn = T9 - Tc;
				   Td = T9 + Tc;
				   Tq = Ci[WS(csi, 5)];
			      }
			 }
		    }
		    {
			 E TB, TF, TO, TG, TE;
			 {
			      E Tm, T11, TN, TD, TM, T12, TC;
			      TB = FNMS(KP1_902113032, TA, Tz);
			      TF = FMA(KP1_902113032, TA, Tz);
			      {
				   E Te, Tr, TJ, TL;
				   Tm = FNMS(KP250000000, Td, T6);
				   Te = T6 + Td;
				   Tr = Tp + Tq;
				   TJ = Tq - Tp;
				   R0[0] = FMA(KP2_000000000, Te, T5);
				   T11 = Te - T5;
				   TN = TJ + TK;
				   TL = TJ - TK;
				   Tv = FMA(KP618033988, Tu, Tr);
				   TD = FNMS(KP618033988, Tr, Tu);
				   TM = FNMS(KP250000000, TL, TI);
				   T12 = TL + TI;
			      }
			      TC = FNMS(KP559016994, Tn, Tm);
			      To = FMA(KP559016994, Tn, Tm);
			      R1[WS(rs, 2)] = FMA(KP1_732050807, T12, T11);
			      R0[WS(rs, 5)] = FMS(KP1_732050807, T12, T11);
			      TW = FMA(KP559016994, TN, TM);
			      TO = FNMS(KP559016994, TN, TM);
			      TG = FNMS(KP951056516, TD, TC);
			      TE = FMA(KP951056516, TD, TC);
			 }
			 Tl = FNMS(KP1_902113032, Tk, Th);
			 Tx = FMA(KP1_902113032, Tk, Th);
			 {
			      E TS, TU, TT, TH;
			      TS = FMA(KP951056516, TR, TO);
			      TU = FNMS(KP951056516, TR, TO);
			      TT = TF - TG;
			      R1[WS(rs, 1)] = -(FMA(KP2_000000000, TG, TF));
			      TH = TB - TE;
			      R0[WS(rs, 6)] = FMA(KP2_000000000, TE, TB);
			      R1[WS(rs, 6)] = -(FMA(KP1_732050807, TU, TT));
			      R0[WS(rs, 4)] = FNMS(KP1_732050807, TU, TT);
			      R1[WS(rs, 3)] = -(FMA(KP1_732050807, TS, TH));
			      R0[WS(rs, 1)] = FNMS(KP1_732050807, TS, TH);
			 }
		    }
	       }
	       Ty = FNMS(KP951056516, Tv, To);
	       Tw = FMA(KP951056516, Tv, To);
	       {
		    E T10, TY, TV, TZ;
		    T10 = FMA(KP951056516, TX, TW);
		    TY = FNMS(KP951056516, TX, TW);
		    TV = Ty - Tx;
		    R0[WS(rs, 3)] = FMA(KP2_000000000, Ty, Tx);
		    TZ = Tl - Tw;
		    R1[WS(rs, 4)] = -(FMA(KP2_000000000, Tw, Tl));
		    R1[WS(rs, 5)] = FMA(KP1_732050807, TY, TV);
		    R1[0] = FNMS(KP1_732050807, TY, TV);
		    R0[WS(rs, 2)] = FMA(KP1_732050807, T10, TZ);
		    R0[WS(rs, 7)] = FNMS(KP1_732050807, T10, TZ);
	       }
	  }
     }
}

static const kr2c_desc desc = { 15, "r2cbIII_15", {21, 0, 43, 0}, &GENUS };

void X(codelet_r2cbIII_15) (planner *p) {
     X(kr2c_register) (p, r2cbIII_15, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_r2cb.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 15 -name r2cbIII_15 -dft-III -include r2cbIII.h */

/*
 * This function contains 64 FP additions, 26 FP multiplications,
 * (or, 49 additions, 11 multiplications, 15 fused multiply/add),
 * 47 stack variables, 14 constants, and 30 memory accesses
 */
#include "r2cbIII.h"

static void r2cbIII_15(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP1_732050807, +1.732050807568877293527446341505872366942805254);
     DK(KP433012701, +0.433012701892219323381861585376468091735701313);
     DK(KP968245836, +0.968245836551854221294816349945599902708230426);
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP1_647278207, +1.647278207092663851754840078556380006059321028);
     DK(KP1_018073920, +1.018073920910254366901961726787815297021466329);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DK(KP1_118033988, +1.118033988749894848204586834365638117720309180);
     DK(KP1_175570504, +1.175570504584946258337411909278145537195304875);
     DK(KP1_902113032, +1.902113032590307144232878666758764286811397268);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(60, rs), MAKE_VOLATILE_STRIDE(60, csr), MAKE_VOLATILE_STRIDE(60, csi)) {
	       E Tv, TD, T5, Ts, TC, T6, Tf, TW, TK, Td, Tg, TP, To, TN, TA;
	       E TO, TQ, Tt, Tu, T12, Te, T11;
	       Tt = Ci[WS(csi, 4)];
	       Tu = Ci[WS(csi, 1)];
	       Tv = FMA(KP1_902113032, Tt, KP1_175570504 * Tu);
	       TD = FNMS(KP1_175570504, Tt, KP1_902113032 * Tu);
	       {
		    E T1, T4, Tq, T2, T3, Tr;
		    T1 = Cr[WS(csr, 7)];
		    T2 = Cr[WS(csr, 4)];
		    T3 = Cr[WS(csr, 1)];
		    T4 = T2 + T3;
		    Tq = KP1_118033988 * (T2 - T3);
		    T5 = FMA(KP2_000000000, T4, T1);
		    Tr = FNMS(KP500000000, T4, T1);
		    Ts = Tq + Tr;
		    TC = Tr - Tq;
	       }
	       {
		    E Tc, TJ, T9, TI;
		    T6 = Cr[WS(csr, 2)];
		    {
			 E Ta, Tb, T7, T8;
			 Ta = Cr[WS(csr, 3)];
			 Tb = Cr[WS(csr, 6)];
			 Tc = Ta + Tb;
			 TJ = Ta - Tb;
			 T7 = Cr[0];
			 T8 = Cr[WS(csr, 5)];
			 T9 = T7 + T8;
			 TI = T7 - T8;
		    }
		    Tf = KP559016994 * (T9 - Tc);
		    TW = FNMS(KP1_647278207, TJ, KP1_018073920 * TI);
		    TK = FMA(KP1_647278207, TI, KP1_018073920 * TJ);
		    Td = T9 + Tc;
		    Tg = FNMS(KP250000000, Td, T6);
	       }
	       {
		    E Tn, TM, Tk, TL;
		    TP = Ci[WS(csi, 2)];
		    {
			 E Tl, Tm, Ti, Tj;
			 Tl = Ci[WS(csi, 3)];
			 Tm = Ci[WS(csi, 6)];
			 Tn = Tl - Tm;
			 TM = Tl + Tm;
			 Ti = Ci[0];
			 Tj = Ci[WS(csi, 5)];
			 Tk = Ti + Tj;
			 TL = Ti - Tj;
		    }
		    To = FMA(KP951056516, Tk, KP587785252 * Tn);
		    TN = KP968245836 * (TL - TM);
		    TA = FNMS(KP587785252, Tk, KP951056516 * Tn);
		    TO = TL + TM;
		    TQ = FMA(KP433012701, TO, KP1_732050807 * TP);
	       }
	       T12 = KP1_732050807 * (TP - TO);
	       Te = T6 + Td;
	       T11 = Te - T5;
	       R0[0] = FMA(KP2_000000000, Te, T5);
	       R0[WS(rs, 5)] = T12 - T11;
	       R1[WS(rs, 2)] = T11 + T12;
	       {
		    E TE, TG, TB, TF, TY, T10, Tz, TX, TV, TZ;
		    TE = TC - TD;
		    TG = TC + TD;
		    Tz = Tg - Tf;
		    TB = Tz + TA;
		    TF = TA - Tz;
		    TX = TN + TQ;
		    TY = TW - TX;
		    T10 = TW + TX;
		    R0[WS(rs, 6)] = FMA(KP2_000000000, TB, TE);
		    R1[WS(rs, 1)] = FMS(KP2_000000000, TF, TG);
		    TV = TE - TB;
		    R0[WS(rs, 1)] = TV + TY;
		    R1[WS(rs, 3)] = TY - TV;
		    TZ = TF + TG;
		    R0[WS(rs, 4)] = TZ - T10;
		    R1[WS(rs, 6)] = -(TZ + T10);
	       }
	       {
		    E Tw, Ty, Tp, Tx, TS, TU, Th, TR, TH, TT;
		    Tw = Ts - Tv;
		    Ty = Ts + Tv;
		    Th = Tf + Tg;
		    Tp = Th + To;
		    Tx = Th - To;
		    TR = TN - TQ;
		    TS = TK + TR;
		    TU = TR - TK;
		    R1[WS(rs, 4)] = -(FMA(KP2_000000000, Tp, Tw));
		    R0[WS(rs, 3)] = FMA(KP2_000000000, Tx, Ty);
		    TH = Tx - Ty;
		    R1[WS(rs, 5)] = TH - TS;
		    R1[0] = TH + TS;
		    TT = Tw - Tp;
		    R0[WS(rs, 2)] = TT - TU;
		    R0[WS(rs, 7)] = TT + TU;
	       }
	  }
     }
}

static const kr2c_desc desc = { 15, "r2cbIII_15", {49, 11, 15, 0}, &GENUS };

void X(codelet_r2cbIII_15) (planner *p) {
     X(kr2c_register) (p, r2cbIII_15, &desc);
}

#endif				/* HAVE_FMA */
