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
/* Generated on Mon Jan 16 09:10:40 EST 2017 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_r2cf.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -n 20 -name r2cf_20 -include r2cf.h */

/*
 * This function contains 86 FP additions, 32 FP multiplications,
 * (or, 58 additions, 4 multiplications, 28 fused multiply/add),
 * 70 stack variables, 4 constants, and 40 memory accesses
 */
#include "r2cf.h"

static void r2cf_20(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(80, rs), MAKE_VOLATILE_STRIDE(80, csr), MAKE_VOLATILE_STRIDE(80, csi)) {
	       E T1i, T1c, T1a, T1o, T1m, T1h, T1b, T13, T1j, T1n;
	       {
		    E T3, T1d, TJ, TV, T1k, T16, T19, T1l, Ty, Ti, T12, TD, T1g, TR, TX;
		    E TK, Tt, TU, TW, TL, TE;
		    {
			 E T1, T2, TG, TH;
			 T1 = R0[0];
			 T2 = R0[WS(rs, 5)];
			 TG = R1[WS(rs, 2)];
			 TH = R1[WS(rs, 7)];
			 {
			      E T6, To, T17, Tx, T18, TC, Tj, T9, Tp, Tu, Td, T15, Tm, Tq, Te;
			      E Tf;
			      {
				   E TA, TB, T7, T8;
				   {
					E T4, TF, TI, T5, Tv, Tw;
					T4 = R0[WS(rs, 2)];
					T3 = T1 - T2;
					TF = T1 + T2;
					T1d = TG - TH;
					TI = TG + TH;
					T5 = R0[WS(rs, 7)];
					Tv = R1[WS(rs, 6)];
					Tw = R1[WS(rs, 1)];
					TJ = TF - TI;
					TV = TF + TI;
					T6 = T4 - T5;
					To = T4 + T5;
					T17 = Tw - Tv;
					Tx = Tv + Tw;
				   }
				   TA = R1[WS(rs, 8)];
				   TB = R1[WS(rs, 3)];
				   T7 = R0[WS(rs, 8)];
				   T8 = R0[WS(rs, 3)];
				   {
					E Tb, Tc, Tk, Tl;
					Tb = R0[WS(rs, 4)];
					T18 = TB - TA;
					TC = TA + TB;
					Tj = T7 + T8;
					T9 = T7 - T8;
					Tc = R0[WS(rs, 9)];
					Tk = R1[0];
					Tl = R1[WS(rs, 5)];
					Tp = R1[WS(rs, 4)];
					Tu = Tb + Tc;
					Td = Tb - Tc;
					T15 = Tl - Tk;
					Tm = Tk + Tl;
					Tq = R1[WS(rs, 9)];
					Te = R0[WS(rs, 6)];
					Tf = R0[WS(rs, 1)];
				   }
			      }
			      {
				   E Ta, Tr, Tz, T1e, T1f, Th, T14, Tg, TP, TQ;
				   Ta = T6 + T9;
				   T1k = T6 - T9;
				   T14 = Tq - Tp;
				   Tr = Tp + Tq;
				   Tz = Te + Tf;
				   Tg = Te - Tf;
				   T16 = T14 - T15;
				   T1e = T14 + T15;
				   T1f = T17 + T18;
				   T19 = T17 - T18;
				   Th = Td + Tg;
				   T1l = Td - Tg;
				   Ty = Tu - Tx;
				   TP = Tu + Tx;
				   Ti = Ta + Th;
				   T12 = Ta - Th;
				   TD = Tz - TC;
				   TQ = Tz + TC;
				   T1g = T1e + T1f;
				   T1i = T1e - T1f;
				   {
					E TT, Tn, Ts, TS;
					TT = Tj + Tm;
					Tn = Tj - Tm;
					Ts = To - Tr;
					TS = To + Tr;
					TR = TP - TQ;
					TX = TP + TQ;
					TK = Ts + Tn;
					Tt = Tn - Ts;
					TU = TS - TT;
					TW = TS + TT;
				   }
			      }
			 }
		    }
		    Cr[WS(csr, 5)] = T3 + Ti;
		    Ci[WS(csi, 5)] = T1g - T1d;
		    TL = Ty + TD;
		    TE = Ty - TD;
		    {
			 E TY, T10, TM, TO, T11, TZ, TN;
			 TY = TW + TX;
			 T10 = TW - TX;
			 Ci[WS(csi, 2)] = KP951056516 * (FMA(KP618033988, Tt, TE));
			 Ci[WS(csi, 6)] = KP951056516 * (FNMS(KP618033988, TE, Tt));
			 Ci[WS(csi, 4)] = KP951056516 * (FMA(KP618033988, TR, TU));
			 Ci[WS(csi, 8)] = -(KP951056516 * (FNMS(KP618033988, TU, TR)));
			 TM = TK + TL;
			 TO = TK - TL;
			 T1c = FNMS(KP618033988, T16, T19);
			 T1a = FMA(KP618033988, T19, T16);
			 Cr[0] = TV + TY;
			 TZ = FNMS(KP250000000, TY, TV);
			 Cr[WS(csr, 10)] = TJ + TM;
			 TN = FNMS(KP250000000, TM, TJ);
			 Cr[WS(csr, 8)] = FNMS(KP559016994, T10, TZ);
			 Cr[WS(csr, 4)] = FMA(KP559016994, T10, TZ);
			 Cr[WS(csr, 6)] = FMA(KP559016994, TO, TN);
			 Cr[WS(csr, 2)] = FNMS(KP559016994, TO, TN);
			 T11 = FNMS(KP250000000, Ti, T3);
			 T1o = FNMS(KP618033988, T1k, T1l);
			 T1m = FMA(KP618033988, T1l, T1k);
			 T1h = FMA(KP250000000, T1g, T1d);
			 T1b = FNMS(KP559016994, T12, T11);
			 T13 = FMA(KP559016994, T12, T11);
		    }
	       }
	       Cr[WS(csr, 3)] = FNMS(KP951056516, T1c, T1b);
	       Cr[WS(csr, 7)] = FMA(KP951056516, T1c, T1b);
	       Cr[WS(csr, 1)] = FMA(KP951056516, T1a, T13);
	       Cr[WS(csr, 9)] = FNMS(KP951056516, T1a, T13);
	       T1j = FNMS(KP559016994, T1i, T1h);
	       T1n = FMA(KP559016994, T1i, T1h);
	       Ci[WS(csi, 3)] = FNMS(KP951056516, T1o, T1n);
	       Ci[WS(csi, 7)] = FMA(KP951056516, T1o, T1n);
	       Ci[WS(csi, 9)] = FMS(KP951056516, T1m, T1j);
	       Ci[WS(csi, 1)] = -(FMA(KP951056516, T1m, T1j));
	  }
     }
}

static const kr2c_desc desc = { 20, "r2cf_20", {58, 4, 28, 0}, &GENUS };

void X(codelet_r2cf_20) (planner *p) {
     X(kr2c_register) (p, r2cf_20, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_r2cf.native -compact -variables 4 -pipeline-latency 4 -n 20 -name r2cf_20 -include r2cf.h */

/*
 * This function contains 86 FP additions, 24 FP multiplications,
 * (or, 74 additions, 12 multiplications, 12 fused multiply/add),
 * 51 stack variables, 4 constants, and 40 memory accesses
 */
#include "r2cf.h"

static void r2cf_20(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(80, rs), MAKE_VOLATILE_STRIDE(80, csr), MAKE_VOLATILE_STRIDE(80, csi)) {
	       E T3, T1m, TF, T17, Ts, TM, TN, Tz, Ta, Th, Ti, T1g, T1h, T1k, T10;
	       E T13, T19, TG, TH, TI, T1d, T1e, T1j, TT, TW, T18;
	       {
		    E T1, T2, T15, TD, TE, T16;
		    T1 = R0[0];
		    T2 = R0[WS(rs, 5)];
		    T15 = T1 + T2;
		    TD = R1[WS(rs, 7)];
		    TE = R1[WS(rs, 2)];
		    T16 = TE + TD;
		    T3 = T1 - T2;
		    T1m = T15 + T16;
		    TF = TD - TE;
		    T17 = T15 - T16;
	       }
	       {
		    E T6, TU, Tv, T12, Ty, TZ, T9, TR, Td, TY, To, TS, Tr, TV, Tg;
		    E T11;
		    {
			 E T4, T5, Tt, Tu;
			 T4 = R0[WS(rs, 2)];
			 T5 = R0[WS(rs, 7)];
			 T6 = T4 - T5;
			 TU = T4 + T5;
			 Tt = R1[WS(rs, 8)];
			 Tu = R1[WS(rs, 3)];
			 Tv = Tt - Tu;
			 T12 = Tt + Tu;
		    }
		    {
			 E Tw, Tx, T7, T8;
			 Tw = R1[WS(rs, 6)];
			 Tx = R1[WS(rs, 1)];
			 Ty = Tw - Tx;
			 TZ = Tw + Tx;
			 T7 = R0[WS(rs, 8)];
			 T8 = R0[WS(rs, 3)];
			 T9 = T7 - T8;
			 TR = T7 + T8;
		    }
		    {
			 E Tb, Tc, Tm, Tn;
			 Tb = R0[WS(rs, 4)];
			 Tc = R0[WS(rs, 9)];
			 Td = Tb - Tc;
			 TY = Tb + Tc;
			 Tm = R1[0];
			 Tn = R1[WS(rs, 5)];
			 To = Tm - Tn;
			 TS = Tm + Tn;
		    }
		    {
			 E Tp, Tq, Te, Tf;
			 Tp = R1[WS(rs, 4)];
			 Tq = R1[WS(rs, 9)];
			 Tr = Tp - Tq;
			 TV = Tp + Tq;
			 Te = R0[WS(rs, 6)];
			 Tf = R0[WS(rs, 1)];
			 Tg = Te - Tf;
			 T11 = Te + Tf;
		    }
		    Ts = To - Tr;
		    TM = T6 - T9;
		    TN = Td - Tg;
		    Tz = Tv - Ty;
		    Ta = T6 + T9;
		    Th = Td + Tg;
		    Ti = Ta + Th;
		    T1g = TY + TZ;
		    T1h = T11 + T12;
		    T1k = T1g + T1h;
		    T10 = TY - TZ;
		    T13 = T11 - T12;
		    T19 = T10 + T13;
		    TG = Tr + To;
		    TH = Ty + Tv;
		    TI = TG + TH;
		    T1d = TU + TV;
		    T1e = TR + TS;
		    T1j = T1d + T1e;
		    TT = TR - TS;
		    TW = TU - TV;
		    T18 = TW + TT;
	       }
	       Cr[WS(csr, 5)] = T3 + Ti;
	       Ci[WS(csi, 5)] = TF - TI;
	       {
		    E TX, T14, T1f, T1i;
		    TX = TT - TW;
		    T14 = T10 - T13;
		    Ci[WS(csi, 6)] = FNMS(KP587785252, T14, KP951056516 * TX);
		    Ci[WS(csi, 2)] = FMA(KP587785252, TX, KP951056516 * T14);
		    T1f = T1d - T1e;
		    T1i = T1g - T1h;
		    Ci[WS(csi, 8)] = FNMS(KP951056516, T1i, KP587785252 * T1f);
		    Ci[WS(csi, 4)] = FMA(KP951056516, T1f, KP587785252 * T1i);
	       }
	       {
		    E T1l, T1n, T1o, T1c, T1a, T1b;
		    T1l = KP559016994 * (T1j - T1k);
		    T1n = T1j + T1k;
		    T1o = FNMS(KP250000000, T1n, T1m);
		    Cr[WS(csr, 4)] = T1l + T1o;
		    Cr[0] = T1m + T1n;
		    Cr[WS(csr, 8)] = T1o - T1l;
		    T1c = KP559016994 * (T18 - T19);
		    T1a = T18 + T19;
		    T1b = FNMS(KP250000000, T1a, T17);
		    Cr[WS(csr, 2)] = T1b - T1c;
		    Cr[WS(csr, 10)] = T17 + T1a;
		    Cr[WS(csr, 6)] = T1c + T1b;
	       }
	       {
		    E TA, TC, Tl, TB, Tj, Tk;
		    TA = FMA(KP951056516, Ts, KP587785252 * Tz);
		    TC = FNMS(KP587785252, Ts, KP951056516 * Tz);
		    Tj = KP559016994 * (Ta - Th);
		    Tk = FNMS(KP250000000, Ti, T3);
		    Tl = Tj + Tk;
		    TB = Tk - Tj;
		    Cr[WS(csr, 9)] = Tl - TA;
		    Cr[WS(csr, 7)] = TB + TC;
		    Cr[WS(csr, 1)] = Tl + TA;
		    Cr[WS(csr, 3)] = TB - TC;
	       }
	       {
		    E TO, TQ, TL, TP, TJ, TK;
		    TO = FMA(KP951056516, TM, KP587785252 * TN);
		    TQ = FNMS(KP587785252, TM, KP951056516 * TN);
		    TJ = FMA(KP250000000, TI, TF);
		    TK = KP559016994 * (TH - TG);
		    TL = TJ + TK;
		    TP = TK - TJ;
		    Ci[WS(csi, 1)] = TL - TO;
		    Ci[WS(csi, 7)] = TQ + TP;
		    Ci[WS(csi, 9)] = TO + TL;
		    Ci[WS(csi, 3)] = TP - TQ;
	       }
	  }
     }
}

static const kr2c_desc desc = { 20, "r2cf_20", {74, 12, 12, 0}, &GENUS };

void X(codelet_r2cf_20) (planner *p) {
     X(kr2c_register) (p, r2cf_20, &desc);
}

#endif				/* HAVE_FMA */
